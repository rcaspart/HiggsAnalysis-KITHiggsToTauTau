
#include <Math/VectorUtil.h>

#include "Artus/Consumer/interface/LambdaNtupleConsumer.h"

#include "HiggsAnalysis/KITHiggsToTauTau/interface/Producers/DiLeptonDcaProducer.h"


void DiLeptonDcaProducer::Init(setting_type const& settings)
{
	ProducerBase<HttTypes>::Init(settings);
	
	// add possible quantities for the lambda ntuples consumers
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("diLepDca3D", [](event_type const& event, product_type const& product) {
		return product.m_diLeptonDca3D;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("diLepDca3DError", [](event_type const& event, product_type const& product) {
		return product.m_diLeptonDca3DError;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("diLepDca3DSigLog", [](event_type const& event, product_type const& product) {
		return product.m_diLeptonDca3DSignificanceLog;
	});
	
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("diLepDca2D", [](event_type const& event, product_type const& product) {
		return product.m_diLeptonDca2D;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("diLepDca2DError", [](event_type const& event, product_type const& product) {
		return product.m_diLeptonDca2DError;
	});
	LambdaNtupleConsumer<HttTypes>::AddFloatQuantity("diLepDca2DSigLog", [](event_type const& event, product_type const& product) {
		return product.m_diLeptonDca2DSignificanceLog;
	});
	
	// initialise corrector
	if (settings.GetApplyDcaCorrection())
	{
		dcaCorrection.initialize(settings.GetDcaCorrectionFactorsData(), settings.GetDcaCorrectionFactorsMc());
	}
}

void DiLeptonDcaProducer::Produce(event_type const& event, product_type& product,
	                                     setting_type const& settings) const
{
	assert(event.m_leptonPairs);
	assert(product.m_flavourOrderedLeptons.size() >= 2);
	
	KLeptonPairs::const_iterator leptonPair = KLeptonPair::find(
			event.m_leptonPairs->begin(), event.m_leptonPairs->end(),
			std::pair<KLepton*, KLepton*>(product.m_flavourOrderedLeptons[0], product.m_flavourOrderedLeptons[1])
	);
	if (leptonPair != event.m_leptonPairs->end())
	{
		product.m_diLeptonDca3D = leptonPair->dca3D;
		product.m_diLeptonDca3DError = leptonPair->dca3DError;
		product.m_diLeptonDca3DSignificanceLog = std::log10(std::abs(product.m_diLeptonDca3D / product.m_diLeptonDca3DError));
		
		product.m_diLeptonDca2D = leptonPair->dca2D;
		product.m_diLeptonDca2DError = leptonPair->dca2DError;
		product.m_diLeptonDca2DSignificanceLog = std::log10(std::abs(product.m_diLeptonDca2D / product.m_diLeptonDca2DError));
		
		// DCA correction (in place)
		if (settings.GetApplyDcaCorrection())
		{
			product.m_diLeptonDca3DSignificanceLog = dcaCorrection.DCAcorrected(
					product.m_diLeptonDca3DSignificanceLog,
					std::abs(product.m_flavourOrderedLeptons[0]->p4.Pt() + product.m_flavourOrderedLeptons[1]->p4.Pt()),
					std::abs(product.m_flavourOrderedLeptons[0]->p4.Pt() - product.m_flavourOrderedLeptons[1]->p4.Pt()),
					std::cos(ROOT::Math::VectorUtil::Angle(product.m_flavourOrderedLeptons[0]->p4, product.m_flavourOrderedLeptons[1]->p4))
			);
			product.m_diLeptonDca2DSignificanceLog = dcaCorrection.DCAcorrected(
					product.m_diLeptonDca2DSignificanceLog,
					std::abs(product.m_flavourOrderedLeptons[0]->p4.Pt() + product.m_flavourOrderedLeptons[1]->p4.Pt()),
					std::abs(product.m_flavourOrderedLeptons[0]->p4.Pt() - product.m_flavourOrderedLeptons[1]->p4.Pt()),
					std::cos(ROOT::Math::VectorUtil::Angle(product.m_flavourOrderedLeptons[0]->p4, product.m_flavourOrderedLeptons[1]->p4))
			);
		}
	}
}
