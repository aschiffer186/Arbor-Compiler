#include "FrontEnd/command_args.hh"
#include "FrontEnd/preprocessor.hh"
#include "Arbor.hh"

///@file Arbor.cpp Entry point to compiler containing main function.

int main(int argc, char** argv)
{
    Arbor::FE::args command_args = Arbor::FE::process_command_args(argc, argv);

    std::vector<std::string> input_files = command_args.input_files;
    std::vector<Arbor::source_file_t> source_files;
    
    for (const auto& file: input_files)
        Arbor::source_file_t source_file = Arbor::FE::preprocess(file);

    return EXIT_SUCCESS;
}