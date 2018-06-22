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
     IF = 263,
     POW = 264,
     IGUAL_A = 265
   };
#endif
/* Tokens.  */
#define ENTERO 258
#define REAL 259
#define CADENA 260
#define TIPO 261
#define ID 262
#define IF 263
#define POW 264
#define IGUAL_A 265




/* Copy the first part of user declarations.  */
#line 1 "sintactico.y"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "op_cadenas.h"
#include "lista.h"
//#include "TADListaSL.h"
int yylex(void);
void yyerror(char *);
lista ts; //Se declara la lista en este caso Tabla de Simbolos
//lista_array array;
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
#line 22 "sintactico.y"
{  /* especifica la colección completa de tipo de datos pibles */
  int entero;
  double flotante;
  char* str;
  elemento elem;
}
/* Line 193 of yacc.c.  */
#line 142 "sintactico.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 155 "sintactico.tab.c"

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
#define YYLAST   749

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNRULES -- Number of states.  */
#define YYNSTATES  326

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   265

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    18,     2,     2,
      20,    22,    16,    14,    21,    15,     2,    17,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
      13,    11,    12,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    21,
      24,    27,    30,    32,    35,    38,    42,    46,    50,    54,
      58,    65,    69,    73,    77,    81,    83,    86,    89,    93,
      97,   101,   105,   112,   116,   120,   124,   128,   135,   139,
     143,   147,   151,   158,   162,   166,   170,   174,   176,   180,
     184,   186,   191,   194,   198,   202,   206,   210,   214,   218,
     222,   226,   230,   234,   238,   242,   246,   250,   254,   258,
     262,   266,   270,   274,   278,   282,   286,   290,   294,   298,
     302,   306,   310,   317,   324,   331,   338,   345,   352,   359,
     363,   370,   376,   382,   388,   394,   399,   407,   415,   423,
     428,   433,   438,   446,   454,   462,   470,   478,   486,   494,
     502,   510,   518,   526,   534,   542,   550,   558,   566,   574,
     582,   590,   598
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      27,     0,    -1,    -1,    27,    28,    -1,    19,    -1,    29,
      19,    -1,    30,    19,    -1,    31,    19,    -1,    33,    19,
      -1,    34,    19,    -1,    32,    19,    -1,    35,    19,    -1,
       3,    -1,    15,    29,    -1,    14,    29,    -1,    29,    14,
      29,    -1,    29,    15,    29,    -1,    29,    16,    29,    -1,
      29,    17,    29,    -1,    29,    18,    29,    -1,     9,    20,
      29,    21,    29,    22,    -1,    29,    14,    31,    -1,    29,
      15,    31,    -1,    29,    16,    31,    -1,    29,    17,    31,
      -1,     4,    -1,    15,    30,    -1,    14,    30,    -1,    30,
      14,    30,    -1,    30,    15,    30,    -1,    30,    16,    30,
      -1,    30,    17,    30,    -1,     9,    20,    30,    21,    30,
      22,    -1,    29,    14,    30,    -1,    29,    15,    30,    -1,
      29,    16,    30,    -1,    29,    17,    30,    -1,     9,    20,
      29,    21,    30,    22,    -1,    30,    14,    29,    -1,    30,
      15,    29,    -1,    30,    16,    29,    -1,    30,    17,    29,
      -1,     9,    20,    30,    21,    29,    22,    -1,    30,    14,
      31,    -1,    30,    15,    31,    -1,    30,    16,    31,    -1,
      30,    17,    31,    -1,     5,    -1,    31,    14,    31,    -1,
      31,    15,    31,    -1,     7,    -1,     7,    23,    29,    24,
      -1,    15,    32,    -1,    20,    32,    22,    -1,    32,    14,
      32,    -1,    32,    14,    29,    -1,    32,    14,    30,    -1,
      32,    14,    31,    -1,    29,    14,    32,    -1,    30,    14,
      32,    -1,    31,    14,    32,    -1,    32,    15,    32,    -1,
      32,    15,    29,    -1,    32,    15,    30,    -1,    32,    15,
      31,    -1,    29,    15,    32,    -1,    30,    15,    32,    -1,
      31,    15,    32,    -1,    32,    16,    32,    -1,    32,    16,
      29,    -1,    32,    16,    30,    -1,    32,    16,    31,    -1,
      29,    16,    32,    -1,    30,    16,    32,    -1,    31,    16,
      32,    -1,    32,    17,    32,    -1,    32,    17,    29,    -1,
      32,    17,    30,    -1,    32,    17,    31,    -1,    29,    17,
      32,    -1,    30,    17,    32,    -1,    31,    17,    32,    -1,
       9,    20,    32,    21,    32,    22,    -1,     9,    20,    32,
      21,    29,    22,    -1,     9,    20,    32,    21,    30,    22,
      -1,     9,    20,    32,    21,    31,    22,    -1,     9,    20,
      29,    21,    32,    22,    -1,     9,    20,    30,    21,    32,
      22,    -1,     9,    20,    31,    21,    32,    22,    -1,     6,
       7,    25,    -1,     6,     7,    23,    29,    24,    25,    -1,
       6,     7,    11,    32,    25,    -1,     6,     7,    11,    29,
      25,    -1,     6,     7,    11,    30,    25,    -1,     6,     7,
      11,    31,    25,    -1,     7,    11,    29,    25,    -1,     7,
      23,    29,    24,    11,    30,    25,    -1,     7,    23,    29,
      24,    11,    29,    25,    -1,     7,    23,    29,    24,    11,
      32,    25,    -1,     7,    11,    30,    25,    -1,     7,    11,
      31,    25,    -1,     7,    11,    32,    25,    -1,     8,    20,
      32,    13,    32,    22,    25,    -1,     8,    20,    32,    13,
      29,    22,    25,    -1,     8,    20,    32,    13,    30,    22,
      25,    -1,     8,    20,    32,    13,    31,    22,    25,    -1,
       8,    20,    29,    13,    32,    22,    25,    -1,     8,    20,
      30,    13,    32,    22,    25,    -1,     8,    20,    31,    13,
      32,    22,    25,    -1,     8,    20,    32,    12,    32,    22,
      25,    -1,     8,    20,    32,    12,    29,    22,    25,    -1,
       8,    20,    32,    12,    30,    22,    25,    -1,     8,    20,
      32,    12,    31,    22,    25,    -1,     8,    20,    29,    12,
      32,    22,    25,    -1,     8,    20,    30,    12,    32,    22,
      25,    -1,     8,    20,    31,    12,    32,    22,    25,    -1,
       8,    20,    32,    10,    32,    22,    25,    -1,     8,    20,
      32,    10,    29,    22,    25,    -1,     8,    20,    32,    10,
      30,    22,    25,    -1,     8,    20,    32,    10,    31,    22,
      25,    -1,     8,    20,    29,    10,    32,    22,    25,    -1,
       8,    20,    30,    10,    32,    22,    25,    -1,     8,    20,
      31,    10,    32,    22,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    48,    51,    52,    53,    54,    55,    56,
      57,    75,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    99,   100,   101,   102,   103,
     104,   105,   107,   108,   109,   110,   111,   113,   114,   115,
     116,   117,   119,   120,   121,   122,   123,   127,   128,   134,
     149,   173,   199,   218,   235,   299,   318,   337,   351,   377,
     400,   418,   481,   500,   519,   533,   556,   579,   597,   661,
     680,   699,   714,   737,   760,   779,   843,   862,   881,   897,
     920,   943,   962,  1029,  1051,  1073,  1091,  1114,  1137,  1156,
    1182,  1214,  1287,  1321,  1354,  1378,  1410,  1437,  1464,  1489,
    1521,  1552,  1618,  1655,  1680,  1705,  1721,  1746,  1771,  1789,
    1826,  1851,  1876,  1892,  1917,  1942,  1959,  1996,  2021,  2046,
    2062,  2087,  2112
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTERO", "REAL", "CADENA", "TIPO", "ID",
  "IF", "POW", "IGUAL_A", "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'\\n'", "'('", "','", "')'", "'['", "']'", "';'", "$accept",
  "input", "line", "exp_e", "exp_f", "exp_c", "expVar", "decl", "asig",
  "inst_ctrl", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    61,    62,    60,    43,    45,    42,    47,    37,    10,
      40,    44,    41,    91,    93,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    26,    27,    27,    28,    28,    28,    28,    28,    28,
      28,    28,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    31,    31,    31,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    33,
      33,    33,    33,    33,    33,    34,    34,    34,    34,    34,
      34,    34,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     3,     3,     3,     3,     3,
       6,     3,     3,     3,     3,     1,     2,     2,     3,     3,
       3,     3,     6,     3,     3,     3,     3,     6,     3,     3,
       3,     3,     6,     3,     3,     3,     3,     1,     3,     3,
       1,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,     6,     6,     6,     6,     6,     6,     3,
       6,     5,     5,     5,     5,     4,     7,     7,     7,     4,
       4,     4,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    12,    25,    47,     0,    50,     0,     0,
       0,     0,     4,     0,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      27,    50,    13,    26,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     6,
       0,     0,     0,     0,     7,     0,     0,     0,     0,    10,
       8,     9,    11,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    15,    33,    21,    58,    16,
      34,    22,    65,    17,    35,    23,    72,    18,    36,    24,
      79,    19,    38,    28,    43,    59,    39,    29,    44,    66,
      40,    30,    45,    73,    41,    31,    46,    80,    48,    60,
      49,    67,    74,    81,    55,    56,    57,    54,    62,    63,
      64,    61,    69,    70,    71,    68,    76,    77,    78,    75,
       0,     0,     0,     0,     0,    95,    99,   100,   101,     0,
      14,    13,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    33,    21,    16,    34,
      22,    17,    35,    23,    18,    36,    24,    38,    28,    43,
      39,    29,    44,    40,    30,    45,    41,    31,    46,     0,
      92,    93,    94,    91,     0,     0,    15,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,    37,    86,    42,    32,    87,
      88,    83,    84,    85,    82,     0,     0,     0,     0,    48,
      49,     0,    97,    96,    98,   120,   113,   106,   121,   114,
     107,   122,   115,   108,   117,   118,   119,   116,   110,   111,
     112,   109,   103,   104,   105,   102
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    14,    36,    37,    34,    18,    19,    20,    21
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -15
static const yytype_int16 yypact[] =
{
     -15,    96,   -15,   -15,   -15,   -15,     1,    -7,   -14,    -9,
     103,    -2,   -15,    -2,   -15,   707,   713,   719,   725,    -4,
       0,    11,     3,    -2,    34,    -2,    -2,    -3,   103,    42,
       4,    46,    77,    48,   151,    66,   731,   377,   112,    -2,
      -2,    -2,    -2,    34,   -15,    -2,    -2,    -2,    -2,   -15,
      -2,    -2,    -2,    -2,   -15,    -2,    -2,    -2,    -2,   -15,
     -15,   -15,   -15,    -2,    34,   -15,   155,    36,   188,   193,
      93,    34,    34,   279,   349,    19,   402,   655,   659,    59,
     683,   691,   103,    42,     4,    63,    63,    63,    63,    63,
      63,    63,    63,    34,   -15,    77,    48,    92,    66,    77,
      48,    92,    66,   -15,   -15,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,    77,    48,    92,    66,    77,    48,    92,    66,
      61,   -15,   -15,   -15,    61,   -15,   -15,   -15,    92,    66,
      92,    66,   -15,   -15,    77,    48,    92,    66,    77,    48,
      92,    66,    61,   -15,   -15,   -15,    61,   -15,   -15,   -15,
     176,   200,   206,   212,   294,   -15,   -15,   -15,   -15,    34,
     133,   133,   116,   116,   116,   116,    86,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,   667,   699,    42,     4,   -15,    42,     4,
     -15,   -15,   -15,   -15,   -15,   -15,   -15,    42,     4,   -15,
      42,     4,   -15,    61,   -15,   -15,    61,   -15,   -15,   299,
     -15,   -15,   -15,   -15,    89,   675,   133,   133,   -15,   -15,
      -2,   249,   305,   334,   469,   473,   501,   505,   514,   518,
     324,   527,   531,   540,   382,   544,   553,   557,   391,   566,
     570,   579,   413,   583,   592,   422,   596,   605,   609,   431,
     618,   622,   631,   103,   103,   119,   119,   -15,   -15,    34,
     181,   218,   224,   107,   108,   110,   115,   121,   131,   132,
     134,   149,   175,   186,   187,   199,   205,   211,   217,   219,
     221,   222,   223,   225,   -15,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,   -15,   -15,   -15,   440,   635,   451,   644,   -15,
     -15,   460,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,   -15,   -15,   -15,   -15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -15,   -15,   -15,    -1,   244,    97,   332,   -15,   -15,   -15
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      15,     3,     4,     5,    23,    31,    25,     9,    22,    29,
      32,    26,    10,    11,    63,    60,    24,    82,    13,    61,
      91,    92,    66,    73,    74,    78,    64,    83,    65,   170,
      62,   171,   172,    45,    46,    47,    48,     3,    95,    99,
     103,   107,   111,    70,   112,   116,   120,   124,    71,    72,
      45,    46,    47,    48,   134,   138,   142,   146,    87,    88,
      43,   156,   150,   154,    47,    48,     3,     4,     5,    93,
     160,   161,    27,    45,    46,    47,    48,    10,    28,    43,
     180,   183,    57,    58,   185,   188,   191,   194,   197,   200,
     203,   206,   209,    41,    42,    43,     2,   220,    17,     3,
       4,     5,     6,     7,     8,     9,     3,     4,    52,    53,
      10,    11,    27,   159,   258,    12,    13,    10,    28,     3,
      68,     5,    76,    80,     5,    70,    55,    56,    57,    58,
      71,    72,   305,   306,    94,   307,    97,   101,   105,   109,
     308,     0,   114,   118,   122,   126,   309,   128,   130,   164,
     165,    43,   136,   140,   144,   148,   310,   311,   215,   312,
     152,   216,   217,   218,   219,    50,    51,    52,    53,    39,
      40,    41,    42,    43,   313,   230,   234,   238,   242,   245,
     155,   249,   187,   190,   193,   196,   199,   202,   205,   208,
      39,    40,    41,    42,    43,    39,    40,    41,    42,    43,
     314,   210,    50,    51,    52,    53,   302,    55,    56,    57,
      58,   315,   316,   157,    45,    46,    47,    48,   158,   260,
      50,    51,    52,    53,   317,   211,    55,    56,    57,    58,
     318,   212,    45,    46,    47,    48,   319,   213,    55,    56,
      57,    58,   320,   303,   321,    16,   322,   323,   324,   304,
     325,     0,   295,   297,    30,    33,     0,     0,   301,   187,
     190,   193,   196,    55,    56,    57,    58,    67,     0,    75,
      79,   263,    84,   232,   236,   240,     0,     0,     0,   251,
       0,     0,     0,    96,   100,   104,   108,     0,     0,   113,
     117,   121,   125,   162,   163,   164,   165,    43,     0,   135,
     139,   143,   147,   166,     0,     0,     0,   151,   162,   163,
     164,   165,    43,   162,   163,   164,   165,    43,   214,    55,
      56,    57,    58,   257,     0,     0,   184,   264,     0,   186,
     189,   192,   195,   198,   201,   204,   207,     0,    39,    40,
      41,    42,    43,    35,     0,    38,   272,     0,    55,    56,
      57,    58,   299,   300,     0,    69,   265,    77,    81,   167,
       0,   168,   169,    39,    40,    41,    42,    43,     0,     0,
       0,    98,   102,   106,   110,     0,     0,   115,   119,   123,
     127,     0,   129,   131,   132,   133,     0,   137,   141,   145,
     149,    45,    46,    47,    48,   153,    39,    40,    41,    42,
      43,     0,     0,     0,   276,    39,    40,    41,    42,    43,
       0,     0,   173,   280,   174,   175,    50,    51,    52,    53,
     231,   235,   239,   243,   246,     0,   250,    39,    40,    41,
      42,    43,     0,     0,     0,   284,    39,    40,    41,    42,
      43,     0,     0,     0,   287,    39,    40,    41,    42,    43,
       0,     0,     0,   291,    85,    86,    87,    88,    43,     0,
       0,     0,   284,     0,   261,    85,    86,    87,    88,    43,
       0,     0,     0,   287,   162,   163,   164,   165,    43,     0,
       0,     0,   284,    55,    56,    57,    58,    55,    56,    57,
      58,   266,     0,     0,     0,   267,     0,   296,   298,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   233,   237,
     241,   244,   247,   248,   252,    55,    56,    57,    58,    55,
      56,    57,    58,   268,     0,     0,     0,   269,    55,    56,
      57,    58,    55,    56,    57,    58,   270,     0,     0,     0,
     271,    45,    46,    47,    48,    50,    51,    52,    53,   273,
       0,     0,   262,   274,    55,    56,    57,    58,    45,    46,
      47,    48,   275,     0,     0,     0,   277,    50,    51,    52,
      53,    55,    56,    57,    58,   278,     0,     0,     0,   279,
      45,    46,    47,    48,    50,    51,    52,    53,   281,     0,
       0,     0,   282,    55,    56,    57,    58,    45,    46,    47,
      48,   283,     0,     0,     0,   285,    55,    56,    57,    58,
      45,    46,    47,    48,   286,     0,     0,     0,   288,    55,
      56,    57,    58,    55,    56,    57,    58,   289,     0,     0,
       0,   290,    45,    46,    47,    48,    50,    51,    52,    53,
     292,     0,     0,     0,   293,    55,    56,    57,    58,    89,
      90,    91,    92,   294,     0,     0,     0,   285,    89,    90,
      91,    92,     0,     0,     0,   176,   288,   177,   178,    55,
      56,    57,    58,    39,    40,    41,    42,    43,     0,     0,
     179,    85,    86,    87,    88,    43,     0,     0,   253,   162,
     163,   164,   165,    43,     0,     0,   259,    50,    51,    52,
      53,     0,     0,     0,   181,    55,    56,    57,    58,     0,
       0,     0,   182,    89,    90,    91,    92,     0,     0,     0,
     254,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,     0,    59,    39,    40,    41,    42,    43
};

static const yytype_int16 yycheck[] =
{
       1,     3,     4,     5,    11,     7,    20,     9,     7,    10,
      11,    20,    14,    15,    11,    19,    23,    20,    20,    19,
      16,    17,    23,    24,    25,    26,    23,    28,    25,    10,
      19,    12,    13,    14,    15,    16,    17,     3,    39,    40,
      41,    42,    43,     9,    45,    46,    47,    48,    14,    15,
      14,    15,    16,    17,    55,    56,    57,    58,    16,    17,
      18,    25,    63,    64,    16,    17,     3,     4,     5,    23,
      71,    72,     9,    14,    15,    16,    17,    14,    15,    18,
      21,    82,    16,    17,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    16,    17,    18,     0,    11,     1,     3,
       4,     5,     6,     7,     8,     9,     3,     4,    16,    17,
      14,    15,     9,    20,    25,    19,    20,    14,    15,     3,
      23,     5,    25,    26,     5,     9,    14,    15,    16,    17,
      14,    15,    25,    25,    22,    25,    39,    40,    41,    42,
      25,    -1,    45,    46,    47,    48,    25,    50,    51,    16,
      17,    18,    55,    56,    57,    58,    25,    25,   159,    25,
      63,   162,   163,   164,   165,    14,    15,    16,    17,    14,
      15,    16,    17,    18,    25,   176,   177,   178,   179,   180,
      25,   182,    85,    86,    87,    88,    89,    90,    91,    92,
      14,    15,    16,    17,    18,    14,    15,    16,    17,    18,
      25,    25,    14,    15,    16,    17,    25,    14,    15,    16,
      17,    25,    25,    25,    14,    15,    16,    17,    25,   220,
      14,    15,    16,    17,    25,    25,    14,    15,    16,    17,
      25,    25,    14,    15,    16,    17,    25,    25,    14,    15,
      16,    17,    25,    25,    25,     1,    25,    25,    25,    25,
      25,    -1,   253,   254,    10,    11,    -1,    -1,   259,   162,
     163,   164,   165,    14,    15,    16,    17,    23,    -1,    25,
      26,    22,    28,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,    45,
      46,    47,    48,    14,    15,    16,    17,    18,    -1,    55,
      56,    57,    58,    24,    -1,    -1,    -1,    63,    14,    15,
      16,    17,    18,    14,    15,    16,    17,    18,    24,    14,
      15,    16,    17,    24,    -1,    -1,    82,    22,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    14,    15,
      16,    17,    18,    11,    -1,    13,    22,    -1,    14,    15,
      16,    17,   255,   256,    -1,    23,    22,    25,    26,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    39,    40,    41,    42,    -1,    -1,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    14,    15,    16,    17,    63,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    22,    14,    15,    16,    17,    18,
      -1,    -1,    10,    22,    12,    13,    14,    15,    16,    17,
     176,   177,   178,   179,   180,    -1,   182,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    22,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    22,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    22,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    22,    -1,   220,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    22,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    22,    14,    15,    16,    17,    14,    15,    16,
      17,    22,    -1,    -1,    -1,    22,    -1,   253,   254,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    14,    15,    16,    17,    14,
      15,    16,    17,    22,    -1,    -1,    -1,    22,    14,    15,
      16,    17,    14,    15,    16,    17,    22,    -1,    -1,    -1,
      22,    14,    15,    16,    17,    14,    15,    16,    17,    22,
      -1,    -1,   220,    22,    14,    15,    16,    17,    14,    15,
      16,    17,    22,    -1,    -1,    -1,    22,    14,    15,    16,
      17,    14,    15,    16,    17,    22,    -1,    -1,    -1,    22,
      14,    15,    16,    17,    14,    15,    16,    17,    22,    -1,
      -1,    -1,    22,    14,    15,    16,    17,    14,    15,    16,
      17,    22,    -1,    -1,    -1,    22,    14,    15,    16,    17,
      14,    15,    16,    17,    22,    -1,    -1,    -1,    22,    14,
      15,    16,    17,    14,    15,    16,    17,    22,    -1,    -1,
      -1,    22,    14,    15,    16,    17,    14,    15,    16,    17,
      22,    -1,    -1,    -1,    22,    14,    15,    16,    17,    14,
      15,    16,    17,    22,    -1,    -1,    -1,    22,    14,    15,
      16,    17,    -1,    -1,    -1,    10,    22,    12,    13,    14,
      15,    16,    17,    14,    15,    16,    17,    18,    -1,    -1,
      21,    14,    15,    16,    17,    18,    -1,    -1,    21,    14,
      15,    16,    17,    18,    -1,    -1,    21,    14,    15,    16,
      17,    -1,    -1,    -1,    21,    14,    15,    16,    17,    -1,
      -1,    -1,    21,    14,    15,    16,    17,    -1,    -1,    -1,
      21,    14,    15,    16,    17,    18,    19,    14,    15,    16,
      17,    -1,    19,    14,    15,    16,    17,    -1,    19,    14,
      15,    16,    17,    -1,    19,    14,    15,    16,    17,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,     0,     3,     4,     5,     6,     7,     8,     9,
      14,    15,    19,    20,    28,    29,    30,    31,    32,    33,
      34,    35,     7,    11,    23,    20,    20,     9,    15,    29,
      30,     7,    29,    30,    31,    32,    29,    30,    32,    14,
      15,    16,    17,    18,    19,    14,    15,    16,    17,    19,
      14,    15,    16,    17,    19,    14,    15,    16,    17,    19,
      19,    19,    19,    11,    23,    25,    29,    30,    31,    32,
       9,    14,    15,    29,    29,    30,    31,    32,    29,    30,
      31,    32,    20,    29,    30,    14,    15,    16,    17,    14,
      15,    16,    17,    23,    22,    29,    30,    31,    32,    29,
      30,    31,    32,    29,    30,    31,    32,    29,    30,    31,
      32,    29,    29,    30,    31,    32,    29,    30,    31,    32,
      29,    30,    31,    32,    29,    30,    31,    32,    31,    32,
      31,    32,    32,    32,    29,    30,    31,    32,    29,    30,
      31,    32,    29,    30,    31,    32,    29,    30,    31,    32,
      29,    30,    31,    32,    29,    25,    25,    25,    25,    20,
      29,    29,    14,    15,    16,    17,    24,    10,    12,    13,
      10,    12,    13,    10,    12,    13,    10,    12,    13,    21,
      21,    21,    21,    29,    30,    29,    30,    31,    29,    30,
      31,    29,    30,    31,    29,    30,    31,    29,    30,    31,
      29,    30,    31,    29,    30,    31,    29,    30,    31,    29,
      25,    25,    25,    25,    24,    29,    29,    29,    29,    29,
      11,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      29,    30,    31,    32,    29,    30,    31,    32,    29,    30,
      31,    32,    29,    30,    32,    29,    30,    32,    32,    29,
      30,    31,    32,    21,    21,    14,    15,    24,    25,    21,
      29,    30,    32,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    29,    30,    29,    30,    31,
      31,    29,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25
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
#line 52 "sintactico.y"
    { printf("\tresultado: %d\n", (yyvsp[(1) - (2)].entero)); ;}
    break;

  case 6:
#line 53 "sintactico.y"
    { printf("\tresultado: %f\n", (yyvsp[(1) - (2)].flotante)); ;}
    break;

  case 7:
#line 54 "sintactico.y"
    { printf("\tresultado: %s\n", (yyvsp[(1) - (2)].str)); ;}
    break;

  case 10:
#line 57 "sintactico.y"
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

  case 11:
#line 75 "sintactico.y"
    {
                              if((yyvsp[(1) - (2)].entero)==1)
                                printf("\n\tIF: True\n");
                              else
                                printf("\n\tIF: False\n");
                            ;}
    break;

  case 12:
#line 83 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (1)].entero); /*printf("%d\n", $1);*/ ;}
    break;

  case 13:
#line 84 "sintactico.y"
    { (yyval.entero) = ((yyvsp[(2) - (2)].entero))*(-1); ;}
    break;

  case 14:
#line 85 "sintactico.y"
    { (yyval.entero) = ((yyvsp[(2) - (2)].entero))*(-1); ;}
    break;

  case 15:
#line 86 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) + (yyvsp[(3) - (3)].entero); ;}
    break;

  case 16:
#line 87 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) - (yyvsp[(3) - (3)].entero); ;}
    break;

  case 17:
#line 88 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) * (yyvsp[(3) - (3)].entero); ;}
    break;

  case 18:
#line 89 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) / (yyvsp[(3) - (3)].entero); ;}
    break;

  case 19:
#line 90 "sintactico.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) % (yyvsp[(3) - (3)].entero); ;}
    break;

  case 20:
#line 91 "sintactico.y"
    { (yyval.entero) = pow((yyvsp[(3) - (6)].entero),(yyvsp[(5) - (6)].entero)); ;}
    break;

  case 21:
#line 92 "sintactico.y"
    {printf("\n\t-->ERROR! Operacion no permitida\n"); (yyval.entero)=0;;}
    break;

  case 22:
#line 93 "sintactico.y"
    {printf("\n\t-->ERROR! Operacion no permitida\n"); (yyval.entero)=0;;}
    break;

  case 23:
#line 94 "sintactico.y"
    {printf("\n\t-->ERROR! Operacion no permitida\n"); (yyval.entero)=0;;}
    break;

  case 24:
#line 95 "sintactico.y"
    {printf("\n\t-->ERROR! Operacion no permitida\n"); (yyval.entero)=0;;}
    break;

  case 25:
#line 99 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (1)].flotante); /*printf("%f\n", $1);*/ ;}
    break;

  case 26:
#line 100 "sintactico.y"
    { (yyval.flotante) = ((yyvsp[(2) - (2)].flotante))*(-1); ;}
    break;

  case 27:
#line 101 "sintactico.y"
    { (yyval.flotante) = ((yyvsp[(2) - (2)].flotante))*(-1); ;}
    break;

  case 28:
#line 102 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) + (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 29:
#line 103 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) - (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 30:
#line 104 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) * (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 31:
#line 105 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) / (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 32:
#line 107 "sintactico.y"
    { (yyval.flotante) = pow((yyvsp[(3) - (6)].flotante),(yyvsp[(5) - (6)].flotante)); ;}
    break;

  case 33:
#line 108 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].entero) + (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 34:
#line 109 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].entero) - (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 35:
#line 110 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].entero) * (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 36:
#line 111 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].entero) / (yyvsp[(3) - (3)].flotante); ;}
    break;

  case 37:
#line 113 "sintactico.y"
    { (yyval.flotante) = pow((yyvsp[(3) - (6)].entero),(yyvsp[(5) - (6)].flotante)); ;}
    break;

  case 38:
#line 114 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) + (yyvsp[(3) - (3)].entero); ;}
    break;

  case 39:
#line 115 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) - (yyvsp[(3) - (3)].entero); ;}
    break;

  case 40:
#line 116 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) * (yyvsp[(3) - (3)].entero); ;}
    break;

  case 41:
#line 117 "sintactico.y"
    { (yyval.flotante) = (yyvsp[(1) - (3)].flotante) / (yyvsp[(3) - (3)].entero); ;}
    break;

  case 42:
#line 119 "sintactico.y"
    { (yyval.flotante) = pow((yyvsp[(3) - (6)].flotante),(yyvsp[(5) - (6)].entero)); ;}
    break;

  case 43:
#line 120 "sintactico.y"
    {printf("\n\t-->ERROR! Operacion no permitida\n"); (yyval.flotante)=0;;}
    break;

  case 44:
#line 121 "sintactico.y"
    {printf("\n\t-->ERROR! Operacion no permitida\n"); (yyval.flotante)=0;;}
    break;

  case 45:
#line 122 "sintactico.y"
    {printf("\n\t-->ERROR! Operacion no permitida\n"); (yyval.flotante)=0;;}
    break;

  case 46:
#line 123 "sintactico.y"
    {printf("\n\t-->ERROR! Operacion no permitida\n"); (yyval.flotante)=0;;}
    break;

  case 47:
#line 127 "sintactico.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); /*printf("%s\n", $1) */ ;}
    break;

  case 48:
#line 128 "sintactico.y"
    {
                            char* aux;
                            aux = concatenar((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
                            (yyval.str) = aux;
                          ;}
    break;

  case 49:
#line 134 "sintactico.y"
    {
                            char* aux;
                            aux = resta((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
                            (yyval.str) = aux;
                          ;}
    break;

  case 50:
#line 149 "sintactico.y"
    {
              posicion p;
              elemento e;
              elemento * e_ts;
              e.name = (yyvsp[(1) - (1)].str); //Se pasa el nombre del identificador al elemento
              p = Search(&ts, e); //Se busca el elemento en la tabla de simbolos
              if(p!=NULL){ //Asegura que la variable ya haya sido declarada
                e_ts = getElement(&ts, p); //Obtiene elemento por referencia
                (yyval.elem) = *e_ts; //se asigna a expVar el contenido del elemento, es decir sólo su contenido
                if((yyval.elem).tipo==1){
                  flag_print = 1;
                }
                else if((yyval.elem).tipo==2){
                  flag_print = 2;
                }
                else if((yyval.elem).tipo==3){
                  flag_print = 3;
                }
              }
              else{ // Si no encuentra el elemento se genera un error de declaracion
                printf("\n\t-->ERROR! no ha sido declarada previamente %s\n", (yyvsp[(1) - (1)].str));
                flag_esta = 0;
              }
            ;}
    break;

  case 51:
#line 173 "sintactico.y"
    {
        posicion p;
        elemento e;
        elemento * e_ts;
        char indice[1000];
        char*nombre;
        sprintf(indice, "%d", (yyvsp[(3) - (4)].entero));
        nombre = concatenar( "__", indice);
        nombre = concatenar((yyvsp[(1) - (4)].str), nombre);
        e.name = nombre;
        //rintf("\n%s", e.name);
        e.name = nombre;
        //e.name = $1; //Se pasa el nombre del identificador al elemento
        p = Search(&ts, e); //Se busca el elemento en la tabla de simbolos
        if(p!=NULL){ //Asegura que la variable ya haya sido declarada
          e_ts = getElement(&ts, p); //Obtiene elemento por referencia
          (yyval.elem) = *e_ts; //se asigna a expVar el contenido del elemento, es decir sólo su contenido

        }
        else{ // Si no encuentra el elemento se genera un error de declaracion
          printf("\n\t-->ERROR! no ha sido declarada previamente %s\n", (yyvsp[(1) - (4)].str));
          flag_esta = 0;
        }

      ;}
    break;

  case 52:
#line 199 "sintactico.y"
    {
                      if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){ //Comprueba que no haya errores de declaracion, compatibilidad de tipos o de operaciones que no estan disponibles
                        elemento*e_aux;
                        e_aux = &(yyvsp[(2) - (2)].elem);
                        (yyval.elem) = *e_aux; //Se inicializa $$ con la copia de $2
                        if((yyval.elem).tipo == 1){
                          (yyval.elem).valor.valor1 = ((yyvsp[(2) - (2)].elem).valor.valor1)*(-1);
                          flag_print = 1;
                        }
                        else if((yyval.elem).tipo == 2){
                          (yyval.elem).valor.valor2 = ((yyvsp[(2) - (2)].elem).valor.valor2)*(-1);
                          flag_print = 2;
                        }
                        else if((yyval.elem).tipo == 3){ //Se genera un error ya que no no existen cadenas negativas
                          printf("\n\t-->ERROR! No hay cadenas negativas\n");
                        }
                      }
                    ;}
    break;

  case 53:
#line 218 "sintactico.y"
    {//faltan las banderas
                          elemento*e_aux; //Pasa una copia a $$ un tipo elemento
                          e_aux = &(yyvsp[(2) - (3)].elem);
                          (yyval.elem) = *e_aux;
                          if((yyval.elem).tipo == 1){
                            (yyval.elem).valor.valor1 = (yyvsp[(2) - (3)].elem).valor.valor1;
                            flag_print = 1;
                          }
                          else if((yyval.elem).tipo == 2){
                            (yyval.elem).valor.valor2 = (yyvsp[(2) - (3)].elem).valor.valor2;
                            flag_print = 2;
                          }
                          else if((yyval.elem).tipo == 3){
                            (yyval.elem).valor.valor3 = (yyvsp[(2) - (3)].elem).valor.valor3;
                          }
                        ;}
    break;

  case 54:
#line 235 "sintactico.y"
    {
                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if((yyval.elem).tipo == 1){ //Se comprueba el tipo de $$ para la operación
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
                            }
                          ;}
    break;

  case 55:
#line 299 "sintactico.y"
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

  case 56:
#line 318 "sintactico.y"
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

  case 57:
#line 337 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                if((yyval.elem).tipo == 3){
                                  (yyval.elem).valor.valor3 = concatenar((yyvsp[(1) - (3)].elem).valor.valor3, (yyvsp[(3) - (3)].str));
                                  flag_print = 3;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                            ;}
    break;

  case 58:
#line 351 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                //En este momento $$ tiene un tipo de dato int, se pasa una copia de $3 para
                                //forzar a que tenga un tipo de dato elemento y en la recursion se pueda
                                //verificar el tipo de elemento
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

  case 59:
#line 377 "sintactico.y"
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

  case 60:
#line 400 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                                char * aux = (yyvsp[(1) - (3)].str);   //guarda exp_e para no perder el valor
                                e_aux = &(yyvsp[(3) - (3)].elem);
                                (yyval.elem) = *e_aux;
                                if((yyval.elem).tipo == 3){
                                  (yyval.elem).valor.valor3 = concatenar(aux, (yyvsp[(3) - (3)].elem).valor.valor3);
                                  flag_print = 3;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                            ;}
    break;

  case 61:
#line 418 "sintactico.y"
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

  case 62:
#line 481 "sintactico.y"
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

  case 63:
#line 500 "sintactico.y"
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

  case 64:
#line 519 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                if((yyval.elem).tipo == 3){
                                  (yyval.elem).valor.valor3 = resta((yyvsp[(1) - (3)].elem).valor.valor3, (yyvsp[(3) - (3)].str));
                                  flag_print = 3;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                            ;}
    break;

  case 65:
#line 533 "sintactico.y"
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

  case 66:
#line 556 "sintactico.y"
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

  case 67:
#line 579 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                                char * aux = (yyvsp[(1) - (3)].str);   //guarda exp_e para no perder el valor
                                e_aux = &(yyvsp[(3) - (3)].elem);
                                (yyval.elem) = *e_aux;
                                if((yyval.elem).tipo == 3){
                                  (yyval.elem).valor.valor3 = resta(aux, (yyvsp[(3) - (3)].elem).valor.valor3);
                                  flag_print = 3;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                            ;}
    break;

  case 68:
#line 597 "sintactico.y"
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

  case 69:
#line 661 "sintactico.y"
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

  case 70:
#line 680 "sintactico.y"
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

  case 71:
#line 699 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
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
                            ;}
    break;

  case 72:
#line 714 "sintactico.y"
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

  case 73:
#line 737 "sintactico.y"
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

  case 74:
#line 760 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                                char * aux = (yyvsp[(1) - (3)].str);   //guarda exp_e para no perder el valor
                                e_aux = &(yyvsp[(3) - (3)].elem);
                                (yyval.elem) = *e_aux;
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
                            ;}
    break;

  case 75:
#line 779 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                if((yyval.elem).tipo == 1){
                                  (yyval.elem).tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                                  if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo==1){
                                    (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].elem).valor.valor1;
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                    (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].elem).valor.valor2;
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 1){
                                    (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].elem).valor.valor1;
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                    (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].elem).valor.valor2;
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
                                    (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].elem).valor.valor1;
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(1) - (3)].elem).tipo == 1 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                    (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].elem).valor.valor2;
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 1){
                                    (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].elem).valor.valor1;
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(1) - (3)].elem).tipo == 2 && (yyvsp[(3) - (3)].elem).tipo == 2){
                                    (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].elem).valor.valor2;
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

  case 76:
#line 843 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                if((yyval.elem).tipo == 1){
                                  (yyval.elem).tipo = 2;
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].entero);
                                  flag_print = 2;
                                }
                                else if ((yyval.elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].entero);
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

  case 77:
#line 862 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                if((yyval.elem).tipo == 1){
                                  (yyval.elem).tipo = 2;
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor1 / (yyvsp[(3) - (3)].flotante);
                                  flag_print = 2;
                                }
                                else if ((yyval.elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = (yyvsp[(1) - (3)].elem).valor.valor2 / (yyvsp[(3) - (3)].flotante);
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

  case 78:
#line 881 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
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
                            ;}
    break;

  case 79:
#line 897 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //para pasarle a $$ un tipo elemento
                                int aux = (yyvsp[(1) - (3)].entero);   //guarda exp_e para no perder el valor
                                e_aux = &(yyvsp[(3) - (3)].elem);
                                (yyval.elem) = *e_aux;
                                if((yyval.elem).tipo == 1){
                                  (yyval.elem).tipo = 2;
                                  (yyval.elem).valor.valor2 = aux / (yyvsp[(3) - (3)].elem).valor.valor1;
                                  flag_print = 2;
                                }
                                else if ((yyval.elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = aux / (yyvsp[(3) - (3)].elem).valor.valor2;
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

  case 80:
#line 920 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                                double aux = (yyvsp[(1) - (3)].flotante);   //guarda exp_e para no perder el valor
                                e_aux = &(yyvsp[(3) - (3)].elem);
                                (yyval.elem) = *e_aux;
                                if((yyval.elem).tipo == 1){
                                  (yyval.elem).tipo = 2;
                                  (yyval.elem).valor.valor2 = aux / (yyvsp[(3) - (3)].elem).valor.valor1;
                                  flag_print = 2;
                                }
                                else if ((yyval.elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = aux / (yyvsp[(3) - (3)].elem).valor.valor2;
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

  case 81:
#line 943 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                                char * aux = (yyvsp[(1) - (3)].str);   //guarda exp_e para no perder el valor
                                e_aux = &(yyvsp[(3) - (3)].elem);
                                (yyval.elem) = *e_aux;
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
                            ;}
    break;

  case 82:
#line 962 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Pasa una copia a $$ un tipo elemento
                                e_aux = &(yyvsp[(3) - (6)].elem);
                                (yyval.elem) = *e_aux;
                                if((yyval.elem).tipo == 1){
                                  (yyval.elem).tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                                  if((yyvsp[(3) - (6)].elem).tipo == 1 && (yyvsp[(5) - (6)].elem).tipo==1){
                                    (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].elem).valor.valor1);
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(3) - (6)].elem).tipo == 1 && (yyvsp[(5) - (6)].elem).tipo == 2){
                                    (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].elem).valor.valor2);
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(3) - (6)].elem).tipo == 2 && (yyvsp[(5) - (6)].elem).tipo == 1){
                                    (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].elem).valor.valor1);
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(3) - (6)].elem).tipo == 2 && (yyvsp[(5) - (6)].elem).tipo == 2){
                                    (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].elem).valor.valor2);
                                    flag_print = 2;
                                  }
                                  else{
                                    printf("\n\t-->ERROR! Incompatible types\n");
                                    flag_incompatibles = 0;
                                    flag_print = 0;
                                  }
                                }
                                else if((yyval.elem).tipo ==2){
                                  if((yyvsp[(3) - (6)].elem).tipo == 1 && (yyvsp[(5) - (6)].elem).tipo==1){
                                    (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].elem).valor.valor1);
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(3) - (6)].elem).tipo == 1 && (yyvsp[(5) - (6)].elem).tipo == 2){
                                    (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].elem).valor.valor2);
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(3) - (6)].elem).tipo == 2 && (yyvsp[(5) - (6)].elem).tipo == 1){
                                    (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].elem).valor.valor1);
                                    flag_print = 2;
                                  }
                                  else if((yyvsp[(3) - (6)].elem).tipo == 2 && (yyvsp[(5) - (6)].elem).tipo == 2){
                                    (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].elem).valor.valor2);
                                    flag_print = 2;
                                  }
                                  else{
                                    printf("\n\t-->ERROR! Incompatible types\n");
                                    flag_incompatibles = 0;
                                    flag_print = 0;
                                  }
                                }
                                else if((yyval.elem).tipo == 3){
                                  if((yyvsp[(3) - (6)].elem).tipo == 3 && (yyvsp[(5) - (6)].elem).tipo == 3){
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

  case 83:
#line 1029 "sintactico.y"
    {//Pendiente
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Pasa una copia a $$ un tipo elemento
                                e_aux = &(yyvsp[(3) - (6)].elem);
                                (yyval.elem) = *e_aux;
                                if((yyval.elem).tipo == 1){
                                  (yyval.elem).tipo = 2;
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].entero));
                                  flag_print = 2;
                                }
                                else if ((yyval.elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].entero));
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

  case 84:
#line 1051 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Pasa una copia a $$ un tipo elemento
                                e_aux = &(yyvsp[(3) - (6)].elem);
                                (yyval.elem) = *e_aux;
                                if((yyval.elem).tipo == 1){
                                  (yyval.elem).tipo = 2;
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor1 , (yyvsp[(5) - (6)].flotante));
                                  flag_print = 2;
                                }
                                else if ((yyval.elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = pow((yyvsp[(3) - (6)].elem).valor.valor2 , (yyvsp[(5) - (6)].flotante));
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

  case 85:
#line 1073 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Pasa una copia a $$ un tipo elemento
                                e_aux = &(yyvsp[(3) - (6)].elem);
                                (yyval.elem) = *e_aux;
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
                            ;}
    break;

  case 86:
#line 1091 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //para pasarle a $$ un tipo elemento
                                int aux = (yyvsp[(3) - (6)].entero);   //guarda exp_e para no perder el valor
                                e_aux = &(yyvsp[(5) - (6)].elem);
                                (yyval.elem) = *e_aux;
                                if((yyval.elem).tipo == 1){
                                  (yyval.elem).tipo = 2;
                                  (yyval.elem).valor.valor2 = pow(aux , (yyvsp[(5) - (6)].elem).valor.valor1);
                                  flag_print = 2;
                                }
                                else if ((yyval.elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = pow(aux , (yyvsp[(5) - (6)].elem).valor.valor2);
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

  case 87:
#line 1114 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                                double aux = (yyvsp[(3) - (6)].flotante);   //guarda exp_e para no perder el valor
                                e_aux = &(yyvsp[(5) - (6)].elem);
                                (yyval.elem) = *e_aux;
                                if((yyval.elem).tipo == 1){
                                  (yyval.elem).tipo = 2;
                                  (yyval.elem).valor.valor2 = pow(aux , (yyvsp[(5) - (6)].elem).valor.valor1);
                                  flag_print = 2;
                                }
                                else if ((yyval.elem).tipo == 2){
                                  (yyval.elem).valor.valor2 = pow(aux , (yyvsp[(5) - (6)].elem).valor.valor2);
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

  case 88:
#line 1137 "sintactico.y"
    {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                                char * aux = (yyvsp[(3) - (6)].str);   //guarda exp_e para no perder el valor
                                e_aux = &(yyvsp[(5) - (6)].elem);
                                (yyval.elem) = *e_aux;
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
                            ;}
    break;

  case 89:
#line 1156 "sintactico.y"
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

  case 90:
#line 1182 "sintactico.y"
    {
                                      elemento e;
                                      elemento reservado;
                                      char *nombre;
                                      char indice[1000];
                                      int i;
                                      //sprintf(indice, "%d", i);
                                      e.name = (yyvsp[(2) - (6)].str);
                                      //reservado.name = $2;

                                      if(!Search(&ts, e)){
                                        for(i = 0;i<=(yyvsp[(4) - (6)].entero); i++){
                                          sprintf(indice, "%d", i);
                                          //indice=concatenar("__", indice);
                                          nombre = concatenar( "__", indice);
                                          nombre = concatenar((yyvsp[(2) - (6)].str), nombre);
                                          //printf("\n%s", nombre);
                                          e.name = nombre;
                                          e.tipo = 2;
                                          //printf("\n%s", e.name);
                                          Insert(&ts, e);
                                        }
                                      }
                                      else{
                                        printf("\n\t-->ERROR! Ya existe la variable\n");
                                      }
                                      ImprimeTS(&ts);
                                    ;}
    break;

  case 91:
#line 1214 "sintactico.y"
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

  case 92:
#line 1287 "sintactico.y"
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

  case 93:
#line 1321 "sintactico.y"
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

  case 94:
#line 1354 "sintactico.y"
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

  case 95:
#line 1378 "sintactico.y"
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

  case 96:
#line 1410 "sintactico.y"
    {
                                        elemento reservado;
                                        elemento*e_ts;
                                        elemento e;
                                        posicion p;
                                        char*nombre;
                                        char indice[1000];
                                        reservado.name = (yyvsp[(1) - (7)].str);
                                        //if(Search(&ts, reservado.name)!= NULL){


                                        //}
                                        sprintf(indice, "%d", (yyvsp[(3) - (7)].entero));
                                        nombre = concatenar( "__", indice);
                                        //printf("\n%s", nombre);
                                        nombre = concatenar((yyvsp[(1) - (7)].str), nombre);
                                        //printf("\n%s", nombre);
                                        e.name = nombre;
                                        printf("\n%s", e.name);
                                        e.name = nombre;
                                        p = Search(&ts, e);
                                        e_ts=getElement(&ts, p);
                                        printf("\n%s", e_ts->name);
                                        e_ts->valor.valor2=(yyvsp[(6) - (7)].flotante);
                                        ImprimeTS(&ts);
                                      ;}
    break;

  case 97:
#line 1437 "sintactico.y"
    {
                                        elemento reservado;
                                        elemento*e_ts;
                                        elemento e;
                                        posicion p;
                                        char*nombre;
                                        char indice[1000];
                                        reservado.name = (yyvsp[(1) - (7)].str);
                                        //if(Search(&ts, reservado.name)!= NULL){


                                        //}
                                        sprintf(indice, "%d", (yyvsp[(3) - (7)].entero));
                                        nombre = concatenar( "__", indice);
                                        //printf("\n%s", nombre);
                                        nombre = concatenar((yyvsp[(1) - (7)].str), nombre);
                                        //printf("\n%s", nombre);
                                        e.name = nombre;
                                        printf("\n%s", e.name);
                                        e.name = nombre;
                                        p = Search(&ts, e);
                                        e_ts=getElement(&ts, p);
                                        printf("\n%s", e_ts->name);
                                        e_ts->valor.valor2=(yyvsp[(6) - (7)].entero);
                                        ImprimeTS(&ts);
                                      ;}
    break;

  case 98:
#line 1464 "sintactico.y"
    {
                                        elemento*e_ts;
                                        elemento e;
                                        posicion p;
                                        char*nombre;
                                        char indice[1000];
                                        sprintf(indice, "%d", (yyvsp[(3) - (7)].entero));
                                        nombre = concatenar( "__", indice);
                                        printf("\n%s", nombre);
                                        nombre = concatenar((yyvsp[(1) - (7)].str), nombre);
                                        printf("\n%s", nombre);
                                        e.name = nombre;
                                        printf("\n%s", e.name);
                                        p = Search(&ts, e);
                                        e_ts=getElement(&ts, p);
                                        if((yyvsp[(6) - (7)].elem).tipo==1){
                                          e_ts->valor.valor2=(yyvsp[(6) - (7)].elem).valor.valor1;
                                        }
                                        else if((yyvsp[(6) - (7)].elem).tipo==2){
                                          e_ts->valor.valor2=(yyvsp[(6) - (7)].elem).valor.valor2;
                                        }

                                        ImprimeTS(&ts);
                                      ;}
    break;

  case 99:
#line 1489 "sintactico.y"
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

  case 100:
#line 1521 "sintactico.y"
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

  case 101:
#line 1552 "sintactico.y"
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

  case 102:
#line 1618 "sintactico.y"
    {
                                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                                if((yyvsp[(3) - (7)].elem).tipo==1 && (yyvsp[(5) - (7)].elem).tipo==1){
                                                  if((yyvsp[(3) - (7)].elem).valor.valor1 < (yyvsp[(5) - (7)].elem).valor.valor1)
                                                    (yyval.entero) = 1;
                                                  else
                                                    (yyval.entero) = 0;
                                                }
                                                else if((yyvsp[(3) - (7)].elem).tipo==1 && (yyvsp[(5) - (7)].elem).tipo==2){
                                                  if((yyvsp[(3) - (7)].elem).valor.valor1 < (yyvsp[(5) - (7)].elem).valor.valor2)
                                                    (yyval.entero) = 1;
                                                  else
                                                    (yyval.entero) = 0;
                                                }
                                                else if ((yyvsp[(3) - (7)].elem).tipo==2 && (yyvsp[(5) - (7)].elem).tipo==1){
                                                  if((yyvsp[(3) - (7)].elem).valor.valor2 < (yyvsp[(5) - (7)].elem).valor.valor1)
                                                    (yyval.entero) = 1;
                                                  else
                                                    (yyval.entero) = 0;
                                                }
                                                else if((yyvsp[(3) - (7)].elem).tipo==2 && (yyvsp[(5) - (7)].elem).tipo==2){
                                                  if((yyvsp[(3) - (7)].elem).valor.valor2 < (yyvsp[(5) - (7)].elem).valor.valor2)
                                                    (yyval.entero) = 1;
                                                  else
                                                    (yyval.entero) = 0;
                                                }
                                                else{
                                                  printf("\n\t--->ERROR! no se puede comparar con cadenas\n");
                                                }
                                              }
                                              else{
                                                flag_esta = 1;
                                                flag_incompatibles = 1;
                                                flag_op = 1;
                                              }
                                            ;}
    break;

  case 103:
#line 1655 "sintactico.y"
    {
                                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                                if((yyvsp[(3) - (7)].elem).tipo==1){
                                                  if((yyvsp[(3) - (7)].elem).valor.valor1 < (yyvsp[(5) - (7)].entero))
                                                    (yyval.entero) = 1;
                                                  else
                                                    (yyval.entero) = 0;
                                                }
                                                else if((yyvsp[(3) - (7)].elem).tipo==2){
                                                  if((yyvsp[(3) - (7)].elem).valor.valor2 < (yyvsp[(5) - (7)].entero))
                                                    (yyval.entero) = 1;
                                                  else
                                                    (yyval.entero) = 0;
                                                }
                                                else{
                                                  printf("\n\t--->ERROR! Incompatible types comparation\n");
                                                }
                                              }
                                              else{
                                                flag_esta = 1;
                                                flag_incompatibles = 1;
                                                flag_op = 1;
                                              }
                                            ;}
    break;

  case 104:
#line 1680 "sintactico.y"
    {
                                             if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                               if((yyvsp[(3) - (7)].elem).tipo==1){
                                                 if((yyvsp[(3) - (7)].elem).valor.valor1 < (yyvsp[(5) - (7)].flotante))
                                                   (yyval.entero) = 1;
                                                 else
                                                   (yyval.entero) = 0;
                                               }
                                               else if((yyvsp[(3) - (7)].elem).tipo==2){
                                                 if((yyvsp[(3) - (7)].elem).valor.valor2 < (yyvsp[(5) - (7)].flotante))
                                                   (yyval.entero) = 1;
                                                 else
                                                   (yyval.entero) = 0;
                                               }
                                               else{
                                                 printf("\n\t--->ERROR! Incompatible types comparation\n");
                                               }
                                             }
                                             else{
                                               flag_esta = 1;
                                               flag_incompatibles = 1;
                                               flag_op = 1;
                                             }
                                           ;}
    break;

  case 105:
#line 1705 "sintactico.y"
    {
                                             if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                               if((yyvsp[(3) - (7)].elem).tipo==3){
                                                 printf("\n\t--->ERROR! no se puede comparar entre cadenas\n");
                                               }
                                               else{
                                                 printf("\n\t--->ERROR! Incompatible types comparation\n");
                                               }
                                             }
                                             else{
                                               flag_esta = 1;
                                               flag_incompatibles = 1;
                                               flag_op = 1;
                                             }
                                           ;}
    break;

  case 106:
#line 1721 "sintactico.y"
    {
                                             if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                               if((yyvsp[(5) - (7)].elem).tipo==1){
                                                 if((yyvsp[(3) - (7)].entero) < (yyvsp[(5) - (7)].elem).valor.valor1)
                                                   (yyval.entero) = 1;
                                                 else
                                                   (yyval.entero) = 0;
                                               }
                                               else if((yyvsp[(5) - (7)].elem).tipo==2){
                                                 if((yyvsp[(3) - (7)].entero) < (yyvsp[(5) - (7)].elem).valor.valor2)
                                                   (yyval.entero) = 1;
                                                 else
                                                   (yyval.entero) = 0;
                                               }
                                               else{
                                                 printf("\n\t--->ERROR! Incompatible types comparation\n");
                                               }
                                             }
                                             else{
                                               flag_esta = 1;
                                               flag_incompatibles = 1;
                                               flag_op = 1;
                                             }
                                           ;}
    break;

  case 107:
#line 1746 "sintactico.y"
    {
                                             if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                               if((yyvsp[(5) - (7)].elem).tipo==1){
                                                 if((yyvsp[(3) - (7)].flotante) < (yyvsp[(5) - (7)].elem).valor.valor1)
                                                   (yyval.entero) = 1;
                                                 else
                                                   (yyval.entero) = 0;
                                               }
                                               else if((yyvsp[(5) - (7)].elem).tipo==2){
                                                 if((yyvsp[(3) - (7)].flotante) < (yyvsp[(5) - (7)].elem).valor.valor2)
                                                   (yyval.entero) = 1;
                                                 else
                                                   (yyval.entero) = 0;
                                               }
                                               else{
                                                 printf("\n\t--->ERROR! Incompatible types comparation\n");
                                               }
                                             }
                                             else{
                                               flag_esta = 1;
                                               flag_incompatibles = 1;
                                               flag_op = 1;
                                             }
                                           ;}
    break;

  case 108:
#line 1771 "sintactico.y"
    {
                                             if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                               //if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                                 if((yyvsp[(5) - (7)].elem).tipo==3){
                                                   printf("\n\t--->ERROR! no se puede comparar entre cadenas\n");
                                                 }
                                                 else{
                                                   printf("\n\t--->ERROR! Incompatible types comparation\n");
                                                 }
                                               }
                                               else{
                                                 flag_esta = 1;
                                                 flag_incompatibles = 1;
                                                 flag_op = 1;
                                               }

                                           ;}
    break;

  case 109:
#line 1789 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              if((yyvsp[(3) - (7)].elem).tipo==1 && (yyvsp[(5) - (7)].elem).tipo==1){
                                                if((yyvsp[(3) - (7)].elem).valor.valor1 > (yyvsp[(5) - (7)].elem).valor.valor1)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if((yyvsp[(3) - (7)].elem).tipo==1 && (yyvsp[(5) - (7)].elem).tipo==2){
                                                if((yyvsp[(3) - (7)].elem).valor.valor1 > (yyvsp[(5) - (7)].elem).valor.valor2)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if ((yyvsp[(3) - (7)].elem).tipo==2 && (yyvsp[(5) - (7)].elem).tipo==1){
                                                if((yyvsp[(3) - (7)].elem).valor.valor2 > (yyvsp[(5) - (7)].elem).valor.valor1)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if((yyvsp[(3) - (7)].elem).tipo==2 && (yyvsp[(5) - (7)].elem).tipo==2){
                                                if((yyvsp[(3) - (7)].elem).valor.valor2 > (yyvsp[(5) - (7)].elem).valor.valor2)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else{
                                                printf("\n\t--->ERROR! no se puede comparar con cadenas\n");
                                              }
                                            }
                                            else{
                                              flag_esta = 1;
                                              flag_incompatibles = 1;
                                              flag_op = 1;
                                            }
                                          ;}
    break;

  case 110:
#line 1826 "sintactico.y"
    {
                                             if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                               if((yyvsp[(3) - (7)].elem).tipo==1){
                                                 if((yyvsp[(3) - (7)].elem).valor.valor1 > (yyvsp[(5) - (7)].entero))
                                                   (yyval.entero) = 1;
                                                 else
                                                   (yyval.entero) = 0;
                                               }
                                               else if((yyvsp[(3) - (7)].elem).tipo==2){
                                                 if((yyvsp[(3) - (7)].elem).valor.valor2 > (yyvsp[(5) - (7)].entero))
                                                   (yyval.entero) = 1;
                                                 else
                                                   (yyval.entero) = 0;
                                               }
                                               else{
                                                 printf("\n\t--->ERROR! Incompatible types comparation\n");
                                               }
                                             }
                                             else{
                                               flag_esta = 1;
                                               flag_incompatibles = 1;
                                               flag_op = 1;
                                             }
                                           ;}
    break;

  case 111:
#line 1851 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              if((yyvsp[(3) - (7)].elem).tipo==1){
                                                if((yyvsp[(3) - (7)].elem).valor.valor1 > (yyvsp[(5) - (7)].flotante))
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if((yyvsp[(3) - (7)].elem).tipo==2){
                                                if((yyvsp[(3) - (7)].elem).valor.valor2 > (yyvsp[(5) - (7)].flotante))
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else{
                                                printf("\n\t--->ERROR! Incompatible types comparation\n");
                                              }
                                            }
                                            else{
                                              flag_esta = 1;
                                              flag_incompatibles = 1;
                                              flag_op = 1;
                                            }
                                          ;}
    break;

  case 112:
#line 1876 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              if((yyvsp[(3) - (7)].elem).tipo==3){
                                                printf("\n\t--->ERROR! no se puede comparar entre cadenas\n");
                                              }
                                              else{
                                                printf("\n\t--->ERROR! Incompatible types comparation\n");
                                              }
                                            }
                                            else{
                                              flag_esta = 1;
                                              flag_incompatibles = 1;
                                              flag_op = 1;
                                            }
                                          ;}
    break;

  case 113:
#line 1892 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              if((yyvsp[(5) - (7)].elem).tipo==1){
                                                if((yyvsp[(3) - (7)].entero) > (yyvsp[(5) - (7)].elem).valor.valor1)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if((yyvsp[(5) - (7)].elem).tipo==2){
                                                if((yyvsp[(3) - (7)].entero) > (yyvsp[(5) - (7)].elem).valor.valor2)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else{
                                                printf("\n\t--->ERROR! Incompatible types comparation\n");
                                              }
                                            }
                                            else{
                                              flag_esta = 1;
                                              flag_incompatibles = 1;
                                              flag_op = 1;
                                            }
                                          ;}
    break;

  case 114:
#line 1917 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              if((yyvsp[(5) - (7)].elem).tipo==1){
                                                if((yyvsp[(3) - (7)].flotante) > (yyvsp[(5) - (7)].elem).valor.valor1)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if((yyvsp[(5) - (7)].elem).tipo==2){
                                                if((yyvsp[(3) - (7)].flotante) > (yyvsp[(5) - (7)].elem).valor.valor2)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else{
                                                printf("\n\t--->ERROR! Incompatible types comparation\n");
                                              }
                                            }
                                            else{
                                              flag_esta = 1;
                                              flag_incompatibles = 1;
                                              flag_op = 1;
                                            }
                                          ;}
    break;

  case 115:
#line 1942 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              //if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                                if((yyvsp[(5) - (7)].elem).tipo==3){
                                                  printf("\n\t--->ERROR! no se puede comparar entre cadenas\n");
                                                }
                                                else{
                                                  printf("\n\t--->ERROR! Incompatible types comparation\n");
                                                }
                                              }
                                              else{
                                                flag_esta = 1;
                                                flag_incompatibles = 1;
                                                flag_op = 1;
                                              }
                                          ;}
    break;

  case 116:
#line 1959 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              if((yyvsp[(3) - (7)].elem).tipo==1 && (yyvsp[(5) - (7)].elem).tipo==1){
                                                if((yyvsp[(3) - (7)].elem).valor.valor1 == (yyvsp[(5) - (7)].elem).valor.valor1)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if((yyvsp[(3) - (7)].elem).tipo==1 && (yyvsp[(5) - (7)].elem).tipo==2){
                                                if((yyvsp[(3) - (7)].elem).valor.valor1 == (yyvsp[(5) - (7)].elem).valor.valor2)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if ((yyvsp[(3) - (7)].elem).tipo==2 && (yyvsp[(5) - (7)].elem).tipo==1){
                                                if((yyvsp[(3) - (7)].elem).valor.valor2 == (yyvsp[(5) - (7)].elem).valor.valor1)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if((yyvsp[(3) - (7)].elem).tipo==2 && (yyvsp[(5) - (7)].elem).tipo==2){
                                                if((yyvsp[(3) - (7)].elem).valor.valor2 == (yyvsp[(5) - (7)].elem).valor.valor2)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else{
                                                printf("\n\t--->ERROR! no se puede comparar con cadenas\n");
                                              }
                                            }
                                            else{
                                              flag_esta = 1;
                                              flag_incompatibles = 1;
                                              flag_op = 1;
                                            }
                                          ;}
    break;

  case 117:
#line 1996 "sintactico.y"
    {
                                             if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                               if((yyvsp[(3) - (7)].elem).tipo==1){
                                                 if((yyvsp[(3) - (7)].elem).valor.valor1 == (yyvsp[(5) - (7)].entero))
                                                   (yyval.entero) = 1;
                                                 else
                                                   (yyval.entero) = 0;
                                               }
                                               else if((yyvsp[(3) - (7)].elem).tipo==2){
                                                 if((yyvsp[(3) - (7)].elem).valor.valor2 == (yyvsp[(5) - (7)].entero))
                                                   (yyval.entero) = 1;
                                                 else
                                                   (yyval.entero) = 0;
                                               }
                                               else{
                                                 printf("\n\t--->ERROR! Incompatible types comparation\n");
                                               }
                                             }
                                             else{
                                               flag_esta = 1;
                                               flag_incompatibles = 1;
                                               flag_op = 1;
                                             }
                                           ;}
    break;

  case 118:
#line 2021 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              if((yyvsp[(3) - (7)].elem).tipo==1){
                                                if((yyvsp[(3) - (7)].elem).valor.valor1 == (yyvsp[(5) - (7)].flotante))
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if((yyvsp[(3) - (7)].elem).tipo==2){
                                                if((yyvsp[(3) - (7)].elem).valor.valor2 == (yyvsp[(5) - (7)].flotante))
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else{
                                                printf("\n\t--->ERROR! Incompatible types comparation\n");
                                              }
                                            }
                                            else{
                                              flag_esta = 1;
                                              flag_incompatibles = 1;
                                              flag_op = 1;
                                            }
                                          ;}
    break;

  case 119:
#line 2046 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              if((yyvsp[(3) - (7)].elem).tipo==3){
                                                printf("\n\t--->ERROR! no se puede comparar entre cadenas\n");
                                              }
                                              else{
                                                printf("\n\t--->ERROR! Incompatible types comparation\n");
                                              }
                                            }
                                            else{
                                              flag_esta = 1;
                                              flag_incompatibles = 1;
                                              flag_op = 1;
                                            }
                                          ;}
    break;

  case 120:
#line 2062 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              if((yyvsp[(5) - (7)].elem).tipo==1){
                                                if((yyvsp[(3) - (7)].entero) == (yyvsp[(5) - (7)].elem).valor.valor1)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if((yyvsp[(5) - (7)].elem).tipo==2){
                                                if((yyvsp[(3) - (7)].entero) == (yyvsp[(5) - (7)].elem).valor.valor2)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else{
                                                printf("\n\t--->ERROR! Incompatible types comparation\n");
                                              }
                                            }
                                            else{
                                              flag_esta = 1;
                                              flag_incompatibles = 1;
                                              flag_op = 1;
                                            }
                                          ;}
    break;

  case 121:
#line 2087 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              if((yyvsp[(5) - (7)].elem).tipo==1){
                                                if((yyvsp[(3) - (7)].flotante) == (yyvsp[(5) - (7)].elem).valor.valor1)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else if((yyvsp[(5) - (7)].elem).tipo==2){
                                                if((yyvsp[(3) - (7)].flotante) == (yyvsp[(5) - (7)].elem).valor.valor2)
                                                  (yyval.entero) = 1;
                                                else
                                                  (yyval.entero) = 0;
                                              }
                                              else{
                                                printf("\n\t--->ERROR! Incompatible types comparation\n");
                                              }
                                            }
                                            else{
                                              flag_esta = 1;
                                              flag_incompatibles = 1;
                                              flag_op = 1;
                                            }
                                          ;}
    break;

  case 122:
#line 2112 "sintactico.y"
    {
                                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                              //if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                                if((yyvsp[(5) - (7)].elem).tipo==3){
                                                  printf("\n\t--->ERROR! no se puede comparar entre cadenas\n");
                                                }
                                                else{
                                                  printf("\n\t--->ERROR! Incompatible types comparation\n");
                                                }
                                              }
                                              else{
                                                flag_esta = 1;
                                                flag_incompatibles = 1;
                                                flag_op = 1;
                                              }
                                          ;}
    break;


/* Line 1267 of yacc.c.  */
#line 4133 "sintactico.tab.c"
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


#line 2131 "sintactico.y"


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

