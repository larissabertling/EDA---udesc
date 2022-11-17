#include<stdlib.h>
#include<stdio.h>

typedef struct reg nodo;
struct reg{
    int chave;
    struct dado contador;
    nodo *proximo;
};

nodo * insere_ini(nodo *lista, int x);
nodo * insere_fim(nodo *lista, int x);
nodo * insere_ordenado(nodo *lista, int x);
nodo * remove(nodo *lista, int alvo);



int main(int agrc, char *argv[]){
    nodo *lista;
    int alvo, x;
    char menu(){
	char opcao;
    while(1){       
        printf("\n--MENU--\n");
        printf("1 . Inserir Inicio\n");
        printf("2 . Inserir Fim\n");
        printf("3 . Inserir Ordenado\n");
        printf("4 . Remover\n");
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
            	printf("Digite o valor\n");
                scanf("%d", &x);
                lista = insere_ini(lista,x);
                break;
                
            case '2':
				printf("Digite o valor\n");
                scanf("%d", &x);
                lista = insere_fim(lista,x);
                break;
                
            case '3':
				printf("Digite o valor\n");
                scanf("%d", &x);
                fflush(stdin);
                lista = insere_ordenado(lista, x);
                break;
                
            case '4':
            	printf("Digite o valor\n");
                scanf("%d", &alvo);
             	lista= remove(lista);
   				printf("Retirado: %3d\n\n", lista->alvo);
   				
            case '0':
                return 0;
                break;
        }
    }
    return 0;
}



nodo * insere_ini(nodo *l, int x){
nodo * n;
	n= (nodo *) malloc (sizeof(nodo));
	n->dado=x;
	n->ant=NULL;
	n->prox=l;
	
	if(n->prox!=NULL) n->prox->ant=n;
	
return(n);
} 

nodo * insere_fim(nodo *l, int x){
nodo *n;
nodo *p;
	p=l;
	n= (nodo *)malloc (sizeof(nodo));
	n->dado=x;
	n->prox=NULL;
	
	if(p!=NULL){
		while(p->prox!=NULL){
			p=p->prox;
	}
	p->prox=n;
	n->ant = p;
}

	else{ 
		l=n;
	}
return(l);
}


nodo * insere_ordenado(nodo *l, int x){
nodo *n;
nodo *p;
nodo *a;
	p=l;a=NULL;
	n=(nodo*)malloc(sizeof(nodo));
	n->dado=x;
	n->prox=NULL; n->ant=NULL;

	while(p!=NULL && p->dado < n->dado){
		a=p;
		p=p->prox;
	}

	if (a==NULL){
		l=insere_inicio(l,x);
	}
	else{
		n->prox=p;
		p->ant=n;
		a->prox=n;
	}
return(l);
}


nodo * remove(nodo *l, int alvo){
nodo *p=l;

	while(p!=NULL && p->dado != alvo){
		p=p->prox;
	}

	if(p == NULL){
		printf("valor nao encontrado!\n");
	return l;
	}

	else{
		if(p->ant==NULL){
			l=p->prox;
	}

	else{
		p->ant->prox = p->prox;
		p->prox->ant = p->ant;
	}
	free(p);
	}
return l;
}


