#include <stdio.h> 
#include <stdlib.h>

//LISTA DE REVIS�O PARA A PROVA

//QUEST�O 1

struct lista {
 struct no *cabeca;
 struct no *ultimo;
};
struct no {
 struct no *prox;
 int dado;
};
typedef struct lista TipoLista;
typedef struct no Apontador;


void Troca(TipoLista *L, Apondador *P)
{
 struct no *prox = P->prox;
 if(prox == NULL) { return; } /* imposs�vel trocar posi��es. */

 
 P->prox = prox->prox;
 prox->prox = P;

}
 
 
//QUEST�O 2

struct lista {
 struct no *cabeca;
 struct no *ultimo;
};
struct no {
 struct no *ante;
 struct no *prox;
 int dado;
};
typedef struct lista TipoLista;
typedef struct no Apontador;
/* void Troca(struct lista *L, struct no *P) ou */
void Troca(TipoLista *L, Apondador *P)
{
 struct no *ante;
 struct no *prox = P->prox;
 if(prox == NULL) { return; } /* imposs�vel trocar posi��es. */
 ante = L->cabeca;
 while(ante->prox != P) {
 ante = ante->prox;
 }
 /* ante � o n� anterior ao n� P */
 ante->prox = prox;
 P->prox = prox->prox;
 prox->prox = P;
 if(L->ultimo == prox) { L->ultimo = ante;
}
 
 
 

//QUEST�O 5
nodo*concatena(nodo * lista1, nodo * lista2){
	if(lista1==NULL) return lista2;
	if(lista2==NULL) return lista1;
	
	nodo *p=lista1;
	
	while(p->prox!=NULL) p=p->prox;
	p->prox=lista2;
	
	return (lista1);
}

//QUEST�O 6

nodo * moveMenor (nodo*lista){
	nodo * p = lista;
	nodo * menor = p;
	while(p!=NULL){
		if(p->valor<menor->valor) menor = p;
		p= p->prox;
	}
	return(trocaNos(lista,lista,menor));
}


//QUEST�O 7

nodo * ordena(nodo * lista){
	nodo * p;
	lista = moveMenor(lista);
	p=lista;
	
	while(p->prox!=NULL){
		p->prox = moveMenor(p->prox);
		p=p->prox;
		
	}
	return(lista);
}
