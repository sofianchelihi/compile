Les commandes pour la compilation:
> bison -d syntax.y
> flex compile.l
> gcc -o output syntax.tab.c scanner.c -lfl -lm 


Pour l'execution:
> ./output input