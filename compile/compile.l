
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "syntax.tab.h"

    int currentColumn = 1;
    int showsuccess = 1;



    void yysuccess(const char *s, const char *lexeme, int length);
    void yyerror(const char *s);
    void showLexicalError();
%}

/*Used to get the current line INTEGER*/
%option yylineno 
%option noyywrap 
%option outfile = "scanner.c"
/*Used for multiline comments*/
%x c_comment     


/*Reserved keywords*/
PRO "pro :"
LOOPF for
LOOPW while
READ read
WRITE write

/*MAIN (\(\)){UNDERSCORE}" entry"(\(\))*/

IF if
ELSE else

/*Identifiers*/


ID [a-zA-Z][_|a-zA-Z0-9]*

ANYTHING .*
DOT \.
LINEBREAK "\n"|"\r"
SEMICOLON ;
COMMA \,

OPENPARENTHESIS \(
CLOSEPARENTHESIS \)
OPENHOOK \{
CLOSEHOOK \}
OPENBRACKET \[
CLOSEBRACKET \]


/*Logical and arithmetic operators*/
EQUAL =
NONEQUAL <>
AND and
OR or
NON not
INFERIOR \<
SUPERIOR \>
INFERIOREQUAL \<\=
SUPERIOREQUAL \>\=
ADD \+
SUB -
MULT \*
DIV \/
MOD \%

/*Elementary instructions*/
ASSIGNMENT \<\-

/*Constant strings and numbers*/
DIGIT [0-9]
NUMBER ([1-9]{DIGIT}*|"0")
INTEGER -?{NUMBER}
REALNUMBER -?{NUMBER}"\."{DIGIT}+
STRING (\"{ANYTHING}\")|(\'{ANYTHING}\') 
CHAR \'.\'
BOOLEAN true|false
SPACE ' ' | \t

/*Declarations*/
INTEGERDECLARE int
STRINGDECLARE string
BOOLEENDECLARE bool
REALDECLARE float
CHARDECLARE char 
STRUCTDECLARE struc

/*Comments*/
INLINECOMMENT #{ANYTHING}


%%

{PRO} {
    yysuccess("pro", yytext, yyleng);
    currentColumn +=yyleng;
    return(PRO);
}

{LOOPF} {
    yysuccess("for", yytext, yyleng);
    currentColumn +=yyleng;
    return(LOOPF);
}
{LOOPW} {
    yysuccess("while", yytext, yyleng);
    currentColumn +=yyleng;
    return(LOOPW);
}

{READ} {
    yysuccess("read", yytext, yyleng);
    currentColumn +=yyleng;
    return(READ);
}

{WRITE} {
    yysuccess("write", yytext, yyleng);
    currentColumn +=yyleng;
    return(WRITE);
}

{IF} {
    yysuccess("if", yytext, yyleng);
    currentColumn +=yyleng;
    return(IF);
}

{ELSE} {
    yysuccess("else", yytext, yyleng);
    currentColumn +=yyleng;
    return(ELSE);
}



{DOT} {
    yysuccess("point", yytext, yyleng);
    currentColumn +=yyleng;
    return(DOT);
}

{COMMA} {
    yysuccess("virgule", yytext, yyleng);
    currentColumn +=yyleng;
    return(COMMA);
}

{SEMICOLON} {
    yysuccess("pointVirgule", yytext, yyleng);
    currentColumn +=yyleng;
    return(SEMICOLON);
}

{OPENPARENTHESIS} {
    yysuccess("parenthesO", yytext, yyleng);
    currentColumn +=yyleng;
    return(OPENPARENTHESIS);
}

{CLOSEPARENTHESIS} {
    yysuccess("parenthesF", yytext, yyleng);
    currentColumn +=yyleng;
    return(CLOSEPARENTHESIS);
}

{OPENHOOK} {
    yysuccess("accoladeO", yytext, yyleng);
    currentColumn +=yyleng;
    return(OPENHOOK);
}

{CLOSEHOOK} {
    yysuccess("accoladeF", yytext, yyleng);
    currentColumn +=yyleng;
    return(CLOSEHOOK);
}

{OPENBRACKET} {
    yysuccess("bracketO", yytext, yyleng);
    currentColumn +=yyleng;
    return(OPENBRACKET);
}

{CLOSEBRACKET} {
    yysuccess("bracketF", yytext, yyleng);
    currentColumn +=yyleng;
    return(CLOSEBRACKET);
}
			
{EQUAL} {
    yysuccess("egale", yytext, yyleng);
    currentColumn +=yyleng;
    return(EQUAL);
}

{NONEQUAL} {
    yysuccess("nonEgale", yytext, yyleng);
    currentColumn +=yyleng;
    return(NONEQUAL);
}

{AND} {
    yysuccess("AND", yytext, yyleng);
    currentColumn +=yyleng;
    return(AND);
}

{OR} {
    yysuccess("OR", yytext, yyleng);
    currentColumn +=yyleng;
    return(OR);
}

{NON} {
    yysuccess("NON", yytext, yyleng);
    currentColumn +=yyleng;
    return(NON);
}

{INFERIOR} {
    yysuccess("INFERIOR", yytext, yyleng);
    currentColumn +=yyleng;
    return(INFERIOR);
}

{SUPERIOR} {
    yysuccess("SUPERIOR", yytext, yyleng);
    currentColumn +=yyleng;
    return(SUPERIOR);
}

{INFERIOREQUAL} {
    yysuccess("INFERIOREQUAL", yytext, yyleng);
    currentColumn +=yyleng;
    return(INFERIOREQUAL);
}

{SUPERIOREQUAL} {
    yysuccess("SUPERIOREQUAL", yytext, yyleng);
    currentColumn +=yyleng;
    return(SUPERIOREQUAL);
}

{ADD} {
    yysuccess("ADDITION", yytext, yyleng);
    currentColumn +=yyleng;
    return(ADD);
}

{SUB} {
    yysuccess("SUBTRACTION", yytext, yyleng);
    currentColumn +=yyleng;
    return(SUB);
}

{MULT} {
    yysuccess("MULTIPLICATION", yytext, yyleng);
    currentColumn +=yyleng;
    return(MULT);
}

{DIV} {
    yysuccess("DIVISION", yytext, yyleng);
    currentColumn +=yyleng;
    return(DIV);
}

{MOD} {
    yysuccess("MODULO", yytext, yyleng);
    currentColumn +=yyleng;
    return(MOD);
}


{ASSIGNMENT} {
    yysuccess("ASSIGNMENT", yytext, yyleng);
    currentColumn +=yyleng;
    return(ASSIGNMENT);
}

{BOOLEAN} {
    yysuccess("boolean", yytext, yyleng);
    currentColumn +=yyleng;
    return(BOOLEAN);
}

{CHAR} {
    yysuccess("charactere", yytext, yyleng);
    currentColumn +=yyleng;
    return(CHAR);
}

{INTEGER} {
    yysuccess("INTEGER", yytext, yyleng);
    currentColumn +=yyleng;
    return(INTEGER);
}




{REALNUMBER} {
    yysuccess("REAL", yytext, yyleng);
    currentColumn +=yyleng;
    return(REALNUMBER);
}




{INTEGERDECLARE} {
    yysuccess("INTEGERdeclaration", yytext, yyleng);
    currentColumn +=yyleng;
    return(INTEGERDECLARE);
}

{STRINGDECLARE} {
    yysuccess("STRINGdeclaration", yytext, yyleng);
    currentColumn +=yyleng;
    return(STRINGDECLARE);
}


{BOOLEENDECLARE} {
    yysuccess("BOOLEANdeclaration", yytext, yyleng);
    currentColumn +=yyleng;
    return(BOOLEENDECLARE);
}

{REALDECLARE} {
    yysuccess("REALdeclaration",yytext, yyleng);
    currentColumn +=yyleng;
    return(REALDECLARE);
}
{CHARDECLARE} {
    yysuccess("CHARdeclaration",yytext, yyleng);
    currentColumn +=yyleng;
    return(CHARDECLARE);
}

{STRUCTDECLARE} {
    yysuccess("STRUCTdeclaration", yytext, yyleng);
    currentColumn +=yyleng;
    return(STRUCTDECLARE);
}


{INLINECOMMENT} {
    yysuccess("comment", "", yyleng);
    currentColumn +=yyleng;
    return(INLINECOMMENT);
}

{LINEBREAK} {
    currentColumn = 1;
}


{ID} {
    yysuccess("id", yytext, yyleng);
    currentColumn +=yyleng;
    FILE *f=fopen("tab_symb.txt","r+");
    fprintf(f,"%s\n",yytext);
    fclose(f);
    return(ID);
}


{STRING} {
    yysuccess("STRING", yytext, yyleng);
    currentColumn +=yyleng;
    return(STRING);
} 


[\ ,\t]+ {
    yysuccess("SPACE", yytext, yyleng);
    currentColumn+=yyleng;
}

<<EOF>> yyterminate();

. {
    yyerror("Unrecognized character");
    showLexicalError();
    yyterminate();
}


%%


void yysuccess(const char *s, const char *lexeme, int length) {
    if(showsuccess) {
        printf("Found %s : ", s);
        printf("\033[0;32m");
        printf("'%s'", lexeme); 
        printf("\033[0m"); 
        printf(" at Ln %d Col %d \n", yylineno, currentColumn);
    }
}

void yyerror(const char *s) {
    printf("\033[0;31m"); 
    printf("\033[0m"); 
}

void showLexicalError() {    
    fprintf(yyout, "Lexical error in Line %d Column %d : Unrecognized character: %s \n", yylineno, currentColumn, yytext);
}

