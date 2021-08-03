// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file Parser/Arbor_parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_ARBOR_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_ARBOR_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 17 "parser.yy"

    #include <string>

#line 53 "Parser/Arbor_parser.tab.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 182 "Parser/Arbor_parser.tab.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // BOOL
      char dummy1[sizeof (bool)];

      // FLOAT
      char dummy2[sizeof (double)];

      // INT
      char dummy3[sizeof (int)];

      // IDENTIFIER
      // TYPENAME
      // CHAR
      // STRING
      char dummy4[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 1,                   // error
    YYUNDEF = 2,                   // "invalid token"
    IDENTIFIER = 3,                // IDENTIFIER
    TYPENAME = 4,                  // TYPENAME
    NPTR = 5,                      // NPTR
    BOOL = 6,                      // BOOL
    INT = 7,                       // INT
    FLOAT = 8,                     // FLOAT
    CHAR = 9,                      // CHAR
    STRING = 10,                   // STRING
    AS = 11,                       // "as"
    BREAK = 12,                    // "break"
    BIT = 13,                      // "bit"
    BOOLT = 14,                    // "bool"
    CASE = 15,                     // "case"
    CASTAS = 16,                   // "castas"
    CATCH = 17,                    // "catch"
    CATCH_ALL = 18,                // "catch-all"
    CHART = 19,                    // "char"
    CLASS = 20,                    // "class"
    CLEANUP = 21,                  // "cleanup"
    CONST = 22,                    // "const"
    CONTINUE = 23,                 // "continue"
    COMPEVAL = 24,                 // "compeval"
    CTOR = 25,                     // "ctor"
    DEFAULT = 26,                  // "default"
    DEFINE = 27,                   // "define"
    DELETE = 28,                   // "delete"
    DO = 29,                       // "do"
    ELSE = 30,                     // "else"
    ELSEIF = 31,                   // "else-if"
    ENUM = 32,                     // "enum"
    FLOATT = 33,                   // "float"
    FOR = 34,                      // "for"
    FUNC = 35,                     // "func"
    GET = 36,                      // "get"
    GOTO = 37,                     // "goto"
    HEAP = 38,                     // "heap"
    IF = 39,                       // "if"
    IMPORT = 40,                   // "import"
    IN = 41,                       // "in"
    INHERITS = 42,                 // "inherits"
    INITIALIZE = 43,               // "initialize"
    INTT = 44,                     // "int"
    IS = 45,                       // "is"
    LET = 46,                      // "let"
    LONG = 47,                     // "long"
    MODULE = 48,                   // "module"
    NEW = 49,                      // "new"
    NOTHROWABLE = 50,              // "nothrowable"
    OPERATOR = 51,                 // "operator"
    PRIVATE = 52,                  // "private"
    PROPERTY = 53,                 // "property"
    PROTECTED = 54,                // "protected"
    PUBLIC = 55,                   // "public"
    REF = 56,                      // "ref"
    RREF = 57,                     // "rref"
    RETHROW = 58,                  // "rethrow"
    RETURN = 59,                   // "return"
    SET = 60,                      // "set"
    SHORT = 61,                    // "short"
    STATIC = 62,                   // "static"
    SUPER = 63,                    // "super"
    SWITCH = 64,                   // "switch"
    THIS = 65,                     // "this"
    THROW = 66,                    // "throw"
    TRY = 67,                      // "try"
    TYPEOF = 68,                   // "typeof"
    VIRTUAL = 69,                  // "virtual"
    WEAK = 70,                     // "weak"
    WHILE = 71,                    // "while"
    YIELD = 72,                    // "yield"
    LBRAC = 73,                    // "["
    RBRAC = 74,                    // "]"
    GT = 75,                       // "<"
    LT = 76,                       // ">"
    COMMA = 77,                    // ","
    PLUS = 78,                     // "+"
    MINUS = 79,                    // "-"
    SLASH = 80,                    // "/"
    SLASHSLASH = 81,               // "//"
    STAR = 82,                     // "*"
    CARROTCARROT = 83,             // "^^"
    PERCENT = 84,                  // "%"
    PLUS_EQ = 85,                  // "+="
    MINUS_EQ = 86,                 // "-="
    STAR_EQ = 87,                  // "*="
    SLASH_EQ = 88,                 // "/="
    SLASHSLASH_EQ = 89,            // "//="
    CARROTCARROT_EQ = 90,          // "^^="
    PERCENT_EQ = 91,               // "%="
    LEQ = 92,                      // "<="
    GEQ = 93,                      // ">="
    EQ = 94,                       // "=="
    NEQ = 95,                      // "!="
    SPACESHIP = 96,                // "<=>"
    AND = 97,                      // "&&"
    OR = 98,                       // "||"
    AMP = 99,                      // "&"
    PIP = 100,                     // "|"
    EXCLAMATION = 101,             // "!"
    CARROT = 102,                  // "^"
    TILDE = 103,                   // "~"
    RIGHT_SHIFT = 104,             // ">>"
    LEFT_SHIFT = 105,              // "<<"
    ASSIGN = 106,                  // "="
    PLUSPLUS = 107,                // "++"
    MINUSMINUS = 108,              // "--"
    LPAR = 109,                    // "("
    RPAR = 110,                    // ")"
    QUESTION = 111,                // "?"
    COLON = 112,                   // ":"
    DOT = 113,                     // "."
    ARROW1 = 114,                  // "->"
    LBRACE = 115,                  // "{"
    RBRACE = 116,                  // "}"
    ARROW2 = 117,                  // "=>"
    SEMICOLON = 118,               // ";"
    DOTS = 119,                    // "..."
    AMPEQ = 120,                   // "&="
    CARROTEQ = 121,                // "^="
    PIPEQ = 122,                   // "|="
    TILDEEQ = 123,                 // "~="
    LEFTEQ = 124,                  // "<<="
    RIGHTEQ = 125,                 // ">>="
    POINTER_TYPE = 126,            // POINTER_TYPE
    ARRAYL = 127,                  // ARRAYL
    ARRAYR = 128,                  // ARRAYR
    T_BEGIN = 129,                 // T_BEGIN
    T_END = 130,                   // T_END
    UMINUS = 131,                  // UMINUS
    POSTINC = 132,                 // POSTINC
    POSTDEC = 133,                 // POSTDEC
    TERN = 134,                    // TERN
    DEREF = 135                    // DEREF
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 138, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_IDENTIFIER = 3,                        // IDENTIFIER
        S_TYPENAME = 4,                          // TYPENAME
        S_NPTR = 5,                              // NPTR
        S_BOOL = 6,                              // BOOL
        S_INT = 7,                               // INT
        S_FLOAT = 8,                             // FLOAT
        S_CHAR = 9,                              // CHAR
        S_STRING = 10,                           // STRING
        S_AS = 11,                               // "as"
        S_BREAK = 12,                            // "break"
        S_BIT = 13,                              // "bit"
        S_BOOLT = 14,                            // "bool"
        S_CASE = 15,                             // "case"
        S_CASTAS = 16,                           // "castas"
        S_CATCH = 17,                            // "catch"
        S_CATCH_ALL = 18,                        // "catch-all"
        S_CHART = 19,                            // "char"
        S_CLASS = 20,                            // "class"
        S_CLEANUP = 21,                          // "cleanup"
        S_CONST = 22,                            // "const"
        S_CONTINUE = 23,                         // "continue"
        S_COMPEVAL = 24,                         // "compeval"
        S_CTOR = 25,                             // "ctor"
        S_DEFAULT = 26,                          // "default"
        S_DEFINE = 27,                           // "define"
        S_DELETE = 28,                           // "delete"
        S_DO = 29,                               // "do"
        S_ELSE = 30,                             // "else"
        S_ELSEIF = 31,                           // "else-if"
        S_ENUM = 32,                             // "enum"
        S_FLOATT = 33,                           // "float"
        S_FOR = 34,                              // "for"
        S_FUNC = 35,                             // "func"
        S_GET = 36,                              // "get"
        S_GOTO = 37,                             // "goto"
        S_HEAP = 38,                             // "heap"
        S_IF = 39,                               // "if"
        S_IMPORT = 40,                           // "import"
        S_IN = 41,                               // "in"
        S_INHERITS = 42,                         // "inherits"
        S_INITIALIZE = 43,                       // "initialize"
        S_INTT = 44,                             // "int"
        S_IS = 45,                               // "is"
        S_LET = 46,                              // "let"
        S_LONG = 47,                             // "long"
        S_MODULE = 48,                           // "module"
        S_NEW = 49,                              // "new"
        S_NOTHROWABLE = 50,                      // "nothrowable"
        S_OPERATOR = 51,                         // "operator"
        S_PRIVATE = 52,                          // "private"
        S_PROPERTY = 53,                         // "property"
        S_PROTECTED = 54,                        // "protected"
        S_PUBLIC = 55,                           // "public"
        S_REF = 56,                              // "ref"
        S_RREF = 57,                             // "rref"
        S_RETHROW = 58,                          // "rethrow"
        S_RETURN = 59,                           // "return"
        S_SET = 60,                              // "set"
        S_SHORT = 61,                            // "short"
        S_STATIC = 62,                           // "static"
        S_SUPER = 63,                            // "super"
        S_SWITCH = 64,                           // "switch"
        S_THIS = 65,                             // "this"
        S_THROW = 66,                            // "throw"
        S_TRY = 67,                              // "try"
        S_TYPEOF = 68,                           // "typeof"
        S_VIRTUAL = 69,                          // "virtual"
        S_WEAK = 70,                             // "weak"
        S_WHILE = 71,                            // "while"
        S_YIELD = 72,                            // "yield"
        S_LBRAC = 73,                            // "["
        S_RBRAC = 74,                            // "]"
        S_GT = 75,                               // "<"
        S_LT = 76,                               // ">"
        S_COMMA = 77,                            // ","
        S_PLUS = 78,                             // "+"
        S_MINUS = 79,                            // "-"
        S_SLASH = 80,                            // "/"
        S_SLASHSLASH = 81,                       // "//"
        S_STAR = 82,                             // "*"
        S_CARROTCARROT = 83,                     // "^^"
        S_PERCENT = 84,                          // "%"
        S_PLUS_EQ = 85,                          // "+="
        S_MINUS_EQ = 86,                         // "-="
        S_STAR_EQ = 87,                          // "*="
        S_SLASH_EQ = 88,                         // "/="
        S_SLASHSLASH_EQ = 89,                    // "//="
        S_CARROTCARROT_EQ = 90,                  // "^^="
        S_PERCENT_EQ = 91,                       // "%="
        S_LEQ = 92,                              // "<="
        S_GEQ = 93,                              // ">="
        S_EQ = 94,                               // "=="
        S_NEQ = 95,                              // "!="
        S_SPACESHIP = 96,                        // "<=>"
        S_AND = 97,                              // "&&"
        S_OR = 98,                               // "||"
        S_AMP = 99,                              // "&"
        S_PIP = 100,                             // "|"
        S_EXCLAMATION = 101,                     // "!"
        S_CARROT = 102,                          // "^"
        S_TILDE = 103,                           // "~"
        S_RIGHT_SHIFT = 104,                     // ">>"
        S_LEFT_SHIFT = 105,                      // "<<"
        S_ASSIGN = 106,                          // "="
        S_PLUSPLUS = 107,                        // "++"
        S_MINUSMINUS = 108,                      // "--"
        S_LPAR = 109,                            // "("
        S_RPAR = 110,                            // ")"
        S_QUESTION = 111,                        // "?"
        S_COLON = 112,                           // ":"
        S_DOT = 113,                             // "."
        S_ARROW1 = 114,                          // "->"
        S_LBRACE = 115,                          // "{"
        S_RBRACE = 116,                          // "}"
        S_ARROW2 = 117,                          // "=>"
        S_SEMICOLON = 118,                       // ";"
        S_DOTS = 119,                            // "..."
        S_AMPEQ = 120,                           // "&="
        S_CARROTEQ = 121,                        // "^="
        S_PIPEQ = 122,                           // "|="
        S_TILDEEQ = 123,                         // "~="
        S_LEFTEQ = 124,                          // "<<="
        S_RIGHTEQ = 125,                         // ">>="
        S_POINTER_TYPE = 126,                    // POINTER_TYPE
        S_ARRAYL = 127,                          // ARRAYL
        S_ARRAYR = 128,                          // ARRAYR
        S_T_BEGIN = 129,                         // T_BEGIN
        S_T_END = 130,                           // T_END
        S_UMINUS = 131,                          // UMINUS
        S_POSTINC = 132,                         // POSTINC
        S_POSTDEC = 133,                         // POSTDEC
        S_TERN = 134,                            // TERN
        S_DEREF = 135,                           // DEREF
        S_136_initailize_ = 136,                 // "initailize"
        S_137_namespace_ = 137,                  // "namespace"
        S_YYACCEPT = 138,                        // $accept
        S_start = 139,                           // start
        S_type = 140,                            // type
        S_type_root = 141,                       // type_root
        S_non_reference_type = 142,              // non_reference_type
        S_type_core = 143,                       // type_core
        S_type_template_paramaters = 144,        // type_template_paramaters
        S_type_list = 145,                       // type_list
        S_reference_type = 146,                  // reference_type
        S_expression = 147,                      // expression
        S_expression0 = 148,                     // expression0
        S_assignment_arg_expression = 149,       // assignment_arg_expression
        S_prvalue_expression = 150,              // prvalue_expression
        S_rvalue_expression = 151,               // rvalue_expression
        S_xvalue_expression = 152,               // xvalue_expression
        S_literal = 153,                         // literal
        S_lambda_expression = 154,               // lambda_expression
        S_new_expression = 155,                  // new_expression
        S_array_index_list = 156,                // array_index_list
        S_array_index = 157,                     // array_index
        S_function_call = 158,                   // function_call
        S_function_call_list = 159,              // function_call_list
        S_function_call_arg = 160,               // function_call_arg
        S_statement = 161,                       // statement
        S_block_statement = 162,                 // block_statement
        S_statements0 = 163,                     // statements0
        S_statements = 164,                      // statements
        S_loop_statement = 165,                  // loop_statement
        S_while_loop_statement = 166,            // while_loop_statement
        S_do_loop_statement = 167,               // do_loop_statement
        S_for_loop_statement = 168,              // for_loop_statement
        S_for_loop_condition = 169,              // for_loop_condition
        S_conditional_statement = 170,           // conditional_statement
        S_if_statement_sequence = 171,           // if_statement_sequence
        S_if_statement = 172,                    // if_statement
        S_else_if_statements0 = 173,             // else_if_statements0
        S_else_if_statements = 174,              // else_if_statements
        S_else_if_statement = 175,               // else_if_statement
        S_else_statement0 = 176,                 // else_statement0
        S_else_statement = 177,                  // else_statement
        S_switch_statement = 178,                // switch_statement
        S_case_blocks0 = 179,                    // case_blocks0
        S_case_blocks = 180,                     // case_blocks
        S_case_block = 181,                      // case_block
        S_default_block0 = 182,                  // default_block0
        S_default_block = 183,                   // default_block
        S_exception_statement = 184,             // exception_statement
        S_try_block = 185,                       // try_block
        S_catch_blocks = 186,                    // catch_blocks
        S_catch_block = 187,                     // catch_block
        S_clean_up_statement = 188,              // clean_up_statement
        S_clean_up_arg = 189,                    // clean_up_arg
        S_jump_statement = 190,                  // jump_statement
        S_expression_statement = 191,            // expression_statement
        S_variable_declaration_statement = 192,  // variable_declaration_statement
        S_variable_declaration = 193,            // variable_declaration
        S_variable_declaration_block_list = 194, // variable_declaration_block_list
        S_variable_declaration_block = 195,      // variable_declaration_block
        S_access_modifier0 = 196,                // access_modifier0
        S_access_modifier = 197,                 // access_modifier
        S_no_op_statement = 198,                 // no_op_statement
        S_function = 199,                        // function
        S_function_header = 200,                 // function_header
        S_function_modifiers = 201,              // function_modifiers
        S_function_argument_list = 202,          // function_argument_list
        S_function_argument = 203,               // function_argument
        S_throwable_expression = 204,            // throwable_expression
        S_return_types_list = 205,               // return_types_list
        S_return_type = 206,                     // return_type
        S_anonymous_function = 207,              // anonymous_function
        S_anonymous_function_header = 208,       // anonymous_function_header
        S_operator_overload = 209,               // operator_overload
        S_operator_overload_header = 210,        // operator_overload_header
        S_operator = 211,                        // operator
        S_function_options = 212,                // function_options
        S_callable = 213,                        // callable
        S_enum = 214,                            // enum
        S_enum_members_list = 215,               // enum_members_list
        S_enum_member = 216,                     // enum_member
        S_class = 217,                           // class
        S_class_header = 218,                    // class_header
        S_inheritance = 219,                     // inheritance
        S_class_names_list = 220,                // class_names_list
        S_class_name = 221,                      // class_name
        S_class_statements = 222,                // class_statements
        S_class_statement = 223,                 // class_statement
        S_property = 224,                        // property
        S_property_blocks = 225,                 // property_blocks
        S_get_block = 226,                       // get_block
        S_set_block = 227,                       // set_block
        S_constructor = 228,                     // constructor
        S_constructor_header = 229,              // constructor_header
        S_initializer_list = 230,                // initializer_list
        S_initializer_blocks_list = 231,         // initializer_blocks_list
        S_initializer_block = 232,               // initializer_block
        S_compeval0 = 233,                       // compeval0
        S_destructor = 234,                      // destructor
        S_destructor_header = 235,               // destructor_header
        S_module = 236,                          // module
        S_module_name = 237,                     // module_name
        S_import = 238,                          // import
        S_type_definition = 239,                 // type_definition
        S_namespace = 240,                       // namespace
        S_namespace_units = 241,                 // namespace_units
        S_namespace_unit = 242,                  // namespace_unit
        S_program_units = 243,                   // program_units
        S_program_unit = 244                     // program_unit
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_BOOL: // BOOL
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.template destroy< double > ();
        break;

      case symbol_kind::S_INT: // INT
        value.template destroy< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_STRING: // STRING
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const double& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    parser (Arbor::FE::parse_context& pc_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPENAME (std::string v, location_type l)
      {
        return symbol_type (token::TYPENAME, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPENAME (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TYPENAME, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NPTR (location_type l)
      {
        return symbol_type (token::NPTR, std::move (l));
      }
#else
      static
      symbol_type
      make_NPTR (const location_type& l)
      {
        return symbol_type (token::NPTR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (bool v, location_type l)
      {
        return symbol_type (token::BOOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL (const bool& v, const location_type& l)
      {
        return symbol_type (token::BOOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (int v, location_type l)
      {
        return symbol_type (token::INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const int& v, const location_type& l)
      {
        return symbol_type (token::INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (double v, location_type l)
      {
        return symbol_type (token::FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const double& v, const location_type& l)
      {
        return symbol_type (token::FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR (std::string v, location_type l)
      {
        return symbol_type (token::CHAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::CHAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AS (location_type l)
      {
        return symbol_type (token::AS, std::move (l));
      }
#else
      static
      symbol_type
      make_AS (const location_type& l)
      {
        return symbol_type (token::AS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT (location_type l)
      {
        return symbol_type (token::BIT, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT (const location_type& l)
      {
        return symbol_type (token::BIT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLT (location_type l)
      {
        return symbol_type (token::BOOLT, std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLT (const location_type& l)
      {
        return symbol_type (token::BOOLT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (location_type l)
      {
        return symbol_type (token::CASE, std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const location_type& l)
      {
        return symbol_type (token::CASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASTAS (location_type l)
      {
        return symbol_type (token::CASTAS, std::move (l));
      }
#else
      static
      symbol_type
      make_CASTAS (const location_type& l)
      {
        return symbol_type (token::CASTAS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CATCH (location_type l)
      {
        return symbol_type (token::CATCH, std::move (l));
      }
#else
      static
      symbol_type
      make_CATCH (const location_type& l)
      {
        return symbol_type (token::CATCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CATCH_ALL (location_type l)
      {
        return symbol_type (token::CATCH_ALL, std::move (l));
      }
#else
      static
      symbol_type
      make_CATCH_ALL (const location_type& l)
      {
        return symbol_type (token::CATCH_ALL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHART (location_type l)
      {
        return symbol_type (token::CHART, std::move (l));
      }
#else
      static
      symbol_type
      make_CHART (const location_type& l)
      {
        return symbol_type (token::CHART, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (location_type l)
      {
        return symbol_type (token::CLASS, std::move (l));
      }
#else
      static
      symbol_type
      make_CLASS (const location_type& l)
      {
        return symbol_type (token::CLASS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLEANUP (location_type l)
      {
        return symbol_type (token::CLEANUP, std::move (l));
      }
#else
      static
      symbol_type
      make_CLEANUP (const location_type& l)
      {
        return symbol_type (token::CLEANUP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST (location_type l)
      {
        return symbol_type (token::CONST, std::move (l));
      }
#else
      static
      symbol_type
      make_CONST (const location_type& l)
      {
        return symbol_type (token::CONST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (location_type l)
      {
        return symbol_type (token::CONTINUE, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const location_type& l)
      {
        return symbol_type (token::CONTINUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPEVAL (location_type l)
      {
        return symbol_type (token::COMPEVAL, std::move (l));
      }
#else
      static
      symbol_type
      make_COMPEVAL (const location_type& l)
      {
        return symbol_type (token::COMPEVAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CTOR (location_type l)
      {
        return symbol_type (token::CTOR, std::move (l));
      }
#else
      static
      symbol_type
      make_CTOR (const location_type& l)
      {
        return symbol_type (token::CTOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT (location_type l)
      {
        return symbol_type (token::DEFAULT, std::move (l));
      }
#else
      static
      symbol_type
      make_DEFAULT (const location_type& l)
      {
        return symbol_type (token::DEFAULT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFINE (location_type l)
      {
        return symbol_type (token::DEFINE, std::move (l));
      }
#else
      static
      symbol_type
      make_DEFINE (const location_type& l)
      {
        return symbol_type (token::DEFINE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DELETE (location_type l)
      {
        return symbol_type (token::DELETE, std::move (l));
      }
#else
      static
      symbol_type
      make_DELETE (const location_type& l)
      {
        return symbol_type (token::DELETE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (location_type l)
      {
        return symbol_type (token::DO, std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const location_type& l)
      {
        return symbol_type (token::DO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSEIF (location_type l)
      {
        return symbol_type (token::ELSEIF, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSEIF (const location_type& l)
      {
        return symbol_type (token::ELSEIF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM (location_type l)
      {
        return symbol_type (token::ENUM, std::move (l));
      }
#else
      static
      symbol_type
      make_ENUM (const location_type& l)
      {
        return symbol_type (token::ENUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOATT (location_type l)
      {
        return symbol_type (token::FLOATT, std::move (l));
      }
#else
      static
      symbol_type
      make_FLOATT (const location_type& l)
      {
        return symbol_type (token::FLOATT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNC (location_type l)
      {
        return symbol_type (token::FUNC, std::move (l));
      }
#else
      static
      symbol_type
      make_FUNC (const location_type& l)
      {
        return symbol_type (token::FUNC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GET (location_type l)
      {
        return symbol_type (token::GET, std::move (l));
      }
#else
      static
      symbol_type
      make_GET (const location_type& l)
      {
        return symbol_type (token::GET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GOTO (location_type l)
      {
        return symbol_type (token::GOTO, std::move (l));
      }
#else
      static
      symbol_type
      make_GOTO (const location_type& l)
      {
        return symbol_type (token::GOTO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEAP (location_type l)
      {
        return symbol_type (token::HEAP, std::move (l));
      }
#else
      static
      symbol_type
      make_HEAP (const location_type& l)
      {
        return symbol_type (token::HEAP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMPORT (location_type l)
      {
        return symbol_type (token::IMPORT, std::move (l));
      }
#else
      static
      symbol_type
      make_IMPORT (const location_type& l)
      {
        return symbol_type (token::IMPORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN (location_type l)
      {
        return symbol_type (token::IN, std::move (l));
      }
#else
      static
      symbol_type
      make_IN (const location_type& l)
      {
        return symbol_type (token::IN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INHERITS (location_type l)
      {
        return symbol_type (token::INHERITS, std::move (l));
      }
#else
      static
      symbol_type
      make_INHERITS (const location_type& l)
      {
        return symbol_type (token::INHERITS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INITIALIZE (location_type l)
      {
        return symbol_type (token::INITIALIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_INITIALIZE (const location_type& l)
      {
        return symbol_type (token::INITIALIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTT (location_type l)
      {
        return symbol_type (token::INTT, std::move (l));
      }
#else
      static
      symbol_type
      make_INTT (const location_type& l)
      {
        return symbol_type (token::INTT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IS (location_type l)
      {
        return symbol_type (token::IS, std::move (l));
      }
#else
      static
      symbol_type
      make_IS (const location_type& l)
      {
        return symbol_type (token::IS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LET (location_type l)
      {
        return symbol_type (token::LET, std::move (l));
      }
#else
      static
      symbol_type
      make_LET (const location_type& l)
      {
        return symbol_type (token::LET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LONG (location_type l)
      {
        return symbol_type (token::LONG, std::move (l));
      }
#else
      static
      symbol_type
      make_LONG (const location_type& l)
      {
        return symbol_type (token::LONG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MODULE (location_type l)
      {
        return symbol_type (token::MODULE, std::move (l));
      }
#else
      static
      symbol_type
      make_MODULE (const location_type& l)
      {
        return symbol_type (token::MODULE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW (location_type l)
      {
        return symbol_type (token::NEW, std::move (l));
      }
#else
      static
      symbol_type
      make_NEW (const location_type& l)
      {
        return symbol_type (token::NEW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOTHROWABLE (location_type l)
      {
        return symbol_type (token::NOTHROWABLE, std::move (l));
      }
#else
      static
      symbol_type
      make_NOTHROWABLE (const location_type& l)
      {
        return symbol_type (token::NOTHROWABLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPERATOR (location_type l)
      {
        return symbol_type (token::OPERATOR, std::move (l));
      }
#else
      static
      symbol_type
      make_OPERATOR (const location_type& l)
      {
        return symbol_type (token::OPERATOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRIVATE (location_type l)
      {
        return symbol_type (token::PRIVATE, std::move (l));
      }
#else
      static
      symbol_type
      make_PRIVATE (const location_type& l)
      {
        return symbol_type (token::PRIVATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROPERTY (location_type l)
      {
        return symbol_type (token::PROPERTY, std::move (l));
      }
#else
      static
      symbol_type
      make_PROPERTY (const location_type& l)
      {
        return symbol_type (token::PROPERTY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROTECTED (location_type l)
      {
        return symbol_type (token::PROTECTED, std::move (l));
      }
#else
      static
      symbol_type
      make_PROTECTED (const location_type& l)
      {
        return symbol_type (token::PROTECTED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUBLIC (location_type l)
      {
        return symbol_type (token::PUBLIC, std::move (l));
      }
#else
      static
      symbol_type
      make_PUBLIC (const location_type& l)
      {
        return symbol_type (token::PUBLIC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REF (location_type l)
      {
        return symbol_type (token::REF, std::move (l));
      }
#else
      static
      symbol_type
      make_REF (const location_type& l)
      {
        return symbol_type (token::REF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RREF (location_type l)
      {
        return symbol_type (token::RREF, std::move (l));
      }
#else
      static
      symbol_type
      make_RREF (const location_type& l)
      {
        return symbol_type (token::RREF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETHROW (location_type l)
      {
        return symbol_type (token::RETHROW, std::move (l));
      }
#else
      static
      symbol_type
      make_RETHROW (const location_type& l)
      {
        return symbol_type (token::RETHROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::RETURN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SET (location_type l)
      {
        return symbol_type (token::SET, std::move (l));
      }
#else
      static
      symbol_type
      make_SET (const location_type& l)
      {
        return symbol_type (token::SET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHORT (location_type l)
      {
        return symbol_type (token::SHORT, std::move (l));
      }
#else
      static
      symbol_type
      make_SHORT (const location_type& l)
      {
        return symbol_type (token::SHORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC (location_type l)
      {
        return symbol_type (token::STATIC, std::move (l));
      }
#else
      static
      symbol_type
      make_STATIC (const location_type& l)
      {
        return symbol_type (token::STATIC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUPER (location_type l)
      {
        return symbol_type (token::SUPER, std::move (l));
      }
#else
      static
      symbol_type
      make_SUPER (const location_type& l)
      {
        return symbol_type (token::SUPER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH (location_type l)
      {
        return symbol_type (token::SWITCH, std::move (l));
      }
#else
      static
      symbol_type
      make_SWITCH (const location_type& l)
      {
        return symbol_type (token::SWITCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THIS (location_type l)
      {
        return symbol_type (token::THIS, std::move (l));
      }
#else
      static
      symbol_type
      make_THIS (const location_type& l)
      {
        return symbol_type (token::THIS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THROW (location_type l)
      {
        return symbol_type (token::THROW, std::move (l));
      }
#else
      static
      symbol_type
      make_THROW (const location_type& l)
      {
        return symbol_type (token::THROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRY (location_type l)
      {
        return symbol_type (token::TRY, std::move (l));
      }
#else
      static
      symbol_type
      make_TRY (const location_type& l)
      {
        return symbol_type (token::TRY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEOF (location_type l)
      {
        return symbol_type (token::TYPEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPEOF (const location_type& l)
      {
        return symbol_type (token::TYPEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VIRTUAL (location_type l)
      {
        return symbol_type (token::VIRTUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_VIRTUAL (const location_type& l)
      {
        return symbol_type (token::VIRTUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WEAK (location_type l)
      {
        return symbol_type (token::WEAK, std::move (l));
      }
#else
      static
      symbol_type
      make_WEAK (const location_type& l)
      {
        return symbol_type (token::WEAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YIELD (location_type l)
      {
        return symbol_type (token::YIELD, std::move (l));
      }
#else
      static
      symbol_type
      make_YIELD (const location_type& l)
      {
        return symbol_type (token::YIELD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRAC (location_type l)
      {
        return symbol_type (token::LBRAC, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRAC (const location_type& l)
      {
        return symbol_type (token::LBRAC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRAC (location_type l)
      {
        return symbol_type (token::RBRAC, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRAC (const location_type& l)
      {
        return symbol_type (token::RBRAC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (location_type l)
      {
        return symbol_type (token::GT, std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const location_type& l)
      {
        return symbol_type (token::GT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (location_type l)
      {
        return symbol_type (token::LT, std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const location_type& l)
      {
        return symbol_type (token::LT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH (location_type l)
      {
        return symbol_type (token::SLASH, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASH (const location_type& l)
      {
        return symbol_type (token::SLASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASHSLASH (location_type l)
      {
        return symbol_type (token::SLASHSLASH, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASHSLASH (const location_type& l)
      {
        return symbol_type (token::SLASHSLASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (location_type l)
      {
        return symbol_type (token::STAR, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const location_type& l)
      {
        return symbol_type (token::STAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARROTCARROT (location_type l)
      {
        return symbol_type (token::CARROTCARROT, std::move (l));
      }
#else
      static
      symbol_type
      make_CARROTCARROT (const location_type& l)
      {
        return symbol_type (token::CARROTCARROT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERCENT (location_type l)
      {
        return symbol_type (token::PERCENT, std::move (l));
      }
#else
      static
      symbol_type
      make_PERCENT (const location_type& l)
      {
        return symbol_type (token::PERCENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS_EQ (location_type l)
      {
        return symbol_type (token::PLUS_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS_EQ (const location_type& l)
      {
        return symbol_type (token::PLUS_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS_EQ (location_type l)
      {
        return symbol_type (token::MINUS_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS_EQ (const location_type& l)
      {
        return symbol_type (token::MINUS_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR_EQ (location_type l)
      {
        return symbol_type (token::STAR_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR_EQ (const location_type& l)
      {
        return symbol_type (token::STAR_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH_EQ (location_type l)
      {
        return symbol_type (token::SLASH_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASH_EQ (const location_type& l)
      {
        return symbol_type (token::SLASH_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASHSLASH_EQ (location_type l)
      {
        return symbol_type (token::SLASHSLASH_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASHSLASH_EQ (const location_type& l)
      {
        return symbol_type (token::SLASHSLASH_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARROTCARROT_EQ (location_type l)
      {
        return symbol_type (token::CARROTCARROT_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_CARROTCARROT_EQ (const location_type& l)
      {
        return symbol_type (token::CARROTCARROT_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERCENT_EQ (location_type l)
      {
        return symbol_type (token::PERCENT_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_PERCENT_EQ (const location_type& l)
      {
        return symbol_type (token::PERCENT_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEQ (location_type l)
      {
        return symbol_type (token::LEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_LEQ (const location_type& l)
      {
        return symbol_type (token::LEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GEQ (location_type l)
      {
        return symbol_type (token::GEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_GEQ (const location_type& l)
      {
        return symbol_type (token::GEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (location_type l)
      {
        return symbol_type (token::EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const location_type& l)
      {
        return symbol_type (token::EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEQ (location_type l)
      {
        return symbol_type (token::NEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_NEQ (const location_type& l)
      {
        return symbol_type (token::NEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SPACESHIP (location_type l)
      {
        return symbol_type (token::SPACESHIP, std::move (l));
      }
#else
      static
      symbol_type
      make_SPACESHIP (const location_type& l)
      {
        return symbol_type (token::SPACESHIP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMP (location_type l)
      {
        return symbol_type (token::AMP, std::move (l));
      }
#else
      static
      symbol_type
      make_AMP (const location_type& l)
      {
        return symbol_type (token::AMP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIP (location_type l)
      {
        return symbol_type (token::PIP, std::move (l));
      }
#else
      static
      symbol_type
      make_PIP (const location_type& l)
      {
        return symbol_type (token::PIP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLAMATION (location_type l)
      {
        return symbol_type (token::EXCLAMATION, std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLAMATION (const location_type& l)
      {
        return symbol_type (token::EXCLAMATION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARROT (location_type l)
      {
        return symbol_type (token::CARROT, std::move (l));
      }
#else
      static
      symbol_type
      make_CARROT (const location_type& l)
      {
        return symbol_type (token::CARROT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TILDE (location_type l)
      {
        return symbol_type (token::TILDE, std::move (l));
      }
#else
      static
      symbol_type
      make_TILDE (const location_type& l)
      {
        return symbol_type (token::TILDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_SHIFT (location_type l)
      {
        return symbol_type (token::RIGHT_SHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_SHIFT (const location_type& l)
      {
        return symbol_type (token::RIGHT_SHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_SHIFT (location_type l)
      {
        return symbol_type (token::LEFT_SHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_SHIFT (const location_type& l)
      {
        return symbol_type (token::LEFT_SHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUSPLUS (location_type l)
      {
        return symbol_type (token::PLUSPLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUSPLUS (const location_type& l)
      {
        return symbol_type (token::PLUSPLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUSMINUS (location_type l)
      {
        return symbol_type (token::MINUSMINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUSMINUS (const location_type& l)
      {
        return symbol_type (token::MINUSMINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAR (location_type l)
      {
        return symbol_type (token::LPAR, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAR (const location_type& l)
      {
        return symbol_type (token::LPAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAR (location_type l)
      {
        return symbol_type (token::RPAR, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAR (const location_type& l)
      {
        return symbol_type (token::RPAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUESTION (location_type l)
      {
        return symbol_type (token::QUESTION, std::move (l));
      }
#else
      static
      symbol_type
      make_QUESTION (const location_type& l)
      {
        return symbol_type (token::QUESTION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROW1 (location_type l)
      {
        return symbol_type (token::ARROW1, std::move (l));
      }
#else
      static
      symbol_type
      make_ARROW1 (const location_type& l)
      {
        return symbol_type (token::ARROW1, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (location_type l)
      {
        return symbol_type (token::LBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const location_type& l)
      {
        return symbol_type (token::LBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (location_type l)
      {
        return symbol_type (token::RBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const location_type& l)
      {
        return symbol_type (token::RBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROW2 (location_type l)
      {
        return symbol_type (token::ARROW2, std::move (l));
      }
#else
      static
      symbol_type
      make_ARROW2 (const location_type& l)
      {
        return symbol_type (token::ARROW2, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOTS (location_type l)
      {
        return symbol_type (token::DOTS, std::move (l));
      }
#else
      static
      symbol_type
      make_DOTS (const location_type& l)
      {
        return symbol_type (token::DOTS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMPEQ (location_type l)
      {
        return symbol_type (token::AMPEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_AMPEQ (const location_type& l)
      {
        return symbol_type (token::AMPEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARROTEQ (location_type l)
      {
        return symbol_type (token::CARROTEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_CARROTEQ (const location_type& l)
      {
        return symbol_type (token::CARROTEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIPEQ (location_type l)
      {
        return symbol_type (token::PIPEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_PIPEQ (const location_type& l)
      {
        return symbol_type (token::PIPEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TILDEEQ (location_type l)
      {
        return symbol_type (token::TILDEEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_TILDEEQ (const location_type& l)
      {
        return symbol_type (token::TILDEEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFTEQ (location_type l)
      {
        return symbol_type (token::LEFTEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFTEQ (const location_type& l)
      {
        return symbol_type (token::LEFTEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHTEQ (location_type l)
      {
        return symbol_type (token::RIGHTEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHTEQ (const location_type& l)
      {
        return symbol_type (token::RIGHTEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POINTER_TYPE (location_type l)
      {
        return symbol_type (token::POINTER_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_POINTER_TYPE (const location_type& l)
      {
        return symbol_type (token::POINTER_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAYL (location_type l)
      {
        return symbol_type (token::ARRAYL, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAYL (const location_type& l)
      {
        return symbol_type (token::ARRAYL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAYR (location_type l)
      {
        return symbol_type (token::ARRAYR, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAYR (const location_type& l)
      {
        return symbol_type (token::ARRAYR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_BEGIN (location_type l)
      {
        return symbol_type (token::T_BEGIN, std::move (l));
      }
#else
      static
      symbol_type
      make_T_BEGIN (const location_type& l)
      {
        return symbol_type (token::T_BEGIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_END (location_type l)
      {
        return symbol_type (token::T_END, std::move (l));
      }
#else
      static
      symbol_type
      make_T_END (const location_type& l)
      {
        return symbol_type (token::T_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMINUS (location_type l)
      {
        return symbol_type (token::UMINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_UMINUS (const location_type& l)
      {
        return symbol_type (token::UMINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POSTINC (location_type l)
      {
        return symbol_type (token::POSTINC, std::move (l));
      }
#else
      static
      symbol_type
      make_POSTINC (const location_type& l)
      {
        return symbol_type (token::POSTINC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POSTDEC (location_type l)
      {
        return symbol_type (token::POSTDEC, std::move (l));
      }
#else
      static
      symbol_type
      make_POSTDEC (const location_type& l)
      {
        return symbol_type (token::POSTDEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TERN (location_type l)
      {
        return symbol_type (token::TERN, std::move (l));
      }
#else
      static
      symbol_type
      make_TERN (const location_type& l)
      {
        return symbol_type (token::TERN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEREF (location_type l)
      {
        return symbol_type (token::DEREF, std::move (l));
      }
#else
      static
      symbol_type
      make_DEREF (const location_type& l)
      {
        return symbol_type (token::DEREF, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const short yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const unsigned char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 1376,     ///< Last index in yytable_.
      yynnts_ = 107,  ///< Number of nonterminal symbols.
      yyfinal_ = 91 ///< Termination state number.
    };


    // User arguments.
    Arbor::FE::parse_context& pc;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPENAME: // TYPENAME
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

} // yy
#line 3720 "Parser/Arbor_parser.tab.hh"




#endif // !YY_YY_PARSER_ARBOR_PARSER_TAB_HH_INCLUDED
