#include "string_utilities.hh"

#include <regex>

namespace Arbor
{
    void replace_all(std::string& str, const std::string& pattern, const std::string& replacement)
    {
        std::string out;
        std::regex re(pattern);
        std::regex_replace(std::back_insert_iterator(out), str.begin(), str.end(), re, replacement);
        str = out;
    }
} // namespace Arbor
