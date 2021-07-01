#ifndef PREPROCESSOR_HH
#define PREPROCESSOR_HH 1

#include <vector>
#include <string>

namespace Arbor::preprocessor
{

    struct source_file_t
    {
        std::string _M_file_name;
        std::string _M_source_text;
        std::vector<std::string> _M_imported_files;

        explicit source_file_t(const std::string& _M_file_name);
    };

    ///\brief Preprocesses a .arb file. 
    ///
    ///The preprocessor prepares a .arb file for compilation by performing the following actions.
    ///1) The preprocessor removes all comments and replaces them with whitespace.
    ///2) The preprocessor concatenates adjacent string literals.
    ///3) The preprocess removes all import statements from the source file and records where they are from.
    ///
    ///The preprocess function returns a \b source_file_t object containg the preprocessesed source code, file
    ///name, and import statements found in the file.
    source_file_t preprocess(const std::string& file_name);

} // namespace Arbor::preprocessor


#endif