#include<stdlib.h>
#include<stdio.h>
#include "lista.h"

typedef struct reg nodo;
struct reg{
    int chave;
    struct dado contador;
    nodo *proximo;
};

char menu();
void imprime_lista(nodo *lista);
int conta_nos(nodo *lista);
int profundidade(nodo *lista, int alvo);
nodo *insere_inicio(nodo *lista, int alvo);
nodo *insere_ordenado(nodo *lista, int alvo);



int main(int agrc, char *argv[]){
    nodo *lista;
    int alvo;
    char menu(){
	char opcao;
    while(1){       
        printf("\n--MENU--\n");
        printf("1 . Imprimir lista;\n");
        printf("3 . Contar celulas;\n");
        printf("4 . Profundidade da celula;\n");
        printf("4 . Valor do inicio da lista;\n");
        printf("5 . Ordenar lista;\n");
        printf("0 . Sair.\n");

        scanf("%c", &opcao);
        fflush(stdin);
            return opcao;
        }
        printf("\n--ERROR--\n");
    }
    while (1){
        switch (menu()){
            case '1':
                imprimeLista(lista);
                break;
            case '2':
                printf("%d", conta_nos(lista));
                break;
            case '3':
                printf("Valor procurado: ");
                scanf("%d", &alvo);
                fflush(stdin);
                printf("%d", profundidade(lista, alvo));
                break;
            case '4':
                printf("Digite o valor\n");
                scanf("%d", &alvo);
                lista = insere_ini(lista,alvo);
                break;
            case '5':
                printf("Digite o valor\n");
                scanf("%d", &alvo);
                fflush(stdin);
                lista = insere_ordenado(lista, alvo);
                break;
            case '0':
                return 0;
                break;
        }
    }
    return 0;
}


void imprime_lista(nodo *lista){
    nodo *p;
    p=lista;
    while(p!=NULL){
        printf("%d\n",p->dado);
        p=p->proximo;
    }
    return;
}

int conta_nos(nodo *lista){
    int contador;
    nodo *p;
    p=lista;
    while(p!=NULL){
        contador++;
        p=p->proximo;
    }
    return (contador);
}

int profundidade(nodo *lista, int alvo){
    int contador=0;
    nodo *p=lista;
    while (p!=NULL){
    if (p->chave==alvo)
    break;
        contador++;
        p=p->proximo;   
    }
    if(p==NULL){
        return -1;
    }else{
        return (contador);
    }
}

nodo * insere_inicio(nodo *lista, int alvo){
    nodo *novo;
    novo = (nodo*)malloc(sizeof(nodo));
    novo->dado = alvo;
    novo->proximo =lista;
    return (novo);
}

nodo * insere_ordenado(nodo *lista, int alvo){
    nodo *novo;
    nodo *p;
    nodo *ant=NULL;
    p=lista;
    novo =(nodo*)malloc(sizeof(nodo));
    novo->dado=alvo;
    novo->proximo=NULL;
    while(p!=NULL && p->dado < novo->dado){
        ant=p;
        p=p->proximo;
}
    if (ant==NULL){
        novo->proximo=p;
        lista=novo;
    }else{
        novo->proximo=ant->proximo;
        ant->proximo=novo;
}
    return(lista);
}

