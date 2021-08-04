%skeleton "lalr1.cc"
%require "3.7.6"

%defines
%file-prefix "Parser/Arbor_parser"

%define api.token.constructor
%define api.token.raw
%define api.value.type variant

%define parse.error detailed
%define parse.lac full
%define parse.trace

%locations

%code requires {
    #include <string>
}

%param {Arbor::FE::parse_context& pc}

%code {
    #include "../parse_context.hh"
    yy::parser::symbol_type yylex(Arbor::FE::parse_context& pc);
}

//-------------------------------------------------------------------------Tokens-------------------------------------------------------------------
%token <std::string> IDENTIFIER <std::string> TYPENAME;
//-------------------------------------------------------------------------Literals------------------------------------------------------------------
%token NPTR <bool> BOOL<int> INT <double> FLOAT <std::string> CHAR <std::string> STRING;
//-------------------------------------------------------------------------Keyowrds----------------------------------------------------------------
%token AS "as" BREAK "break" BIT "bit" BOOLT "bool" CASE "case" CASTAS "castas" CATCH "catch" CATCH_ALL "catch-all" CHART "char" CLASS "class" CLEANUP "cleanup" CONST "const";
%token CONTINUE "continue" COMPEVAL "compeval" CTOR "ctor" DEFAULT "default" DEFINE "define" DELETE "delete" DO "do" ELSE "else" ELSEIF "else-if" ENUM "enum" FLOATT "float";
%token FOR "for" FUNC "func" GET "get" GOTO "goto" HEAP "heap" IF "if" IMPORT "import" IN "in" INHERITS "inherits" INITIALIZE "initialize" INTT "int" IS "is" LET "let" LONG "long" MODULE "module";
%token NEW "new" NOTHROWABLE "nothrowable" OPERATOR "operator" PRIVATE "private" PROPERTY "property" PROTECTED "protected" PUBLIC "public" REF "ref" RREF "rref" RETHROW "rethrow" RETURN "return" SET "set";
%token SHORT "short" STATIC "static" SUPER "super" SWITCH "switch" THIS "this" THROW "throw" TRY "try" TYPEOF "typeof";
%token VIRTUAL "virtual" WEAK "weak" WHILE "while" YIELD "yield";
//-----------------------------------------------------------------------Operators----------------------------------------------------------------------
%token LBRAC "[" RBRAC "]" GT "<" LT ">" COMMA "," PLUS "+" MINUS "-" SLASH "/" SLASHSLASH "//" STAR "*" CARROTCARROT "^^";
%token PERCENT "%" PLUS_EQ "+=" MINUS_EQ "-=" STAR_EQ "*=" SLASH_EQ "/=" SLASHSLASH_EQ "//=" CARROTCARROT_EQ "^^=" ;
%token PERCENT_EQ "%=" LEQ "<=" GEQ ">=" EQ "==" NEQ "!=" SPACESHIP "<=>" AND "&&" OR "||" AMP "&" PIP "|" EXCLAMATION "!";
%token CARROT "^" TILDE "~" RIGHT_SHIFT ">>" LEFT_SHIFT "<<" ASSIGN "=" PLUSPLUS "++" MINUSMINUS "--"; 
%token LPAR "(" RPAR ")" QUESTION "?" COLON ":" DOT "." ARROW1 "->" LBRACE "{" RBRACE "}" ARROW2 "=>" SEMICOLON ";"
%token DOTS "...";
%token AMPEQ "&=" CARROTEQ "^=" PIPEQ "|=" TILDEEQ "~=" LEFTEQ "<<=" RIGHTEQ ">>=";
//--------------------------------------------------------------------Context helpers--------------------------------------------------------------
%token POINTER_TYPE ARRAYL ARRAYR T_BEGIN T_END;
//-----------------------------------------------------------------Dummy Precedence Tokens---------------------------------------------------------
%token UMINUS POSTINC POSTDEC TERN

//---------------------------------------------------------------------Precedences------------------------------------------------------------------
%right "+=" "-=" "*=" "/=" "//=" "^^=" "%=" "="  "^=" "&=" "~=" "|=" ">>=" "<<=" TERN "is"
%left "||"
%left "&&"
%left "|"
%left "^"
%left "&"
%left "==" "!="
%left "<" "<=" ">" ">="
%left "<=>"
%left "<<" ">>"
%left "+" "-"
%left "*" "/" "%" "//"
%right "^^"
%right "!" "~" "++" "--" UMINUS DEREF
%left "." "->" POSTINC POSTDEC "("


%%
//--------------------------------------------------------------------Begin Grammar----------------------------------------------------------------
//Start smybol
start: 
    program_units | %empty
    ;

//--------------------------------------------------TYPES------------------------------------------------------------------------------------------
type: 
    "const" type_root |
    type_root
    ;
type_root:
    non_reference_type | reference_type
    ;
non_reference_type :
    type_core |
    type_core POINTER_TYPE |
    type_core "weak" POINTER_TYPE |
    type_core ARRAYL xvalue_expression ARRAYR
    ;
type_core :
    TYPENAME type_template_paramaters |
    TYPENAME |
    "bit" |
    "bool" |
    "short" |
    "int" |
    "long" |
    "float" |
    "char"
    ;
type_template_paramaters:
    T_BEGIN type_list T_END
    ;
type_list: 
    type |
    type_list "," type
    ;
reference_type: 
    "ref" non_reference_type |
    "rref" non_reference_type
    ;


//------------------------------------------------------------------Expressions--------------------------------------------------------------------
expression: //All expressions
    assignment_arg_expression |
    xvalue_expression "=" rvalue_expression
    ;
expression0:
    expression | 
    %empty
    ;
assignment_arg_expression:
    xvalue_expression |
    prvalue_expression
    ;
prvalue_expression: //Expressions that can only appear on the right side of an '=' sign
    literal |
    "super" |
    rvalue_expression "+" rvalue_expression |
    rvalue_expression "-" rvalue_expression |
    rvalue_expression "*" rvalue_expression |
    rvalue_expression "/" rvalue_expression |
    rvalue_expression "//" rvalue_expression |
    rvalue_expression "^^" rvalue_expression |
    xvalue_expression "+=" rvalue_expression |
    xvalue_expression "-=" rvalue_expression |
    xvalue_expression "*=" rvalue_expression |
    xvalue_expression "/=" rvalue_expression |
    xvalue_expression "//=" rvalue_expression |
    xvalue_expression "^^=" rvalue_expression |
    rvalue_expression ">" rvalue_expression |
    rvalue_expression ">=" rvalue_expression |
    rvalue_expression "<=" rvalue_expression |
    rvalue_expression "<=>" rvalue_expression |
    rvalue_expression "&&" rvalue_expression |
    rvalue_expression "||" rvalue_expression |
    rvalue_expression "&" rvalue_expression |
    rvalue_expression "^" rvalue_expression |
    rvalue_expression "|" rvalue_expression |
    rvalue_expression "~" rvalue_expression |
    rvalue_expression ">>" rvalue_expression |
    rvalue_expression "<<" rvalue_expression |
    xvalue_expression "&=" rvalue_expression |
    xvalue_expression "^=" rvalue_expression |
    xvalue_expression "|=" rvalue_expression |
    xvalue_expression "~=" rvalue_expression |
    xvalue_expression ">>=" rvalue_expression |
    xvalue_expression "<<=" rvalue_expression |
    rvalue_expression "is" type |
    "!" rvalue_expression |
    "-" rvalue_expression %prec UMINUS |
    "typeof" "(" rvalue_expression ")" |
    "castas" "<" type ">" "(" rvalue_expression ")" |
    "(" rvalue_expression ")" "?" rvalue_expression ":" rvalue_expression %prec TERN|
    new_expression |
    lambda_expression
    ;
rvalue_expression: //Union[prvalue, xvalue]
    prvalue_expression |
    xvalue_expression
    ;
xvalue_expression: //Expressions that can appear on the left or right side of an equal sign
    IDENTIFIER |
    "this" |
    "++" xvalue_expression |
    "--" xvalue_expression |
    xvalue_expression "++" %prec POSTINC|
    xvalue_expression "--" %prec POSTDEC |
    "*" xvalue_expression %prec DEREF |
    xvalue_expression "." xvalue_expression |
    xvalue_expression "->" xvalue_expression |
    "(" rvalue_expression ")" |
    "[" array_index_list "]" |
    function_call
    ;
literal: 
    BOOL | NPTR | INT | FLOAT | STRING | CHAR
    ;
lambda_expression: 
    "(" function_argument_list ")" "->" return_types_list "=>" block_statement 
    ;
new_expression:
    "new" type "(" function_call_list ")" |
    "new" "heap" type "(" function_call_list ")"
    ;
array_index_list:
    array_index |
    array_index_list "," array_index
    ;
array_index:
    expression |
    expression0 ":" expression0
    ;
function_call: 
    xvalue_expression "(" function_argument_list ")" |
    xvalue_expression "(" ")"
    ;
function_call_list:
    function_call_arg |
    function_call_list "," function_call_arg
    ";"
function_call_arg:
    expression 
    ;

//-------------------------------------------------------------------------Statements--------------------------------------------------------------
statement:
    block_statement |
    loop_statement | 
    conditional_statement |
    exception_statement |
    clean_up_statement |
    jump_statement |
    expression_statement |
    variable_declaration_statement |
    no_op_statement
    ;
block_statement:
    "{" statements0 "}"
    ;
statements0:
    statements | 
    %empty
    ;
statements:
    statement |
    statements statement 
    ;
loop_statement:
    while_loop_statement |
    do_loop_statement | 
    for_loop_statement
    ;
while_loop_statement:
    "while" "(" expression ")" block_statement 
    ;
do_loop_statement:
    "do" block_statement "while" "(" expression ")"
    ;
for_loop_statement: 
    "for" "(" for_loop_condition ")" block_statement  
    ;
for_loop_condition:
    variable_declaration ";" expression0 ";" expression0 |
    variable_declaration "in" expression
    ;
conditional_statement:
    if_statement_sequence |
    switch_statement
    ;
if_statement_sequence:
    if_statement else_if_statements0 else_statement0 
    ;
if_statement:
    "if" "(" expression ")" block_statement
    ;
else_if_statements0:
    else_if_statements | 
    %empty
    ;
else_if_statements:
    else_if_statement |
    else_if_statements else_if_statement 
    ;
else_if_statement:
    "else-if" "(" expression ")" block_statement
    ;
else_statement0:
    else_statement |
    %empty
    ;
else_statement:
    "else" block_statement
    ;
switch_statement:
    "switch" "(" expression ")" case_blocks0 default_block0 
    ;
case_blocks0:
    case_blocks |
    %empty
    ;
case_blocks:
    case_block |
    case_blocks case_block 
    ;
case_block:
    "case" expression ":" block_statement jump_statement
    ;
default_block0:
    default_block |
    %empty
    ;
default_block:
    "default" ":" block_statement jump_statement 
    ;
exception_statement:
    try_block catch_blocks 
    ;
try_block:
    "try" block_statement 
    ;
catch_blocks:
    catch_block |
    catch_blocks catch_block 
    ;
catch_block:
    "catch" "(" variable_declaration ")" block_statement |
    "catch-all" block_statement
    ;
clean_up_statement:
    "cleanup" "(" IDENTIFIER "," clean_up_arg ")" ";"
    ;
clean_up_arg:
    IDENTIFIER |
    lambda_expression |
    function |
    anonymous_function
    ;
jump_statement:
    "return" ";" |
    "break" ";" |
    "continue" ";" |
    "rethrow" ";" |
    "throw" expression ";" |
    "yield" ";" |
    "goto" IDENTIFIER ";"
    ;
expression_statement:
    expression ";"
    ;
variable_declaration_statement:
    variable_declaration ";"
    ;
variable_declaration:
    "let" access_modifier0 variable_declaration_block_list
    ;
variable_declaration_block_list:
    variable_declaration_block |
    variable_declaration_block_list "," variable_declaration_block
    ;
variable_declaration_block:
    "let" type IDENTIFIER |
    "let" type IDENTIFIER "=" expression;
access_modifier0:
    access_modifier |
    %empty
    ;
access_modifier:
    "public" | "private" | "protected"
    ;
no_op_statement:
    ";"
    ;

//-------------------------------------------------------------------Functions-------------------------------------------------------------------------
function:
    function_header block_statement  
    ;
function_header:
    "func" access_modifier function_modifiers IDENTIFIER "(" function_argument_list ")" throwable_expression "->" return_types_list |
    "func" IDENTIFIER "(" function_argument_list ")" throwable_expression "->" return_types_list
    ;
function_modifiers:
    "virtual" |
    "compeval" |
    "static" |
    "static" "compeval"
    ;
function_argument_list:
    function_argument |
    function_argument_list "," function_argument
    ;
function_argument:
    type IDENTIFIER |
    type "..." |
    type IDENTIFIER "=" expression
    ;
throwable_expression:
    "nothrowable" |
    "nothrowable" "(" expression ")"
    ;
return_types_list:
    return_type |
    return_types_list "," return_type
    ;
return_type:
    type |
    "typeof" "(" expression ")"
    ;
anonymous_function:
    anonymous_function_header block_statement 
    ;
anonymous_function_header:
    "func" "compeval""(" function_argument_list ")" throwable_expression "->" return_types_list |
    "func" "(" function_argument_list ")" throwable_expression "->" return_types_list
    ;
operator_overload:
    operator_overload_header block_statement  |
    operator_overload_header "=" function_options ";"
    ;
operator_overload_header:
    "operator" operator "(" function_argument_list ")" throwable_expression "->" return_types_list
operator:
    "+" | "-" | "*" | "/" | "//" | "^^" | "%" | "+=" | "-=" | "*=" | "/=" | "//=" | "^^=" | "%=" |
    ">" | ">=" | "<" | "<=" | "<=>" | "==" | "!=" | "^" | "&" | "~" | "<<" | ">>" | "=" | "++" | "--" |
    "[" "]" | "(" ")" | "->" | "new" | type
    ;
function_options:
    "delete" | "default"
    ;
callable:
    function |
    operator_overload
    ;

//-----------------------------------------------------------------Enums-----------------------------------------------------------------------------------
enum:
    "enum" "{" enum_members_list "}"
    ;
enum_members_list:
    enum_member |
    enum_members_list "," enum_member
    ;
enum_member: 
    IDENTIFIER |
    IDENTIFIER "=" INT
    ;

//-----------------------------------------------------------------Classes---------------------------------------------------------------------------
class:
    class_header "{" class_statements "}" |
    class_header "{" "}"
    ;
class_header:
    "class" IDENTIFIER |
    "class" IDENTIFIER inheritance
    ;
inheritance:
    "inherits" class_names_list
class_names_list:
    class_name |
    class_names_list "," class_name
    ;
class_name:
    IDENTIFIER |
    IDENTIFIER type_template_paramaters
    ;
class_statements:
    class_statement |
    class_statements class_statement
    ;
class_statement:
    variable_declaration_statement |
    callable |
    constructor |
    destructor |
    property |
    class
    ;
property:
    "let" access_modifier "property" type IDENTIFIER "{" property_blocks "}" ";"
property_blocks:
    get_block |
    set_block |
    get_block set_block |
    set_block get_block 
    ;
get_block:
    "get" "(" ")" "=>" IDENTIFIER ";" |
    "get" "(" ")" block_statement
    ;
set_block:
    "set" "(" ")" "=>" IDENTIFIER ";" |
    "set" "(" ")" block_statement
constructor:
    constructor_header initializer_list block_statement | 
    constructor_header initializer_list ";" |
    constructor_header block_statement |
    constructor_header "=" function_options ";"
    ;
constructor_header:
    "ctor" access_modifier compeval0 IDENTIFIER "(" function_argument_list ")" throwable_expression
    ;
initializer_list: 
    "=>" "initailize" "(" initializer_blocks_list ")"
    ;
initializer_blocks_list: 
    initializer_block |
    initializer_blocks_list "," initializer_block
    ;
initializer_block:
    IDENTIFIER ":" rvalue_expression
    ;
compeval0:
    "compeval" | 
    %empty
    ;
destructor:
    destructor_header block_statement |
    destructor_header "=" function_options ";"
destructor_header:
    "~" IDENTIFIER "(" ")"
    ;

//---------------------------------------------------------------------Templates----------------------------------------------------------------------

//------------------------------------------------------------------Global Level Statements----------------------------------------------------------------------
module:
    "module" module_name ";" |
    "module" module_name ":" IDENTIFIER ";"
    ;
module_name:
    IDENTIFIER |
    module_name "." IDENTIFIER |
    module_name "-" IDENTIFIER
    ;
import:
    "import" module_name ";" |
    "import" ":" IDENTIFIER ";"
    ;
type_definition: 
    "define" type "as" IDENTIFIER ";"
    ;
namespace:
    "namespace" module_name "{" namespace_units "}" |
    "namespace" module_name "{" "}"
    ;
namespace_units:
    namespace_unit |
    namespace_units namespace_unit
    ;
namespace_unit:
    class |
    enum |
    callable |
    type_definition |
    variable_declaration_statement
    ;

//------------------------------------------------------------------Start Symbol Heleprs-----------------------------------------------------------------------
program_units:
    program_unit |
    program_units program_unit
    ;
program_unit:
    module |
    import |
    type_definition | 
    callable |
    variable_declaration_statement |
    class |
    enum |
    namespace
    ;
%%