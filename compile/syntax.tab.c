/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"


    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Struct.c"
    // #define YYSTYPE union {
    //         char* string;
    //         int int_val;
    //         double real_val;
    //         char char_val;
    // }
    extern FILE *yyin;
	extern FILE *yyout;
    extern int yylineno;
    extern char *yytext;
    extern int yylex();
    extern void yyerror(const char *s);
    int currentColumn = 1;
    Ligne *Table_sym;  
    int i =25;
    int ri=1;
    typedef struct quad{
        char op[4];
        char opr1[10];
        char opr2[10];
        char res[10];
    }quad;
    int sauv_if_fin = 0;
    int sauv_else =0;
    int sauv_else_fin=0;
    int sauv_fin_while=0;
    quad tab_quad[1000];
    int taille;

#line 106 "syntax.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRO = 258,
    LOOPF = 259,
    LOOPW = 260,
    READ = 261,
    WRITE = 262,
    IF = 263,
    ELSE = 264,
    DOT = 265,
    COMMA = 266,
    SEMICOLON = 267,
    OPENPARENTHESIS = 268,
    CLOSEPARENTHESIS = 269,
    OPENHOOK = 270,
    CLOSEHOOK = 271,
    OPENBRACKET = 272,
    CLOSEBRACKET = 273,
    EQUAL = 274,
    NONEQUAL = 275,
    AND = 276,
    OR = 277,
    NON = 278,
    INFERIOR = 279,
    SUPERIOR = 280,
    INFERIOREQUAL = 281,
    SUPERIOREQUAL = 282,
    ADD = 283,
    SUB = 284,
    MULT = 285,
    DIV = 286,
    MOD = 287,
    ASSIGNMENT = 288,
    BOOLEAN = 289,
    CHAR = 290,
    INTEGER = 291,
    REALNUMBER = 292,
    INTEGERDECLARE = 293,
    STRINGDECLARE = 294,
    BOOLEENDECLARE = 295,
    REALDECLARE = 296,
    CHARDECLARE = 297,
    STRUCTDECLARE = 298,
    INLINECOMMENT = 299,
    LINEBREAK = 300,
    STRING = 301,
    ID = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "syntax.y"

    char string[255];
    int int_val;
    double real_val;
    char char_val;

#line 213 "syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   401

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,   100,   100,   100,   100,   100,   100,
     102,   103,   104,   104,   104,   105,   105,   105,   105,   106,
     109,   112,   115,   124,   127,   130,   139,   145,   145,   146,
     147,   148,   149,   149,   159,   169,   179,   189,   199,   209,
     210,   210,   211,   212,   213,   213,   213,   213,   213,   214,
     214,   214,   214,   214,   220,   226,   232,   238,   244,   251,
     262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRO", "LOOPF", "LOOPW", "READ", "WRITE",
  "IF", "ELSE", "DOT", "COMMA", "SEMICOLON", "OPENPARENTHESIS",
  "CLOSEPARENTHESIS", "OPENHOOK", "CLOSEHOOK", "OPENBRACKET",
  "CLOSEBRACKET", "EQUAL", "NONEQUAL", "AND", "OR", "NON", "INFERIOR",
  "SUPERIOR", "INFERIOREQUAL", "SUPERIOREQUAL", "ADD", "SUB", "MULT",
  "DIV", "MOD", "ASSIGNMENT", "BOOLEAN", "CHAR", "INTEGER", "REALNUMBER",
  "INTEGERDECLARE", "STRINGDECLARE", "BOOLEENDECLARE", "REALDECLARE",
  "CHARDECLARE", "STRUCTDECLARE", "INLINECOMMENT", "LINEBREAK", "STRING",
  "ID", "$accept", "Input", "code", "declaration", "type", "structure",
  "tabledeclaration", "tablesize", "statements", "if_stm", "B1",
  "if_else_stm", "A1", "A2", "for_stm", "while_stm", "C1", "expression",
  "read", "write", "commentaire", "expressionAR", "item", "tableelement",
  "champenreg", "expressionLG", "element", "affectation", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -31,    18,    17,   -32,   266,   -13,    24,    28,    34,
      -8,     4,     4,     6,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,    12,     3,    85,   -32,   -16,   -32,   -32,   -32,   -32,
      39,   -32,    50,    47,   -32,   -32,    48,   -32,   -32,   -32,
     -32,   326,   -32,   -32,   -32,   -18,   -32,   -32,    33,     4,
      22,     4,     4,   301,   326,   -18,   351,     8,   -18,     6,
     -32,   -32,   -32,    37,    75,     6,   -32,   266,    75,   -10,
     266,    81,   266,   266,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     4,     4,     6,    73,    83,
      89,    88,   -32,   -32,   358,   -32,    87,    94,    95,   363,
     311,    97,   -32,     6,   136,   266,   150,   194,   105,   105,
     105,   105,   105,   105,   -32,   -32,    15,    15,    15,    84,
     -32,   306,   -32,   104,   106,    92,   -32,   -32,    70,   332,
     -32,   208,   -32,   -32,     4,   -32,   -32,   108,   -32,   -32,
      35,   -32,     6,   369,   266,   252,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    51,    14,    17,    18,    15,
      16,     0,    50,     0,     8,     0,    19,     7,     9,    25,
       0,    26,     0,     0,    27,    28,     0,    10,    11,    12,
       6,    37,    49,    61,    62,    38,    58,     5,     0,     0,
       0,     0,     0,    59,     0,    30,     0,     0,    57,     0,
      50,    45,    41,     0,     0,     0,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    54,     0,    53,    51,    50,     0,    23,
       0,     0,    13,     0,     0,     0,     0,     0,    63,    64,
      65,    67,    66,    68,    43,    44,    46,    47,    48,    55,
      56,     0,    36,     0,     0,    54,    52,    69,     0,     0,
      29,     0,    32,    35,     0,    39,    40,     0,    70,    31,
       0,    21,     0,     0,     0,     0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,    -5,   -32,   -32,   -32,   -32,    60,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,    80,   -32,   -32,
     -32,    -4,   -32,   -32,   -32,     0,   -32,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    67,    24,    25,    26,    27,    98,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    68,   102,    85,    86,    52,    54,    56,    54,    61,
      55,    57,    58,    63,     1,    12,     3,    11,     4,    59,
      64,    13,    93,   103,   -59,   -59,    14,    12,    15,    85,
      86,    69,     5,    13,    48,    13,    65,    49,    14,    53,
      15,    50,    15,    80,    81,    54,   142,    51,    56,    88,
     -20,    53,    91,    60,    70,    94,    85,    86,    62,    71,
      99,   100,    72,    73,    99,   104,    87,   106,   107,    89,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    54,    54,   121,    95,   119,   120,   122,    59,     6,
       7,     8,     9,    10,    85,    86,   105,   123,    11,   129,
     131,    66,   125,   124,    13,   -24,    86,   -33,    12,    85,
      86,    96,   -22,   126,    13,   128,   135,   137,   136,    14,
     141,    15,    97,    16,    17,    18,    19,    20,   101,    21,
      54,    90,    22,    80,   140,    82,    83,    84,   143,   145,
       6,     7,     8,     9,    10,     0,     0,     0,     0,    11,
       0,     0,   130,     0,     6,     7,     8,     9,    10,    12,
       0,     0,     0,    11,     0,    13,   132,     0,     0,     0,
      14,     0,    15,    12,    16,    17,    18,    19,    20,    13,
      21,     0,     0,    22,    14,     0,    15,     0,    16,    17,
      18,    19,    20,     0,    21,     0,     0,    22,     6,     7,
       8,     9,    10,     0,     0,     0,     0,    11,     0,     0,
     133,     0,     6,     7,     8,     9,    10,    12,     0,     0,
       0,    11,     0,    13,   139,     0,     0,     0,    14,     0,
      15,    12,    16,    17,    18,    19,    20,    13,    21,     0,
       0,    22,    14,     0,    15,     0,    16,    17,    18,    19,
      20,     0,    21,     0,     0,    22,     6,     7,     8,     9,
      10,     0,     0,     0,     0,    11,     0,     0,   146,     0,
       6,     7,     8,     9,    10,    12,     0,     0,     0,    11,
       0,    13,     0,     0,     0,     0,    14,     0,    15,    12,
      16,    17,    18,    19,    20,    13,    21,     0,     0,    22,
      14,     0,    15,     0,    16,    17,    18,    19,    20,     0,
      21,    63,     0,    22,     0,   -50,     0,   134,    64,     0,
     -50,   -50,     0,   127,     0,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,    80,    81,    82,    83,    84,    80,
      81,    82,    83,    84,   138,    74,    75,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      80,    81,    82,    83,    84,    92,     0,     0,     0,     0,
      74,    75,    92,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   144,     0,    80,    81,    82,    83,
      84,    80,    81,    82,    83,    84,     0,    80,    81,    82,
      83,    84
};

static const yytype_int16 yycheck[] =
{
       5,    17,    12,    21,    22,    13,    10,    11,    12,    13,
      10,    11,    12,    10,     3,    23,    47,    13,     0,    13,
      17,    29,    14,    33,    21,    22,    34,    23,    36,    21,
      22,    47,    15,    29,    47,    29,    33,    13,    34,    47,
      36,    13,    36,    28,    29,    49,    11,    13,    52,    49,
      47,    47,    52,    47,    15,    59,    21,    22,    46,     9,
      64,    65,    15,    15,    68,    70,    33,    72,    73,    47,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    47,    85,    86,    14,    13,     4,
       5,     6,     7,     8,    21,    22,    15,    14,    13,   103,
     105,    16,    14,    14,    29,    18,    22,    15,    23,    21,
      22,    36,    18,    18,    29,    18,    12,    47,    12,    34,
      12,    36,    47,    38,    39,    40,    41,    42,    68,    44,
     134,    51,    47,    28,   134,    30,    31,    32,   142,   144,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    16,    -1,     4,     5,     6,     7,     8,    23,
      -1,    -1,    -1,    13,    -1,    29,    16,    -1,    -1,    -1,
      34,    -1,    36,    23,    38,    39,    40,    41,    42,    29,
      44,    -1,    -1,    47,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    -1,    44,    -1,    -1,    47,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      16,    -1,     4,     5,     6,     7,     8,    23,    -1,    -1,
      -1,    13,    -1,    29,    16,    -1,    -1,    -1,    34,    -1,
      36,    23,    38,    39,    40,    41,    42,    29,    44,    -1,
      -1,    47,    34,    -1,    36,    -1,    38,    39,    40,    41,
      42,    -1,    44,    -1,    -1,    47,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    13,    -1,    -1,    16,    -1,
       4,     5,     6,     7,     8,    23,    -1,    -1,    -1,    13,
      -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,    23,
      38,    39,    40,    41,    42,    29,    44,    -1,    -1,    47,
      34,    -1,    36,    -1,    38,    39,    40,    41,    42,    -1,
      44,    10,    -1,    47,    -1,    14,    -1,    11,    17,    -1,
      19,    20,    -1,    12,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    12,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      28,    29,    30,    31,    32,    14,    -1,    -1,    -1,    -1,
      19,    20,    14,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    15,    -1,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    -1,    28,    29,    30,
      31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    49,    47,     0,    15,     4,     5,     6,     7,
       8,    13,    23,    29,    34,    36,    38,    39,    40,    41,
      42,    44,    47,    50,    51,    52,    53,    54,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    47,    13,
      13,    13,    13,    47,    69,    73,    69,    73,    73,    13,
      47,    69,    46,    10,    17,    33,    16,    50,    17,    47,
      15,     9,    15,    15,    19,    20,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    21,    22,    33,    73,    47,
      65,    73,    14,    14,    69,    47,    36,    47,    55,    69,
      69,    55,    12,    33,    50,    15,    50,    50,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    73,
      73,    69,    14,    14,    14,    14,    18,    12,    18,    69,
      16,    50,    16,    16,    11,    12,    12,    47,    12,    16,
      73,    12,    11,    69,    15,    50,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    52,    52,    52,    52,    52,    52,
      53,    54,    55,    55,    55,    56,    56,    56,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    65,    66,
      67,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    70,    71,    72,    73,    73,    73,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     6,     1,     1,     1,     1,     1,     1,     1,     4,
       2,     5,     4,     4,    11,     4,     4,     1,     1,     5,
       5,     2,     3,     3,     3,     2,     3,     3,     3,     1,
       1,     1,     4,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     4,
       5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 13:
#line 92 "syntax.y"
                               { 
    if(get_id(Table_sym,(yyvsp[-1].string))!=NULL){
        printf("Variable deja declarer : %s \n ",(yyvsp[-1].string));
        YYERROR;
    }else{
        insertColumn(Table_sym,(yyvsp[-2].string),(yyvsp[-1].string),"",1); 
    }
    }
#line 1549 "syntax.tab.c"
    break;

  case 29:
#line 106 "syntax.y"
                                   {
    sprintf(tab_quad[sauv_if_fin].opr1,"%d",taille+1);
}
#line 1557 "syntax.tab.c"
    break;

  case 30:
#line 109 "syntax.y"
                   {
    sauv_if_fin = taille-1;
}
#line 1565 "syntax.tab.c"
    break;

  case 31:
#line 112 "syntax.y"
                                             {
    sprintf(tab_quad[sauv_else_fin].opr1,"%d",taille+1);
}
#line 1573 "syntax.tab.c"
    break;

  case 32:
#line 115 "syntax.y"
                               {
    sprintf(tab_quad[sauv_else].opr1,"%d",taille+2); 
    strcpy( tab_quad[taille].op,"BR");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,"");
    strcpy( tab_quad[taille].res,"");
    sauv_else_fin = taille;
    taille++;
}
#line 1587 "syntax.tab.c"
    break;

  case 33:
#line 124 "syntax.y"
                                                     {
    sauv_else=taille-1;
}
#line 1595 "syntax.tab.c"
    break;

  case 35:
#line 130 "syntax.y"
                                     {
    strcpy( tab_quad[taille].op,"BR");
    sprintf( tab_quad[taille].opr1,"%d", sauv_fin_while+1);
    strcpy( tab_quad[taille].opr2,"");
    strcpy( tab_quad[taille].res,"");
    taille++;
    sprintf(tab_quad[sauv_fin_while].opr1,"%d",taille+1);

}
#line 1609 "syntax.tab.c"
    break;

  case 36:
#line 139 "syntax.y"
                                                      {
    sauv_fin_while=taille-1;   
}
#line 1617 "syntax.tab.c"
    break;

  case 42:
#line 149 "syntax.y"
                                                            { strcpy( (yyval.string),(yyvsp[-1].string)); }
#line 1623 "syntax.tab.c"
    break;

  case 43:
#line 149 "syntax.y"
                                                                                                                                {
    char res[10];
    strcpy( tab_quad[taille].op,"+");
    strcpy( tab_quad[taille].opr1,(yyvsp[-2].string));
    strcpy( tab_quad[taille].opr2,(yyvsp[0].string));
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( (yyval.string),res);
}
#line 1639 "syntax.tab.c"
    break;

  case 44:
#line 159 "syntax.y"
                                  {
        char res[10];
    strcpy( tab_quad[taille].op,"-");
    strcpy( tab_quad[taille].opr1,(yyvsp[-2].string));
    strcpy( tab_quad[taille].opr2,(yyvsp[0].string));
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( (yyval.string),res);
}
#line 1655 "syntax.tab.c"
    break;

  case 45:
#line 169 "syntax.y"
                    {
    char res[10];
    strcpy( tab_quad[taille].op,"-");
    strcpy( tab_quad[taille].opr1,"0");
    strcpy( tab_quad[taille].opr2,(yyvsp[0].string));
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( (yyval.string),res);
}
#line 1671 "syntax.tab.c"
    break;

  case 46:
#line 179 "syntax.y"
                                  {
    char res[10];
    strcpy( tab_quad[taille].op,"*");
    strcpy( tab_quad[taille].opr1,(yyvsp[-2].string));
    strcpy( tab_quad[taille].opr2,(yyvsp[0].string));
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( (yyval.string),res);
}
#line 1687 "syntax.tab.c"
    break;

  case 47:
#line 189 "syntax.y"
                                 {
    char res[10];
    strcpy( tab_quad[taille].op,"/");
    strcpy( tab_quad[taille].opr1,(yyvsp[-2].string));
    strcpy( tab_quad[taille].opr2,(yyvsp[0].string));
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( (yyval.string),res);
}
#line 1703 "syntax.tab.c"
    break;

  case 48:
#line 199 "syntax.y"
                                 {
    char res[10];
    strcpy( tab_quad[taille].op,"\%");
    strcpy( tab_quad[taille].opr1,(yyvsp[-2].string));
    strcpy( tab_quad[taille].opr2,(yyvsp[0].string));
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( (yyval.string),res);
}
#line 1719 "syntax.tab.c"
    break;

  case 50:
#line 210 "syntax.y"
         { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1725 "syntax.tab.c"
    break;

  case 51:
#line 210 "syntax.y"
                                                        { sprintf((yyval.string),"%d",(yyvsp[0].int_val)); }
#line 1731 "syntax.tab.c"
    break;

  case 54:
#line 213 "syntax.y"
                                                            { strcpy( (yyval.string),(yyvsp[-1].string));}
#line 1737 "syntax.tab.c"
    break;

  case 63:
#line 214 "syntax.y"
                                                                                    {
    strcpy( tab_quad[taille].op,"BNE");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,(yyvsp[-2].string));
    strcpy( tab_quad[taille].res,(yyvsp[0].string));
    taille++;
}
#line 1749 "syntax.tab.c"
    break;

  case 64:
#line 220 "syntax.y"
                                       {
    strcpy( tab_quad[taille].op,"BE");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,(yyvsp[-2].string));
    strcpy( tab_quad[taille].res,(yyvsp[0].string));
    taille++;
}
#line 1761 "syntax.tab.c"
    break;

  case 65:
#line 226 "syntax.y"
                                     {
     strcpy( tab_quad[taille].op,"BGE");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,(yyvsp[-2].string));
    strcpy( tab_quad[taille].res,(yyvsp[0].string));
    taille++;
}
#line 1773 "syntax.tab.c"
    break;

  case 66:
#line 232 "syntax.y"
                                            {
    strcpy( tab_quad[taille].op,"BG");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,(yyvsp[-2].string));
    strcpy( tab_quad[taille].res,(yyvsp[0].string));
    taille++;
}
#line 1785 "syntax.tab.c"
    break;

  case 67:
#line 238 "syntax.y"
                                      {
     strcpy( tab_quad[taille].op,"BLE");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,(yyvsp[-2].string));
    strcpy( tab_quad[taille].res,(yyvsp[0].string));
    taille++;
}
#line 1797 "syntax.tab.c"
    break;

  case 68:
#line 244 "syntax.y"
                                            {
     strcpy( tab_quad[taille].op,"BL");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,(yyvsp[-2].string));
    strcpy( tab_quad[taille].res,(yyvsp[0].string));
    taille++;
}
#line 1809 "syntax.tab.c"
    break;

  case 69:
#line 251 "syntax.y"
                                                  { 
    if(get_id(Table_sym,(yyvsp[-3].string))!=NULL){
        strcpy( tab_quad[taille].op,":=");
        strcpy(tab_quad[taille].opr1,(yyvsp[-1].string));
        strcpy( tab_quad[taille].opr2,"");
        strcpy( tab_quad[taille].res,(yyvsp[-3].string));
        taille++;
    }else{
        printf("Variable non declaré :%s\n",(yyvsp[-3].string));
        YYERROR;
    }
}
#line 1826 "syntax.tab.c"
    break;

  case 70:
#line 262 "syntax.y"
                                            {
    if(get_id(Table_sym,(yyvsp[-3].string))==NULL){
        insertColumn(Table_sym,(yyvsp[-4].string),(yyvsp[-3].string),"",1); 
        strcpy( tab_quad[taille].op,":=");
        strcpy(tab_quad[taille].opr1,(yyvsp[-1].string));
        strcpy( tab_quad[taille].opr2,"");
        strcpy( tab_quad[taille].res,(yyvsp[-3].string));
        taille++;
    }else{
        printf("Variable deja declaré :%s\n",(yyvsp[-3].string));
        YYERROR;
    }
}
#line 1844 "syntax.tab.c"
    break;


#line 1848 "syntax.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 275 "syntax.y"




int main(int argc, char **argv) {
    Table_sym = insertLigne(&Table_sym ,1);
    yyin = fopen(argv[1], "r");
    yyout = fopen("Output.txt", "r+");
    taille=0;
    int value = yyparse();

    // Column *col = Table_sym->Columns;
    // while(col!=NULL){
    //     printf("%s  :   %s\n",col->nameToken,col->typeToken);
    //     col=col->suivC;
    // }
    int i =0;
    for(i=0 ; i<taille ; i++){
        printf("%d-(%s,%s,%s,%s)\n",i+1,tab_quad[i].op,tab_quad[i].opr1,tab_quad[i].opr2,tab_quad[i].res);
    }


    if(value==1){
        printf("\nErreur dans la ligne :%d  et la colonne : %d\n",yylineno,currentColumn);
    }else{
        printf("Complation success\n");
    }
    fclose(yyin);
    fclose(yyout);
    return 0;
}





