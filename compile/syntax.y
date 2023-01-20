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
    extern void yyerror(const char *s);
    int currentColumn = 1;
    Ligne *Table_sym;  
    int i =25;
    int ri=1;
    typedef struct quad{
        char op[4];
        char opr1[10];
        char opr2[10];
        char res[10];
    }quad;

    quad tab_quad[1000];
    int taille;
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
%left NON;
%left MULT DIV MOD;
%left ADD SUB;
%left INFERIOR INFERIOREQUAL SUPERIOR SUPERIOREQUAL;
%left EQUAL NONEQUAL;
%left AND;
%left OR;
%right ASSIGNMENT ;
%left COMMA;
%start Input;




%%
/*  La grammaire */
Input: | PRO ID OPENHOOK code CLOSEHOOK ;
code: code code | affectation | commentaire  | tabledeclaration   | declaration | statements  | expression  | read | write  ;
declaration: type ID SEMICOLON { 
    if(get_id(Table_sym,$2)!=NULL){
        printf("Variable deja declarer : %s \n ",$2);
        YYERROR;
    }else{
        insertColumn(Table_sym,$<string>1,$2,"",1); 
    }
    };
type: INTEGERDECLARE  | REALDECLARE  | CHARDECLARE  | STRINGDECLARE  | BOOLEENDECLARE | structure ;
// structdeclaration: STRUCTDECLARE structure OPENHOOK declarations CLOSEHOOK ;
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
expressionAR :OPENPARENTHESIS expressionAR CLOSEPARENTHESIS { strcpy( $<string>$,$<string>2); } | expressionAR ADD expressionAR {
    char res[10];
    strcpy( tab_quad[taille].op,"+");
    strcpy( tab_quad[taille].opr1,$<string>1);
    strcpy( tab_quad[taille].opr2,$<string>3);
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( $<string>$,res);
} | expressionAR SUB expressionAR {
        char res[10];
    strcpy( tab_quad[taille].op,"-");
    strcpy( tab_quad[taille].opr1,$<string>1);
    strcpy( tab_quad[taille].opr2,$<string>3);
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( $<string>$,res);
}| SUB expressionAR {
    char res[10];
    strcpy( tab_quad[taille].op,"-");
    strcpy( tab_quad[taille].opr1,"0");
    strcpy( tab_quad[taille].opr2,$<string>2);
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( $<string>$,res);
}| expressionAR MULT expressionAR {
    char res[10];
    strcpy( tab_quad[taille].op,"*");
    strcpy( tab_quad[taille].opr1,$<string>1);
    strcpy( tab_quad[taille].opr2,$<string>3);
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( $<string>$,res);
}| expressionAR DIV expressionAR {
    char res[10];
    strcpy( tab_quad[taille].op,"/");
    strcpy( tab_quad[taille].opr1,$<string>1);
    strcpy( tab_quad[taille].opr2,$<string>3);
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( $<string>$,res);
}| expressionAR MOD expressionAR {
    char res[10];
    strcpy( tab_quad[taille].op,"\%");
    strcpy( tab_quad[taille].opr1,$<string>1);
    strcpy( tab_quad[taille].opr2,$<string>3);
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( $<string>$,res);
}| item;
item: ID { strcpy($<string>$, $<string>1); }  | INTEGER { sprintf($<string>$,"%d",$<int_val>1); } ;
tableelement : ID OPENBRACKET tablesize CLOSEBRACKET;
champenreg: ID DOT ID ;
expressionLG: OPENPARENTHESIS expressionLG CLOSEPARENTHESIS | expressionLG AND expressionLG | expressionLG OR expressionLG | NON expressionLG | element ;
element : ID | BOOLEAN | tableelement | champenreg | expressionAR EQUAL expressionAR | expressionAR NONEQUAL expressionAR | expressionAR INFERIOR expressionAR | expressionAR INFERIOREQUAL expressionAR | expressionAR SUPERIOR expressionAR | expressionAR SUPERIOREQUAL expressionAR | expressionLG EQUAL expressionLG | expressionLG NONEQUAL expressionLG;
// affectation : ID ASSIGNMENT expression | type ID ASSIGNMENT expression;
affectation : ID ASSIGNMENT expressionAR SEMICOLON{ 
    if(get_id(Table_sym,$1)!=NULL){
        strcpy( tab_quad[taille].op,":=");
        strcpy(tab_quad[taille].opr1,$<string>3);
        strcpy( tab_quad[taille].opr2,"");
        strcpy( tab_quad[taille].res,$1);
        taille++;
    }else{
        printf("Variable non declaré :%s\n",$1);
        YYERROR;
    }
}| type ID ASSIGNMENT expressionAR SEMICOLON{
    if(get_id(Table_sym,$2)==NULL){
        insertColumn(Table_sym,$<string>1,$2,"",1); 
        strcpy( tab_quad[taille].op,":=");
        strcpy(tab_quad[taille].opr1,$<string>4);
        strcpy( tab_quad[taille].opr2,"");
        strcpy( tab_quad[taille].res,$2);
        taille++;
    }else{
        printf("Variable deja declaré :%s\n",$2);
        YYERROR;
    }
};
%%



int main(int argc, char **argv) {
    Table_sym = insertLigne(&Table_sym ,1);
    yyin = fopen(argv[1], "r");
    yyout = fopen("Output.txt", "r+");
    taille=0;
    int value = yyparse();

    // Column *col = Table_sym->Columns;
    // while(col!=NULL){
    //     printf("%s  :   %s\n",col->nameToken,col->typeToken);
    //     col=col->suivC;
    // }
    int i =0;
    for(i=0 ; i<taille ; i++){
        printf("%d-(%s,%s,%s,%s)\n",i+1,tab_quad[i].op,tab_quad[i].opr1,tab_quad[i].opr2,tab_quad[i].res);
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





