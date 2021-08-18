#include <regex>
#include <fstream>
#include <iostream>

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

    std::string get_file_name(const std::string& str)
    {
        size_t idx = str.find_last_of('/');
        if (idx == std::string::npos)
            idx = str.find_last_of('\\');
        if (idx == std::string::npos)
            return str;
        std::string filename(str.begin() + idx + 1, str.end());
        return filename;
    }

    source_file_t preprocess(const std::string& filename)
    {
        std::fstream fin(filename);
        if (!fin.is_open())
        {
            //throw an error
            std::cout << "Could not open source file " << filename << ". Compilation process terminated." << std::endl;
            exit(EXIT_FAILURE);
        }
        std::string line, source_code;
        source_file_t source_file;
        std::string filepart = get_file_name(filename);
        int line_count = 1;
        while(getline(fin, line))
        {
            //Replace all magic constatns by their actual values
            replace_all(line, "__LINE__", std::to_string(line_count));
            replace_all(line, "__FILE__", filepart);
            replace_all(line, "__VERSION__", ARB_VERSION);
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
            ++line_count;
        }

        source_file.source_code = source_code;
        return source_file;
    }
} // namespace Arbor::FE
