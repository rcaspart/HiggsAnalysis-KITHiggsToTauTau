// copied from DesyHTauTau/TauTauSkimming/src/DCACorrection.cc

#include "HiggsAnalysis/KITHiggsToTauTau/interface/Utility/DCACorrection.h"

DCACorrection::DCACorrection() {}
DCACorrection::~DCACorrection() {}

void DCACorrection::initialize(//TString baseDir,
                               TString fileNameData,
                               TString fileNameMC){

  pPlus[0]=TString("pPlusp30"); // 30 < pT,mu1 + pT,mu2 < 50 
  pPlus[1]=TString("pPlusp50"); // 50 < pT,mu1 + pT,mu2 < 100
  pPlus[2]=TString("pPlusp100"); // 100 < pT,mu1 + pT,mu2

  pMin[0]=TString("pMinp0"); // 0 < pT,mu1 - pT,mu2 < 10 
  pMin[1]=TString("pMinp10"); // 10 < pT,mu1 - pT,mu2 < 30 
  pMin[2]=TString("pMinp30"); // 30 < pT,mu1 - pT,mu2

  ang[0]=TString("cosMin1");  // -1.0 < angle(mu1, mu2) < -0.5
  ang[1]=TString("cosMin05");  // -0.5 < angle(mu1, mu2) < 0.0
  ang[2]=TString("cos0");  // 0.0 < angle(mu1, mu2) < 0.5
  ang[3]=TString("cos05");  // 0.5 < angle(mu1, mu2) < 1.0

  fileData = new TFile(/*baseDir + "/"+*/fileNameData);
  fileMC = new TFile(/*baseDir + "/"++*/fileNameMC);

  LOG(DEBUG) << "File DCA corr data : " << fileData << "  " << fileNameData;
  LOG(DEBUG) << "File DCA corr MC   : " << fileMC   << "  " << fileNameMC;


  pPlusf[0]=30.;
  pPlusf[1]=50.;
  pPlusf[2]=100.;
  pPlusf[3]=9999.;

  pMinf[0]=0.;
  pMinf[1]=10.;
  pMinf[2]=30.;
  pMinf[3]=9999.;

  angf[0]=-1;
  angf[1]=-0.5;
  angf[2]=0;
  angf[3]=0.5;
  angf[4]=9999.;

  for(int k=0; k<3 ; ++k) {
    for(int j=0; j<3 ; ++j) {
      int iMax = 4;
      if (k==0 && j==0)
        iMax = 2;
      if (k==0 && j==1)
        iMax = 1;
      if (k==0 && j==2)
        iMax = 0;
      for(int i=0; i<iMax ; ++i) {
	LOG(DEBUG) << "[k,j,i]=[" << k << "," << j << "," << i << "]    :   "
                  << pPlus[k]+pMin[j]+ang[i]+"_Full_func";
        DCAdata[k][j][i] = (TF1*)fileData->Get(pPlus[k]+pMin[j]+ang[i]+"_Full_func");
        DCAmc[k][j][i]   = (TF1*)fileMC->Get(pPlus[k]+pMin[j]+ang[i]+"_Full_func");
        double rMin;
        double rMax;
	LOG(DEBUG) << "   Data : Func = " << DCAdata[k][j][i];
	LOG(DEBUG) << "   MC   : Func = " << DCAmc[k][j][i];
        DCAdata[k][j][i]->GetRange(rMin,rMax);
        dmaxData[k][j][i] = float(rMax);
        dminData[k][j][i] = float(rMin);
	LOG(DEBUG) << "   Data : Dmin = " << dminData[k][j][i] << "    Dmax = " << dmaxData[k][j][i];
        DCAmc[k][j][i]->GetRange(rMin,rMax);
        dmaxMC[k][j][i] = float(rMax);
        dminMC[k][j][i] = float(rMin);
	LOG(DEBUG) << "   MC   : Dmin = " << dminMC[k][j][i] << "    Dmax = " << dmaxMC[k][j][i];
        intDcaData[k][j][i] = float(DCAdata[k][j][i]->Integral(dminData[k][j][i],dmaxData[k][j][i]));
	LOG(DEBUG) << "   Data : Int = " << intDcaData[k][j][i];
        intDcaMC[k][j][i] = float(DCAmc[k][j][i]->Integral(dminMC[k][j][i],dmaxMC[k][j][i]));
	LOG(DEBUG) << "   MC   : Int = " << intDcaMC[k][j][i];
      }
    }
  }


}

float DCACorrection::DCAcorrected(float dca, float ptplus, float ptminus, float angle){

  _DCAcorrected = dca;

  int nSumProb = 1;
  double q[1];
  double sumProb[1];

  int k = binNumber(ptplus,3,pPlusf);
  int j = binNumber(ptminus,3,pMinf);
  int i = binNumber(angle,4,angf);

  if (_DCAcorrected>2) {
    LOG(DEBUG);
    LOG(DEBUG) << " ptplus = " << ptplus << "  ;  ptminus = " << ptminus << "  ;  angle = " << angle;
    LOG(DEBUG) << " [k,j,i] = [" << k << "," << j << "," << i << "]";
    LOG(DEBUG) << "DCA Corrected = " << _DCAcorrected;
  }

  if (k==0 && j==0 && i>1)
    return dca;
  if (k==0 && j==1 && i>0)
    return dca;
  if (k==0 && j==2)
    return dca;

  if(dca>dminMC[k][j][i] && dca<dmaxMC[k][j][i] && ptplus>30) {
    sumProb[0] = DCAmc[k][j][i]->Integral(dminMC[k][j][i],dca)/intDcaMC[k][j][i];
    if (sumProb[0]<1) {
      DCAdata[k][j][i]->GetQuantiles(nSumProb,q,sumProb);
      _DCAcorrected = float(q[0]);

      //      LOG(DEBUG) << " sumProb = " << sumProb[0];
      //      LOG(DEBUG) << " ptplus = " << ptplus << "  ;  ptminus = " << ptminus << "  ;  angle = " << angle;
      //	LOG(DEBUG) << " [k,j,i] = [" << k << "," << j << "," << i << "]";
      //	LOG(DEBUG) << " calculating quantiles...";
      //	LOG(DEBUG) << " Data Full integral = " << DCAdata[k][j][i]->Integral(dminData[k][j][i],dmaxData[k][j][i]);
      //	LOG(DEBUG) << " MC Full integral   = " << DCAmc[k][j][i]->Integral(dminMC[k][j][i],dmaxMC[k][j][i]);
      //	LOG(DEBUG) << " Data integral to dca corr = " << DCAdata[k][j][i]->Integral(dminData[k][j][i],_DCAcorrected);
      //	LOG(DEBUG) << " MC   integral to dca      = " << DCAmc[k][j][i]->Integral(dminMC[k][j][i],dca);
      //	LOG(DEBUG) << " DCA : "<< dca;
      //	LOG(DEBUG) << " corrected : "<< _DCAcorrected;

    }
  }
  /*   LOG(DEBUG) << " DCA : "<< dca; */
  /*   LOG(DEBUG) << " corrected : "<< _DCAcorrected; */
  /*   LOG(DEBUG); */

  return _DCAcorrected;


}
