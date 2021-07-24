#ifndef STRING_UTILITIES_HH
#define STRING_UTILITIES_HH 1

#include <string>

namespace Arbor
{
    void replace_all(std::string& str, const std::string& pattern, const std::string& replacement);

    ///\brief Removes trailing and leading whitespace
    ///
    ///This function removes trailing and leading whitespace from the specified string, modifing it 
    ///in the process. Complexity: linear in the length of str
    ///
    ///\param str the string to be trimmed
    void trim(std::string& str);
} // namespace Arbor


#endif