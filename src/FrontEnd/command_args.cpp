#include <cstring>
#include <iostream>
#include <regex>

#include "command_args.hh"

///@file command_args.cpp

///@namespace Arbor::FE The parent namespace for all code for the front end of the compiler
namespace Arbor::FE
{
    args process_command_args(int argc, char** argv)
    {
        bool debugFlag = false, versionFlag = false, helpFlag = false, outputFlag = false, inOutputFlag = false;
        std::string output;
        std::vector<std::string> input_files;
        for (int i = 1; i < argc; ++i) //Skip program name
        {
            char* arg = *(argv + i);

            if (strlen(arg) == 1)
            {
                std::cout << "Invalid command line option" << std::endl;
                exit(EXIT_FAILURE);
            }
            else if (arg[0] == '-')
            {
                if (strcmp(arg, "-g") == 0)
                {
                    debugFlag = true;
                }
                else if (strcmp(arg, "-h") == 0)
                {
                    helpFlag = true;
                }
                else if (strcmp(arg, "-v") == 0)
                {
                    versionFlag = true;
                }
                else if (strcmp(arg, "-o") == 0)
                {
                    outputFlag = true;
                    inOutputFlag = true;
                }
                else 
                {
                    std::cout << "Invalid command line option";
                    exit(EXIT_FAILURE);
                }
            }
            else if (strlen(arg) < 5)
            {
                if (inOutputFlag)
                {
                    output = arg;
                    inOutputFlag = false;
                }
                else
                {
                    std::cout << "Invalid command line argument" << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                std::regex r("[_a-zA-Z](_|-|[a-zA-Z0-9]*\\.arb");
                std::cmatch s;
                bool is_valid_file = std::regex_match(arg, s, r);
            }
        }
    }
} // namespace Arbor::FE
