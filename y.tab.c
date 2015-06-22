/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.c"
#include <string.h>
extern int yylineno;

#define YY_BUF_SIZE 32768

extern int yylex();
extern FILE* yyin;
void yyerror(char *s);
void panic(int* array, int size);

str* symbolTable = NULL;
str* scope = NULL;


#line 85 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    var_identifier = 258,
    var_real = 259,
    var_integer = 260,
    var_char = 261,
    var_string = 262,
    lalg_integer = 263,
    lalg_real = 264,
    lalg_char = 265,
    lalg_string = 266,
    lalg_add = 267,
    lalg_sub = 268,
    lalg_mul = 269,
    lalg_div = 270,
    lalg_equal = 271,
    lalg_n_equal = 272,
    lalg_g_than = 273,
    lalg_l_than = 274,
    lalg_ge_than = 275,
    lalg_le_than = 276,
    lalg_assignment = 277,
    lalg_leftp = 278,
    lalg_rightp = 279,
    lalg_colon = 280,
    lalg_semicolon = 281,
    lalg_period = 282,
    lalg_comma = 283,
    lalg_program = 284,
    lalg_procedure = 285,
    lalg_function = 286,
    lalg_begin = 287,
    lalg_end = 288,
    lalg_const = 289,
    lalg_var = 290,
    lalg_read = 291,
    lalg_write = 292,
    lalg_while = 293,
    lalg_do = 294,
    lalg_for = 295,
    lalg_to = 296,
    lalg_if = 297,
    lalg_then = 298,
    lalg_else = 299
  };
#endif
/* Tokens.  */
#define var_identifier 258
#define var_real 259
#define var_integer 260
#define var_char 261
#define var_string 262
#define lalg_integer 263
#define lalg_real 264
#define lalg_char 265
#define lalg_string 266
#define lalg_add 267
#define lalg_sub 268
#define lalg_mul 269
#define lalg_div 270
#define lalg_equal 271
#define lalg_n_equal 272
#define lalg_g_than 273
#define lalg_l_than 274
#define lalg_ge_than 275
#define lalg_le_than 276
#define lalg_assignment 277
#define lalg_leftp 278
#define lalg_rightp 279
#define lalg_colon 280
#define lalg_semicolon 281
#define lalg_period 282
#define lalg_comma 283
#define lalg_program 284
#define lalg_procedure 285
#define lalg_function 286
#define lalg_begin 287
#define lalg_end 288
#define lalg_const 289
#define lalg_var 290
#define lalg_read 291
#define lalg_write 292
#define lalg_while 293
#define lalg_do 294
#define lalg_for 295
#define lalg_to 296
#define lalg_if 297
#define lalg_then 298
#define lalg_else 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:355  */
char* str;
		int type;
	   

#line 218 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    88,    89,    99,   100,   110,   111,   112,
     121,   130,   131,   141,   145,   149,   159,   170,   180,   184,
     188,   199,   199,   200,   211,   211,   212,   222,   222,   223,
     233,   234,   244,   244,   245,   255,   256,   265,   268,   268,
     269,   279,   280,   289,   289,   290,   300,   300,   301,   311,
     311,   312,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   341,   342,   352,   352,   352,   352,   352,   352,   353,
     363,   364,   374,   374,   374,   375,   385,   385,   386,   396,
     396,   397,   407,   408,   417,   417,   418,   428,   428,   429,
     439,   439,   439,   440,   449,   449,   450
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "var_identifier", "var_real",
  "var_integer", "var_char", "var_string", "lalg_integer", "lalg_real",
  "lalg_char", "lalg_string", "lalg_add", "lalg_sub", "lalg_mul",
  "lalg_div", "lalg_equal", "lalg_n_equal", "lalg_g_than", "lalg_l_than",
  "lalg_ge_than", "lalg_le_than", "lalg_assignment", "lalg_leftp",
  "lalg_rightp", "lalg_colon", "lalg_semicolon", "lalg_period",
  "lalg_comma", "lalg_program", "lalg_procedure", "lalg_function",
  "lalg_begin", "lalg_end", "lalg_const", "lalg_var", "lalg_read",
  "lalg_write", "lalg_while", "lalg_do", "lalg_for", "lalg_to", "lalg_if",
  "lalg_then", "lalg_else", "$accept", "programa", "corpo", "dc", "dc_c",
  "dc_v", "tipo_var", "variaveis", "mais_var", "dc_p", "dc_f",
  "parametros", "lista_par", "mais_par", "corpo_p", "dc_loc", "lista_arg",
  "argumentos", "mais_ident", "pfalsa", "comandos", "cmd", "condicao",
  "relacao", "expressao", "op_un", "outros_termos", "op_ad", "termo",
  "mais_fatores", "op_mul", "fator", "var_numero", YY_NULLPTR
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
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -106

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-106)))

#define YYTABLE_NINF -90

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,    24,    40,    47,  -106,   107,   -21,    77,    59,    62,
     128,    88,  -106,    69,  -106,   109,    67,    87,    91,    43,
      69,   110,   117,   125,   129,   169,   116,   119,  -106,   143,
     118,  -106,   150,    99,  -106,  -106,  -106,   130,  -106,   174,
     112,  -106,   124,   109,   109,   169,   139,   123,  -106,  -106,
     121,   188,     9,    38,  -106,    69,  -106,   109,  -106,    66,
       3,  -106,   159,  -106,   120,   207,  -106,  -106,     7,   141,
    -106,   145,   152,   156,   174,    82,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,   174,  -106,  -106,   174,     4,  -106,   211,
    -106,  -106,  -106,   190,  -106,  -106,  -106,  -106,  -106,   157,
    -106,   122,   158,    70,  -106,  -106,  -106,   112,  -106,  -106,
    -106,  -106,   146,   147,  -106,     8,  -106,   166,   222,  -106,
    -106,  -106,     9,   195,    38,   128,   177,   192,   197,     6,
     203,  -106,    82,   174,  -106,    82,  -106,  -106,     4,  -106,
    -106,    66,  -106,   199,  -106,    67,   200,    66,  -106,   183,
    -106,  -106,    52,  -106,    69,     6,    82,  -106,   122,  -106,
     196,    99,  -106,  -106,   209,  -106,  -106
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     9,     0,     0,     0,
       0,     0,     2,     0,    12,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,    23,     0,     0,    96,    95,    94,     0,    40,     0,
       0,    58,     0,     0,     0,     0,     0,    71,    72,    73,
       0,     0,     0,     0,     3,     0,    20,     0,    16,     0,
       0,    26,     0,     5,     0,    71,    57,    42,     0,     0,
      59,     0,     0,     0,     0,     0,    69,    63,    64,    65,
      66,    67,    68,     0,    93,    90,     0,     0,    91,    78,
      79,    80,    70,     0,    49,    18,    15,    14,    13,     0,
      29,     0,     0,     0,     9,     7,    45,     0,    41,    38,
      52,    53,     0,     0,    60,     0,    61,     0,    86,    87,
      88,    82,     0,    83,     0,     0,    17,     0,     0,     0,
       0,    43,     0,     0,    48,     0,    56,    92,     0,    76,
      10,     0,    27,    36,    37,     0,     0,     0,    54,     0,
      46,    84,     0,    21,     0,     0,     0,    34,     0,    30,
       0,     0,    55,    32,     0,    24,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -106,  -106,  -106,  -106,   172,    -9,  -105,    46,  -106,    92,
      72,   135,    81,  -106,    85,  -106,  -106,   134,  -106,  -106,
     -20,   -72,   198,  -106,   -37,  -106,   126,  -106,   149,   106,
    -106,   127,   229
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,   144,    99,   127,    58,    33,
      63,   102,   128,   159,   145,   146,    41,    69,   108,   136,
      26,    27,    50,    83,    51,    52,    92,    93,    53,   121,
     122,    87,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    16,    66,   115,   100,   118,    -4,   143,   106,   134,
      84,    -6,    85,    35,    36,     1,   -85,   -85,   119,   120,
     -85,   -85,   -85,   -85,   -85,   -85,   101,     3,   -85,   -28,
     -85,   -44,    86,   107,   -47,    94,   152,   113,   -11,    89,
       4,    15,   155,   -85,    38,   -85,   116,   -85,   -85,   117,
      90,    91,   135,   157,   -77,   -77,   -77,   -77,   -77,   -77,
     148,    30,   -77,   150,   -77,    39,    40,    96,    31,   -39,
      18,   100,    19,     5,    97,    98,   -33,   -77,   158,   -77,
      11,   -77,   -77,   114,   162,    19,    12,   -39,    34,    71,
      72,    35,    36,   101,    13,   -28,   149,    32,   -22,   -22,
      61,    20,   -50,    95,    17,    21,    22,    23,     6,    24,
      28,    25,    29,    67,    20,    68,   140,   -60,    21,    22,
      23,   104,    24,   126,    25,    29,   -75,   -75,   -75,    14,
      62,   -25,    46,    43,   160,   -83,   -83,    -8,    -8,    -8,
      44,     7,    -8,    59,    56,    55,   -75,   -62,    45,    54,
      -8,    -8,    -8,    60,     7,    -8,    64,    70,   -11,   -11,
     -11,    74,   103,    15,    75,   109,   -62,   -19,   -19,   110,
      47,    57,   -74,   -74,   -74,    65,   111,   -74,   -74,   -74,
     112,    48,    49,   125,   129,   132,    48,    49,   133,    76,
     137,   123,   -74,   -74,   -74,   -74,   -75,   -74,   -75,   -75,
     -75,   -31,    48,    49,    77,    78,    79,    80,    81,    82,
     -75,   -75,   -75,   -74,   -81,   -81,   -81,   141,   -75,   -83,
     -83,   142,   156,   -81,   -81,   -89,   -89,   -89,   147,   164,
     -75,   -12,   154,   165,   -81,   166,   105,   153,   130,   163,
     161,   131,   124,    73,   151,   -89,    37,     0,     0,   138,
     139
};

static const yytype_int16 yycheck[] =
{
      20,    10,    39,    75,     1,     1,    27,     1,     1,     1,
       1,    32,     3,     4,     5,    29,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    23,     3,    24,    26,
      26,    24,    23,    26,    26,    55,   141,    74,    32,     1,
       0,    35,   147,    39,     1,    41,    83,    43,    44,    86,
      12,    13,    44,     1,    16,    17,    18,    19,    20,    21,
     132,    15,    24,   135,    26,    22,    23,     1,     1,    26,
       1,     1,     3,    26,     8,     9,    24,    39,    26,    41,
       3,    43,    44,     1,   156,     3,    27,    44,     1,    43,
      44,     4,     5,    23,    32,    25,   133,    30,    31,    32,
       1,    32,    33,    57,    16,    36,    37,    38,     1,    40,
       1,    42,     3,     1,    32,     3,   125,    26,    36,    37,
      38,     1,    40,     1,    42,     3,     3,     4,     5,     1,
      31,    32,     3,    23,   154,    12,    13,    30,    31,    32,
      23,    34,    35,    25,     1,    26,    23,    24,    23,    33,
      30,    31,    32,     3,    34,    35,    26,    33,    30,    31,
      32,    22,     3,    35,    43,    24,    43,    24,    25,    24,
       1,    28,     3,     4,     5,     1,    24,     3,     4,     5,
      24,    12,    13,    26,    26,    39,    12,    13,    41,     1,
      24,     1,    23,     3,     4,     5,     1,    23,     3,     4,
       5,    24,    12,    13,    16,    17,    18,    19,    20,    21,
       3,     4,     5,    23,     3,     4,     5,    25,    23,    12,
      13,    24,    39,    12,    13,     3,     4,     5,    25,    33,
      23,    32,    32,   161,    23,    26,    64,   145,   103,   158,
     155,   107,    93,    45,   138,    23,    17,    -1,    -1,   122,
     124
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    46,     3,     0,    26,     1,    34,    47,    48,
      49,     3,    27,    32,     1,    35,    50,    16,     1,     3,
      32,    36,    37,    38,    40,    42,    65,    66,     1,     3,
      52,     1,    30,    54,     1,     4,     5,    77,     1,    22,
      23,    61,    65,    23,    23,    23,     3,     1,    12,    13,
      67,    69,    70,    73,    33,    26,     1,    28,    53,    25,
       3,     1,    31,    55,    26,     1,    69,     1,     3,    62,
      33,    52,    52,    67,    22,    43,     1,    16,    17,    18,
      19,    20,    21,    68,     1,     3,    23,    76,    77,     1,
      12,    13,    71,    72,    65,    52,     1,     8,     9,    51,
       1,    23,    56,     3,     1,    49,     1,    26,    63,    24,
      24,    24,    24,    69,     1,    66,    69,    69,     1,    14,
      15,    74,    75,     1,    73,    26,     1,    52,    57,    26,
      56,    62,    39,    41,     1,    44,    64,    24,    76,    71,
      50,    25,    24,     1,    50,    59,    60,    25,    66,    69,
      66,    74,    51,    54,    32,    51,    39,     1,    26,    58,
      65,    59,    66,    57,    33,    55,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    49,
      50,    50,    50,    51,    51,    51,    52,    52,    53,    53,
      53,    54,    54,    54,    55,    55,    55,    56,    56,    56,
      57,    57,    58,    58,    58,    59,    59,    60,    61,    61,
      61,    62,    62,    63,    63,    63,    64,    64,    64,    65,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    70,    71,    71,    71,    72,
      72,    72,    73,    73,    74,    74,    74,    75,    75,    75,
      76,    76,    76,    76,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     1,     4,     1,     6,     0,     1,
       6,     0,     1,     1,     1,     1,     2,     1,     2,     0,
       1,     6,     0,     1,     7,     0,     1,     3,     0,     1,
       4,     1,     2,     0,     1,     5,     1,     1,     3,     0,
       1,     2,     1,     2,     0,     1,     2,     0,     1,     3,
       0,     1,     4,     4,     6,     8,     5,     3,     2,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     0,     1,     3,     0,     1,     1,
       1,     1,     3,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1
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
#line 84 "parser.y" /* yacc.c:1646  */
    {
		printTable(symbolTable);
	}
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 90 "parser.y" /* yacc.c:1646  */
    {
		printf("corpo error\n");
		int syncArray[] = { lalg_period };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);

	}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 101 "parser.y" /* yacc.c:1646  */
    {
		printf("dc error\n");
		int syncArray[] = { lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);

	}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 113 "parser.y" /* yacc.c:1646  */
    { 
		printf("dc_c error\n");
		int syncArray[] = { lalg_var, lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "parser.y" /* yacc.c:1646  */
    {
		char* token = strtok((yyvsp[-4].str), " ");
		while(token){
			insertSymbol(&symbolTable,token, 1, (yyvsp[-2].type), NULL, scope);
			token = strtok(NULL, " ");
		}
	
	}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 132 "parser.y" /* yacc.c:1646  */
    { 
		printf("dc_v error\n");
		int syncArray[] = { lalg_procedure, lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 142 "parser.y" /* yacc.c:1646  */
    {
		(yyval.type) = 1;
	}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 146 "parser.y" /* yacc.c:1646  */
    {
		(yyval.type) = 0;
	}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 150 "parser.y" /* yacc.c:1646  */
    { 
		printf("tipo_var error\n");
		int syncArray[] = { lalg_semicolon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 160 "parser.y" /* yacc.c:1646  */
    {
		if((yyvsp[0].str) == NULL){
			(yyvsp[0].str) = (char*) calloc(sizeof(char),1);
		}

		(yyval.str) = (char*) malloc(sizeof(char) * (strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 2));
		strcpy((yyval.str), (yyvsp[-1].str));
		strcat((yyval.str), " ");
		strcat((yyval.str), (yyvsp[0].str));
	}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 171 "parser.y" /* yacc.c:1646  */
    { 
		printf("variaveis error\n");
		int syncArray[] = { lalg_colon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 181 "parser.y" /* yacc.c:1646  */
    {
		(yyval.str) = (yyvsp[0].str);
	}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 185 "parser.y" /* yacc.c:1646  */
    {
		(yyval.str) = NULL;
	}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 189 "parser.y" /* yacc.c:1646  */
    { 
		printf("mais_var error\n");
		int syncArray[] = { lalg_colon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 201 "parser.y" /* yacc.c:1646  */
    { 
		printf("procedure error\n");
		int syncArray[] = { lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 213 "parser.y" /* yacc.c:1646  */
    { 
		printf("function error\n");
		int syncArray[] = { lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "parser.y" /* yacc.c:1646  */
    { 
		printf("parametros error\n");
		int syncArray[] = { lalg_semicolon };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 235 "parser.y" /* yacc.c:1646  */
    { 
		printf("lista_par error\n");
		int syncArray[] = { lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 246 "parser.y" /* yacc.c:1646  */
    { 
		printf("mais_par error\n");
		int syncArray[] = { lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 257 "parser.y" /* yacc.c:1646  */
    { 
		printf("corpo error\n");
		int syncArray[] = { lalg_procedure, lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 270 "parser.y" /* yacc.c:1646  */
    { 
		printf("lista_arg error\n");
		int syncArray[] = { lalg_semicolon };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 281 "parser.y" /* yacc.c:1646  */
    { 
		printf("argumentos error\n");
		int syncArray[] = { lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 291 "parser.y" /* yacc.c:1646  */
    { 
		printf("mais_ident error\n");
		int syncArray[] = { lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 302 "parser.y" /* yacc.c:1646  */
    { 
		printf("pfalsa error\n");
		int syncArray[] = { lalg_semicolon };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 313 "parser.y" /* yacc.c:1646  */
    { 
		printf("comandos error\n");
		int syncArray[] = { lalg_end };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 331 "parser.y" /* yacc.c:1646  */
    { 
		printf("cmd error\n");
		int syncArray[] = { lalg_semicolon };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 343 "parser.y" /* yacc.c:1646  */
    { 
		printf("condicao error\n");
		int syncArray[] = { lalg_rightp, lalg_then };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 354 "parser.y" /* yacc.c:1646  */
    { 
		printf("relacao error\n");
		int syncArray[] = { lalg_add, lalg_sub, var_identifier, var_real, var_integer, lalg_leftp };
		yyclearin;
		yyerrok;
		panic(syncArray, 6);
	}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 365 "parser.y" /* yacc.c:1646  */
    { 
		printf("expressao error\n");
		int syncArray[] = { lalg_semicolon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 376 "parser.y" /* yacc.c:1646  */
    { 
		printf("op_un error\n");
		int syncArray[] = { var_identifier, var_real, var_integer, lalg_leftp };
		yyclearin;
		yyerrok;
		panic(syncArray, 4);
	}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 387 "parser.y" /* yacc.c:1646  */
    { 
		printf("outros_termos error\n");
		int syncArray[] = { lalg_colon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 398 "parser.y" /* yacc.c:1646  */
    { 
		printf("op_ad error\n");
		int syncArray[] = { lalg_add, lalg_sub, var_identifier, var_real, var_integer };
		yyclearin;
		yyerrok;
		panic(syncArray, 5);
	}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 409 "parser.y" /* yacc.c:1646  */
    { 
		printf("termo error\n");
		int syncArray[] = { lalg_semicolon, lalg_rightp, lalg_add, lalg_sub, var_identifier, var_real, var_integer, lalg_leftp };
		yyclearin;
		yyerrok;
		panic(syncArray, 8);
	}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 419 "parser.y" /* yacc.c:1646  */
    { 
		printf("mais_fatores error\n");
		int syncArray[] = { lalg_semicolon, lalg_rightp, lalg_add, lalg_sub };
		yyclearin;
		yyerrok;
		panic(syncArray, 4);
	}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 430 "parser.y" /* yacc.c:1646  */
    { 
		printf("op_mul error\n");
		int syncArray[] = { var_identifier, var_real, var_integer, lalg_leftp};
		yyclearin;
		yyerrok;
		panic(syncArray, 4);
	}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 441 "parser.y" /* yacc.c:1646  */
    { 
		printf("fator error\n");
		int syncArray[] = { lalg_mul, lalg_div, lalg_add, var_identifier, var_real, var_integer, lalg_leftp};
		yyclearin;
		yyerrok;
		panic(syncArray, 7);
	}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 451 "parser.y" /* yacc.c:1646  */
    { 
		printf("var_numero error\n");
		int syncArray[] = { var_identifier, var_real, var_integer, lalg_leftp};
		yyclearin;
		yyerrok;
		panic(syncArray, 5);
	}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1878 "y.tab.c" /* yacc.c:1646  */
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
#line 458 "parser.y" /* yacc.c:1906  */


#define lalg_EOF 0

int syncArrayProgram[] = { lalg_EOF };
int syncArrayCorpo[] = { lalg_period };
int syncArrayDc[] = { lalg_begin };
int syncArrayDcc[] = { lalg_var, lalg_begin };
int syncArrayDcv[] = { lalg_procedure, lalg_begin };
int syncArrayTipoVar[] = { lalg_semicolon, lalg_rightp };
int syncArrayVariaveis[] = { lalg_colon, lalg_rightp };
int syncArrayMaisVar[] = { lalg_colon, lalg_rightp };
int syncArrayDcp[] = { lalg_begin };

// Function that prints the error message
void yyerror(char *s)
{
	fprintf(stderr, "Parser: %s at line %d, token \'%s\' not expected\n", s, yylineno, yylval.str);
}

int main(int argc, char **argv)
{
	int status;

	// Uncomment this flag to turn debug mode on for the parser
	//yydebug = 1;

	// Checks if the program has 1 argument and pass it as a program to be analized
	if(argc == 2)
		yyin = fopen(argv[1], "r");

	// Creating the init buffer and pushing it into flex internal stack
	createInitBuffer();
	// Parsing the file and saving the status 
	status = yyparse();

	return (status);
}

// Function that verifies if a token belongs to the syncArray
int verifyToken(int* syncArray, int size, int token)
{
	int i;
	for(i = 0; i < size; i++)
	{
		//printf("looping: token: %d syncarray[i]: %d\n", token, syncArray[i]);
		if(token == syncArray[i])
		{
			return i;
		}
	}

	return(-1);
}

// Function that implements the panic mode error recovery
void panic(int* array, int size)
{
        int tokenTest = 0;
	
        printf("** Entering in panic mode **\n");

	tokenTest = yylex();

	// Keep skipping tokens until you find the syncronization token or the file ends
	while(verifyToken(array, size, tokenTest) < 0 && tokenTest != 0){
		printf("Token skipped: \'%s\' - code: %d\n", yylval.str, tokenTest);
		tokenTest = yylex();
	}

	// Pushing the string into flex intenal stack
	if(tokenTest != 0)
	{
		pushBuffer(yylval.str);
	}
	else
	{
		yyerror("Fim de arquivo nao esperado");
		exit(1);
	}

	printf("** Exiting panic mode **\n");
}
