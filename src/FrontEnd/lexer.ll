%option batch
%option noyywrap
%option yylineno
%option stack
%option outfile="Parser/Arbor_lexer.cc"
%option header-file="Parser/Arbor_lexer.hh"

/*Necessary Code */
%{
    #include "Arbor_parser.tab.hh"
    #include "location.hh"
    #include "../parse_context.hh"
    //Define yylex() to work with Bison
    #define YY_DECL yy::parser::symbol_type yylex(Arbor::FE::parse_context& pc)
    #define YY_USER_ACTION loc.columns(yyleng);
    //Forward declations of helper functions
    yy::parser::symbol_type make_CHAR(const std::string& str, const yy::parser::location_type& loc);
    yy::parser::symbol_type make_STRING(const std::string& str, const yy::parser::location_type& loc);
%}

/*Begin definitions*/
/*Identifiers*/
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
/*Unsigned integers */
INT [0-9]+[sSlLbB]?
/*Unsigned flosts */
FLOAT ([0-9]+\.)|([0-9]*\.[0-9]+([eE][+-]?(0-9)*\.?[0-9]+)?)
/*A single character*/
CHAR ('(\\(f|v|n|b|t|r|a))?[^\n']\')|('')
/*A  character string*/
STRING "[^\\n\"]*"
%%
%{
    //Get location from parser context
    yy::parser::location_type& loc = pc.get_location();
    //Advance location
    loc.step();
%}
{IDENTIFIER} {
    if (pc.get_context_state() != Arbor::FE::parse_context::context_state::TYPE)
        return yy::parser::make_IDENTIFIER(yytext, loc);
    else
        return yy::parser::make_IDENTIFIER(yytext, loc);
}
{INT} return yy::parser::make_INT(std::atol(yytext), loc);
{FLOAT} return yy::parser::make_FLOAT(std::atof(yytext), loc);
{CHAR} return make_CHAR(yytext, loc);
{STRING} return yy::parser::make_STRING(yytext, loc);
"func" return yy::parser::make_FUNC(loc);
"nptr" return yy::parser::make_NPTR(loc);
%%
yy::parser::symbol_type make_CHAR(const std::string& s, const yy::parser::location_type& loc)
{
    std::string text(s.begin() + 1, s.end() - 1);
    return yy::parser::make_CHAR(text.c_str(), loc);
}

yy::parser::symbol_type make_STRING(const std::string& s, const yy::parser::location_type& loc)
{
    std::string text(s.begin() + 1, s.end() - 1);
    return yy::parser::make_STRING(text.c_str(), loc);
}

void Arbor::FE::parse_context::scan_begin()
{
    _M_lex_buffer = yy_scan_string(_M_source.source_code.c_str());
}

Arbor::FE::parse_context::~parse_context()
{
    yy_delete_buffer(_M_lex_buffer);
}
