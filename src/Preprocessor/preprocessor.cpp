#include "preprocessor.hh"
#include "../Exceptions/IO_exceptions.hh"
#include "../Utiities/string_utilities.hh"

#include <fstream>
#include <ctime>

namespace Arbor::preprocessor
{
    source_file_t preprocess(const std::string& file_name)
    {
        std::ifstream fin(file_name);
        if (!fin.is_open())
        {
            std::string what_arg = "Unable to open source file: " + file_name;
            throw exceptions::file_not_found_exception(what_arg);
        }

        std::string curr_line;
        int curr_line_no = 1;

        while(getline(fin, curr_line))
        {
            //Replace macros
            replace_all(curr_line, "__FILE__", file_name);
            replace_all(curr_line, "__LINE__", std::to_string(curr_line_no));
            auto time = std::time(nullptr);
            replace_all(curr_line, "__DATE__", std::asctime(std::localtime(&time)));
            replace_all(curr_line, "__ARB_VERSION__", "21");
        }
    }
} // namespace Arbor::preprocessor
