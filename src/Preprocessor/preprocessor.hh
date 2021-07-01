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
    };

    class preprocessor
    {
        public:
            preprocessor() = default;

            source_file_t preprocess(const std::string& file_name);
        private:
            std::vector<std::string> _M_seen_declaration_files;
    };
} // namespace Arbor::preprocessor


#endif