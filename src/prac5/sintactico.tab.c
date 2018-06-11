/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ENTERO = 258,
     REAL = 259,
     CADENA = 260,
     TIPO = 261,
     ID = 262,
     POW = 263
   };
#endif
/* Tokens.  */
#define ENTERO 258
#define REAL 259
#define CADENA 260
#define TIPO 261
#define ID 262
#define POW 263




/* Copy the first part of user declarations.  */
#line 1 "sintactico.y"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "op_cadenas.h"
#include "lista.h"
int yylex(void);
void yyerror(char *);
lista ts; //Se declara la lista en este caso Tabla de Simbolos
int flag_esta = 1; // Controla que las variables hayan sido declaradas
int flag_incompatibles=1; //Controla que los tipos de datos coincidan
int flag_op = 1; //controla las operaciones que no se pueden hacer
int flag_print = 0; // controla la impresion de resultado para hacer la que corresponde a su tipo puede ser 1, 2 o 3


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "sintactico.y"
{  /* especifica la colección completa de tipo de datos pibles */
  int entero;
  double flotante;
  char* str;
  Valor valor;
  elemento elem;
}
/* Line 193 of yacc.c.  */
#line 136 "sintactico.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 149 "sintactico.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   398

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  19
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNRULES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   263

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      14,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      15,    17,    12,    10,    16,    11,     2,    13,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    18,
       2,     9,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    21,
      24,    27,    30,    32,    35,    38,    42,    46,    50,    54,
      61,    63,    66,    69,    73,    77,    81,    85,    92,    96,
     100,   104,   108,   115,   119,   123,   127,   131,   138,   140,
     144,   148,   150,   153,   157,   161,   165,   169,   173,   177,
     181,   185,   189,   193,   197,   201,   205,   209,   213,   217,
     221,   225,   229,   233,   237,   241,   245,   249,   253,   257,
     261,   265,   272,   279,   286,   293,   300,   307,   314,   318,
     324,   330,   336,   342,   347,   352,   357,   362,   367,   372,
     377,   382,   385,   389,   393,   397
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      20,     0,    -1,    -1,    20,    21,    -1,    14,    -1,    22,
      14,    -1,    23,    14,    -1,    24,    14,    -1,    26,    14,
      -1,    27,    14,    -1,    25,    14,    -1,    28,    14,    -1,
       3,    -1,    11,    22,    -1,    10,    22,    -1,    22,    10,
      22,    -1,    22,    11,    22,    -1,    22,    12,    22,    -1,
      22,    13,    22,    -1,     8,    15,    22,    16,    22,    17,
      -1,     4,    -1,    11,    23,    -1,    10,    23,    -1,    23,
      10,    23,    -1,    23,    11,    23,    -1,    23,    12,    23,
      -1,    23,    13,    23,    -1,     8,    15,    23,    16,    23,
      17,    -1,    22,    10,    23,    -1,    22,    11,    23,    -1,
      22,    12,    23,    -1,    22,    13,    23,    -1,     8,    15,
      22,    16,    23,    17,    -1,    23,    10,    22,    -1,    23,
      11,    22,    -1,    23,    12,    22,    -1,    23,    13,    22,
      -1,     8,    15,    23,    16,    22,    17,    -1,     5,    -1,
      24,    10,    24,    -1,    24,    11,    24,    -1,     7,    -1,
      11,    25,    -1,    25,    10,    25,    -1,    25,    10,    22,
      -1,    25,    10,    23,    -1,    25,    10,    24,    -1,    22,
      10,    25,    -1,    23,    10,    25,    -1,    24,    10,    25,
      -1,    25,    11,    25,    -1,    25,    11,    22,    -1,    25,
      11,    23,    -1,    25,    11,    24,    -1,    22,    11,    25,
      -1,    23,    11,    25,    -1,    24,    11,    25,    -1,    25,
      12,    25,    -1,    25,    12,    22,    -1,    25,    12,    23,
      -1,    25,    12,    24,    -1,    22,    12,    25,    -1,    23,
      12,    25,    -1,    24,    12,    25,    -1,    25,    13,    25,
      -1,    25,    13,    22,    -1,    25,    13,    23,    -1,    25,
      13,    24,    -1,    22,    13,    25,    -1,    23,    13,    25,
      -1,    24,    13,    25,    -1,     8,    15,    25,    16,    25,
      17,    -1,     8,    15,    25,    16,    22,    17,    -1,     8,
      15,    25,    16,    23,    17,    -1,     8,    15,    25,    16,
      24,    17,    -1,     8,    15,    22,    16,    25,    17,    -1,
       8,    15,    23,    16,    25,    17,    -1,     8,    15,    24,
      16,    25,    17,    -1,     6,     7,    18,    -1,     6,     7,
       9,    25,    18,    -1,     6,     7,     9,    22,    18,    -1,
       6,     7,     9,    23,    18,    -1,     6,     7,     9,    24,
      18,    -1,     7,     9,    22,    18,    -1,     7,     9,    23,
      18,    -1,     7,     9,    24,    18,    -1,     7,     9,    25,
      18,    -1,     6,     7,     9,    25,    -1,     6,     7,     9,
      22,    -1,     6,     7,     9,    23,    -1,     6,     7,     9,
      24,    -1,     6,     7,    -1,     7,     9,    22,    -1,     7,
       9,    23,    -1,     7,     9,    24,    -1,     7,     9,    25,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    45,    48,    49,    50,    51,    52,    53,
      54,    72,    75,    76,    77,    78,    79,    80,    81,    83,
      86,    87,    88,    89,    90,    91,    92,    94,    95,    96,
      97,    98,   100,   101,   102,   103,   104,   106,   110,   111,
     117,   126,   143,   162,   231,   250,   269,   287,   310,   333,
     355,   419,   438,   457,   476,   499,   522,   544,   608,   627,
     646,   673,   696,   719,   750,   794,   809,   824,   847,   866,
     885,   912,   956,   971,   986,  1009,  1028,  1047,  1074,  1101,
    1174,  1208,  1241,  1265,  1298,  1330,  1361,  1428,  1429,  1430,
    1431,  1432,  1433,  1434,  1435,  1436
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTERO", "REAL", "CADENA", "TIPO", "ID",
  "POW", "'='", "'+'", "'-'", "'*'", "'/'", "'\\n'", "'('", "','", "')'",
  "';'", "$accept", "input", "line", "exp_e", "exp_f", "exp_c", "expVar",
  "decl", "asig", "err", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,    61,
      43,    45,    42,    47,    10,    40,    44,    41,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    19,    20,    20,    21,    21,    21,    21,    21,    21,
      21,    21,    22,    22,    22,    22,    22,    22,    22,    22,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    24,    24,
      24,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    26,    26,
      26,    26,    26,    27,    27,    27,    27,    28,    28,    28,
      28,    28,    28,    28,    28,    28
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     3,     3,     3,     3,     6,
       1,     2,     2,     3,     3,     3,     3,     6,     3,     3,
       3,     3,     6,     3,     3,     3,     3,     6,     1,     3,
       3,     1,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     6,     6,     6,     6,     6,     6,     6,     3,     5,
       5,     5,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     2,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    12,    20,    38,     0,    41,     0,     0,
       0,     4,     3,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,     0,     0,    14,    22,    41,    13,    21,
       0,    42,     0,     0,     0,     0,     5,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     7,     0,     0,     0,
       0,    10,     8,     9,    11,     0,    78,    92,    93,    94,
      95,     0,     0,     0,     0,     0,    13,    21,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    28,    47,    16,
      29,    54,    17,    30,    61,    18,    31,    68,    33,    23,
      48,    34,    24,    55,    35,    25,    62,    36,    26,    69,
       0,     0,    39,    49,    40,    56,    63,    70,    44,    45,
      46,    43,    51,    52,    53,    50,    58,    59,    60,    57,
      65,    66,    67,    64,    88,    89,    90,    87,    83,    84,
      85,    86,     0,     0,     0,     0,     0,     0,    15,    28,
      16,    29,    17,    30,    18,    31,    33,    23,    34,    24,
      35,    25,    36,    26,    80,    81,    82,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    32,    75,    37,    27,    76,    77,    72,    73,
      74,    71,     0,     0,     0,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    12,   100,   101,    30,    16,    17,    18,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -9
static const yytype_int16 yypact[] =
{
      -9,   152,    -9,    -9,    -9,    -9,    -5,     5,     2,    47,
       8,    -9,    -9,    -7,    31,   259,   376,    42,    45,    62,
      -8,     8,     8,     7,    47,    12,    40,    -9,    50,    53,
     160,    87,     8,     8,     8,     8,    -9,     8,     8,     8,
       8,    -9,     8,     8,     8,     8,    -9,     8,     8,     8,
       8,    -9,    -9,    -9,    -9,     8,    -9,    17,    67,    92,
     107,   125,   341,   348,   355,    47,    12,    40,    47,    47,
      47,    47,    47,    47,    47,    47,    50,    53,    87,    50,
      53,    87,    -9,    -9,    -9,    -9,    -9,    -9,    50,    53,
      87,    50,    53,    87,    -9,    -9,    -9,    -9,    -9,    -9,
     381,   385,   103,    87,   103,    87,    -9,    -9,    50,    53,
     103,    87,    50,    53,   103,    87,    -9,    -9,    -9,    -9,
      -9,    -9,    -9,    -9,   184,   200,   204,   213,    -9,    -9,
      -9,    -9,     8,     8,     8,     8,   362,   369,    12,    40,
      12,    40,    -9,    -9,    -9,    -9,    12,    40,    12,    40,
      -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    80,   217,
     225,   235,   243,   251,   269,   277,   285,   293,   301,    47,
      47,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,
      -9,    -9,   309,   317,   325,   333
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
      -9,    -9,    -9,    -1,    74,    39,   143,    -9,    -9,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      13,    55,    20,    32,    33,    34,    35,    36,    25,    28,
      56,     3,     4,     5,    21,    27,     8,    22,     9,    10,
      57,    61,    65,    66,    70,    71,     0,    32,    33,    34,
      35,    76,    79,    82,    85,   128,    88,    91,    94,    97,
      15,    37,    38,    39,    40,    41,   108,   112,   116,   120,
       3,     4,    74,    75,   124,    23,    52,     9,    24,    53,
      59,    63,    34,    35,   136,    39,    40,   138,   140,   142,
     144,   146,   148,   150,   152,    14,    54,    37,    38,    39,
      40,   102,   104,    26,    29,   129,   110,   114,   118,   122,
      32,    33,    34,    35,   126,    58,    62,   171,    67,    49,
      50,     0,    42,    43,    44,    45,    77,    80,    83,    86,
     130,    89,    92,    95,    98,    44,    45,    47,    48,    49,
      50,   109,   113,   117,   121,   131,     0,     0,     0,   125,
       0,   158,   161,     0,   165,    32,    33,    34,    35,   137,
       0,   132,   139,   141,   143,   145,   147,   149,   151,   153,
       0,     0,     2,    31,     0,     3,     4,     5,     6,     7,
       8,     0,     9,    10,    60,    64,    11,     0,   182,   184,
      42,    43,    44,    45,   167,    78,    81,    84,    87,     0,
      90,    93,    96,    99,     0,   103,   105,   106,   107,     0,
     111,   115,   119,   123,    32,    33,    34,    35,   127,     0,
       0,     0,   154,     0,     0,     0,   159,   162,     0,   166,
      37,    38,    39,    40,    42,    43,    44,    45,   155,     0,
       0,     0,   156,    47,    48,    49,    50,    37,    38,    39,
      40,   157,     0,     0,   172,    47,    48,    49,    50,     0,
       0,     0,   173,   183,   185,    32,    33,    34,    35,     0,
       0,     0,   174,    37,    38,    39,    40,     0,     0,     0,
     175,    47,    48,    49,    50,     0,     0,     0,   176,    42,
      43,    44,    45,    46,     0,   160,   163,   164,   168,    47,
      48,    49,    50,     0,     0,     0,   177,    32,    33,    34,
      35,     0,     0,     0,   178,    37,    38,    39,    40,     0,
       0,     0,   179,    42,    43,    44,    45,     0,     0,     0,
     180,    47,    48,    49,    50,     0,     0,     0,   181,    68,
      69,    70,    71,     0,     0,     0,   171,    72,    73,    74,
      75,     0,     0,     0,   172,    68,    69,    70,    71,     0,
       0,     0,   174,    72,    73,    74,    75,     0,     0,     0,
     175,    37,    38,    39,    40,     0,     0,   133,    42,    43,
      44,    45,     0,     0,   134,    47,    48,    49,    50,     0,
       0,   135,    68,    69,    70,    71,     0,     0,   169,    72,
      73,    74,    75,     0,     0,   170,    47,    48,    49,    50,
      51,    32,    33,    34,    35,    37,    38,    39,    40
};

static const yytype_int16 yycheck[] =
{
       1,     9,     7,    10,    11,    12,    13,    14,     9,    10,
      18,     3,     4,     5,     9,     7,     8,    15,    10,    11,
      21,    22,    15,    24,    12,    13,    -1,    10,    11,    12,
      13,    32,    33,    34,    35,    18,    37,    38,    39,    40,
       1,    10,    11,    12,    13,    14,    47,    48,    49,    50,
       3,     4,    12,    13,    55,     8,    14,    10,    11,    14,
      21,    22,    12,    13,    65,    12,    13,    68,    69,    70,
      71,    72,    73,    74,    75,     1,    14,    10,    11,    12,
      13,    42,    43,     9,    10,    18,    47,    48,    49,    50,
      10,    11,    12,    13,    55,    21,    22,    17,    24,    12,
      13,    -1,    10,    11,    12,    13,    32,    33,    34,    35,
      18,    37,    38,    39,    40,    12,    13,    10,    11,    12,
      13,    47,    48,    49,    50,    18,    -1,    -1,    -1,    55,
      -1,   132,   133,    -1,   135,    10,    11,    12,    13,    65,
      -1,    16,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,     0,    10,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    21,    22,    14,    -1,   169,   170,
      10,    11,    12,    13,   135,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    -1,
      47,    48,    49,    50,    10,    11,    12,    13,    55,    -1,
      -1,    -1,    18,    -1,    -1,    -1,   132,   133,    -1,   135,
      10,    11,    12,    13,    10,    11,    12,    13,    18,    -1,
      -1,    -1,    18,    10,    11,    12,    13,    10,    11,    12,
      13,    18,    -1,    -1,    17,    10,    11,    12,    13,    -1,
      -1,    -1,    17,   169,   170,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    10,    11,    12,    13,    -1,    -1,    -1,    17,    10,
      11,    12,    13,    14,    -1,   132,   133,   134,   135,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    10,    11,    12,    13,    -1,    -1,    -1,    17,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    10,    11,    12,    13,    -1,    -1,    16,    10,    11,
      12,    13,    -1,    -1,    16,    10,    11,    12,    13,    -1,
      -1,    16,    10,    11,    12,    13,    -1,    -1,    16,    10,
      11,    12,    13,    -1,    -1,    16,    10,    11,    12,    13,
      14,    10,    11,    12,    13,    10,    11,    12,    13
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,     0,     3,     4,     5,     6,     7,     8,    10,
      11,    14,    21,    22,    23,    24,    25,    26,    27,    28,
       7,     9,    15,     8,    11,    22,    23,     7,    22,    23,
      24,    25,    10,    11,    12,    13,    14,    10,    11,    12,
      13,    14,    10,    11,    12,    13,    14,    10,    11,    12,
      13,    14,    14,    14,    14,     9,    18,    22,    23,    24,
      25,    22,    23,    24,    25,    15,    22,    23,    10,    11,
      12,    13,    10,    11,    12,    13,    22,    23,    25,    22,
      23,    25,    22,    23,    25,    22,    23,    25,    22,    23,
      25,    22,    23,    25,    22,    23,    25,    22,    23,    25,
      22,    23,    24,    25,    24,    25,    25,    25,    22,    23,
      24,    25,    22,    23,    24,    25,    22,    23,    24,    25,
      22,    23,    24,    25,    22,    23,    24,    25,    18,    18,
      18,    18,    16,    16,    16,    16,    22,    23,    22,    23,
      22,    23,    22,    23,    22,    23,    22,    23,    22,    23,
      22,    23,    22,    23,    18,    18,    18,    18,    22,    23,
      25,    22,    23,    25,    25,    22,    23,    24,    25,    16,
      16,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    22,    23,    22,    23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 49 "sintactico.y"
    { printf("\tresultado: %d\n", (yyvsp[(1) - (2)].entero)); ;}
    break;

  case 6:
#line 50 "sintactico.y"
    { printf("\tresultado: %f\n", (yyvsp[(1) - (2)].flotante)); ;}
    break;

  case 7:
#line 51 "sintactico.y"
    { printf("\tresultado: %s\n", (yyvsp[(1) - (2)].str)); ;}
    break;

  case 10:
#line 54 "sintactico.y"
    {
                        if(flag_print==1){
                          printf("\tresultado: %d\n", (yyvsp[(1) - (2)].elem).valor.valor1);
                          flag_print = 0;
                        }
                        else if(flag_print==2){
                          printf("\tresultado: %f\n", (yyvsp[(1) - (2)].elem).valor.valor2);
                          flag_print = 0;
                        }
                        else if(flag_print==3){
                          printf("\tresultado: %s\n", (yyvsp[(1) - (2)].elem).valor.valor3);
                          flag_print = 0;
                        }
                        else
                          flag_incompatibles=1;
                          flag_op=1;
                          flag_esta=1;
                      ;}
    break;

  case 12:
#line 75 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (1)].entero); /*printf("%d\n", $1);*/ ;}
    break;

  case 13:
#line 76 "sintactico.y"
    { (yyval.entero) = ((yyvsp[(2) - (2)].entero))*(-1); ;}
    break;

  case 14:
#line 77 "sintactico.y"
    { (yyval.entero) = ((yyvsp[(2) - (2)].entero))*(-1); ;}
    break;

  case 15:
#line 78 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) + (yyvsp[(3) - (3)].entero); ;}
    break;

  case 16:
#line 79 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) - (yyvsp[(3) - (3)].entero); ;}
    break;

  case 17:
#line 80 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) * (yyvsp[(3) - (3)].entero); ;}
    break;

  case 18:
#line 81 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) / (yyvsp[(3) - (3)].entero); ;}
    break;

  case 19:
#line 83 "sintactico.y"
    { (yyval.entero) = pow((yyvsp[(3) - (6)].entero),(yyvsp[(5) - (6)].entero)); ;}
    break;

  case 20:
#line 86 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (1)].flotante); /*printf("%f\n", $1);*/ ;}
    break;

  case 21:
#line 87 "sintactico.y"
    { (yyval.flotante) = ((yyvsp[(2) - (2)].flotante))*(-1); ;}
    break;

  case 22:
#line 88 "sintactico.y"
    { (yyval.flotante) = ((yyvsp[(2) - (2)].flotante))*(-1); ;}
    break;

  case 23:
#line 89 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) + (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 24:
#line 90 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) - (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 25:
#line 91 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) * (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 26:
#line 92 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) / (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 27:
#line 94 "sintactico.y"
    { (yyval.flotante) = pow((yyvsp[(3) - (6)].flotante),(yyvsp[(5) - (6)].flotante)); ;}
    break;

  case 28:
#line 95 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].entero) + (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 29:
#line 96 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].entero) - (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 30:
#line 97 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].entero) * (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 31:
#line 98 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].entero) / (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 32:
#line 100 "sintactico.y"
    { (yyval.flotante) = pow((yyvsp[(3) - (6)].entero),(yyvsp[(5) - (6)].flotante)); ;}
    break;

  case 33:
#line 101 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) + (yyvsp[(3) - (3)].entero); ;}
    break;

  case 34:
#line 102 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) - (yyvsp[(3) - (3)].entero); ;}
    break;

  case 35:
#line 103 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) * (yyvsp[(3) - (3)].entero); ;}
    break;

  case 36:
#line 104 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) / (yyvsp[(3) - (3)].entero); ;}
    break;

  case 37:
#line 106 "sintactico.y"
    { (yyval.flotante) = pow((yyvsp[(3) - (6)].flotante),(yyvsp[(5) - (6)].entero)); ;}
    break;

  case 38:
#line 110 "sintactico.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); /*printf("%s\n", $1) */ ;}
    break;

  case 39:
#line 111 "sintactico.y"
    {
                            char* aux;
                            aux = concatenar((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
                            (yyval.str) = aux;
                          ;}
    break;

  case 40:
#line 117 "sintactico.y"
    {
                            char* aux;
                            aux = resta((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
                            (yyval.str) = aux;
                          ;}
    break;

  case 41:
#line 126 "sintactico.y"
    {
              posicion p;
              elemento e;
              elemento * e_ts;
              //limpiar $1
              e.name = (yyvsp[(1) - (1)].str);
              p = Search(&ts, e);
              if(p!=NULL){
                e_ts = getElement(&ts, p);
                (yyval.elem) = *e_ts;
              }
              else{
                printf("\n\t-->ERROR! no ha sido declarada previamente %s\n", (yyvsp[(1) - (1)].str));
                flag_esta = 0;
              }
            ;}
    break;

  case 42:
#line 143 "sintactico.y"
    {
                      if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                      elemento*e_aux; //Pasa una copia a $$ un tipo elemento
                      e_aux = &(yyvsp[(2) - (2)].elem);
                      (yyval.elem) = *e_aux;
                      if((yyval.elem).tipo == 1){
                        (yyval.elem).valor.valor1 = ((yyvsp[(2) - (2)].elem).valor.valor1)*(-1);
                        flag_print = 1;
                      }
                      else if((yyval.elem).tipo == 2){
                        (yyval.elem).valor.valor2 = ((yyvsp[(2) - (2)].elem).valor.valor2)*(-1);
                        flag_print = 2;
                      }
                      else if((yyval.elem).tipo == 3){
                        printf("\n\t-->ERROR! No hay cadenas negativas\n");
                      }
                      }
                    ;}
    break;

  case 43:
#line 162 "sintactico.y"
    {
                            //printf("$$.name: %s\n", $$.name);
                            //printf("$$.tipo: %d\n", $$.tipo);
                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                            if((yyval.elem).tipo == 1){
                              (yyval.elem).tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                              if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo==1){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 + (yyvsp[(3) - (3)].elem).valor.valor1;
                                flag_print=2;
                              }
                              else if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 + (yyvsp[(3) - (3)].elem).valor.valor2;
                                flag_print = 2;
                              }
                              else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 1){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 + (yyvsp[(3) - (3)].elem).valor.valor1;
                                flag_print = 2;
                              }
                              else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 + (yyvsp[(3) - (3)].elem).valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                            }
                            else if((yyval.elem).tipo ==2){
                              if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo==1){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 + (yyvsp[(3) - (3)].elem).valor.valor1;
                                flag_print = 2;
                              }
                              else if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 + (yyvsp[(3) - (3)].elem).valor.valor2;
                                flag_print = 2;
                              }
                              else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 1){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 + (yyvsp[(3) - (3)].elem).valor.valor1;
                                flag_print = 2;
                              }
                              else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 + (yyvsp[(3) - (3)].elem).valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print=0;
                              }
                            }
                            else if((yyval.elem).tipo == 3){
                              if((yyvsp[(1) - (3)].elem).tipo == 3 && (yyvsp[(3) - (3)].elem).tipo == 3){
                                (yyval.elem).valor.valor3 = concatenar((yyvsp[(1) - (3)].elem).valor.valor3, (yyvsp[(3) - (3)].elem).valor.valor3);
                                flag_print = 3;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print=0;
                              }
                            }
                            //printf("$$.name: %s\n", $$.name);
                            //printf("$$.tipo: %d\n", $$.tipo);
                            //printf("$$.valor: %f\n", $$.valor.valor2);
                            }
                          ;}
    break;

  case 44:
#line 231 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 + (yyvsp[(3) - (3)].entero);
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 + (yyvsp[(3) - (3)].entero);
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 45:
#line 250 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 + (yyvsp[(3) - (3)].flotante);
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 + (yyvsp[(3) - (3)].flotante);
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 46:
#line 269 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if ((yyval.elem).tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ((yyval.elem).tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if((yyval.elem).tipo == 3)
                                (yyval.elem).valor.valor3 = concatenar((yyvsp[(1) - (3)].elem).valor.valor3, (yyvsp[(3) - (3)].str));
                                flag_print = 3;
                              }
                            ;}
    break;

  case 47:
#line 287 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //para pasarle a $$ un tipo elemento
                              int aux = (yyvsp[(1) - (3)].entero);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = aux + (yyvsp[(3) - (3)].elem).valor.valor1;
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = aux + (yyvsp[(3) - (3)].elem).valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 48:
#line 310 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              double aux = (yyvsp[(1) - (3)].flotante);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = aux + (yyvsp[(3) - (3)].elem).valor.valor1;
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = aux + (yyvsp[(3) - (3)].elem).valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 49:
#line 333 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              char * aux = (yyvsp[(1) - (3)].str);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if ((yyval.elem).tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ((yyval.elem).tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if((yyval.elem).tipo == 3)
                                (yyval.elem).valor.valor3 = concatenar(aux, (yyvsp[(3) - (3)].elem).valor.valor3);
                                flag_print = 3;
                              }
                            ;}
    break;

  case 50:
#line 355 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                                if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo==1){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 - (yyvsp[(3) - (3)].elem).valor.valor1;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 - (yyvsp[(3) - (3)].elem).valor.valor2;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 1){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 - (yyvsp[(3) - (3)].elem).valor.valor1;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 - (yyvsp[(3) - (3)].elem).valor.valor2;
                                  flag_print = 2;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              else if((yyval.elem).tipo ==2){
                                if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo==1){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 - (yyvsp[(3) - (3)].elem).valor.valor1;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 - (yyvsp[(3) - (3)].elem).valor.valor2;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 1){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 - (yyvsp[(3) - (3)].elem).valor.valor1;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 - (yyvsp[(3) - (3)].elem).valor.valor2;
                                  flag_print = 2;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              else if((yyval.elem).tipo == 3){
                                if((yyvsp[(1) - (3)].elem).tipo == 3 && (yyvsp[(3) - (3)].elem).tipo == 3){
                                  (yyval.elem).valor.valor3 = resta((yyvsp[(1) - (3)].elem).valor.valor3, (yyvsp[(3) - (3)].elem).valor.valor3);
                                  flag_print = 3;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              }

                            ;}
    break;

  case 51:
#line 419 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 - (yyvsp[(3) - (3)].entero);
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 - (yyvsp[(3) - (3)].entero);
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 52:
#line 438 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 - (yyvsp[(3) - (3)].flotante);
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 - (yyvsp[(3) - (3)].flotante);
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 53:
#line 457 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if ((yyval.elem).tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ((yyval.elem).tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if((yyval.elem).tipo == 3){
                                (yyval.elem).valor.valor3 = resta((yyvsp[(1) - (3)].elem).valor.valor3, (yyvsp[(3) - (3)].str));
                                flag_print = 3;
                              }
                              }
                            ;}
    break;

  case 54:
#line 476 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //para pasarle a $$ un tipo elemento
                              int aux = (yyvsp[(1) - (3)].entero);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = aux - (yyvsp[(3) - (3)].elem).valor.valor1;
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = aux - (yyvsp[(3) - (3)].elem).valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 55:
#line 499 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              double aux = (yyvsp[(1) - (3)].flotante);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = aux - (yyvsp[(3) - (3)].elem).valor.valor1;
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = aux - (yyvsp[(3) - (3)].elem).valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 56:
#line 522 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              char * aux = (yyvsp[(1) - (3)].str);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if ((yyval.elem).tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ((yyval.elem).tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if((yyval.elem).tipo == 3)
                                (yyval.elem).valor.valor3 = resta(aux, (yyvsp[(3) - (3)].elem).valor.valor3);
                                flag_print = 3;
                              }
                            ;}
    break;

  case 57:
#line 544 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                                if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo==1){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 * (yyvsp[(3) - (3)].elem).valor.valor1;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 * (yyvsp[(3) - (3)].elem).valor.valor2;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 1){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 * (yyvsp[(3) - (3)].elem).valor.valor1;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 * (yyvsp[(3) - (3)].elem).valor.valor2;
                                  flag_print = 2;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              else if((yyval.elem).tipo ==2){
                                if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo==1){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 * (yyvsp[(3) - (3)].elem).valor.valor1;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 * (yyvsp[(3) - (3)].elem).valor.valor2;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 1){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 * (yyvsp[(3) - (3)].elem).valor.valor1;
                                  flag_print = 2;
                                }
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 * (yyvsp[(3) - (3)].elem).valor.valor2;
                                  flag_print = 2;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              else if((yyval.elem).tipo == 3){
                                if((yyvsp[(1) - (3)].elem).tipo == 3 && (yyvsp[(3) - (3)].elem).tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                  flag_print = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              }
                            ;}
    break;

  case 58:
#line 608 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 * (yyvsp[(3) - (3)].entero);
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 * (yyvsp[(3) - (3)].entero);
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 59:
#line 627 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 * (yyvsp[(3) - (3)].flotante);
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 * (yyvsp[(3) - (3)].flotante);
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 60:
#line 646 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if ((yyval.elem).tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ((yyval.elem).tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if((yyval.elem).tipo == 3){
                                if((yyval.elem).tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                  flag_print = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              }
                            ;}
    break;

  case 61:
#line 673 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //para pasarle a $$ un tipo elemento
                              int aux = (yyvsp[(1) - (3)].entero);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = aux * (yyvsp[(3) - (3)].elem).valor.valor1;
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = aux * (yyvsp[(3) - (3)].elem).valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 62:
#line 696 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              double aux = (yyvsp[(1) - (3)].flotante);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = aux * (yyvsp[(3) - (3)].elem).valor.valor1;
                                flag_print = 2;
                              }
                              else if ((yyval.elem).tipo == 2){
                                (yyval.elem).valor.valor2 = aux * (yyvsp[(3) - (3)].elem).valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            ;}
    break;

  case 63:
#line 719 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              char * aux = (yyvsp[(1) - (3)].str);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if ((yyval.elem).tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ((yyval.elem).tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if((yyval.elem).tipo == 3){
                                if((yyval.elem).tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                  flag_print = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              }
                            ;}
    break;

  case 64:
#line 750 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                                if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo==1)
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].elem).valor.valor1;
                                else if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo == 2)
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].elem).valor.valor2;
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 1)
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].elem).valor.valor1;
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 2)
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].elem).valor.valor2;
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              else if((yyval.elem).tipo ==2){
                                if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo==1)
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].elem).valor.valor1;
                                else if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo == 2)
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].elem).valor.valor2;
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 1)
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].elem).valor.valor1;
                                else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 2)
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].elem).valor.valor2;
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              else if((yyval.elem).tipo == 3){
                                if((yyvsp[(1) - (3)].elem).tipo == 3 && (yyvsp[(3) - (3)].elem).tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            ;}
    break;

  case 65:
#line 794 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].entero);
                              }
                              else if ((yyval.elem).tipo == 2)
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].entero);
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            ;}
    break;

  case 66:
#line 809 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].flotante);
                              }
                              else if ((yyval.elem).tipo == 2)
                                (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].flotante);
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            ;}
    break;

  case 67:
#line 824 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if ((yyval.elem).tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if ((yyval.elem).tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if((yyval.elem).tipo == 3){
                                if((yyval.elem).tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            ;}
    break;

  case 68:
#line 847 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //para pasarle a $$ un tipo elemento
                              int aux = (yyvsp[(1) - (3)].entero);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = aux / (yyvsp[(3) - (3)].elem).valor.valor1;
                              }
                              else if ((yyval.elem).tipo == 2)
                                (yyval.elem).valor.valor2 = aux / (yyvsp[(3) - (3)].elem).valor.valor2;
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            ;}
    break;

  case 69:
#line 866 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              double aux = (yyvsp[(1) - (3)].flotante);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = aux / (yyvsp[(3) - (3)].elem).valor.valor1;
                              }
                              else if ((yyval.elem).tipo == 2)
                                (yyval.elem).valor.valor2 = aux / (yyvsp[(3) - (3)].elem).valor.valor2;
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            ;}
    break;

  case 70:
#line 885 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              char * aux = (yyvsp[(1) - (3)].str);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(3) - (3)].elem);
                              (yyval.elem) = *e_aux;
                              if ((yyval.elem).tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if ((yyval.elem).tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if((yyval.elem).tipo == 3){
                                if((yyval.elem).tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            ;}
    break;

  case 71:
#line 912 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                                if((yyvsp[(3) - (6)].elem).tipo == 1 && (yyvsp[(5) - (6)].elem).tipo==1)
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].elem).valor.valor1);
                                else if((yyvsp[(3) - (6)].elem).tipo == 1 && (yyvsp[(5) - (6)].elem).tipo == 2)
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].elem).valor.valor2);
                                else if((yyvsp[(3) - (6)].elem).tipo == 2 && (yyvsp[(5) - (6)].elem).tipo == 1)
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].elem).valor.valor1);
                                else if((yyvsp[(3) - (6)].elem).tipo == 2 && (yyvsp[(5) - (6)].elem).tipo == 2)
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].elem).valor.valor2);
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              else if((yyval.elem).tipo ==2){
                                if((yyvsp[(3) - (6)].elem).tipo == 1 && (yyvsp[(5) - (6)].elem).tipo==1)
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].elem).valor.valor1);
                                else if((yyvsp[(3) - (6)].elem).tipo == 1 && (yyvsp[(5) - (6)].elem).tipo == 2)
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].elem).valor.valor2);
                                else if((yyvsp[(3) - (6)].elem).tipo == 2 && (yyvsp[(5) - (6)].elem).tipo == 1)
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].elem).valor.valor1);
                                else if((yyvsp[(3) - (6)].elem).tipo == 2 && (yyvsp[(5) - (6)].elem).tipo == 2)
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].elem).valor.valor2);
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              else if((yyval.elem).tipo == 3){
                                if((yyvsp[(3) - (6)].elem).tipo == 3 && (yyvsp[(5) - (6)].elem).tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            ;}
    break;

  case 72:
#line 956 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].entero));
                              }
                              else if ((yyval.elem).tipo == 2)
                                (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].entero));
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            ;}
    break;

  case 73:
#line 971 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].flotante));
                              }
                              else if ((yyval.elem).tipo == 2)
                                (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].flotante));
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            ;}
    break;

  case 74:
#line 986 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if ((yyval.elem).tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if ((yyval.elem).tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if((yyval.elem).tipo == 3){
                                if((yyval.elem).tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            ;}
    break;

  case 75:
#line 1009 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //para pasarle a $$ un tipo elemento
                              int aux = (yyvsp[(3) - (6)].entero);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(5) - (6)].elem);
                              (yyval.elem) = *e_aux;
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = pow(aux , (yyvsp[(5) - (6)].elem).valor.valor1);
                              }
                              else if ((yyval.elem).tipo == 2)
                                (yyval.elem).valor.valor2 = pow(aux , (yyvsp[(5) - (6)].elem).valor.valor2);
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            ;}
    break;

  case 76:
#line 1028 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              double aux = (yyvsp[(3) - (6)].flotante);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(5) - (6)].elem);
                              (yyval.elem) = *e_aux;
                              if((yyval.elem).tipo == 1){
                                (yyval.elem).tipo = 2;
                                (yyval.elem).valor.valor2 = pow(aux , (yyvsp[(5) - (6)].elem).valor.valor1);
                              }
                              else if ((yyval.elem).tipo == 2)
                                (yyval.elem).valor.valor2 = pow(aux , (yyvsp[(5) - (6)].elem).valor.valor2);
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            ;}
    break;

  case 77:
#line 1047 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              char * aux = (yyvsp[(3) - (6)].str);   //guarda exp_e para no perder el valor
                              e_aux = &(yyvsp[(5) - (6)].elem);
                              (yyval.elem) = *e_aux;
                              if ((yyval.elem).tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if ((yyval.elem).tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if((yyval.elem).tipo == 3){
                                if((yyval.elem).tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            ;}
    break;

  case 78:
#line 1074 "sintactico.y"
    {
                      elemento e;
                      int tipo;

                      if(!strcmp((yyvsp[(1) - (3)].str), "int")){
                        tipo = 1;
                      }
                      else if(!strcmp((yyvsp[(1) - (3)].str), "double")){
                        tipo = 2;
                      }
                      else if(!strcmp((yyvsp[(1) - (3)].str), "string")){
                        tipo = 3;
                      }

                      e.name = (yyvsp[(2) - (3)].str);
                      e.tipo = tipo;

                      if(Buscar(&ts, e)){
                        printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", (yyvsp[(2) - (3)].str));
                      }
                      else{
                        Insert(&ts, e);
                        printf("\n\t Se agregó correctamente\n");
                        ImprimeTS(&ts);
                      }
                    ;}
    break;

  case 79:
#line 1101 "sintactico.y"
    {
                                      elemento e;
                                      //posicion p_expVar;

                                      //p_expVar = Search(&ts, $4);

                                      if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                        if(!strcmp((yyvsp[(1) - (5)].str), "int")){
                                          e.name = (yyvsp[(2) - (5)].str);
                                          e.tipo = 1;
                                          if((yyvsp[(4) - (5)].elem).tipo == 1)
                                            e.valor.valor1 = (yyvsp[(4) - (5)].elem).valor.valor1;
                                          else if((yyvsp[(4) - (5)].elem).tipo == 2)
                                            e.valor.valor1 = (yyvsp[(4) - (5)].elem).valor.valor2;
                                          else if((yyvsp[(4) - (5)].elem).tipo == 3)
                                            printf("\n\t---> ERROR! Incompatible types in assigment: %s is int and %s string", e.name, (yyvsp[(4) - (5)].elem).name);

                                          if(Buscar(&ts, e)){
                                            printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", (yyvsp[(2) - (5)].str));
                                          }
                                          else{
                                            Insert(&ts, e);
                                            printf("\n\t Se agregó correctamente\n");
                                            ImprimeTS(&ts);
                                          }
                                        }
                                        if(!strcmp((yyvsp[(1) - (5)].str), "double")){
                                          e.name = (yyvsp[(2) - (5)].str);
                                          e.tipo = 2;
                                          if((yyvsp[(4) - (5)].elem).tipo == 1)
                                            e.valor.valor2 = (yyvsp[(4) - (5)].elem).valor.valor1;
                                          else if((yyvsp[(4) - (5)].elem).tipo == 2)
                                            e.valor.valor2 = (yyvsp[(4) - (5)].elem).valor.valor2;
                                          else if((yyvsp[(4) - (5)].elem).tipo == 3)
                                            printf("\n\t---> ERROR! Incompatible types in assigment: %s is double and %s string", e.name, (yyvsp[(4) - (5)].elem).name);

                                          if(Buscar(&ts, e)){
                                            printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", (yyvsp[(2) - (5)].str));
                                          }
                                          else{
                                            Insert(&ts, e);
                                            printf("\n\t Se agregó correctamente\n");
                                            ImprimeTS(&ts);
                                          }
                                        }
                                        if(!strcmp((yyvsp[(1) - (5)].str), "string")){
                                          e.name = (yyvsp[(2) - (5)].str);
                                          e.tipo = 3;
                                          if((yyvsp[(4) - (5)].elem).tipo == 1)
                                            printf("\n\t---> ERROR! Incompatible types in assigment: %s is string and %s int", e.name, (yyvsp[(4) - (5)].elem).name);
                                          else if((yyvsp[(4) - (5)].elem).tipo == 2)
                                            printf("\n\t---> ERROR! Incompatible types in assigment: %s is string and %s double", e.name, (yyvsp[(4) - (5)].elem).name);
                                          else if((yyvsp[(4) - (5)].elem).tipo == 3)
                                            e.valor.valor3 = (yyvsp[(4) - (5)].elem).valor.valor3;

                                          if(Buscar(&ts, e)){
                                            printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", (yyvsp[(2) - (5)].str));
                                          }
                                          else{
                                            Insert(&ts, e);
                                            printf("\n\t Se agregó correctamente\n");
                                            ImprimeTS(&ts);
                                          }
                                        }
                                      }
                                      else{
                                        printf("\n\t-->ERROR! no se ha podido declarar %s\n", (yyvsp[(2) - (5)].str));
                                        flag_esta = 1;
                                        flag_incompatibles = 1;
                                        flag_op = 1;
                                      }
                                  ;}
    break;

  case 80:
#line 1174 "sintactico.y"
    {
                                    elemento e;

                                    if(!strcmp((yyvsp[(1) - (5)].str), "int")){
                                      e.name = (yyvsp[(2) - (5)].str);
                                      e.tipo = 1;
                                      e.valor.valor1 = (yyvsp[(4) - (5)].entero);
                                      if(Buscar(&ts, e)){
                                        printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", (yyvsp[(2) - (5)].str));
                                      }
                                      else{
                                        Insert(&ts, e);
                                        printf("\n\t Se agregó correctamente\n");
                                        ImprimeTS(&ts);
                                      }
                                    }
                                    else if(!strcmp((yyvsp[(1) - (5)].str), "double")){
                                      e.name = (yyvsp[(2) - (5)].str);
                                      e.tipo = 2;
                                      e.valor.valor2 = (yyvsp[(4) - (5)].entero);
                                      if(Buscar(&ts, e)){
                                        printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", (yyvsp[(2) - (5)].str));
                                      }
                                      else{
                                        Insert(&ts, e);
                                        printf("\n\t Se agregó correctamente\n");
                                        ImprimeTS(&ts);
                                      }
                                    }
                                    else if(!strcmp((yyvsp[(1) - (5)].str), "string")){
                                      printf("\n\t--->ERROR! Incompatible types in assigment\n");
                                    }
                                  ;}
    break;

  case 81:
#line 1208 "sintactico.y"
    {
                                  elemento e;
                                  if(!strcmp((yyvsp[(1) - (5)].str), "int")){
                                    e.name = (yyvsp[(2) - (5)].str);
                                    e.tipo = 1;
                                    e.valor.valor1 = (yyvsp[(4) - (5)].flotante);
                                    if(Buscar(&ts, e)){
                                      printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", (yyvsp[(2) - (5)].str));
                                    }
                                    else{
                                      Insert(&ts, e);
                                      printf("\n\t Se agregó correctamente\n");
                                      ImprimeTS(&ts);
                                    }
                                  }
                                  else if(!strcmp((yyvsp[(1) - (5)].str), "double")){
                                    e.name = (yyvsp[(2) - (5)].str);
                                    e.tipo = 2;
                                    e.valor.valor2 = (yyvsp[(4) - (5)].flotante);
                                    if(Buscar(&ts, e)){
                                      printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", (yyvsp[(2) - (5)].str));
                                    }
                                    else{
                                      Insert(&ts, e);
                                      printf("\n\t Se agregó correctamente\n");
                                      ImprimeTS(&ts);
                                    }
                                  }
                                  else if(!strcmp((yyvsp[(1) - (5)].str), "string")){
                                    printf("\n\t--->ERROR! Incompatible types in assigment\n");
                                  }
                                ;}
    break;

  case 82:
#line 1241 "sintactico.y"
    {
                                    elemento e;
                                    if(!strcmp((yyvsp[(1) - (5)].str), "int")){
                                      printf("\n\t--->ERROR! Incompatible types in assigment\n");
                                    }
                                    else if(!strcmp((yyvsp[(1) - (5)].str), "double")){
                                      printf("\n\t--->ERROR! Incompatible types in assigment\n");
                                    }
                                    else if(!strcmp((yyvsp[(1) - (5)].str), "string")){
                                      e.name = (yyvsp[(2) - (5)].str);
                                      e.tipo = 3;
                                      e.valor.valor3 = (yyvsp[(4) - (5)].str);
                                      if(Buscar(&ts, e)){
                                        printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", (yyvsp[(2) - (5)].str));
                                      }
                                      else{
                                        Insert(&ts, e);
                                        printf("\n\t Se agregó correctamente\n");
                                        ImprimeTS(&ts);
                                      }
                                    }
                                  ;}
    break;

  case 83:
#line 1265 "sintactico.y"
    {
                          elemento e;
                          posicion p;
                          elemento * e_ts;

                          e.name = (yyvsp[(1) - (4)].str);

                          p = Search(&ts,e);

                          if(p != NULL){
                            //printf("Posicion en la que encontre el elemento %p\n", p);
                            e_ts = getElement(&ts, p);
                            //printf("Elemento apuntado y guardado: %p\n", e_ts);

                            if(e_ts->tipo == 1){
                              e_ts->valor.valor1=(yyvsp[(3) - (4)].entero);
                              printf("\n\tAsignacion correcta\n");
                              ImprimeTS(&ts);
                            }
                            else if(e_ts->tipo == 2){
                              e_ts->valor.valor2=(yyvsp[(3) - (4)].entero);
                              printf("\n\tAsignacion correcta\n");
                              ImprimeTS(&ts);
                            }
                            else if(e_ts->tipo == 3){
                              printf("\n\t--->ERROR! Incompatible types in assigment\n");
                            }
                          }
                          else{
                            printf("\n\t-->ERROR! asignacion primero tiene que ser declarado %s\n", e.name);
                          }
                        ;}
    break;

  case 84:
#line 1298 "sintactico.y"
    {
                            elemento e;
                            posicion p;
                            elemento * e_ts;

                            e.name = (yyvsp[(1) - (4)].str);
                            p = Search(&ts,e);

                            if(p != NULL){
                              //printf("Posicion en la que encontre el elemento %p\n", p);
                              e_ts = getElement(&ts, p);
                              //printf("Elemento apuntado y guardado: %p\n", e_ts);

                              if(e_ts->tipo == 1){
                                e_ts->valor.valor1=(yyvsp[(3) - (4)].flotante);
                                printf("\n\tAsignacion correcta\n");
                                ImprimeTS(&ts);
                              }
                              else if(e_ts->tipo == 2){
                                e_ts->valor.valor2=(yyvsp[(3) - (4)].flotante);
                                printf("\n\tAsignacion correcta\n");
                                ImprimeTS(&ts);
                              }
                              else if(e_ts->tipo == 3){
                                printf("\n\t--->ERROR! Incompatible types in assigment\n");
                              }
                            }
                            else{
                              printf("\n\t-->ERROR! asignacion primero tiene que ser declarado %s\n", e.name);
                            }
                          ;}
    break;

  case 85:
#line 1330 "sintactico.y"
    {
                            elemento e;
                            posicion p;
                            elemento * e_ts;

                            e.name = (yyvsp[(1) - (4)].str);
                            p = Search(&ts,e);

                            if(p != NULL){
                              //printf("Posicion en la que encontre el elemento %p\n", p);
                              e_ts = getElement(&ts, p);
                              //printf("Elemento apuntado y guardado: %p\n", e_ts);

                              if(e_ts->tipo == 1){
                                printf("\n\t--->ERROR! Incompatible types in assigment\n");

                              }
                              else if(e_ts->tipo == 2){
                                printf("\n\t--->ERROR! Incompatible types in assigment\n");
                              }
                              else if(e_ts->tipo == 3){
                                e_ts->valor.valor3=(yyvsp[(3) - (4)].str);
                                printf("\n\tAsignacion correcta\n");
                                ImprimeTS(&ts);
                              }
                            }
                            else{
                              printf("\n\t-->ERROR! asignacion primero tiene que ser declarado %s\n", e.name);
                            }
                          ;}
    break;

  case 86:
#line 1361 "sintactico.y"
    {
                            elemento e;
                            posicion p;
                            elemento * e_ts;

                            e.name = (yyvsp[(1) - (4)].str);

                            p = Search(&ts, e);

                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              e_ts = getElement(&ts, p);
                              if(p != NULL){
                                e_ts = getElement(&ts, p);
                                if(e_ts->tipo == 1){
                                  if((yyvsp[(3) - (4)].elem).tipo == 1){
                                    e_ts->valor.valor1 = (yyvsp[(3) - (4)].elem).valor.valor1;
                                    printf("\n\tAsignacion correcta\n");
                                    ImprimeTS(&ts);
                                  }
                                  else if((yyvsp[(3) - (4)].elem).tipo == 2){
                                    e_ts->valor.valor1 = (yyvsp[(3) - (4)].elem).valor.valor2;
                                    printf("\n\tAsignacion correcta\n");
                                    ImprimeTS(&ts);
                                  }
                                  else if((yyvsp[(3) - (4)].elem).tipo == 3)
                                    printf("\n\t---> ERROR! Incompatible types in assigment: %s is string and %s int", e.name, (yyvsp[(3) - (4)].elem).name);
                                }
                                else if(e_ts->tipo == 2){
                                  if((yyvsp[(3) - (4)].elem).tipo == 1){
                                    e_ts->valor.valor2 = (yyvsp[(3) - (4)].elem).valor.valor1;
                                    printf("\n\tAsignacion correcta\n");
                                    ImprimeTS(&ts);
                                  }
                                  else if((yyvsp[(3) - (4)].elem).tipo == 2){
                                    e_ts->valor.valor2 = (yyvsp[(3) - (4)].elem).valor.valor2;
                                    printf("\n\tAsignacion correcta\n");
                                    ImprimeTS(&ts);
                                  }
                                  else if((yyvsp[(3) - (4)].elem).tipo == 3)
                                    printf("\n\t---> ERROR! Incompatible types in assigment: %s is string and %s double", e.name, (yyvsp[(3) - (4)].elem).name);
                                }
                                else if(e_ts->tipo == 3){
                                  if((yyvsp[(3) - (4)].elem).tipo == 1)
                                    printf("\n\t---> ERROR! Incompatible types in assigment: %s is int and %s string", e.name, (yyvsp[(3) - (4)].elem).name);
                                  else if((yyvsp[(3) - (4)].elem).tipo == 2)
                                    printf("\n\t---> ERROR! Incompatible types in assigment: %s is double and %s string", e.name, (yyvsp[(3) - (4)].elem).name);
                                  else if((yyvsp[(3) - (4)].elem).tipo == 3){
                                    e_ts->valor.valor3=(yyvsp[(3) - (4)].elem).valor.valor3;
                                    printf("\n\tAsignacion correcta\n");
                                    ImprimeTS(&ts);
                                  }
                                }
                              }
                              else{
                                printf("\n\t-->ERROR! asignacion primero tiene que ser declarado %s\n", e.name);
                              }
                            }
                            else{
                              printf("\n\t-->ERROR! no se ha podido declarar %s\n", (yyvsp[(1) - (4)].str));
                              flag_esta = 1;
                              flag_incompatibles = 1;
                              flag_op = 1;
                            }
                          ;}
    break;

  case 87:
#line 1428 "sintactico.y"
    { printf("\n\t-->ERROR! te falto escribir ';'\n"); ;}
    break;

  case 88:
#line 1429 "sintactico.y"
    { printf("\n\t-->ERROR! te falto escribir ';'\n"); ;}
    break;

  case 89:
#line 1430 "sintactico.y"
    { printf("\n\t-->ERROR! te falto escribir ';'\n"); ;}
    break;

  case 90:
#line 1431 "sintactico.y"
    { printf("\n\t-->ERROR! te falto escribir ';'\n"); ;}
    break;

  case 91:
#line 1432 "sintactico.y"
    { printf("\n\t-->ERROR! te falto escribir ';'\n"); ;}
    break;

  case 92:
#line 1433 "sintactico.y"
    { printf("\n\t-->ERROR! te falto escribir ';'\n"); ;}
    break;

  case 93:
#line 1434 "sintactico.y"
    { printf("\n\t-->ERROR! te falto escribir ';'\n"); ;}
    break;

  case 94:
#line 1435 "sintactico.y"
    { printf("\n\t-->ERROR! te falto escribir ';'\n"); ;}
    break;

  case 95:
#line 1436 "sintactico.y"
    { printf("\n\t-->ERROR! te falto escribir ';'\n"); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 3211 "sintactico.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1439 "sintactico.y"


int main(){
  Initialize(&ts);
  yyparse();
  Destroy(&ts);
  ImprimeTS(&ts);
  return 0;
}

void yyerror(char *s){
  printf("--%s--\n", s);
}

int yywrap(){
  return 1;
}

