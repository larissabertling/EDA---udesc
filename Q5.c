#include<stdio.h>
#include<stdlib.h>

nodo * profundidade(arvore r){
   if (r == NULL) 
      return -1; 
   else {
      int pe = profundidade (r->esq);
      int pd = profundidade (r->dir);
      if (pe < pd) return pd + 1;
      else return pe + 1;
   }
}



