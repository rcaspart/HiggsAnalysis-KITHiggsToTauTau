#!/usr/bin/env python
# -*- coding: utf-8 -*-
import glob
import Artus.HarryPlotter.utility.roottools as roottools
import Artus.Utility.tools as tools
from Artus.Utility.tfilecontextmanager import TFileContextManager
import argparse
import os
import Artus.Utility.logger as logger
import logging
log = logging.getLogger(__name__)
import ROOT as root
from cStringIO import StringIO
import sys
import pprint

title_name = {
		"et_nobtag_tight" : "e^{}#tau_{h} no b-tag tight",
        "et_btag_tight" : "e^{}#tau_{h} b-tag tight",
        "et_nobtag_loosemt" : "e^{}#tau_{h} no b-tag loose mT",
        "et_btag_loosemt" : "e^{}#tau_{h} b-tag loose mT",
        "mt_nobtag_tight" : "#mu^{}#tau_{h} no b-tag tight",
        "mt_btag_tight" : "#mu^{}#tau_{h} b-tag tight",
        "mt_nobtag_loosemt" : "#mu^{}#tau_{h} no b-tag loose mT",
        "mt_btag_loosemt" : "#mu^{}#tau_{h} b-tag loose mT",
        "tt_nobtag" : "#tau_{h}^{}#tau_{h} no b-tag",
        "tt_btag" : "#tau_{h}^{}#tau_{h} b-tag"
        }


def _call_command(args):
        command = None
        cwd = None
        if isinstance(args, basestring):
                command = args
        else:
                command = args[0]
                if len(args) > 1:
                        cwd = args[1]

        old_cwd = None
        if not cwd is None:
                old_cwd = os.getcwd()
                os.chdir(cwd)

        log.debug(command)
        logger.subprocessCall(command, shell=True)

        if not cwd is None:
                os.chdir(old_cwd)

def get_pairs(ifile, ifolder):
	f = root.TFile(ifile)
	folder = f.Get(ifolder)
	systematics = []
	for entry in folder.GetListOfKeys():
		if("Down" in entry.GetName() and not "metadata" in entry.GetName()):
			sys = entry.GetName().replace("Down", "")
			systematics.append([sys.split("_")[0], sys+"Down", sys+"Up"])
			
	pprint.pprint(systematics)
	return systematics

parser = argparse.ArgumentParser(description="evaluates systematic shifts  of input file", parents=[logger.loggingParser])
parser.add_argument("--inputfile")
parser.add_argument("--folder")
parser.add_argument("--outputfolder")
args = parser.parse_args()
logger.initLogger(args)

json = os.environ["CMSSW_BASE"] + "/src/HiggsAnalysis/KITHiggsToTauTau/data/plots/configs/syst_template.json"
print json
name_pairs = get_pairs(args.inputfile, args.folder)
base_command = " ".join(["harry.py", "-j", json, "-o", args.outputfolder+"/"+args.folder, "--files", args.inputfile])
commands = []
for pair in name_pairs:
	print pair
	command = " ".join([base_command, "--folder", args.folder, "--filename", pair[1].replace("Down", ""), "--title '", title_name[args.folder], "' -x"])
	print command
	for single_name in pair:
		command += " " + single_name
	commands.append(command)
pprint.pprint(commands)	
tools.parallelize(_call_command, commands, 10)
#p = subprocess.Popen( " ".join(call_command + ['--algorithm '+algo+' -n ".'+algo+'.'+workspace_type+'"','-d ' + w ]), cwd = os.path.dirname(w), shell=True)
#p.wait()
