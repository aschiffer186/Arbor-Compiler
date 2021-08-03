// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "Arbor_parser.tab.hh"


// Unqualified %code blocks.
#line 23 "parser.yy"

    #include "../parse_context.hh"
    yy::parser::symbol_type yylex(Arbor::FE::parse_context& pc);

#line 51 "Parser/Arbor_parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 143 "Parser/Arbor_parser.tab.cc"

  /// Build a parser object.
  parser::parser (Arbor::FE::parse_context& pc_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      pc (pc_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // BOOL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_STRING: // STRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    /// Discard the LAC context in case there still is one left from a
    /// previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (pc));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
           goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
           goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_BOOL: // BOOL
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_STRING: // STRING
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {

#line 641 "Parser/Arbor_parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "IDENTIFIER", "TYPENAME",
  "NPTR", "BOOL", "INT", "FLOAT", "CHAR", "STRING", "as", "break", "bit",
  "bool", "case", "castas", "catch", "catch-all", "char", "class",
  "cleanup", "const", "continue", "compeval", "ctor", "default", "define",
  "delete", "do", "else", "else-if", "enum", "float", "for", "func", "get",
  "goto", "heap", "if", "import", "in", "inherits", "initialize", "int",
  "is", "let", "long", "module", "new", "nothrowable", "operator",
  "private", "property", "protected", "public", "ref", "rref", "rethrow",
  "return", "set", "short", "static", "super", "switch", "this", "throw",
  "try", "typeof", "virtual", "weak", "while", "yield", "[", "]", "<", ">",
  ",", "+", "-", "/", "//", "*", "^^", "%", "+=", "-=", "*=", "/=", "//=",
  "^^=", "%=", "<=", ">=", "==", "!=", "<=>", "&&", "||", "&", "|", "!",
  "^", "~", ">>", "<<", "=", "++", "--", "(", ")", "?", ":", ".", "->",
  "{", "}", "=>", ";", "...", "&=", "^=", "|=", "~=", "<<=", ">>=",
  "POINTER_TYPE", "ARRAYL", "ARRAYR", "T_BEGIN", "T_END", "UMINUS",
  "POSTINC", "POSTDEC", "TERN", "DEREF", "initailize", "namespace",
  "$accept", "start", "type", "type_root", "non_reference_type",
  "type_core", "type_template_paramaters", "type_list", "reference_type",
  "expression", "expression0", "assignment_arg_expression",
  "prvalue_expression", "rvalue_expression", "xvalue_expression",
  "literal", "lambda_expression", "new_expression", "array_index_list",
  "array_index", "function_call", "function_call_list",
  "function_call_arg", "statement", "block_statement", "statements0",
  "statements", "loop_statement", "while_loop_statement",
  "do_loop_statement", "for_loop_statement", "for_loop_condition",
  "conditional_statement", "if_statement_sequence", "if_statement",
  "else_if_statements0", "else_if_statements", "else_if_statement",
  "else_statement0", "else_statement", "switch_statement", "case_blocks0",
  "case_blocks", "case_block", "default_block0", "default_block",
  "exception_statement", "try_block", "catch_blocks", "catch_block",
  "clean_up_statement", "clean_up_arg", "jump_statement",
  "expression_statement", "variable_declaration_statement",
  "variable_declaration", "variable_declaration_block_list",
  "variable_declaration_block", "access_modifier0", "access_modifier",
  "no_op_statement", "function", "function_header", "function_modifiers",
  "function_argument_list", "function_argument", "throwable_expression",
  "return_types_list", "return_type", "anonymous_function",
  "anonymous_function_header", "operator_overload",
  "operator_overload_header", "operator", "function_options", "callable",
  "enum", "enum_members_list", "enum_member", "class", "class_header",
  "inheritance", "class_names_list", "class_name", "class_statements",
  "class_statement", "property", "property_blocks", "get_block",
  "set_block", "constructor", "constructor_header", "initializer_list",
  "initializer_blocks_list", "initializer_block", "compeval0",
  "destructor", "destructor_header", "module", "module_name", "import",
  "type_definition", "namespace", "namespace_units", "namespace_unit",
  "program_units", "program_unit", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }


  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (!yy_lac_established_)
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
    return true;
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* evt)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << evt << '\n';
        yy_lac_established_ = false;
      }
  }

  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -435;

  const signed char parser::yytable_ninf_ = -32;

  const short
  parser::yypact_[] =
  {
       3,    29,   677,   -76,    50,    42,   152,    42,   698,    42,
      56,  -435,   -68,  -435,   -34,  -435,    75,  -435,  -435,  -435,
     -15,  -435,  -435,  -435,  -435,     3,  -435,    65,    14,  -435,
    -435,  -435,  1184,  -435,  -435,  -435,   278,   278,  -435,   105,
    -435,  -435,   -41,  -435,   144,    57,  -435,  -435,  -435,    -3,
    -435,   -42,   113,  -435,    32,  -435,   108,  -435,  -435,  -435,
    -435,  -435,  -435,  -435,  -435,  -435,  -435,  -435,  -435,  -435,
    -435,  -435,  -435,  -435,  -435,  -435,  -435,  -435,  -435,  -435,
    -435,  -435,  -435,  -435,  -435,  -435,    83,  -435,  -435,    92,
     -46,  -435,  -435,   607,  -435,    66,  -435,   100,  -435,   202,
    -435,   677,  -435,  -435,  -435,  -435,   209,    99,  -435,    24,
     129,   -37,  -435,   677,  -435,   206,  -435,   246,   266,   268,
    -435,   677,   195,  -435,  -435,  -435,  -435,   677,   199,  -435,
    -435,  -435,  -435,  -435,  -435,  -435,   155,   204,   165,   162,
     -34,   172,   281,   179,  1177,   171,   178,  -435,   181,  -435,
     842,   -34,   189,   190,   184,   842,   842,    24,   842,    24,
      24,   824,  -435,   186,  -435,   143,  1080,   421,  -435,  -435,
    -435,  -435,  -435,  -435,   196,   607,  -435,  -435,  -435,  -435,
    -435,  -435,   283,  -435,  -435,   225,  -435,  -435,  -435,  -435,
    -435,  -435,  -435,   200,   152,   152,   318,  -435,  -435,  -435,
    -435,   151,  -435,  -435,  -435,    94,  -435,   123,    14,   250,
    -435,  -435,   -43,  -435,  -435,   842,   271,   321,   144,  -435,
       9,   -33,  -435,  -435,   224,  -435,  -435,   332,   113,   -30,
    -435,  -435,  -435,  -435,  -435,  -435,   201,  -435,  -435,   677,
     334,  -435,   267,   294,   233,   842,   677,   234,  -435,  -435,
     842,   239,  -435,   842,   842,  -435,   230,   240,   -17,  -435,
    -435,   243,  1161,   149,   243,   149,   149,   877,   -19,  -435,
     677,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   842,  -435,  -435,   166,    24,
      24,   842,   842,   842,   842,   842,   842,  -435,  -435,   251,
     331,   283,  -435,   253,   -34,   225,  -435,  -435,   340,   322,
     265,  -435,  -435,    66,   241,  -435,    46,    66,  -435,  -435,
     202,   677,  -435,   916,  -435,  -435,  -435,   270,  -435,   677,
     336,   677,   276,  -435,   336,  -435,  -435,   311,   313,   279,
     286,   -22,  -435,   287,   291,   842,   288,  -435,   955,   292,
     842,  -435,   842,   293,   296,  -435,   580,    72,    72,    34,
      34,    34,    34,   580,   580,   796,  1241,  1211,  1041,  1271,
     227,   243,   289,   289,  1080,  1080,  1080,  1080,  1080,  1080,
    1080,  -435,    -9,  -435,  -435,  1080,  1080,  1080,  1080,  1080,
    1080,   842,   -34,  -435,  -435,  -435,   294,  -435,  -435,  -435,
     402,   677,   297,   290,   302,  -435,  -435,   298,  -435,  -435,
    -435,   842,  -435,   305,   301,    26,   842,   309,   308,    17,
     842,   -34,   842,   842,   -34,   842,  -435,    38,  -435,   391,
    -435,   -34,  -435,  -435,  -435,   842,  1096,  -435,   314,  -435,
     315,   310,   409,  -435,  -435,   423,  -435,  -435,   842,  1096,
     336,  -435,  1096,   842,  -435,    58,   677,  -435,   317,  -435,
    -435,   -34,   319,  -435,  -435,   316,  -435,    47,   842,  -435,
     842,   407,   391,  -435,  -435,   387,   326,  -435,   -55,  -435,
     -34,   -34,   677,   323,   324,    52,  -435,   327,   364,   328,
     364,   994,   337,   677,   325,  -435,  -435,   842,  -435,   329,
     333,   338,  -435,  -435,  -435,   842,   842,  1096,   -34,  -435,
    -435,    53,    -5,   842,   423,  -435,  -435,  1096,  -435,   677,
      64,  -435,  -435,  -435,   -34,   -34,  1080,   341,  -435,  -435,
     336,   339,   343,   355,   393,   418,  1080,  -435,   364,   114,
     336,   228,   228,  -435,  -435,   345,   346,   354,  -435,  -435,
     336,   359,  -435,  -435,   124,   131,  -435,   360,  1096,   472,
    -435,   473,  -435,  1096,   364,   363,   370,   364,  -435,  -435
  };

  const short
  parser::yydefact_[] =
  {
       3,     0,     0,     0,     0,     0,   173,     0,     0,     0,
       0,   306,     0,   238,     0,   239,     0,   305,   308,   307,
       0,   302,   303,   304,   309,     2,   300,   247,    13,    14,
      15,    20,     0,    19,    17,    18,     0,     0,    16,     0,
       5,     6,     8,     7,     0,     0,   175,   176,   174,     0,
     286,     0,     0,   172,     0,   234,     0,   218,   216,   202,
     203,   205,   206,   204,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   219,   217,   221,   222,   220,   224,   223,
     225,   227,   226,   228,   229,   230,     0,   233,   235,     0,
       0,     1,   166,   115,   178,     0,   199,     0,   301,     0,
     248,     0,    12,     4,    24,    25,     0,     0,     9,     0,
     243,     0,   241,     0,   182,   183,   181,     0,     0,     0,
     289,     0,   167,   168,   285,   231,   232,     0,     0,    74,
      87,    86,    88,    89,    91,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,    75,
       0,     0,     0,     0,     0,    29,     0,     0,     0,     0,
       0,     0,   177,     0,    26,    72,     0,    73,    32,    71,
      70,    85,   116,   104,     0,   114,   105,   118,   119,   120,
     106,   126,   131,   127,   107,     0,   108,   109,   110,   111,
     112,   237,   236,     0,     0,   173,     0,   246,   256,   257,
     261,     0,   254,   260,   258,     0,   259,     0,   252,   249,
     250,    22,     0,   290,    10,     0,     0,     0,     0,   240,
       0,     0,   185,   184,     0,   288,   287,     0,     0,     0,
     292,   299,   297,   296,   295,   298,     0,   293,   159,     0,
       0,   160,     0,     0,     0,     0,     0,     0,   161,   158,
       0,     0,   148,     0,     0,   163,    97,     0,     0,    95,
      72,    66,    73,    80,    65,    76,    77,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,   117,     0,
     136,   130,   132,     0,     0,   147,   149,   200,   281,   172,
       0,   245,   255,     0,     0,   273,     0,     0,   282,   253,
       0,     0,    21,     0,    11,   244,   242,   187,   188,     0,
       0,     0,   170,   169,     0,   291,   294,     0,     0,     0,
       0,     0,   164,     0,     0,     0,     0,   162,     0,     0,
      29,    84,    29,    83,     0,    64,    46,    34,    35,    37,
      38,    36,    39,    48,    47,    49,    50,    51,    52,    54,
      53,    55,    56,    57,    40,    41,    42,    43,    44,    45,
      27,   100,     0,    81,    82,    58,    59,    60,    61,    63,
      62,     0,     0,   128,   135,   133,     0,   152,   150,   280,
       0,     0,     0,     0,     0,   272,   271,     0,   251,    23,
      83,     0,   186,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,   103,     0,   101,   140,
      67,     0,    28,    98,    96,     0,     0,    99,     0,   137,
       0,     0,     0,   284,   274,     0,   283,   189,     0,     0,
       0,   171,     0,     0,   154,     0,     0,   155,     0,   156,
     157,     0,     0,   123,   125,     0,   129,     0,     0,    93,
       0,   145,   139,   141,   121,     0,     0,   194,     0,   192,
       0,     0,     0,     0,     0,     0,   277,     0,   180,     0,
     201,     0,     0,     0,     0,   196,   122,    29,    94,     0,
       0,     0,   138,   144,   142,     0,     0,     0,     0,   134,
     151,     0,     0,     0,     0,   276,   191,     0,    68,     0,
       0,   153,   124,   102,     0,     0,    69,     0,   193,    92,
       0,     0,     0,     0,   263,   264,   279,   278,   179,     0,
       0,     0,     0,   195,   275,     0,     0,     0,   265,   266,
       0,     0,   143,   146,     0,     0,   262,     0,     0,     0,
     268,     0,   270,     0,   198,     0,     0,   197,   267,   269
  };

  const short
  parser::yypgoto_[] =
  {
    -435,  -435,    -2,   450,    27,  -435,   285,  -435,  -435,   -67,
    -349,  -435,   -77,   303,   -85,  -435,    67,  -435,  -435,   132,
    -435,    62,    22,   342,   -13,  -435,  -435,  -435,  -435,  -435,
    -435,  -435,  -435,  -435,  -435,  -435,  -435,   191,  -435,  -435,
    -435,  -435,  -435,    19,  -435,  -435,  -435,  -435,  -435,   188,
    -435,  -435,  -292,  -435,   -80,  -234,  -435,   284,  -435,     1,
    -435,    84,  -435,  -435,  -109,   175,  -342,  -434,    -1,  -435,
    -435,  -435,  -435,  -435,  -281,   -92,  -114,  -435,   306,   -87,
    -435,  -435,  -435,   174,  -435,   335,  -435,  -435,   -26,   -24,
    -435,  -435,  -435,  -435,     2,  -435,  -435,  -435,  -435,   257,
    -435,  -113,  -435,  -435,   304,  -435,   498
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    10,   220,    40,    41,    42,   102,   212,    43,   436,
     257,   164,   260,   166,   262,   168,   169,   170,   258,   259,
     171,   437,   438,   172,   173,   174,   175,   176,   177,   178,
     179,   350,   180,   181,   182,   310,   311,   312,   403,   404,
     183,   481,   482,   483,   512,   513,   184,   185,   315,   316,
     186,   468,   187,   188,    11,    12,   122,   123,    52,    49,
     190,    13,    14,   117,   268,   222,   424,   488,   489,   470,
     471,    15,    16,    89,   193,    17,    18,   111,   112,    19,
      20,   100,   209,   210,   201,   202,   203,   543,   544,   545,
     204,   205,   326,   495,   496,   410,   206,   207,    21,    51,
      22,    23,    24,   236,   237,    25,    26
  };

  const short
  parser::yytable_[] =
  {
      39,    94,   427,    96,   221,   199,    88,    53,   167,   351,
     200,   443,   337,   189,   233,   235,   165,   198,   229,   432,
     464,   114,   517,     1,   216,   498,   163,   129,   500,   107,
       2,   541,    27,   118,   331,     3,   232,   118,     4,    44,
     218,   234,   413,     5,   339,    50,   417,   339,   231,     6,
      92,     7,   465,    45,     8,   542,    91,   361,   339,   115,
     362,    45,   518,   104,   105,   167,   116,   119,   339,   128,
     167,   119,   263,   165,   265,   266,   120,   340,   165,   219,
     344,    93,   502,   251,   475,   108,   109,   332,   256,   149,
     167,   364,   191,   548,   192,   189,   433,   155,   165,   211,
      97,   447,    46,   339,    47,    48,   157,    99,   163,   199,
      46,   118,    47,    48,   200,   478,   106,   277,   499,   227,
       1,   198,   233,   235,   478,   194,   466,   242,   338,   524,
     339,   159,   160,   215,   574,     4,   460,   286,   252,   577,
       9,   339,   247,   101,   232,   119,   195,   110,   479,   234,
     124,     8,   274,   275,   276,   277,   231,   508,   532,   121,
     167,    93,   525,   540,   415,   167,   113,   503,   165,   167,
      28,     1,   450,   165,   550,   286,   194,   165,   353,    29,
      30,    95,   125,   356,   -31,    31,     4,   359,    32,   392,
      93,   339,   325,   126,   328,   318,   319,   195,   554,    33,
     323,   127,     8,   196,    46,   208,    47,    48,   561,    93,
      34,   324,   213,    35,   393,   394,   197,   -31,   567,     1,
     -31,     1,    36,    37,   560,   214,     2,    38,     2,   327,
     223,     3,   425,     3,     4,   217,     4,   347,    93,    93,
     136,   569,   313,   314,   354,     6,    93,     6,   571,   224,
       8,   139,     8,   -31,   196,   -31,   296,   297,   298,   562,
     563,   -31,   299,   300,    54,   142,    90,   321,   365,   225,
     167,   226,   228,   238,   240,   167,   391,   167,   165,   239,
     241,   243,    28,   165,   244,   165,   145,   146,   245,   248,
     250,    29,    30,   442,   150,   256,   249,    31,   253,   254,
     154,   407,   255,   271,   269,   272,   273,   274,   275,   276,
     277,    33,   307,   416,   309,   230,   167,   345,   317,   278,
     279,   320,    34,   280,   165,    35,   283,   330,   335,   419,
     286,   287,   288,   341,   448,   342,   167,   348,   349,    38,
       6,   167,   -28,   355,   165,   167,   286,   167,   167,   165,
     167,   352,   360,   165,   457,   165,   165,   357,   165,   461,
     401,   402,   406,   472,   409,   474,   442,   272,   273,   274,
     275,   276,   277,   167,   412,   411,   421,   414,   296,   297,
     298,   165,   426,   521,   299,   300,   423,   428,   430,   449,
     429,   497,   286,   167,   530,   167,   431,   434,   439,   334,
     435,   165,   441,   165,   445,   451,   480,   453,   454,   452,
     446,   455,   493,   510,   458,   459,   456,   463,   473,   492,
     549,   476,   167,   462,   490,   491,   494,   504,   484,   506,
     165,   167,   270,   511,   507,   516,   523,   526,   522,   165,
     442,   517,   527,   531,   487,   534,   529,   533,   555,   537,
     535,   553,   556,   542,   541,   564,   565,   487,   505,   261,
     487,   264,   -30,   271,   267,   272,   273,   274,   275,   276,
     277,   557,   566,   568,   573,   575,   576,   519,   520,   278,
     279,   578,   103,   280,   281,   282,   283,   284,   579,   285,
     286,   287,   288,   329,   444,   -30,   467,   477,   -30,   515,
     509,   514,   405,   408,   418,   539,   289,   290,   291,   292,
     293,   294,   343,   469,   422,   487,   538,   308,   333,   559,
     558,   551,   552,    98,   336,   487,   547,   295,   296,   297,
     298,   -30,     0,   -30,   299,   300,   322,     0,     0,   -30,
     346,   301,   302,   303,   304,   305,   306,     0,     0,     0,
       0,   570,   572,     0,     0,     0,   358,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
       0,   487,     0,     0,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,     0,
       0,     0,     0,     0,   395,   396,   397,   398,   399,   400,
     129,     0,   130,   131,   132,   133,   134,   135,     0,   136,
       0,     0,     0,   137,     0,     0,     0,     0,   138,     0,
     139,     0,     0,     0,     0,     0,   140,     0,     0,     0,
       0,   141,     0,     0,   142,     0,   143,     0,     0,     0,
       0,     0,     0,     6,     0,     0,   144,     0,   272,   273,
     274,   275,   276,   277,     0,   145,   146,     0,     0,     0,
     147,   148,   149,   150,   151,   152,   280,     0,   153,   154,
     155,    28,     0,   286,   287,   288,   156,     0,     0,   157,
      29,    30,     0,     0,     0,     0,    31,     0,     0,    32,
       0,     0,    28,     0,     0,     0,     0,     0,   158,     0,
      33,    29,    30,     0,   159,   160,   161,    31,     0,     0,
      32,    34,    93,     0,    35,   162,     0,     0,     0,     0,
       0,    33,     0,    36,    37,     0,     0,     0,    38,     0,
       0,     0,    34,     0,     0,    35,     0,    55,   485,     0,
       0,     0,     0,     0,    36,    37,     0,     0,     0,    38,
       0,     0,     0,     0,     0,     0,   501,     0,     0,     0,
       0,    56,     0,    57,    58,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    78,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,   536,     0,
       0,     0,     0,     0,     0,     0,   546,   129,    28,   130,
     131,   132,   133,   134,   135,     0,     0,    29,    30,     0,
     137,     0,     0,    31,     0,   129,    32,   130,   131,   132,
     133,   134,   135,     0,     0,     0,     0,    33,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
       0,    35,     0,   144,   272,   273,   274,   275,   276,   277,
      36,    37,     0,     0,     0,    38,     0,   147,     0,   149,
       0,   144,   152,     0,     0,     0,     0,   155,     0,   286,
     287,   288,     0,   156,     0,   147,   157,   149,     0,     0,
     152,     0,     0,     0,     0,   155,     0,     0,     0,     0,
       0,   156,   270,     0,   157,   158,     0,     0,     0,     0,
       0,   159,   160,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   158,     0,     0,     0,     0,     0,   159,
     160,   161,     0,   271,     0,   272,   273,   274,   275,   276,
     277,   270,     0,     0,     0,     0,     0,     0,     0,   278,
     279,     0,     0,   280,   281,   282,   283,   284,     0,   285,
     286,   287,   288,     0,     0,     0,     0,   363,     0,     0,
       0,     0,   271,     0,   272,   273,   274,   275,   276,   277,
     270,     0,     0,     0,     0,     0,     0,     0,   278,   279,
       0,     0,   280,   281,   282,   283,   284,     0,   285,   286,
     287,   288,     0,     0,     0,     0,   420,     0,     0,     0,
       0,   271,     0,   272,   273,   274,   275,   276,   277,   270,
       0,     0,     0,     0,     0,     0,     0,   278,   279,     0,
       0,   280,   281,   282,   283,   284,     0,   285,   286,   287,
     288,     0,     0,     0,     0,   440,     0,     0,     0,     0,
     271,     0,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,     0,     0,     0,   278,   279,     0,     0,
     280,   281,   282,   283,   284,     0,   285,   286,   287,   288,
      28,     0,     0,     0,   528,     0,     0,     0,     0,    29,
      30,     0,     0,     0,     0,    31,     0,   271,    32,   272,
     273,   274,   275,   276,   277,   270,     0,     0,     0,    33,
       0,     0,     0,   278,   279,     0,     0,   280,     0,     0,
      34,     0,     0,    35,   286,   287,   288,     0,     0,     0,
       0,     0,    36,    37,     0,     0,   271,    38,   272,   273,
     274,   275,   276,   277,   486,     0,     0,     0,     0,     0,
       0,     0,   278,   279,     0,     0,   280,   281,   282,   283,
     284,    28,   285,   286,   287,   288,     0,     0,    28,     0,
      29,    30,     0,     0,     0,     0,    31,    29,    30,    32,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,   246,     0,    33,     0,     0,
       0,    34,     0,     0,    35,     0,     0,     0,    34,     0,
       0,    35,     0,    36,    37,     0,     0,     0,    38,     0,
      36,    37,     0,     0,     0,    38,   289,   290,   291,   292,
     293,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   296,   297,
     298,     0,     0,     0,   299,   300,     0,     0,     0,     0,
       0,   301,   302,   303,   304,   305,   306,   271,     0,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   279,     0,     0,   280,   281,     0,
     283,   284,     0,   285,   286,   287,   288,   271,     0,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   279,     0,     0,   280,     0,     0,
     283,   284,     0,   285,   286,   287,   288,   271,     0,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   279,     0,     0,   280,     0,     0,
     283,     0,     0,   285,   286,   287,   288
  };

  const short
  parser::yycheck_[] =
  {
       2,    14,   344,    16,   113,    97,     8,     6,    93,   243,
      97,   360,     3,    93,   128,   128,    93,    97,   127,    41,
       3,    24,    77,    20,   109,   459,    93,     3,   462,    70,
      27,    36,     3,    79,    77,    32,   128,    79,    35,   115,
      77,   128,   323,    40,    77,     3,   327,    77,   128,    46,
     118,    48,    35,     3,    51,    60,     0,    74,    77,    62,
      77,     3,   117,    36,    37,   150,    69,   113,    77,   115,
     155,   113,   157,   150,   159,   160,   118,   110,   155,   116,
     110,   115,    24,   150,   433,   126,   127,   130,   155,    65,
     175,   110,    26,   527,    28,   175,   118,    73,   175,   101,
     115,   110,    52,    77,    54,    55,    82,    42,   175,   201,
      52,    79,    54,    55,   201,    77,    11,    83,   460,   121,
      20,   201,   236,   236,    77,    25,   109,   140,   119,    77,
      77,   107,   108,   109,   568,    35,   110,   103,   151,   573,
     137,    77,   144,   129,   236,   113,    46,     3,   110,   236,
     118,    51,    80,    81,    82,    83,   236,   110,   507,    46,
     245,   115,   110,   110,   118,   250,   109,   109,   245,   254,
       4,    20,   406,   250,   110,   103,    25,   254,   245,    13,
      14,   106,    74,   250,    41,    19,    35,   254,    22,   298,
     115,    77,   205,   110,   207,   194,   195,    46,   540,    33,
     106,   109,    51,   103,    52,     3,    54,    55,   550,   115,
      44,   117,     3,    47,   299,   300,   116,    74,   560,    20,
      77,    20,    56,    57,   110,   126,    27,    61,    27,   106,
      24,    32,   341,    32,    35,   106,    35,   239,   115,   115,
      12,   117,    17,    18,   246,    46,   115,    46,   117,     3,
      51,    23,    51,   110,   103,   112,   107,   108,   109,   551,
     552,   118,   113,   114,     7,    37,     9,   116,   270,     3,
     355,     3,    77,   118,   109,   360,   110,   362,   355,    75,
     118,   109,     4,   360,     3,   362,    58,    59,   109,   118,
     109,    13,    14,   360,    66,   362,   118,    19,   109,   109,
      72,   314,   118,    76,   118,    78,    79,    80,    81,    82,
      83,    33,   116,   326,    31,   116,   401,   116,   118,    92,
      93,     3,    44,    96,   401,    47,    99,    77,     7,   331,
     103,   104,   105,   109,   401,     3,   421,     3,    71,    61,
      46,   426,   112,   109,   421,   430,   103,   432,   433,   426,
     435,   118,   112,   430,   421,   432,   433,   118,   435,   426,
     109,    30,   109,   430,    24,   432,   433,    78,    79,    80,
      81,    82,    83,   458,   109,    53,   106,   136,   107,   108,
     109,   458,   106,   492,   113,   114,    50,    76,   109,   402,
      77,   458,   103,   478,   503,   480,   110,   110,   110,   128,
     109,   478,   110,   480,   111,     3,    15,   110,   118,   411,
     114,   109,     3,   480,   109,   114,   118,   109,   431,   109,
     529,   434,   507,   114,   110,   110,     3,   110,   441,   110,
     507,   516,    45,    26,   118,   109,   112,   110,   115,   516,
     507,    77,   114,   118,   446,   112,   109,   118,   109,   516,
     112,   110,   109,    60,    36,   110,   110,   459,   471,   156,
     462,   158,    41,    76,   161,    78,    79,    80,    81,    82,
      83,   116,   118,   114,   114,     3,     3,   490,   491,    92,
      93,   118,    32,    96,    97,    98,    99,   100,   118,   102,
     103,   104,   105,   208,   362,    74,   429,   435,    77,   112,
     478,   482,   311,   315,   330,   518,    85,    86,    87,    88,
      89,    90,   228,   429,   339,   517,   517,   175,   215,   545,
     544,   534,   535,    25,   218,   527,   524,   106,   107,   108,
     109,   110,    -1,   112,   113,   114,   201,    -1,    -1,   118,
     236,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,   564,   565,    -1,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,    -1,
      -1,   573,    -1,    -1,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,    -1,
      -1,    -1,    -1,    -1,   301,   302,   303,   304,   305,   306,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    21,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    -1,    78,    79,
      80,    81,    82,    83,    -1,    58,    59,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    96,    -1,    71,    72,
      73,     4,    -1,   103,   104,   105,    79,    -1,    -1,    82,
      13,    14,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      33,    13,    14,    -1,   107,   108,   109,    19,    -1,    -1,
      22,    44,   115,    -1,    47,   118,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    44,    -1,    -1,    47,    -1,    49,   445,    -1,
      -1,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,
      -1,    73,    -1,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    99,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   515,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   523,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    -1,
      16,    -1,    -1,    19,    -1,     3,    22,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    33,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    49,    78,    79,    80,    81,    82,    83,
      56,    57,    -1,    -1,    -1,    61,    -1,    63,    -1,    65,
      -1,    49,    68,    -1,    -1,    -1,    -1,    73,    -1,   103,
     104,   105,    -1,    79,    -1,    63,    82,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    79,    45,    -1,    82,   101,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    76,    -1,    78,    79,    80,    81,    82,
      83,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,   105,    -1,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    76,    -1,    78,    79,    80,    81,    82,    83,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    96,    97,    98,    99,   100,    -1,   102,   103,
     104,   105,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    76,    -1,    78,    79,    80,    81,    82,    83,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      -1,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      76,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,   105,
       4,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    19,    -1,    76,    22,    78,
      79,    80,    81,    82,    83,    45,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    -1,    -1,
      44,    -1,    -1,    47,   103,   104,   105,    -1,    -1,    -1,
      -1,    -1,    56,    57,    -1,    -1,    76,    61,    78,    79,
      80,    81,    82,    83,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    96,    97,    98,    99,
     100,     4,   102,   103,   104,   105,    -1,    -1,     4,    -1,
      13,    14,    -1,    -1,    -1,    -1,    19,    13,    14,    22,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    38,    -1,    33,    -1,    -1,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,
      56,    57,    -1,    -1,    -1,    61,    85,    86,    87,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,   113,   114,    -1,    -1,    -1,    -1,
      -1,   120,   121,   122,   123,   124,   125,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,    -1,
      99,   100,    -1,   102,   103,   104,   105,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    -1,    -1,
      99,   100,    -1,   102,   103,   104,   105,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    -1,    -1,
      99,    -1,    -1,   102,   103,   104,   105
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    20,    27,    32,    35,    40,    46,    48,    51,   137,
     139,   192,   193,   199,   200,   209,   210,   213,   214,   217,
     218,   236,   238,   239,   240,   243,   244,     3,     4,    13,
      14,    19,    22,    33,    44,    47,    56,    57,    61,   140,
     141,   142,   143,   146,   115,     3,    52,    54,    55,   197,
       3,   237,   196,   197,   237,    49,    73,    75,    76,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    99,   102,
     103,   104,   105,   106,   107,   108,   109,   114,   140,   211,
     237,     0,   118,   115,   162,   106,   162,   115,   244,    42,
     219,   129,   144,   141,   142,   142,    11,    70,   126,   127,
       3,   215,   216,   109,    24,    62,    69,   201,    79,   113,
     118,    46,   194,   195,   118,    74,   110,   109,   115,     3,
       5,     6,     7,     8,     9,    10,    12,    16,    21,    23,
      29,    34,    37,    39,    49,    58,    59,    63,    64,    65,
      66,    67,    68,    71,    72,    73,    79,    82,   101,   107,
     108,   109,   118,   147,   149,   150,   151,   152,   153,   154,
     155,   158,   161,   162,   163,   164,   165,   166,   167,   168,
     170,   171,   172,   178,   184,   185,   188,   190,   191,   192,
     198,    26,    28,   212,    25,    46,   103,   116,   192,   213,
     217,   222,   223,   224,   228,   229,   234,   235,     3,   220,
     221,   140,   145,     3,   126,   109,   152,   106,    77,   116,
     140,   202,   203,    24,     3,     3,     3,   140,    77,   202,
     116,   192,   213,   214,   217,   239,   241,   242,   118,    75,
     109,   118,   162,   109,     3,   109,    38,   140,   118,   118,
     109,   147,   162,   109,   109,   118,   147,   148,   156,   157,
     150,   151,   152,   152,   151,   152,   152,   151,   202,   118,
      45,    76,    78,    79,    80,    81,    82,    83,    92,    93,
      96,    97,    98,    99,   100,   102,   103,   104,   105,    85,
      86,    87,    88,    89,    90,   106,   107,   108,   109,   113,
     114,   120,   121,   122,   123,   124,   125,   116,   161,    31,
     173,   174,   175,    17,    18,   186,   187,   118,   197,   197,
       3,   116,   223,   106,   117,   162,   230,   106,   162,   144,
      77,    77,   130,   151,   128,     7,   216,     3,   119,    77,
     110,   109,     3,   195,   110,   116,   242,   140,     3,    71,
     169,   193,   118,   147,   140,   109,   147,   118,   151,   147,
     112,    74,    77,   110,   110,   140,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   110,   202,   152,   152,   151,   151,   151,   151,   151,
     151,   109,    30,   176,   177,   175,   109,   162,   187,    24,
     233,    53,   109,   212,   136,   118,   162,   212,   221,   140,
     110,   106,   203,    50,   204,   202,   106,   204,    76,    77,
     109,   110,    41,   118,   110,   109,   147,   159,   160,   110,
     110,   110,   147,   148,   157,   111,   114,   110,   147,   162,
     193,     3,   140,   110,   118,   109,   118,   147,   109,   114,
     110,   147,   114,   109,     3,    35,   109,   154,   189,   199,
     207,   208,   147,   162,   147,   148,   162,   159,    77,   110,
      15,   179,   180,   181,   162,   151,    68,   140,   205,   206,
     110,   110,   109,     3,     3,   231,   232,   147,   205,   204,
     205,   151,    24,   109,   110,   162,   110,   118,   110,   160,
     147,    26,   182,   183,   181,   112,   109,    77,   117,   162,
     162,   202,   115,   112,    77,   110,   110,   114,   110,   109,
     202,   118,   148,   118,   112,   112,   151,   147,   206,   162,
     110,    36,    60,   225,   226,   227,   151,   232,   205,   202,
     110,   162,   162,   110,   204,   109,   109,   116,   227,   226,
     110,   204,   190,   190,   110,   110,   118,   204,   114,   117,
     162,   117,   162,   114,   205,     3,     3,   205,   118,   118
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     142,   142,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   144,   145,   145,   146,   146,   147,   147,   148,   148,
     149,   149,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   151,   151,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   153,   153,   153,   153,
     153,   153,   154,   155,   155,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   162,   163,   163,   164,   164,   165,   165,
     165,   166,   167,   168,   169,   169,   170,   170,   171,   172,
     173,   173,   174,   174,   175,   176,   176,   177,   178,   179,
     179,   180,   180,   181,   182,   182,   183,   184,   185,   186,
     186,   187,   187,   188,   189,   189,   189,   189,   190,   190,
     190,   190,   190,   190,   190,   191,   192,   193,   194,   194,
     195,   195,   196,   196,   197,   197,   197,   198,   199,   200,
     200,   201,   201,   201,   201,   202,   202,   203,   203,   203,
     204,   204,   205,   205,   206,   206,   207,   208,   208,   209,
     209,   210,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   212,   212,   213,   213,
     214,   215,   215,   216,   216,   217,   217,   218,   218,   219,
     220,   220,   221,   221,   222,   222,   223,   223,   223,   223,
     223,   223,   224,   225,   225,   225,   225,   226,   226,   227,
     227,   228,   228,   228,   228,   229,   230,   231,   231,   232,
     233,   233,   234,   234,   235,   236,   237,   237,   237,   238,
     239,   240,   240,   241,   241,   242,   242,   242,   242,   242,
     243,   243,   244,   244,   244,   244,   244,   244,   244,   244
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     1,     2,
       3,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     2,     2,     1,     3,     1,     0,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     4,     7,     7,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     7,     5,     6,     1,     3,     1,     3,     4,
       3,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     0,     1,     2,     1,     1,
       1,     5,     6,     5,     5,     3,     1,     1,     3,     5,
       1,     0,     1,     2,     5,     1,     0,     2,     6,     1,
       0,     1,     2,     5,     1,     0,     4,     2,     2,     1,
       2,     5,     2,     7,     1,     1,     1,     1,     2,     2,
       2,     2,     3,     2,     3,     2,     2,     3,     1,     3,
       3,     5,     1,     0,     1,     1,     1,     1,     2,    10,
       8,     1,     1,     1,     2,     1,     3,     2,     2,     4,
       1,     4,     1,     3,     1,     4,     2,     8,     7,     2,
       4,     8,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     1,     3,     4,     3,     2,     3,     2,
       1,     3,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     9,     1,     1,     2,     2,     6,     4,     6,
       4,     3,     3,     2,     4,     8,     5,     1,     3,     3,
       1,     0,     2,     4,     4,     3,     1,     3,     3,     3,
       4,     5,     4,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    74,    74,    74,    79,    80,    83,    83,    86,    87,
      88,    89,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   103,   106,   107,   110,   111,   117,   118,   121,   122,
     125,   126,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   171,   172,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   189,   189,   189,   189,
     189,   189,   192,   195,   196,   199,   200,   203,   204,   207,
     208,   211,   212,   215,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   231,   234,   235,   238,   239,   242,   243,
     244,   247,   250,   253,   256,   257,   260,   261,   264,   267,
     270,   271,   274,   275,   278,   281,   282,   285,   288,   291,
     292,   295,   296,   299,   302,   303,   306,   309,   312,   315,
     316,   319,   320,   323,   326,   327,   328,   329,   332,   333,
     334,   335,   336,   337,   338,   341,   344,   347,   350,   351,
     354,   355,   357,   358,   361,   361,   361,   364,   369,   372,
     373,   376,   377,   378,   379,   382,   383,   386,   387,   388,
     391,   392,   395,   396,   399,   400,   403,   406,   407,   410,
     411,   414,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   418,   418,   418,   418,   418,   421,   421,   424,   425,
     430,   433,   434,   437,   438,   443,   444,   447,   448,   451,
     453,   454,   457,   458,   461,   462,   465,   466,   467,   468,
     469,   470,   473,   475,   476,   477,   478,   481,   482,   485,
     486,   488,   489,   490,   491,   494,   497,   500,   501,   504,
     507,   508,   511,   512,   514,   521,   524,   525,   526,   529,
     532,   535,   536,   539,   540,   543,   544,   545,   546,   547,
     552,   553,   556,   557,   558,   559,   560,   561,   562,   563
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1788 "Parser/Arbor_parser.tab.cc"

#line 565 "parser.yy"
