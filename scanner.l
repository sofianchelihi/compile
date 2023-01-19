
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Struct.c"
    #include "scanner.tab.h"
    
    

    Ligne *table;
    Ligne *currentLigne;
    Ligne *table_de_symboles;


    char tt[100][100];
    int i = 0;

    int currentColumn = 1;
    int showsuccess = 0;


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
    insertColumn(currentLigne,"motCle",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(PRO);
}

{LOOPF} {
    yysuccess("for", yytext, yyleng);
    insertColumn(currentLigne,"motCle",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(LOOPF);
}
{LOOPW} {
    yysuccess("while", yytext, yyleng);
    insertColumn(currentLigne,"motCle",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(LOOPW);
}

{READ} {
    yysuccess("read", yytext, yyleng);
    insertColumn(currentLigne,"motCle",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(READ);
}

{WRITE} {
    yysuccess("write", yytext, yyleng);
    insertColumn(currentLigne,"motCle",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(WRITE);
}

{IF} {
    yysuccess("if", yytext, yyleng);
    insertColumn(currentLigne,"motCle",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(IF);
}

{ELSE} {
    yysuccess("else", yytext, yyleng);
    insertColumn(currentLigne,"motCle",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(ELSE);
}



{DOT} {
    yysuccess("point", yytext, yyleng);
    insertColumn(currentLigne,"specialChar",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(DOT);
}

{COMMA} {
    yysuccess("virgule", yytext, yyleng);
    insertColumn(currentLigne,"specialChar",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(COMMA);
}

{SEMICOLON} {
    yysuccess("pointVirgule", yytext, yyleng);
    insertColumn(currentLigne,"specialChar",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(SEMICOLON);
}

{OPENPARENTHESIS} {
    yysuccess("parenthesO", yytext, yyleng);
    insertColumn(currentLigne,"specialChar",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(OPENPARENTHESIS);
}

{CLOSEPARENTHESIS} {
    yysuccess("parenthesF", yytext, yyleng);
    insertColumn(currentLigne,"specialChar",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(CLOSEPARENTHESIS);
}

{OPENHOOK} {
    yysuccess("accoladeO", yytext, yyleng);
    insertColumn(currentLigne,"specialChar",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(OPENHOOK);
}

{CLOSEHOOK} {
    yysuccess("accoladeF", yytext, yyleng);
    insertColumn(currentLigne,"specialChar",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(CLOSEHOOK);
}

{OPENBRACKET} {
    yysuccess("bracketO", yytext, yyleng);
    insertColumn(currentLigne,"specialChar",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(OPENBRACKET);
}

{CLOSEBRACKET} {
    yysuccess("bracketF", yytext, yyleng);
    insertColumn(currentLigne,"specialChar",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(CLOSEBRACKET);
}
			
{EQUAL} {
    yysuccess("egale", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(EQUAL);
}

{NONEQUAL} {
    yysuccess("nonEgale", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(NONEQUAL);
}

{AND} {
    yysuccess("AND", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(AND);
}

{OR} {
    yysuccess("OR", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(OR);
}

{NON} {
    yysuccess("NON", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(NON);
}

{INFERIOR} {
    yysuccess("INFERIOR", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(INFERIOR);
}

{SUPERIOR} {
    yysuccess("SUPERIOR", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(SUPERIOR);
}

{INFERIOREQUAL} {
    yysuccess("INFERIOREQUAL", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(INFERIOREQUAL);
}

{SUPERIOREQUAL} {
    yysuccess("SUPERIOREQUAL", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(SUPERIOREQUAL);
}

{ADD} {
    yysuccess("ADDITION", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(ADD);
}

{SUB} {
    yysuccess("SUBTRACTION", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(SUB);
}

{MULT} {
    yysuccess("MULTIPLICATION", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(MULT);
}

{DIV} {
    yysuccess("DIVISION", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(DIV);
}

{MOD} {
    yysuccess("MODULO", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(MOD);
}


{ASSIGNMENT} {
    yysuccess("ASSIGNMENT", yytext, yyleng);
    insertColumn(currentLigne,"operateur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(ASSIGNMENT);
}

{BOOLEAN} {
    yysuccess("boolean", yytext, yyleng);
    insertColumn(currentLigne,"valeur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(BOOLEAN);
}

{CHAR} {
    yysuccess("charactere", yytext, yyleng);
    insertColumn(currentLigne,"valeur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(CHAR);
}

{INTEGER} {
    yysuccess("INTEGER", yytext, yyleng);
    insertColumn(currentLigne,"valeur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(INTEGER);
}




{REALNUMBER} {
    yysuccess("REAL", yytext, yyleng);
    insertColumn(currentLigne,"valeur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(REALNUMBER);
}




{INTEGERDECLARE} {
    yysuccess("INTEGERdeclaration", yytext, yyleng);
    insertColumn(currentLigne,"declaration",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(INTEGERDECLARE);
}

{STRINGDECLARE} {
    yysuccess("STRINGdeclaration", yytext, yyleng);
     insertColumn(currentLigne,"declaration",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(STRINGDECLARE);
}


{BOOLEENDECLARE} {
    yysuccess("BOOLEANdeclaration", yytext, yyleng);
     insertColumn(currentLigne,"declaration",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(BOOLEENDECLARE);
}

{REALDECLARE} {
    yysuccess("REALdeclaration",yytext, yyleng);
    insertColumn(currentLigne,"declaration",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(REALDECLARE);
}
{CHARDECLARE} {
    yysuccess("CHARdeclaration",yytext, yyleng);
     insertColumn(currentLigne,"declaration",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(CHARDECLARE);
}

{STRUCTDECLARE} {
    yysuccess("STRUCTdeclaration", yytext, yyleng);
    insertColumn(currentLigne,"declaration",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(STRUCTDECLARE);
}


{INLINECOMMENT} {
    yysuccess("comment", "", yyleng);
    insertColumn(currentLigne,"comment",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(INLINECOMMENT);
}

{LINEBREAK} {
    currentColumn = 1;
    currentLigne = insertLigne(&table,yylineno);
    return(LINEBREAK);
}


{ID} {
    yysuccess("id", yytext, yyleng);
    insertColumn(currentLigne,"id",yytext,"",currentColumn);
    insertColumn(table_de_symboles,"id",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(ID);
}


{STRING} {
    yysuccess("STRING", yytext, yyleng);
    insertColumn(currentLigne,"valeur",yytext,"",currentColumn);
    currentColumn +=yyleng;
    return(STRING);
} 


[\ ,\t]+ {
    currentColumn+=yyleng;
}

<<EOF>> yyterminate();

. {
    yyerror("Unrecognized character");
    showLexicalError();
    yyterminate();
}


%%

