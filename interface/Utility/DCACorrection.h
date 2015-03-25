// copied from DesyHTauTau/TauTauSkimming/interface/DCACorrection.h

#include "Artus/Utility/interface/ArtusLogging.h"

#include "TH1.h"
#include "TF1.h"
#include "TROOT.h"
#include "TFile.h"
#include "TMath.h"


#include <string>
#include <iostream>
#include <vector>

using namespace std;


class DCACorrection{
  
 private:
  TFile* fileData;
  TFile* fileMC;
  TF1* DCAdata[3][3][4];
  TF1* DCAmc[3][3][4]; 
  float dmaxMC[3][3][4];
  float dminMC[3][3][4];
  float dmaxData[3][3][4]; 
  float dminData[3][3][4]; 
  float intDcaMC[3][3][4];
  float intDcaData[3][3][4];
  TString pPlus[3];
  TString pMin[3];
  TString ang[4];
  float pPlusf[4];
  float pMinf[4];
  float angf[5];
 public:
  DCACorrection();
  ~DCACorrection();
  void initialize(//TString baseDir,
		  TString fileNameData,
		  TString fileNameMC);
  float DCAcorrected(float dca, float ptplus, float ptminus, float angle);
  int binNumber(float x, int nbins, float * bins) {

    int binN = 0;

    for (int iB=0; iB<nbins; ++iB) {
      if (x>=bins[iB]&&x<bins[iB+1]) {
	binN = iB;
	break;
      }
    }
    
    return binN;

  }
  float _DCAcorrected;

};

