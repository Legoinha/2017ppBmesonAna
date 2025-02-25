#include "TROOT.h"
#include "TH1.h"
#include "TTree.h"
#include "TH2.h"
#include "TF1.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TVector2.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TRandom.h"
#include <iostream>
#include <fstream>

#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TGraphAsymmErrors.h"
#include "TGraphErrors.h"

#include "TH1.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TMath.h"
//#include "tnp_weight_lowptPBsb.h"



//#include "his.h"
using namespace std;

using std::cout;
using std::endl;

void BsComparison(){



	
	gStyle->SetOptStat(0);

	TCanvas * c = new TCanvas("c","c",600,600);

	c->cd();

	c->SetLeftMargin(0.16);




//	TString InfileBs = "FinalFiles/BsPPCorrYieldPT.root";
//	TString InfileBs = "/Users/zhaozhongshi/Desktop/TempDownload/ForPAG/HenriqueYield/BsPPCorrYieldPT3.root";

	TString InfileBs = "../../../Bs/EffAna/FinalFiles/BsPPCorrYieldPT.root";

	TFile * FileBs = new TFile(InfileBs.Data());
	TH1D * BsCross = (TH1D *) FileBs->Get("CorrDiffHisBin");
	BsCross->SetMarkerStyle(20);
	BsCross->SetMarkerSize(1);
	BsCross->SetMarkerColor(1);
	BsCross->SetLineColor(1);







	//B+ PBsb//
	
//	const int NBins = 7;
	const int NBins = 4;

	float BsXsecPPY[NBins];
//	float BsXsecPPX[NBins] = {6,8.5,12.5,17.5,25,40,55};
	float BsXsecPPX[NBins] = {8.5,12.5,17.5,35};


	float BsXSecPPYErrUp[NBins];
	float BsXSecPPYErrDown[NBins];


	float BsXSecPPYErrUpPercent[NBins];
	float BsXSecPPYErrDownPercent[NBins];


	for(int i = 0; i < NBins; i++){

		BsXsecPPY[i] = BsCross->GetBinContent(i+1);
		BsXSecPPYErrUp[i] = BsCross->GetBinError(i+1);
		BsXSecPPYErrDown[i] = BsCross->GetBinError(i+1);
		BsXSecPPYErrUpPercent[i] = BsXSecPPYErrUp[i]/BsXsecPPY[i];
		BsXSecPPYErrDownPercent[i] = BsXSecPPYErrDown[i]/BsXsecPPY[i];
		cout << "BsXsecPPY[i] = " << BsXsecPPY[i]  << "   Stat[i]  = " << BsXSecPPYErrUpPercent[i] << endl;
		
	}


	float BsXsecPPY2D[NBins];
	float BsXSecPPY2DErrUp[NBins];
	float BsXSecPPY2DErrDown[NBins];

	TH1D * BsCross2D = (TH1D *) FileBs->Get("hPtSigma");
	BsCross2D->SetMarkerStyle(20);
	BsCross2D->SetMarkerSize(1);
	BsCross2D->SetMarkerColor(1);
	BsCross2D->SetLineColor(1);



	for(int i = 0; i < NBins; i++){

		BsXsecPPY2D[i] = BsCross2D->GetBinContent(i+1);
		BsXSecPPY2DErrUp[i] = BsCross2D->GetBinError(i+1);
		BsXSecPPY2DErrDown[i] = BsCross2D->GetBinError(i+1);
		

	}





//	float BsXSecPPXErrUp[NBins] = {1,1.5,2.5,2.5,5,10,5};
//	float BsXSecPPXErrDown[NBins] = {1,1.5,2.5,2.5,5,10,5};
	
	float BsXSecPPXErrUp[NBins] = {1.5,2.5,2.5,15};
	float BsXSecPPXErrDown[NBins] = {1.5,2.5,2.5,15};

/*
	float BsXsecPBsbY[NBins] = {4.82132e+06/11.1,311668,270167,64384.4,208537/11.1,28700.6/11.1,7000.73/11.1};
	float BsXsecPBsbX[NBins] = {6,8.73,12.4,17.2,25,40,55};


	float BsXSecPBsbXErrUp[NBins] = {1,1.27,2.6,2.8,5,10,5};
	float BsXSecPBsbXErrDown[NBins] = {1,1.23,2.4,2.2,5,10,5};

	float BsXSecPBsbYErrUpPercent[NBins] = {0.278198,0.159,0.041,0.0654,0.0690334,0.104543,0.24575};
	float BsXSecPBsbYErrDownPercent[NBins] = {0.278198,0.145,0.0795,0.065,0.0690334,0.104543,0.24575};


	float BsXSecPBsbYErrUp[NBins];
	float BsXSecPBsbYErrDown[NBins];

	for(int i = 0; i < NBins; i++){

		BsXSecPBsbYErrUp[i] = BsXSecPBsbYErrUpPercent[i] * BsXsecPBsbY[i];
		BsXSecPBsbYErrDown[i] = BsXSecPBsbYErrDownPercent[i] * BsXsecPBsbY[i];

	}




*/

	//Syst Add Up PP//



	float BsXSecPPYSystUp[NBins];
	float BsXSecPPYSystDown[NBins];


	float BsTrackingSyst[NBins] = {0.10,0.10,0.10,0.10};
	float BsMDDataSyst[NBins] = {0.0466,0.0870,0.0725,0.0495};
	float BsPtShapeSyst[NBins] = {0.0194,0.00607,0.00100,0.000312};	
	float BsPDFSyst[NBins] = {0.0545,0.012,0.0213,0.0395};

	float BsTnPSystDown[NBins] = {0.00412,0.00385,0.00376,0.00457};
	float BsTnPSystUp[NBins] = {0.00412,0.00385,0.00376,0.00457};

	float BsTotalSystDown[NBins];
	float BsTotalSystUp[NBins];

	for(int i = 0; i < NBins; i++){

		
		BsTotalSystDown[i] = TMath::Sqrt(BsTrackingSyst[i] * BsTrackingSyst[i] + BsMDDataSyst[i] * BsMDDataSyst[i] + BsPDFSyst[i] * BsPDFSyst[i] + BsPtShapeSyst[i] * BsPtShapeSyst[i] + BsTnPSystDown[i] * BsTnPSystDown[i]);
		BsTotalSystUp[i] = TMath::Sqrt(BsTrackingSyst[i] * BsTrackingSyst[i] +BsMDDataSyst[i] * BsMDDataSyst[i] + BsPDFSyst[i] * BsPDFSyst[i] + BsPtShapeSyst[i] * BsPtShapeSyst[i] + BsTnPSystUp[i] * BsTnPSystUp[i]);


	}
	
	for(int i = 0; i < NBins; i++){

		BsXSecPPYSystUp[i] = BsXsecPPY[i] * ( BsTotalSystUp[i]);
		BsXSecPPYSystDown[i] = BsXsecPPY[i] * (BsTotalSystDown[i] );
		//cout << "i = " << i << "     BPXSecPPYSystDown[i] = " << BPXSecPPYSystDown[i] << "  BPXSecPPYErrDown[i] =  " << BPXSecPPYErrDown[i] << endl;
		
	}







	TH2D * HisEmpty = new TH2D("HisEmpty","",100,7,50,100,100.0,2000000);
	HisEmpty->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	HisEmpty->GetYaxis()->SetTitle("Cross Section (Or Production Yield)");
	HisEmpty->GetXaxis()->CenterTitle();
	HisEmpty->GetYaxis()->CenterTitle();
	HisEmpty->GetYaxis()->SetTitleOffset(1.8);
	HisEmpty->Draw();

	TGraphAsymmErrors *BsPPCrossGraph = new TGraphAsymmErrors(NBins, BsXsecPPX, BsXsecPPY,BsXSecPPXErrDown, BsXSecPPXErrUp,BsXSecPPYErrDown,BsXSecPPYErrUp);
	

	TGraphAsymmErrors *BsPPCrossGraphSyst  = new TGraphAsymmErrors(NBins, BsXsecPPX, BsXsecPPY, BsXSecPPXErrDown, BsXSecPPXErrUp, BsXSecPPYSystDown,BsXSecPPYSystUp);


	TGraphAsymmErrors *BsPPCrossGraph2D = new TGraphAsymmErrors(NBins, BsXsecPPX, BsXsecPPY2D,BsXSecPPXErrDown, BsXSecPPXErrUp,BsXSecPPY2DErrDown,BsXSecPPY2DErrUp);


//	TGraphAsymmErrors *BsPBsbCrossGraph = new TGraphAsymmErrors(NBins, BsXsecPBsbX, BsXsecPBsbY,BsXSecPBsbXErrDown, BsXSecPbPbXErrUp,BsXSecPbPbYErrDown,BsXSecPbPbYErrUp);
/*
	BsPBsbCrossGraph->SetLineColor(kGreen+2);
//	BsPBsbCrossGraph->SetFillColorAlpha(kGreen-9,0.5);
	BsPBsbCrossGraph->SetMarkerStyle(20);
	BsPBsbCrossGraph->SetMarkerSize(1);
	BsPBsbCrossGraph->SetMarkerColor(kGreen+2);
*/
	BsPPCrossGraph->SetLineColor(kBlue+2);
//	BsPPCrossGraph->SetFillColorAlpha(kBlue-9,0.5);
	BsPPCrossGraph->SetMarkerStyle(21);
	BsPPCrossGraph->SetMarkerSize(1);
	BsPPCrossGraph->SetMarkerColor(kBlue+2);



	BsPPCrossGraphSyst->SetFillColorAlpha(kBlue-9,0.5);
	BsPPCrossGraphSyst->SetLineColor(kBlue-9);
	


	BsPPCrossGraph->Draw("ep");	
	BsPPCrossGraphSyst->Draw("5same");	
	
	c->SaveAs("Plots/Bs/BsCrossONLY.png");
	c->SaveAs("Plots/Bs/BsCrossONLY.pdf");
	
	c->SetLogy();
	c->SaveAs("Plots/Bs/BsCrossONLYLog.png");
	c->SaveAs("Plots/Bs/BsCrossONLYLog.pdf");




	//2015 Reference//


	TCanvas * cRatio = new TCanvas("cRatio","cRatio",800,1200);
    TPad * MyPad1;

	MyPad1 = new TPad("MyPad1","",0,0.5,1,1.0);
	MyPad1->Draw();
   

	TPad * MyPad2;

	MyPad2 = new TPad("MyPad2","",0,0.25,1,0.50);
	MyPad2->Draw();



	TPad * MyPad3;

	MyPad3 = new TPad("MyPad3","",0,0.00,1,0.25);
	MyPad3->Draw();


	MyPad1->cd();



	TH2D * HisEmpty2 = new TH2D("HisEmpty2","",100,7,50,100,100.0,30000000);
	HisEmpty2->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	HisEmpty2->GetYaxis()->SetTitle("Cross Section (Or Production Yield)");
	HisEmpty2->GetXaxis()->CenterTitle();
	HisEmpty2->GetYaxis()->CenterTitle();
	HisEmpty2->GetYaxis()->SetTitleOffset(1.2);
	HisEmpty2->Draw();

	BsPPCrossGraph->Draw("ep");

/*
	const int NBins2015 = 5;
	float BsXsecPPX2015[NBins2015] = {8.5,12.5,17.5,25,40};
	float BsXSecPPXErrDown2015[NBins2015] = {1.5,2.5,2.5,5,10};
	float BsXSecPPXErrUp2015[NBins2015] = {1.5,2.5,2.5,5,10};
	
	float BsXsecPPY2015[NBins2015] = {2610000,744000,197000,46500,5300};
	float BsXSecPPYErrDown2015[NBins2015] = {170000,29000,9000,2400,500};
	float BsXSecPPYErrUp2015[NBins2015] = {170000,29000,9000,2400,500};
*/
	const int NBins2015 = 3;
	float BsXsecPPX2015[NBins2015] = {11,17.5,35.0};
	float BsXSecPPXErrDown2015[NBins2015] = {4,2.5,15};
	float BsXSecPPXErrUp2015[NBins2015] = {4,2.5,15};
	
	float BsXsecPPY2015[NBins2015] = {316000,34100,3830};
	float BsXSecPPYErrDown2015[NBins2015] = {37000,6300,670};
	float BsXSecPPYErrUp2015[NBins2015] = {37000,6300,670};

	float BsXSecPPYSystDown2015[NBins2015] = {62000,3200,360};
	float BsXSecPPYSystUp2015[NBins2015] = {62000,3200,360};


	TGraphAsymmErrors *BsPPCrossGraph2015 = new TGraphAsymmErrors(NBins2015, BsXsecPPX2015, BsXsecPPY2015,BsXSecPPXErrDown2015, BsXSecPPXErrUp2015,BsXSecPPYErrDown2015,BsXSecPPYErrUp2015);
	TGraphAsymmErrors *BsPPCrossGraph2015Syst = new TGraphAsymmErrors(NBins2015, BsXsecPPX2015, BsXsecPPY2015,BsXSecPPXErrDown2015, BsXSecPPXErrUp2015,BsXSecPPYSystDown2015,BsXSecPPYSystUp2015);



	BsPPCrossGraph2015Syst->SetFillColorAlpha(kGreen-9+2,0.5);
	BsPPCrossGraph2015Syst->SetLineColor(kGreen-9+2);




	BsPPCrossGraph2015->SetLineColor(kGreen+2);
	BsPPCrossGraph2015->SetMarkerStyle(33);
	BsPPCrossGraph2015->SetMarkerSize(1);
	BsPPCrossGraph2015->SetMarkerColor(kGreen+2);
	BsPPCrossGraph2015->Draw("epSAME");


	BsPPCrossGraph2015Syst->Draw("5same");	




	BsPPCrossGraph2D->SetLineColor(kOrange+1);
	BsPPCrossGraph2D->SetMarkerStyle(34);
	BsPPCrossGraph2D->SetMarkerSize(1);
	BsPPCrossGraph2D->SetMarkerColor(kOrange+1);
	BsPPCrossGraph2D->Draw("epSAME");







	TFile * finFONLL = new TFile("FONLLs/BsFONLL.root");
	finFONLL->cd();
	TGraphAsymmErrors *BsFONLL = (TGraphAsymmErrors*) finFONLL->Get("gaeSigmaBplus");
	BsFONLL->SetLineColor(kRed+2);
	BsFONLL->SetMarkerStyle(20);
	BsFONLL->SetMarkerSize(1);
	BsFONLL->SetMarkerColor(kRed+2);
	BsFONLL->Draw("epSAME");



	TFile * finFONLL2 = new TFile("FONLLs/BsFONLLFid.root");
	finFONLL2->cd();
	TGraphAsymmErrors *BsFONLL2 = (TGraphAsymmErrors*) finFONLL2->Get("gaeSigmaBplus");
	BsFONLL2->SetLineColor(kRed+2);
	BsFONLL2->SetMarkerStyle(20);
	BsFONLL2->SetMarkerSize(1);
	BsFONLL2->SetMarkerColor(kRed+2);
	BsFONLL2->Draw("epSAME");


	double XTempChange;
	double YTempChange;
	double YErrLowTemp;
	double YErrHighTemp;

	for(int i = 0; i < 1; i ++){

		BsFONLL2->GetPoint(i,XTempChange,YTempChange);
		YErrLowTemp = BsFONLL2->GetErrorYlow(i);
		YErrHighTemp = BsFONLL2->GetErrorYhigh(i);

		BsFONLL->SetPoint(i,XTempChange,YTempChange);
		BsFONLL->SetPointEYhigh(i,YErrHighTemp);
		BsFONLL->SetPointEYlow(i,YErrLowTemp);



	}

	TLegend* leg3 = new TLegend(0.37,0.50,0.70,0.80,NULL,"brNDC");
	leg3->SetBorderSize(0);
	leg3->SetTextSize(0.040);
	leg3->SetTextFont(42);
	leg3->SetFillStyle(0);
	leg3->SetLineWidth(3);
	leg3->AddEntry(BsPPCrossGraph,"2017 pp 5.02 TeV","PL");
	leg3->AddEntry(BsPPCrossGraph2D,"2017 pp 5.02 TeV (2D Map)","PL");	
	leg3->AddEntry(BsPPCrossGraph2015,"2015 pp 5.02 TeV","PL");
	leg3->AddEntry(BsFONLL,"FONLL Calculations","PL");
	leg3->Draw("same");



	MyPad1->Update();




	//Ratio

	float Ratio1Y[NBins2015];
	float Ratio1YErr[NBins2015];
	
	float Ratio2Y[NBins2015];
	float Ratio2YErr[NBins2015];



	for(int i = 1; i < NBins2015; i++){

		Ratio1Y[i] = BsXsecPPY[i+1]/BsXsecPPY2015[i];
		Ratio1YErr[i] = Ratio1Y[i] * sqrt(BsXSecPPYErrDown[i+1]/BsXsecPPY[i+1] * BsXSecPPYErrDown[i+1]/BsXsecPPY[i+1] + BsXSecPPYErrDown2015[i]/BsXsecPPY2015[i] * BsXSecPPYErrDown2015[i]/BsXsecPPY2015[i]);

	//	cout << "BsXSecPPYErrDown2015[i]/BsXsecPPY2015[i] = " << BsXSecPPYErrDown[i+1]/BsXsecPPY[i+1]  << endl;
			

	//	cout << "sqrt(BsXSecPPYErrDown[i+1]/BsXsecPPY[i+1] * BsXSecPPYErrDown[i+1]/BsXsecPPY[i+1] + BsXSecPPYErrDown2015[i]/BsXsecPPY2015[i] * BsXSecPPYErrDown2015[i]/BsXsecPPY2015[i]) = " << sqrt(BsXSecPPYErrDown[i+1]/BsXsecPPY[i+1] * BsXSecPPYErrDown[i+1]/BsXsecPPY[i+1] + BsXSecPPYErrDown2015[i]/BsXsecPPY2015[i] * BsXSecPPYErrDown2015[i]/BsXsecPPY2015[i]) << endl;

		Ratio2Y[i] = BsXsecPPY2D[i+1]/BsXsecPPY2015[i];
		Ratio2YErr[i] = Ratio2Y[i] *TMath::Sqrt(BsXSecPPY2DErrDown[i+1]/BsXsecPPY2D[i+1] * BsXSecPPY2DErrDown[i+1]/BsXsecPPY2D[i+1] + BsXSecPPYErrDown2015[i]/BsXsecPPY2015[i] * BsXSecPPYErrDown2015[i]/BsXsecPPY2015[i] );


	}

	Ratio1Y[0] = -1;
	Ratio1YErr[0] = 0.001;
	Ratio2Y[0] = -1;
	Ratio2YErr[0] = 0.001;


	cRatio->cd();



	MyPad2->cd();


	TH2D * HisEmpty3 = new TH2D("HisEmpty3","",100,7,50,100,0,2);
	HisEmpty3->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	HisEmpty3->GetYaxis()->SetTitle("2017/2015 Data");
	HisEmpty3->GetXaxis()->CenterTitle();
	HisEmpty3->GetYaxis()->CenterTitle();
	HisEmpty3->GetYaxis()->SetTitleOffset(1.2);
	HisEmpty3->Draw();


	TGraphAsymmErrors *Ratio1 = new TGraphAsymmErrors(NBins2015, BsXsecPPX2015, Ratio1Y ,BsXSecPPXErrDown2015, BsXSecPPXErrUp2015,Ratio1YErr,Ratio1YErr);
	
	TGraphAsymmErrors *Ratio2 = new TGraphAsymmErrors(NBins2015, BsXsecPPX2015, Ratio2Y,BsXSecPPXErrDown2015, BsXSecPPXErrUp2015,Ratio2YErr,Ratio2YErr);

	Ratio1->SetLineColor(kBlue+2);
	Ratio1->SetMarkerStyle(21);
	Ratio1->SetMarkerSize(1);
	Ratio1->SetMarkerColor(kBlue+2);
	Ratio1->Draw("epSAME");




	Ratio2->SetLineColor(kOrange+1);
	Ratio2->SetMarkerStyle(34);
	Ratio2->SetMarkerSize(1);
	Ratio2->SetMarkerColor(kOrange+1);
	Ratio2->Draw("epSAME");


	TLine * Unity2 = new TLine(7,1,50,1);
	Unity2->SetLineWidth(2);
	Unity2->SetLineStyle(2);
	Unity2->SetLineColor(1);
	Unity2->Draw("SAME");




	MyPad2->Update();


	//FONLL




	float Ratio3Y[NBins];
	float Ratio3YErr[NBins];
	
	float Ratio4Y[NBins];
	float Ratio4YErr[NBins];

	float FONLLY[NBins];
	float FONLLYErr[NBins];


	
	double XTempFONLL;
	double YTempFONLL;

	for(int i = 0; i < NBins; i++){

		
		BsFONLL->GetPoint(i,XTempFONLL,YTempFONLL);
		FONLLY[i] = YTempFONLL;
		FONLLYErr[i] = BsFONLL->GetErrorYhigh (i);


	//	FONLLY[i] = BsFONLL->GetPointY(i);
	//	FONLLYErr[i] = BsFONLL->GetErrorYhigh (i);

		Ratio3Y[i] = BsXsecPPY[i]/FONLLY[i];
		Ratio3YErr[i] = Ratio3Y[i] * sqrt(BsXSecPPYErrDown[i]/BsXsecPPY[i] * BsXSecPPYErrDown[i]/BsXsecPPY[i] + FONLLYErr[i]/FONLLY[i] * FONLLYErr[i]/FONLLY[i]);

		Ratio4Y[i] = BsXsecPPY2D[i]/FONLLY[i];
		Ratio4YErr[i] = Ratio4Y[i] *TMath::Sqrt(BsXSecPPY2DErrDown[i]/BsXsecPPY2D[i] * BsXSecPPY2DErrDown[i]/BsXsecPPY2D[i] + FONLLYErr[i]/FONLLY[i] * FONLLYErr[i]/FONLLY[i] );


	}

	cRatio->cd();



	MyPad3->cd();



	TH2D * HisEmpty4 = new TH2D("HisEmpty4","",100,7,50,100,0,2);
	HisEmpty4->GetXaxis()->SetTitle("B^{0}_{s} p_{T} (GeV/c)");
	HisEmpty4->GetYaxis()->SetTitle("2017 Data/FONLL");
	HisEmpty4->GetXaxis()->CenterTitle();
	HisEmpty4->GetYaxis()->CenterTitle();
	HisEmpty4->GetYaxis()->SetTitleOffset(1.2);
	HisEmpty4->Draw();


	TGraphAsymmErrors *Ratio3 = new TGraphAsymmErrors(NBins, BsXsecPPX, Ratio3Y ,BsXSecPPXErrDown, BsXSecPPXErrUp,Ratio3YErr,Ratio3YErr);

	TGraphAsymmErrors *Ratio4 = new TGraphAsymmErrors(NBins, BsXsecPPX, Ratio4Y,BsXSecPPXErrDown, BsXSecPPXErrUp,Ratio4YErr,Ratio4YErr);

	Ratio3->SetLineColor(kBlue+2);
	Ratio3->SetMarkerStyle(21);
	Ratio3->SetMarkerSize(1);
	Ratio3->SetMarkerColor(kBlue+2);
	Ratio3->Draw("epSAME");




	Ratio4->SetLineColor(kOrange+1);
	Ratio4->SetMarkerStyle(34);
	Ratio4->SetMarkerSize(1);
	Ratio4->SetMarkerColor(kOrange+1);
	Ratio4->Draw("epSAME");



	Unity2->Draw("SAME");




	MyPad2->Update();








	cRatio->SaveAs("Plots/Bs/BsCrossComp.png");
//	cRatio->SetLogy();

	//MyPad1->SetLogy();
	
	MyPad1->SetLogy();
	MyPad1->Update();

	cRatio->SaveAs("Plots/Bs/BsCrossCompLog.png");

	cRatio->SaveAs("Plots/Bs/BsCrossCompLog.pdf");




	//FONLL






}
