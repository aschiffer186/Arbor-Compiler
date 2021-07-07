#ifndef FILE_NOT_FOUND_EXCEPTION_HH
#define FILE_NOT_FOUND_EXCEPTION_HH 1

#include "arbor_exception.hh"

namespace Arbor::exceptions
{
    class file_not_found_exception : public arbor_exception
    {
        public:
            file_not_found_exception(const std::string& what_arg, arbor_exception* cause = nullptr)
                : arbor_exception(what_arg, cause), _M_type_str("file_not_found_exception")
            {

            }

            file_not_found_exception(const std::string& what_arg, const std::string& filename, int line, arbor_exception* cause = nullptr)
                : arbor_exception(what_arg, filename, line, cause),_M_type_str("file_not_found_exception")
            {

            }

            const char * get_exception_class() const noexcept override
            {
                return _M_type_str.c_str();
            }

        private:
            std::string _M_type_str;
    };
    
} // namespace Arbor::exceptions


#endif