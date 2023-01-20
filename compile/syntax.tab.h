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
#line 35 "syntax.y"

    char string[255];
    int int_val;
    double real_val;
    char char_val;

#line 112 "syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
