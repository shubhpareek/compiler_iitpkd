/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
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
    BEG = 258,
    END = 259,
    T_INT = 260,
    T_BOOL = 261,
    WRITE = 262,
    DECL = 263,
    ENDDECL = 264,
    NUM = 265,
    VAR = 266,
    IF = 267,
    THEN = 268,
    ELSE = 269,
    ENDIF = 270,
    LOGICAL_AND = 271,
    LOGICAL_NOT = 272,
    LOGICAL_OR = 273,
    EQUALEQUAL = 274,
    LESSTHANOREQUAL = 275,
    GREATERTHANOREQUAL = 276,
    NOTEQUAL = 277,
    WHILE = 278,
    DO = 279,
    ENDWHILE = 280,
    FOR = 281,
    T = 282,
    F = 283,
    MAIN = 284,
    RETURN = 285
  };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define T_INT 260
#define T_BOOL 261
#define WRITE 262
#define DECL 263
#define ENDDECL 264
#define NUM 265
#define VAR 266
#define IF 267
#define THEN 268
#define ELSE 269
#define ENDIF 270
#define LOGICAL_AND 271
#define LOGICAL_NOT 272
#define LOGICAL_OR 273
#define EQUALEQUAL 274
#define LESSTHANOREQUAL 275
#define GREATERTHANOREQUAL 276
#define NOTEQUAL 277
#define WHILE 278
#define DO 279
#define ENDWHILE 280
#define FOR 281
#define T 282
#define F 283
#define MAIN 284
#define RETURN 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "src/compiler.y"

	int iValue;
	char * sindex;
	struct varlis*vl;
	struct arrtype*at;
	struct glis*gl;
	struct nptstmt * npt;
	struct nptlist * nptlis;
	struct gdec*gd;

#line 128 "src/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
