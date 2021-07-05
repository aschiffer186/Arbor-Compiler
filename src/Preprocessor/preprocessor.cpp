#include "preprocessor.hh"

#include <fstream>

namespace Arbor::preprocessor
{
    source_file_t preprocess(const std::string& file_name)
    {
        std::ifstream fin(file_name);
        if (!fin.is_open())
            throw 1;
    }
} // namespace Arbor::preprocessor
