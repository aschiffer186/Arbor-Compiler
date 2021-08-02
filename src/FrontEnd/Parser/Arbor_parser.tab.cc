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
#line 136 "Parser/Arbor_parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false)
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
      case symbol_kind::S_NPTR: // NPTR
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
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
      case symbol_kind::S_NPTR: // NPTR
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
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
      case symbol_kind::S_NPTR: // NPTR
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
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
      case symbol_kind::S_NPTR: // NPTR
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.move< char > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
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
            symbol_type yylookahead (yylex ());
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
      case symbol_kind::S_NPTR: // NPTR
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_CHAR: // CHAR
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
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

#line 653 "Parser/Arbor_parser.tab.cc"

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
  "BOOL", "NPTR", "INT", "FLOAT", "CHAR", "STRING", "break", "bit", "bool",
  "case", "castas", "catch", "catch-all", "char", "cleanup", "const",
  "continue", "compeval", "default", "delete", "do", "else", "else-if",
  "enum", "float", "for", "func", "goto", "heap", "if", "in", "int", "is",
  "let", "long", "new", "nothrowable", "operator", "ref", "rref",
  "rethrow", "return", "short", "static", "super", "switch", "this",
  "throw", "try", "typeof", "virtual", "while", "yield", "[", "]", "<",
  ">", ",", "+", "-", "/", "//", "*", "^^", "%", "+=", "-=", "*=", "/=",
  "//=", "^^=", "%=", "<=", ">=", "==", "!=", "<=>", "&&", "||", "&", "|",
  "!", "^", "~", ">>", "<<", "=", "++", "--", "(", ")", "?", ":", ".",
  "->", "{", "}", "=>", ";", "...", "&=", "^=", "|=", "~=", "<<=", ">>=",
  "POINTER_TYPE", "ARRAYL", "ARRAYR", "UMINUS", "POSTINC", "POSTDEC",
  "TERN", "DEREF", "$accept", "start", "type", "type_root",
  "non_reference_type", "type_core", "type_template_paramaters",
  "type_list", "reference_type", "expression", "expression0",
  "assignment_arg_expression", "prvalue_expression", "rvalue_expression",
  "xvalue_expression", "literal", "lambda_expression", "new_expression",
  "array_index_list", "array_index", "function_call", "function_call_list",
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
  "variable_declaration_block", "no_op_statement", "function",
  "function_header", "function_modifiers", "function_argument_list",
  "function_argument", "throwable_expression", "return_types_list",
  "return_type", "anonymous_function", "anonymous_function_header",
  "operator_overload", "operator_overload_header", "operator",
  "function_options", "callable", "callables", "enum", "enum_members_list",
  "enum_member", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -344;

  const signed char parser::yytable_ninf_ = -31;

  const short
  parser::yypact_[] =
  {
      38,   -88,    82,   546,    20,  -344,   -60,  -344,   -74,  -344,
      55,  -344,    62,   -17,  -344,    72,  -344,    81,    15,  -344,
    -344,  -344,   657,  -344,  -344,  -344,  -344,   252,   252,  -344,
      53,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,
      19,  -344,  -344,  -344,  -344,   -12,  -344,    33,  -344,   484,
    -344,   108,  -344,  -344,    43,   -40,  -344,   935,  -344,    44,
      46,  -344,  -344,  -344,  -344,  -344,  -344,  -344,   135,   935,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,    61,    84,    79,
      73,   -60,    85,   177,    88,   145,   902,    87,    90,  -344,
      94,  -344,   138,   -60,    97,   101,    98,   138,   138,   156,
     138,   156,   156,    24,  -344,   100,  -344,    74,   808,   617,
    -344,  -344,  -344,  -344,  -344,  -344,    83,   484,  -344,  -344,
    -344,  -344,  -344,  -344,   181,  -344,  -344,   146,  -344,  -344,
    -344,  -344,   107,  -344,  -344,  -344,   112,   190,    62,  -344,
       7,   -49,  -344,   935,   935,    91,   -48,  -344,   122,   215,
    -344,   165,   184,   123,   138,   935,   163,  -344,   935,   133,
    -344,  -344,   138,   125,  -344,   138,   138,  -344,   132,   142,
     -21,  -344,  -344,   153,   895,   138,    58,   153,    58,    58,
     676,   -47,  -344,   935,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,  -344,
    -344,   638,   156,   156,   138,   138,   138,   138,   138,   138,
    -344,  -344,   149,   218,   181,  -344,   152,   -60,   146,  -344,
    -344,  -344,  -344,  -344,   160,  -344,   935,   206,   -46,  -344,
     -37,  -344,   206,   935,   192,   158,   162,   -24,  -344,   167,
     260,   145,   161,   138,   171,  -344,   709,   173,   138,  -344,
     138,   742,   176,   183,  -344,  1071,   170,   170,   -45,   -45,
     -45,   -45,  1071,  1071,  1099,   975,   945,  1065,  1005,  1035,
     153,   240,   240,   808,   808,   808,   808,   808,   808,   808,
    -344,     0,  -344,  -344,   808,   808,   808,   808,   808,   808,
     138,   -60,  -344,  -344,  -344,   184,  -344,  -344,   138,  -344,
     175,   186,   206,   935,  -344,   187,   180,     4,   138,   -60,
     138,   138,   -60,   185,  -344,   138,  -344,    25,  -344,   269,
    -344,   -60,  -344,  -344,  -344,  -344,   138,   890,  -344,   194,
    -344,   198,  -344,   138,   890,   195,  -344,   890,   193,  -344,
      80,   935,  -344,   200,  -344,  -344,   -60,   202,  -344,  -344,
     197,  -344,   138,    27,   138,  -344,   138,   275,   269,  -344,
    -344,   322,   207,  -344,   -43,  -344,   -60,   -60,   214,   248,
     890,   248,   138,   217,   935,   209,  -344,  -344,   138,  -344,
    -344,   210,   221,   223,  -344,  -344,  -344,   138,   138,   890,
     -60,  -344,  -344,  -344,   248,   775,   935,    28,  -344,  -344,
    -344,   -60,   -60,   808,   219,  -344,  -344,  -344,    31,   206,
     188,   188,  -344,   206,   225,  -344,  -344,   227,   890,   890,
     248,   248
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,   232,     0,   233,     0,   234,
       2,     3,     0,     0,   176,   177,   175,     0,    12,    13,
      14,    19,     0,    18,    16,    17,   228,     0,     0,    15,
       0,   212,   210,   196,   197,   199,   200,   198,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   213,   211,   215,
     216,   214,   218,   217,   219,   221,   220,   222,   223,   224,
       0,   227,   229,     5,     6,     8,     7,     0,     1,   114,
     172,     0,   193,   235,   239,     0,   237,     0,   178,     0,
       0,    11,     4,    23,    24,   225,   226,     9,     0,     0,
      73,    85,    86,    87,    88,    90,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,    74,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     0,     0,     0,   171,     0,    25,    71,     0,    72,
      31,    70,    69,    84,   115,   103,     0,   113,   104,   117,
     118,   119,   105,   125,   130,   126,   106,     0,   107,   108,
     109,   110,     0,   111,   231,   230,     0,     0,     0,   236,
       0,     0,   179,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,     0,     0,     0,   166,   167,     0,     0,
     160,   157,     0,     0,   147,     0,     0,   162,    96,     0,
       0,    94,    71,    65,    72,     0,    79,    64,    75,    76,
       0,     0,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   116,     0,   135,   129,   131,     0,     0,   146,   148,
     165,   194,   240,   238,   181,   182,     0,     0,     0,    21,
       0,    10,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,     0,     0,     0,   161,     0,     0,    28,    83,
      28,     0,    82,     0,    63,    45,    33,    34,    36,    37,
      35,    38,    47,    46,    48,    49,    50,    51,    53,    52,
      54,    55,    56,    39,    40,    41,    42,    43,    44,    26,
      99,     0,    80,    81,    57,    58,    59,    60,    62,    61,
       0,     0,   127,   134,   132,     0,   151,   149,     0,   180,
     184,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,    28,     0,   169,   168,     0,   102,     0,   100,   139,
      66,     0,    27,    97,    95,    82,     0,     0,    98,     0,
     136,     0,   183,     0,     0,     0,    22,     0,     0,   153,
       0,     0,   154,     0,   155,   156,     0,     0,   122,   124,
       0,   128,     0,     0,     0,    92,     0,   144,   138,   140,
     120,     0,     0,   188,     0,   186,     0,     0,     0,   174,
       0,   195,     0,   176,     0,     0,   190,   121,    28,   170,
      93,     0,     0,     0,   137,   143,   141,     0,     0,     0,
       0,   133,   150,   185,   173,     0,     0,     0,   152,   123,
     101,     0,     0,    68,     0,   187,    91,    67,     0,     0,
       0,     0,   189,     0,     0,   142,   145,     0,     0,     0,
     192,   191
  };

  const short
  parser::yypgoto_[] =
  {
    -344,  -344,    -3,   300,   127,  -344,  -344,  -344,  -344,    12,
    -269,  -344,   -61,   247,   -67,  -344,   -10,  -344,  -344,    49,
    -344,   -14,   -42,   199,    -5,  -344,  -344,  -344,  -344,  -344,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,    95,  -344,  -344,
    -344,  -344,  -344,   -53,  -344,  -344,  -344,  -344,  -344,    96,
    -344,  -344,  -273,  -344,  -344,  -167,  -344,    67,  -344,     6,
    -344,  -344,   -71,    89,  -258,  -343,   -70,  -344,  -344,  -344,
    -344,  -344,  -344,   338,  -344,  -344,  -344,   204
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     4,   160,    63,    64,    65,    81,   260,    66,   346,
     189,   126,   192,   128,   194,   130,   131,   132,   190,   191,
     133,   347,   348,   134,   135,   136,   137,   138,   139,   140,
     141,   266,   142,   143,   144,   243,   244,   245,   322,   323,
     145,   387,   388,   389,   414,   415,   146,   147,   248,   249,
     148,   373,   149,   150,   151,   152,   176,   177,   153,     5,
       6,    17,   201,   162,   331,   394,   395,   375,   376,     7,
       8,    67,   156,     9,    10,    11,    75,    76
  };

  const short
  parser::yytable_[] =
  {
      62,    70,   129,    72,   335,   267,   161,   369,   127,   353,
     254,   340,    12,   256,   256,   256,   256,    71,   166,   419,
      68,   399,   158,   210,   401,   333,    69,    90,    18,    91,
      92,    93,    94,    95,    96,   370,    19,    20,   279,    98,
      69,   280,    21,   219,    22,   129,   257,   262,   283,   332,
     129,   127,   196,    23,   198,   199,   127,   424,   334,   420,
      24,   159,   256,    25,   106,    74,     1,    27,    28,     2,
     129,    29,   380,   109,   365,   111,   127,    77,   114,   341,
       3,   125,   117,    13,    79,    13,     2,   384,   118,   384,
     256,   119,   258,   256,    78,   358,   171,     3,   371,    87,
      88,    80,   403,   179,    14,   450,   451,   129,   184,   -30,
     120,   255,    85,   127,    86,   129,   121,   122,   123,   129,
     385,   127,   410,   439,   183,   127,   443,    89,    15,   188,
      15,   154,   155,   -30,   157,    16,   -30,    16,   163,   429,
     164,    90,   165,    91,    92,    93,    94,    95,    96,   125,
     229,   230,   231,    98,    83,    84,   232,   233,   361,    90,
     311,   259,   246,   247,   167,   312,   313,   445,   446,   -30,
     168,   -30,   270,   169,   404,   272,   170,   -30,   106,   172,
     173,   444,   174,   175,   240,   447,   269,   109,   182,   111,
     180,   185,   114,   181,   274,   186,   117,   252,   277,    97,
     284,   187,   118,   202,   261,   119,   129,   111,   242,   100,
     250,   129,   127,   129,   117,   251,   263,   127,   264,   127,
     103,   265,   105,   119,   120,   271,   268,   273,   275,   -27,
     121,   122,   123,   107,   108,   207,   208,   209,   210,   278,
     112,   219,   326,   320,   321,   116,   325,   330,   121,   122,
     195,   328,   338,   129,   337,   345,    18,   339,   219,   127,
     336,   129,   342,   343,    19,    20,   349,   127,   351,   363,
      21,   129,   356,   129,   129,   368,   382,   127,   129,   127,
     127,    23,   357,   386,   127,   364,   367,   402,    24,   396,
     352,    25,   188,   397,   400,   405,   129,   407,   413,    29,
     408,   418,   127,   205,   206,   207,   208,   209,   210,   423,
     419,   426,   428,   430,   442,   129,   360,   129,   431,   129,
     432,   127,    82,   127,   448,   127,   449,   372,   219,   354,
     366,   383,   359,   427,   378,   416,   241,   381,   344,   324,
     362,   129,   411,   374,   327,   329,   390,   127,    73,   435,
     377,   129,   379,   352,   393,   438,     0,   127,     0,   203,
       0,   393,   253,     0,   393,   193,     0,   197,     0,     0,
     200,   406,     0,     0,     0,   398,     0,     0,     0,     0,
       0,     0,     0,   204,     0,   205,   206,   207,   208,   209,
     210,   421,   422,     0,   409,     0,     0,   393,   412,   211,
     212,     0,     0,   213,   214,   215,   216,   217,     0,   218,
     219,   220,   221,     0,     0,   436,   393,     0,     0,   417,
     352,     0,     0,     0,     0,     0,   440,   441,     0,     0,
     434,     0,   276,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,     0,   393,   393,     0,     0,     0,
       0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,     0,     0,     0,     0,
       0,   314,   315,   316,   317,   318,   319,    90,     0,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,    98,
       0,     0,     0,    99,     0,   100,     0,     0,     0,   101,
       0,     0,     0,     0,   102,     0,   103,     0,   104,     0,
       0,     0,   105,     0,   106,     0,     0,     0,     0,   107,
     108,     0,     0,   109,   110,   111,   112,   113,   114,     0,
     115,   116,   117,     0,     0,     0,     0,     0,   118,     0,
      18,   119,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     0,     0,     0,    21,     0,    22,     0,     0,     0,
     120,     0,     0,     0,     0,    23,   121,   122,   123,     0,
       0,     0,    24,     0,    69,    25,    26,   124,     0,    27,
      28,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   391,    30,     0,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     0,     0,
      52,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,     0,    18,     0,     0,    61,     0,     0,     0,   425,
      19,    20,   -29,     0,     0,     0,    21,     0,    22,     0,
       0,    18,     0,     0,   433,     0,     0,    23,     0,    19,
      20,     0,     0,     0,    24,    21,   -29,    25,     0,   -29,
       0,    27,    28,     0,     0,    29,    23,   222,   223,   224,
     225,   226,   227,    24,     0,     0,    25,     0,     0,     0,
      27,    28,     0,     0,    29,     0,     0,     0,   228,   229,
     230,   231,   -29,   203,   -29,   232,   233,     0,     0,     0,
     -29,     0,   234,   235,   236,   237,   238,   239,     0,     0,
       0,     0,     0,   310,     0,     0,     0,   204,     0,   205,
     206,   207,   208,   209,   210,     0,   203,     0,     0,     0,
       0,     0,     0,   211,   212,     0,     0,   213,   214,   215,
     216,   217,     0,   218,   219,   220,   221,     0,     0,     0,
     204,   282,   205,   206,   207,   208,   209,   210,     0,   203,
       0,     0,     0,     0,     0,     0,   211,   212,     0,     0,
     213,   214,   215,   216,   217,     0,   218,   219,   220,   221,
       0,     0,     0,   204,   350,   205,   206,   207,   208,   209,
     210,     0,   203,     0,     0,     0,     0,     0,     0,   211,
     212,     0,     0,   213,   214,   215,   216,   217,     0,   218,
     219,   220,   221,     0,     0,     0,   204,   355,   205,   206,
     207,   208,   209,   210,     0,   203,     0,     0,     0,     0,
       0,     0,   211,   212,     0,     0,   213,   214,   215,   216,
     217,     0,   218,   219,   220,   221,     0,     0,     0,   204,
     437,   205,   206,   207,   208,   209,   210,     0,     0,     0,
       0,     0,     0,     0,     0,   211,   212,     0,     0,   213,
     214,   215,   216,   217,    18,   218,   219,   220,   221,     0,
       0,     0,    19,    20,     0,     0,    18,     0,    21,     0,
      22,     0,     0,     0,    19,    20,     0,     0,     0,    23,
      21,     0,    22,     0,     0,     0,    24,     0,     0,    25,
       0,    23,     0,    27,    28,   178,     0,    29,    24,    18,
       0,    25,     0,     0,   392,    27,    28,    19,    20,    29,
       0,     0,     0,    21,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,    23,   222,   223,   224,   225,   226,
     227,    24,     0,     0,    25,     0,     0,     0,    27,    28,
       0,     0,    29,     0,     0,     0,     0,   229,   230,   231,
       0,     0,     0,   232,   233,     0,     0,     0,     0,     0,
     234,   235,   236,   237,   238,   239,   204,     0,   205,   206,
     207,   208,   209,   210,     0,     0,     0,     0,     0,     0,
       0,     0,   211,   212,     0,     0,   213,   214,     0,   216,
     217,     0,   218,   219,   220,   221,   204,     0,   205,   206,
     207,   208,   209,   210,     0,     0,     0,     0,     0,     0,
       0,     0,   211,   212,     0,     0,   213,     0,     0,   216,
     217,     0,   218,   219,   220,   221,   204,     0,   205,   206,
     207,   208,   209,   210,     0,     0,     0,     0,     0,     0,
       0,     0,   211,   212,     0,     0,   213,     0,     0,   216,
       0,     0,   218,   219,   220,   221,   204,     0,   205,   206,
     207,   208,   209,   210,     0,     0,     0,     0,     0,     0,
       0,     0,   211,   212,     0,     0,   213,     0,     0,   216,
       0,     0,     0,   219,   220,   221,   204,     0,   205,   206,
     207,   208,   209,   210,   205,   206,   207,   208,   209,   210,
       0,     0,   211,   212,     0,     0,   213,     0,     0,     0,
       0,     0,   213,   219,   220,   221,     0,     0,     0,   219,
     220,   221,   205,   206,   207,   208,   209,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,   220,   221
  };

  const short
  parser::yycheck_[] =
  {
       3,     6,    69,     8,   262,   172,    77,     3,    69,   278,
       3,    35,   100,    62,    62,    62,    62,    91,    89,    62,
       0,   364,    62,    68,   367,    62,   100,     3,     4,     5,
       6,     7,     8,     9,    10,    31,    12,    13,    59,    15,
     100,    62,    18,    88,    20,   112,    95,    95,    95,    95,
     117,   112,   119,    29,   121,   122,   117,   400,    95,   102,
      36,   101,    62,    39,    40,     3,    28,    43,    44,    31,
     137,    47,   341,    49,   332,    51,   137,    94,    54,   103,
      42,    69,    58,     3,     3,     3,    31,    62,    64,    62,
      62,    67,   163,    62,    22,    95,   101,    42,    94,   111,
     112,    86,    22,   106,    22,   448,   449,   174,   113,    35,
      86,   104,    59,   174,    95,   182,    92,    93,    94,   186,
      95,   182,    95,    95,   112,   186,    95,    94,    48,   117,
      48,    23,    24,    59,    91,    55,    62,    55,    94,   408,
      94,     3,     7,     5,     6,     7,     8,     9,    10,   137,
      92,    93,    94,    15,    27,    28,    98,    99,   325,     3,
     231,   164,    16,    17,   103,   232,   233,   440,   441,    95,
      86,    97,   175,    94,    94,   178,   103,   103,    40,    94,
       3,   439,    94,    38,   101,   443,   174,    49,    94,    51,
     103,    94,    54,   103,   182,    94,    58,     7,   186,    11,
     203,   103,    64,   103,   113,    67,   273,    51,    27,    21,
     103,   278,   273,   280,    58,   103,    94,   278,     3,   280,
      32,    56,    38,    67,    86,    62,   103,    94,   103,    97,
      92,    93,    94,    45,    46,    65,    66,    67,    68,    97,
      52,    88,   247,    94,    26,    57,    94,    41,    92,    93,
      94,    91,    94,   320,    62,    94,     4,    95,    88,   320,
     263,   328,    95,     3,    12,    13,    95,   328,    95,    94,
      18,   338,    96,   340,   341,    95,    91,   338,   345,   340,
     341,    29,    99,    14,   345,    99,    99,    94,    36,    95,
     278,    39,   280,    95,    99,    95,   363,    95,    23,    47,
     103,    94,   363,    63,    64,    65,    66,    67,    68,    95,
      62,    94,   103,   103,    95,   382,   321,   384,    97,   386,
      97,   382,    22,   384,    99,   386,    99,   337,    88,   280,
     333,   345,   320,   404,   339,   388,   137,   342,   271,   244,
     328,   408,   384,   337,   248,   256,   351,   408,    10,   419,
     338,   418,   340,   341,   357,   426,    -1,   418,    -1,    37,
      -1,   364,   158,    -1,   367,   118,    -1,   120,    -1,    -1,
     123,   376,    -1,    -1,    -1,   363,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,    67,
      68,   396,   397,    -1,   382,    -1,    -1,   400,   386,    77,
      78,    -1,    -1,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    -1,    -1,   420,   419,    -1,    -1,    97,
     408,    -1,    -1,    -1,    -1,    -1,   431,   432,    -1,    -1,
     418,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,    -1,   448,   449,    -1,    -1,    -1,
      -1,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,   235,   236,   237,   238,   239,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    19,    -1,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    34,    -1,
      -1,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    -1,
       4,    67,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    29,    92,    93,    94,    -1,
      -1,    -1,    36,    -1,   100,    39,    40,   103,    -1,    43,
      44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   356,    58,    -1,    60,    61,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,     4,    -1,    -1,    99,    -1,    -1,    -1,   402,
      12,    13,    35,    -1,    -1,    -1,    18,    -1,    20,    -1,
      -1,     4,    -1,    -1,   417,    -1,    -1,    29,    -1,    12,
      13,    -1,    -1,    -1,    36,    18,    59,    39,    -1,    62,
      -1,    43,    44,    -1,    -1,    47,    29,    70,    71,    72,
      73,    74,    75,    36,    -1,    -1,    39,    -1,    -1,    -1,
      43,    44,    -1,    -1,    47,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    37,    97,    98,    99,    -1,    -1,    -1,
     103,    -1,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    61,    -1,    63,
      64,    65,    66,    67,    68,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    -1,    -1,    81,    82,    83,
      84,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      61,    95,    63,    64,    65,    66,    67,    68,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    -1,    61,    95,    63,    64,    65,    66,    67,
      68,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    -1,    -1,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    61,    95,    63,    64,
      65,    66,    67,    68,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,    61,
      95,    63,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    81,
      82,    83,    84,    85,     4,    87,    88,    89,    90,    -1,
      -1,    -1,    12,    13,    -1,    -1,     4,    -1,    18,    -1,
      20,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    29,
      18,    -1,    20,    -1,    -1,    -1,    36,    -1,    -1,    39,
      -1,    29,    -1,    43,    44,    33,    -1,    47,    36,     4,
      -1,    39,    -1,    -1,    54,    43,    44,    12,    13,    47,
      -1,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    70,    71,    72,    73,    74,
      75,    36,    -1,    -1,    39,    -1,    -1,    -1,    43,    44,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    92,    93,    94,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,   110,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    81,    82,    -1,    84,
      85,    -1,    87,    88,    89,    90,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    81,    -1,    -1,    84,
      85,    -1,    87,    88,    89,    90,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    81,    -1,    -1,    84,
      -1,    -1,    87,    88,    89,    90,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    88,    89,    90,    61,    -1,    63,    64,
      65,    66,    67,    68,    63,    64,    65,    66,    67,    68,
      -1,    -1,    77,    78,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    81,    88,    89,    90,    -1,    -1,    -1,    88,
      89,    90,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    28,    31,    42,   120,   178,   179,   188,   189,   192,
     193,   194,   100,     3,    22,    48,    55,   180,     4,    12,
      13,    18,    20,    29,    36,    39,    40,    43,    44,    47,
      58,    60,    61,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    84,    87,    88,    89,    90,    91,    92,    93,
      94,    99,   121,   122,   123,   124,   127,   190,     0,   100,
     143,    91,   143,   192,     3,   195,   196,    94,    22,     3,
      86,   125,   122,   123,   123,    59,    95,   111,   112,    94,
       3,     5,     6,     7,     8,     9,    10,    11,    15,    19,
      21,    25,    30,    32,    34,    38,    40,    45,    46,    49,
      50,    51,    52,    53,    54,    56,    57,    58,    64,    67,
      86,    92,    93,    94,   103,   128,   130,   131,   132,   133,
     134,   135,   136,   139,   142,   143,   144,   145,   146,   147,
     148,   149,   151,   152,   153,   159,   165,   166,   169,   171,
     172,   173,   174,   177,    23,    24,   191,    91,    62,   101,
     121,   181,   182,    94,    94,     7,   181,   103,    86,    94,
     103,   143,    94,     3,    94,    38,   175,   176,    33,   121,
     103,   103,    94,   128,   143,    94,    94,   103,   128,   129,
     137,   138,   131,   132,   133,    94,   133,   132,   133,   133,
     132,   181,   103,    37,    61,    63,    64,    65,    66,    67,
      68,    77,    78,    81,    82,    83,    84,    85,    87,    88,
      89,    90,    70,    71,    72,    73,    74,    75,    91,    92,
      93,    94,    98,    99,   105,   106,   107,   108,   109,   110,
     101,   142,    27,   154,   155,   156,    16,    17,   167,   168,
     103,   103,     7,   196,     3,   104,    62,    95,   181,   121,
     126,   113,    95,    94,     3,    56,   150,   174,   103,   128,
     121,    62,   121,    94,   128,   103,   132,   128,    97,    59,
      62,   132,    95,    95,   121,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
      95,   181,   133,   133,   132,   132,   132,   132,   132,   132,
      94,    26,   157,   158,   156,    94,   143,   168,    91,   182,
      41,   183,    95,    62,    95,   183,   121,    62,    94,    95,
      35,   103,    95,     3,   176,    94,   128,   140,   141,    95,
      95,    95,   128,   129,   138,    95,    96,    99,    95,   128,
     143,   174,   128,    94,    99,   183,   121,    99,    95,     3,
      31,    94,   135,   170,   178,   186,   187,   128,   143,   128,
     129,   143,    91,   140,    62,    95,    14,   160,   161,   162,
     143,   132,    54,   121,   184,   185,    95,    95,   128,   184,
      99,   184,    94,    22,    94,    95,   143,    95,   103,   128,
      95,   141,   128,    23,   163,   164,   162,    97,    94,    62,
     102,   143,   143,    95,   184,   132,    94,   181,   103,   129,
     103,    97,    97,   132,   128,   185,   143,    95,   181,    95,
     143,   143,    95,    95,   183,   171,   171,   183,    99,    99,
     184,   184
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   119,   120,   120,   121,   121,   122,   122,   123,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     125,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   134,   134,   134,   134,   134,
     134,   135,   136,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   143,   144,   144,   145,   145,   146,   146,   146,
     147,   148,   149,   150,   150,   151,   151,   152,   153,   154,
     154,   155,   155,   156,   157,   157,   158,   159,   160,   160,
     161,   161,   162,   163,   163,   164,   165,   166,   167,   167,
     168,   168,   169,   170,   170,   170,   170,   171,   171,   171,
     171,   171,   171,   171,   172,   173,   174,   175,   175,   176,
     176,   177,   178,   179,   179,   180,   180,   180,   180,   181,
     181,   182,   182,   182,   183,   183,   184,   184,   185,   185,
     186,   187,   187,   188,   188,   189,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     191,   191,   192,   192,   193,   193,   194,   195,   195,   196,
     196
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     2,     2,     1,     3,     1,     0,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     8,     7,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     7,     5,     6,     1,     3,     1,     3,     4,     3,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     1,     2,     1,     1,     1,
       5,     6,     5,     5,     3,     1,     1,     3,     5,     1,
       0,     1,     2,     5,     1,     0,     2,     6,     1,     0,
       1,     2,     5,     1,     0,     4,     2,     2,     1,     2,
       5,     2,     7,     1,     1,     1,     1,     2,     2,     2,
       2,     3,     2,     3,     2,     2,     2,     1,     3,     3,
       5,     1,     2,     9,     8,     1,     1,     1,     2,     1,
       3,     2,     2,     4,     1,     4,     1,     3,     1,     4,
       2,     8,     7,     2,     4,     8,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     3,     1,
       3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    64,    64,    64,    68,    69,    72,    72,    75,    76,
      77,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      91,    94,    95,    98,    99,   105,   106,   109,   110,   113,
     114,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   159,   160,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   177,   177,   177,   177,   177,
     177,   180,   183,   184,   187,   188,   191,   192,   195,   196,
     199,   200,   203,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   219,   222,   223,   226,   227,   230,   231,   232,
     235,   238,   241,   244,   245,   248,   249,   252,   255,   258,
     259,   262,   263,   266,   269,   270,   273,   276,   279,   280,
     283,   284,   287,   290,   291,   294,   297,   300,   303,   304,
     307,   308,   311,   314,   315,   316,   317,   320,   321,   322,
     323,   324,   325,   326,   329,   332,   335,   338,   339,   342,
     343,   345,   350,   353,   354,   357,   358,   359,   360,   363,
     364,   367,   368,   369,   372,   373,   376,   377,   380,   381,
     384,   387,   388,   391,   392,   395,   397,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   399,   399,   399,   399,   399,
     402,   402,   405,   406,   409,   410,   415,   418,   419,   422,
     423
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
#line 1692 "Parser/Arbor_parser.tab.cc"

#line 425 "parser.yy"
