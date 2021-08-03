#include "Parser/Arbor_parser.tab.hh"

#include "parse_context.hh"

namespace Arbor::FE
{
    parse_context::parse_context(const source_file_t& src)
        : _M_state(context_state::NORMAL), _M_source(src), _M_loc(), _M_lex_buffer(nullptr)
    {
        scan_begin();
    }

    parse_context::context_state parse_context::get_context_state() 
    {
        return _M_state;
    }

    void parse_context::set_context_state(parse_context::context_state s)
    {
        _M_state = s;
    }
} // namespace Arbor::FE

