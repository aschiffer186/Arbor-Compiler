#include <regex>

#include "preprocessor.hh"

///@file preprocessor.cpp

namespace Arbor::FE
{
    /**
     * @brief Replaces all occurrences of a string with the specified pattern
     * Replaces all occurences of the specified pattern in the specified string with the spcified replacement. Modifies
     * the specified string 
     * @param str the string to be modified
     * @param pattern the pattern to find and replace
     * @param replacement the replacement for the pattern
     */ 
    void replace_all(std::string& str, const std::string& pattern, const std::string& replacement)
    {
        std::regex re(pattern);
        std::string replaced;
        std::regex_replace(std::back_inserter(replaced), str.begin(), str.end(), re, replacement);
        str = replaced;
    }
} // namespace Arbor::FE
