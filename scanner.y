%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Struct.c"
    extern FILE *yyin;
	extern FILE *yyout;
    extern int yylineno;
    extern char *yytext;
    
    

    extern Ligne *table;
    extern Ligne *currentLigne;
    extern Ligne *table_de_symboles;


    extern char tt[100][100];
    extern int i = 0;

    extern int currentColumn = 1;
    extern int showsuccess = 0;


    void yysuccess(const char *s, const char *lexeme, int length);
    void yyerror(const char *s);
    void showLexicalError();
    extern int yylex();
%}


%token  PRO
%token  LOOPF LOOPW
%token  READ WRITE
%token  IF ELSE
%token  DOT COMMA SEMICOLON
%token  OPENPARENTHESIS CLOSEPARENTHESIS OPENHOOK CLOSEHOOK OPENBRACKET CLOSEBRACKET
%token  EQUAL NONEQUAL AND OR NON INFERIOR SUPERIOR INFERIOREQUAL SUPERIOREQUAL
%token  ADD SUB MULT DIV MOD
%token  ASSIGNMENT
%token  BOOLEAN CHAR INTEGER REALNUMBER
%token  INTEGERDECLARE STRINGDECLARE BOOLEENDECLARE REALDECLARE CHARDECLARE STRUCTDECLARE
%token  INLINECOMMENT
%token  LINEBREAK
%token  ID
%token  STRING




%left OPENPARENTHESIS CLOSEPARENTHESIS OPENBRACKET CLOSEBRACKET DOT ;
%left NON
%left MULT DIV MOD
%left ADD SUB
%left INFERIOR INFERIOREQUAL SUPERIOR SUPERIOREQUAL
%left EQUAL NONEQUAL
%left AND
%left OR
%right ASSIGNMENT 
%left COMMA



%start Input




%%
/*  La grammaire */
Input: PRO ID OPENHOOK code CLOSEHOOK ;
code:  affectation code |commentaire code |tabledeclaration code | structdeclaration code | declarations code | statements code | expression code | read code| write code | tabledeclaration | structdeclaration | declarations | statements | expression | read | write | commentaire | affectation;
declarations: declaration declarations | declaration;
declaration: type ID SEMICOLON | type ID ASSIGNMENT expression SEMICOLON | tabledeclaration;
type: INTEGER | REALNUMBER | CHAR | STRING | BOOLEAN | structure ;
structdeclaration: STRUCTDECLARE structure OPENHOOK declarations CLOSEHOOK ;
structure: ID ;
tabledeclaration: type OPENBRACKET tablesize CLOSEBRACKET ID SEMICOLON;
tablesize: ID | expressionAR | INTEGER;
statements : if_stm | if_else_stm | for_stm | while_stm ;
if_stm: IF OPENPARENTHESIS expression CLOSEPARENTHESIS OPENHOOK code CLOSEHOOK;
if_else_stm: IF OPENPARENTHESIS expression CLOSEPARENTHESIS OPENHOOK code CLOSEHOOK ELSE OPENHOOK code CLOSEHOOK;
for_stm: LOOPF ID ASSIGNMENT expression COMMA expression COMMA expression OPENHOOK code CLOSEHOOK;
while_stm: LOOPW OPENPARENTHESIS expression CLOSEPARENTHESIS OPENHOOK code CLOSEHOOK;
expression : expressionAR | expressionLG ;
read: READ OPENPARENTHESIS ID CLOSEPARENTHESIS SEMICOLON ;
write: WRITE OPENPARENTHESIS expression CLOSEPARENTHESIS SEMICOLON;
commentaire: INLINECOMMENT STRING;
expressionAR :OPENPARENTHESIS expressionAR CLOSEPARENTHESIS | expressionAR ADD expressionAR | expressionAR SUB expressionAR | SUB expressionAR | expressionAR MULT expressionAR | expressionAR DIV expressionAR | expressionAR MOD expressionAR | item;
item: ID | INTEGER | tableelement | champenreg ;
tableelement : ID OPENBRACKET tablesize CLOSEBRACKET;
champenreg: ID DOT ID;
expressionLG: OPENPARENTHESIS expressionLG CLOSEPARENTHESIS | expressionLG AND expressionLG | expressionLG OR expressionLG | NON expressionLG | element ;
element : ID | BOOLEAN | tableelement | champenreg | expressionAR EQUAL expressionAR | expressionAR NONEQUAL expressionAR | expressionAR INFERIOR expressionAR | expressionAR INFERIOREQUAL expressionAR | expressionAR SUPERIOR expressionAR | expressionAR SUPERIOREQUAL expressionAR | expressionLG EQUAL expressionLG | expressionLG NONEQUAL expressionLG;
affectation : ID ASSIGNMENT expression;
%%




int main(int argc, char **argv) {

  
    yyin = fopen(argv[1], "r");
    yyout = fopen("Output.txt", "w");

    if (argc>=3 && sscanf (argv[2], "%i", &showsuccess) != 1) {
        fprintf(stderr, "error - not an integer");
    }
    if(showsuccess != 0) showsuccess = 1;
    
    // alocate the symbols table
    table = insertLigne(&table ,yylineno);
    currentLigne=table;
    table_de_symboles = insertLigne(&table_de_symboles ,0);
    yyparse();

    // tokenize the source program
    fclose(yyin);
    fclose(yyout);
    return 0;

}

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



