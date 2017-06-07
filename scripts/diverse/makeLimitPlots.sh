#!/bin/bash

for PROC in gg bb
do
    for FILE in `ls mssm_freezing_${PROC}H*.json`
    do
        CHN=$(basename $FILE)
        CHN=${CHN#mssm_freezing_${PROC}H_}
        CHN=${CHN%.json}

        if [ $CHN == "em" ]; then LABEL="e^{}#mu"; fi
        if [ $CHN == "tt" ]; then LABEL="#tau_{h}^{}#tau_{h}"; fi
        if [ $CHN == "et" ]; then LABEL="e^{}#tau_{h}"; fi
        if [ $CHN == "mt" ]; then LABEL="#mu^{}#tau_{h}"; fi
        if [ $CHN == "cmb" ]; then LABEL="e^{}#tau_{h}^{}+#mu^{}#tau_{h}^{}+#tau_{h}^{}#tau_{h}^{}+e^{}#mu"; fi
        if [ $CHN == "htt_et_nobtag_13TeV" ]; then LABEL="e^{}#tau_{h} no b-tag"; fi
        if [ $CHN == "htt_et_btag_13TeV" ]; then LABEL="e^{}#tau_{h} b-tag"; fi
        if [ $CHN == "htt_et_8_13TeV" ]; then LABEL="e^{}#tau_{h} no b-tag tight"; fi
        if [ $CHN == "htt_et_9_13TeV" ]; then LABEL="e^{}#tau_{h} b-tag tight"; fi
        if [ $CHN == "htt_et_10_13TeV" ]; then LABEL="e^{}#tau_{h} no b-tag loose mT"; fi
        if [ $CHN == "htt_et_11_13TeV" ]; then LABEL="e^{}#tau_{h} b-tag loose mT"; fi
        if [ $CHN == "htt_mt_nobtag_13TeV" ]; then LABEL="#mu^{}#tau_{h} no b-tag"; fi
        if [ $CHN == "htt_mt_btag_13TeV" ]; then LABEL="#mu^{}#tau_{h} b-tag"; fi
        if [ $CHN == "htt_mt_8_13TeV" ]; then LABEL="#mu^{}#tau_{h} no b-tag tight"; fi
        if [ $CHN == "htt_mt_9_13TeV" ]; then LABEL="#mu^{}#tau_{h} b-tag tight"; fi
        if [ $CHN == "htt_mt_10_13TeV" ]; then LABEL="#mu^{}#tau_{h} no b-tag loose mT"; fi
        if [ $CHN == "htt_mt_11_13TeV" ]; then LABEL="#mu^{}#tau_{h} b-tag loose mT"; fi
        if [ $CHN == "htt_em_nobtag_13TeV" ]; then LABEL="e^{}#mu no b-tag"; fi
        if [ $CHN == "htt_em_btag_13TeV" ]; then LABEL="e^{}#mu b-tag"; fi
        if [ $CHN == "htt_em_8_13TeV" ]; then LABEL="e^{}#mu no b-tag low D^{}_{#zeta}"; fi
        if [ $CHN == "htt_em_9_13TeV" ]; then LABEL="e^{}#mu b-tag low D^{}_{#zeta}"; fi
        if [ $CHN == "htt_em_10_13TeV" ]; then LABEL="e^{}#mu no b-tag medium D^{}_{#zeta}"; fi
        if [ $CHN == "htt_em_11_13TeV" ]; then LABEL="e^{}#mu b-tag medium D^{}_{#zeta}"; fi
        if [ $CHN == "htt_em_12_13TeV" ]; then LABEL="e^{}#mu no b-tag high D^{}_{#zeta}"; fi
        if [ $CHN == "htt_em_13_13TeV" ]; then LABEL="e^{}#mu b-tag high D^{}_{#zeta}"; fi
        if [ $CHN == "htt_tt_nobtag_13TeV" ]; then LABEL="#tau_{h}^{}#tau_{h} no b-tag"; fi
        if [ $CHN == "htt_tt_btag_13TeV" ]; then LABEL="#tau_{h}^{}#tau_{h} b-tag"; fi
        if [ $CHN == "htt_tt_8_13TeV" ]; then LABEL="#tau_{h}^{}#tau_{h} no b-tag"; fi
        if [ $CHN == "htt_tt_9_13TeV" ]; then LABEL="#tau_{h}^{}#tau_{h} b-tag"; fi
        if [ $CHN == "htt_cmb_nobtag_13TeV" ]; then LABEL="e^{}#tau_{h}^{}+#mu^{}#tau_{h}^{}+#tau_{h}^{}#tau_{h}^{}+e^{}#mu no b-tag"; fi
        if [ $CHN == "htt_cmb_btag_13TeV" ]; then LABEL="e^{}#tau_{h}^{}+#mu^{}#tau_{h}^{}+#tau_{h}^{}#tau_{h}^{}+e^{}#mu b-tag"; fi

        python scripts/plotMSSMLimits.py $FILE --output mssm_freezing_${PROC}H_${CHN} --show exp --process "${PROC}#phi" --title-right "35.9 fb^{-1} (13 TeV)" --title-left "${LABEL}" --logy --logx --cms-sub "Preliminary"
    #done
    python scripts/plotMSSMLimits.py mssm_freezing_${PROC}H_et.json:exp0:LineStyle=7,LineWidth=2,LineColor=ROOT.kBlue,MarkerColor=ROOT.kBlue,MarkerSize=1.2,MarkerStyle=22,Title='"'"e^{}#tau_{h}"'"' mssm_freezing_${PROC}H_mt.json:exp0:LineStyle=7,LineWidth=2,LineColor=ROOT.kRed,MarkerColor=ROOT.kRed,MarkerStyle=21,Title='"'"#mu^{}#tau_{h}"'"' mssm_freezing_${PROC}H_em.json:exp0:LineStyle=7,LineWidth=2,MarkerSize=1.6,LineColor=ROOT.kYellow+3,MarkerColor=ROOT.kYellow+3,MarkerStyle=33,Title='"'"e^{}#mu"'"' mssm_freezing_${PROC}H_tt.json:exp0:LineStyle=7,LineWidth=2,MarkerSize=1.2,LineColor=ROOT.kBlack,MarkerColor=ROOT.kBlack,MarkerStyle=23,Title='"'"#tau_{h}^{}#tau_{h}"'"' mssm_freezing_${PROC}H_cmb.json:exp0:LineStyle=7,LineWidth=2,LineColor=ROOT.kGreen+2,MarkerColor=ROOT.kGreen+2,MarkerStyle=8,Title='"'"combined"'"' --output mssm_freezing_${PROC}H_comp --show exp --process "${PROC}#phi" --title-right "35.9 fb^{-1} (13 TeV)" --logy --logx --cms-sub "Preliminary" --legend-pos "0.25,0.28,3,0.015"
    for CHN in et mt tt em cmb
    do
        if [ $CHN == "em" ]; then LABEL="e^{}#mu"; fi
        if [ $CHN == "tt" ]; then LABEL="#tau_{h}^{}#tau_{h}"; fi
        if [ $CHN == "et" ]; then LABEL="e^{}#tau_{h}"; fi
        if [ $CHN == "mt" ]; then LABEL="#mu^{}#tau_{h}"; fi
        if [ $CHN == "cmb" ]; then LABEL="e^{}#tau_{h}^{}+#mu^{}#tau_{h}^{}+#tau_{h}^{}#tau_{h}^{}+e^{}#mu"; fi
        python scripts/plotMSSMLimits.py mssm_freezing_${PROC}H_htt_${CHN}_nobtag_13TeV.json:exp0:LineStyle=7,LineWidth=2,LineColor=ROOT.kBlue,MarkerColor=ROOT.kBlue,MarkerSize=1.2,MarkerStyle=22,Title='"'"no b-tag"'"' mssm_freezing_${PROC}H_htt_${CHN}_btag_13TeV.json:exp0:LineStyle=7,LineWidth=2,LineColor=ROOT.kRed,MarkerColor=ROOT.kRed,MarkerStyle=21,Title='"'"b-tag"'"' mssm_freezing_${PROC}H_${CHN}.json:exp0:LineStyle=7,LineWidth=2,LineColor=ROOT.kGreen+2,MarkerColor=ROOT.kGreen+2,MarkerStyle=8,Title='"'"combined"'"' --output mssm_freezing_${PROC}H_comp_${CHN} --show exp --process "${PROC}#phi" --title-left "${LABEL}" --title-right "35.9 fb^{-1} (13 TeV)" --logy --logx --cms-sub "Preliminary" --legend-pos "0.25,0.15,3,0.015"
    done
done

exit

mssm_freezing_${PROC}H_et.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kBlue,MarkerStyle=22,Title='"'"e^{}#tau_{h}"'"' mssm_freezing_${PROC}H_mt.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kRed,MarkerStyle=21,Title='"'"#mu^{}#tau_{h}"'"' mssm_freezing_${PROC}H_em.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kYellow+3,MarkerStyle=33,Title='"'"e^{}#mu"'"' mssm_freezing_${PROC}H_tt.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kBlack,MarkerStyle=23,Title='"'"#tau_{h}^{}#tau_{h}"'"' mssm_freezing_${PROC}H_cmb.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kGreen+2,MarkerStyle=8,Title='"'"combined"'"'

mssm_freezing_${PROC}H_et.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kBlue,MarkerStyle=22,Title='"'"e^{}#tau_{h}"'"'
mssm_freezing_${PROC}H_mt.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kRed,MarkerStyle=21,Title='"'"#mu^{}#tau_{h}"'"'
mssm_freezing_${PROC}H_em.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kYellow+3,MarkerStyle=33,Title='"'"e^{}#mu"'"'
mssm_freezing_${PROC}H_tt.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kBlack,MarkerStyle=23,Title='"'"#tau_{h}^{}#tau_{h}"'"'
mssm_freezing_${PROC}H_cmb.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kGreen+2,MarkerStyle=8,Title='"'"combined"'"'
#mssm_freezing_${PROC}H_cmb.json:exp0:LineColor=ROOT.kGreen,MarkerColor=ROOT.kGreen,MarkerStyle=0,Title='"'"e^{}#tau_{h}^{}+#mu^{}#tau_{h}^{}+#tau_{h}^{}#tau_{h}^{}+e^{}#mu"'"'

for i in KIT Vienna
do
    for j in IC Vienna
    do
        #for CHN in et mt em tt htt_et_8_13TeV htt_et_9_13TeV htt_et_10_13TeV htt_et_11_13TeV htt_mt_8_13TeV htt_mt_9_13TeV htt_mt_10_13TeV htt_mt_11_13TeV
        for CHN in et mt tt
        do
            if [ $CHN == "em" ]; then LABEL="e^{}#mu"; fi
            if [ $CHN == "tt" ]; then LABEL="#tau_{h}^{}#tau_{h}"; fi
            if [ $CHN == "et" ]; then LABEL="e^{}#tau_{h}"; fi
            if [ $CHN == "mt" ]; then LABEL="#mu^{}#tau_{h}"; fi
            if [ $CHN == "htt_et_8_13TeV" ]; then LABEL="e^{}#tau_{h} no b-tag tight"; fi
            if [ $CHN == "htt_et_9_13TeV" ]; then LABEL="e^{}#tau_{h} b-tag tight"; fi
            if [ $CHN == "htt_mt_8_13TeV" ]; then LABEL="#mu^{}#tau_{h} no b-tag tight"; fi
            if [ $CHN == "htt_mt_9_13TeV" ]; then LABEL="#mu^{}#tau_{h} b-tag tight"; fi
            if [ $CHN == "htt_et_10_13TeV" ]; then LABEL="e^{}#tau_{h} no b-tag loosemt"; fi
            if [ $CHN == "htt_et_11_13TeV" ]; then LABEL="e^{}#tau_{h} b-tag loosemt"; fi
            if [ $CHN == "htt_mt_10_13TeV" ]; then LABEL="#mu^{}#tau_{h} no b-tag loosemt"; fi
            if [ $CHN == "htt_mt_11_13TeV" ]; then LABEL="#mu^{}#tau_{h} b-tag loosemt"; fi
            for PROC in gg bb
            do
                if [ $i == $j ]; then break; fi
                python scripts/MSSMlimitCompare.py --file mssm_${i}_ff_${PROC}H_${CHN}.json,mssm_${j}_ff_${PROC}H_${CHN}.json --labels ${i},${j} --relative --channel_label "${LABEL}" -o syncplot_${i}_${j}_ff_${PROC}H_${CHN}_fine --process "${PROC}#phi" --title "35.9 fb^{-1} (13 TeV)" --custom_y_range --y_axis_min 0 --y_axis_max 0.15
            done
        done
    done
done

for i in KIT Vienna
do
    for j in IC Vienna 
    do
        #for CHN in et mt em tt htt_et_8_13TeV htt_et_9_13TeV htt_et_10_13TeV htt_et_11_13TeV htt_mt_8_13TeV htt_mt_9_13TeV htt_mt_10_13TeV htt_mt_11_13TeV
        #for CHN in mt htt_mt_8_13TeV htt_mt_9_13TeV htt_mt_10_13TeV htt_mt_11_13TeV
        for CHN in et mt tt
        do
            if [ $CHN == "et" ]; then LABEL="e^{}#tau_{h}"; fi
            if [ $CHN == "mt" ]; then LABEL="#mu^{}#tau_{h}"; fi
            if [ $CHN == "tt" ]; then LABEL="#tau_{h}^{}#tau_{h}"; fi
            if [ $CHN == "htt_et_8_13TeV" ]; then LABEL="e^{}#tau_{h} no b-tag tight"; fi
            if [ $CHN == "htt_et_9_13TeV" ]; then LABEL="e^{}#tau_{h} b-tag tight"; fi
            if [ $CHN == "htt_mt_8_13TeV" ]; then LABEL="#mu^{}#tau_{h} no b-tag tight"; fi
            if [ $CHN == "htt_mt_9_13TeV" ]; then LABEL="#mu^{}#tau_{h} b-tag tight"; fi
            if [ $CHN == "htt_et_10_13TeV" ]; then LABEL="e^{}#tau_{h} no b-tag loosemt"; fi
            if [ $CHN == "htt_et_11_13TeV" ]; then LABEL="e^{}#tau_{h} b-tag loosemt"; fi
            if [ $CHN == "htt_mt_10_13TeV" ]; then LABEL="#mu^{}#tau_{h} no b-tag loosemt"; fi
            if [ $CHN == "htt_mt_11_13TeV" ]; then LABEL="#mu^{}#tau_{h} b-tag loosemt"; fi
            for PROC in gg bb
            do
                if [ $i == $j ]; then break; fi
                python scripts/MSSMlimitCompare.py --file mssm_${i}_MC_${PROC}H_${CHN}.json,mssm_${j}_MC_${PROC}H_${CHN}.json --labels ${i},${j} --relative --channel_label "${LABEL}" -o syncplot_${i}_${j}_${PROC}H_${CHN}_fine --process "${PROC}#phi" --title "35.9 fb^{-1} (13 TeV)" --custom_y_range --y_axis_min 0 --y_axis_max 0.15
            done
        done
    done
done
