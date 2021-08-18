#include "lexer.hh"

namespace Arbor::FE
{
    void lexer::set_source(const source_file_t& src)
    {
        _M_source_text = src.source_code;
        _M_line = 0;
        _M_col = 0;
        _M_pos = 0;
    }

    std::vector<lexer::token_type> lexer::lex()
    {
        std::vector<lexer::token_type> tokens;
        while(_M_pos < _M_source_text.length())
        {
            lexer::token_type t = next_token();
            tokens.push_back(t);
        }
        tokens.push_back(lexer::token_type(_M_line, _M_col, _M_col + 1, token_kind::eEof, "$"));
        return tokens;
    }

    lexer::token_type lexer::next_token()
    {
        std::string token_value = "";
        size_t starting_col = _M_col;
        int curr_state = START;
        while (true)
        {
            char c = get_char();
            char l = lookahead();
            if (!c)
                break;
            switch(curr_state)
            {
                case START:
                    token_value += c;
                    if (c == '+')
                        curr_state = PLUS;
                    else if (c == '-')
                        curr_state = MINUS;
                    else if (c == '*')
                        curr_state = STAR;
                    else if (c == '/')
                        curr_state = DIVIDE;
                    else if (c == '^')
                        curr_state = CARROT;
                    else if (c == '%')
                        curr_state = MODULO;
                    else if (isdigit(c))
                        curr_state = INT;
                    else if (c == '.')
                        curr_state = FLOAT;
                    break;
                case PLUS:
                    next();
                    return lexer::token_type(_M_line, _M_col - 1, _M_col, token_kind::ePlus, token_value);
                case MINUS:
                    next();
                    return lexer::token_type(_M_line, _M_col - 1, _M_col, token_kind::eMinus, token_value);
                case STAR:
                    next();
                    return lexer::token_type(_M_line, _M_col - 1, _M_col, token_kind::eTimes, token_value);
                case DIVIDE:
                    if (lookahead() == '/')
                    {
                        next();
                        token_value += c;
                        curr_state = INT_DIVIDE;
                        break;
                    }
                    next();
                    return lexer::token_type(_M_line, _M_col - 2, _M_col - 1, token_kind::eDivide, token_value);
                case INT_DIVIDE:
                    next();
                    return lexer::token_type(_M_line, _M_col - 2, _M_col - 1, token_kind::eIntDivide, token_value);
                case CARROT:
                    if (lookahead() == '^')
                    {
                        next();
                        token_value += c;
                        curr_state = EXP;
                        break;
                    }
                    next();
                    return lexer::token_type(_M_line, _M_col - 1, _M_col, token_kind::eBitXor, token_value);
                case MODULO:
                    next();
                    return lexer::token_type(_M_line, _M_col - 1, _M_col, token_kind::eModulo, token_value);
                case INT:
                    l = tolower(l);
                    if (isdigit(l))
                    {
                        next();
                        c = get_char();
                        token_value += c;
                        break;
                    }
                    else if (l == 'b' || l == 's' || l == 'l')
                    {
                        next();
                        c = get_char();
                        token_value += c;
                        curr_state = INT_WITH_SUFFIX;
                        break;
                    }
                    else if (l == '.')
                    {
                        next();
                        c = get_char();
                        token_value += c;
                        curr_state = FLOAT;
                        break;
                    }
                    next();
                    return lexer::token_type(_M_line, _M_col - token_value.length(), _M_col, token_kind::eInt, token_value);
                case INT_WITH_SUFFIX:
                    return lexer::token_type(_M_line, _M_col - token_value.length(), _M_col, token_kind::eInt, token_value);
                case FLOAT:
                    l = tolower(l);
                    if (isdigit(l))
                    {
                        next();
                        c = get_char();
                        token_value += c;
                        break;
                    }
                    else if (l == 'e')
                    {
                        next();
                        c = get_char();
                        token_value += c;
                        curr_state = FLOAT_WITH_EXP_BEGIN;
                        break;
                    }
                    else if (l == 'f')
                    {
                        next();
                        c = get_char();
                        token_value += c;
                        curr_state = FLOAT_WITH_SUFFIX;
                        break;
                    }
                    next();
                    return lexer::token_type(_M_line, _M_col - token_value.length(), _M_col, token_kind::eFloat, token_value);
                case FLOAT_WITH_EXP_BEGIN:
                    if (isdigit(l))
                    {
                        next();
                        c = get_char();
                        token_value += c;
                        curr_state = FLOAT_WITH_EXP;
                        break;
                    }
                    else if (l == '+' || l == '-')
                    {
                        next();
                        c = get_char();
                        token_value += c;
                        curr_state = FLOAT_WITH_SIGNED_EXP;
                        break;
                    }
                    curr_state = ERROR;
                case FLOAT_WITH_EXP:
                    if (isdigit(l))
                    {
                        c = get_char();
                        next();
                        token_value += c;
                        break;
                    }
                    else if (tolower(l) == 'f')
                    {
                        next();
                        c = get_char();
                        token_value += c;
                        curr_state = FLOAT_WITH_SUFFIX;
                        break;
                    }
                    next();
                    return lexer::token_type(_M_line, _M_col - token_value.length(), _M_col, token_kind::eFloat, token_value);
                case FLOAT_WITH_SIGNED_EXP:
                    if (isdigit(l))
                    {
                        next();
                        c = get_char();
                        token_value += c;
                        curr_state = FLOAT_WITH_EXP;
                        break;
                    }
                    curr_state = ERROR;
                    break;
                case FLOAT_WITH_SUFFIX:
                    next();
                    return lexer::token_type(_M_line, _M_col - token_value.length(), _M_col, token_kind::eFloat, token_value);
            }
        }
    }

    void lexer::next()
    {
        while(true)
        {
            if (_M_pos >= _M_source_text.length())
                return;
            char ret_val = _M_source_text[_M_pos];
            ++_M_pos;
            ++_M_col;
            while(isspace(_M_source_text[_M_pos]))
            {
                ++_M_pos;
                ++_M_col;
            }
            if (_M_source_text[_M_pos] == '/')
            {
                if (lookahead() != '/' && lookahead() != '*')
                    return;
                if (lookahead() == '/')
                {
                    while (_M_pos < _M_source_text.length() && _M_source_text[_M_pos] != '\n')
                    {
                        ++_M_pos;
                        ++_M_col;
                    }
                    ++_M_col;
                    ++_M_pos;
                }
                else if (lookahead() == '*')
                {
                    while(_M_pos < _M_source_text.length() && !(_M_source_text[_M_pos] == '*' && lookahead() == '/'))
                    {
                        ++_M_pos;
                        ++_M_col;
                    }
                    ++_M_pos;
                    ++_M_pos;
                    ++_M_col;
                }
            }
            else
                return;
        }
    }

    char lexer::get_char() const
    {
        if (_M_pos >= _M_source_text.length())
            return 0;
        return _M_source_text[_M_pos];
    }

    char lexer::lookahead() const
    {
        if (_M_pos >= _M_source_text.length())
            return 0;
        return _M_source_text[_M_pos + 1];
    }
} // namespace Arbor::FE
