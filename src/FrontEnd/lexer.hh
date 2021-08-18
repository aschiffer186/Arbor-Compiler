#ifndef LEXER_HH
#define LEXER_HH 1 

#include "../Arbor.hh"
#include <variant>
#include <concepts>

namespace Arbor::FE
{
    /**
     * @brief Lexer
     * 
     * A class to perform lexical analysis on an Arbor source file. 
     * 
     * Each lexer performs lexical analysis on exactly one source file.
     * 
     * See lex() for more details about how the lexer operates
     */ 
    class lexer
    {
        public:
            /**
             * @brief Link between lexer and parser
             * 
             * Arbor lexing is context sensitive. The lexer_state
             * enum allows the lexer to know which context to consider 
             * when lexing a source file.
             */
            enum class lexer_state
            {
                EXPECT_EXPRESSIO,
                EXPECT_TYPE
            };

            enum class token_kind
            {
                eEof,
                eIdentifier,
                eTypename,
                eNptr,
                eBool,
                eInt, 
                eFloat,
                eChar,
                eString,
                ePlus,
                eMinus,
                eTimes,
                eDivide,
                eIntDivide,
                eExp,
                eModulo,
                eBitXor
            };

            struct token_type
            {
                size_t start_col, end_col;
                size_t line;
                std::string value;
                token_kind kind;

                token_type(size_t l, size_t start_c, size_t end_c, token_kind k, const std::string& v)
                : start_col(start_c), end_col(end_c), line(l), value(v), kind(k)
                {
                    
                }
            };
        
        public:
            /**
             * @brief Constructor
             * 
             * Constructs a new lexer object that is not attached to any Arbor source file
             */ 
            lexer() = default;

            /**
             * Provides the lexer with a source file to read and resets the lexer to the 
             * beginning of the source file.
             */ 
            void set_source(const source_file_t& src);

             /**
             * @brief Lexes the lexer's source text
             * 
             * This function reads the source file character by charcter and groups the characters 
             * into tokens according to Arbor's lexical analysis rules. After performing lexical 
             * analysis, the lexer appends an end-of-file (EOF) token indicating the end of the 
             * token stream.
             * 
             * The lexer works by attempting to form the longest possible token, even if that means 
             * lexical analysis will fail further on. 
             * 
             * When lexical analysis failes, the lexer will produce an "error" token, and continue 
             * lexing. It will always attempt to lex the entire source code. 
             * 
             * If the source_file_t passsed to the lexer is empty, the lexer will still produce 
             * the EOF token. In other words, the returned vector will always contain the EOF token. 
             * 
             * @return A vector containing the source file's files tokens
             */ 
            std::vector<token_type> lex();

            /**
             * @brief Sets the current state of the lexer.
             * 
             * @param state the new ate of the lexer
             */
            void set_state(lexer_state state) noexcept;

            /**
             * @brief Returns a lookahead token. 
             * 
             * This function returns a lookahead token, that is a token that is token token ahead 
             * of the current token (this may be the EOF). After this funtion is called, the lexer will 
             * remain at the same place in the source text as before the function was called.
             * 
             * @return a lookahead token
             */ 
            token_type lookahead_token();

            /**
             * @brief Returns the current state of the lexer.
             * 
             * @return the current state of the lexer
             */ 
            lexer_state curr_state() const noexcept;

        private:
            token_type next_token();

            /**
             * Advances the lexer forward to the next non-whitespace, non-comment character. 
             */ 
            void next();

            char get_char() const;

            char lookahead() const;

        private:
            size_t _M_pos, _M_line, _M_col;
            std::string _M_source_text;
            
        private:
            //State machine details
            static const int ERROR = -1;
            static const int START = 0; 
            static const int PLUS = 1;
            static const int MINUS = 2;
            static const int STAR = 3;
            static const int DIVIDE = 4;
            static const int INT_DIVIDE = 5;
            static const int CARROT = 6;
            static const int EXP = 8;
            static const int MODULO = 7;
            static const int INT = 9;
            static const int INT_WITH_SUFFIX = 11;
            static const int FLOAT = 10;
            static const int FLOAT_WITH_EXP_BEGIN = 12;
            static const int FLOAT_WITH_SIGNED_EXP = 13;
            static const int FLOAT_WITH_EXP = 14;
            static const int FLOAT_WITH_SUFFIX = 15;
    };
}

#endif