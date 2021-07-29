#ifndef COMMAND_ARGS_HH
#define COMMAND_ARGS_HH

///@file command_args.hh Functionality to handle command ine arguments

#include <string>
#include <vector>

///\namespace Arbor::FE The parent namespace for all code for the front end of the compiler
namespace Arbor::FE
{
    ///Struct storing command line options and input/output files
    struct args
    {
        bool debug;
        bool help;
        bool version;
        std::string output_file;
        std::vector<std::string> input_files;
    };

    /**
     * \brief Processes command line arguments
     * Processes command line arguments to determine what options, if any, should be
     * passed to the compiler. Additionally, gets file names of input and output files.
     * @param argc the number of command line arguments 
     * @param argv an array containing the command line arguments
     * @return a struct containing options and files to be passed to the compile
     * */
    args process_command_args(int argc, char** argv);
}

#endif