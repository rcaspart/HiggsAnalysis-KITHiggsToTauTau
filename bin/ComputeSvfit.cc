#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

#include "Kappa/DataFormats/interface/Kappa.h"

#include "Artus/Utility/interface/RootFileHelper.h"

#include "HiggsAnalysis/KITHiggsToTauTau/interface/HttEnumTypes.h"
#include "HiggsAnalysis/KITHiggsToTauTau/interface/Utility/SvfitTools.h"


// copied from StackOverflow. Must be perfect.
void removeCharsFromString( std::string &str, char* charsToRemove ) {
	for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
		str.erase( std::remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
	}
}

int main(int argc, const char *argv[])
{

	boost::program_options::options_description args{"Svfit calculator options"};
	args.add_options()
		("help,h", "Print help message")
		("inputfile,i",  boost::program_options::value<std::string>(), "Path to the input ROOT file")
		//("inputtree,t", boost::program_options::value<std::string>(), "Path to input tree in ROOT file")
		("outputfile,o", boost::program_options::value<std::string>(), "Output filename");

	// parse the options
	boost::program_options::variables_map vm;
	boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(args).run(), vm);
	boost::program_options::notify(vm);
	
	if (vm.count("help")) {
		std::cout << "ComputeSvfit -i|--inputfile <INPUT.root> -o|--outputfile <OUTPUT.root>" << std::endl;
		return 1;
	}
	
	SvfitEventKey svfitEventKey;
	SvfitInputs svfitInputs;
	SvfitResults svfitResults;
	SvfitTools svfitTools;

	std::string inputFilename = vm["inputfile"].as<std::string>();
	char chars[] = "\"";
	removeCharsFromString(inputFilename, chars);
	std::cout << "Opening input file \"" << inputFilename << "\"..." << std::endl;
	TFile *inputFile = TFile::Open(inputFilename.c_str(), "READ");
	std::string treePath = std::string(inputFile->GetListOfKeys()->At(0)->GetName()) + std::string("/svfitCache");
	std::cout << "Reading input tree \"" << treePath << "\"..." << std::endl;
	TTree *inputTree = (TTree*)inputFile->Get(treePath.c_str());
	
	svfitEventKey.SetBranchAddresses(inputTree);
	svfitInputs.SetBranchAddresses(inputTree);
	svfitResults.SetBranchAddresses(inputTree);

	std::string outputFilename = vm["outputfile"].as<std::string>();
	TFile *outputFile = new TFile(outputFilename.c_str(), "RECREATE");
	TTree *outputTree = new TTree("svfitCache", "svfitCache");
	
	svfitEventKey.CreateBranches(outputTree);
	//svfitInputs.CreateBranches(outputTree);
	svfitResults.CreateBranches(outputTree);

	HttEnumTypes::SvfitCacheMissBehaviour svfitCacheMissBehaviour = HttEnumTypes::SvfitCacheMissBehaviour::recalculate;
	bool svfitCalculated = false;

	unsigned int nEntries = inputTree->GetEntries();
	for(unsigned int entry = 0; entry < nEntries; entry++)
	{
		std::cout << "Entry: " << entry+1 << " / " << nEntries << std::endl;
		inputTree->GetEntry(entry);
		
		svfitResults = svfitTools.GetResults(svfitEventKey, svfitInputs, svfitCalculated, svfitCacheMissBehaviour);
		svfitResults.SetBranchAddresses(outputTree);
		outputTree->Fill();
	}
	
	inputFile->Close();
	
	RootFileHelper::WriteRootObject(outputFile, outputTree, treePath);
	outputFile->Close();
	std::cout << "Outputs written to \"" << outputFilename << "\"." << std::endl;
	
	return 0;
}
