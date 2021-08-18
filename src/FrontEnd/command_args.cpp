#include <cstring>
#include <iostream>
#include <regex>

#include "command_args.hh"
#include "../Arbor.hh"

///@file command_args.cpp

///@namespace Arbor::FE The parent namespace for all code for the front end of the compiler
namespace Arbor::FE
{
    args process_command_args(int argc, const char** argv)
    {
        bool debugFlag = false, versionFlag = false, helpFlag = false, outputFlag = false, inOutputFlag = false, showGrammarFlag = false;
        std::string output;
        std::vector<std::string> input_files;
        std::regex r("[_a-zA-Z](_|-|[a-zA-Z0-9])*\\.arb"); // Match Arbor file pattern
        std::cmatch s;
        for (int i = 1; i < argc; ++i) //Skip program name
        {
            const char* arg = *(argv + i);
            if (strlen(arg) == 1) // Currently there are no valid command arguments of length 1
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
                    std::cout << "Helpful help message" << std::endl;
                    helpFlag = true;
                }
                else if (strcmp(arg, "-v") == 0)
                {
                    std::cout << "Arbor version: " << ARB_VERSION << std::endl;
                    versionFlag = true;
                }
                else if (strcmp(arg, "-r") == 0)
                {
                    std::cout << "Insert beautiful grammar here." << std::endl;
                    showGrammarFlag = true;
                }
                else if (strcmp(arg, "-o") == 0)
                {
                    if (outputFlag)
                    {
                        std::cout << "May only specify one output file" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    outputFlag = true;
                    inOutputFlag = true;
                }
                else 
                {
                    std::cout << "Invalid command line option: " << arg << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            else if (strlen(arg) < 5)
            {
                //There are no valid file names of length 4 or shorter, 
                //so the only valid files in this case are output files
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
                bool is_valid_file = std::regex_match(arg, s, r);

                if (is_valid_file)
                {
                    if (!inOutputFlag)
                    {
                        input_files.emplace_back(arg);
                    }
                    else
                    {
                        output = arg;
                        inOutputFlag = false;
                    }
                }
                else 
                {
                    //Only valid files are output files in this case
                    if (!inOutputFlag)
                    {
                        std::cout << "Invalid command line argument" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    output = arg;
                    inOutputFlag = false;
                }
            }
        }

        //Check to ensure output is specified
        if (output.empty() && !helpFlag && !versionFlag && !showGrammarFlag)
        {
            std::cout << "Must specify output file" << std::endl;
            exit(EXIT_FAILURE);
        }
        //Check to ensure at least one input is specified
        if (input_files.empty() && !helpFlag && !versionFlag && !showGrammarFlag)
        {
            std::cout << "Must specify at least one input file" << std::endl;
            exit(EXIT_FAILURE);
        }

        args a = {debugFlag, helpFlag, versionFlag, showGrammarFlag, output, input_files};
        return a;
    }
} // namespace Arbor::FE
