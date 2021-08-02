%skeleton "lalr1.cc"
%require "3.7.6"

%defines
%file-prefix "Parser/Arbor_parser"

%define api.token.constructor
%define api.token.raw
%define api.value.type variant

%define parse.error detailed
%define parse.lac full

%locations

%code requires {
    #include <string>
}

//Tokens
%token <std::string> IDENTIFIER <std::string> TYPENAME;
//Literals
%token <bool> BOOL NPTR <int> INT <double> FLOAT <char> CHAR <std::string> STRING;
//Keyowrds
%token BREAK "break" BIT "bit" BOOLT "bool" CASE "case" CASTAS "castas" CATCH "catch" CATCH_ALL "catch-all" CHART "char" CLEANUP "cleanup" CONST "const";
%token CONTINUE "continue" COMPEVAL "compeval" DEFAULT "default" DELETE "delete" DO "do" ELSE "else" ELSEIF "else-if" ENUM "enum" FLOATT "float";
%token FOR "for" FUNC "func" GOTO "goto" HEAP "heap" IF "if" IN "in" INTT "int" IS "is" LET "let" LONG "long";
%token NEW "new" NOTHROWABLE "nothrowable" OPERATOR "operator" REF "ref" RREF "rref" RETHROW "rethrow" RETURN "return";
%token SHORT "short" STATIC "static" SUPER "super" SWITCH "switch" THIS "this" THROW "throw" TRY "try" TYPEOF "typeof";
%token VIRTUAL "virtual" WHILE "while" YIELD "yield";
//Operators
%token LBRAC "[" RBRAC "]" GT "<" LT ">" COMMA "," PLUS "+" MINUS "-" SLASH "/" SLASHSLASH "//" STAR "*" CARROTCARROT "^^";
%token PERCENT "%" PLUS_EQ "+=" MINUS_EQ "-=" STAR_EQ "*=" SLASH_EQ "/=" SLASHSLASH_EQ "//=" CARROTCARROT_EQ "^^=" ;
%token PERCENT_EQ "%=" LEQ "<=" GEQ ">=" EQ "==" NEQ "!=" SPACESHIP "<=>" AND "&&" OR "||" AMP "&" PIP "|" EXCLAMATION "!";
%token CARROT "^" TILDE "~" RIGHT_SHIFT ">>" LEFT_SHIFT "<<" ASSIGN "=" PLUSPLUS "++" MINUSMINUS "--"; 
%token LPAR "(" RPAR ")" QUESTION "?" COLON ":" DOT "." ARROW1 "->" LBRACE "{" RBRACE "}" ARROW2 "=>" SEMICOLON ";"
%token DOTS "...";
%token AMPEQ "&=" CARROTEQ "^=" PIPEQ "|=" TILDEEQ "~=" LEFTEQ "<<=" RIGHTEQ ">>=";
//Context helpers
%token POINTER_TYPE ARRAYL ARRAYR;
//Dummy Precedence Tokens
%token UMINUS POSTINC POSTDEC TERN

//Precedences
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
//Start smybol
start: callables | enum;

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
    type_core ARRAYL INT ARRAYR
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
    "!" "(" type_list ")"
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
    "castas" "!""(" type ")" "(" rvalue_expression ")" |
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
    "let" variable_declaration_block_list
    ;
variable_declaration_block_list:
    variable_declaration_block |
    variable_declaration_block_list "," variable_declaration_block
    ;
variable_declaration_block:
    "let" type IDENTIFIER |
    "let" type IDENTIFIER "=" expression;
no_op_statement:
    ";"
    ;

//-------------------------------------------------------------------Functions-------------------------------------------------------------------------
function:
    function_header block_statement  
    ;
function_header:
    "func" function_modifiers IDENTIFIER "(" function_argument_list ")" throwable_expression "->" return_types_list |
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
callables: 
    callable | 
    callables callable
    ;

//--------------------------------------------------------Enums-----------------------------------------------------------------------------------
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
%%