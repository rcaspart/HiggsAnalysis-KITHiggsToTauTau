#!/bin/bash

# qcd estimation lowmt-ss
#makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/thesis/qcd_ss --era 2016 -e "os" -w "((q_1*q_2)>0.0)" -b classic -x mt_tot -c mt et --categories inclusive --no-ewk-samples -a  "--plot-modules PlotRootHtt --x-bins 30,0,300 --qcd-extrapolation-factors-ss-os 1.0 --formats png eps pdf"

# high mt regions
#makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/thesis/qcd_os_highmt --era 2016 -e "mt" -w "(mt_1>70.0)" -b classic -x mt_tot -c mt et --categories inclusive --no-ewk-samples -a  "--plot-modules PlotRootHtt --x-bins 30,0,300 --formats png eps pdf"
#makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/qcd_ss_highmt --era 2016 -e "os" "mt" -w "((q_1*q_2)>0.0)*(mt_1>70.0)" -b classic -x mt_tot -c mt et --categories inclusive --no-ewk-samples -a  "--plot-modules PlotRootHtt --x-bins 30,0,300 --qcd-extrapolation-factors-ss-os 1.0 --formats png eps pdf"

# mt_1 plot
#makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/thesis/ --era 2016 -b new -x mt_1 -c mt et --categories inclusive --no-ewk-samples -r -a  "--plot-modules PlotRootHtt --format png eps pdf"
# iso_1 and iso_2
#makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/thesis/ --era 2016 -b new -x iso_1 iso_2 -c mt et tt --categories inclusive --no-ewk-samples -r -a  "--plot-modules PlotRootHtt --format png eps pdf"

# npv w/ wo pileupreweighting
#makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/thesis/wo_pileup --era 2016 -b new -x npv -c mt et tt --categories inclusive --no-ewk-samples -r -w "1/puWeight" -a  "--plot-modules PlotRootHtt --format png eps pdf"
#makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/thesis/w_pileup --era 2016 -b new -x npv -c mt et tt --categories inclusive --no-ewk-samples -r -a  "--plot-modules PlotRootHtt --format png eps pdf"

# tt channel mt_tot in anti-iso regions
makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/thesis/qcd_tt_os --era 2016 -b new -x mt_tot -c tt --categories inclusive --no-ewk-samples -r -a  "--plot-modules PlotRootHtt --format png eps pdf"
makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/thesis/qcd_tt_ss --era 2016 -b new -x mt_tot -c tt --categories inclusive --no-ewk-samples -r -e "os" -w "(q_1*q_2)>0.0" -a  "--plot-modules PlotRootHtt --format png eps pdf"
makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/thesis/qcd_tt_aiso_ss --era 2016 -b new -x mt_tot -c tt --categories inclusive --no-ewk-samples -r -e "os" "iso_2" -w "((q_1*q_2)>0.0 && byLooseIsolationMVArun2v1DBoldDMwLT_2 > 0.5 && byMediumIsolationMVArun2v1DBoldDMwLT_2 < 0.5)*((gen_match_1 == 5)*0.99 + (gen_match_1 != 5))" -a  "--plot-modules PlotRootHtt --format png eps pdf"
makePlots_controlPlots.py -i /storage/b/rcaspart/htautau/2017-06-02_17-02_nominal/ --mssm -o plots/thesis/qcd_tt_aiso_os --era 2016 -b new -x mt_tot -c tt --categories inclusive --no-ewk-samples -r -e "iso_2" -w "(byLooseIsolationMVArun2v1DBoldDMwLT_2 > 0.5 && byMediumIsolationMVArun2v1DBoldDMwLT_2 < 0.5)*((gen_match_1 == 5)*0.99 + (gen_match_1 != 5))" -a  "--plot-modules PlotRootHtt --format png eps pdf"
