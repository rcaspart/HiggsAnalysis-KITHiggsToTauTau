
#include "Artus/Consumer/interface/LambdaNtupleConsumer.h"
#include "Artus/Utility/interface/DefaultValues.h"
#include <TMath.h>
#include "HiggsAnalysis/KITHiggsToTauTau/interface/Producers/MVAInputQuantitiesProducer.h"


void MVAInputQuantitiesProducer::Init(setting_type const& settings)
{   
    ProducerBase<HttTypes>::Init(settings);
    LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("TrainingSelectionValue", [](event_type const& event, product_type const& product) {
        return product.tsValue;
    });
    LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("pVecSum", [](event_type const& event, product_type const& product) {
        return product.pVecSum;
    });
    LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("pScalSum", [](event_type const& event, product_type const& product) {
        return product.pScalSum;
    });
    LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("min_ll_jet_eta", [](event_type const& event, product_type const& product) {
        return product.min_ll_jet_eta;
    });
    LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("lep1_centrality", [](event_type const& event, product_type const& product) {
        return product.lep1_centrality;
    });
    LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("lep2_centrality", [](event_type const& event, product_type const& product) {
        return product.lep2_centrality;
    });
    
}

void MVAInputQuantitiesProducer::Produce(event_type const& event, product_type& product,
                                      setting_type const& settings) const
{   //tsValue production
    int evt_number = event.m_eventInfo->nEvent, lumi = event.m_eventInfo->nLumi, rndm = 0;
    unsigned char *evt_char = reinterpret_cast<unsigned char *>(&evt_number);
    unsigned char *lumi_char = reinterpret_cast<unsigned char *>(&lumi);
    unsigned char *random_selector = reinterpret_cast<unsigned char *>(&rndm);
    *random_selector = *evt_char ^ *lumi_char;
    product.tsValue = rndm%100;
    
    //pVecSum production
    product.pVecSum = (product.m_met->p4 + product.m_diTauSystemCA + product.m_diJetSystem).M();
    
    //pScalSum production
    product.pVecSum = (product.m_met->p4).M() + product.m_diTauSystemCA.M() + product.m_diJetSystem.M();
    
    double jet1_eta = product.m_validJets[0]->p4.Eta();
    double jet2_eta = product.m_validJets[1]->p4.Eta();
    //min_ll_jet_eta production
    product.min_ll_jet_eta = std::min(product.m_diLeptonSystem.Eta() + jet1_eta, product.m_diLeptonSystem.Eta() + jet2_eta);
    
    //object_centrality production
    double eta = 0.0;
    eta = product.m_flavourOrderedLeptons[0]->p4.Eta();
    product.lep1_centrality = TMath::Exp(-4.0/(jet1_eta-jet2_eta)/(jet1_eta-jet2_eta)*(eta-(jet1_eta+jet2_eta)/2.0)*(eta-(jet1_eta+jet2_eta)/2.0));
    eta = product.m_flavourOrderedLeptons[1]->p4.Eta();
    product.lep2_centrality = TMath::Exp(-4.0/(jet1_eta-jet2_eta)/(jet1_eta-jet2_eta)*(eta-(jet1_eta+jet2_eta)/2.0)*(eta-(jet1_eta+jet2_eta)/2.0));
    
}
