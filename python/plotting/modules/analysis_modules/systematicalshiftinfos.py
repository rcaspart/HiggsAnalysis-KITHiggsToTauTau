# -*- coding: utf-8 -*-

"""
"""

import logging
import Artus.Utility.logger as logger
log = logging.getLogger(__name__)

import ROOT

import Artus.HarryPlotter.analysisbase as analysisbase


class SystematicalShiftInfos(analysisbase.AnalysisBase):
	"""Add information about the mean, width and number of events to the "text" in in a plot. Intended for systematical up/down shifts to show effects. Currently supports only mpl syntax."""
	def __init__(self):
		super(SystematicalShiftInfos, self).__init__()
	
	def modify_argument_parser(self, parser, args):
		super(SystematicalShiftInfos, self).modify_argument_parser(parser, args)
	
	def prepare_args(self, parser, plotData):
		super(SystematicalShiftInfos, self).prepare_args(parser, plotData)
	
	def run(self, plotData=None):
		super(SystematicalShiftInfos, self).run(plotData)


		print plotData.plotdict["root_objects"]["nominal"].GetMean(), " pm ", plotData.plotdict["root_objects"]["nominal"].GetStdDev(), " (", plotData.plotdict["root_objects"]["nominal"].Integral(), " Entries)"
		print plotData.plotdict["root_objects"]["up"].GetMean(), " pm ", plotData.plotdict["root_objects"]["up"].GetStdDev(), " (", plotData.plotdict["root_objects"]["up"].Integral(), " Entries)"
		print plotData.plotdict["root_objects"]["down"].GetMean(), " pm ", plotData.plotdict["root_objects"]["down"].GetStdDev(), " (", plotData.plotdict["root_objects"]["down"].Integral(), " Entries)"

		# mean
		plotData.plotdict["texts"] = []
		down_perc = "{0:+.2f}%".format(100*(-1+plotData.plotdict["root_objects"]["down"].GetMean()/plotData.plotdict["root_objects"]["nominal"].GetMean()))
		up_perc = "{0:+.2f}%".format(100*(-1+plotData.plotdict["root_objects"]["up"].GetMean()/plotData.plotdict["root_objects"]["nominal"].GetMean()))
		nominal = "%.2f" % plotData.plotdict["root_objects"]["nominal"].GetMean()
		plotData.plotdict["texts"].append("Mean: "+nominal+"^{"+up_perc+"}_{"+down_perc+"}")

		# width
		down_perc = "{0:+.2f}%".format(100*(-1+plotData.plotdict["root_objects"]["down"].GetStdDev()/plotData.plotdict["root_objects"]["nominal"].GetStdDev()))
		up_perc = "{0:+.2f}%".format(100*(-1+plotData.plotdict["root_objects"]["up"].GetStdDev()/plotData.plotdict["root_objects"]["nominal"].GetStdDev()))
		nominal = "%.2f" % plotData.plotdict["root_objects"]["nominal"].GetStdDev()
		plotData.plotdict["texts"].append("#sigma : "+nominal+"^{"+up_perc+"}_{"+down_perc+"}")
		# nEvents
		down_perc = "{0:+.2f}%".format(100*(-1+plotData.plotdict["root_objects"]["down"].Integral()/plotData.plotdict["root_objects"]["nominal"].Integral()))
		up_perc = "{0:+.2f}%".format(100*(-1+plotData.plotdict["root_objects"]["up"].Integral()/plotData.plotdict["root_objects"]["nominal"].Integral()))
		nominal = "%.2e" % plotData.plotdict["root_objects"]["nominal"].Integral()
		plotData.plotdict["texts"].append("N : "+nominal+"^{"+up_perc+"}_{"+down_perc+"}")
		
