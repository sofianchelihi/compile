%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Struct.c"
    // #define YYSTYPE union {
    //         char* string;
    //         int int_val;
    //         double real_val;
    //         char char_val;
    // }
    extern FILE *yyin;
	extern FILE *yyout;
    extern int yylineno;
    extern char *yytext;
    extern int yylex();
    int currentColumn = 1;
    Ligne *Table_sym;  
    int i =25;
%}

%union {
    char string[255];
    int int_val;
    double real_val;
    char char_val;
}


%token  PRO
%token  LOOPF LOOPW
%token  READ WRITE
%token  IF ELSE
%token  DOT COMMA
%token  <char_val> SEMICOLON
%token  OPENPARENTHESIS CLOSEPARENTHESIS OPENHOOK CLOSEHOOK OPENBRACKET CLOSEBRACKET
%token  EQUAL NONEQUAL AND OR NON INFERIOR SUPERIOR INFERIOREQUAL SUPERIOREQUAL
%token  ADD SUB MULT DIV MOD
%token  ASSIGNMENT
%token  <string> BOOLEAN
%token  <char_val> CHAR
%token  <int_val> INTEGER
%token  <real_val> REALNUMBER
%token  <string> INTEGERDECLARE 
%token  <string> STRINGDECLARE 
%token  <string> BOOLEENDECLARE 
%token  <string> REALDECLARE 
%token  <string> CHARDECLARE 
%token  <string> STRUCTDECLARE
%token  INLINECOMMENT
%token  LINEBREAK
%token  <string> STRING
%token  <string> ID




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
declarations: declaration declarations | declaration ;


// declaration:    INTEGERDECLARE ID SEMICOLON {  ;printf("%s : %s\n",$1,$2); }|
//                 REALDECLARE ID SEMICOLON { printf("%s : %s\n",$1,$2); }| 
//                 STRINGDECLARE ID SEMICOLON { printf("%s : %s\n",$1,$2); }|
//                 CHARDECLARE ID SEMICOLON { printf("%s : %s\n",$1,$2); }| 
//                 BOOLEENDECLARE ID SEMICOLON { printf("%s : %s\n",$1,$2); }| 
//                 INTEGERDECLARE ID ASSIGNMENT expression SEMICOLON |
//                 REALDECLARE | STRINGDECLARE | CHARDECLARE | BOOLEENDECLARE | tabledeclaration;


declaration: type ID SEMICOLON { insertColumn(Table_sym,$<string>1,$2,"",1); };
type: INTEGERDECLARE  | REALDECLARE  | CHARDECLARE  | STRINGDECLARE  | BOOLEENDECLARE | structure ;
structdeclaration: STRUCTDECLARE structure OPENHOOK declarations CLOSEHOOK ;
structure: ID ;
tabledeclaration: type OPENBRACKET tablesize CLOSEBRACKET ID SEMICOLON;
tablesize: ID | expressionAR | INTEGER;
statements : if_stm | if_else_stm | for_stm | while_stm ;
if_stm: IF OPENPARENTHESIS expressionLG CLOSEPARENTHESIS OPENHOOK code CLOSEHOOK;
if_else_stm: IF OPENPARENTHESIS expressionLG CLOSEPARENTHESIS OPENHOOK code CLOSEHOOK ELSE OPENHOOK code CLOSEHOOK;
for_stm: LOOPF ID ASSIGNMENT expressionAR COMMA expressionLG COMMA expressionAR OPENHOOK code CLOSEHOOK;
while_stm: LOOPW OPENPARENTHESIS expressionLG CLOSEPARENTHESIS OPENHOOK code CLOSEHOOK;
expression : expressionAR | expressionLG;
read: READ OPENPARENTHESIS ID CLOSEPARENTHESIS SEMICOLON ;
write: WRITE OPENPARENTHESIS expression CLOSEPARENTHESIS SEMICOLON;
commentaire: INLINECOMMENT STRING;
expressionAR :OPENPARENTHESIS expressionAR CLOSEPARENTHESIS | expressionAR ADD expressionAR | expressionAR SUB expressionAR | SUB expressionAR | expressionAR MULT expressionAR | expressionAR DIV expressionAR | expressionAR MOD expressionAR | item;
item: ID | INTEGER | tableelement | champenreg ;
tableelement : ID OPENBRACKET tablesize CLOSEBRACKET;
champenreg: ID DOT ID ;
expressionLG: OPENPARENTHESIS expressionLG CLOSEPARENTHESIS | expressionLG AND expressionLG | expressionLG OR expressionLG | NON expressionLG | element ;
element : ID | BOOLEAN | tableelement | champenreg | expressionAR EQUAL expressionAR | expressionAR NONEQUAL expressionAR | expressionAR INFERIOR expressionAR | expressionAR INFERIOREQUAL expressionAR | expressionAR SUPERIOR expressionAR | expressionAR SUPERIOREQUAL expressionAR | expressionLG EQUAL expressionLG | expressionLG NONEQUAL expressionLG;
affectation : ID ASSIGNMENT expression | type ID ASSIGNMENT expression;
%%




int main(int argc, char **argv) {
    Table_sym = insertLigne(&Table_sym ,1);

 //  insertColumn(Table_sym,"STRING","user","islam",1);

    yyin = fopen(argv[1], "r");
    yyout = fopen("Output.txt", "r+");

    int value = yyparse();

    Column *col = Table_sym->Columns;
    while(col!=NULL){
        printf("%s  :   %s\n",col->nameToken,col->typeToken);
        col=col->suivC;
    }


    if(value==1){
        printf("\nErreur dans la ligne :%d  et la colonne : %d\n",yylineno,currentColumn);
    }else{
        printf("Complation success");
    }
    fclose(yyin);
    fclose(yyout);
    return 0;
}





