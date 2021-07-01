#ifndef COMMAND_ARGS_HH
#define COMMAND_ARGS_HH 1

#include <vector>
#include <string>

namespace Arbor::preprocessor
{
    struct options
    {
        bool help_flag;
        bool version_flag;
        bool debug_flag;
        std::string output_file;
        std::vector<std::string> files;
    };

    options get_opt(int argc, char** argv);
} // namespace Arbor::preprocessor


#endif