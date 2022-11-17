//Karla Alexsandra de Souza Joriatti E Larissa Regina Bertling

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct reg celula;
struct reg{
	float dado;
	celula * prox, *ant;
};

void imprime_serie(celula *l);
celula * insere_fim(celula *l, float valor);
celula * remove_valor(celula *l, float valor);
celula * atualiza(celula *l, float alvo, float valor);


void imprime_serie(celula *l){
	celula *p;
	p = l;

    if(l == NULL)
    {
        printf("\n\nERRO. NAO EXISTE SERIE CADASTRADA\n\n");
    }
    else
    {
        printf("\n\n_______________\n\n");

        while(p!= NULL){
            printf("|   %.4f   |\n", p->dado);
            p = p->prox;
        }

        printf("_______________\n\n");
    }

}
celula * insere_fim(celula *l, float valor){
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

celula * remove_valor(celula *l, float valor){
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

celula * atualiza(celula *l, float alvo, float valor){
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
