import pyparsing as pp
from pyparsing.core import Keyword
from pyparsing.diagram import to_railroad, railroad_to_html
from pyparsing.helpers import delimitedList
from railroad import Optional

#Tokens
_identifier = pp.Word(pp.alphas + '-', pp.alphanums + '-' + '_').setName("identifier")
_int = pp.Regex(r"[0-9]+[sSbBlL]?").setName("int")
_float = pp.Regex(r"([0-9]+.)|([0-9]*\.[0-9]+([eE][+-]?(0-9)*\.?[0-9]+)?)").setName("float")
_true = pp.Literal("true").setName("true")
_false = pp.Literal("false").setName("true")
_string = pp.dblQuotedString.setName("string")
_nptr = pp.Keyword("nptr").setName("nptr")

_literal = _int | _float | _true | _false | _string | _nptr

_castas = pp.Keyword("castas")
_const = Keyword("const")
_let = Keyword("let")
_ref = Keyword("ref")
_rref = pp.Keyword("rref")
_super = pp.Keyword("super")
_this = pp.Keyword("this")
_typeof = pp.Keyword("typeof")

#Grammar
type_nt = pp.Forward()
type_template_paramaters_nt = '!' +'(' + pp.delimitedList(type_nt, ',') + ')'
type_core_nt = _identifier | (_identifier + type_template_paramaters_nt)
non_reference_type_nt = type_core_nt | (type_core_nt + '*') | (type_core_nt + '*')
reference_type_nt = (_ref + non_reference_type_nt) | (_rref + non_reference_type_nt)
type_nt <<= (_const + (non_reference_type_nt | reference_type_nt)) | (non_reference_type_nt | reference_type_nt)


expression_nt = pp.Forward()
binary_expression_nt = (expression_nt + '+' + expression_nt |
    expression_nt + '-' + expression_nt |
    expression_nt + '*' + expression_nt |
    expression_nt + '/' + expression_nt |
    expression_nt + '//' + expression_nt |
    expression_nt + '^^' + expression_nt |
    expression_nt + '%' + expression_nt |
    expression_nt + '+=' + expression_nt |
    expression_nt + '-=' + expression_nt |
    expression_nt + '*=' + expression_nt |
    expression_nt + '/=' + expression_nt |
    expression_nt + '//=' + expression_nt |
    expression_nt + '^^=' + expression_nt |
    expression_nt + '%=' + expression_nt |
    expression_nt + '<' + expression_nt |
    expression_nt + '<=' + expression_nt |
    expression_nt + '>=' + expression_nt |
    expression_nt + '<=>' + expression_nt |
    expression_nt + '==' + expression_nt |
    expression_nt + '&&' + expression_nt |
    expression_nt + '||' + expression_nt |
    expression_nt + 'is' + expression_nt |
    expression_nt + '&' + expression_nt |
    expression_nt + '^' + expression_nt |
    expression_nt + '|' + expression_nt |
    expression_nt + '~' + expression_nt |
    expression_nt + '>>' + expression_nt |
    expression_nt + '<<' + expression_nt |
    expression_nt + '=' + expression_nt)
unary_expression_nt = (
    '++' + expression_nt | 
    '--' + expression_nt |
    expression_nt + '++' |
    '-' + expression_nt |
    '*' + expression_nt
)
array_index_list_nt = pp.Forward()
array_index_nt = expression_nt | pp.Optional(expression_nt) + ':' + pp.Optional(expression_nt)
array_index_list_nt <<= array_index_nt | pp.delimitedList(array_index_nt)
expression_list_nt = pp.Forward()
expression_list_nt <<= expression_nt | pp.delimitedList(expression_nt)
variable_block_nt = type_nt + _identifier + pp.Optional('=' + expression_nt)
variable_delcaration_block_list_nt = pp.Forward()
variable_delcaration_block_list_nt <<= variable_block_nt | pp.delimitedList(variable_block_nt)
variable_delcaration_nt = _let + variable_delcaration_block_list_nt
expression_nt <<= (_literal |
    _identifier |
    _this |
    _super |
    binary_expression_nt
    | unary_expression_nt |
    '(' + expression_nt + ')' + '?' + expression_nt + ':' + expression_nt |
    '('+ expression_nt + ')' |
    '[' + array_index_list_nt + ']'|
    expression_nt + '.' + expression_nt |
    expression_nt + '->' + expression_nt | 
    _typeof + '(' + expression_nt + ')' | 
    _castas + '<' + type_nt + '>' + '(' + expression_nt + ')'|
    expression_list_nt |
    variable_delcaration_nt)

#Naming non-terminals
type_nt.setName("type")
type_template_paramaters_nt.setName("type-template-paramaters")
type_core_nt.setName("type-core")
non_reference_type_nt.setName("non-reference-type")
reference_type_nt.setName("reference-type")
expression_nt.setName("expression")
binary_expression_nt.setName("binary expression")
array_index_nt.setName("array-index")
expression_list_nt.setName("expression-list")
variable_block_nt.setName("variable-block")

grammar = expression_nt

with open('index.html', 'w') as fp:
    railroad = to_railroad(grammar)
    fp.write(railroad_to_html(railroad))