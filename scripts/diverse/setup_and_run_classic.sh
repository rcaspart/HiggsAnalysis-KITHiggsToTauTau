#!/bin/bash

#setup datacards
#MorphingMSSMFull2016 --output_folder="mssm_freezing_classic" -m MH --postfix="-mttot" --control_region=1 --auto_rebin=true --real_data=false --zmm_fit=true --ttbar_fit=true --jetfakes=false --input_folder_mt KIT --input_folder_et Imperial --input_folder_tt Vienna --input_folder_em DESY

# turn into workspaces
#combineTool.py -M T2W -o "ws.root" -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO '"map=^.*/ggH$:r_ggH[0,0,200]"' --PO '"map=^.*/bbH$:r_bbH[0,0,200]"' -i output/mssm_freezing_classic/* --parallel 20

# do asymptotics and collect limits
combineTool.py -m "90,100,110,120,130,140,160,180,200,250,350,400,450,500,600,700,800,900,1000,1200,1400,1600,1800,2000,2300,2600,2900,3200" -t -1 -M Asymptotic --rAbsAcc 0 --rRelAcc 0.0005 --boundlist input/mssm_boundaries.json  --setPhysicsModelParameters r_ggH=0,r_bbH=0 --redefineSignalPOIs r_ggH -d output/mssm_freezing_classic/*/ws.root --there -n ".ggH" --parallel 20
combineTool.py -m "90,100,110,120,130,140,160,180,200,250,350,400,450,500,600,700,800,900,1000,1200,1400,1600,1800,2000,2300,2600,2900,3200" -t -1 -M Asymptotic --rAbsAcc 0 --rRelAcc 0.0005 --boundlist input/mssm_boundaries.json  --setPhysicsModelParameters r_ggH=0,r_bbH=0 --redefineSignalPOIs r_bbH -d output/mssm_freezing_classic/*/ws.root --there -n ".bbH" --parallel 20

combineTool.py -M CollectLimits output/mssm_freezing_classic/*/higgsCombine.ggH*.root --use-dirs -o "mssm_freezing_classic_ggH.json"
combineTool.py -M CollectLimits output/mssm_freezing_classic/*/higgsCombine.bbH*.root --use-dirs -o "mssm_freezing_classic_bbH.json"

# get prefit shapes and plots
PostFitShapesFromWorkspace -d output/mssm_freezing_classic/cmb/combined.txt.cmb -w output/mssm_freezing_classic/cmb/ws.root -o shapes_20170529_classic.root --print --freeze r_ggH=0.1,r_bbH=0.1,MH=700
python scripts/makeMassPlotsPrefit.py

exit

# do asymptotic MSSMvsBG
mkdir -p MSSMvsBG/mhmodp
pushd MSSMvsBG/mhmodp
combineTool.py -M AsymptoticGrid ../scripts/mssm_asymptotic_grid_mhmodp.json -d ../output/mssm_freezing_mhmodp/cmb/mhmodp.root --job-mode 'interactive' --task-name 'mssm_mhmodp' --parallel 20
popd
mkdir -p MSSMvsBG/hmssm
pushd MSSMvsBG/hmssm
combineTool.py -M AsymptoticGrid ../scripts/mssm_asymptotic_grid_hMSSM.json -d ../output/mssm_freezing_mhmodp/cmb/hmssm.root --job-mode 'interactive' --task-name 'mssm_hmssm' --parallel 20
popd

exit

# do asymptoic MSSMvsSM
mkdir -p MSSMvsSM/mhmodp
pushd MSSMvsSM/mhmodp
combineTool.py -M AsymptoticGrid ../scripts/mssm_asymptotic_grid_mhmodp.json -d ../output/mssm_freezing_vsSM_mhmodp/cmb/mhmodp.root --job-mode 'interactive' --task-name 'mssm_mhmodp' --redefineSignalPOI x --setPhysicsModelParameters r=1 --parallel 20
popd
mkdir -p MSSMvsSM/hmssm
pushd MSSMvsSM/hmssm
combineTool.py -M AsymptoticGrid ../scripts/mssm_asymptotic_grid_hMSSM.json -d ../output/mssm_freezing_vsSM_mhmodp/cmb/hmssm.root --job-mode 'interactive' --task-name 'mssm_hmssm' --redefineSignalPOI x --setPhysicsModelParameters r=1 --parallel 20
popd
