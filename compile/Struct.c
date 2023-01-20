#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Column
{
    char typeToken[256];
    char nameToken[256];
    char valeurToken[256];
    int numColumn;
    struct Column *suivC; 
}Column;



typedef struct Ligne
{
    int numLigne;
    Column *Columns;
    struct Ligne *suivL; 
}Ligne;


Column* allocateColumn(){
    Column *col = (Column*)malloc(sizeof(Column));

    col->numColumn=1;
    col->suivC=NULL;

    return col;
} 


Ligne* allocateLigne(){
    Ligne *li = (Ligne*)malloc(sizeof(Ligne));

    li->Columns=NULL;
    li->numLigne=1;
    li->suivL=NULL;


    return li;
}

    Ligne* insertLigne(Ligne **Lign , int numLigne){
        Ligne *li ;
        Ligne *newLigne;
        if(*Lign==NULL){
            newLigne = allocateLigne();
            return newLigne;
        }else{
            li = *Lign;
            while (li->suivL!=NULL)
            {
                li = li->suivL;
            }
            newLigne = allocateLigne();
            li->suivL=newLigne;
            newLigne->numLigne=numLigne;
            return newLigne;    
        }
    }



    void insertColumn(Ligne *Lign,char* typeToken,char* nameToken,char* valeurToken,int numColumn){
        Column *col,*c = Lign->Columns;
        if(c==NULL){
            col= allocateColumn(); 
            strcpy(col->typeToken,typeToken);
            strcpy(col->nameToken,nameToken);
            strcpy(col->valeurToken,valeurToken);
            col->numColumn=numColumn;
            Lign->Columns=col;
        }else{
            while (c->suivC!=NULL)
            {
                c=c->suivC;
            }
            col= allocateColumn(); 
            strcpy( col->typeToken,typeToken);
            strcpy(col->nameToken,nameToken);
            strcpy(  col->valeurToken,valeurToken);
            col->numColumn=numColumn;
            c->suivC=col;
        }
    }


    Column* get_id(Ligne *Lign , char id[]){
        Column *col = Lign->Columns;
        int stop = 0;
        while (stop==0 && col!=NULL){
            if( strcmp(col->nameToken,id)==0){
                stop = 1;
            }
            else{
                col=col->suivC;
            }
        }
        return col;      
    }
