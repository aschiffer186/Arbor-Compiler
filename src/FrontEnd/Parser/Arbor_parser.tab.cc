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


  const short parser::yypact_ninf_ = -443;

  const signed char parser::yytable_ninf_ = -32;

  const short
  parser::yypact_[] =
  {
       2,    36,   401,   -82,    49,    16,   124,    96,   700,    96,
      64,  -443,    -9,  -443,     5,  -443,   -74,  -443,  -443,  -443,
      45,  -443,  -443,  -443,  -443,     2,  -443,   131,    73,  -443,
    -443,  -443,   839,  -443,  -443,  -443,   366,   366,  -443,   194,
    -443,  -443,   -45,  -443,   207,   106,  -443,  -443,  -443,    33,
    -443,   215,    29,   181,  -443,    -7,  -443,   162,  -443,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,   129,  -443,  -443,
     132,   -48,  -443,  -443,   616,  -443,   109,  -443,   137,  -443,
     255,  -443,   401,  -443,  -443,  -443,  -443,   257,   133,  -443,
     112,   161,   -19,  -443,   401,  -443,   245,  -443,   268,   154,
     271,   273,  -443,   401,   204,  -443,   279,  -443,  -443,  -443,
     401,    27,  -443,  -443,  -443,  -443,  -443,  -443,  -443,   166,
     212,   179,   173,     5,   185,   289,   187,   707,   182,   184,
    -443,   188,  -443,   143,     5,   195,   196,   189,   143,   143,
     112,   143,   112,   112,   812,  -443,   190,  -443,    91,  1050,
     428,  -443,  -443,  -443,  -443,  -443,  -443,   201,   616,  -443,
    -443,  -443,  -443,  -443,  -443,   272,  -443,  -443,   163,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,   192,   124,   124,   308,
    -443,  -443,  -443,  -443,   210,  -443,  -443,  -443,     8,  -443,
       7,    73,   235,  -443,  -443,   -47,   203,  -443,   143,   254,
     312,   207,  -443,    12,   -34,  -443,  -443,   216,  -443,  -443,
    -443,   326,   181,   213,   -26,  -443,  -443,  -443,  -443,  -443,
    -443,   211,  -443,  -443,   401,   327,  -443,   264,   292,   221,
     143,   401,   233,  -443,  -443,   143,   228,  -443,   143,   143,
    -443,   231,   239,    14,  -443,  -443,   249,  1051,   329,   249,
     329,   329,   847,   -21,  -443,   401,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,  -443,  -443,   276,   112,   112,   143,   143,   143,   143,
     143,   143,  -443,  -443,   248,   324,   272,  -443,   250,     5,
     163,  -443,  -443,   340,   313,   265,  -443,  -443,   109,   240,
    -443,    71,   109,  -443,  -443,   255,   401,  -443,  -443,   886,
    -443,  -443,  -443,   269,  -443,   401,   328,   401,   277,  -443,
    -443,   328,  -443,  -443,   301,   310,   275,   278,   -20,  -443,
     280,   282,   143,   284,  -443,   925,   288,   143,  -443,   143,
     281,   290,  -443,   589,   183,   183,    61,    61,    61,    61,
     589,   589,   784,  1131,  1101,  1011,  1161,  1191,   249,   627,
     627,  1050,  1050,  1050,  1050,  1050,  1050,  1050,  -443,   -14,
    -443,  -443,  1050,  1050,  1050,  1050,  1050,  1050,   143,     5,
    -443,  -443,  -443,   292,  -443,  -443,  -443,   399,   401,   296,
     291,   298,  -443,  -443,   293,  -443,  -443,  -443,   143,  -443,
     299,   303,    30,   143,   304,   315,    20,   143,     5,   143,
     143,     5,   143,  -443,    59,  -443,   397,  -443,     5,  -443,
    -443,  -443,   143,  1066,  -443,   311,  -443,   319,   323,   430,
    -443,  -443,   437,  -443,  -443,   143,  1066,   328,  -443,  1066,
     143,  -443,    25,   401,  -443,   334,  -443,  -443,     5,   337,
    -443,  -443,   331,  -443,    97,   143,  -443,   143,   424,   397,
    -443,  -443,   396,   343,  -443,   -42,  -443,     5,     5,   401,
     338,   342,   107,  -443,   346,   382,   347,   382,   964,   351,
     401,   345,  -443,  -443,   143,  -443,   352,   361,   368,  -443,
    -443,  -443,   143,   143,  1066,     5,  -443,  -443,   113,     0,
     143,   437,  -443,  -443,  1066,  -443,   401,   119,  -443,  -443,
    -443,     5,     5,  1050,   371,  -443,  -443,   328,   373,   374,
     370,   427,   454,  1050,  -443,   382,   123,   328,   256,   256,
    -443,  -443,   381,   387,   385,  -443,  -443,   328,   390,  -443,
    -443,   -77,   111,  -443,   392,  1066,   504,  -443,   506,  -443,
    1066,   382,   393,   402,   382,  -443,  -443
  };

  const short
  parser::yydefact_[] =
  {
       3,     0,     0,     0,     0,     0,   173,     0,     0,     0,
       0,   308,     0,   238,     0,   239,     0,   307,   310,   309,
       0,   304,   305,   306,   311,     2,   302,   247,    13,    14,
      15,    20,     0,    19,    17,    18,     0,     0,    16,     0,
       5,     6,     8,     7,     0,     0,   175,   176,   174,     0,
     287,     0,     0,     0,   172,     0,   234,     0,   218,   216,
     202,   203,   205,   206,   204,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   219,   217,   221,   222,   220,   224,
     223,   225,   227,   226,   228,   229,   230,     0,   233,   235,
       0,     0,     1,   166,   115,   178,     0,   199,     0,   303,
       0,   248,     0,    12,     4,    24,    25,     0,     0,     9,
       0,   243,     0,   241,     0,   182,   183,   181,     0,     0,
       0,     0,   290,     0,   167,   168,     0,   285,   231,   232,
       0,     0,    74,    87,    86,    88,    89,    91,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,    75,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,   177,     0,    26,    72,     0,
      73,    32,    71,    70,    85,   116,   104,     0,   114,   105,
     118,   119,   120,   106,   126,   131,   127,   107,     0,   108,
     109,   110,   111,   112,   237,   236,     0,     0,   173,     0,
     246,   256,   257,   261,     0,   254,   260,   258,     0,   259,
       0,   252,   249,   250,    22,     0,     0,    10,     0,     0,
       0,     0,   240,     0,     0,   185,   184,     0,   291,   289,
     288,     0,     0,     0,     0,   294,   301,   299,   298,   297,
     300,     0,   295,   159,     0,     0,   160,     0,     0,     0,
       0,     0,     0,   161,   158,     0,     0,   148,     0,     0,
     163,    97,     0,     0,    95,    72,    66,    73,    80,    65,
      76,    77,     0,     0,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   117,     0,   136,   130,   132,     0,     0,
     147,   149,   200,   281,   172,     0,   245,   255,     0,     0,
     273,     0,     0,   282,   253,     0,     0,    21,   292,     0,
      11,   244,   242,   187,   188,     0,     0,     0,   170,   169,
     286,     0,   293,   296,     0,     0,     0,     0,     0,   164,
       0,     0,     0,     0,   162,     0,     0,    29,    84,    29,
      83,     0,    64,    46,    34,    35,    37,    38,    36,    39,
      48,    47,    49,    50,    51,    52,    54,    53,    55,    56,
      57,    40,    41,    42,    43,    44,    45,    27,   100,     0,
      81,    82,    58,    59,    60,    61,    63,    62,     0,     0,
     128,   135,   133,     0,   152,   150,   280,     0,     0,     0,
       0,     0,   272,   271,     0,   251,    23,    83,     0,   186,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,   103,     0,   101,   140,    67,     0,    28,
      98,    96,     0,     0,    99,     0,   137,     0,     0,     0,
     284,   274,     0,   283,   189,     0,     0,     0,   171,     0,
       0,   154,     0,     0,   155,     0,   156,   157,     0,     0,
     123,   125,     0,   129,     0,     0,    93,     0,   145,   139,
     141,   121,     0,     0,   194,     0,   192,     0,     0,     0,
       0,     0,     0,   277,     0,   180,     0,   201,     0,     0,
       0,     0,   196,   122,    29,    94,     0,     0,     0,   138,
     144,   142,     0,     0,     0,     0,   134,   151,     0,     0,
       0,     0,   276,   191,     0,    68,     0,     0,   153,   124,
     102,     0,     0,    69,     0,   193,    92,     0,     0,     0,
       0,   263,   264,   279,   278,   179,     0,     0,     0,     0,
     195,   275,     0,     0,     0,   265,   266,     0,     0,   143,
     146,     0,     0,   262,     0,     0,     0,   268,     0,   270,
       0,   198,     0,     0,   197,   267,   269
  };

  const short
  parser::yypgoto_[] =
  {
    -443,  -443,    -2,   478,   218,  -443,   316,  -443,  -443,   -68,
    -353,  -443,   -84,   307,   -92,  -443,    83,  -443,  -443,   152,
    -443,    81,    39,   348,   -13,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,   214,  -443,  -443,
    -443,  -443,  -443,    42,  -443,  -443,  -443,  -443,  -443,   219,
    -443,  -443,  -311,  -443,   -85,  -243,  -443,   322,  -443,     1,
    -443,   108,  -443,  -443,  -110,   198,  -343,  -442,     9,  -443,
    -443,  -443,  -443,  -443,  -216,   -87,  -115,  -443,   335,   -86,
    -443,  -443,  -443,   220,  -443,   341,  -443,  -443,    -5,     6,
    -443,  -443,  -443,  -443,    31,  -443,  -443,  -443,  -443,   225,
    -443,  -114,  -443,  -443,   320,  -443,   535
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    10,   223,    40,    41,    42,   103,   215,    43,   443,
     262,   167,   265,   169,   267,   171,   172,   173,   263,   264,
     174,   444,   445,   175,   176,   177,   178,   179,   180,   181,
     182,   357,   183,   184,   185,   315,   316,   317,   410,   411,
     186,   488,   489,   490,   519,   520,   187,   188,   320,   321,
     189,   475,   190,   191,    11,    12,   124,   125,    53,    49,
     193,    13,    14,   118,   273,   225,   431,   495,   496,   477,
     478,    15,    16,    90,   196,    17,    18,   112,   113,    19,
      20,   101,   212,   213,   204,   205,   206,   550,   551,   552,
     207,   208,   331,   502,   503,   417,   209,   210,    21,    52,
      22,    23,    24,   241,   242,    25,    26
  };

  const short
  parser::yytable_[] =
  {
      39,    95,   170,    97,   224,   358,    89,    54,   434,   192,
     168,   202,   203,   201,   450,   343,   238,   240,   219,    50,
     234,   439,     1,   471,   505,   108,   166,   507,    45,     2,
     336,   120,    96,    44,     3,   524,   548,     4,    94,    27,
     576,    94,     5,   345,   237,   239,   236,     1,     6,   509,
       7,   345,    45,     8,     2,   472,   345,   115,   221,     3,
     549,   170,     4,   345,    92,   121,   170,   131,   268,   168,
     270,   271,   120,     6,   168,   525,   346,    46,     8,    47,
      48,   109,   110,   337,   351,   256,   170,   482,   368,   371,
     261,   369,   555,   192,   168,   116,   454,   222,   440,    50,
     214,    46,   117,    47,    48,   126,   121,   345,   120,    93,
     166,   127,   420,   332,   328,   132,   424,   202,   203,   201,
      94,   231,    94,    94,   506,   329,   238,   240,    51,   473,
     247,   344,   -31,   581,   510,   194,   485,   195,   584,     9,
     467,   257,   121,   235,   282,   252,   132,   122,   133,   134,
     135,   136,   137,   138,   237,   239,   236,     1,   170,   140,
      98,   539,   197,   170,   291,   -31,   168,   170,   -31,   486,
     457,   168,     4,   100,   485,   168,    46,   152,    47,    48,
     318,   319,   360,   198,   531,   158,    94,   363,     8,   422,
     345,   366,   147,   399,   160,   330,   345,   333,   323,   324,
     345,   -31,   102,   -31,   561,   107,   150,   515,   152,   -31,
     111,   155,   400,   401,   568,   114,   158,   532,   119,   162,
     163,   218,   159,   547,   574,   160,    94,   123,   578,   557,
       1,     1,    55,   567,    91,   197,   128,   432,     2,   129,
     199,   130,   354,     3,   161,     4,     4,   569,   570,   361,
     162,   163,   164,   200,   105,   106,   198,     6,   211,   217,
     216,     8,     8,   279,   280,   281,   282,   220,   139,   226,
     170,   227,   228,   372,   229,   170,   230,   170,   168,   142,
      28,   232,   233,   168,   243,   168,   291,   244,   245,    29,
      30,   246,   249,   145,   248,    31,   250,   255,    32,   449,
     253,   261,   254,   314,   258,   259,   414,   260,   274,    33,
     322,   325,   335,   199,   148,   149,   170,   312,   423,   341,
      34,   338,   153,    35,   168,   347,   326,   352,   157,   348,
     355,   350,    36,    37,   426,   356,   170,    38,     6,   359,
     455,   170,   362,   -28,   168,   170,   364,   170,   170,   168,
     170,   367,   291,   168,   409,   168,   168,   408,   168,   413,
     464,   301,   302,   303,   416,   468,   418,   304,   305,   479,
      28,   481,   449,   170,   419,   428,   421,   435,   430,    29,
      30,   168,   340,   433,   437,    31,   398,   436,   438,   528,
     441,   442,   452,   170,   446,   170,   456,   504,   448,    33,
     537,   168,   458,   168,   453,    28,   460,   462,   465,   461,
      34,   463,   487,    35,    29,    30,   459,   466,   469,   517,
      31,   497,   170,    32,   470,   480,   556,    38,   483,   498,
     168,   170,   499,   500,    33,   491,   301,   302,   303,   168,
     501,   275,   304,   305,   511,    34,   449,   513,    35,   514,
     518,   494,   523,   529,   530,   544,   533,    36,    37,   524,
     536,   534,    38,   538,   494,   512,   266,   494,   269,   -30,
     540,   272,   276,   541,   277,   278,   279,   280,   281,   282,
     542,   560,   562,   563,   526,   527,   564,   549,   283,   284,
     548,   571,   285,   286,   287,   288,   289,   572,   290,   291,
     292,   293,   -30,   573,   575,   -30,   580,   582,   522,   583,
     104,   585,   546,   294,   295,   296,   297,   298,   299,   474,
     586,   451,   494,   484,   516,   339,   313,   334,   558,   559,
     412,   521,   494,   545,   300,   301,   302,   303,   -30,   415,
     -30,   304,   305,   429,   476,   327,   -30,   566,   306,   307,
     308,   309,   310,   311,   349,   425,   342,   565,   577,   579,
      99,   353,   554,     0,     0,   365,     0,     0,     0,     0,
       0,     0,     0,   494,     0,     0,     0,     0,   494,     0,
       0,     0,     0,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,     0,   402,   403,   404,   405,   406,   407,   132,
       0,   133,   134,   135,   136,   137,   138,     0,   139,     0,
       0,     0,   140,     0,     0,     0,     0,   141,     0,   142,
       0,     0,     0,     0,     0,   143,     0,     0,     0,     0,
     144,     0,     0,   145,     0,   146,     0,     0,     0,     0,
       0,     0,     6,     0,     0,   147,     0,   277,   278,   279,
     280,   281,   282,     0,   148,   149,     0,     0,     0,   150,
     151,   152,   153,   154,   155,   285,     0,   156,   157,   158,
       0,     0,   291,   292,   293,   159,     0,     0,   160,     0,
       0,     0,     0,     0,    28,   277,   278,   279,   280,   281,
     282,    28,     0,    29,    30,     0,     0,   161,     0,    31,
      29,    30,    32,   162,   163,   164,    31,     0,     0,    32,
     291,    94,     0,    33,   165,     0,     0,     0,     0,     0,
      33,     0,     0,     0,    34,   251,     0,    35,     0,    56,
       0,    34,     0,     0,    35,     0,    36,    37,     0,   492,
       0,    38,     0,    36,    37,     0,     0,     0,    38,     0,
       0,     0,     0,    57,     0,    58,    59,   508,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     0,    79,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,    88,   132,    28,   133,   134,   135,
     136,   137,   138,     0,     0,    29,    30,     0,   140,   543,
       0,    31,     0,     0,    32,     0,     0,   553,     0,     0,
       0,     0,     0,    28,     0,    33,     0,     0,     0,     0,
       0,     0,    29,    30,     0,     0,    34,     0,    31,    35,
       0,   147,   277,   278,   279,   280,   281,   282,    36,    37,
       0,     0,    33,    38,     0,   150,     0,   152,     0,     0,
     155,     0,     0,    34,     0,   158,    35,   291,   292,   293,
       0,   159,   275,     0,   160,    36,    37,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,   162,
     163,   164,     0,   276,     0,   277,   278,   279,   280,   281,
     282,   275,     0,     0,     0,     0,     0,     0,     0,   283,
     284,     0,     0,   285,   286,   287,   288,   289,     0,   290,
     291,   292,   293,     0,     0,     0,     0,   370,     0,     0,
       0,     0,   276,     0,   277,   278,   279,   280,   281,   282,
     275,     0,     0,     0,     0,     0,     0,     0,   283,   284,
       0,     0,   285,   286,   287,   288,   289,     0,   290,   291,
     292,   293,     0,     0,     0,     0,   427,     0,     0,     0,
       0,   276,     0,   277,   278,   279,   280,   281,   282,   275,
       0,     0,     0,     0,     0,     0,     0,   283,   284,     0,
       0,   285,   286,   287,   288,   289,     0,   290,   291,   292,
     293,     0,     0,     0,     0,   447,     0,     0,     0,     0,
     276,     0,   277,   278,   279,   280,   281,   282,     0,     0,
       0,     0,     0,     0,     0,     0,   283,   284,     0,     0,
     285,   286,   287,   288,   289,     0,   290,   291,   292,   293,
      28,     0,     0,     0,   535,     0,     0,     0,     0,    29,
      30,     0,     0,     0,     0,    31,     0,   276,    32,   277,
     278,   279,   280,   281,   282,   275,     0,     0,     0,    33,
       0,     0,     0,   283,   284,     0,     0,   285,     0,     0,
      34,     0,     0,    35,   291,   292,   293,     0,     0,     0,
       0,     0,    36,    37,     0,     0,   276,    38,   277,   278,
     279,   280,   281,   282,   493,     0,   294,   295,   296,   297,
     298,   299,   283,   284,     0,     0,   285,   286,   287,   288,
     289,     0,   290,   291,   292,   293,     0,     0,   301,   302,
     303,     0,     0,     0,   304,   305,     0,     0,     0,     0,
       0,   306,   307,   308,   309,   310,   311,   276,     0,   277,
     278,   279,   280,   281,   282,     0,     0,     0,     0,     0,
       0,     0,     0,   283,   284,     0,     0,   285,   286,     0,
     288,   289,     0,   290,   291,   292,   293,   276,     0,   277,
     278,   279,   280,   281,   282,     0,     0,     0,     0,     0,
       0,     0,     0,   283,   284,     0,     0,   285,     0,     0,
     288,   289,     0,   290,   291,   292,   293,   276,     0,   277,
     278,   279,   280,   281,   282,     0,     0,     0,     0,     0,
       0,     0,     0,   283,   284,     0,     0,   285,     0,     0,
     288,     0,     0,   290,   291,   292,   293,   276,     0,   277,
     278,   279,   280,   281,   282,     0,     0,     0,     0,     0,
       0,     0,     0,   283,   284,     0,     0,   285,     0,     0,
     288,     0,     0,     0,   291,   292,   293
  };

  const short
  parser::yycheck_[] =
  {
       2,    14,    94,    16,   114,   248,     8,     6,   351,    94,
      94,    98,    98,    98,   367,     3,   131,   131,   110,     3,
     130,    41,    20,     3,   466,    70,    94,   469,     3,    27,
      77,    79,   106,   115,    32,    77,    36,    35,   115,     3,
     117,   115,    40,    77,   131,   131,   131,    20,    46,    24,
      48,    77,     3,    51,    27,    35,    77,    24,    77,    32,
      60,   153,    35,    77,     0,   113,   158,   115,   160,   153,
     162,   163,    79,    46,   158,   117,   110,    52,    51,    54,
      55,   126,   127,   130,   110,   153,   178,   440,    74,   110,
     158,    77,   534,   178,   178,    62,   110,   116,   118,     3,
     102,    52,    69,    54,    55,   112,   113,    77,    79,   118,
     178,   118,   328,   106,   106,     3,   332,   204,   204,   204,
     115,   123,   115,   115,   467,   117,   241,   241,   112,   109,
     143,   119,    41,   575,   109,    26,    77,    28,   580,   137,
     110,   154,   113,   116,    83,   147,     3,   118,     5,     6,
       7,     8,     9,    10,   241,   241,   241,    20,   250,    16,
     115,   514,    25,   255,   103,    74,   250,   259,    77,   110,
     413,   255,    35,    42,    77,   259,    52,    65,    54,    55,
      17,    18,   250,    46,    77,    73,   115,   255,    51,   118,
      77,   259,    49,   303,    82,   208,    77,   210,   197,   198,
      77,   110,   129,   112,   547,    11,    63,   110,    65,   118,
       3,    68,   304,   305,   557,   109,    73,   110,     3,   107,
     108,   109,    79,   110,   567,    82,   115,    46,   117,   110,
      20,    20,     7,   110,     9,    25,    74,   347,    27,   110,
     103,   109,   244,    32,   101,    35,    35,   558,   559,   251,
     107,   108,   109,   116,    36,    37,    46,    46,     3,   126,
       3,    51,    51,    80,    81,    82,    83,   106,    12,    24,
     362,     3,   118,   275,     3,   367,     3,   369,   362,    23,
       4,    77,     3,   367,   118,   369,   103,    75,   109,    13,
      14,   118,     3,    37,   109,    19,   109,   109,    22,   367,
     118,   369,   118,    31,   109,   109,   319,   118,   118,    33,
     118,     3,    77,   103,    58,    59,   408,   116,   331,     7,
      44,   118,    66,    47,   408,   109,   116,   116,    72,     3,
       3,   118,    56,    57,   336,    71,   428,    61,    46,   118,
     408,   433,   109,   112,   428,   437,   118,   439,   440,   433,
     442,   112,   103,   437,    30,   439,   440,   109,   442,   109,
     428,   107,   108,   109,    24,   433,    53,   113,   114,   437,
       4,   439,   440,   465,   109,   106,   136,    76,    50,    13,
      14,   465,   128,   106,   109,    19,   110,    77,   110,   499,
     110,   109,   111,   485,   110,   487,   409,   465,   110,    33,
     510,   485,     3,   487,   114,     4,   110,   109,   109,   118,
      44,   118,    15,    47,    13,    14,   418,   114,   114,   487,
      19,   110,   514,    22,   109,   438,   536,    61,   441,   110,
     514,   523,   109,     3,    33,   448,   107,   108,   109,   523,
       3,    45,   113,   114,   110,    44,   514,   110,    47,   118,
      26,   453,   109,   115,   112,   523,   110,    56,    57,    77,
     109,   114,    61,   118,   466,   478,   159,   469,   161,    41,
     118,   164,    76,   112,    78,    79,    80,    81,    82,    83,
     112,   110,   109,   109,   497,   498,   116,    60,    92,    93,
      36,   110,    96,    97,    98,    99,   100,   110,   102,   103,
     104,   105,    74,   118,   114,    77,   114,     3,   112,     3,
      32,   118,   525,    85,    86,    87,    88,    89,    90,   436,
     118,   369,   524,   442,   485,   218,   178,   211,   541,   542,
     316,   489,   534,   524,   106,   107,   108,   109,   110,   320,
     112,   113,   114,   345,   436,   204,   118,   552,   120,   121,
     122,   123,   124,   125,   232,   335,   221,   551,   571,   572,
      25,   241,   531,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   575,    -1,    -1,    -1,    -1,   580,    -1,
      -1,    -1,    -1,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,    -1,    -1,
      -1,    -1,    -1,   306,   307,   308,   309,   310,   311,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    21,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    -1,    78,    79,    80,
      81,    82,    83,    -1,    58,    59,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    96,    -1,    71,    72,    73,
      -1,    -1,   103,   104,   105,    79,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,     4,    78,    79,    80,    81,    82,
      83,     4,    -1,    13,    14,    -1,    -1,   101,    -1,    19,
      13,    14,    22,   107,   108,   109,    19,    -1,    -1,    22,
     103,   115,    -1,    33,   118,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    44,    38,    -1,    47,    -1,    49,
      -1,    44,    -1,    -1,    47,    -1,    56,    57,    -1,   452,
      -1,    61,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    73,    -1,    75,    76,   470,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    99,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,   114,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    14,    -1,    16,   522,
      -1,    19,    -1,    -1,    22,    -1,    -1,   530,    -1,    -1,
      -1,    -1,    -1,     4,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    44,    -1,    19,    47,
      -1,    49,    78,    79,    80,    81,    82,    83,    56,    57,
      -1,    -1,    33,    61,    -1,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    44,    -1,    73,    47,   103,   104,   105,
      -1,    79,    45,    -1,    82,    56,    57,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      80,    81,    82,    83,    68,    -1,    85,    86,    87,    88,
      89,    90,    92,    93,    -1,    -1,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,    -1,    -1,   107,   108,
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
      99,    -1,    -1,   102,   103,   104,   105,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    -1,    -1,
      99,    -1,    -1,    -1,   103,   104,   105
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    20,    27,    32,    35,    40,    46,    48,    51,   137,
     139,   192,   193,   199,   200,   209,   210,   213,   214,   217,
     218,   236,   238,   239,   240,   243,   244,     3,     4,    13,
      14,    19,    22,    33,    44,    47,    56,    57,    61,   140,
     141,   142,   143,   146,   115,     3,    52,    54,    55,   197,
       3,   112,   237,   196,   197,   237,    49,    73,    75,    76,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    99,
     102,   103,   104,   105,   106,   107,   108,   109,   114,   140,
     211,   237,     0,   118,   115,   162,   106,   162,   115,   244,
      42,   219,   129,   144,   141,   142,   142,    11,    70,   126,
     127,     3,   215,   216,   109,    24,    62,    69,   201,     3,
      79,   113,   118,    46,   194,   195,   112,   118,    74,   110,
     109,   115,     3,     5,     6,     7,     8,     9,    10,    12,
      16,    21,    23,    29,    34,    37,    39,    49,    58,    59,
      63,    64,    65,    66,    67,    68,    71,    72,    73,    79,
      82,   101,   107,   108,   109,   118,   147,   149,   150,   151,
     152,   153,   154,   155,   158,   161,   162,   163,   164,   165,
     166,   167,   168,   170,   171,   172,   178,   184,   185,   188,
     190,   191,   192,   198,    26,    28,   212,    25,    46,   103,
     116,   192,   213,   217,   222,   223,   224,   228,   229,   234,
     235,     3,   220,   221,   140,   145,     3,   126,   109,   152,
     106,    77,   116,   140,   202,   203,    24,     3,   118,     3,
       3,   140,    77,     3,   202,   116,   192,   213,   214,   217,
     239,   241,   242,   118,    75,   109,   118,   162,   109,     3,
     109,    38,   140,   118,   118,   109,   147,   162,   109,   109,
     118,   147,   148,   156,   157,   150,   151,   152,   152,   151,
     152,   152,   151,   202,   118,    45,    76,    78,    79,    80,
      81,    82,    83,    92,    93,    96,    97,    98,    99,   100,
     102,   103,   104,   105,    85,    86,    87,    88,    89,    90,
     106,   107,   108,   109,   113,   114,   120,   121,   122,   123,
     124,   125,   116,   161,    31,   173,   174,   175,    17,    18,
     186,   187,   118,   197,   197,     3,   116,   223,   106,   117,
     162,   230,   106,   162,   144,    77,    77,   130,   118,   151,
     128,     7,   216,     3,   119,    77,   110,   109,     3,   195,
     118,   110,   116,   242,   140,     3,    71,   169,   193,   118,
     147,   140,   109,   147,   118,   151,   147,   112,    74,    77,
     110,   110,   140,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   110,   202,
     152,   152,   151,   151,   151,   151,   151,   151,   109,    30,
     176,   177,   175,   109,   162,   187,    24,   233,    53,   109,
     212,   136,   118,   162,   212,   221,   140,   110,   106,   203,
      50,   204,   202,   106,   204,    76,    77,   109,   110,    41,
     118,   110,   109,   147,   159,   160,   110,   110,   110,   147,
     148,   157,   111,   114,   110,   147,   162,   193,     3,   140,
     110,   118,   109,   118,   147,   109,   114,   110,   147,   114,
     109,     3,    35,   109,   154,   189,   199,   207,   208,   147,
     162,   147,   148,   162,   159,    77,   110,    15,   179,   180,
     181,   162,   151,    68,   140,   205,   206,   110,   110,   109,
       3,     3,   231,   232,   147,   205,   204,   205,   151,    24,
     109,   110,   162,   110,   118,   110,   160,   147,    26,   182,
     183,   181,   112,   109,    77,   117,   162,   162,   202,   115,
     112,    77,   110,   110,   114,   110,   109,   202,   118,   148,
     118,   112,   112,   151,   147,   206,   162,   110,    36,    60,
     225,   226,   227,   151,   232,   205,   202,   110,   162,   162,
     110,   204,   109,   109,   116,   227,   226,   110,   204,   190,
     190,   110,   110,   118,   204,   114,   117,   162,   117,   162,
     114,   205,     3,     3,   205,   118,   118
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
     233,   233,   234,   234,   235,   236,   236,   237,   237,   237,
     238,   238,   239,   240,   240,   241,   241,   242,   242,   242,
     242,   242,   243,   243,   244,   244,   244,   244,   244,   244,
     244,   244
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
       1,     0,     2,     4,     4,     3,     5,     1,     3,     3,
       3,     4,     5,     5,     4,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1
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
     507,   508,   511,   512,   514,   521,   522,   525,   526,   527,
     530,   531,   534,   537,   538,   541,   542,   545,   546,   547,
     548,   549,   554,   555,   558,   559,   560,   561,   562,   563,
     564,   565
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
#line 1778 "Parser/Arbor_parser.tab.cc"

#line 567 "parser.yy"
