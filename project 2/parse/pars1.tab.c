/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "pars1.y" /* yacc.c:339  */
     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"
#include <string.h>
#include <float.h>

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;


#line 130 "pars1.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    IDENTIFIER = 258,
    STRING = 259,
    NUMBER = 260,
    PLUS = 261,
    MINUS = 262,
    TIMES = 263,
    DIVIDE = 264,
    ASSIGN = 265,
    EQ = 266,
    NE = 267,
    LT = 268,
    LE = 269,
    GE = 270,
    GT = 271,
    POINT = 272,
    DOT = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    DIV = 277,
    MOD = 278,
    IN = 279,
    COMMA = 280,
    SEMICOLON = 281,
    COLON = 282,
    LPAREN = 283,
    RPAREN = 284,
    LBRACKET = 285,
    RBRACKET = 286,
    DOTDOT = 287,
    ARRAY = 288,
    BEGINBEGIN = 289,
    CASE = 290,
    CONST = 291,
    DO = 292,
    DOWNTO = 293,
    ELSE = 294,
    END = 295,
    FILEFILE = 296,
    FOR = 297,
    FUNCTION = 298,
    GOTO = 299,
    IF = 300,
    LABEL = 301,
    NIL = 302,
    OF = 303,
    PACKED = 304,
    PROCEDURE = 305,
    PROGRAM = 306,
    RECORD = 307,
    REPEAT = 308,
    SET = 309,
    THEN = 310,
    TO = 311,
    TYPE = 312,
    UNTIL = 313,
    VAR = 314,
    WHILE = 315,
    WITH = 316
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 300 "pars1.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    85,    85,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   100,   101,   103,   104,   106,   107,   109,   110,
     112,   113,   115,   116,   118,   119,   121,   123,   124,   126,
     127,   129,   130,   132,   134,   135,   136,   137,   139,   140,
     141,   143,   144,   146,   147,   149,   151,   152,   153,   154,
     156,   158,   159,   161,   162,   164,   165,   166,   167,   168,
     169,   170,   172,   173,   174,   175,   177,   178,   179,   181,
     182,   183,   184,   185,   186,   188,   189,   190,   191,   192,
     193,   194,   195,   197,   198,   199,   201,   202,   204,   205,
     207
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "$accept", "program",
  "statement", "statelist", "idlist", "argslist", "haslabel", "hasconst",
  "hastype", "hasvar", "block", "labels", "consts", "types", "typedef",
  "type", "type2", "list", "var", "vars", "dovar", "arrayref", "arraylist",
  "fields", "compexpr", "expr", "unaryexpr", "term", "factor",
  "factorlist", "endpart", "endif", "assignment", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -162

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-162)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,    17,    26,    13,  -162,    44,    28,    36,    14,    99,
      66,    67,    72,    76,    56,  -162,  -162,  -162,  -162,     3,
    -162,    61,   121,   132,   132,    99,   121,    84,   132,  -162,
      99,   132,    38,    35,  -162,    80,  -162,    81,   -20,    68,
      69,    83,   -15,    88,    90,    91,    85,    95,  -162,   132,
     132,  -162,    99,    40,  -162,  -162,   121,   121,    93,    71,
      22,  -162,    58,    96,    86,    38,    74,  -162,    77,    97,
      73,   103,    99,  -162,  -162,  -162,   131,   132,   140,  -162,
      67,   -25,     7,  -162,    72,    76,     7,  -162,    76,   118,
     123,   119,  -162,   132,  -162,  -162,  -162,   132,   132,   132,
     132,   132,   132,   121,   121,   121,   121,   121,   121,   121,
     121,   132,  -162,  -162,   132,    99,    99,   132,    99,    38,
    -162,  -162,   128,  -162,  -162,  -162,   124,   152,    76,   127,
      76,  -162,  -162,  -162,  -162,  -162,  -162,   148,   132,   133,
     141,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,   136,   143,   130,  -162,  -162,
    -162,  -162,    66,   173,  -162,   153,    33,   154,   144,  -162,
    -162,  -162,   132,    99,    99,  -162,  -162,  -162,  -162,   158,
     155,     7,  -162,  -162,  -162,  -162,    33,   137,   161,  -162,
       7,    76,  -162,  -162
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    21,    23,    25,    46,
      81,    76,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,     0,    78,    49,     0,    11,     0,     0,    28,
       0,     0,     0,     0,    15,     0,     0,     0,     2,     0,
       0,    50,     0,    46,    76,    79,     0,     0,     0,    61,
      65,    68,    74,    83,     0,     0,     0,    10,     0,    13,
       0,     0,     0,    87,    26,    48,     0,     0,     0,    20,
       0,     0,     0,    22,    32,     0,     0,    24,    44,     0,
      17,     0,     5,     0,    66,    67,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     3,     0,     0,     0,     0,     0,     0,
      47,    90,     0,    27,    18,    38,     0,     0,     0,     0,
       0,    33,    34,    31,    14,    45,    43,     4,     0,    51,
       0,    55,    56,    57,    58,    59,    60,    62,    63,    64,
      69,    70,    73,    71,    72,    84,     0,    89,    12,     9,
       8,    86,    30,     0,    35,     0,     0,     0,     0,    16,
      52,    77,     0,     0,     0,     6,    29,    40,    39,    42,
       0,     0,    37,    85,     7,    88,     0,     0,    54,    41,
       0,     0,    36,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,    -7,    78,   -79,   -47,  -162,   107,   151,   149,
     146,   110,    31,   111,  -162,   -85,  -161,    10,   109,  -162,
    -162,  -162,    59,     8,    -1,    75,  -162,   -49,    -9,    29,
     -61,  -162,   174
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    69,    70,    45,    89,    14,    15,    16,    17,
      18,    40,    38,    42,    43,   131,   132,   180,    46,    47,
      33,    34,    51,   168,    90,    59,    60,    61,    62,    64,
      74,   175,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,   135,    32,    91,   113,   179,   134,    94,    95,     9,
     125,    10,   126,    55,     9,     1,    35,    35,    65,     9,
       3,    35,    58,    63,   127,   179,     4,    68,   103,   104,
      71,    49,    12,    50,    13,   128,   125,    12,   126,    13,
     129,     5,   105,    35,    13,    92,   140,     6,     9,   165,
      10,   167,    75,    76,   147,   148,   149,     7,   161,   130,
      11,   128,     8,    35,    72,   119,   106,   107,    93,    37,
      50,    12,    39,    13,    48,    41,   121,   108,    73,    44,
     109,   110,    97,    98,    99,   100,   101,   102,    52,    67,
      77,   169,    78,    80,    82,    81,   188,   150,   151,   152,
     153,   154,    19,    20,    21,   192,    35,    35,   157,    35,
     155,   160,   167,   156,    84,    85,   159,   112,    86,     9,
      22,    88,    96,   116,    53,    20,    54,    23,   111,    24,
     114,   117,   115,    25,   120,    53,    20,    54,    56,    57,
     118,    26,    22,    27,    28,   122,    29,   137,   138,    23,
     139,    24,    30,    22,   162,   164,   163,   166,   -77,    31,
      23,   172,    24,    50,    35,    35,   184,   185,    29,   174,
     171,    63,   141,   142,   143,   144,   145,   146,   177,    29,
     173,   181,   178,   186,   182,   190,   187,   191,   124,    79,
     123,    83,    87,   176,   158,   133,   189,   136,   170,   193,
      66,   183
};

static const yytype_uint8 yycheck[] =
{
       9,    86,     9,    50,    65,   166,    85,    56,    57,    34,
       3,    36,     5,    22,    34,    51,    25,    26,    25,    34,
       3,    30,    23,    24,    17,   186,     0,    28,     6,     7,
      31,    28,    57,    30,    59,    28,     3,    57,     5,    59,
      33,    28,    20,    52,    59,    52,    93,     3,    34,   128,
      36,   130,    17,    18,   103,   104,   105,    29,   119,    52,
      46,    28,    26,    72,    26,    72,     8,     9,    28,     3,
      30,    57,     5,    59,    18,     3,    77,    19,    40,     3,
      22,    23,    11,    12,    13,    14,    15,    16,    27,     5,
      10,   138,    11,    25,    11,    26,   181,   106,   107,   108,
     109,   110,     3,     4,     5,   190,   115,   116,   115,   118,
     111,   118,   191,   114,    26,    25,   117,    31,    27,    34,
      21,    26,    29,    26,     3,     4,     5,    28,    32,    30,
      56,    58,    55,    34,     3,     3,     4,     5,     6,     7,
      37,    42,    21,    44,    45,     5,    47,    29,    25,    28,
      31,    30,    53,    21,    26,     3,    32,    30,    10,    60,
      28,    25,    30,    30,   173,   174,   173,   174,    47,    39,
      29,   172,    97,    98,    99,   100,   101,   102,     5,    47,
      37,    27,    29,    25,    40,    48,    31,    26,    81,    38,
      80,    42,    46,   162,   116,    84,   186,    88,   139,   191,
      26,   172
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    29,    26,    34,
      36,    46,    57,    59,    68,    69,    70,    71,    72,     3,
       4,     5,    21,    28,    30,    34,    42,    44,    45,    47,
      53,    60,    64,    82,    83,    90,    94,     3,    74,     5,
      73,     3,    75,    76,     3,    66,    80,    81,    18,    28,
      30,    84,    27,     3,     5,    90,     6,     7,    86,    87,
      88,    89,    90,    86,    91,    64,    94,     5,    86,    64,
      65,    86,    26,    40,    92,    17,    18,    10,    11,    70,
      25,    26,    11,    71,    26,    25,    27,    72,    26,    67,
      86,    67,    64,    28,    89,    89,    29,    11,    12,    13,
      14,    15,    16,     6,     7,    20,     8,     9,    19,    22,
      23,    32,    31,    92,    56,    55,    26,    58,    37,    64,
       3,    86,     5,    73,    69,     3,     5,    17,    28,    33,
      52,    77,    78,    75,    66,    77,    80,    29,    25,    31,
      67,    87,    87,    87,    87,    87,    87,    89,    89,    89,
      90,    90,    90,    90,    90,    86,    86,    64,    65,    86,
      64,    92,    26,    32,     3,    66,    30,    66,    85,    67,
      84,    29,    25,    37,    39,    93,    74,     5,    29,    78,
      79,    27,    40,    91,    64,    64,    25,    31,    77,    79,
      48,    26,    77,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    73,    73,    74,
      74,    75,    75,    76,    77,    77,    77,    77,    78,    78,
      78,    79,    79,    80,    80,    81,    82,    82,    82,    82,
      83,    84,    84,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    92,    92,    93,    93,
      94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     3,     4,     3,     5,     6,     4,     4,
       2,     1,     3,     1,     3,     1,     3,     1,     4,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     5,
       4,     3,     2,     3,     1,     2,     6,     3,     1,     3,
       3,     3,     1,     3,     2,     3,     1,     3,     2,     1,
       2,     3,     4,     5,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     1,     3,
       3,     3,     3,     3,     1,     3,     1,     4,     1,     2,
       3,     1,     1,     1,     3,     5,     3,     1,     2,     0,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 86 "pars1.y" /* yacc.c:1646  */
    { parseresult = makeprogram((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1])); }
#line 1518 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makeprogn((yyvsp[-2]), cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1524 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 90 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makefuncall((TOKEN)talloc(), (yyvsp[-3]), (yyvsp[-1])); }
#line 1530 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "pars1.y" /* yacc.c:1646  */
    { (yyval) = dolabel((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1536 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makeif((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0])); }
#line 1542 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 93 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makefor(1, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1548 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makewhile((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1554 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 95 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makerepeat((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1560 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 96 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makegoto((yyvsp[0])->intval); }
#line 1566 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 100 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1572 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 103 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1578 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 106 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1584 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 107 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1590 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 109 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1596 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 112 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1602 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 115 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1608 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 118 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1614 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 121 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makeprogn((yyvsp[-2]), cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1620 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 123 "pars1.y" /* yacc.c:1646  */
    { instlabel((yyvsp[-2])); }
#line 1626 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 124 "pars1.y" /* yacc.c:1646  */
    { instlabel((yyvsp[0])); }
#line 1632 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 126 "pars1.y" /* yacc.c:1646  */
    { instconst((yyvsp[-4]), (yyvsp[-2])); }
#line 1638 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 127 "pars1.y" /* yacc.c:1646  */
    { instconst((yyvsp[-3]), (yyvsp[-1])); }
#line 1644 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 130 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1650 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 132 "pars1.y" /* yacc.c:1646  */
    { insttype((yyvsp[-2]), (yyvsp[0])); }
#line 1656 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 134 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1662 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 135 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instpoint((yyvsp[-1]), (yyvsp[0])); }
#line 1668 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 136 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instarray((yyvsp[-3]), (yyvsp[0])); }
#line 1674 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 137 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instrec((yyvsp[-2]), (yyvsp[-1])); }
#line 1680 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 139 "pars1.y" /* yacc.c:1646  */
    { (yyval) = findtype((yyvsp[0])); }
#line 1686 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 140 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instenum((yyvsp[-1])); }
#line 1692 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 141 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1698 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 143 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1704 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 144 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1710 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 146 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1716 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 147 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1722 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 149 "pars1.y" /* yacc.c:1646  */
    { instvars((yyvsp[-2]), (yyvsp[0])); }
#line 1728 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 151 "pars1.y" /* yacc.c:1646  */
    { (yyval) = findid((yyvsp[0])); }
#line 1734 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 152 "pars1.y" /* yacc.c:1646  */
    { (yyval) = reducedot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1740 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 153 "pars1.y" /* yacc.c:1646  */
    { (yyval) = dopoint((yyvsp[-1]), (yyvsp[0])); }
#line 1746 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 156 "pars1.y" /* yacc.c:1646  */
    { (yyval) = arrayref((yyvsp[-1]), NULL, (yyvsp[0]), NULL); }
#line 1752 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 158 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1758 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 159 "pars1.y" /* yacc.c:1646  */
    { (yyval) = nconc((yyvsp[-2]), (yyvsp[0])); }
#line 1764 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 161 "pars1.y" /* yacc.c:1646  */
    { (yyval) = nconc(instfields((yyvsp[-4]), (yyvsp[-2])), (yyvsp[0])); }
#line 1770 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 162 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instfields((yyvsp[-2]), (yyvsp[0])); }
#line 1776 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 164 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1782 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 165 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1788 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 166 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1794 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 167 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1800 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 168 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1806 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 169 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1812 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 172 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1818 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 173 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1824 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 174 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1830 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 177 "pars1.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1836 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 178 "pars1.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1842 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 181 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1848 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 182 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1854 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 183 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1860 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 184 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1866 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 185 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1872 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 188 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1878 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 190 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makefuncall((TOKEN)talloc(), (yyvsp[-3]), (yyvsp[-1])); }
#line 1884 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 192 "pars1.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1890 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 193 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1896 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 197 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1902 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 198 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1908 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 199 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])); }
#line 1914 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 201 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-1]), (yyvsp[0])); }
#line 1920 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 202 "pars1.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1926 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 204 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1932 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 205 "pars1.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1938 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 207 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1944 "pars1.tab.c" /* yacc.c:1646  */
    break;


#line 1948 "pars1.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 212 "pars1.y" /* yacc.c:1906  */



/* You should add your own debugging is below, and add debugging
   printouts to your programs.
   You will want to change DEBUG to turn off printouts once things
   are working.  */

#define DEBUG		31             /* set bits here for debugging, 0 = off  */
#define DB_CONS		1             /* bit to trace cons */
#define DB_BINOP	2             /* bit to trace binop */
#define DB_MAKEIF	4             /* bit to trace makeif */
#define DB_MAKEPROGN	8             /* bit to trace makeprogn */
#define DB_PARSERES	16             /* bit to trace parseresult */


 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int labeltable [1000]; 
   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */


TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { 
  //printf("\nin cons\n");fflush(0);
  item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");fflush(0);
         dbugprinttok(item);
         dbugprinttok(list);
       };
	  //printf("\nend cons\n");fflush(0);
    return item;
  }

TOKEN nconc(TOKEN lista, TOKEN listb) {
	//printf("\nin nconc\n");fflush(0);
	TOKEN list = lista;
	while(list->link != NULL) {
		list = list->link;
	}
	list->link = listb;
	//printf("\nend nconc\n");fflush(0);

	return list;
}

TOKEN findid(TOKEN tok) {
       //printf("\nin findid\n");fflush(0);

        //printf("\n f1\n");fflush(0);

        SYMBOL s;
        SYMBOL type;
        s = searchst(tok->stringval);
        //printf("\n f2\n");fflush(0);

        if(s == NULL) {
        //      return tok;
        }
        //printstlevel(1);
        tok->symentry = s;
        //printf("\n f3\n");fflush(0);

        type = s->datatype;
        //printf("\n f4\n");fflush(0);

        tok->symtype = type;

        //printf("\n f5\n");fflush(0);

        if (s->kind == CONSTSYM) {
                 if (s->basicdt == REAL) {
                        //printf("\n f6\n");fflush(0);

                        tok->tokentype = NUMBERTOK;
                        tok->datatype = REAL;
                        tok->realval = s->constval.realnum;
                } else if (s->basicdt == INTEGER) {
                        //printf("\n f7\n");fflush(0);

                        tok->tokentype = NUMBERTOK;
                        tok->datatype = INTEGER;
                        tok->intval = s->constval.intnum;
                }
        } else if( s->datatype->kind == TYPESYM && s->datatype->datatype->kind == POINTERSYM ) {
                //printf("\n f8\n");fflush(0);
                tok->symtype = s->datatype->datatype->datatype;
        }
        //printf("\nend findid\n");fflush(0);

        return tok;	
}

TOKEN unaryop(TOKEN op, TOKEN lhs) {
	//printf("\nin unaryop");
	op->operands = lhs;
	lhs->link = NULL;
	return op;
	//printf("\nend unaryop");
}

int isReal(TOKEN tok) {
	SYMBOL s = searchst(tok->stringval);
	if(s->basicdt == REAL)
		return 1;
	else
		return 0;
}

int isInt(TOKEN tok) {
	SYMBOL s = searchst(tok->stringval);
	if(s->basicdt == INTEGER)
		return 1;
	else
		return 0;
}

int isId(TOKEN tok) {
	if(tok->tokentype == IDENTIFIERTOK)	
		return 1;
	else
		return 0;
}

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { 
    //printf("\nin binop\n");fflush(0);
  op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */

if (isId(lhs)) {
	if (isId(rhs)) {
		if (isReal(lhs) && isReal(rhs)) {
			op->datatype = REAL;
		} else if (isReal(lhs) && isInt(rhs)) {
			op->datatype = REAL;
			TOKEN floattok = makeop(FLOATOP);
			floattok->operands = rhs;
			lhs->link = floattok;
		} else if (isInt(lhs) && isReal(rhs)) {
			if (op->whichval == ASSIGNOP) {
				TOKEN fixtok = makeop(FIXOP);
				fixtok->operands =rhs;
				lhs->link = fixtok;
			} else {
				op->datatype = REAL;
				TOKEN floattok = makeop(FLOATOP);
				floattok->operands = lhs;
				floattok->link = rhs;
			}
		}
	} else {
		if (isReal(lhs) && (rhs->datatype == REAL)) {
			op->datatype = REAL;
		} else if (isReal(lhs) && (rhs->datatype == INTEGER)) {
			op->datatype = REAL;
			rhs->datatype = REAL;
			rhs->realval = (double) rhs->intval;
		} else if (isInt(lhs) && (rhs->datatype == REAL)) {
			if (op->whichval == ASSIGNOP) {
				if (rhs->tokentype == NUMBERTOK) {
					rhs->datatype = INTEGER;
					rhs->intval = (int) rhs->realval;
				} else if (rhs->tokentype == IDENTIFIERTOK || rhs->tokentype == OPERATOR) {
					TOKEN fixtok = makeop(FIXOP);
					fixtok->operands = rhs;
					lhs->link = fixtok;           
				}
			} else {
				op->datatype = REAL;
				TOKEN floattok = makeop(FLOATOP);
				floattok->operands = lhs;
				floattok->link = rhs;
			}
		}
	}
} else {
	if (isId(rhs)) {
		if ((lhs->datatype == REAL) && isReal(rhs)) {
			op->datatype = REAL;
		} else if ((lhs->datatype == INTEGER) && isReal(rhs)) {
			op->datatype = REAL;
			lhs->datatype = REAL;
			lhs->realval = (double) lhs->intval;
		} else if ((lhs->datatype == REAL) && isInt(rhs)) {
			op->datatype = REAL;
			TOKEN floattok = makeop(FLOATOP);
			floattok->operands = rhs;
			lhs->link = floattok;
		}
	} else {
		if ((lhs->datatype == REAL) && (rhs->datatype == REAL)) {
			op->datatype = REAL;
		} else if ((lhs->datatype == INTEGER) && (rhs->datatype == REAL)) {
			op->datatype = REAL;
			lhs->datatype = REAL;
			lhs->realval = (double) lhs->intval;
		} else if ((lhs->datatype == REAL) && (rhs->datatype == INTEGER)) {
			op->datatype = REAL;
			rhs->datatype = REAL;
			rhs->realval = (double) rhs->intval;
		}        
	}
}

    if (DEBUG & DB_BINOP)
       { printf("binop\n");fflush(0);
         dbugprinttok(op);
         dbugprinttok(lhs);
         dbugprinttok(rhs);
       };
	  //printf("\nend binop\n");fflush(0);
    return op;
  }

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart) {
	  //printf("\nin makeif\n");fflush(0);
	tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");fflush(0);
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
  //printf("\nend makeif\n");fflush(0);
     return tok;
   }

TOKEN findtype(TOKEN tok) {
	//printf("\nin findtype\n");fflush(0);
	tok->symtype = searchst(tok->stringval);
	//printf("\nend findtype\n");fflush(0);
	return tok;
}

void instconst(TOKEN idtok, TOKEN consttok) {
	//printf("\nin instconst\n");fflush(0);
	SYMBOL s;
	SYMBOL type;
//	type = idtok->symtype;
//	int align = alignsize(type);
//	i = alignsize(type);

	s = insertsym(idtok->stringval);
	s->datatype = type;
	s->kind = CONSTSYM;
//	s->size = type->size;
	s->basicdt = consttok->datatype;
	if(s->basicdt == REAL) {
	        s->constval.realnum = consttok->realval;
	}
	if(s->basicdt == INTEGER) {
	        s->constval.intnum = consttok->intval;
	}
	//printf("\nend instconst\n");fflush(0);
}

void instvars(TOKEN idlist, TOKEN typetok) {
	//printf("\n in instvars\n");fflush(0);
	SYMBOL s;
	SYMBOL type;
	int i;
	type = typetok->symtype;
	//dbugprinttok(idlist);
	//dbugprinttok(typetok);
	//ppsym(type);
	//printstlevel(1);
	i = alignsize(type);
	while ( idlist != NULL ) {
                s = insertsym(idlist->stringval);
                s->datatype = type;
                s->kind = VARSYM;
                s->size = type->size;
                s->basicdt = type->basicdt;
                s->offset = wordaddress(blockoffs[blocknumber], i);
                blockoffs[blocknumber] = s->offset + s->size;
                idlist = idlist->link;
        };
	//printf("\n end instvars\n");fflush(0);
}

void instlabel (TOKEN num) {
	//printf("\n in instlabel\n");fflush(0);
	labeltable[labelnumber++] = num->intval;
	//printf("\n end instlabel\n");fflush(0);
}

TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) {
	//printf("\nin dolabel\n");fflush(0);

	TOKEN progn = makeprogn(tok, statement);
	TOKEN label = talloc();
	label->tokentype = OPERATOR;
	label->whichval = LABELOP;
	label->operands = labeltok;
	int i = 0;
	while(labeltable[i] != labeltok->intval) {
		i++;
	}
	labeltok->intval = i;
	progn->operands = label;
	label->link = statement;

	//printf("\nend dolabel\n");fflush(0);
	
	return progn;
}

void insttype(TOKEN typename, TOKEN typetok) {
	//printf("\nin insttype\n");fflush(0);
	SYMBOL sym, typesym;
	typesym = typetok->symtype;
	
//	printstlevel(1);
	sym = searchins(typename->stringval);
//	dbugprinttok(typename);
	sym->datatype = typesym;
	sym->kind = TYPESYM;
	sym->size = typesym->size;
	sym->basicdt = typesym->basicdt;
	
//	printstlevel(1);
	
	//printf("\nend insttype\n");fflush(0);
}

TOKEN instpoint(TOKEN tok, TOKEN typename) {
	//printf("\nin instpoint\n");fflush(0);
	SYMBOL ptrsym, sym;
	ptrsym = symalloc();
	ptrsym->kind = POINTERSYM;
	ptrsym->basicdt = POINTER;
	ptrsym->size = basicsizes[POINTER];
	tok->symtype = ptrsym;
	sym = searchins(typename->stringval);
	sym->kind = TYPESYM;
	ptrsym->datatype = sym;

	tok->datatype = POINTER;
	//printstlevel(1);
	//dbugprinttok(tok);
	//printf("\nend instpoint\n");fflush(0);
	return tok;
}

TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok) {
	//printf("\nin instdotdot\n");fflush(0);
	TOKEN t = makesubrange(dottok, lowtok->intval, hightok->intval);
	//printf("\nend instdotdot\n");fflush(0);
	return t;
}

TOKEN instarray(TOKEN bounds, TOKEN typetok) {
	//printf("\nin instarray\n");fflush(0);
	SYMBOL s = makesym("array");
	//printf("\n a1\n");fflush(0);
	
	//printf("\n%d , %d\n", bounds->symtype->lowbound, bounds->symtype->highbound);
	//dbugprinttok(bounds);
	//dbugprinttok(typetok);
	
	s->kind = ARRAYSYM;
	s->datatype = typetok->symtype;
	s->lowbound = bounds->symtype->lowbound;
	s->highbound = bounds->symtype->highbound;


	//printf("\n%p \n", s->datatype);fflush(0);
	//printf("\n a2\n");fflush(0);
	int size = s->datatype->size * (s->highbound - s->lowbound + 1);
	s->size = size;
	//printf("\n a3\n");fflush(0);

	TOKEN t;
	if(bounds->link) {
	//printf("\n a4\n");fflush(0);

		int low = bounds->link->symtype->datatype->lowbound;
		int high = bounds->link->symtype->datatype->highbound;
		TOKEN subrange = makesubrange(copytok(typetok), low, high);
		t = instarray(subrange, typetok);
		s->datatype = t->symtype;
		s->size = s->datatype->size * (s->highbound - s->lowbound + 1);
	}

	//printf("\n a5\n");fflush(0);
	
	typetok->symtype = s;
	
	//printf("\nend instarray\n");fflush(0);
	return typetok;
}

TOKEN instrec(TOKEN rectok, TOKEN argstok) {
	//printf("\nin instrec\n");fflush(0);

	int size, offset;
	SYMBOL s = symalloc();
	s->kind = RECORDSYM;
	rectok->symtype = s;
	s->datatype = argstok->symtype;
	offset = wordaddress(argstok->symtype->size, 8);
	size = offset;
	TOKEN curr = argstok;
	TOKEN next = argstok->link;
	while(next) {
		curr->symtype->link = next->symtype;
		offset = wordaddress(next->symtype->size, 8);
		next->symtype->offset = size;
		size += offset;
		curr = next;
		next = next->link;
	}
	s->size = size;
	//printf("\nend instrec\n");fflush(0);
	return rectok;
}

TOKEN instfields(TOKEN idlist, TOKEN typetok) {
	//printf("\n in instfields\n");fflush(0);

	int next = 0;
	int offset = 0;

	SYMBOL recsym, typesym;

	TOKEN temp = idlist;

	while (temp) {
		typesym = searchst(typetok->stringval);
		recsym = makesym(temp->stringval);
		recsym->datatype = typesym;
		offset = next;
		next = next + typesym->size;

		recsym->offset = offset;
		recsym->size = typesym->size;
		recsym->datatype = typesym;

		if (typesym->kind == BASICTYPE) {
			recsym->basicdt = typesym->basicdt;
		}

		temp->symtype = recsym;

		temp = temp->link;
	}

	return idlist;
}

TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement) {
	//printf("\nin makewhile\n");fflush(0);
	TOKEN label = talloc();
	label->tokentype = OPERATOR;
	label->whichval = LABELOP;

	TOKEN number = talloc();
	number->tokentype = NUMBERTOK;
	number->intval = labelnumber++;
	label->operands = number;

	TOKEN progn = makeprogn(tok, label);

	TOKEN ifop = talloc();
	ifop->tokentype = OPERATOR;
	ifop->whichval = IFOP;
	TOKEN iftok = unaryop(ifop, expr);
	
	label->link = ifop;
	iftok->operands->link = statement;
	
	TOKEN temp = statement->operands;

	while(temp->link) {
		//printf("\n in makewhile\n");fflush(0);
		temp = temp->link;
	}
	printf("endmakewhile\n");fflush(0);

	TOKEN gototok = talloc();
	gototok->tokentype = OPERATOR;
	gototok->whichval = GOTOOP;
	TOKEN gotonum = copytok(number);
	temp->link = unaryop(gototok, gotonum);
	
	//printf("\nend makewhile\n");fflush(0);

	return progn;
}

TOKEN instenum(TOKEN idlist) {
	//printf("\n in instenum\n");fflush(0);

	int low = 0;
	int high = 0;
	TOKEN t = idlist;
	while(t) {
		t = t->link;
		high++;
	}
	TOKEN subrange = makesubrange(copytok(idlist), low, high - 1);
	t = idlist;
	TOKEN number = copytok(idlist);
	number->tokentype = NUMBERTOK;
	number->datatype = INTEGER;
	
	int i = 0;
	for(; i < high; i++) {
		number->intval = i;
		instconst(t, number);
		number = copytok(number);
		t = t->link;
	}

	//printf("\n end instenum\n");fflush(0);

	return subrange;
}

TOKEN makesubrange(TOKEN tok, int low, int high) {
	//printf("\nin makesubrange\n");fflush(0);
	TOKEN out = copytok(tok);
	SYMBOL subrange = symalloc();
	subrange->kind = SUBRANGE;
	subrange->basicdt = INTEGER;
	subrange->lowbound = low;
	subrange->highbound = high;
	subrange->size = basicsizes[INTEGER];
	out->symtype = subrange;

	//printf("\nend makesubrange\n");fflush(0);
	return out;
}

TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
	//printf("\n in arrayref\n");fflush(0);
	int i = 0;
	int is2d = 0;
	if(subs->link) {
		is2d = 1;
	}

	TOKEN t;
	SYMBOL s = searchst(arr->stringval);
	SYMBOL type = s->datatype->datatype->datatype;
	SYMBOL prevtype = s->datatype;

	if(is2d) {
		type = s->datatype->datatype;
		if(subs->tokentype == IDENTIFIERTOK) {
			
			TOKEN size = talloc();
			size->tokentype = NUMBERTOK;
			size->datatype = INTEGER;
			size->intval = type->size;
			
			TOKEN top = talloc();
			top->tokentype = OPERATOR;
			top->whichval = TIMESOP;
			
			t = binop(top, size, subs);
			TOKEN plus = copytok(top);
			plus->whichval = PLUSOP;
			TOKEN neg = copytok(size);
			neg->intval = -neg->intval + 4;
			t = binop(plus, neg, t);
			i = 1;
		}	
		
		int offset = type->size * (subs->intval - 1);
		TOKEN aref = talloc();
		aref->tokentype = OPERATOR;
		aref->whichval = AREFOP;
		aref->operands = arr;
		
		if(i) {
			arr->link = t;
		} else {
			subs->intval = offset;
			arr->link = subs;
		}
		aref->symtype = prevtype;				
		//printf("\n end arrayref\n");fflush(0);
		return aref;
	} else {
		if(subs->tokentype == IDENTIFIERTOK) {
			TOKEN size = talloc();
			size->tokentype = NUMBERTOK;
			size->datatype = INTEGER;
			size->intval = type->size;
			
			TOKEN top = talloc();
			top->tokentype = OPERATOR;
			top->whichval = TIMESOP;
			
			t = binop(top, size, subs);
			TOKEN plus = copytok(top);
			plus->whichval = PLUSOP;
			TOKEN neg = copytok(size);
			neg->intval = -neg->intval;
			t = binop(plus, neg, t);
			i = 1;
		}	
		
		int offset = type->size * (subs->intval - 1);
		TOKEN aref = talloc();
		aref->tokentype = OPERATOR;
		aref->whichval = AREFOP;
		aref->operands = arr;
		if(i) {
			arr->link = t;
		} else {
			subs->intval = offset;
			arr->link = subs;
		}
		aref->symtype = prevtype;
		//printf("\n end arrayref\n");fflush(0);				
		return aref;
	}
}


TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
	int ispointer = 0;
	SYMBOL fields = var->symtype->datatype->datatype->datatype;
	while(fields) {
		if(strcmp(fields->namestring, field->stringval) == 0) {
			ispointer = 1;
		}
		fields = fields->link;
	}
	SYMBOL s;
	if(ispointer) {
		s = var->symtype->datatype->datatype->datatype;
		int offset = 0;
		while(s && (strcmp(s->namestring, field->stringval) != 0)) {
			offset += s->size;
			if((offset % 8 != 0) && (s->size == 8)){
				offset += 4;
			}
			s = s->link;
		}
		var->operands->link->intval += offset;
		
		return var;
	} else {
		SYMBOL r = var->symtype->datatype->datatype->datatype;
		s = r->datatype->datatype;
		TOKEN aref = talloc();
		aref->tokentype = OPERATOR;
		aref->whichval = AREFOP;
		aref->operands = var;
	
		int offset = 0;
		while(s && (strcmp(s->namestring, field->stringval) != 0)) {
			offset += s->size;
			if((offset % 8 != 0) && (s->size == 8)) {
				offset += 4;
			}
			s = s->link;
		}
		aref->symtype = s;
		
		if((offset % 8 != 0) && (s->size == 8)) {
				offset += 4;
		}
			
		TOKEN numtok = talloc();
		numtok->tokentype = NUMBERTOK;
		numtok->datatype = INTEGER;
		numtok->intval = offset;
		var->link = numtok;
	
		return aref;
	}
}

TOKEN dopoint(TOKEN var, TOKEN tok) {
	//printf("\n in dopoint\n");fflush(0);
	SYMBOL s = searchst(var->stringval);
	TOKEN t = talloc();
	t->tokentype = OPERATOR;
	t->whichval = POINTEROP;
	t->operands = var;
	
	if(var->whichval == AREFOP) {
		t->symtype = var->symtype;
		//printf("\n end dopoint\n");fflush(0);
		return t;
	} else {
		t->symtype = s;
		//printf("\n end dopoint\n");fflush(0);
		return t;
	}
}

TOKEN dogoto(TOKEN tok, TOKEN labeltok) {
	//printf("\nin dogoto\n");fflush(0);
	TOKEN t = talloc();
	t->tokentype = OPERATOR;
	t->whichval = GOTOOP;
	TOKEN number = talloc();
	number->tokentype = NUMBERTOK;
	int i = 0;
	while(labeltable[i] != labeltok->intval) {
		i++;
	}
	number->intval = i;
	t->operands = number;
	//printf("\nend dogoto\n");fflush(0);
	return t;
}

TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
	//printf("\nin makeprogram\n");fflush(0);
	TOKEN program = talloc();
	TOKEN aux = talloc();
	program->tokentype = OPERATOR;
	program->whichval = PROGRAMOP;
	program->operands = name;
	
	aux = makeprogn(aux, args);
	name->link = aux;
	aux->link = statements;
	
	//printf("\nend makeprogram\n");fflush(0);
	return program;
}

TOKEN makeop(int opnum) {
	TOKEN tok = talloc();
	tok->tokentype = OPERATOR;
	tok->whichval = opnum;
	return tok;
}

TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr) {
	int labelnum = labelnumber;
	TOKEN label = makelabel();
	tok = makeprogn(tok, label);

	TOKEN statetok = makeprogn(tokb, statements);
	label->link = statetok;
	TOKEN gototok = makegoto(labelnum);
	TOKEN progn = makeprogn((TOKEN)talloc(), NULL);
	progn->link = gototok;

	TOKEN iftok = talloc();
	iftok = makeif(iftok, expr, progn, gototok);
	statetok->link = iftok;

	return tok;
}

TOKEN copytok(TOKEN origtok) {
	//printf("\nin copytok\n");fflush(0);
	TOKEN newtok = talloc();
	newtok->tokentype = origtok->tokentype;
	newtok->datatype = origtok->datatype;
	newtok->symtype = origtok->symtype;
	newtok->symentry = origtok->symentry;
	newtok->operands = origtok->operands;
	newtok->link = origtok->link;
	newtok->whichval = origtok->whichval;
	newtok->intval = origtok->intval;
	newtok->realval = origtok->realval;

	//printf("\nend copytok\n");fflush(0);

	return newtok;
}

TOKEN makeintc(int num) {
	//printf("\nin makeintc\n");fflush(0);

	TOKEN tok = talloc();
	tok->tokentype = NUMBERTOK;
	tok->datatype = INTEGER;
	tok->intval = num;

	//printf("\nend makeintc\n");fflush(0);

	return tok;
}

TOKEN makegoto(int label) {
	//printf("\nin makegoto\n");fflush(0);

	TOKEN tok = talloc();
	tok->tokentype = OPERATOR;
	tok->whichval = GOTOOP;
	tok->operands = makeintc(label);
	
	//printf("\nend makegoto\n");fflush(0);

	return tok;
}

TOKEN makelabel() {
	//printf("\nin makelabel\n");fflush(0);

	TOKEN tok = talloc();
	tok->tokentype = OPERATOR;
	tok->whichval = LABELOP;
	tok->operands = makeintc(labelnumber);
	labelnumber+=1;
	//printf("\nend makelabel\n");fflush(0);

	return tok;
}

TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr, TOKEN tokc, TOKEN statement) {
	//printf("\nin makefor\n");fflush(0);

	tok = makeprogn(tok, asg);
	tok->operands = asg;
	TOKEN label = makelabel();
	asg->link = label;
	
	TOKEN condition = talloc();
	TOKEN stateprog = talloc();
	stateprog = makeprogn(stateprog, statement);
	
	TOKEN leop = makeop(LEOP);
	condition = makeif(condition, leop, stateprog, NULL);
	condition->operands = leop;

	TOKEN copy = copytok(asg->operands);
	leop->operands = copy;
	leop->link = stateprog;
	copy->link = endexpr;
	
	TOKEN plusop = makeop(PLUSOP);
	TOKEN copy2 = copytok(asg->operands);
	copy2->link = plusop;
	
	TOKEN i = makeintc(1);
	TOKEN copy3 = copytok(asg->operands);
	plusop->operands = copy3;
	copy3->link = i;

	TOKEN assign_op = makeop(ASSIGNOP);
	statement->link = assign_op;
	assign_op->link = makegoto(labelnumber - 1);
	label->link = condition;

	//printf("\nend makefor\n");fflush(0);

	return tok;
}


TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
	//printf("\nin makefuncall\n");fflush(0);	
	dbugprinttok(tok);
	dbugprinttok(fn);
	dbugprinttok(args);
	tok->operands = fn;
	tok->whichval = FUNCALLOP;
	tok->datatype = fn->datatype;
	
	fn->link = args;
	//printf("\nend makefuncall\n");fflush(0);	

	return tok;
}

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {
	//printf("\nin makeprog\n");fflush(0);	
  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");fflush(0);
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
	//printf("\nend makeprog\n");fflush(0);	

     return tok;
   }

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

int main(void)          /*  */
  { int res;
    initsyms();
    res = yyparse();
//    printst();       /* to shorten, change to:  printstlevel(1);  */
	printstlevel(1);
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
    /* uncomment following to call code generator. */
     /* 
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
 */
  }
