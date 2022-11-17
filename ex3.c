//Larissa Regina Bertling

//exame questão 3


#include <stdio.h>
#include <stdlib.h>

typedef struct reg nodo;
struct reg{
    int peso;
    nodo *esq, *dir;
};

typedef struct reg arvore;//raiz da arvore

int ramoMaisPesado(arvore *r);
int max(int a, int b);

int ramoMaisPesado(arvore *r){
    nodo *d, *e, *p;

    e = r->esq;
    d = r->dir;

    if (r == NULL){
        return 0;
    }
    else if (e == NULL && d == NULL){
        return r->peso;
    }
    else if(e == NULL && d != NULL){
        return r->peso + ramoMaisPesado(d);
    }
    else if(d == NULL && e != NULL){
        return r->peso + ramoMaisPesado(e);
    }
    else{
        return max(e->peso + ramoMaisPesado(e->esq) + ramoMaisPesado(e->dir), d->peso + ramoMaisPesado(d->esq)+ramoMaisPesado(d->dir));
    }
}

int max(int a, int b){
    if(a > b)
        return a;
    else if(a < b)
        return b;
    else
        return -1;
}
