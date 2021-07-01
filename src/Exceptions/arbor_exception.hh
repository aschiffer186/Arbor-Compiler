#ifndef ARBOR_EXCEPTION_HH
#define ARBOR_EXCEPTION_HH 1

#include <exception>
#include <string>

namespace Arbor::exception
{
    class arbor_exception : public std::exception
    {
        public:
            explicit arbor_exception(const std::string& what_arg, arbor_exception* cause = nullptr)
                : _M_cause(cause), _M_what_arg(what_arg)
            {

            }

            arbor_exception(const std::string& what_arg, const std::string& file_name, int line, arbor_exception* cause = nullptr)
                : _M_cause(cause), _M_line(line), _M_file(file_name), _M_what_arg(what_arg)
            {

            }

            virtual int get_line() const noexcept
            {
                return _M_line;
            }

            virtual const char* get_file() const noexcept
            {
                return _M_file.c_str();
            }

            arbor_exception* get_cause() const noexcept
            {
                return _M_cause;
            }

            const char* what() const noexcept override
            {
                return _M_what_arg.c_str();
            }

            virtual ~arbor_exception()
            {
                delete _M_cause;
            }

        private:
            arbor_exception* _M_cause;
            int _M_line;
            std::string _M_file;
            std::string _M_what_arg;
    };
} // namespace Arbor::exception


#endif