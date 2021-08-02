#ifndef PARSE_CONTEXT
#define PARSE_CONTEXT

#include "../Arbor.hh"
#include "Parser/location.hh"

///@file parse_context.hh Containts information needed for parser

namespace Arbor::FE
{

    /***
     * @brief Helper class for parsing.
     * 
     * The parse_context class provides two functions for the parser. 
     * First, owns (and managers the memory of) the incomplete parse trees,
     * merging subtrees together until parsing is complete or there is an 
     * error. Second, the parse_context class keeps track of the parser
     * state for context-sensitive lexing. 
     */ 
    class parse_context
    {
        public:
            enum class context_state
            {
                TYPE,
                NON_TYPE
            };
        public:
            parse_context(const source_file_t& source);

            void parse();

            source_file_t get_source_file();

            /***
             * @brief Return the current state the parser is in 
             * 
             * Returns a context_state enum indicating what state the parser  
             * is currently in based on what it is parsing 
             * @return the current state of the parser
             */ 
            context_state get_context_state();

            /***
             * @brief Return a reference to the parser's location
             * 
             * Returns a reference to the parser's location.
             * @return a reference to the parser's location
             */ 
            yy::location& get_location();
        private:
            int get_parse_state;
            source_file_t _M_source;
            yy::location _M_loc;
    };
} // namespace Arbor::FE


#endif