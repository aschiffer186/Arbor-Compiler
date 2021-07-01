#include "command_args.hh"

#include <iostream>
#include <cstring>
#include <algorithm>

namespace Arbor::preprocessor
{
    options get_opt(int argc, char** argv)
    {
        options opt;
        bool help_flag = false;
        bool version_flag = false;
        bool debug_flag = false;
        bool seen_output_flag = false;
        bool in_output_flag = false;
        std::string output_file;
        std::vector<std::string> input_files;

        for(int i = 1; i < argc; ++i)
        {
            char* arg = argv[i];
            if (strlen(arg) < 2)
            {
                if(!in_output_flag)
                {
                    std::cerr << "Unexpected command line argument: " << arg << std::endl;
                    exit(EXIT_FAILURE);
                }
                else
                {
                    output_file = std::string(arg);
                    in_output_flag = false;
                }
            }
            else if (strlen(arg) == 2) 
            {
                if (strcmp(arg, "-h") == 0)
                {
                    if (help_flag)
                        std::cerr << "Invalid command line argument: duplicate -h flag" << std::endl;
                        exit(EXIT_FAILURE);
                    help_flag = true;
                }
                else if (strcmp(arg, "-v") == 0)
                {
                    if (version_flag)
                        std::cerr << "Invalid command line argument: duplicate -v flag" << std::endl;
                        exit(EXIT_FAILURE);
                    version_flag = true;
                }
                else if (strcmp(arg, "-g") == 0)
                {
                    if(debug_flag)
                        std::cerr << "Invalid command line argument: duplicate -g flag" << std::endl;
                        exit(EXIT_FAILURE);
                    debug_flag = true;
                }
                else if(strcmp(arg, "-o") == 0)
                {
                    if(seen_output_flag)
                        std::cerr << "Invalid command line argument: duplicate -o flag" << std::endl;
                        exit(EXIT_FAILURE);
                    seen_output_flag = true;
                }
                else
                {
                    std::cerr << "Unexpected command line argument: " << arg << std::endl;
                    exit(EXIT_FAILURE);
                }
            } 
            else if (strlen(arg) < 5)
            {
                if (in_output_flag)
                {
                    if(!in_output_flag)
                    {
                        std::cerr << "Unexpected command line argument: " << arg << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        output_file = std::string(arg);
                        in_output_flag = false;
                    }
                }
            }
            else
            {
                if(in_output_flag)
                {
                    output_file = std::string(arg);
                    in_output_flag = false;
                } 
                else 
                {
                    size_t len = strlen(arg);
                    char * pattern = ".arb";
                    if (strncmp(arg + (len - 4), pattern, 4) != 0)
                    {
                        std::cerr << "Unsupported file type; only .arb files are accepted" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    input_files.emplace_back(arg);
                }
            }
        }

        if(!seen_output_flag)
            std::cerr << "Must specify output file" << std::endl;
            exit(EXIT_FAILURE);
        
        if((seen_output_flag || debug_flag) && input_files.size() == 0)
        {
            std::cerr << "Must specify input files" << std::endl;
            exit(EXIT_FAILURE);
        }

        auto it = std::find(input_files.begin(), input_files.end(), output_file);
        if (it != input_files.begin())
        {
            std::cerr << "Error: output file is an input file" << std::endl;
            exit(EXIT_FAILURE);
        }

        options opts = {help_flag, version_flag, debug_flag, output_file, input_files};
        return opts;
    }
} // namespace Arbor::preprocessor
