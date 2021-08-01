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

#line 7 "parser.yy"
namespace Arbor { namespace FE { namespace parser {
#line 137 "Parser/Arbor_parser.tab.cc"

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

      case symbol_kind::S_NPTR: // NPTR
        value.YY_MOVE_OR_COPY< std::nullptr_t > (YY_MOVE (that.value));
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

      case symbol_kind::S_NPTR: // NPTR
        value.move< std::nullptr_t > (YY_MOVE (that.value));
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

      case symbol_kind::S_NPTR: // NPTR
        value.copy< std::nullptr_t > (that.value);
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

      case symbol_kind::S_NPTR: // NPTR
        value.move< std::nullptr_t > (that.value);
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

      case symbol_kind::S_NPTR: // NPTR
        yylhs.value.emplace< std::nullptr_t > ();
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

#line 669 "Parser/Arbor_parser.tab.cc"

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
  "BOOL", "NPTR", "INT", "FLOAT", "CHAR", "STRING", "break", "case",
  "castas", "catch", "catch-all", "cleanup", "const", "continue",
  "compeval", "default", "delete", "do", "else", "else-if", "for", "func",
  "goto", "heap", "if", "in", "is", "let", "new", "nothrowable",
  "operator", "ref", "rref", "rethrow", "return", "static", "super",
  "switch", "this", "throw", "try", "typeof", "virtual", "while", "yield",
  "[", "]", "<", ">", ",", "+", "-", "/", "//", "*", "^^", "%", "+=", "-=",
  "*=", "/=", "//=", "^^=", "%=", "<=", ">=", "==", "!=", "<=>", "&&",
  "||", "&", "|", "!", "^", "~", ">>", "<<", "=", "++", "--", "(", ")",
  "?", ":", ".", "->", "{", "}", "=>", ";", "...", "&=", "^=", "|=", "~=",
  "<<=", ">>=", "POINTER_TYPE", "ARRAYL", "ARRAYR", "UMINUS", "POSTINC",
  "POSTDEC", "TERN", "DEREF", "FUNC_CALL", "$accept", "start", "type",
  "type_root", "non_reference_type", "type_core",
  "type_template_paramaters", "type_list", "reference_type", "expression",
  "expression0", "assignment_arg_expression", "prvalue_expression",
  "rvalue_expression", "xvalue_expression", "literal",
  "variable_declaration", "variable_declaration_block_list",
  "variable_declaration_block", "lambda_expression", "new_expression",
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
  "no_op_statement", "function", "function_header", "function_modifiers",
  "function_argument_list", "function_argument", "throwable_expression",
  "return_types_list", "return_type", "anonymous_function",
  "anonymous_function_header", "operator_overload",
  "operator_overload_header", "operator", "function_options", "callable",
  "callables", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -338;

  const signed char parser::yytable_ninf_ = -23;

  const short
  parser::yypact_[] =
  {
      12,    61,   607,    15,  -338,   -59,  -338,     3,  -338,    12,
     -49,  -338,    20,  -338,    38,   -33,    36,  -338,    50,    50,
      28,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
      23,  -338,  -338,  -338,  -338,   -60,  -338,    32,  -338,   531,
    -338,    47,  -338,  -338,   155,  -338,    45,    48,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,    83,   155,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,    18,    53,    54,    66,   -59,    92,
      96,    93,   101,   139,    88,    91,  -338,   104,  -338,   383,
     -59,   107,   109,   110,   383,   383,    39,   383,    39,    39,
     697,  -338,   115,  -338,    58,   925,   701,  -338,   119,  -338,
    -338,  -338,  -338,  -338,    59,   531,  -338,  -338,  -338,  -338,
    -338,  -338,   158,  -338,  -338,   102,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,   121,     4,   -36,  -338,   155,   155,   113,
      27,  -338,   155,   184,  -338,   140,   164,   128,   383,   155,
     173,  -338,   155,   143,  -338,  -338,   383,   136,  -338,   383,
     383,  -338,   141,   160,   -31,  -338,  -338,   170,   135,   383,
     122,   170,   122,   122,   793,    57,  -338,   155,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,  -338,  -338,    19,    39,    39,   383,   383,
     383,   383,   383,   383,  -338,  -338,  -338,   165,   229,   158,
    -338,   168,   -59,   102,  -338,  -338,   172,  -338,   155,   223,
      67,  -338,    68,  -338,   223,   171,   205,   176,   -18,   181,
    -338,   182,   267,   101,   189,   383,   190,  -338,   826,   192,
     383,  -338,   383,   859,   188,   191,  -338,   539,   187,   187,
     -44,   -44,   -44,   -44,   539,   539,   183,   985,   955,   572,
    1015,   390,   170,   276,   276,   925,   925,   925,   925,   925,
     925,   925,  -338,  -338,    82,  -338,   194,   194,   925,   925,
     925,   925,   925,   925,   383,   -59,  -338,  -338,  -338,   164,
    -338,  -338,   383,  -338,   195,   196,   223,   155,  -338,   197,
     204,     8,   383,   383,   383,   -59,   -59,   200,  -338,   383,
      84,   280,  -338,   -59,  -338,  -338,  -338,  -338,   383,    13,
     383,  -338,   206,  -338,   207,  -338,   383,    13,   208,  -338,
      13,   383,  -338,    16,   155,  -338,   209,  -338,  -338,   -59,
     210,  -338,   203,  -338,  -338,   383,    87,  -338,   383,   283,
     280,  -338,  -338,   758,   214,  -338,   -23,  -338,   211,   -59,
     -59,   217,   251,    13,   251,   892,   221,   155,   215,  -338,
    -338,   383,  -338,  -338,   220,   222,  -338,  -338,  -338,   383,
     383,    13,   -59,  -338,  -338,  -338,  -338,   251,  -338,   155,
      94,  -338,  -338,   -59,   -59,   925,   225,  -338,  -338,   116,
     223,   124,   124,  -338,   223,   227,  -338,  -338,   228,    13,
      13,   251,   251
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,   224,     0,   225,     0,   226,     2,
       0,   168,   169,   167,     0,    11,     0,   220,     0,     0,
       0,   204,   202,   188,   189,   191,   192,   190,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   205,   203,   207,
     208,   206,   210,   209,   211,   213,   212,   214,   215,   216,
       0,   219,   221,     4,     5,     7,     6,     0,     1,   111,
     164,     0,   185,   227,     0,   170,     0,     0,    10,     3,
      15,    16,   217,   218,     8,     0,     0,    65,    77,    78,
      79,    80,    82,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     0,    66,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,   163,     0,    17,    63,     0,    64,    23,     0,    62,
      61,    76,   112,   100,     0,   110,   101,   114,   115,   116,
     102,   122,   127,   123,   103,     0,   104,   105,   106,   107,
     108,   223,   222,     0,     0,     0,   171,     0,     0,     0,
       0,   155,     0,     0,   156,     0,     0,     0,     0,     0,
      83,    84,     0,     0,   157,   154,     0,     0,   144,     0,
       0,   159,    93,     0,     0,    91,    63,    57,    64,     0,
      71,    56,    67,    68,     0,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,   109,   113,     0,   132,   126,
     128,     0,     0,   143,   145,   186,   173,   174,     0,     0,
       0,    13,     0,     9,     0,     0,     0,     0,     0,     0,
     160,     0,     0,     0,     0,     0,     0,   158,     0,     0,
      20,    75,    20,     0,    74,     0,    55,    37,    25,    26,
      28,    29,    27,    30,    39,    38,    40,    41,    42,    43,
      45,    44,    46,    47,    48,    31,    32,    33,    34,    35,
      36,    18,    96,    99,     0,    97,    72,    73,    49,    50,
      51,    52,    54,    53,     0,     0,   124,   131,   129,     0,
     148,   146,     0,   172,   176,     0,     0,     0,    12,     0,
       0,     0,     0,     0,    20,     0,     0,    86,    85,     0,
       0,   136,    58,     0,    19,    94,    92,    74,     0,     0,
       0,    95,     0,   133,     0,   175,     0,     0,     0,    14,
       0,     0,   150,     0,     0,   151,     0,   152,   153,     0,
       0,   121,     0,   119,   125,     0,     0,    89,     0,   141,
     135,   137,   117,     0,     0,   180,     0,   178,     0,     0,
       0,     0,   166,     0,   187,     0,   168,     0,     0,   182,
     118,    20,    87,    90,     0,     0,   134,   140,   138,     0,
       0,     0,     0,    98,   130,   147,   177,   165,    59,     0,
       0,   149,   120,     0,     0,    60,     0,   179,    88,     0,
       0,     0,     0,   181,     0,     0,   139,   142,     0,     0,
       0,   184,   183
  };

  const short
  parser::yypgoto_[] =
  {
    -338,  -338,    -2,   297,   108,  -338,  -338,  -338,  -338,    90,
    -254,  -338,   -38,   310,   -51,  -338,  -151,  -338,    63,    -1,
    -338,  -338,    62,  -338,  -246,   -17,   201,    -4,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
      99,  -338,  -338,  -338,  -338,  -338,   -32,  -338,  -338,  -338,
    -338,  -338,   106,  -338,  -338,  -292,  -338,  -338,  -338,    21,
    -338,  -338,   -62,   103,  -240,  -337,   -58,  -338,  -338,  -338,
    -338,  -338,  -338,   335,  -338
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     3,   144,    53,    54,    55,    68,   242,    56,   293,
     173,   113,   176,   115,   178,   117,   118,   160,   161,   119,
     120,   174,   175,   121,   294,   295,   122,   123,   124,   125,
     126,   127,   128,   129,   249,   130,   131,   132,   228,   229,
     230,   306,   307,   133,   369,   370,   371,   396,   397,   134,
     135,   233,   234,   136,   356,   137,   138,   139,   140,     4,
       5,    14,   185,   146,   315,   376,   377,   358,   359,     6,
       7,    57,   143,     8,     9
  };

  const short
  parser::yytable_[] =
  {
      52,    60,   145,    62,   319,   248,   335,   236,   116,   330,
     382,   352,   323,   384,   150,    58,   194,    15,   238,    10,
     261,   114,    77,   262,    78,    79,    80,    81,    82,    83,
      16,   401,    85,    59,   353,   386,   203,    64,     1,    65,
      15,    66,    77,    74,    75,    67,   407,     2,   116,    18,
      19,   239,    93,   116,    15,   180,    12,   182,   183,   374,
      96,   114,    98,    13,    10,   101,   114,   141,   142,   104,
     362,   402,    18,    19,   116,   105,   348,   324,   106,    72,
      11,   238,    98,   366,   155,   240,    61,   114,   -22,   104,
     149,   163,   431,   432,   354,    59,   168,   107,   106,   157,
     237,    12,   387,   108,   109,   110,   292,   116,    13,   -22,
      73,   238,   -22,   151,   244,   116,   231,   232,    76,   116,
     114,   238,   317,   108,   109,   179,    70,    71,   114,   426,
     427,   147,   114,   159,   148,    84,   340,   412,   340,   152,
     153,   340,    87,    15,   265,   -22,   241,   -22,   238,   112,
     245,    90,   225,   -22,   316,   318,    16,   252,   344,    15,
     254,   154,    94,    95,   116,   296,   297,   162,    99,   341,
     238,   367,    16,   103,   393,    18,    19,   114,   156,   158,
     425,   420,   227,   164,   428,   266,   165,   246,   247,   167,
     166,    18,    19,   169,   172,   170,    92,   206,   207,   208,
     209,   210,   211,   424,   116,   171,   213,   214,   215,   116,
     186,   116,   216,   217,   224,   112,   235,   114,   243,   213,
     214,   215,   114,   250,   114,   216,   217,   253,   310,   255,
     -19,   257,   218,   219,   220,   221,   222,   223,   189,   190,
     191,   192,   193,   194,   191,   192,   193,   194,   251,   260,
     203,   304,   305,   116,   309,   312,   256,   314,   320,   321,
     259,   116,   322,   203,   204,   205,   114,   203,   325,   326,
     327,   116,   116,   116,   114,   329,   338,   331,   116,   333,
     215,   346,   339,   365,   114,   114,   114,   347,   350,   116,
     351,   114,   368,   379,   380,   116,   388,   390,   391,   383,
     400,   343,   114,   395,   406,   401,   403,   409,   114,   413,
     411,   414,   423,    69,   116,   349,   328,   116,   429,   430,
     355,   363,   364,   378,   336,   410,   226,   114,   308,   372,
     114,   189,   190,   191,   192,   193,   194,   375,   398,   311,
     116,   313,   357,   417,    63,   375,     0,   419,   375,   116,
     334,     0,   172,   114,     0,   389,   203,     0,     0,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   404,   405,     0,     0,     0,
       0,   375,     0,     0,     0,     0,    77,     0,    78,    79,
      80,    81,    82,    83,   342,     0,    85,     0,   418,   375,
       0,     0,   345,     0,     0,     0,     0,     0,     0,   421,
     422,     0,   360,   361,   334,   177,    93,   181,     0,     0,
     184,     0,     0,     0,    96,     0,    98,   375,   375,   101,
       0,     0,     0,   104,     0,     0,   381,     0,     0,   105,
       0,     0,   106,   188,     0,   189,   190,   191,   192,   193,
     194,     0,     0,     0,     0,   392,     0,     0,   394,   195,
     196,   107,     0,   197,     0,     0,   200,   108,   109,   110,
     203,   204,   205,     0,     0,     0,     0,     0,     0,   258,
       0,   334,     0,     0,     0,     0,     0,     0,     0,   263,
     416,     0,     0,     0,     0,     0,     0,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   298,   299,
     300,   301,   302,   303,    77,     0,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,     0,    86,     0,    87,
       0,     0,     0,    88,     0,     0,    89,     0,    90,     0,
      91,     0,     0,    92,    93,     0,     0,     0,     0,    94,
      95,     0,    96,    97,    98,    99,   100,   101,     0,   102,
     103,   104,     0,     0,     0,     0,     0,   105,     0,     0,
     106,     0,     0,     0,   189,   190,   191,   192,   193,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,    15,   197,     0,     0,   108,   109,   110,     0,   203,
     204,   205,     0,    59,    16,   188,   111,   189,   190,   191,
     192,   193,   194,     0,     0,     0,     0,     0,     0,     0,
      17,   195,   196,    18,    19,   197,     0,     0,   373,     0,
       0,     0,   203,   204,   205,     0,     0,    20,     0,    21,
      22,   385,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,    42,     0,     0,    43,    44,    45,    46,
      47,    48,    49,    50,     0,     0,     0,     0,    51,     0,
      77,    15,    78,    79,    80,    81,    82,    83,     0,   415,
      85,     0,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,   -21,     0,    18,    19,     0,     0,     0,    96,     0,
      98,     0,     0,   101,     0,     0,     0,   104,     0,     0,
       0,     0,   -21,   105,     0,   -21,   106,     0,     0,     0,
       0,     0,     0,   206,   207,   208,   209,   210,   211,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,   108,   109,   110,   212,   213,   214,   215,   -21,   187,
     -21,   216,   217,     0,     0,     0,   -21,     0,   218,   219,
     220,   221,   222,   223,     0,     0,     0,     0,     0,     0,
       0,   188,     0,   189,   190,   191,   192,   193,   194,     0,
       0,     0,     0,     0,   187,     0,     0,   195,   196,     0,
       0,   197,   198,   199,   200,   201,     0,   202,   203,   204,
     205,     0,     0,     0,     0,     0,   188,   399,   189,   190,
     191,   192,   193,   194,     0,     0,     0,   187,     0,     0,
       0,     0,   195,   196,     0,     0,   197,   198,   199,   200,
     201,     0,   202,   203,   204,   205,     0,     0,     0,   188,
     264,   189,   190,   191,   192,   193,   194,     0,     0,     0,
     187,     0,     0,     0,     0,   195,   196,     0,     0,   197,
     198,   199,   200,   201,     0,   202,   203,   204,   205,     0,
       0,     0,   188,   332,   189,   190,   191,   192,   193,   194,
       0,     0,     0,   187,     0,     0,     0,     0,   195,   196,
       0,     0,   197,   198,   199,   200,   201,     0,   202,   203,
     204,   205,     0,     0,     0,   188,   337,   189,   190,   191,
     192,   193,   194,     0,     0,     0,   187,     0,     0,     0,
       0,   195,   196,     0,     0,   197,   198,   199,   200,   201,
       0,   202,   203,   204,   205,     0,     0,     0,   188,   408,
     189,   190,   191,   192,   193,   194,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,     0,   197,   198,
     199,   200,   201,     0,   202,   203,   204,   205,   188,     0,
     189,   190,   191,   192,   193,   194,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,     0,   197,   198,
       0,   200,   201,     0,   202,   203,   204,   205,   188,     0,
     189,   190,   191,   192,   193,   194,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,     0,   197,     0,
       0,   200,   201,     0,   202,   203,   204,   205,   188,     0,
     189,   190,   191,   192,   193,   194,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,     0,   197,     0,
       0,   200,     0,     0,   202,   203,   204,   205
  };

  const short
  parser::yycheck_[] =
  {
       2,     5,    64,     7,   244,   156,   260,     3,    59,   255,
     347,     3,    30,   350,    76,     0,    60,     4,    54,     3,
      51,    59,     3,    54,     5,     6,     7,     8,     9,    10,
      17,    54,    13,    92,    26,    19,    80,    86,    26,    19,
       4,     3,     3,   103,   104,    78,   383,    35,    99,    36,
      37,    87,    33,   104,     4,   106,    40,   108,   109,    46,
      41,    99,    43,    47,     3,    46,   104,    20,    21,    50,
     324,    94,    36,    37,   125,    56,   316,    95,    59,    51,
      19,    54,    43,   329,    88,   147,    83,   125,    30,    50,
       7,    93,   429,   430,    86,    92,   100,    78,    59,     3,
      96,    40,    86,    84,    85,    86,    87,   158,    47,    51,
      87,    54,    54,    95,    87,   166,    14,    15,    86,   170,
     158,    54,    54,    84,    85,    86,    18,    19,   166,   421,
     422,    86,   170,    32,    86,    11,    54,   391,    54,    86,
      86,    54,    18,     4,    87,    87,   148,    89,    54,    59,
     152,    27,    93,    95,    87,    87,    17,   159,   309,     4,
     162,    95,    38,    39,   215,   216,   217,    28,    44,    87,
      54,    87,    17,    49,    87,    36,    37,   215,    86,    86,
     420,    87,    24,    95,   424,   187,    95,     3,    48,    99,
      86,    36,    37,    86,   104,    86,    32,    62,    63,    64,
      65,    66,    67,    87,   255,    95,    84,    85,    86,   260,
      95,   262,    90,    91,    95,   125,    95,   255,   105,    84,
      85,    86,   260,    95,   262,    90,    91,    54,   232,    86,
      89,    95,    97,    98,    99,   100,   101,   102,    55,    56,
      57,    58,    59,    60,    57,    58,    59,    60,   158,    89,
      80,    86,    23,   304,    86,    83,   166,    34,    87,    54,
     170,   312,    86,    80,    81,    82,   304,    80,    87,    87,
       3,   322,   323,   324,   312,    86,    88,    87,   329,    87,
      86,    86,    91,    83,   322,   323,   324,    91,    91,   340,
      86,   329,    12,    87,    87,   346,    87,    87,    95,    91,
      86,   305,   340,    20,    87,    54,    95,    86,   346,    89,
      95,    89,    87,    16,   365,   317,   253,   368,    91,    91,
     321,   325,   326,   340,   262,   387,   125,   365,   229,   333,
     368,    55,    56,    57,    58,    59,    60,   339,   370,   233,
     391,   238,   321,   401,     9,   347,    -1,   409,   350,   400,
     260,    -1,   262,   391,    -1,   359,    80,    -1,    -1,    -1,
      -1,    -1,   400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   379,   380,    -1,    -1,    -1,
      -1,   383,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,   304,    -1,    13,    -1,   402,   401,
      -1,    -1,   312,    -1,    -1,    -1,    -1,    -1,    -1,   413,
     414,    -1,   322,   323,   324,   105,    33,   107,    -1,    -1,
     110,    -1,    -1,    -1,    41,    -1,    43,   429,   430,    46,
      -1,    -1,    -1,    50,    -1,    -1,   346,    -1,    -1,    56,
      -1,    -1,    59,    53,    -1,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,   365,    -1,    -1,   368,    69,
      70,    78,    -1,    73,    -1,    -1,    76,    84,    85,    86,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,   169,
      -1,   391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,   221,   222,   223,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    -1,    -1,    16,    -1,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    27,    -1,
      29,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,     4,    73,    -1,    -1,    84,    85,    86,    -1,    80,
      81,    82,    -1,    92,    17,    53,    95,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    69,    70,    36,    37,    73,    -1,    -1,   338,    -1,
      -1,    -1,    80,    81,    82,    -1,    -1,    50,    -1,    52,
      53,   351,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    76,    -1,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    91,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,   399,
      13,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    30,    -1,    36,    37,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    51,    56,    -1,    54,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    83,    84,    85,    86,    87,    31,
      89,    90,    91,    -1,    -1,    -1,    95,    -1,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    69,    70,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,    53,    89,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    69,    70,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    79,    80,    81,    82,    -1,    -1,    -1,    53,
      87,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    80,    81,    82,    -1,
      -1,    -1,    53,    87,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    79,    80,
      81,    82,    -1,    -1,    -1,    53,    87,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    80,    81,    82,    -1,    -1,    -1,    53,    87,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    82,    53,    -1,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,    74,
      -1,    76,    77,    -1,    79,    80,    81,    82,    53,    -1,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,    -1,
      -1,    76,    77,    -1,    79,    80,    81,    82,    53,    -1,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,    -1,
      -1,    76,    -1,    -1,    79,    80,    81,    82
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    26,    35,   113,   171,   172,   181,   182,   185,   186,
       3,    19,    40,    47,   173,     4,    17,    33,    36,    37,
      50,    52,    53,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    76,    79,    80,    81,    82,    83,    84,    85,
      86,    91,   114,   115,   116,   117,   120,   183,     0,    92,
     139,    83,   139,   185,    86,    19,     3,    78,   118,   115,
     116,   116,    51,    87,   103,   104,    86,     3,     5,     6,
       7,     8,     9,    10,    11,    13,    16,    18,    22,    25,
      27,    29,    32,    33,    38,    39,    41,    42,    43,    44,
      45,    46,    48,    49,    50,    56,    59,    78,    84,    85,
      86,    95,   121,   123,   124,   125,   126,   127,   128,   131,
     132,   135,   138,   139,   140,   141,   142,   143,   144,   145,
     147,   148,   149,   155,   161,   162,   165,   167,   168,   169,
     170,    20,    21,   184,   114,   174,   175,    86,    86,     7,
     174,    95,    86,    86,    95,   139,    86,     3,    86,    32,
     129,   130,    28,   114,    95,    95,    86,   121,   139,    86,
      86,    95,   121,   122,   133,   134,   124,   125,   126,    86,
     126,   125,   126,   126,   125,   174,    95,    31,    53,    55,
      56,    57,    58,    59,    60,    69,    70,    73,    74,    75,
      76,    77,    79,    80,    81,    82,    62,    63,    64,    65,
      66,    67,    83,    84,    85,    86,    90,    91,    97,    98,
      99,   100,   101,   102,    95,    93,   138,    24,   150,   151,
     152,    14,    15,   163,   164,    95,     3,    96,    54,    87,
     174,   114,   119,   105,    87,   114,     3,    48,   128,   146,
      95,   121,   114,    54,   114,    86,   121,    95,   125,   121,
      89,    51,    54,   125,    87,    87,   114,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,    87,   121,   136,   137,   126,   126,   125,   125,
     125,   125,   125,   125,    86,    23,   153,   154,   152,    86,
     139,   164,    83,   175,    34,   176,    87,    54,    87,   176,
      87,    54,    86,    30,    95,    87,    87,     3,   130,    86,
     136,    87,    87,    87,   121,   122,   134,    87,    88,    91,
      54,    87,   121,   139,   128,   121,    86,    91,   176,   114,
      91,    86,     3,    26,    86,   131,   166,   171,   179,   180,
     121,   121,   122,   139,   139,    83,   136,    87,    12,   156,
     157,   158,   139,   125,    46,   114,   177,   178,   137,    87,
      87,   121,   177,    91,   177,   125,    19,    86,    87,   139,
      87,    95,   121,    87,   121,    20,   159,   160,   158,    89,
      86,    54,    94,    95,   139,   139,    87,   177,    87,    86,
     174,    95,   122,    89,    89,   125,   121,   178,   139,   174,
      87,   139,   139,    87,    87,   176,   167,   167,   176,    91,
      91,   177,   177
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   112,   113,   114,   114,   115,   115,   116,   116,   116,
     117,   117,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   127,   127,   127,
     127,   127,   127,   128,   129,   129,   130,   130,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   139,
     140,   140,   141,   141,   142,   142,   142,   143,   144,   145,
     146,   146,   147,   147,   148,   149,   150,   150,   151,   151,
     152,   153,   153,   154,   155,   156,   156,   157,   157,   158,
     159,   159,   160,   161,   162,   163,   163,   164,   164,   165,
     166,   166,   166,   166,   167,   167,   167,   167,   167,   167,
     167,   168,   169,   170,   171,   172,   172,   173,   173,   173,
     173,   174,   174,   175,   175,   175,   176,   176,   177,   177,
     178,   178,   179,   180,   180,   181,   181,   182,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   184,   184,   185,   185,   186,   186
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     2,     4,
       2,     1,     4,     1,     3,     2,     2,     1,     3,     1,
       0,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     4,     7,
       7,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     3,     5,     7,     5,
       6,     1,     3,     1,     3,     4,     3,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     1,     2,     1,     1,     1,     5,     6,     5,
       5,     3,     1,     1,     3,     5,     1,     0,     1,     2,
       5,     1,     0,     2,     6,     1,     0,     1,     2,     5,
       1,     0,     4,     2,     2,     1,     2,     5,     2,     7,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     2,
       3,     2,     2,     1,     2,     9,     8,     1,     1,     1,
       2,     1,     3,     2,     2,     4,     1,     4,     1,     3,
       1,     4,     2,     8,     7,     2,     4,     8,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    65,    65,    69,    70,    73,    73,    76,    77,    78,
      81,    82,    85,    88,    89,    92,    93,    99,   100,   103,
     104,   107,   108,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   153,   154,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   171,   171,   171,
     171,   171,   171,   174,   177,   178,   181,   182,   184,   187,
     188,   191,   192,   195,   196,   199,   200,   203,   204,   207,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   223,
     226,   227,   230,   231,   234,   235,   236,   239,   242,   245,
     248,   249,   252,   253,   256,   259,   262,   263,   266,   267,
     270,   273,   274,   277,   280,   283,   284,   287,   288,   291,
     294,   295,   298,   301,   304,   307,   308,   311,   312,   315,
     318,   319,   320,   321,   324,   325,   326,   327,   328,   329,
     330,   333,   336,   339,   344,   347,   348,   351,   352,   353,
     354,   357,   358,   361,   362,   363,   366,   367,   370,   371,
     374,   375,   378,   381,   382,   385,   386,   389,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   391,
     391,   391,   392,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   392,   393,   393,   393,
     393,   393,   396,   396,   399,   400,   403,   404
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


#line 7 "parser.yy"
} } } // Arbor::FE::parser
#line 1678 "Parser/Arbor_parser.tab.cc"

#line 406 "parser.yy"
