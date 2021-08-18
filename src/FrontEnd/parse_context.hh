#ifndef PARSE_CONTEXT
#define PARSE_CONTEXT

#include "ParseTree/parse_tree.hh"
#include "../Arbor.hh"
#include "Parser/location.hh"
#include "Parser/Arbor_lexer.hh"

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
                TEMPLATE,
                NORMAL
            };
        public:
            /**
             * @brief Constructor
             * Creates a new parese_context to aid in parsing the specified source_file_t. 
             * @param source the source_file_t to parse
             */ 
            parse_context(const source_file_t& source);

            parse_tree_t parse();

            /**
             * @brief Returns the source file stored by the parse_context.
             * @return the source file stored by the parse_context
             */ 
            source_file_t get_source_file();

            /**
             * @brief Intializes the scanner to read from the source file. 
             * Initializes the scanner to read from the source file's source code 
             * instead of a file. Implemented in the scanner itself. 
             */ 
            void scan_begin();

            /***
             * @brief Return the current state the parser is in 
             * 
             * Returns a context_state enum indicating what state the parser  
             * is currently in based on what it is parsing 
             * @return the current state of the parser
             */ 
            context_state get_context_state();

            /***
             * @brief Set the current parse state
             * 
             * Set the state of the parse context.
             * @param s the new state of the parse_context
             */ 
            void set_context_state(context_state s);

            /***
             * @brief Return a reference to the parser's location
             * 
             * Returns a reference to the parser's location.
             * @return a reference to the parser's location
             */ 
            yy::location& get_location();

            std::vector<syntax_node*>& tree();

            ~parse_context();
        private:
            context_state _M_state;
            source_file_t _M_source;
            yy::location _M_loc;
            std::vector<syntax_node*> _M_trees;
            YY_BUFFER_STATE _M_lex_buffer;
    };
} // namespace Arbor::FE


#endif