#include <regex>
#include <fstream>

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

    source_file_t preprocess(const std::string& filename)
    {
        std::fstream fin(filename);
        if (!fin.is_open())
        {
            //throw an error
        }
        std::string line, source_code;
        source_file_t source_file;
        while(getline(fin, line))
        {
            //Replace all magic constatns by their actual values
            replace_all(line, "__LINE__", std::to_string(__LINE__));
            replace_all(line, "__FILE__", filename);
            replace_all(line, "__VERSION__", __VERSION__);
            replace_all(line, "__DATE__", __DATE__);
            replace_all(line, "__TIME__", __TIME__);
            #if defined WIN32
            replace_all(line, "__OS__", "WIN32");
            #elif defined WIN64
            replace_all(line, "__OS__", "WIN64");
            #elif defined APPLE
            replace_all(line, "__OS__", "APPLE");
            #elif defined LINUX
            replace_all(line, "__OS__", "LINUX");
            #else
            replace_all(line, "__OS__", "OTHER");
            #endif

            source_code.append(line + "\n");
        }

        source_file.source_code = source_code;
        return source_file;
    }
} // namespace Arbor::FE
