#include <gtest/gtest.h>
#include "../src/Arbor.hh"
#include "../src/FrontEnd/lexer.hh"

TEST(TestLexer, TestArithmeticExpressions)
{
    Arbor::FE::lexer l;
    
    std::string src1 = "1+2+3";
    
    Arbor::source_file_t src_t;
    src_t.source_code = src1;
    l.set_source(src_t);
    auto toks = l.lex();

    ASSERT_EQ(toks.size(), 6);
    int col = 0;
    std::vector<Arbor::FE::lexer::token_kind> expected = {Arbor::FE::lexer::token_kind::eInt, 
                    Arbor::FE::lexer::token_kind::ePlus,
                    Arbor::FE::lexer::token_kind::eInt,
                    Arbor::FE::lexer::token_kind::ePlus,
                    Arbor::FE::lexer::token_kind::eInt,
                    Arbor::FE::lexer::token_kind::eEof};
    std::vector<std::string> expected_value = {
        "1",
        "+",
        "2",
        "+",
        "3",
        "$"
    };
    for(const auto& tok : toks)
    {
        EXPECT_EQ(tok.line, 0);
        EXPECT_EQ(tok.start_col, col);
        EXPECT_EQ(tok.end_col, col + 1);
        EXPECT_EQ(tok.kind, expected[col]);
        EXPECT_STREQ(tok.value.c_str(), expected_value[col].c_str());
        ++col;
    }

    std::string src2 = "1*2-36";
    src_t.source_code = src2;
    l.set_source(src_t);
    toks = l.lex();
    ASSERT_EQ(toks.size(), 6);
    col = 0;
    expected = {Arbor::FE::lexer::token_kind::eInt, 
                    Arbor::FE::lexer::token_kind::eTimes,
                    Arbor::FE::lexer::token_kind::eInt,
                    Arbor::FE::lexer::token_kind::eMinus,
                    Arbor::FE::lexer::token_kind::eInt,
                    Arbor::FE::lexer::token_kind::eEof};
    expected_value = {
        "1",
        "*",
        "2",
        "-",
        "36",
        "$"
    };
    int idx = 0;
    for(const auto& tok : toks)
    {
        EXPECT_EQ(tok.line, 0);
        EXPECT_EQ(tok.start_col, col);
        EXPECT_EQ(tok.end_col, col + tok.value.length());
        EXPECT_EQ(tok.kind, expected[idx]);
        EXPECT_STREQ(tok.value.c_str(), expected_value[idx].c_str());
        col += tok.value.length();
        ++idx;
    }

    //Test lexing arithmetic operators
    std::string src3 = "-+*/%^^//";
    src_t.source_code = src3;
    l.set_source(src_t);
    toks = l.lex();

    expected = {
        Arbor::FE::lexer::token_kind::eMinus,
        Arbor::FE::lexer::token_kind::ePlus,
        Arbor::FE::lexer::token_kind::eDivide,
        Arbor::FE::lexer::token_kind::eTimes,
        Arbor::FE::lexer::token_kind::eModulo,
        Arbor::FE::lexer::token_kind::eExp,
        Arbor::FE::lexer::token_kind::eIntDivide,
        Arbor::FE::lexer::token_kind::eEof
    };

    expected_value = {
        "-",
        "+",
        "/",
        "*",
        "%",
        "^^",
        "//"
    };
    idx = 0;
    col = 0;
    for(const auto& tok : toks)
    {
        EXPECT_EQ(tok.line, 0);
        EXPECT_EQ(tok.start_col, col);
        EXPECT_EQ(tok.end_col, col + tok.value.length());
        EXPECT_EQ(tok.kind, expected[idx]);
        EXPECT_STREQ(tok.value.c_str(), expected_value[idx].c_str());
        col += tok.value.length();
        ++idx;
    }
}