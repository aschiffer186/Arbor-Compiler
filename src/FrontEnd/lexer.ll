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
    yy::parser::symbol_type make_BOOL(const std::string& str, const yy::parser::location_type& loc);
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
BOOL ("true")|("false")
%%
%{
    //Get location from parser context
    yy::parser::location_type& loc = pc.get_location();
    //Advance location
    loc.step();
%}
{INT} return yy::parser::make_INT(std::atol(yytext), loc);
{FLOAT} return yy::parser::make_FLOAT(std::atof(yytext), loc);
{CHAR} return make_CHAR(yytext, loc);
{STRING} return yy::parser::make_STRING(yytext, loc);
{BOOL} return make_BOOL(yytext, loc);
as return yy::parser::make_AS(loc);
bit return yy::parser::make_BIT(loc);
bool return yy::parser::make_BOOLT(loc);
break return yy::parser::make_BREAK(loc);
case return yy::parser::make_CASE(loc);
cast-as return yy::parser::make_CASTAS(loc);
catch return yy::parser::make_CATCH(loc);
catch-all return yy::parser::make_CATCH_ALL(loc);
char return yy::parser::make_CHART(loc);
class return yy::parser::make_CLASS(loc);
cleanup return yy::parser::make_CLEANUP(loc);
const return yy::parser::make_CONST(loc);
continue return yy::parser::make_CONTINUE(loc);
compeval return yy::parser::make_COMPEVAL(loc);
ctor return yy::parser::make_CTOR(loc);
default return yy::parser::make_DEFAULT(loc);
define return yy::parser::make_DEFINE(loc);
delete return yy::parser::make_DELETE(loc);
do return yy::parser::make_DO(loc);
else return yy::parser::make_ELSE(loc);
else-if return yy::parser::make_ELSEIF(loc);
enum return yy::parser::make_ENUM(loc);
float return yy::parser::make_FLOATT(loc);
for return yy::parser::make_FOR(loc);
func return yy::parser::make_FUNC(loc);
get return yy::parser::make_GET(loc);
heap return yy::parser::make_HEAP(loc);
if return yy::parser::make_IF(loc);
import return yy::parser::make_IMPORT(loc);
in return yy::parser::make_IN(loc);
inherits return yy::parser::make_INHERITS(loc);
initialize return yy::parser::make_INITIALIZE(loc);
int return yy::parser::make_INTT(loc);
is return yy::parser::make_IS(loc);
let return yy::parser::make_LET(loc);
long return yy::parser::make_LONG(loc);
module return yy::parser::make_MODULE(loc);
new return yy::parser::make_NEW(loc);
nothrowable return yy::parser::make_NOTHROWABLE(loc);
nptr return yy::parser::make_NPTR(loc);
operator return yy::parser::make_OPERATOR(loc);
private return yy::parser::make_PRIVATE(loc);
property return yy::parser::make_PROPERTY(loc);
protected return yy::parser::make_PROTECTED(loc);
public return yy::parser::make_PUBLIC(loc);
ref return yy::parser::make_REF(loc);
rref return yy::parser::make_RREF(loc);
rethrow return yy::parser::make_RETHROW(loc);
return return yy::parser::make_RETURN(loc);
set return yy::parser::make_SET(loc);
short return yy::parser::make_SHORT(loc);
static return yy::parser::make_STATIC(loc);
super return yy::parser::make_SUPER(loc);
this return yy::parser::make_THIS(loc);
throw return yy::parser::make_THROW(loc);
try return yy::parser::make_TRY(loc);
typeof return yy::parser::make_TYPEOF(loc);
virtual return yy::parser::make_VIRTUAL(loc);
weak return yy::parser::make_WEAK(loc);
yield return yy::parser::make_YIELD(loc);
{IDENTIFIER} {
    if (pc.get_context_state() != Arbor::FE::parse_context::context_state::TYPE)
        return yy::parser::make_IDENTIFIER(yytext, loc);
    else
        return yy::parser::make_TYPENAME(yytext, loc);
}
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

yy::parser::symbol_type make_BOOL(const std::string& text, const yy::parser::location_type& loc)
{
    bool val = text == "true";
    return yy::parser::make_BOOL(val, loc);
}

void Arbor::FE::parse_context::scan_begin()
{
    _M_lex_buffer = yy_scan_string(_M_source.source_code.c_str());
}

Arbor::FE::parse_context::~parse_context()
{
    yy_delete_buffer(_M_lex_buffer);
}
