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
  "POSTDEC", "TERN", "DEREF", "$accept", "start", "type", "type_root",
  "non_reference_type", "type_core", "type_template_paramaters",
  "type_list", "reference_type", "expression", "expression0",
  "assignment_arg_expression", "prvalue_expression", "rvalue_expression",
  "xvalue_expression", "literal", "variable_declaration",
  "variable_declaration_block_list", "variable_declaration_block",
  "lambda_expression", "new_expression", "array_index_list", "array_index",
  "function_call", "function_call_list", "function_call_arg", "statement",
  "block_statement", "statements0", "statements", "loop_statement",
  "while_loop_statement", "do_loop_statement", "for_loop_statement",
  "for_loop_condition", "conditional_statement", "if_statement_sequence",
  "if_statement", "else_if_statements0", "else_if_statements",
  "else_if_statement", "else_statement0", "else_statement",
  "switch_statement", "case_blocks0", "case_blocks", "case_block",
  "default_block0", "default_block", "exception_statement", "try_block",
  "catch_blocks", "catch_block", "clean_up_statement", "clean_up_arg",
  "jump_statement", "expression_statement",
  "variable_declaration_statement", "no_op_statement", "function",
  "function_header", "function_modifiers", "function_argument_list",
  "function_argument", "throwable_expression", "return_types_list",
  "return_type", "anonymous_function", "anonymous_function_header",
  "operator_overload", "operator_overload_header", "operator",
  "function_options", "callable", "callables", YY_NULLPTR
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
      -7,    32,   565,    25,  -338,   -69,  -338,   -56,  -338,    -7,
     -57,  -338,    14,  -338,    38,   -29,    22,  -338,    61,    61,
      20,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
      -1,  -338,  -338,  -338,  -338,    23,  -338,     9,  -338,   482,
    -338,   131,  -338,  -338,   107,  -338,    33,    39,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,   105,   107,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,    40,    47,    55,    50,   -69,    63,
     158,    76,   134,    72,    68,    74,  -338,    81,  -338,   679,
     -69,    85,    92,    84,   679,   679,    19,   679,    19,    19,
     658,  -338,    86,  -338,   -12,   872,   683,  -338,    87,  -338,
    -338,  -338,  -338,  -338,    90,   482,  -338,  -338,  -338,  -338,
    -338,  -338,   165,  -338,  -338,   123,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,   110,     5,   -41,  -338,   107,   107,    95,
     -24,  -338,   107,   199,  -338,   159,   180,   116,   679,   107,
     160,  -338,   107,   132,  -338,  -338,   679,   124,  -338,   679,
     679,  -338,   138,   140,    80,  -338,  -338,   143,   293,   679,
      31,   143,    31,    31,   740,   -23,  -338,   107,   679,   679,
     679,   679,   679,   679,   679,   679,   679,   679,   679,   679,
     679,   679,   679,   679,   679,   679,   679,   679,   679,   679,
     679,   679,   679,  -338,  -338,     7,    19,    19,   679,   679,
     679,   679,   679,   679,  -338,  -338,  -338,   139,   197,   165,
    -338,   144,   -69,   123,  -338,  -338,   148,  -338,   107,   212,
     -20,  -338,   -17,  -338,   212,   146,   193,   167,   -13,   164,
    -338,   169,   251,   134,   171,   679,   175,  -338,   773,   176,
     679,  -338,   679,   806,   183,   182,  -338,   490,   228,   228,
     -40,   -40,   -40,   -40,   490,   490,   185,   902,   365,   962,
     932,   179,   143,   221,   221,   872,   872,   872,   872,   872,
     872,   872,  -338,    -6,  -338,  -338,   872,   872,   872,   872,
     872,   872,   679,   -69,  -338,  -338,  -338,   180,  -338,  -338,
     679,  -338,   188,   200,   212,   107,  -338,   201,   204,    12,
     679,   679,   679,   -69,   -69,   211,  -338,   679,  -338,     1,
    -338,   283,  -338,   -69,  -338,  -338,  -338,  -338,   679,    93,
    -338,   209,  -338,   210,  -338,   679,    93,   207,  -338,    93,
     679,  -338,    13,   107,  -338,   213,  -338,  -338,   -69,   215,
    -338,   214,  -338,  -338,   679,    26,   679,  -338,   679,   284,
     283,  -338,  -338,   117,   220,  -338,   -44,  -338,   -69,   -69,
     223,   257,    93,   257,   839,   229,   107,   222,  -338,  -338,
     679,  -338,  -338,   226,   233,   234,  -338,  -338,  -338,   679,
     679,    93,   -69,  -338,  -338,  -338,   257,  -338,   107,    36,
    -338,  -338,  -338,   -69,   -69,   872,   231,  -338,  -338,    53,
     212,   177,   177,  -338,   212,   236,  -338,  -338,   240,    93,
      93,   257,   257
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
      36,    18,    96,     0,    72,    73,    49,    50,    51,    52,
      54,    53,     0,     0,   124,   131,   129,     0,   148,   146,
       0,   172,   176,     0,     0,     0,    12,     0,     0,     0,
       0,     0,    20,     0,     0,    86,    85,     0,    99,     0,
      97,   136,    58,     0,    19,    94,    92,    74,     0,     0,
      95,     0,   133,     0,   175,     0,     0,     0,    14,     0,
       0,   150,     0,     0,   151,     0,   152,   153,     0,     0,
     121,     0,   119,   125,     0,     0,     0,    89,     0,   141,
     135,   137,   117,     0,     0,   180,     0,   178,     0,     0,
       0,   166,     0,   187,     0,   168,     0,     0,   182,   118,
      20,    87,    90,     0,     0,     0,   134,   140,   138,     0,
       0,     0,     0,   130,   147,   177,   165,    59,     0,     0,
     149,   120,    98,     0,     0,    60,     0,   179,    88,     0,
       0,     0,     0,   181,     0,     0,   139,   142,     0,     0,
       0,   184,   183
  };

  const short
  parser::yypgoto_[] =
  {
    -338,  -338,    -2,   309,   136,  -338,  -338,  -338,  -338,    43,
    -254,  -338,   -38,   261,   -52,  -338,  -151,  -338,    79,    15,
    -338,  -338,    71,  -338,     8,   -30,   216,    -4,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
     111,  -338,  -338,  -338,  -338,  -338,   -31,  -338,  -338,  -338,
    -338,  -338,   109,  -338,  -338,  -263,  -338,  -338,  -338,    24,
    -338,  -338,   -62,   112,  -240,  -337,   -50,  -338,  -338,  -338,
    -338,  -338,  -338,   340,  -338
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     3,   144,    53,    54,    55,    68,   242,    56,   328,
     173,   113,   176,   115,   178,   117,   118,   160,   161,   119,
     120,   174,   175,   121,   329,   330,   122,   123,   124,   125,
     126,   127,   128,   129,   249,   130,   131,   132,   228,   229,
     230,   304,   305,   133,   369,   370,   371,   396,   397,   134,
     135,   233,   234,   136,   355,   137,   138,   139,   140,     4,
       5,    14,   185,   146,   313,   376,   377,   357,   358,     6,
       7,    57,   143,     8,     9
  };

  const short
  parser::yytable_[] =
  {
      52,    60,   145,    62,   317,   248,   335,   116,   236,   381,
     401,    15,   383,   238,   150,   351,    10,   321,   -22,     1,
     194,   114,    77,    59,    16,    58,    15,    61,     2,    64,
     238,   238,   385,    65,   238,    10,    59,   315,   352,   -22,
     203,    66,   -22,    18,    19,   406,   239,   116,   238,    67,
     402,    11,   116,    12,   180,   366,   182,   183,    18,    19,
      13,   114,    98,   244,   265,    15,   114,   314,   361,   104,
     316,    72,    12,   116,   347,   -22,    15,   -22,   106,    13,
     366,   340,   322,   -22,   155,   240,    73,   114,   367,    16,
     238,   163,   431,   432,   292,    76,   168,    15,   353,   386,
     162,   237,   112,   108,   109,   179,   116,   238,    18,    19,
      16,    15,   149,   392,   116,   213,   214,   215,   116,   147,
     114,   216,   217,   420,    16,   148,    74,    75,   114,    18,
      19,   261,   114,   152,   262,   151,   411,   231,   232,   374,
     424,   153,   167,    18,    19,   154,   241,   172,   187,   156,
     245,   141,   142,   293,    70,    71,   343,   252,   426,   427,
     254,   157,   158,   164,   294,   295,   159,   166,   112,   165,
     188,   169,   189,   190,   191,   192,   193,   194,   170,   171,
     425,   186,   224,   225,   428,   266,   195,   196,    84,   227,
     197,   198,   199,   200,   201,    87,   202,   203,   204,   205,
     243,   251,   246,   116,    90,   235,   399,   247,   116,   256,
     116,   250,    92,   259,   253,    94,    95,   114,   255,   257,
     303,    99,   114,   203,   114,   302,   103,   -19,   308,   260,
     307,   310,   188,   318,   189,   190,   191,   192,   193,   194,
     189,   190,   191,   192,   193,   194,   312,   319,   195,   196,
     116,   323,   197,   320,   325,   200,   324,   327,   116,   203,
     204,   205,   331,   333,   114,   203,   204,   205,   116,   116,
     116,   338,   114,   339,   345,   116,   189,   190,   191,   192,
     193,   194,   114,   114,   114,   191,   192,   193,   194,   114,
     350,   346,   349,   116,   364,   368,   378,   379,   382,   342,
     387,   203,   389,   334,   395,   172,   400,   114,   203,   390,
     405,   401,   116,   348,   116,   408,   116,   410,   423,   362,
     363,   412,   413,   414,   409,    69,   114,   429,   114,   372,
     114,   430,   326,   336,   354,   365,   393,   375,   116,   398,
     306,   226,   309,   356,   375,   341,   419,   375,   116,    63,
     311,   417,   114,   344,   388,   206,   207,   208,   209,   210,
     211,     0,   114,   359,   360,   334,   177,     0,   181,     0,
       0,   184,     0,     0,   403,   404,     0,   213,   214,   215,
     375,     0,     0,   216,   217,     0,     0,     0,   380,     0,
     218,   219,   220,   221,   222,   223,     0,     0,   418,   375,
       0,     0,     0,     0,     0,     0,     0,   391,     0,   421,
     422,   394,     0,     0,     0,     0,     0,     0,   188,     0,
     189,   190,   191,   192,   193,   194,     0,   375,   375,     0,
     258,     0,     0,   334,   195,   196,     0,     0,   197,   198,
     263,   200,   201,   416,   202,   203,   204,   205,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   296,
     297,   298,   299,   300,   301,    77,     0,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,     0,    86,     0,
      87,     0,     0,     0,    88,     0,     0,    89,     0,    90,
       0,    91,     0,     0,    92,    93,     0,     0,     0,     0,
      94,    95,     0,    96,    97,    98,    99,   100,   101,     0,
     102,   103,   104,     0,     0,     0,     0,     0,   105,     0,
       0,   106,     0,     0,     0,   189,   190,   191,   192,   193,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,     0,   197,     0,     0,   108,   109,   110,    15,
     203,   204,   205,     0,    59,     0,     0,   111,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,   373,
       0,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,   384,     0,     0,     0,    20,     0,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,    42,     0,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,     0,     0,    51,     0,     0,     0,
     415,    77,    15,    78,    79,    80,    81,    82,    83,     0,
       0,    85,     0,     0,     0,    16,     0,     0,     0,     0,
       0,     0,    77,     0,    78,    79,    80,    81,    82,    83,
       0,    93,    85,     0,    18,    19,     0,     0,     0,    96,
       0,    98,     0,     0,   101,     0,     0,     0,   104,     0,
       0,     0,    93,   -21,   105,     0,     0,   106,     0,     0,
      96,     0,    98,     0,     0,   101,     0,     0,     0,   104,
       0,     0,     0,     0,   -21,   105,   107,   -21,   106,     0,
       0,     0,   108,   109,   110,   206,   207,   208,   209,   210,
     211,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,   108,   109,   110,   212,   213,   214,   215,
     -21,   187,   -21,   216,   217,     0,     0,     0,   -21,     0,
     218,   219,   220,   221,   222,   223,     0,     0,     0,     0,
       0,     0,     0,   188,     0,   189,   190,   191,   192,   193,
     194,     0,     0,     0,   187,     0,     0,     0,     0,   195,
     196,     0,     0,   197,   198,   199,   200,   201,     0,   202,
     203,   204,   205,     0,     0,     0,   188,   264,   189,   190,
     191,   192,   193,   194,     0,     0,     0,   187,     0,     0,
       0,     0,   195,   196,     0,     0,   197,   198,   199,   200,
     201,     0,   202,   203,   204,   205,     0,     0,     0,   188,
     332,   189,   190,   191,   192,   193,   194,     0,     0,     0,
     187,     0,     0,     0,     0,   195,   196,     0,     0,   197,
     198,   199,   200,   201,     0,   202,   203,   204,   205,     0,
       0,     0,   188,   337,   189,   190,   191,   192,   193,   194,
       0,     0,     0,   187,     0,     0,     0,     0,   195,   196,
       0,     0,   197,   198,   199,   200,   201,     0,   202,   203,
     204,   205,     0,     0,     0,   188,   407,   189,   190,   191,
     192,   193,   194,     0,     0,     0,     0,     0,     0,     0,
       0,   195,   196,     0,     0,   197,   198,   199,   200,   201,
       0,   202,   203,   204,   205,   188,     0,   189,   190,   191,
     192,   193,   194,     0,     0,     0,     0,     0,     0,     0,
       0,   195,   196,     0,     0,   197,     0,     0,   200,   201,
       0,   202,   203,   204,   205,   188,     0,   189,   190,   191,
     192,   193,   194,     0,     0,     0,     0,     0,     0,     0,
       0,   195,   196,     0,     0,   197,     0,     0,   200,     0,
       0,   202,   203,   204,   205,   188,     0,   189,   190,   191,
     192,   193,   194,     0,     0,     0,     0,     0,     0,     0,
       0,   195,   196,     0,     0,   197,     0,     0,     0,     0,
       0,     0,   203,   204,   205
  };

  const short
  parser::yycheck_[] =
  {
       2,     5,    64,     7,   244,   156,   260,    59,     3,   346,
      54,     4,   349,    54,    76,     3,     3,    30,    30,    26,
      60,    59,     3,    92,    17,     0,     4,    83,    35,    86,
      54,    54,    19,    19,    54,     3,    92,    54,    26,    51,
      80,     3,    54,    36,    37,   382,    87,    99,    54,    78,
      94,    19,   104,    40,   106,    54,   108,   109,    36,    37,
      47,    99,    43,    87,    87,     4,   104,    87,   322,    50,
      87,    51,    40,   125,   314,    87,     4,    89,    59,    47,
      54,    87,    95,    95,    88,   147,    87,   125,    87,    17,
      54,    93,   429,   430,    87,    86,   100,     4,    86,    86,
      28,    96,    59,    84,    85,    86,   158,    54,    36,    37,
      17,     4,     7,    87,   166,    84,    85,    86,   170,    86,
     158,    90,    91,    87,    17,    86,   103,   104,   166,    36,
      37,    51,   170,    86,    54,    95,   390,    14,    15,    46,
      87,    86,    99,    36,    37,    95,   148,   104,    31,    86,
     152,    20,    21,   215,    18,    19,   307,   159,   421,   422,
     162,     3,    86,    95,   216,   217,    32,    86,   125,    95,
      53,    86,    55,    56,    57,    58,    59,    60,    86,    95,
     420,    95,    95,    93,   424,   187,    69,    70,    11,    24,
      73,    74,    75,    76,    77,    18,    79,    80,    81,    82,
     105,   158,     3,   255,    27,    95,    89,    48,   260,   166,
     262,    95,    32,   170,    54,    38,    39,   255,    86,    95,
      23,    44,   260,    80,   262,    86,    49,    89,   232,    89,
      86,    83,    53,    87,    55,    56,    57,    58,    59,    60,
      55,    56,    57,    58,    59,    60,    34,    54,    69,    70,
     302,    87,    73,    86,     3,    76,    87,    86,   310,    80,
      81,    82,    87,    87,   302,    80,    81,    82,   320,   321,
     322,    88,   310,    91,    86,   327,    55,    56,    57,    58,
      59,    60,   320,   321,   322,    57,    58,    59,    60,   327,
      86,    91,    91,   345,    83,    12,    87,    87,    91,   303,
      87,    80,    87,   260,    20,   262,    86,   345,    80,    95,
      87,    54,   364,   315,   366,    86,   368,    95,    87,   323,
     324,    95,    89,    89,   386,    16,   364,    91,   366,   333,
     368,    91,   253,   262,   319,   327,   366,   339,   390,   370,
     229,   125,   233,   319,   346,   302,   408,   349,   400,     9,
     238,   401,   390,   310,   358,    62,    63,    64,    65,    66,
      67,    -1,   400,   320,   321,   322,   105,    -1,   107,    -1,
      -1,   110,    -1,    -1,   378,   379,    -1,    84,    85,    86,
     382,    -1,    -1,    90,    91,    -1,    -1,    -1,   345,    -1,
      97,    98,    99,   100,   101,   102,    -1,    -1,   402,   401,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   364,    -1,   413,
     414,   368,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    56,    57,    58,    59,    60,    -1,   429,   430,    -1,
     169,    -1,    -1,   390,    69,    70,    -1,    -1,    73,    74,
     179,    76,    77,   400,    79,    80,    81,    82,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,    -1,   218,
     219,   220,   221,   222,   223,     3,    -1,     5,     6,     7,
       8,     9,    10,    11,    -1,    13,    -1,    -1,    16,    -1,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    27,
      -1,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    73,    -1,    -1,    84,    85,    86,     4,
      80,    81,    82,    -1,    92,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,   338,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   350,    -1,    -1,    -1,    50,    -1,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    76,    -1,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
     399,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    33,    13,    -1,    36,    37,    -1,    -1,    -1,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    33,    30,    56,    -1,    -1,    59,    -1,    -1,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    51,    56,    78,    54,    59,    -1,
      -1,    -1,    84,    85,    86,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    83,    84,    85,    86,
      87,    31,    89,    90,    91,    -1,    -1,    -1,    95,    -1,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      80,    81,    82,    -1,    -1,    -1,    53,    87,    55,    56,
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
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    80,    81,    82,    53,    -1,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    -1,    -1,    76,    77,
      -1,    79,    80,    81,    82,    53,    -1,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    -1,    -1,    76,    -1,
      -1,    79,    80,    81,    82,    53,    -1,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    26,    35,   112,   170,   171,   180,   181,   184,   185,
       3,    19,    40,    47,   172,     4,    17,    33,    36,    37,
      50,    52,    53,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    76,    79,    80,    81,    82,    83,    84,    85,
      86,    91,   113,   114,   115,   116,   119,   182,     0,    92,
     138,    83,   138,   184,    86,    19,     3,    78,   117,   114,
     115,   115,    51,    87,   103,   104,    86,     3,     5,     6,
       7,     8,     9,    10,    11,    13,    16,    18,    22,    25,
      27,    29,    32,    33,    38,    39,    41,    42,    43,    44,
      45,    46,    48,    49,    50,    56,    59,    78,    84,    85,
      86,    95,   120,   122,   123,   124,   125,   126,   127,   130,
     131,   134,   137,   138,   139,   140,   141,   142,   143,   144,
     146,   147,   148,   154,   160,   161,   164,   166,   167,   168,
     169,    20,    21,   183,   113,   173,   174,    86,    86,     7,
     173,    95,    86,    86,    95,   138,    86,     3,    86,    32,
     128,   129,    28,   113,    95,    95,    86,   120,   138,    86,
      86,    95,   120,   121,   132,   133,   123,   124,   125,    86,
     125,   124,   125,   125,   124,   173,    95,    31,    53,    55,
      56,    57,    58,    59,    60,    69,    70,    73,    74,    75,
      76,    77,    79,    80,    81,    82,    62,    63,    64,    65,
      66,    67,    83,    84,    85,    86,    90,    91,    97,    98,
      99,   100,   101,   102,    95,    93,   137,    24,   149,   150,
     151,    14,    15,   162,   163,    95,     3,    96,    54,    87,
     173,   113,   118,   105,    87,   113,     3,    48,   127,   145,
      95,   120,   113,    54,   113,    86,   120,    95,   124,   120,
      89,    51,    54,   124,    87,    87,   113,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,    87,   173,   125,   125,   124,   124,   124,   124,
     124,   124,    86,    23,   152,   153,   151,    86,   138,   163,
      83,   174,    34,   175,    87,    54,    87,   175,    87,    54,
      86,    30,    95,    87,    87,     3,   129,    86,   120,   135,
     136,    87,    87,    87,   120,   121,   133,    87,    88,    91,
      87,   120,   138,   127,   120,    86,    91,   175,   113,    91,
      86,     3,    26,    86,   130,   165,   170,   178,   179,   120,
     120,   121,   138,   138,    83,   135,    54,    87,    12,   155,
     156,   157,   138,   124,    46,   113,   176,   177,    87,    87,
     120,   176,    91,   176,   124,    19,    86,    87,   138,    87,
      95,   120,    87,   136,   120,    20,   158,   159,   157,    89,
      86,    54,    94,   138,   138,    87,   176,    87,    86,   173,
      95,   121,    95,    89,    89,   124,   120,   177,   138,   173,
      87,   138,   138,    87,    87,   175,   166,   166,   175,    91,
      91,   176,   176
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   111,   112,   113,   113,   114,   114,   115,   115,   115,
     116,   116,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   126,   126,   126,
     126,   126,   126,   127,   128,   128,   129,   129,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   138,
     139,   139,   140,   140,   141,   141,   141,   142,   143,   144,
     145,   145,   146,   146,   147,   148,   149,   149,   150,   150,
     151,   152,   152,   153,   154,   155,   155,   156,   156,   157,
     158,   158,   159,   160,   161,   162,   162,   163,   163,   164,
     165,   165,   165,   165,   166,   166,   166,   166,   166,   166,
     166,   167,   168,   169,   170,   171,   171,   172,   172,   172,
     172,   173,   173,   174,   174,   174,   175,   175,   176,   176,
     177,   177,   178,   179,   179,   180,   180,   181,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   183,   183,   184,   184,   185,   185
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
#line 1667 "Parser/Arbor_parser.tab.cc"

#line 406 "parser.yy"
