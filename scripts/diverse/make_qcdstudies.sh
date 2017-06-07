#!/bin/bash

#FOLDER=/storage/b/rcaspart/htautau/2017-04-04_18-54/
FOLDER=/storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/


./HiggsAnalysis/KITHiggsToTauTau/scripts/makePlots_datacardsMSSMHtt.py -i $FOLDER -c mt --categories mt_nobtag mt_btag mt_inclusive -b classic -e 2017 -x m_vis -n 10 --exclude-cuts "iso_1" -w "(iso_1 < 0.25)*(iso_1 > 0.15)" -o qcdstudies/qcd_os_ss_near -a " --qcd-extrapolation-factors-ss-os 1.0 --wjets-from-mc False True"
./HiggsAnalysis/KITHiggsToTauTau/scripts/makePlots_datacardsMSSMHtt.py -i $FOLDER -c et --categories et_nobtag et_btag et_inclusive -b classic -e 2017 -x m_vis -n 10  --exclude-cuts "iso_1" -w "(iso_1 < 0.20)*(iso_1 > 0.1)" -o qcdstudies/qcd_os_ss_near -a " --qcd-extrapolation-factors-ss-os 1.0 --wjets-from-mc False True"

./HiggsAnalysis/KITHiggsToTauTau/scripts/makePlots_datacardsMSSMHtt.py -i $FOLDER -c mt --categories mt_nobtag mt_btag mt_inclusive -b classic -e 2017 -x m_vis -n 10 --exclude-cuts "iso_1" -w "(iso_1 < 0.5)*(iso_1 > 0.25)" -o qcdstudies/qcd_os_ss_far -a " --qcd-extrapolation-factors-ss-os 1.0 --wjets-from-mc False True"
./HiggsAnalysis/KITHiggsToTauTau/scripts/makePlots_datacardsMSSMHtt.py -i $FOLDER -c et --categories et_nobtag et_btag et_inclusive -b classic -e 2017 -x m_vis -n 10  --exclude-cuts "iso_1" -w "(iso_1 < 0.5)*(iso_1 > 0.2)" -o qcdstudies/qcd_os_ss_far -a " --qcd-extrapolation-factors-ss-os 1.0 --wjets-from-mc False True"

./HiggsAnalysis/KITHiggsToTauTau/scripts/makePlots_datacardsMSSMHtt.py -i $FOLDER -c mt --categories mt_nobtag mt_btag mt_inclusive -b classic -e 2017 -x m_vis -n 10 --exclude-cuts "iso_1" -w "(iso_1 < 0.5)*(iso_1 > 0.15)" -o qcdstudies/qcd_os_ss_cmb -a " --qcd-extrapolation-factors-ss-os 1.0 --wjets-from-mc False True"
./HiggsAnalysis/KITHiggsToTauTau/scripts/makePlots_datacardsMSSMHtt.py -i $FOLDER -c et --categories et_nobtag et_btag et_inclusive -b classic -e 2017 -x m_vis -n 10  --exclude-cuts "iso_1" -w "(iso_1 < 0.5)*(iso_1 > 0.1)" -o qcdstudies/qcd_os_ss_cmb -a " --qcd-extrapolation-factors-ss-os 1.0 --wjets-from-mc False True"
