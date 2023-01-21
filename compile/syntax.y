%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Struct.c"
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
        char op[10];
        char opr1[10];
        char opr2[10];
        char res[10];
    }quad;
    int sauv_if_fin = 0;
    int sauv_else =0;
    int sauv_else_fin=0;
    int sauv_fin_while=0;
    int  sauv_for_test=0;
    int sauv_for_init_id=0;
    quad tab_quad[1000];
    int taille;
    char pas[20];
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
%token  DOT
%token <char_val> COMMA
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
code: code code | affectation | commentaire  | tabledeclaration | structdeclaration   | declaration | statements  | expression  | read | write  ;
declaration: type ID SEMICOLON { 
    if(get_id(Table_sym,$2)!=NULL){
        printf("Variable deja declarer : %s \n ",$2);
        YYERROR;
    }else{
        insertColumn(Table_sym,$<string>1,$2,"",1); 
    }
    };
type: INTEGERDECLARE  | REALDECLARE  | CHARDECLARE  | STRINGDECLARE  | BOOLEENDECLARE | structure ;
structdeclaration: STRUCTDECLARE structure OPENHOOK declarations CLOSEHOOK ;
declarations : declaration | declaration declarations;
structure: ID ;
tabledeclaration: type OPENBRACKET tablesize CLOSEBRACKET ID SEMICOLON;
tablesize: ID | expressionAR | INTEGER;
statements : if_stm | if_else_stm | for_stm | while_stm ;
if_stm: B1  OPENHOOK code CLOSEHOOK{
    sprintf(tab_quad[sauv_if_fin].opr1,"%d",taille+1);
};
B1:IF  expressionLG{
    sauv_if_fin = taille-1;
};
if_else_stm: A1 ELSE OPENHOOK code CLOSEHOOK {
    sprintf(tab_quad[sauv_else_fin].opr1,"%d",taille+1);
};
A1: A2 OPENHOOK code CLOSEHOOK {
    sprintf(tab_quad[sauv_else].opr1,"%d",taille+2); 
    strcpy( tab_quad[taille].op,"BR");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,"");
    strcpy( tab_quad[taille].res,"");
    sauv_else_fin = taille;
    taille++;
};
A2: IF OPENPARENTHESIS expressionLG CLOSEPARENTHESIS {
    sauv_else=taille-1;
};
for_stm: R1 OPENHOOK code CLOSEHOOK{
    char res[10];
    strcpy( tab_quad[taille].op,"+");
    strcpy( tab_quad[taille].opr1,tab_quad[sauv_for_init_id].res);
    strcpy( tab_quad[taille].opr2,pas);
    sprintf(res, "R%d", ri);
    strcpy( tab_quad[taille].res,res);
    taille++;
    ri++;
    strcpy( tab_quad[taille].op,":=");
    sprintf(tab_quad[taille].opr1,"%s",res);
    strcpy( tab_quad[taille].opr2,"");
    strcpy( tab_quad[taille].res,tab_quad[sauv_for_init_id].res);
    taille++;
    strcpy( tab_quad[taille].op,"BR");
    sprintf( tab_quad[taille].opr1,"%d", sauv_for_test);
    strcpy( tab_quad[taille].opr2,"");
    strcpy( tab_quad[taille].res,"");
    taille++;
    sprintf(tab_quad[sauv_for_test].opr1,"%d",taille+1);
};
R1:R2 SEMICOLON INTEGER{
    sprintf(pas,"%d",$<int_val>3);
};
R2:R3 SEMICOLON expressionLG{
    sauv_for_test = taille-1;
};
R3:LOOPF ID ASSIGNMENT expressionAR{
    if(get_id(Table_sym,$<string>2)!=NULL){
        strcpy( tab_quad[taille].op,":=");
        strcpy(tab_quad[taille].opr1,$<string>4);
        strcpy( tab_quad[taille].opr2,"");
        strcpy( tab_quad[taille].res,$<string>2);
        sauv_for_init_id =taille;
        taille++;
    }else{
        printf("variable non declaré : %s\n",$<string>2);
        YYERROR;
    }
};


while_stm: C1 OPENHOOK code CLOSEHOOK{
    strcpy( tab_quad[taille].op,"BR");
    sprintf( tab_quad[taille].opr1,"%d", sauv_fin_while+1);
    strcpy( tab_quad[taille].opr2,"");
    strcpy( tab_quad[taille].res,"");
    taille++;
    sprintf(tab_quad[sauv_fin_while].opr1,"%d",taille+1);

};
C1:LOOPW OPENPARENTHESIS expressionLG CLOSEPARENTHESIS{
    sauv_fin_while=taille-1;   
};



expression : expressionAR | expressionLG;
read: READ OPENPARENTHESIS ID CLOSEPARENTHESIS SEMICOLON{
    if(get_id(Table_sym,$<string>3)!=NULL){
        strcpy( tab_quad[taille].op,"INPUT");
        strcpy( tab_quad[taille].opr1,$<string>3);
        strcpy( tab_quad[taille].opr2,"");
        strcpy( tab_quad[taille].res,"");
        taille++;
    }else{
        printf("variable non declaré : %s\n",$<string>3);
        YYERROR;
    }
};
write: WRITE OPENPARENTHESIS expressionAR CLOSEPARENTHESIS SEMICOLON{
    strcpy( tab_quad[taille].op,"OUTPUT");
    strcpy( tab_quad[taille].opr1,$<string>3);
    strcpy( tab_quad[taille].opr2,"");
    strcpy( tab_quad[taille].res,"");
    taille++;
};
commentaire: INLINECOMMENT ;
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
item: ID { 
    if(get_id(Table_sym,$<string>1)!=NULL){
    strcpy($<string>$, $<string>1); 
    }else{
        printf("variable non declarer : %s\n",$<string>1);
        YYERROR;
    }
        }  | INTEGER { sprintf($<string>$,"%d",$<int_val>1); } ;
tableelement : ID OPENBRACKET tablesize CLOSEBRACKET;
champenreg: ID DOT ID ;
expressionLG: OPENPARENTHESIS expressionLG CLOSEPARENTHESIS { strcpy( $<string>$,$<string>2);}  | expressionLG AND expressionLG | expressionLG OR expressionLG | NON expressionLG | element ;
element : ID | BOOLEAN | tableelement | champenreg | expressionAR EQUAL expressionAR{
    strcpy( tab_quad[taille].op,"BNE");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,$<string>1);
    strcpy( tab_quad[taille].res,$<string>3);
    taille++;
} | expressionAR NONEQUAL expressionAR {
    strcpy( tab_quad[taille].op,"BE");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,$<string>1);
    strcpy( tab_quad[taille].res,$<string>3);
    taille++;
}| expressionAR INFERIOR expressionAR{
     strcpy( tab_quad[taille].op,"BGE");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,$<string>1);
    strcpy( tab_quad[taille].res,$<string>3);
    taille++;
} | expressionAR INFERIOREQUAL expressionAR {
    strcpy( tab_quad[taille].op,"BG");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,$<string>1);
    strcpy( tab_quad[taille].res,$<string>3);
    taille++;
} | expressionAR SUPERIOR expressionAR{
     strcpy( tab_quad[taille].op,"BLE");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,$<string>1);
    strcpy( tab_quad[taille].res,$<string>3);
    taille++;
} | expressionAR SUPERIOREQUAL expressionAR {
     strcpy( tab_quad[taille].op,"BL");
    strcpy( tab_quad[taille].opr1,"");
    strcpy( tab_quad[taille].opr2,$<string>1);
    strcpy( tab_quad[taille].res,$<string>3);
    taille++;
};
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
    int i =0;
    for(i=0 ; i<taille ; i++){
        fprintf(yyout,"%d-(%s,%s,%s,%s)\n",i+1,tab_quad[i].op,tab_quad[i].opr1,tab_quad[i].opr2,tab_quad[i].res);
    }


    if(value==1){
        printf("\nErreur syntaxique dans la ligne :%d  et la colonne : %d\n",yylineno,currentColumn);
    }else{
        printf("Complation success\n");
    }
    fclose(yyin);
    fclose(yyout);
    return 0;
}





