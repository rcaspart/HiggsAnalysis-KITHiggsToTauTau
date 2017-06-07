#!/bin/bash

#INPUT=/storage/b/rcaspart/htautau/2017-05-23_15-01_data_RunC_RunF/
#INPUT=/storage/b/rcaspart/htautau/2017-05-26_20-43_ttTriggerSF
#INPUT=/storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/
INPUT=/storage/b/rcaspart/htautau/2017-06-05_19-27_jec/
#OUTPUT=plots/htt_datacards_final
OUTPUT=plots/htt_datacards_jec

makePlots_datacardsMSSMHtt.py -i ${INPUT} -c mt --categories mt_btag_loosemt mt_nobtag_loosemt mt_nobtag_tight mt_btag_tight -b new -e 2017 -x mt_tot --controlregions -o ${OUTPUT} --fakefactor-method standard -n 40 --SMHiggs
makePlots_datacardsMSSMHtt.py -i ${INPUT} -c et --categories et_btag_loosemt et_nobtag_loosemt et_nobtag_tight et_btag_tight -b new -e 2017 -x mt_tot --controlregions -o ${OUTPUT} --fakefactor-method standard -n 40 --SMHiggs
makePlots_datacardsMSSMHtt.py -i ${INPUT} -c tt --categories tt_nobtag tt_btag -b new -e 2017 -x mt_tot -o ${OUTPUT} --fakefactor-method standard -n 40 --SMHiggs
makePlots_datacardsMSSMHtt.py -i ${INPUT} -c em --categories em_nobtag_lowPzeta em_nobtag_mediumPzeta em_nobtag_highPzeta em_btag_lowPzeta em_btag_mediumPzeta em_btag_highPzeta -b new -e 2017 -x mt_tot -o ${OUTPUT} --fakefactor-method standard -n 20
makePlots_datacardsMSSMHtt.py -i ${INPUT} -c mm --categories mm_btag mm_nobtag -b classic -e 2017 -x m_vis -n 20 -o ${OUTPUT}
