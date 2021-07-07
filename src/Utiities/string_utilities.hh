#ifndef STRING_UTILITIES_HH
#define STRING_UTILITIES_HH 1

#include <string>

namespace Arbor
{
    void replace_all(std::string& str, const std::string& pattern, const std::string& replacement);
} // namespace Arbor


#endif