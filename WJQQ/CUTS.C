#include <TH1D.h>
#include <TMath.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <TVector3.h>
#include <TTree.h>
#include <xsecs.h>



void CUTS(int ibatch, int ikind, int mchi, int mglu, float xsec){

  string fin="";

  gROOT->ProcessLine(".L xsecs.h");

  if(ikind == 0 ) fin ="/cms/kyriacou/NtuplesJan18/DATAJG/datag.root";

  if(ikind == 4 ) fin ="/cms/kyriacou/NtuplesJan18//SIG/sig.root";
  //  if(ikind == 4 ) fin ="/cms/kyriacou/Ntuples/SIG/sig.root";
  if(ikind == 5 ) fin ="/cms/kyriacou/NtuplesJan18/TT/top.root";
  if(ikind == 6 ) fin ="/cms/kyriacou/NtuplesJan18/WJQQ/wjqq.root";

  if(ikind == 10 ) fin ="/cms/kyriacou/NtuplesJan18/Q35/q35.root";
  if(ikind == 11 ) fin ="/cms/kyriacou/NtuplesJan18/Q57/q57.root";
  if(ikind == 12 ) fin ="/cms/kyriacou/NtuplesJan18/Q71/Q71.root";
  if(ikind == 13 ) fin ="/cms/kyriacou/NtuplesJan18/Q15/q115.root";
  if(ikind == 14 ) fin ="/cms/kyriacou/NtuplesJan18/Q52/q52.root";
  if(ikind == 15 ) fin ="/cms/kyriacou/NtuplesJan18/Q2/q2.root";
  if(ikind == 16 ) fin ="/cms/kyriacou/NtuplesJan18/Q35/q35ext.root";
  if(ikind == 17 ) fin ="/cms/kyriacou/NtuplesJan18/Q57/q57ext.root";
  if(ikind == 18 ) fin ="/cms/kyriacou/NtuplesJan18/Q71/Q71ext.root";
  if(ikind == 19 ) fin ="/cms/kyriacou/NtuplesJan18/Q15/q15ext.root";
  if(ikind == 20 ) fin ="/cms/kyriacou/NtuplesJan18/Q52/q52ext.root";
  if(ikind == 21 ) fin ="/cms/kyriacou/NtuplesJan18/Q2/Q2ext.root";
  
  /*

  if(ikind == 10 ) fin ="/cms/kyriacou/Ntuples/QCD/Q35/q35.root";
  if(ikind == 11 ) fin ="/cms/kyriacou/Ntuples/QCD/Q57/q57.root";
  if(ikind == 12 ) fin ="/cms/kyriacou/Ntuples/QCD/Q71/q71.root";
  if(ikind == 13 ) fin ="/cms/kyriacou/Ntuples/QCD/Q115/q115.root";
  if(ikind == 14 ) fin ="/cms/kyriacou/Ntuples/QCD/Q152/q152.root";
  if(ikind == 15 ) fin ="/cms/kyriacou/Ntuples/QCD/Q2/q2.root";
  if(ikind == 16 ) fin ="/cms/kyriacou/Ntuples/QCD/Q35/q35ext.root";
  if(ikind == 17 ) fin ="/cms/kyriacou/Ntuples/QCD/Q57/q57ext.root";
  if(ikind == 18 ) fin ="/cms/kyriacou/Ntuples/QCD/Q71ext/q71ext.root";
  if(ikind == 19 ) fin ="/cms/kyriacou/Ntuples/QCD/Q115ext/q115ext.root";
  if(ikind == 20 ) fin ="/cms/kyriacou/Ntuples/QCD/Q152ext/q52ext.root";
  if(ikind == 21 ) fin ="/cms/kyriacou/Ntuples/QCD/Q2ext/q2ext.root";
  */


  const char *finc = fin.c_str();
  TFile *f12 = new TFile(finc);
  f12->cd();
  demo->cd();

  TH2D *NJLT    = new TH2D("NJLT","",5,0,5,5,0,5);
  TH1D * mas22 = new TH1D("mas22","",100,0,2);
  TH1D *NJ_all  = new TH1D("NJ_all","",100,0,100);
  TH1D *Nvtx_all  = new TH1D("Nvtx_all","",50,0,100);
  TH1D *L0     = new TH1D("L0","",36,200,2000); //,10,-5,5);
  TH1D *L1     = new TH1D("L1","",36,200,2000); //,10,-5,5);
  TH1D *L11    = new TH1D("L11","",36,200,2000); //,10,-5,5);
  TH1D *T1     = new TH1D("T1","",36,200,2000); //,10,-5,5);
  TH1D *TR     = new TH1D("TR","",36,200,2000); //,10,-5,5);
  TH1D *LR     = new TH1D("LR","",36,200,2000); //,10,-5,5);

  TH1D *drL0   = new TH1D("drL0","",60,0,6); //,10,-5,5);
  TH1D *drL1   = new TH1D("drL1","",60,0,6); //,10,-5,5);
  TH1D *drT1   = new TH1D("drT1","",60,0,6); //,10,-5,5);

  TH1D *TReta     = new TH1D("TReta","",20,-5,5);
  TH1D *LReta     = new TH1D("LReta","",20,-5,5);
  TH1D *T1eta     = new TH1D("T1eta","",20,-5,5);
  TH1D *L1eta     = new TH1D("L1eta","",20,-5,5);
  TH1D *L0eta     = new TH1D("L0eta","",20,-5,5);

  TH2F *T1etapt     = new TH2F("T1etapt","",8,-2,2,10,200,1200);
  TH2F *LforT1etapt = new TH2F("LforT1etapt","",8,-2,2,10,200,1200);
  TH2F *L0etapt     = new TH2F("L0etapt","",8,-2,2,8,200,2000);
  TH2F *L1etapt     = new TH2F("L1etapt","",8,-2,2,8,200,2000);

  TH1D *LM     = new TH1D("LM","",50,0,1000); //,10,-5,5);
  TH1D *TM     = new TH1D("TM","",50,0,1000); //,10,-5,5);
  TH1D *L2M     = new TH1D("L2M","",50,0,1000); //,10,-5,5);


  TH1D *LT00M  = new TH1D("LT00M","",50,0,1000); //,10,-5,5);
  TH1D *LT10M  = new TH1D("LT10M","",50,0,1000); //,10,-5,5);
  TH1D *LT11M  = new TH1D("LT11M","",50,0,1000); //,10,-5,5);
  TH1D *LT20M  = new TH1D("LT20M","",50,0,1000); //,10,-5,5);
  TH1D *LT21M  = new TH1D("LT21M","",50,0,1000); //,10,-5,5);
  TH1D *LT21MT = new TH1D("LT21MT","",50,0,1000); //,10,-5,5);
  TH1D *LT22M  = new TH1D("LT22M","",50,0,1000); //,10,-5,5);

  TH1D *LT00Mav  = new TH1D("LT00Mav","",50,0,1000); //,10,-5,5);
  TH1D *LT20Mav  = new TH1D("LT20Mav","",50,0,1000); //,10,-5,5);
  TH1D *LT21Mav  = new TH1D("LT21Mav","",50,0,1000); //,10,-5,5);
  TH1D *LT22Mav  = new TH1D("LT22Mav","",50,0,1000); //,10,-5,5);

  TH2F *LT20M_2d  = new TH2F("LT20M_2d","",50,0,1000,50,0,1000);
  TH2F *LT21M_2d  = new TH2F("LT21M_2d","",50,0,1000,50,0,1000);
  TH2F *LT22M_2d  = new TH2F("LT22M_2d","",50,0,1000,50,0,1000);


  TH1D *LT20ht     = new TH1D("LT20ht","",30,1000,4000);
  TH1D *LT21ht     = new TH1D("LT21ht","",30,1000,4000);
  TH1D *LT22ht     = new TH1D("LT22ht","",30,1000,4000);

  TH1D *LT10ht     = new TH1D("LT10ht","",30,1000,4000);
  TH1D *LT11ht     = new TH1D("LT11ht","",30,1000,4000);
  TH1D *LT00ht     = new TH1D("LT00ht","",30,1000,4000);

  TH2F *LT22m_ht   = new TH2F("LT22m_ht","",30,1000,4000,50,0,1000);
  TH2F *LT21m_ht   = new TH2F("LT21m_ht","",30,1000,4000,50,0,1000);
  TH2F *LT20m_ht   = new TH2F("LT20m_ht","",30,1000,4000,50,0,1000);



  TH1D *h_phopt       = new TH1D("h_phopt","",100,0,1000);
  TH1D *h_t31         = new TH1D("h_t31","",100,0,1);
  TH1D *h_haspho      = new TH1D("h_haspho","",18,-1,2);
  TH1D *h_subjf       = new TH1D("h_subjf","",100,0,1);

  TH2F *h_subjfmass   = new TH2F("h_subjfmass","",100,0,1,500,0,1000);
  TH2F *h_subjfpt     = new TH2F("h_subjfpt","",100,0,1,200,0,2000);


  TH1D *h_phosieieB   = new TH1D("h_phosieieB","",80,0.004,0.012);
  TH1D *h_phosieieE   = new TH1D("h_phosieieE","",40,0.02,0.03);
  TH1D *h_phohoe      = new TH1D("h_phohoe","",100,0,0.15);
  TH1D *h_phohoeL      = new TH1D("h_phohoeL","",100,0,0.15);
  TH1D *h_phohoeL_m   = new TH1D("h_phohoeL_m","",100,0,0.15);
  TH1D *h_phohaspix   = new TH1D("h_phohaspix","",100,-1,2);
  TH1D *h_spt1        = new TH1D("h_spt1","",100,0,1000);
  TH1D *h_spt2        = new TH1D("h_spt2","",100,0,1000);
  TH1D *h_spt3        = new TH1D("h_spt3","",100,0,1000);

  TH1D *h_phopt_m     = new TH1D("h_phopt_m","",100,0,1000);
  TH1D *h_t31_m       = new TH1D("h_t31_m","",100,0,1);
  TH1D *h_haspho_m    = new TH1D("h_haspho_m","",18,-1,2);
  TH1D *h_subjf_m     = new TH1D("h_subjf_m","",100,0,1);
  TH1D *h_subjfL      = new TH1D("h_subjfL","",100,0,1);
  TH1D *h_subjfL_m    = new TH1D("h_subjfL_m","",100,0,1);

  TH2F *h_subjfmass_m    = new TH2F("h_subjfmass_m","",100,0,1,500,0,1000);
  TH2F *h_subjfpt_m      = new TH2F("h_subjfpt_m","",100,0,1,200,0,2000);
  TH2F *h_subjfptL_m     = new TH2F("h_subjfptL_m","",100,0,1,200,0,2000);
  TH2F *h_subjfmassL_m   = new TH2F("h_subjfmassL_m","",100,0,1,500,0,1000);


  TH1D *h_phosieieB_m = new TH1D("h_phosieieB_m","",80,0.004,0.012);
  TH1D *h_phosieieE_m = new TH1D("h_phosieieE_m","",40,0.02,0.03);
  TH1D *h_phohoe_m    = new TH1D("h_phohoe_m","",100,0,0.15);
  TH1D *h_phohaspix_m = new TH1D("h_phohaspix_m","",100,-1,2);
  TH1D *h_spt1_m      = new TH1D("h_spt1_m","",100,0,1000);
  TH1D *h_spt2_m      = new TH1D("h_spt2_m","",100,0,1000);
  TH1D *h_spt3_m      = new TH1D("h_spt3_m","",100,0,1000);

  TH1D *mallpt   = new TH1D("mallpt","",40,0,2000);
  TH1D *malleta  = new TH1D("malleta","",40,-5,5);
  TH1D *mallnvtx = new TH1D("mallnvtx","",35,0,70);
  TH1D *mallmass = new TH1D("mallmass","",200,0,400);
  

  TH1D *mLpt   = new TH1D("mLpt","",40,0,2000);
  TH1D *mLeta  = new TH1D("mLeta","",40,-5,5);
  TH1D *mLnvtx = new TH1D("mLnvtx","",35,0,70);
  TH1D *mLmass = new TH1D("mLmass","",200,0,400);


  TH1D *mTpt   = new TH1D("mTpt","",40,0,2000);
  TH1D *mTeta  = new TH1D("mTeta","",40,-5,5);
  TH1D *mTnvtx = new TH1D("mTnvtx","",35,0,70);
  TH1D *mTmass = new TH1D("mTmass","",200,0,400);

  TH1F *hdummy = new TH1F("hdummy","",100,0,10);



  Nvtx_all->Sumw2();
  
  h_t31->Sumw2();
  h_haspho->Sumw2();
  h_subjf->Sumw2();
  h_phopt->Sumw2();
  h_phosieieB->Sumw2();
  h_phosieieE->Sumw2();
  h_phohoe->Sumw2();
  h_phohaspix->Sumw2();
  h_spt1->Sumw2();
  h_spt2->Sumw2();
  h_spt3->Sumw2();

  h_t31_m->Sumw2();
  h_haspho_m->Sumw2();
  h_subjf_m->Sumw2();
  h_subjfL->Sumw2();
  h_subjfL_m->Sumw2();
  h_phopt_m->Sumw2();
  h_phosieieB_m->Sumw2();
  h_phosieieE_m->Sumw2();
  h_phohoe_m->Sumw2();
  h_phohaspix_m->Sumw2();
  h_spt1_m->Sumw2();
  h_spt2_m->Sumw2();
  h_spt3_m->Sumw2();



  TReta->Sumw2();
  LReta->Sumw2();
  T1eta->Sumw2();
  L1eta->Sumw2();
  L0eta->Sumw2();

  T1etapt->Sumw2();
  L0etapt->Sumw2();
  L1etapt->Sumw2();
  LforT1etapt->Sumw2();

  mallpt->Sumw2();
  malleta->Sumw2();
  mallnvtx->Sumw2();
  mallmass->Sumw2();
  
  mLpt->Sumw2();
  mLeta->Sumw2();
  mLnvtx->Sumw2();
  mLmass->Sumw2();
  
  mTpt->Sumw2();
  mTeta->Sumw2();
  mTnvtx->Sumw2();
  mTmass->Sumw2();





  drL0->Sumw2();
  drL1->Sumw2();
  drT1->Sumw2();



  //Setting output
  ostringstream btc;
  btc << ibatch;
  string  fout  = "./Plots/Plots_"+btc.str()+".root";
  string  fcut  = "./CutPlots/cuts_"+btc.str()+".root";
  string  ftree = "./JetTrees/jetTree_"+btc.str()+".root";
  if(ikind == 4){
    ostringstream mch;
    ostringstream mgl;
    mch<<mchi;
    mgl<<mglu;
    fout = "./FewMassP/chi_"+mch.str()+"glu_"+mgl.str()+"_"+btc.str()+".root";
    fcut = "./FewMassP/cuts_chi_"+mch.str()+"glu_"+mgl.str()+"_"+btc.str()+".root";
    ftree = "./FewMassP/jetTree_nj3_"+mch.str()+"glu_"+mgl.str()+"_"+btc.str()+".root";
  }
  const char *foutc = fout.c_str();
  const char *fcutc = fcut.c_str();
  const char *ftreec = ftree.c_str();

  

  
  TFile *f1 = new TFile(foutc,"recreate");
  f1->cd();
  hdummy->Write();
  TFile *f2 = new TFile(ftreec,"recreate");
  f2->cd();
  hdummy->Write();

  TTree *ev =  new TTree("ev","treeofJets");
  
  
  TFile *f23 = new TFile(fcutc,"recreate");
  f23->cd();
  hdummy->Write();



  vector<int> isLoose;
  vector<int> isTight;
  vector<float> ak8pt;
  vector<float> ak8phi;
  vector<float> ak8eta;

  vector<float> ak4pt;
  vector<float> ak4phi;
  vector<float> ak4eta;


  vector<float> ak8m;
  vector<int>   phoindx;
  float htak4;
  int NVTX;
  float xsweight;

  ev->Branch("htak4",&htak4,"htak4/F");
  ev->Branch("NVTX",&NVTX,"NVTX/I");
 
  ev->Branch("isLoose",&isLoose);
  ev->Branch("isTight",&isTight);
  ev->Branch("ak8pt",&ak8pt);
  ev->Branch("ak8phi",&ak8phi);
  ev->Branch("ak8eta",&ak8eta);
  ev->Branch("ak4pt",&ak4pt);
  ev->Branch("ak4phi",&ak4phi);
  ev->Branch("ak4eta",&ak4eta);
  ev->Branch("ak8m",&ak8m);
  ev->Branch("phoindx",&phoindx);
  ev->Branch("xsweight",&xsweight,"xsweight/F");

  f12->cd();
  demo->cd();
  int NJ;
  float HTak4;
  int nvtx;
  

  L0->Sumw2();
  T1->Sumw2();
  L1->Sumw2();
  L11->Sumw2();

  LR->Sumw2();
  TR->Sumw2();

  vector<float> *ak8ptC;
  vector<float> *ak8phiC;
  vector<float> *ak8etaC;


  vector<float> *ak4ptC;
  vector<float> *ak4phiC;
  vector<float> *ak4etaC;



  vector<float> *ak8t3t1C;
  vector<float> *ak8subjC;
  vector<float> *ak8phoindxC;
  vector<float> *ak8subindxC;
  vector<float> *ak8prMassC;
  vector<float> *ak8spt1;
  vector<float> *ak8spt2;
  vector<float> *ak8spt3;

  //photon quantites

  vector<float> *phopt;
  vector<float> *phoeta;
  vector<float> *phophi;
  vector<float> *phohoe;
  vector<float> *phosieie;
  vector<float>   *phohaspixelseed;


  //mc quantities //only relevant for signal sample
  float mcglumass;
  float mcchimass;
  vector<float> *mcchipt;
  vector<float> *mcchieta;
  vector<float> *mcchiphi;

  vector<float> *mcphopt;
  vector<float> *mcphoeta;
  vector<float> *mcphophi;

  event->SetBranchAddress("NJ",&NJ);
  event->SetBranchAddress("HTak4",&HTak4);
  event->SetBranchAddress("nvtx",&nvtx);

  event->SetBranchAddress("ak8spt1",&ak8spt1);
  event->SetBranchAddress("ak8spt2",&ak8spt2);
  event->SetBranchAddress("ak8spt3",&ak8spt3);



  event->SetBranchAddress("ak4ptC",&ak4ptC);
  event->SetBranchAddress("ak4etaC",&ak4etaC);
  event->SetBranchAddress("ak4phiC",&ak4phiC);




  event->SetBranchAddress("ak8ptC",&ak8ptC);
  event->SetBranchAddress("ak8etaC",&ak8etaC);
  event->SetBranchAddress("ak8phiC",&ak8phiC);
  event->SetBranchAddress("ak8t3t1C",&ak8t3t1C);
  event->SetBranchAddress("ak8subjC",&ak8subjC);
  event->SetBranchAddress("ak8phoindxC",&ak8phoindxC);
  event->SetBranchAddress("ak8subindxC",&ak8subindxC);
  event->SetBranchAddress("ak8prMassC",&ak8prMassC);

  event->SetBranchAddress("phopt",&phopt);
  event->SetBranchAddress("phoeta",&phoeta);
  event->SetBranchAddress("phophi",&phophi);
  event->SetBranchAddress("phohoe",&phohoe);
  event->SetBranchAddress("phosieie",&phosieie);
  event->SetBranchAddress("phohaspixelseed",&phohaspixelseed);

  if(ikind == 4){
    event->SetBranchAddress("mcglumass",&mcglumass);
    event->SetBranchAddress("mcchimass",&mcchimass);
    event->SetBranchAddress("mcchipt",&mcchipt);
    event->SetBranchAddress("mcchieta",&mcchieta);
    event->SetBranchAddress("mcchiphi",&mcchiphi);
 
    event->SetBranchAddress("mcphopt",&mcphopt);
    event->SetBranchAddress("mcphoeta",&mcphoeta);
    event->SetBranchAddress("mcphophi",&mcphophi);
  }



  int initial = ibatch*100000;
  int final   = (1 + ibatch)*100000;
  int entt = event->GetEntries();
  if(final > entt ) final = entt;


  for(int i  = initial; i < final;   i++){
    event->GetEntry(i);

    
    if(ikind == 4){
      if(mcglumass < mglu - 20 || mcglumass >  mglu + 20 ) continue;
      if(mcchimass  >= 150){
	if( mcchimass < mchi  - 10  || mcchimass >  mchi + 10 ) continue;
      } else{
	if( mcchimass < mchi  - 5  || mcchimass >  mchi + 5   ) continue;
      }
    }


 

    NJ_all->Fill(NJ);
    //  cout<<nvxt<<endl;
    Nvtx_all->Fill(nvtx);

    // if( HTak4 < 1000) continue;
    if(NJ != 3   || HTak4 < 1000 ) continue;

    if(i % 1000 == 0 ) cout<<"entry: "<<i <<" "<<entt<<endl;
    htak4 = HTak4;
    NVTX = nvtx;
    



    isLoose.clear();
    isTight.clear();
    ak8pt.clear();
    ak8phi.clear();
    ak8eta.clear();

    ak4pt.clear();
    ak4phi.clear();
    ak4eta.clear();

    ak8m.clear();
    phoindx.clear();
    

    if(fabs((*ak8etaC)[0]) > 2 ) continue;
    if(fabs((*ak8etaC)[1]) > 2 ) continue;
    if(fabs((*ak8etaC)[2]) > 2 ) continue;


    bool pass = true;
    for(int ijet = 0 ; ijet < (*ak8ptC).size(); ijet++){
      TVector3 jv1;
      float jpt  = (*ak8ptC)[ijet];
      float jeta = (*ak8etaC)[ijet];
      float jphi = (*ak8phiC)[ijet];
      jv1.SetPtEtaPhi(jpt,jeta,jphi);
      for(int ijet2 = 0 ; ijet2 < (*ak8ptC).size(); ijet2++){
	if(ijet2 == ijet ) continue;
	float jpt2  = (*ak8ptC)[ijet2];
	float jeta2 = (*ak8etaC)[ijet2];
	float jphi2 = (*ak8phiC)[ijet2];
	TVector3 jv2;
	jv2.SetPtEtaPhi(jpt2,jeta2,jphi2);
	float dr12 = jv1.DeltaR(jv2);
	if(dr12 < 1.5 ) pass = false;
      }
    }

    if(!pass) continue;
    int it = 0;
    int il = 0;

    for(int iak4 = 0; iak4 < (*ak4ptC).size(); iak4++){
      float jpt  = (*ak4ptC)[iak4];
      float jeta = (*ak4etaC)[iak4];
      float jphi = (*ak4phiC)[iak4];

      ak4pt.push_back(jpt);
      ak4eta.push_back(jeta);
      ak4phi.push_back(jphi);

    }


    vector<int> phoI;
    phoI.clear();
    float mindr = 99;
    for (int ij = 0; ij < (*ak8ptC).size(); ij++){



      float jetpt  = (*ak8ptC)[ij];
      float jeteta = (*ak8etaC)[ij];

      if( fabs(jeteta) > 2.0 ) continue;



    


      float jetphi = (*ak8phiC)[ij];
      float jprm   = (*ak8prMassC)[ij]; 
      int   phoind = int( (*ak8phoindxC)[ij] );
      int   subind = int( (*ak8subindxC)[ij] );
      float t3t1   = (*ak8t3t1C)[ij];

    
      bool matchi = false;
      bool matpho = false;
      if( ikind == 4 ){
	TVector3 jv;
	jv.SetPtEtaPhi(jetpt,jeteta,jetphi);
	for(int ichii = 0; ichii < (*mcchipt).size(); ichii++){
	  float cpt  = (*mcchipt)[ichii];
	  float ceta = (*mcchieta)[ichii];
	  float cphi = (*mcchiphi)[ichii];
	  TVector3 chiv;
	  chiv.SetPtEtaPhi(cpt,ceta,cphi);
	  float drr = chiv.DeltaR(jv);
	  if(drr < 0.8 ) matchi = true;
	}
	for(int iphomc = 0; iphomc < (*mcphopt).size(); iphomc++){
	  float ppt  = (*mcphopt)[iphomc]; 
	  float peta = (*mcphoeta)[iphomc]; 
	  float pphi = (*mcphophi)[iphomc]; 
	  TVector3 phov; 
	  phov.SetPtEtaPhi(ppt,peta,pphi);
	  float drr = phov.DeltaR(jv);
	  if(drr< 0.7 ) matpho = true;
	}

	

	if(matchi && matpho ){
	  matchi = true; 
	}else{
	  matchi = false;
	}

      }
				  

      int haspixel =  0;
      float sieie = 100;
      float hoe = 100;;
      float peta = 0;
      float subjf = -1;
      int haspho = 0;


      h_haspho->Fill(haspho);
      
      if( !matchi) h_t31->Fill(t3t1);

      if(phoind >= 0 ){
	float ppt = (*phopt)[phoind];
        float sp1 = (*ak8spt1)[ij];
        float sp2 = (*ak8spt2)[ij];
        float sp3 = (*ak8spt3)[ij];
	float subpt = -1;
	float jmpr= (*ak8prMassC)[ij];
      
	subjf = (*ak8subjC)[ij];
        if(subind == 1 ) subpt = sp1;
        if(subind == 2 ) subpt = sp2;
	if(subind == 3 ) subpt = sp3;

	if( fabs(ppt/subpt -  subjf)  > 0.001 ){
	  for(int iphoo = 0; iphoo < (*phopt).size(); iphoo++){
	    float subjn = (*phopt)[iphoo]/subpt;
	    if( fabs(subjn - subjf) < 0.001 ) phoind = iphoo;
          }
        }


	haspho = 1;
	haspixel = (*phohaspixelseed)[phoind];
	sieie = (*phosieie)[phoind];
	hoe = (*phohoe)[phoind];
	peta = (*phoeta)[phoind];



	if(!matchi){

          h_spt1->Fill(sp1);
          h_spt2->Fill(sp2);
          h_spt3->Fill(sp3);
          h_phopt->Fill(ppt);
          h_phohoe->Fill(hoe);
          h_phohaspix->Fill(haspixel);
	  h_subjf->Fill(subjf);
	  h_subjfmass->Fill(subjf,jmpr);
	  h_subjfpt->Fill(subjf,jetpt);
	  
	  if(fabs(peta) < 1.4789 ) h_phosieieB->Fill(sieie);
	  if(fabs(peta) > 1.4789 ) h_phosieieE->Fill(sieie);
        }
        if(matchi && ikind == 4){
	  h_t31_m->Fill(t3t1);


	  mallpt->Fill(jetpt);
	  malleta->Fill(jeteta);
	  mallmass->Fill(jprm);
	  mallnvtx->Fill(nvtx);
	   
	  h_subjfmass_m->Fill(subjf,jmpr);
	  h_subjfpt_m->Fill(subjf,jetpt);
	  
	  h_spt1_m->Fill(sp1);
          h_spt2_m->Fill(sp2);
          h_spt3_m->Fill(sp3);
          h_phopt_m->Fill(ppt);
          h_subjf_m->Fill(subjf);
          h_phohoe_m->Fill(hoe);
          h_phohaspix_m->Fill(haspixel);
          if(fabs(peta) < 1.4789 ) h_phosieieB_m->Fill(sieie);
          if(fabs(peta) > 1.4789 ) h_phosieieE_m->Fill(sieie);
        }
      }
      if(!matchi) h_haspho->Fill(haspho);
      if(matchi && ikind == 4)  h_haspho_m->Fill(haspho);


      int isL  =   is_Loose( haspho,t3t1,haspixel,peta,sieie,hoe);
      int isT  =   is_Tight( haspho,t3t1,haspixel,subjf,peta,sieie,hoe);

      // if(isL) cout<<isL<<endl;


      if(isL ) il++;
      if(isT ) it++;

      if(isL ) LM->Fill(jmpr);
      if(isT ) TM->Fill(jmpr);

      if( isL ){
	h_subjfL->Fill(subjf);
      }
      if(isL && !matchi ){ 
	h_phohoeL->Fill(hoe);
	
      }
      if(isL && matchi ) {
	mLpt->Fill(jetpt);
	mLeta->Fill(jeteta);
	mLnvtx->Fill(nvtx);
	mLmass->Fill(jprm);

	h_subjfptL_m->Fill(subjf,jetpt);
	h_subjfmassL_m->Fill(subjf,jprm);
	h_phohoeL_m->Fill(hoe);
	  
	h_subjfL_m->Fill(subjf);

      }


      if(isT && matchi ) {
	mTpt->Fill(jetpt);
	mTeta->Fill(jeteta);
	mTnvtx->Fill(nvtx);
	mTmass->Fill(jprm);
	 
      }



      isLoose.push_back(isL );
      isTight.push_back(isT );
      ak8pt.push_back(jetpt);
      ak8phi.push_back(jetphi);
      ak8eta.push_back(jeteta);
      ak8m.push_back(jprm);
      phoindx.push_back(phoind);
    }

    



    float xswei = 1;
    if(ikind  == 0 ) xswei = 1;
    
    if(ikind == 10 ) xswei = 1.0*1000.0*xsec35/ntot35;
    if(ikind == 11 ) xswei = 1.0*1000.0*xsec57/ntot57;
    if(ikind == 12 ) xswei = 1.0*1000.0*xsec71/ntot71;
    if(ikind == 13 ) xswei = 1.0*1000.0*xsec15/ntot15;
    if(ikind == 14 ) xswei = 1.0*1000.0*xsec52/ntot52;
    if(ikind == 15 ) xswei = 1.0*1000.0*xsec2/ntot2;
    if(ikind == 16 ) xswei = 1.0*1000.0*xsec35/ntot35;
    if(ikind == 17 ) xswei = 1.0*1000.0*xsec57/ntot57;
    if(ikind == 18 ) xswei = 1.0*1000.0*xsec71/ntot71;
    if(ikind == 19 ) xswei = 1.0*1000.0*xsec15/ntot15;
    if(ikind == 20 ) xswei = 1.0*1000.0*xsec52/ntot52;
    if(ikind == 21 ) xswei = 1.0*1000.0*xsec2/ntot2;
    
    if(ikind == 4 ) xswei = 1.0*1000.0*xsec;

    if(ikind == 5  ) xswei = 1.0*1000.0*xsectt/ntott;
    if(ikind == 6 )  xswei = 1.0*1000.0*xsecwj/ntotwjqq;
    
    xsweight = xswei;
    

    ev->Fill();
    NJLT->Fill(it,il);



    float mav00 = 0;
    float mav20 = 0;
    float mav21 = 0;
    float mav22 = 0;

    int e_mav00 = 0;
    int e_mav20 = 0;
    int e_mav21 = 0;
    int e_mav22 = 0;

    float m1_L2 = 0;
    float m2_L2 = 0;



    phoI.clear();
    for(int ij = 0; ij < (*ak8ptC).size(); ij++){
      float jetpt  = (*ak8ptC)[ij];
      float jeteta = (*ak8etaC)[ij];

      if(fabs(jeteta) > 2) continue;

      	float mindr = 99;
	TVector3 jv1e,jv2e;
	jv1e.SetPtEtaPhi(jetpt,jeteta,jetphi);
	for(int ik = 0; ik < (*ak8ptC).size(); ik++){
	  if( ik == ij ) continue;
	  float pt1  =  (*ak8ptC)[0];
	  float phi1 =  (*ak8phiC)[0];
	  float eta1 =  (*ak8etaC)[0];
	  jv2e.SetPtEtaPhi(pt1,eta1,phi1);
	  float dr12 = jv1e.DeltaR(jv2e);
	  if( dr12 < mindr) mindr = dr12;
	}




      float jetphi = (*ak8phiC)[ij];
      if(it == 0 && il == 0 ){

	//cALCULATING dr
	drL0->Fill(mindr);
	L0->Fill(jetpt);
	L0eta->Fill(jeteta);
	L0etapt->Fill(jeteta,jetpt);

      }
      int   phoind =int( (*ak8phoindxC)[ij]);
      float t3t1  = (*ak8t3t1C)[ij];

      int haspixel =  0;
      float sieie = 100;
      float hoe = 100;;
      float peta = 0;
      float subjf = -1;
      int haspho = 0;

      bool sh = 0;
      /*
      if( phoind >= 0 ){
	for(int ipI = 0; ipI < (phoI).size(); ipI++){
	  if(phoind == (phoI)[ipI]) sh = true;
	}
	phoI.push_back(phoind);
      }
      */
      if(phoind >= 0 ){
	haspho = 1;
	haspixel = (*phohaspixelseed)[phoind];
	sieie = (*phosieie)[phoind];
	hoe = (*phohoe)[phoind];
	peta = (*phoeta)[phoind];
	subjf = (*ak8subjC)[ij];
      }

      float jmpr= (*ak8prMassC)[ij];
      int isL  =   is_Loose( haspho,t3t1,haspixel,peta,sieie,hoe);
      int isT  =   is_Tight( haspho,t3t1,haspixel,subjf,peta,sieie,hoe);
      isL = isL && !sh;
      isT = isT && !sh;


      if(il == 2 ){
        if(isL && m1_L2 ==  0) m1_L2 = jmpr;
        if(isL && m1_L2 >   0) m2_L2 = jmpr;
      }



      if(il == 2 && isL) L2M->Fill(jmpr);

      if(isL && il == 1){
	L1->Fill(jetpt);
	L1eta->Fill(jeteta);
	drL1->Fill(mindr);
	LforT1etapt->Fill(jeteta,jetpt);
	L1etapt->Fill(jeteta,jetpt);

      }
     if(il  == 1 ){

	if(it == 0  && isL) L11->Fill(jetpt);
	if(it == 1 && isT){
	  T1->Fill(jetpt);
	  T1eta->Fill(jeteta);
	  drT1->Fill(mindr);
	  T1etapt->Fill(jeteta,jetpt);
	}
     }

      if(it == 0 && il == 0){
	e_mav00++;
	mav00 += jmpr;
	LT00M->Fill(jmpr);
      }
      if(it == 0 && il == 1 && isL){
	LT10M->Fill(jmpr);
      }



      if(it == 1 && il == 1 && isT){
        LT11M->Fill(jmpr);


      }
      if(it == 0 && il == 2 && isL){
	e_mav20++;
	mav20 += jmpr;
        LT20M->Fill(jmpr);
      }



      if(it == 1 && il == 2 && isT){
        LT21MT->Fill(jmpr);

      }
      if(it == 1 && il == 2 && isL){
        LT21M->Fill(jmpr);

	e_mav21++;
	mav21 += jmpr;
      }
      if(it == 2 && il == 2 && isT){
        LT22M->Fill(jmpr);
	e_mav22++;
	mav22 += jmpr;
      }

    }

    if( il ==2 ){
      if( m1_L2 > 0 && m2_L2 > 0){
	float m_as = fabs(m1_L2 - m2_L2)/(m1_L2 + m2_L2);
	mas22->Fill(m_as);
      }
    }



    if(it == 0 && il == 2){
	 LT20ht->Fill(HTak4);
	 if(e_mav20 > 0 ) LT20Mav->Fill(mav20/(1.0*e_mav20));
	 LT20M_2d->Fill(m1_L2,m2_L2);

    }

    if(it == 1 && il == 2){
      LT21ht->Fill(HTak4);
      if(e_mav21 > 0 ) LT21Mav->Fill(mav21/(1.0*e_mav21));
      LT21M_2d->Fill(m1_L2,m2_L2);
    }

    if(it == 2 && il == 2){
      LT22ht->Fill(HTak4);
      if(e_mav22 > 0 ) LT22Mav->Fill(mav22/(1.0*e_mav22));
      LT22M_2d->Fill(m1_L2,m2_L2);

   }

    if(it == 0 && il == 1) LT10ht->Fill(HTak4);
    if(it == 1 && il == 1) LT11ht->Fill(HTak4);
    if(it == 0 && il == 0) LT00ht->Fill(HTak4);

    if(il == 2 && it == 2 ){
      if(m1_L2 > m2_L2 ) LT22m_ht->Fill(HTak4,m1_L2);
      if(m2_L2 > m1_L2 ) LT22m_ht->Fill(HTak4,m2_L2);
    }
    if(il == 2 && it == 1 ){
      if(m1_L2 > m2_L2 ) LT21m_ht->Fill(HTak4,m1_L2);
      if(m2_L2 > m1_L2 ) LT21m_ht->Fill(HTak4,m2_L2);
    }
    if(il == 2 && it == 0 ){
      if(m1_L2 > m2_L2 ) LT20m_ht->Fill(HTak4,m1_L2);
      if(m2_L2 > m1_L2 ) LT20m_ht->Fill(HTak4,m2_L2);
    }




  } //EOF event


  TR->Divide(T1,L1,1.,1.,"B");
  LR->Divide(L1,L0,1.,1.,"B");
  LReta->Divide(L1eta,L0eta,1.,1.,"B");
  TReta->Divide(T1eta,L1eta,1.,1.,"B");



  //Scaling and saving
  TH2F *NJLT_sc  = NJLT->Clone();
  TH1D *L0_sc    = L0->Clone();
  TH1D *L1_sc    = L1->Clone();
  TH1D *L11_sc   = L11->Clone();
  TH1D *T1_sc    = T1->Clone();
  TH1D *LM_sc  = LM->Clone();
  TH1D *TM_sc  = TM->Clone();
  TH1D *L2M_sc = L2M->Clone();
  TH1D *LT00M_sc  = LT00M->Clone();
  TH1D *LT10M_sc  = LT10M->Clone();
  TH1D *LT11M_sc  = LT11M->Clone();
  TH1D *LT20M_sc  = LT20M->Clone();
  TH1D *LT21M_sc  = LT21M->Clone();
  TH1D *LT21MT_sc = LT21MT->Clone();
  TH1D *LT22M_sc  = LT22M->Clone();
  TH1D *LT20ht_sc = LT20ht->Clone();
  TH1D *LT21ht_sc = LT21ht->Clone();
  TH1D *LT22ht_sc = LT22ht->Clone();
  TH1D *LT10ht_sc = LT10ht->Clone();
  TH1D *LT11ht_sc = LT11ht->Clone();
  TH1D *LT00ht_sc = LT00ht->Clone();

  TH1D *LT20Mav_sc  = LT20Mav->Clone();
  TH1D *LT21Mav_sc  = LT21Mav->Clone();
  TH1D  *LT22Mav_sc  = LT22Mav->Clone();

  TH1D *T1etapt_sc = T1etapt->Clone();
  TH1D *L0etapt_sc = L0etapt->Clone();
  TH1D *L1etapt_sc = L1etapt->Clone();
  TH1D *LforT1etapt_sc = LforT1etapt->Clone();



  NJLT_sc->SetName("NJLT_sc");
  L0_sc->SetName("L0_sc");
  L11_sc->SetName("L11_sc");
  L1_sc->SetName("L1_sc");
  T1_sc->SetName("T1_sc");
  LM_sc->SetName("LM_sc");
  TM_sc->SetName("TM_sc");
  L2M_sc->SetName("L2M_sc");
  LT00M_sc->SetName("LT00M_sc");
  LT10M_sc->SetName("LT10M_sc");
  LT11M_sc->SetName("LT11M_sc");
  LT20M_sc->SetName("LT20M_sc");
  LT21M_sc->SetName("LT21M_sc");
  LT21MT_sc->SetName("LT21MT_sc");
  LT22M_sc->SetName("LT22M_sc");
  LT20ht_sc->SetName("LT20ht_sc");
  LT21ht_sc->SetName("LT21ht_sc");
  LT22ht_sc->SetName("LT22ht_sc");
  LT10ht_sc->SetName("LT10ht_sc");
  LT11ht_sc->SetName("LT11ht_sc");
  LT00ht_sc->SetName("LT00ht_sc");

  LT20Mav_sc->SetName("LT20Mav_sc");
  LT21Mav_sc->SetName("LT21Mav_sc");
  LT22Mav_sc->SetName("LT22Mav_sc");

  T1etapt_sc->SetName("T1etapt_sc");
  L0etapt_sc->SetName("L0etapt_sc");
  L1etapt_sc->SetName("L1etapt_sc");
  LforT1etapt_sc->SetName("LforT1etapt_sc");
 

  double scale = 1;
  scale = 30*xsweight;
  if(ikind == 0 ) scale = 1; 

  NJLT_sc->Scale(scale);

  L0_sc->Scale(scale);
  L11_sc->Scale(scale);
  L1_sc->Scale(scale);
  T1_sc->Scale(scale);

  LM_sc->Scale(scale);
  TM_sc->Scale(scale);
  L2M_sc->Scale(scale);
  LT00M_sc->Scale(scale);
  LT10M_sc->Scale(scale);
  LT11M_sc->Scale(scale);
  LT20M_sc->Scale(scale);
  LT21M_sc->Scale(scale);
  LT21MT_sc->Scale(scale);
  LT22M_sc->Scale(scale);
  LT20ht_sc->Scale(scale);
  LT21ht_sc->Scale(scale);
  LT22ht_sc->Scale(scale);
  LT10ht_sc->Scale(scale);
  LT11ht_sc->Scale(scale);
  LT00ht_sc->Scale(scale);


  LT20Mav_sc->Scale(scale);
  LT21Mav_sc->Scale(scale);
  LT22Mav_sc->Scale(scale);

  h_spt1->Scale(scale);
  h_spt2->Scale(scale);
  h_spt3->Scale(scale);

  h_spt1_m->Scale(scale);
  h_spt2_m->Scale(scale);
  h_spt3_m->Scale(scale);

  T1etapt_sc->Scale(scale);
  L0etapt_sc->Scale(scale);
  L1etapt_sc->Scale(scale);
  LforT1etapt_sc->Scale(scale);


  f1->cd();
  NJLT->Write();
  NJ_all->Write();
  Nvtx_all->Write();

  L0->Write();
  L1->Write();
  T1->Write();

  drL0->Write();
  drL1->Write();
  drT1->Write();

  TR->Write();
  LR->Write();

  TReta->Write();
  LReta->Write();
  T1eta->Write();
  L1eta->Write();
  L0eta->Write();

  drL0->Write();
  drL1->Write();
  drT1->Write();



  LT20ht->Write();
  LT21ht->Write();
  LT22ht->Write();

  LT10ht->Write();
  LT11ht->Write();
  LT00ht->Write();

  LT22m_ht->Write();
  LT21m_ht->Write();
  LT20m_ht->Write();

  LT00M->Write();
  LT10M->Write();
  LT11M->Write();
  LT20M->Write();
  LT21M->Write();
  LT21MT->Write();
  LT22M->Write();

  LM->Write();
  TM->Write();
  L2M->Write();

  LT00Mav->Write();
  LT20Mav->Write();
  LT21Mav->Write();
  LT22Mav->Write();



  NJLT_sc->Write();

  L0_sc->Write();
  L11_sc->Write();
  L1_sc->Write();
  T1_sc->Write();

  LM_sc->Write();
  TM_sc->Write();
  L2M_sc->Write();
  LT00M_sc->Write();
  LT10M_sc->Write();
  LT11M_sc->Write();
  LT20M_sc->Write();
  LT21M_sc->Write();
  LT21MT_sc->Write();
  LT22M_sc->Write();
  LT20ht_sc->Write();
  LT21ht_sc->Write();
  LT22ht_sc->Write();
  LT10ht_sc->Write();
  LT11ht_sc->Write();
  LT00ht_sc->Write();

  LT20M_2d->Write();
  LT21M_2d->Write();
  LT22M_2d->Write();
  mas22->Write();

  LT20Mav_sc->Write();
  LT21Mav_sc->Write();
  LT22Mav_sc->Write();


  T1etapt->Write();
  L0etapt->Write();
  L1etapt->Write();
  LforT1etapt->Write();

  T1etapt_sc->Write();
  L0etapt_sc->Write();
  L1etapt_sc->Write();
  LforT1etapt_sc->Write(); 



  f2->cd();
  NJ_all->Write();
  ev->Write();

  f23->cd();
  NJ_all->Write();
 
  Nvtx_all->Write();


  h_t31->Write();
  h_haspho->Write();
  h_subjf->Write();
  h_phopt->Write();
  h_phosieieB->Write();
  h_phosieieE->Write();
  h_phohoe->Write();
  h_phohaspix->Write();
  h_spt1->Write();
  h_spt2->Write();
  h_spt3->Write();
  h_subjfmass->Write();
  h_subjfpt->Write();
  h_phohoeL->Write();
  h_subjfL->Write();

  if(ikind == 4 ){
    h_phopt_m->Write();
    h_t31_m->Write();
    h_haspho_m->Write();
    h_subjf_m->Write();
    h_phosieieB_m->Write();
    h_phosieieE_m->Write();
    h_phohoe_m->Write();
    h_phohoeL_m->Write();
    h_phohaspix_m->Write();
    h_spt1_m->Write();
    h_spt2_m->Write();
    h_spt3_m->Write();
    h_subjfmass_m->Write();
    h_subjfpt_m->Write();
    
    h_subjfptL_m->Write();
    h_subjfmassL_m->Write();
    h_subjfL_m->Write();



    mallpt->Write();
    malleta->Write();
    mallnvtx->Write();
    mallmass->Write();
 
    mLpt->Write();
    mLeta->Write();
    mLnvtx->Write();
    mLmass->Write();

    mTpt->Write();
    mTeta->Write();
    mTnvtx->Write();
    mTmass->Write();
  }

}




int is_Loose(float haspho,float t3t1,float haspixel,float phoeta,float phosie,float phohoe ){

  if(haspho == -99) return 0;
  if(haspixel == 0 && haspho && t3t1 < 0.5 ){
    //    return 1;
    if(fabs(phoeta) < 1.4789 && phosie < 0.019 && phohoe < 0.05) return 1;
    if(fabs(phoeta) > 1.4789 && phosie < 0.03 && phohoe < 0.05) return 1;
  }
  return 0;
}


int is_Tight(float haspho,float t3t1,float haspixel,float subjf,float phoeta,float phosie,float phohoe ){


  if(haspho == -99) return 0;
  if( ( haspixel == 0 && haspho && (t3t1 < 0.5 ) ) && 0.9 < subjf ){
    //    return 1;
    if(fabs(phoeta) < 1.4789 && phosie < 0.019 && phohoe < 0.05) return 1;
    if(fabs(phoeta) > 1.4789 && phosie < 0.03 && phohoe < 0.05) return 1;
  }
  return 0;

}


