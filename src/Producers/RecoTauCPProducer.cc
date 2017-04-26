
#include "Artus/Consumer/interface/LambdaNtupleConsumer.h"
#include "Artus/KappaAnalysis/interface/KappaTypes.h"

#include "HiggsAnalysis/KITHiggsToTauTau/interface/HttEnumTypes.h"
#include "HiggsAnalysis/KITHiggsToTauTau/interface/Utility/CPQuantities.h"
#include "HiggsAnalysis/KITHiggsToTauTau/interface/Producers/RecoTauCPProducer.h"


std::string RecoTauCPProducer::GetProducerId() const
{
	return "RecoTauCPProducer";
}

void RecoTauCPProducer::Init(setting_type const& settings)
{
	ProducerBase<HttTypes>::Init(settings);
	m_isData = settings.GetInputIsData();

	// add possible quantities for the lambda ntuples consumers
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoPhiStarCP", [](event_type const& event, product_type const& product)
	{
		return product.m_recoPhiStarCP;
	});

	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoPhiStarCP_rho", [](event_type const& event, product_type const& product)
	{
		return product.m_recoPhiStarCP_rho;
	});


	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoPhiStarCPrPV", [](event_type const& event, product_type const& product)
	{
		return product.m_recoPhiStarCPrPV;
	});

	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoPhiStarCPrPVbs", [](event_type const& event, product_type const& product)
	{
		return product.m_recoPhiStarCPrPVbs;
	});

	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoPhiStar", [](event_type const& event, product_type const& product)
	{
		return product.m_recoPhiStar;
	});

	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoPhiStar_rho", [](event_type const& event, product_type const& product)
	{
		return product.m_recoPhiStar_rho;
	});

	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoChargedHadron1HiggsFrameEnergy", [](event_type const& event, product_type const& product)
	{
		return product.m_recoChargedHadronEnergies.first;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoChargedHadron2HiggsFrameEnergy", [](event_type const& event, product_type const& product)
	{
		return product.m_recoChargedHadronEnergies.second;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("lep1D0refitPV", [](event_type const& event, product_type const& product)
	{
		return product.m_refitPV ? product.m_flavourOrderedLeptons.at(0)->track.getDxy(product.m_refitPV) : DefaultValues::UndefinedDouble;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("lep1D0refitPVBS", [](event_type const& event, product_type const& product)
	{
		return product.m_refitPV ? product.m_flavourOrderedLeptons.at(0)->track.getDxy(product.m_refitPVBS) : DefaultValues::UndefinedDouble;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("lep1DzrefitPV", [](event_type const& event, product_type const& product)
	{
		return product.m_refitPV ? product.m_flavourOrderedLeptons.at(0)->track.getDz(product.m_refitPV) : DefaultValues::UndefinedDouble;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("lep1DzrefitPVBS", [](event_type const& event, product_type const& product)
	{
		return product.m_refitPV ? product.m_flavourOrderedLeptons.at(0)->track.getDz(product.m_refitPVBS) : DefaultValues::UndefinedDouble;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("lep2D0refitPV", [](event_type const& event, product_type const& product)
	{
		return product.m_refitPV ? product.m_flavourOrderedLeptons.at(1)->track.getDxy(product.m_refitPV) : DefaultValues::UndefinedDouble;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("lep2D0refitPVBS", [](event_type const& event, product_type const& product)
	{
		return product.m_refitPV ? product.m_flavourOrderedLeptons.at(1)->track.getDxy(product.m_refitPVBS) : DefaultValues::UndefinedDouble;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("lep2DzrefitPV", [](event_type const& event, product_type const& product)
	{
		return product.m_refitPV ? product.m_flavourOrderedLeptons.at(1)->track.getDz(product.m_refitPV) : DefaultValues::UndefinedDouble;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("lep2DzrefitPVBS", [](event_type const& event, product_type const& product)
	{
		return product.m_refitPV ? product.m_flavourOrderedLeptons.at(1)->track.getDz(product.m_refitPVBS) : DefaultValues::UndefinedDouble;
	});
//	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoImpactParameter1", [](event_type const& event, product_type const& product)
//	{
//		return product.m_recoIP1;
//	});
//	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoImpactParameter2", [](event_type const& event, product_type const& product)
//	{
//		return product.m_recoIP2;
//	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoTrackRefError1", [](event_type const& event, product_type const& product)
	{
		return product.m_recoTrackRefError1;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoTrackRefError2", [](event_type const& event, product_type const& product)
	{
		return product.m_recoTrackRefError2;
	});

	// IP vectors (3D method)
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP1x", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP1 != nullptr) ? (product.m_recoIP1).x() : DefaultValues::UndefinedFloat);
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP1y", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP1 != nullptr) ? (product.m_recoIP1).y() : DefaultValues::UndefinedFloat);
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP1z", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP1 != nullptr) ? (product.m_recoIP1).z() : DefaultValues::UndefinedFloat);
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP2x", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP2 != nullptr) ? (product.m_recoIP2).x() : DefaultValues::UndefinedFloat);
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP2y", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP2 != nullptr) ? (product.m_recoIP2).y() : DefaultValues::UndefinedFloat);
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP2z", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP2 != nullptr) ? (product.m_recoIP2).z() : DefaultValues::UndefinedFloat);
	});

	// IP vectors (using d0 and dz)
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP1method2x", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP1method2 != nullptr) ? (product.m_recoIP1method2).x() : DefaultValues::UndefinedFloat);
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP1method2y", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP1method2 != nullptr) ? (product.m_recoIP1method2).y() : DefaultValues::UndefinedFloat);
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP1method2z", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP1method2 != nullptr) ? (product.m_recoIP1method2).z() : DefaultValues::UndefinedFloat);
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP2method2x", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP2method2 != nullptr) ? (product.m_recoIP2method2).x() : DefaultValues::UndefinedFloat);
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP2method2y", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP2method2 != nullptr) ? (product.m_recoIP2method2).y() : DefaultValues::UndefinedFloat);
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("recoIP2method2z", [](event_type const& event, product_type const& product)
	{
		return ((&product.m_recoIP2method2 != nullptr) ? (product.m_recoIP2method2).z() : DefaultValues::UndefinedFloat);
	});

	// deltaR between IP vectors
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("deltaRgenIPrecoIP1", [](event_type const& event, product_type const& product)
	{
		return product.m_deltaRgenIPrecoIP1;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("deltaRgenIPrecoIP2", [](event_type const& event, product_type const& product)
	{
		return product.m_deltaRgenIPrecoIP2;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("deltaRgenIPrecoIP1met2", [](event_type const& event, product_type const& product)
	{
		return product.m_deltaRgenIPrecoIP1met2;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("deltaRgenIPrecoIP2met2", [](event_type const& event, product_type const& product)
	{
		return product.m_deltaRgenIPrecoIP2met2;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("deltaRrecoIP1s", [](event_type const& event, product_type const& product)
	{
		return product.m_deltaRrecoIP1s;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("deltaRrecoIP2s", [](event_type const& event, product_type const& product)
	{
		return product.m_deltaRrecoIP2s;
	});

}

void RecoTauCPProducer::Produce(event_type const& event, product_type& product, setting_type const& settings) const
{
	assert(event.m_vertexSummary);
	assert(product.m_flavourOrderedLeptons.size() >= 2);

	KLepton* recoParticle1 = product.m_chargeOrderedLeptons.at(0);
	KLepton* recoParticle2 = product.m_chargeOrderedLeptons.at(1);
	TVector3 recoIP1;
	TVector3 recoIP2;
	TVector3 recoIP1method2;
	TVector3 recoIP2method2;

	// Defining CPQuantities object to use variables and functions of this class
	CPQuantities cpq;

	// old calculation of recoPhiStarCP --> need to be rechecked
	KTrack trackP = product.m_chargeOrderedLeptons[0]->track;
	KTrack trackM = product.m_chargeOrderedLeptons[1]->track;
	RMFLV momentumP = ((product.m_chargeOrderedLeptons[0]->flavour() == KLeptonFlavour::TAU) ? static_cast<KTau*>(product.m_chargeOrderedLeptons[0])->chargedHadronCandidates.at(0).p4 : product.m_chargeOrderedLeptons[0]->p4);
	RMFLV momentumM = ((product.m_chargeOrderedLeptons[1]->flavour() == KLeptonFlavour::TAU) ? static_cast<KTau*>(product.m_chargeOrderedLeptons[1])->chargedHadronCandidates.at(0).p4 : product.m_chargeOrderedLeptons[1]->p4);

	if (product.m_decayChannel == HttEnumTypes::DecayChannel::TT) {

	RMFLV chargedPiP = ((product.m_chargeOrderedLeptons.at(0)->flavour() == KLeptonFlavour::TAU) ? static_cast<KTau*>((product.m_chargeOrderedLeptons.at(0))->sumChargedHadronCandidates() : DefaultValues::UndefinedRMFLV);
	RMFLV chargedPiM = ((product.m_chargeOrderedLeptons.at(1)->flavour() == KLeptonFlavour::TAU) ? static_cast<KTau*>((product.m_chargeOrderedLeptons.at(1))->sumChargedHadronCandidates() : DefaultValues::UndefinedRMFLV);
	RMFLV piZeroP = ((product.m_chargeOrderedLeptons.at(0)->flavour() == KLeptonFlavour::TAU) ? static_cast<KTau*>(product.m_chargeOrderedLeptons.at(0))->piZeroMomentum() : DefaultValues::UndefinedRMFLV);
	RMFLV piZeroM = ((product.m_chargeOrderedLeptons.at(1)->flavour() == KLeptonFlavour::TAU) ? static_cast<KTau*>(product.m_chargeOrderedLeptons.at(1))->piZeroMomentum() : DefaultValues::UndefinedRMFLV);


	}

    // variables for the rho method



	product.m_recoPhiStarCP = cpq.CalculatePhiStarCP(event.m_vertexSummary->pv, trackP, trackM, momentumP, momentumM);
	//product.m_recoPhiStarCPrPV = cpq.CalculatePhiStarCP(event.m_refitVertexSummary->pv, trackP, trackM, momentumP, momentumM);
	//product.m_recoPhiStarCPrPVbs = cpq.CalculatePhiStarCP(event.m_refitVertexBSSummary->pv, trackP, trackM, momentumP, momentumM);

	//product.m_recoPhiStar = cpq.GetRecoPhiStar();
	//product.m_recoIP1 = cpq.GetRecoIP1();
	//product.m_recoIP2 = cpq.GetRecoIP2();
	//product.m_recoChargedHadronEnergies.first = cpq.CalculateChargedHadronEnergy(product.m_diTauSystem, momentumP);
	//product.m_recoChargedHadronEnergies.second = cpq.CalculateChargedHadronEnergy(product.m_diTauSystem, momentumM);
	//product.m_recoTrackRefError1 = cpq.CalculateTrackReferenceError(trackP);
	//product.m_recoTrackRefError2 = cpq.CalculateTrackReferenceError(trackM);

	// calculation of the IP vectors
	if (product.m_refitPV != nullptr){
		recoIP1 = cpq.CalculateIPVector(recoParticle1, product.m_refitPV);
		recoIP2 = cpq.CalculateIPVector(recoParticle2, product.m_refitPV);
		product.m_recoIP1 = recoIP1;
		product.m_recoIP2 = recoIP2;

		double dz1 = product.m_flavourOrderedLeptons.at(0)->track.getDz(product.m_refitPV);
		double dz2 = product.m_flavourOrderedLeptons.at(1)->track.getDz(product.m_refitPV);
		recoIP1method2 = cpq.CalculateIPVector(recoParticle1, product.m_refitPV, dz1);
		recoIP2method2 = cpq.CalculateIPVector(recoParticle2, product.m_refitPV, dz2);
		product.m_recoIP1method2 = recoIP1method2;
		product.m_recoIP2method2 = recoIP2method2;

		double deltaRrecoIP1s = recoIP1.DeltaR(recoIP1method2);
		double deltaRrecoIP2s = recoIP2.DeltaR(recoIP2method2);
		product.m_deltaRrecoIP1s = deltaRrecoIP1s;
		product.m_deltaRrecoIP2s = deltaRrecoIP2s;


		if (!m_isData){

			if(&product.m_genIP1 != nullptr){
				double deltaRgenIPrecoIP1 = recoIP1.DeltaR(product.m_genIP1);
				product.m_deltaRgenIPrecoIP1 = deltaRgenIPrecoIP1;

				double deltaRgenIPrecoIP1met2 = recoIP1method2.DeltaR(product.m_genIP1);
				product.m_deltaRgenIPrecoIP1met2 = deltaRgenIPrecoIP1met2;
			} // if genIP1 exists

			if(&product.m_genIP2 != nullptr){
				double deltaRgenIPrecoIP2 = recoIP2.DeltaR(product.m_genIP2);
				product.m_deltaRgenIPrecoIP2 = deltaRgenIPrecoIP2;

				double deltaRgenIPrecoIP2met2 = recoIP2method2.DeltaR(product.m_genIP2);
				product.m_deltaRgenIPrecoIP2met2 = deltaRgenIPrecoIP2met2;
			} // if genIP2 exists

		} // if MC sample

	} // if the refitPV exists


}
