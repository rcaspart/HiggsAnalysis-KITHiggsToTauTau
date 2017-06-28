#!/bin/bash

for CHN in et_nobtag_tight et_btag_tight et_nobtag_loosemt et_btag_loosemt mt_nobtag_tight mt_btag_tight mt_nobtag_loosemt mt_btag_loosemt tt_nobtag tt_btag
do
    make_systematicShiftPlots.py --folder ${CHN} --inputfile datacards.root --outputfolder systshifts
done
