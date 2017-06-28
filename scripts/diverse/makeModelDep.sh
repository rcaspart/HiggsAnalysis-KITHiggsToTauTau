#!/bin/bash

#python ../CombineTools/scripts/plotLimitGrid.py MSSMvsBG/hmssm/asymptotic_grid.root --scenario-label="hMSSM scenario"  --output="mssm_freezing_hmssm_vsBG_cmb" --title-right="35.9 fb^{-1} (13 TeV)" --cms-sub="Preliminary" --contours="exp-2,exp-1,exp0,exp+1,exp+2" --model_file=$PWD/shapes/Models/hMSSM_13TeV.root --debug-output debug_hmssm.root
#python ../CombineTools/scripts/plotLimitGrid.py MSSMvsBG/mhmodp/asymptotic_grid.root --scenario-label="m_{h}^{mod+} scenario"  --output="mssm_freezing_mhmodp_cmb" --title-right="35.9 fb^{-1} (13 TeV)" --cms-sub="Preliminary" --contours="exp-2,exp-1,exp0,exp+1,exp+2" --model_file=$PWD/shapes/Models/mhmodp_mu200_13TeV.root --debug-output debug_mhmodp.root
#python ../CombineTools/scripts/plotLimitGrid.py MSSMvsSM/mhmodp/asymptotic_grid.root --scenario-label="m_{h}^{mod+} scenario"  --output="mssm_freezing_mhmodp_cmb" --title-right="35.9 fb^{-1} (13 TeV)" --cms-sub="Preliminary" --contours="exp-2,exp-1,exp0,exp+1,exp+2" --model_file=$PWD/shapes/Models/mhmodp_mu200_13TeV.root --debug-output "mhmod_vsSM.root"

#exit
python ../CombineTools/scripts/plotLimitGrid.py MSSMvsSM/mhmodp/asymptotic_grid.root --scenario-label="m_{h}^{mod+} scenario"  --output="mssm_freezing_mhmodp_cmb" --title-right="35.9 fb^{-1} (13 TeV)" --cms-sub="Preliminary" --contours="exp-2,exp-1,exp0,exp+1,exp+2" --model_file=$PWD/shapes/Models/mhmodp_mu200_13TeV.root
python ../CombineTools/scripts/plotLimitGrid.py MSSMvsBG/mhmodp/asymptotic_grid.root --scenario-label="m_{h}^{mod+} scenario"  --output="mssm_freezing_mhmodp_vsBG_cmb" --title-right="35.9 fb^{-1} (13 TeV)" --cms-sub="Preliminary" --contours="exp-2,exp-1,exp0,exp+1,exp+2" --model_file=$PWD/shapes/Models/mhmodp_mu200_13TeV.root

python ../CombineTools/scripts/plotLimitGrid.py MSSMvsSM/hmssm/asymptotic_grid.root --scenario-label="hMSSM scenario"  --output="mssm_freezing_hmssm_cmb" --title-right="35.9 fb^{-1} (13 TeV)" --cms-sub="Preliminary" --contours="exp-2,exp-1,exp0,exp+1,exp+2" --model_file=$PWD/shapes/Models/hMSSM_13TeV.root
python ../CombineTools/scripts/plotLimitGrid.py MSSMvsBG/hmssm/asymptotic_grid.root --scenario-label="hMSSM scenario"  --output="mssm_freezing_hmssm_vsBG_cmb" --title-right="35.9 fb^{-1} (13 TeV)" --cms-sub="Preliminary" --contours="exp-2,exp-1,exp0,exp+1,exp+2" --model_file=$PWD/shapes/Models/hMSSM_13TeV.root
