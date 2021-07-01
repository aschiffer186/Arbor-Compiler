#include "Preprocessor/command_args.hh"

int main(int argc, char** argv)
{
    //Process command line arguments
    Arbor::preprocessor::options opts = Arbor::preprocessor::get_opt(argc, argv);
    //Extract input and output files
    std::string output_file = opts.output_file;
    std::vector<std::string> input_files = opts.files;
}