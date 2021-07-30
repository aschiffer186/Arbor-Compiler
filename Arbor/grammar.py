import pyparsing as pp
from pyparsing.core import Keyword
from pyparsing.diagram import to_railroad, railroad_to_html
from railroad import Optional

#Tokens
_identifier = pp.Word(pp.alphas + '-', pp.alphanums + '-' + '_').setName("identifier")
_int = pp.Regex(r"[0-9]+[sSbBlL]?").setName("int")
_float = pp.Regex(r"([0-9]+.)|([0-9]*\.[0-9]+([eE][+-]?(0-9)*\.?[0-9]+)?)").setName("float")
_true = pp.Literal("true")
_false = pp.Literal("false")
_string = pp.dblQuotedString.setName("string")

_const = Keyword("const")
_ref = Keyword("ref")
_rref = pp.Keyword("rref")

#Grammar
type_nt = pp.Forward()
type_template_paramaters_nt = '<' + pp.delimitedList(type_nt, ',') + '>'
type_core_nt = _identifier | (_identifier + type_template_paramaters_nt)
non_reference_type_nt = type_core_nt | (type_core_nt + '*') | (type_core_nt + '*')
reference_type_nt = (_ref + non_reference_type_nt) | (_rref + non_reference_type_nt)
type_nt <<= (_const + (non_reference_type_nt | reference_type_nt)) | (non_reference_type_nt | reference_type_nt)

#Naming non-terminals
type_nt.setName("type")
type_template_paramaters_nt.setName("type-template-paramaters")
type_core_nt.setName("type-core")
non_reference_type_nt.setName("non-reference-type")
reference_type_nt.setName("reference-type")

grammar = type_nt

with open('index.html', 'w') as fp:
    railroad = to_railroad(grammar)
    fp.write(railroad_to_html(railroad))