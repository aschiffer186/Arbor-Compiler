#ifndef ARBOR_HH
#define ARBOR_HH

///@file Arbor.hh This file defines data types that are required for the entire compilation process

#include <string>
#include <unordered_map>

#include "Utility/specializations.hh"
#include "FrontEnd/ParseTree/parse_tree.hh"

//Arbor facts
///Current version of Arbor
static const std::string ARB_VERSION = "0.1.0";

///@namespace Arbor The parent namespace of all C++ code for the Arbor parser
namespace Arbor
{
    /**
     * @brief Struct containing information about a source file
     * The @b source_file_t struct stores all data abouut a source file 
     * that the compiler needs to translate that source file.
     * */
    struct source_file_t
    {
        ///The name of the source file
        std::string name;
        ///The source code in the source file
        std::string source_code;
        ///Map of compiler definitions
        std::unordered_map<std::pair<std::string, int>, std::string> compiler_defs;
        ///Parse tree
        //FE::parse_tree_t parse_tree;
    };
} // namespace Arbor


#endif