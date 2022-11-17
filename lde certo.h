#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct reg celula;
struct reg{
	int dado;
	celula * prox, *ant;
};

celula * incializa();
void imprime_lista(celula *l);
celula * insere_inicio(celula *l, int valor);
celula * insere_fim(celula *l, int valor);
celula * insere_ordenado(celula *l, int valor);
celula * busca_exclui(celula *l, int valor);
celula * atualiza(celula *l, int alvo, int valor);
void libera_lista(celula *l);

void imprime_lista(celula *l){
	celula *p;
	p = l;

    printf("\n\n");

	while(p!= NULL){
		printf(" %d ->", p->dado);
		p = p->prox;
	}

    printf("\n\n");
}

celula * insere_inicio(celula *l, int valor){
    celula *p;
    p = (celula *)malloc(sizeof(celula));
    p->dado = valor;
    p->ant = NULL;
    p->prox = l;

    if(p->prox != NULL)
        p->prox->ant = p;

    return p;
}

celula * insere_fim(celula *l, int valor){
    celula *novo, *p;
    p = l;
    novo = (celula *)malloc(sizeof(celula));
    novo -> dado = valor;
    novo -> prox = NULL;

    if(p != NULL)
    {
        while (p->prox != NULL)
            p = p->prox;
        p->prox = novo;
        novo->ant = p;
    }
    else
        l = novo;
    return l;
}

celula * insere_ordenado(celula *l, int valor){
    celula *novo, *p, *ant;
    p = l;
    ant = NULL;
    novo = (celula *)malloc(sizeof(celula));
    novo->dado = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    while (p != NULL && p->dado < novo->dado)
    {
        ant = p;
        p = p->prox;
    }

    if(ant == NULL)
        l = insere_inicio(l, valor);
    else
    {   if(p!= NULL)
            p->ant = novo;

        novo->prox = p;
        novo->ant = ant;
        ant->prox = novo;
    }
    
    return l;
}

celula * busca_exclui(celula *l, int valor){
    celula *p = l;

    while (p != NULL && p->dado != valor)
        p = p->prox;

    if (p == NULL)
    {
        printf("\n\nValor não encontrado\n\n");
        return l;
    }
    else
    {   
        if(p->ant == NULL)
            l = p->prox;
        else
        {
            if(p->prox != NULL)
                p->prox->ant = p->ant;

            p->ant->prox = p->prox;
        }

        free(p); 
    }

   return l; 
}

celula * atualiza(celula *l, int alvo, int valor){
    celula *p;
    p = l;

    while(p != NULL && p->dado != alvo)
        p = p->prox;
   
    if(p == NULL)
        printf("\n\nValor não encontrado\n\n");
    else
        p->dado = valor;

    return l;
}

void libera_lista(celula *l){
	celula *p, *a;
	p = l;

	while(p!= NULL){
        a = p;
		p = p->prox;
        free(a);
	}
}