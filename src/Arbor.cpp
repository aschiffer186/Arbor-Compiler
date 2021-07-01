#include "Preprocessor/command_args.hh"
#include "Preprocessor/preprocessor.hh"

int main(int argc, char** argv)
{
    //Process command line arguments
    Arbor::preprocessor::options opts = Arbor::preprocessor::get_opt(argc, argv);
    //Extract input and output files
    std::string output_file = opts.output_file;
    std::vector<std::string> input_files = opts.files;

    std::vector<Arbor::preprocessor::source_file_t> source_files;
    source_files.reserve(input_files.size());

    //Preprocess file
    for(const auto& file: input_files)
    {
        try
        {
            auto src = Arbor::preprocessor::preprocess(file);
            source_files.push_back(src);
        } catch (...) 
        {
            return EXIT_FAILURE;
        }
    }
}