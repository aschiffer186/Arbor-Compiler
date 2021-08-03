#include "FrontEnd/command_args.hh"
#include "FrontEnd/preprocessor.hh"
#include "FrontEnd/parse_context.hh"
#include "Arbor.hh"

///@file Arbor.cpp Entry point to compiler containing main function.

int main(int argc, char** argv)
{
    Arbor::FE::args command_args = Arbor::FE::process_command_args(argc, argv);

    std::vector<std::string> input_files = command_args.input_files;
    std::vector<Arbor::source_file_t> source_files;
    
    //Read in and preproces text in preparation for lexing
    for (const auto& file: input_files)
    {
        Arbor::source_file_t source_file = Arbor::FE::preprocess(file);
        source_files.push_back(std::move(source_file));
    }

    //Parse each source file
    for(auto& source_file: source_files)
    {
        Arbor::FE::parse_context pc(source_file);
        source_file.parse_tree =  pc.parse();
    }

    return EXIT_SUCCESS;
}