
#pragma once

#include <TH2.h>
#include "Artus/Core/interface/ProducerBase.h"
#include "HiggsAnalysis/KITHiggsToTauTau/interface/HttTypes.h"
#include <boost/regex.hpp>

/**
   \brief ZPtReweightProducer
   Config tags:
   - Fill me with something meaningful

*/

class ZPtReweightProducer: public ProducerBase<HttTypes> {
public:

	typedef typename HttTypes::event_type event_type;
	typedef typename HttTypes::product_type product_type;
	typedef typename HttTypes::setting_type setting_type;
	
	virtual ~ZPtReweightProducer();

	std::string GetProducerId() const;

	virtual void Init(setting_type const& settings) override;

	virtual void Produce(event_type const& event, product_type & product, 
	                     setting_type const& settings) const override;
private:
	TH2D* m_zPtHist = nullptr;
	bool m_applyReweighting;
};
