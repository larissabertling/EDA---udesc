#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

deque * addFrente(deque *r, int a){
    Queue *p;
    p = malloc(sizeof(Queue));
    p->valor = a;
    p->ant = NULL;

    if(r->frente == NULL){//deque vazio
        p->prox = NULL;
        r->frente = p;
    }
    else{
        p->prox = r->frente;
        r->frente->ant = p;
        r->frente = p;
    }

    return r;
}

deque * addAtras(deque *r, int a){
    Queue *p;
    p = malloc(sizeof(Queue));
    p->valor = a;
    p->prox = NULL;

    if(r->tras == NULL){//deque vazio
        p->ant = NULL;
        r->tras = p;
    }
    else{
        p->ant = r->tras;
        r->tras->prox = p;
        r->tras = p;
    }

    return r;
}

deque * delFrente(deque *r){
    if(r->frente == NULL){
        printf("Deque vazio!\n");
        return r;
    }
    
    Queue *p;
    p = r->frente;

    p->prox->ant = NULL;
    r->frente = p->prox;

    free(p);

    return r;
}

deque * delAtras(deque *r){
    if(r->tras == NULL){
        printf("Deque vazio!\n");
        return r;
    }
    
    Queue *p;
    p = r->tras;

    p->ant->prox = NULL;
    r->tras = p->ant;

    free(p);

    return r;
}
