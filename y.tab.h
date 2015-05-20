/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 16 "parser.y" /* yacc.c:1909  */
char* str;

#line 145 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
