#!/bin/bash

#INPUT=/storage/b/rcaspart/htautau/2017-05-23_15-01_data_RunC_RunF/
#INPUT=/storage/b/rcaspart/htautau/2017-05-26_20-43_ttTriggerSF
#INPUT=/storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/
#INPUT=/storage/b/rcaspart/htautau/2017-06-05_19-27_jec/
#INPUT=/storage/b/akhmet/merged_files_from_naf/default_artus_LepToMET_pair_only_11_06_2017/
INPUT=/storage/b/rcaspart/htautau/2017-06-21_eleScale/
OUTPUT=plots/htt_datacards_thesis_final
#OUTPUT=plots/htt_datacards_thesis_ptdeptt

makePlots_datacardsMSSMHtt.py -i ${INPUT} -c mt --categories mt_btag_loosemt mt_nobtag_loosemt mt_nobtag_tight mt_btag_tight -b new -e 2017 -x mt_tot --controlregions -o ${OUTPUT} --fakefactor-method standard -n 40 --SMHiggs
makePlots_datacardsMSSMHtt.py -i ${INPUT} -c et --categories et_btag_loosemt et_nobtag_loosemt et_nobtag_tight et_btag_tight -b new -e 2017 -x mt_tot --controlregions -o ${OUTPUT} --fakefactor-method standard -n 40 --SMHiggs
makePlots_datacardsMSSMHtt.py -i ${INPUT} -c tt --categories tt_nobtag tt_btag -b new -e 2017 -x mt_tot -o ${OUTPUT} --fakefactor-method standard -n 40 --SMHiggs
