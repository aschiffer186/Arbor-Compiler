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
    #include "../ParseTree/syntax_node.hh"
    yy::parser::symbol_type yylex(Arbor::FE::parse_context& pc);

#line 52 "Parser/Arbor_parser.tab.cc"


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
#line 144 "Parser/Arbor_parser.tab.cc"

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
      case symbol_kind::S_literal: // literal
        value.YY_MOVE_OR_COPY< Arbor::FE::prvalue_expression_node* > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_literal: // literal
        value.move< Arbor::FE::prvalue_expression_node* > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_literal: // literal
        value.copy< Arbor::FE::prvalue_expression_node* > (that.value);
        break;

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
      case symbol_kind::S_literal: // literal
        value.move< Arbor::FE::prvalue_expression_node* > (that.value);
        break;

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
      case symbol_kind::S_literal: // literal
        yylhs.value.emplace< Arbor::FE::prvalue_expression_node* > ();
        break;

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
  case 88: // literal: BOOL
#line 191 "parser.yy"
         {yylhs.value.as < Arbor::FE::prvalue_expression_node* > () = new Arbor::FE::literal_node<bool>(yystack_[0].value.as < bool > ());}
#line 664 "Parser/Arbor_parser.tab.cc"
    break;

  case 89: // literal: NPTR
#line 192 "parser.yy"
         {yylhs.value.as < Arbor::FE::prvalue_expression_node* > () = new Arbor::FE::literal_node<bool>(nullptr));}
#line 670 "Parser/Arbor_parser.tab.cc"
    break;

  case 90: // literal: INT
#line 193 "parser.yy"
         {yylhs.value.as < Arbor::FE::prvalue_expression_node* > () = new Arbor::FE::literal_node<bool>(yystack_[0].value.as < int > ());}
#line 676 "Parser/Arbor_parser.tab.cc"
    break;

  case 91: // literal: FLOAT
#line 194 "parser.yy"
          {yylhs.value.as < Arbor::FE::prvalue_expression_node* > () = new Arbor::FE::literal_node<bool>(yystack_[0].value.as < double > ());}
#line 682 "Parser/Arbor_parser.tab.cc"
    break;

  case 92: // literal: STRING
#line 195 "parser.yy"
           {yylhs.value.as < Arbor::FE::prvalue_expression_node* > () = new Arbor::FE::literal_node<bool>(yystack_[0].value.as < std::string > ());}
#line 688 "Parser/Arbor_parser.tab.cc"
    break;

  case 93: // literal: CHAR
#line 196 "parser.yy"
         {yylhs.value.as < Arbor::FE::prvalue_expression_node* > () = new Arbor::FE::literal_node<bool>(yystack_[0].value.as < std::string > ());}
#line 694 "Parser/Arbor_parser.tab.cc"
    break;


#line 698 "Parser/Arbor_parser.tab.cc"

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
  "POSTINC", "POSTDEC", "TERN", "DEREF", "virtual const", "compeval const",
  "initailize", "type", "namespace", "$accept", "start", "type",
  "type_root", "non_reference_type", "type_core",
  "type_template_paramaters", "type_list", "reference_type", "expression",
  "expression0", "assignment_arg_expression", "prvalue_expression",
  "rvalue_expression", "xvalue_expression", "literal", "lambda_expression",
  "new_expression", "array_index_list", "array_index", "function_call",
  "function_call_list", "function_call_arg", "statement",
  "block_statement", "statements0", "statements", "loop_statement",
  "while_loop_statement", "do_loop_statement", "for_loop_statement",
  "for_loop_condition", "conditional_statement", "if_statement_sequence",
  "if_statement", "else_if_statements0", "else_if_statements",
  "else_if_statement", "else_statement0", "else_statement",
  "switch_statement", "case_blocks0", "case_blocks", "case_block",
  "default_block0", "default_block", "exception_statement", "try_block",
  "catch_blocks", "catch_block", "clean_up_statement", "clean_up_arg",
  "jump_statement", "expression_statement",
  "variable_declaration_statement", "variable_declaration",
  "variable_declaration_block_list", "variable_declaration_block",
  "access_modifier0", "access_modifier", "no_op_statement", "function",
  "function_header", "function_modifiers", "function_argument_list",
  "function_argument", "throwable_expression", "return_types_list",
  "return_type", "anonymous_function", "anonymous_function_header",
  "operator_overload", "operator_overload_header", "operator",
  "function_options", "callable", "enum", "enum_members_list",
  "enum_member", "class", "class_header", "inheritance",
  "class_names_list", "class_name", "class_statements", "class_statement",
  "property", "property_blocks", "get_block", "set_block", "constructor",
  "constructor_header", "initializer_list", "initializer_blocks_list",
  "initializer_block", "compeval0", "destructor", "destructor_header",
  "template_header", "template_declaration_list",
  "template_declaration_type", "module", "module_name", "import",
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


  const short parser::yypact_ninf_ = -479;

  const short parser::yytable_ninf_ = -176;

  const short
  parser::yypact_[] =
  {
     549,   -73,  -479,  -479,  -479,   743,   -82,  -479,    35,    14,
    -479,   180,  -479,    38,   863,  -479,  -479,  -479,    30,    30,
    -479,   109,    38,   125,   132,  -479,  -479,   -44,  -479,  -479,
      28,   156,  -479,  -479,   124,  -479,     2,  -479,  -479,  -479,
     130,    87,   -47,   153,  -479,  -479,  -479,  -479,   549,  -479,
    1431,  -479,  -479,   237,   147,     7,  -479,   260,   -40,   220,
      36,  -479,   193,  -479,  -479,  -479,  -479,  -479,  -479,  -479,
    -479,  -479,  -479,  -479,  -479,  -479,  -479,  -479,  -479,  -479,
    -479,  -479,  -479,  -479,  -479,  -479,  -479,  -479,  -479,  -479,
    -479,  -479,   158,  -479,  -479,   162,  -479,  -479,  -479,   -18,
    -479,  -479,   149,  -479,    48,  -479,  1431,   807,  -479,   222,
    -479,   704,   270,   124,   276,  -479,   863,  -479,  -479,   -42,
     172,   -41,  -479,  1431,  -479,   252,  -479,  -479,  -479,   281,
     168,   285,   288,  -479,  1431,   215,  -479,   290,  -479,  -479,
    -479,  1431,   472,  -479,  -479,  -479,   993,    48,    48,    48,
     993,   199,  -479,   286,  -479,  -479,  -479,  -479,  -479,  -479,
     181,   230,   202,   196,   124,   206,   313,   209,  1424,   201,
     203,  -479,   216,   993,   124,   217,   225,   211,   993,   993,
     975,  -479,   212,  -479,    -9,  1327,  1030,  -479,  -479,  -479,
    -479,  -479,   223,   807,  -479,  -479,  -479,  -479,  -479,  -479,
     300,  -479,  -479,   160,  -479,  -479,  -479,  -479,  -479,  -479,
    -479,   218,   180,   180,   335,  -479,  -479,  -479,  -479,   745,
    -479,  -479,  -479,    57,  -479,    47,   198,   298,  -479,  -479,
     241,  1431,  -479,   345,   237,  -479,    19,   -17,  -479,  -479,
     244,  -479,  -479,  -479,   352,   220,   239,   -10,  -479,  -479,
    -479,  -479,  -479,  -479,   659,  -479,   247,   248,   143,  -479,
     235,   235,   235,  -479,  1124,  1408,  -479,  -479,  1066,    48,
      48,  -479,   358,  -479,  1431,   359,  -479,   297,   325,   255,
     993,  1431,   267,  -479,  -479,   993,   261,  -479,   993,   993,
    -479,   287,   287,  1163,    -6,  -479,  1431,   993,   993,   993,
     993,   993,   993,   993,   993,   993,   993,   993,   993,   993,
     993,   993,   993,   993,   993,   993,   993,   993,   993,   993,
     993,   993,   993,   993,   993,   993,   993,   993,   993,   993,
    -479,  -479,   282,   362,   300,  -479,   284,   124,   160,  -479,
    -479,   371,   343,   291,  -479,  -479,   222,   259,  -479,   -34,
     222,  -479,   180,   180,   401,  -479,  1431,  -479,  -479,  -479,
     299,  -479,  1431,   356,  1431,   302,  -479,  -479,   356,  -479,
    -479,   993,  -479,   993,  -479,  -479,    21,  -479,  -479,   294,
     338,   340,   310,   311,   -16,  -479,   312,   315,   993,   316,
    -479,  1202,   317,   309,   318,  -479,   461,   221,   221,   -46,
     -46,   -46,   -46,   461,   461,   306,   306,   823,  1488,  1458,
    1288,  1518,  1548,   287,   179,   179,  1327,  1327,  1327,  1327,
    1327,  1327,  1327,  1327,  1327,  1327,  1327,  1327,  1327,   993,
     124,  -479,  -479,  -479,   325,  -479,  -479,  -479,   427,  1431,
     323,   319,   326,  -479,  -479,   320,   371,   381,   -73,   364,
    -479,    42,   993,  -479,   327,   328,    50,   993,   330,  -479,
    -479,  -479,  -479,  -479,   336,   208,   993,   124,   993,   993,
     124,   993,  -479,    51,  -479,   431,  -479,   124,   993,  1343,
     337,  -479,   339,   342,   445,  -479,  -479,   450,  -479,   451,
    1431,  -479,   401,   356,  -479,   993,  1343,   356,  -479,  1343,
     993,  -479,   161,  1431,  -479,   346,  -479,  -479,   124,   420,
    -479,   350,  -479,  -479,   344,  -479,    55,   993,  -479,   993,
     435,   431,  -479,  -479,  1085,   355,  -479,   -37,  -479,   124,
     124,  1431,   353,   357,    63,  -479,   365,   464,  -479,   361,
     363,   394,   366,   394,  1241,   368,  1431,   360,  -479,   124,
    -479,   993,  -479,   369,   370,   372,  -479,  -479,  -479,   993,
     993,  1343,   124,  -479,  -479,    89,     6,   993,   450,  -479,
    1431,   373,  1343,  -479,  1343,  -479,  1431,    92,  -479,  -479,
    -479,  -479,   124,   124,  1327,   379,  -479,  -479,   356,   383,
     384,   382,   437,   465,  1327,  -479,    93,     6,   394,   394,
     104,   356,   170,   170,  -479,  -479,   390,   396,   391,  -479,
    -479,   356,   392,   356,   400,  -479,  -479,   -53,   136,  -479,
    -479,   397,   403,  1343,   507,  -479,   517,  -479,  -479,  1343,
     394,   407,   412,   394,  -479,  -479
  };

  const short
  parser::yydefact_[] =
  {
       3,    13,    14,    15,    20,     0,     0,    19,     0,     0,
      17,   175,    18,     0,     0,   177,   178,   176,     0,     0,
      16,     0,     0,     0,   300,     5,     6,     8,     7,   324,
       0,     0,   174,   246,     0,   247,     0,   323,   326,   325,
       0,     0,     0,   296,   320,   321,   322,   327,     2,   318,
       0,    12,     4,     0,     0,   190,   303,     0,     0,     0,
       0,   242,     0,   226,   224,   210,   211,   213,   214,   212,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   227,
     225,   229,   230,   228,   232,   231,   233,   235,   234,   236,
     237,   238,     0,   241,   243,     0,    24,    25,   298,     0,
       1,   299,     0,     9,     0,   168,     0,   117,   181,     0,
     206,     0,     0,     0,     0,   295,     0,   319,    22,     0,
     251,     0,   249,     0,   185,   186,   184,   188,   189,     0,
       0,     0,     0,   306,     0,   169,   170,     0,   301,   239,
     240,     0,   175,    10,    76,    77,    29,     0,     0,     0,
       0,     0,    87,     0,    89,    88,    90,    91,    93,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,    26,    74,     0,    75,    32,    73,    72,
     118,   106,     0,   116,   107,   120,   121,   122,   108,   128,
     133,   129,   109,     0,   110,   111,   112,   113,   114,   245,
     244,     0,     0,   175,     0,   254,   264,   265,   269,     0,
     262,   268,   266,     0,   267,     0,     0,   255,   180,   297,
       0,     0,    21,     0,     0,   248,     0,     0,   191,   187,
       0,   307,   305,   304,     0,     0,     0,     0,   310,   317,
     315,   314,   313,   316,   175,   311,    99,     0,     0,    97,
      82,    78,    79,    74,     0,    75,    80,    81,     0,     0,
       0,    11,     0,   161,     0,     0,   162,     0,     0,     0,
       0,     0,     0,   163,   160,     0,     0,   150,     0,     0,
     165,    68,    67,     0,     0,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   119,     0,   138,   132,   134,     0,     0,   149,   151,
     207,   291,   174,     0,   253,   263,     0,     0,   282,     0,
       0,   292,     0,     0,     0,   256,     0,    23,   252,   250,
     193,   194,     0,     0,     0,   172,   171,   302,     0,   309,
     312,    29,    86,    29,    85,   102,     0,    83,    84,     0,
       0,     0,     0,     0,     0,   166,     0,     0,     0,     0,
     164,     0,     0,    85,     0,    66,    46,    34,    35,    37,
      38,    36,    39,    48,    47,    51,    50,    49,    52,    53,
      54,    56,    55,    57,    58,    59,    40,    41,    42,    43,
      44,    45,    27,    60,    61,    62,    63,    65,    64,     0,
       0,   130,   137,   135,     0,   154,   152,   290,     0,     0,
       0,     0,     0,   281,   280,     0,   291,     0,   260,   257,
     258,     0,     0,   192,   196,     0,     0,     0,     0,    28,
     100,    98,   101,   308,     0,     0,     0,     0,     0,    29,
       0,     0,   105,     0,   103,   142,    69,     0,     0,     0,
       0,   139,     0,     0,     0,   294,   283,     0,   293,     0,
       0,   261,     0,     0,   195,     0,     0,     0,   173,     0,
       0,   156,     0,     0,   157,     0,   158,   159,     0,     0,
     296,     0,   125,   127,     0,   131,     0,     0,    95,     0,
     147,   141,   143,   123,     0,     0,   200,     0,   198,     0,
       0,     0,     0,     0,     0,   287,     0,     0,   259,     0,
       0,   183,     0,   209,     0,     0,     0,     0,   203,     0,
     124,    29,    96,     0,     0,     0,   140,   146,   144,     0,
       0,     0,     0,   136,   153,     0,     0,     0,     0,   286,
       0,     0,     0,   197,     0,    70,     0,     0,   155,   202,
     126,   104,     0,     0,    71,     0,   199,    94,     0,     0,
       0,     0,   272,   273,   289,   288,     0,     0,   208,   182,
       0,     0,     0,     0,   201,   285,     0,     0,     0,   274,
     275,     0,     0,     0,     0,   145,   148,     0,     0,   271,
     284,     0,     0,     0,     0,   277,     0,   279,   270,     0,
     205,     0,     0,   204,   276,   278
  };

  const short
  parser::yypgoto_[] =
  {
    -479,  -479,     0,   516,   190,  -479,    83,  -479,  -479,  -101,
    -351,  -479,   -88,   333,   -94,  -479,    67,  -479,  -479,   163,
    -479,    66,    17,   354,   -27,  -479,  -479,  -479,  -479,  -479,
    -479,  -479,  -479,  -479,  -479,  -479,  -479,   204,  -479,  -479,
    -479,  -479,  -479,    24,  -479,  -479,  -479,  -479,  -479,   210,
    -479,  -479,  -377,  -479,   -83,  -267,  -479,   301,    -3,    -7,
    -479,    84,   -39,  -479,  -118,   188,  -364,  -478,    -2,  -479,
      43,  -479,  -479,   438,  -156,   -96,  -115,  -479,   324,   -95,
    -479,  -479,  -479,    59,  -479,   341,  -479,   -30,   -24,   -22,
    -479,  -479,  -479,  -479,     5,   129,  -479,  -479,   -99,  -479,
    -111,  -479,   167,  -479,  -113,  -479,  -479,   329,  -479,   529
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    23,   236,    25,    26,    27,    51,   119,    28,   459,
     257,   183,   263,   185,   265,   187,   188,   189,   258,   259,
     152,   473,   474,   190,   191,   192,   193,   194,   195,   196,
     197,   383,   198,   199,   200,   333,   334,   335,   431,   432,
     201,   520,   521,   522,   556,   557,   202,   203,   338,   339,
     204,   505,   205,   206,    29,    30,   135,   136,    31,    32,
     208,    33,    34,   129,   294,   238,   455,   527,   528,   507,
     508,    35,    36,    95,   211,    37,    38,   121,   122,    39,
      40,   355,   449,   450,   219,   220,   221,   591,   592,   593,
     222,   223,   349,   534,   535,   438,   224,   225,    41,    42,
      43,    44,    58,    45,    46,    47,   254,   255,    48,    49
  };

  const short
  parser::yytable_[] =
  {
      24,    55,   113,   229,   458,   237,   182,   108,    59,   110,
     151,   384,   226,   186,    94,   217,   218,    56,   541,   184,
     460,   543,   360,   247,   207,   468,   102,   251,   216,   253,
     114,   124,   -31,    53,     1,   231,   234,   303,    54,   131,
     561,    56,   589,     2,     3,   256,   250,   252,    24,     4,
     118,   144,   186,   260,   261,   262,    50,   314,   184,   249,
     362,   131,   107,     7,   624,   -31,   590,   362,   -31,   125,
     115,   362,   286,   132,    10,   235,   126,    12,   133,   186,
     562,   107,   103,   104,   443,   184,   228,    15,   232,    16,
      17,    20,   182,   363,   598,   132,   599,   142,   362,   186,
     368,   -31,   469,   -31,   394,   184,   153,   112,   109,   -31,
     207,    24,    98,   145,    24,   131,    94,   107,   514,   362,
     226,   146,     8,   217,   218,   100,    57,   362,   517,   539,
     147,   462,   517,   542,   244,   101,   216,   277,   361,   251,
     568,   253,    24,   127,   128,   630,   105,   287,   137,   132,
     376,   633,   493,   350,   138,   148,   149,   150,   250,   252,
     497,   518,   107,   346,    54,   552,   362,   482,   282,   362,
     362,   249,   107,   569,   347,   377,   378,   336,   337,   386,
      60,   362,   160,   106,   389,   545,   186,   113,   392,    99,
     441,   186,   184,   163,   445,   186,   348,   184,   351,   588,
     580,   184,   601,   611,   116,   341,   342,   166,    96,    97,
      59,   501,     1,    15,   613,    16,    17,   372,   112,    24,
     373,     2,     3,   352,   605,   615,   616,     4,   169,   170,
       5,   357,    15,     8,    16,    17,   173,   614,   451,   107,
     120,     7,   177,   502,   353,   111,   456,   620,   209,   622,
     210,   107,    10,   626,    24,    12,   123,   298,   299,   300,
     301,   302,   303,   130,    18,    19,   134,   139,   140,    20,
     546,   141,   256,   227,   380,   143,   239,   186,   233,   186,
       1,   387,   314,   184,   240,   184,   241,   472,   242,     2,
       3,   243,   245,   246,   186,     4,   395,   272,     5,   273,
     184,   300,   301,   302,   303,   274,   266,   267,   268,     7,
     435,   275,   269,   270,   276,   278,   279,   503,   280,   283,
      10,   284,   444,    12,   314,   285,   288,   271,   480,   290,
     295,   332,    18,    19,   289,   186,   340,    20,   343,   330,
     354,   184,   266,   267,   268,   446,   447,    21,   269,   270,
     356,   494,   358,   364,   510,   365,   498,   367,   186,   -28,
     371,   379,   381,   186,   184,   511,   509,   513,   382,   184,
     472,    11,   186,   385,   186,   186,   388,   186,   184,   390,
     184,   184,   297,   184,   298,   299,   300,   301,   302,   303,
     314,   429,   430,   434,   540,   437,   439,   442,   304,   305,
     440,   186,   308,   481,   448,   452,   454,   184,   457,   314,
     315,   316,   463,   565,   464,    21,   472,   465,   554,   466,
     478,   467,   470,   186,   471,   186,   475,   477,   577,   184,
     483,   184,   479,   485,   490,   487,   495,   486,   488,   484,
     512,   492,   496,   515,   499,   500,   519,   529,   532,   530,
     523,   531,   596,   533,   536,   502,   547,   186,   600,   585,
     550,   555,   551,   184,   560,    24,   186,   571,   566,   567,
     113,   561,   184,   573,   570,   572,     1,   576,   578,   526,
     574,   548,   582,   264,   583,     2,     3,   581,   597,   604,
     537,     4,   606,   607,     5,    55,   526,   590,   608,   526,
     617,   589,   563,   564,     6,     7,   618,     8,   621,   619,
     631,   291,   292,   293,   623,   628,    10,   629,    11,    12,
     632,    52,   579,    14,    15,   634,    16,    17,    18,    19,
     635,   491,   504,    20,   553,   587,   461,   516,   433,   298,
     299,   300,   301,   302,   303,   558,   366,   331,   436,   506,
     453,   538,   549,     1,   230,   602,   603,   308,   359,   586,
     345,   526,     2,     3,   314,   315,   316,   612,     4,   610,
     609,     5,   526,   595,   526,   489,  -175,   117,     0,     0,
       0,     6,     7,   370,     8,     0,     0,     0,   248,     9,
     625,   627,     0,    10,     0,    11,    12,    13,     0,     0,
      14,    15,     0,    16,    17,    18,    19,     0,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   391,     0,   526,     0,     0,     0,     0,     0,   526,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     4,     0,
       0,     5,     0,     0,     0,     0,     0,     0,    21,    22,
       0,     6,     7,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,    11,    12,     0,     1,     0,
      14,    15,     0,    16,    17,    18,    19,     2,     3,     0,
      20,     0,     0,     4,     0,     0,     5,     0,     0,   212,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     1,    10,     1,
     213,    12,     0,     0,     0,    14,     2,     3,     2,     3,
      18,    19,     4,     0,     4,    20,     0,     5,     0,     0,
     212,     0,     0,     0,     0,   369,     7,     0,     7,     0,
       8,     0,     0,     0,     0,     0,     0,    10,     0,    10,
      12,   213,    12,     0,     0,     0,    14,     0,    21,    18,
      19,    18,    19,     0,    20,     0,    20,   214,     0,     0,
     144,   524,   154,   155,   156,   157,   158,   159,     0,   160,
     215,     0,     0,   161,     0,     0,     0,     0,   162,     0,
     163,     0,     0,   544,     0,     0,   164,     0,     0,     0,
       0,   165,     0,    21,   166,     0,   167,     0,   214,     0,
       0,     0,     0,    11,     0,     0,   168,     0,     0,     0,
       0,   344,     0,     0,     0,   169,   170,     1,     0,     0,
     171,   172,   145,   173,   174,   175,     2,     3,   176,   177,
     146,     0,     4,     0,    21,     5,   178,     0,     0,   147,
       0,     0,   584,     0,     0,     0,     7,     0,     0,     0,
     594,   298,   299,   300,   301,   302,   303,    10,   179,     0,
      12,     0,    61,     0,   148,   149,   180,     0,     0,    18,
      19,     0,   107,     0,    20,   181,   314,   315,   316,     0,
       0,     0,     0,     0,     0,     0,    62,     0,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,    84,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,     0,    93,   144,     1,
     154,   155,   156,   157,   158,   159,     0,     0,     2,     3,
       0,   161,     0,     0,     4,     0,   144,     5,   154,   155,
     156,   157,   158,   159,     0,     0,     0,     0,     7,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,    12,     0,   168,     0,     0,     0,     0,     0,
       0,    18,    19,     0,     0,     0,    20,     0,   171,     0,
     145,     0,   168,   175,     0,     0,     0,     0,   146,     0,
       0,     0,     0,     0,   178,     0,   171,   147,   145,     0,
       0,   175,     0,     0,     0,     0,   146,     0,     0,     0,
       1,   -30,   178,     0,     0,   147,   179,     0,     0,     2,
       3,     0,   148,   149,   180,     4,     0,     0,     5,     0,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     7,
     148,   149,   180,     0,   -30,     0,     0,   -30,     0,     0,
      10,     0,     0,    12,     0,   317,   318,   319,   320,   321,
     322,     0,    18,    19,     0,     0,     0,    20,     0,     0,
     296,     0,     0,     0,     0,     0,   323,   266,   267,   268,
     -30,     0,   -30,   269,   270,     0,     0,     0,   -30,     0,
     324,   325,   326,   327,   328,   329,     0,     0,     0,     0,
       0,   297,     0,   298,   299,   300,   301,   302,   303,   296,
       0,     0,     0,     0,     0,     0,   375,   304,   305,   306,
     307,   308,   309,   310,   311,   312,     0,   313,   314,   315,
     316,     0,     0,     0,     0,     0,     0,   559,     0,     0,
     297,     0,   298,   299,   300,   301,   302,   303,   296,     0,
       0,     0,     0,     0,     0,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,     0,   313,   314,   315,   316,
       0,     0,     0,     0,   374,     0,     0,     0,     0,   297,
       0,   298,   299,   300,   301,   302,   303,   296,     0,     0,
       0,     0,     0,     0,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,     0,   313,   314,   315,   316,     0,
       0,     0,     0,   393,     0,     0,     0,     0,   297,     0,
     298,   299,   300,   301,   302,   303,   296,     0,     0,     0,
       0,     0,     0,     0,   304,   305,   306,   307,   308,   309,
     310,   311,   312,     0,   313,   314,   315,   316,     0,     0,
       0,     0,   476,     0,     0,     0,     0,   297,     0,   298,
     299,   300,   301,   302,   303,     0,     0,     0,     0,     0,
       0,     0,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,     0,   313,   314,   315,   316,     1,     0,     0,
       0,   575,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     0,     4,     0,   297,     5,   298,   299,   300,   301,
     302,   303,   296,     0,     0,     0,     7,     0,     0,     0,
     304,   305,   306,   307,   308,     0,     0,    10,     0,     0,
      12,   314,   315,   316,     0,     0,     0,     0,     0,    18,
      19,     0,     0,   297,    20,   298,   299,   300,   301,   302,
     303,   525,     0,     0,     0,     0,     0,     0,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,     1,   313,
     314,   315,   316,     0,     0,     1,     0,     2,     3,     0,
       0,     0,     0,     4,     2,     3,     5,     0,     0,     0,
       4,     0,     0,     5,     0,     0,     0,     7,     0,     0,
       0,     0,   281,     0,     7,     0,     0,     0,    10,     0,
       0,    12,     0,     0,     0,    10,     0,     0,    12,     0,
      18,    19,     0,     0,     0,    20,     0,    18,    19,     0,
       0,     0,    20,   317,   318,   319,   320,   321,   322,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,   267,   268,     0,     0,
       0,   269,   270,     0,     0,     0,     0,     0,   324,   325,
     326,   327,   328,   329,   297,     0,   298,   299,   300,   301,
     302,   303,     0,     0,     0,     0,     0,     0,     0,     0,
     304,   305,   306,   307,   308,   309,     0,   311,   312,     0,
     313,   314,   315,   316,   297,     0,   298,   299,   300,   301,
     302,   303,     0,     0,     0,     0,     0,     0,     0,     0,
     304,   305,   306,   307,   308,     0,     0,   311,   312,     0,
     313,   314,   315,   316,   297,     0,   298,   299,   300,   301,
     302,   303,     0,     0,     0,     0,     0,     0,     0,     0,
     304,   305,   306,   307,   308,     0,     0,   311,     0,     0,
     313,   314,   315,   316,   297,     0,   298,   299,   300,   301,
     302,   303,     0,     0,     0,     0,     0,     0,     0,     0,
     304,   305,   306,   307,   308,     0,     0,   311,     0,     0,
       0,   314,   315,   316
  };

  const short
  parser::yycheck_[] =
  {
       0,     8,    41,   114,   368,   123,   107,    34,    11,    36,
     104,   278,   111,   107,    14,   111,   111,     3,   496,   107,
     371,   499,     3,   141,   107,    41,    70,   142,   111,   142,
      77,    24,    41,   115,     4,    77,    77,    83,     3,    79,
      77,     3,    36,    13,    14,   146,   142,   142,    48,    19,
      50,     3,   146,   147,   148,   149,   129,   103,   146,   142,
      77,    79,   115,    33,   117,    74,    60,    77,    77,    62,
     117,    77,   173,   113,    44,   116,    69,    47,   118,   173,
     117,   115,   126,   127,   118,   173,   113,    52,   130,    54,
      55,    61,   193,   110,   572,   113,   574,   115,    77,   193,
     110,   110,   118,   112,   110,   193,   106,    20,   106,   118,
     193,   111,     3,    65,   114,    79,   116,   115,   469,    77,
     219,    73,    35,   219,   219,     0,   112,    77,    77,   493,
      82,   110,    77,   497,   134,     3,   219,   164,   119,   254,
      77,   254,   142,   136,   137,   623,   118,   174,   112,   113,
     268,   629,   110,   106,   118,   107,   108,   109,   254,   254,
     110,   110,   115,   106,     3,   110,    77,   434,   168,    77,
      77,   254,   115,   110,   117,   269,   270,    17,    18,   280,
      13,    77,    12,    27,   285,    24,   280,   226,   289,    22,
     346,   285,   280,    23,   350,   289,   223,   285,   225,   110,
     551,   289,   110,   110,    51,   212,   213,    37,    18,    19,
     213,     3,     4,    52,   110,    54,    55,    74,    20,   219,
      77,    13,    14,    25,   588,   602,   603,    19,    58,    59,
      22,   231,    52,    35,    54,    55,    66,   601,   356,   115,
       3,    33,    72,    35,    46,   115,   364,   611,    26,   613,
      28,   115,    44,   117,   254,    47,   109,    78,    79,    80,
      81,    82,    83,     3,    56,    57,    46,    74,   110,    61,
     109,   109,   373,     3,   274,   126,    24,   371,   106,   373,
       4,   281,   103,   371,     3,   373,   118,   388,     3,    13,
      14,     3,    77,     3,   388,    19,   296,    11,    22,   118,
     388,    80,    81,    82,    83,    75,   107,   108,   109,    33,
     337,   109,   113,   114,   118,   109,     3,   109,   109,   118,
      44,   118,   349,    47,   103,   109,   109,   128,   429,   118,
     118,    31,    56,    57,   109,   429,   118,    61,     3,   116,
      42,   429,   107,   108,   109,   352,   353,   139,   113,   114,
     109,   452,     7,   109,   465,     3,   457,   118,   452,   112,
     112,     3,     3,   457,   452,   466,   465,   468,    71,   457,
     471,    46,   466,   118,   468,   469,   109,   471,   466,   118,
     468,   469,    76,   471,    78,    79,    80,    81,    82,    83,
     103,   109,    30,   109,   495,    24,    53,   138,    92,    93,
     109,   495,    96,   430,     3,   106,    50,   495,   106,   103,
     104,   105,   118,   531,    76,   139,   517,    77,   519,   109,
     111,   110,   110,   517,   109,   519,   110,   110,   546,   517,
       3,   519,   114,   110,    53,   109,   109,   118,   118,   439,
     467,    77,   114,   470,   114,   109,    15,   110,     3,   110,
     477,   109,   570,     3,     3,    35,   110,   551,   576,   560,
     110,    26,   118,   551,   109,   465,   560,     3,   115,   112,
     509,    77,   560,   110,   109,   114,     4,   109,   118,   479,
     114,   508,   112,   150,   112,    13,    14,   118,   115,   110,
     490,    19,   109,   109,    22,   502,   496,    60,   116,   499,
     110,    36,   529,   530,    32,    33,   110,    35,   116,   118,
       3,   178,   179,   180,   114,   118,    44,   114,    46,    47,
       3,     5,   549,    51,    52,   118,    54,    55,    56,    57,
     118,   448,   465,    61,   517,   562,   373,   471,   334,    78,
      79,    80,    81,    82,    83,   521,   245,   193,   338,   465,
     362,   492,   509,     4,   116,   582,   583,    96,   234,   561,
     219,   561,    13,    14,   103,   104,   105,   597,    19,   593,
     592,    22,   572,   568,   574,   446,    27,    48,    -1,    -1,
      -1,    32,    33,   254,    35,    -1,    -1,    -1,   116,    40,
     617,   618,    -1,    44,    -1,    46,    47,    48,    -1,    -1,
      51,    52,    -1,    54,    55,    56,    57,    -1,    -1,    -1,
      61,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   288,    -1,   623,    -1,    -1,    -1,    -1,    -1,   629,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    46,    47,    -1,     4,    -1,
      51,    52,    -1,    54,    55,    56,    57,    13,    14,    -1,
      61,    -1,    -1,    19,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    44,     4,
      46,    47,    -1,    -1,    -1,    51,    13,    14,    13,    14,
      56,    57,    19,    -1,    19,    61,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,   116,    33,    -1,    33,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    44,
      47,    46,    47,    -1,    -1,    -1,    51,    -1,   139,    56,
      57,    56,    57,    -1,    61,    -1,    61,   103,    -1,    -1,
       3,   478,     5,     6,     7,     8,     9,    10,    -1,    12,
     116,    -1,    -1,    16,    -1,    -1,    -1,    -1,    21,    -1,
      23,    -1,    -1,   500,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    34,    -1,   139,    37,    -1,    39,    -1,   103,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    58,    59,     4,    -1,    -1,
      63,    64,    65,    66,    67,    68,    13,    14,    71,    72,
      73,    -1,    19,    -1,   139,    22,    79,    -1,    -1,    82,
      -1,    -1,   559,    -1,    -1,    -1,    33,    -1,    -1,    -1,
     567,    78,    79,    80,    81,    82,    83,    44,   101,    -1,
      47,    -1,    49,    -1,   107,   108,   109,    -1,    -1,    56,
      57,    -1,   115,    -1,    61,   118,   103,   104,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    99,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,   114,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    14,
      -1,    16,    -1,    -1,    19,    -1,     3,    22,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    33,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    -1,    -1,    61,    -1,    63,    -1,
      65,    -1,    49,    68,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    63,    82,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
       4,    41,    79,    -1,    -1,    82,   101,    -1,    -1,    13,
      14,    -1,   107,   108,   109,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    33,
     107,   108,   109,    -1,    74,    -1,    -1,    77,    -1,    -1,
      44,    -1,    -1,    47,    -1,    85,    86,    87,    88,    89,
      90,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
     110,    -1,   112,   113,   114,    -1,    -1,    -1,   118,    -1,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    79,    80,    81,    82,    83,    45,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      76,    -1,    78,    79,    80,    81,    82,    83,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,   105,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    76,
      -1,    78,    79,    80,    81,    82,    83,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,   105,    -1,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    76,    -1,
      78,    79,    80,    81,    82,    83,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,   102,   103,   104,   105,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,   102,   103,   104,   105,     4,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,    19,    -1,    76,    22,    78,    79,    80,    81,
      82,    83,    45,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    -1,    -1,    44,    -1,    -1,
      47,   103,   104,   105,    -1,    -1,    -1,    -1,    -1,    56,
      57,    -1,    -1,    76,    61,    78,    79,    80,    81,    82,
      83,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,     4,   102,
     103,   104,   105,    -1,    -1,     4,    -1,    13,    14,    -1,
      -1,    -1,    -1,    19,    13,    14,    22,    -1,    -1,    -1,
      19,    -1,    -1,    22,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    38,    -1,    33,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,
      56,    57,    -1,    -1,    -1,    61,    -1,    56,    57,    -1,
      -1,    -1,    61,    85,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,   113,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,    76,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    -1,    99,   100,    -1,
     102,   103,   104,   105,    76,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    -1,    -1,    99,   100,    -1,
     102,   103,   104,   105,    76,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    -1,    -1,    99,    -1,    -1,
     102,   103,   104,   105,    76,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    -1,    -1,    99,    -1,    -1,
      -1,   103,   104,   105
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,    13,    14,    19,    22,    32,    33,    35,    40,
      44,    46,    47,    48,    51,    52,    54,    55,    56,    57,
      61,   139,   140,   142,   143,   144,   145,   146,   149,   195,
     196,   199,   200,   202,   203,   212,   213,   216,   217,   220,
     221,   239,   240,   241,   242,   244,   245,   246,   249,   250,
     129,   147,   144,   115,     3,   200,     3,   112,   243,   199,
     243,    49,    73,    75,    76,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    99,   102,   103,   104,   105,   106,
     107,   108,   109,   114,   143,   214,   145,   145,     3,   243,
       0,     3,    70,   126,   127,   118,    27,   115,   165,   106,
     165,   115,    20,   203,    77,   117,    51,   250,   143,   148,
       3,   218,   219,   109,    24,    62,    69,   136,   137,   204,
       3,    79,   113,   118,    46,   197,   198,   112,   118,    74,
     110,   109,   115,   126,     3,    65,    73,    82,   107,   108,
     109,   155,   161,   143,     5,     6,     7,     8,     9,    10,
      12,    16,    21,    23,    29,    34,    37,    39,    49,    58,
      59,    63,    64,    66,    67,    68,    71,    72,    79,   101,
     109,   118,   150,   152,   153,   154,   155,   156,   157,   158,
     164,   165,   166,   167,   168,   169,   170,   171,   173,   174,
     175,   181,   187,   188,   191,   193,   194,   195,   201,    26,
      28,   215,    25,    46,   103,   116,   195,   216,   220,   225,
     226,   227,   231,   232,   237,   238,   239,     3,   165,   241,
     214,    77,   130,   106,    77,   116,   143,   205,   206,    24,
       3,   118,     3,     3,   143,    77,     3,   205,   116,   195,
     216,   217,   220,   245,   247,   248,   150,   151,   159,   160,
     155,   155,   155,   153,   154,   155,   107,   108,   109,   113,
     114,   128,    11,   118,    75,   109,   118,   165,   109,     3,
     109,    38,   143,   118,   118,   109,   150,   165,   109,   109,
     118,   154,   154,   154,   205,   118,    45,    76,    78,    79,
      80,    81,    82,    83,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   102,   103,   104,   105,    85,    86,    87,
      88,    89,    90,   106,   120,   121,   122,   123,   124,   125,
     116,   164,    31,   176,   177,   178,    17,    18,   189,   190,
     118,   200,   200,     3,   116,   226,   106,   117,   165,   233,
     106,   165,    25,    46,    42,   222,   109,   143,     7,   219,
       3,   119,    77,   110,   109,     3,   198,   118,   110,   116,
     248,   112,    74,    77,   110,   110,   205,   155,   155,     3,
     143,     3,    71,   172,   196,   118,   150,   143,   109,   150,
     118,   154,   150,   110,   110,   143,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   109,
      30,   179,   180,   178,   109,   165,   190,    24,   236,    53,
     109,   215,   138,   118,   165,   215,   200,   200,     3,   223,
     224,   205,   106,   206,    50,   207,   205,   106,   207,   150,
     151,   160,   110,   118,    76,    77,   109,   110,    41,   118,
     110,   109,   150,   162,   163,   110,   110,   110,   111,   114,
     150,   165,   196,     3,   143,   110,   118,   109,   118,   236,
      53,   147,    77,   110,   150,   109,   114,   110,   150,   114,
     109,     3,    35,   109,   157,   192,   202,   210,   211,   239,
     241,   150,   165,   150,   151,   165,   162,    77,   110,    15,
     182,   183,   184,   165,   154,    68,   143,   208,   209,   110,
     110,   109,     3,     3,   234,   235,     3,   143,   224,   207,
     150,   208,   207,   208,   154,    24,   109,   110,   165,   211,
     110,   118,   110,   163,   150,    26,   185,   186,   184,   112,
     109,    77,   117,   165,   165,   205,   115,   112,    77,   110,
     109,     3,   114,   110,   114,   110,   109,   205,   118,   165,
     151,   118,   112,   112,   154,   150,   209,   165,   110,    36,
      60,   228,   229,   230,   154,   235,   205,   115,   208,   208,
     205,   110,   165,   165,   110,   207,   109,   109,   116,   230,
     229,   110,   228,   110,   207,   193,   193,   110,   110,   118,
     207,   116,   207,   114,   117,   165,   117,   165,   118,   114,
     208,     3,     3,   208,   118,   118
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   141,   142,   142,   143,   143,   144,   144,   145,   145,
     145,   145,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   147,   148,   148,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   154,   154,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   156,   156,
     156,   156,   156,   156,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   165,   166,   166,   167,   167,
     168,   168,   168,   169,   170,   171,   172,   172,   173,   173,
     174,   175,   176,   176,   177,   177,   178,   179,   179,   180,
     181,   182,   182,   183,   183,   184,   185,   185,   186,   187,
     188,   189,   189,   190,   190,   191,   192,   192,   192,   192,
     193,   193,   193,   193,   193,   193,   193,   194,   195,   196,
     197,   197,   198,   198,   199,   199,   200,   200,   200,   201,
     202,   202,   203,   203,   204,   204,   204,   204,   204,   204,
     204,   205,   205,   206,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   210,   211,   211,   212,   212,   213,   213,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   215,   215,   216,   216,   217,   218,
     218,   219,   219,   220,   220,   221,   221,   222,   223,   223,
     224,   224,   225,   225,   226,   226,   226,   226,   226,   226,
     227,   227,   228,   228,   228,   228,   229,   229,   230,   230,
     231,   231,   231,   231,   232,   232,   233,   234,   234,   235,
     236,   236,   237,   237,   238,   239,   240,   240,   241,   241,
     241,   242,   242,   243,   243,   243,   244,   244,   245,   246,
     246,   247,   247,   248,   248,   248,   248,   248,   249,   249,
     250,   250,   250,   250,   250,   250,   250,   250
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
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       7,     7,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     7,     5,     6,     1,     3,     1,
       3,     4,     3,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     1,     2,
       1,     1,     1,     5,     6,     5,     5,     3,     1,     1,
       3,     5,     1,     0,     1,     2,     5,     1,     0,     2,
       6,     1,     0,     1,     2,     5,     1,     0,     4,     2,
       2,     1,     2,     5,     2,     7,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     2,     3,     2,     2,     3,
       1,     3,     3,     5,     1,     0,     1,     1,     1,     1,
       3,     2,    10,     8,     1,     1,     1,     2,     1,     1,
       0,     1,     3,     2,     2,     4,     1,     4,     1,     3,
       1,     4,     3,     2,     8,     7,     2,     4,     9,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     1,     3,     4,     3,     3,     4,     2,     1,     3,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
      10,     9,     1,     1,     2,     2,     6,     4,     6,     4,
       3,     3,     2,     4,     9,     8,     5,     1,     3,     3,
       1,     0,     2,     4,     4,     2,     1,     3,     2,     2,
       1,     3,     5,     1,     3,     3,     3,     4,     6,     5,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    75,    75,    75,    80,    81,    84,    84,    87,    88,
      89,    90,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   104,   107,   108,   111,   112,   117,   118,   121,   122,
     125,   126,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   173,   174,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   191,   192,
     193,   194,   195,   196,   199,   202,   203,   206,   207,   210,
     211,   214,   215,   218,   219,   222,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   238,   241,   242,   245,   246,
     249,   250,   251,   254,   257,   260,   263,   264,   267,   268,
     271,   274,   277,   278,   281,   282,   285,   288,   289,   292,
     295,   298,   299,   302,   303,   306,   309,   310,   313,   316,
     319,   322,   323,   326,   327,   330,   333,   334,   335,   336,
     339,   340,   341,   342,   343,   344,   345,   348,   351,   354,
     357,   358,   361,   362,   364,   365,   368,   368,   368,   371,
     376,   377,   380,   381,   384,   385,   386,   387,   388,   389,
     390,   393,   394,   397,   398,   399,   402,   403,   406,   407,
     410,   411,   414,   415,   418,   419,   422,   423,   426,   427,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   432,
     432,   432,   432,   432,   435,   435,   438,   439,   444,   447,
     448,   451,   452,   457,   458,   461,   462,   465,   467,   468,
     471,   472,   475,   476,   479,   480,   481,   482,   483,   484,
     487,   488,   491,   492,   493,   494,   497,   498,   501,   502,
     504,   505,   506,   507,   510,   511,   514,   517,   518,   521,
     524,   525,   528,   529,   531,   536,   539,   540,   543,   544,
     545,   554,   555,   558,   559,   560,   563,   564,   567,   570,
     571,   574,   575,   578,   579,   580,   581,   582,   587,   588,
     591,   592,   593,   594,   595,   596,   597,   598
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
#line 1927 "Parser/Arbor_parser.tab.cc"

#line 600 "parser.yy"
