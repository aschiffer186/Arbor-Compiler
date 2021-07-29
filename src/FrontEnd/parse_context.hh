#ifndef PARSE_CONTEXT
#define PARSE_CONTEXT

#include "../Arbor.hh"

///@file parse_context.hh Containts information needed for parser

namespace Arbor::FE
{
    class parse_context
    {
        public:
            parse_context(const source_file_t& source);

            void parse();

            source_file_t get_source_file();
        
        private:
            source_file_t _M_source;


    };
} // namespace Arbor::FE


#endif