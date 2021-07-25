#include "string_utilities.hh"

#include <regex>

namespace Arbor
{
    void replace_all(std::string& str, const std::string& pattern, const std::string& replacement)
    {
        std::string out;
        std::regex re(pattern);
        std::regex_replace(std::back_inserter(out), str.begin(), str.end(), re, replacement);
        str = out;
    }

    void trim(std::string& str)
    {
        auto forward_it = str.begin();
        for (; forward_it != str.end(); ++forward_it)
        {
            if (!isspace(*forward_it))
                break;
        }

        if (forward_it == str.end())
        {
            str = "";
            return;
        }

        auto backward_it = std::prev(str.end());

        for(; backward_it != str.begin(); --backward_it)
        {
            if(!isspace(*backward_it))
                break;
        }

        str = std::string(forward_it, backward_it + 1);
    }
} // namespace Arbor
