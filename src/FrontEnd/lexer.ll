%option batch
%option noyywrap
%option yylineno
%option stack
%option outfile="Parser/Arbor_lexer.cc"


/*Necessary Code */
%{
    #include "Arbor_parser.tab.hh"
    //Define yylex() to work with Bison
    #define YYDECL yy::parser::symbol_type yylex()
    #define YY_USER_ACTION loc.columns(yyleng)
    //We need to scan a string, not a file
    auto buff = yy_scan_string(pc.get_source_file().source_code);
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
CHAR (\'(\\(f|v|n|b|t|r|a))?[^\\n\']\')|(\'\')
/*A  character string*/
STRING "[^\\n\"]*"
/*Start conditions*/
%s type_
%s func_
%%
%{
    //Get location from parser context
    yy::location_type& loc = pc.get_loc();
    //Advance location
    loc.step();
%}
{IDENTIFIER} return yy::parser::make_IDENTIFIER(yytext, loc);
<func_> {IDENTIFIER} BEGIN(type_); return::yy::parser::make_IDENTIFIER(yytext, loc);
<type_> {IDENTIFIER} BEGIN(INITIAL); return yy::parser::make_TYPENAME(yytext, loc);
{INT} return yy::parser::make_INT(std::atol(yytext), loc);
{FLOAT} return yy:parser::make_FLOAT(std::atof(yytext), loc);
{CHAR} return make_CHAR(yytext, loc);
{STRING} return yy::parser::make_STRING(yytext, loc);
"func" BEGIN(func_); return yy::parser::make_FUNC(loc);
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
