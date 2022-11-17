//exame quest�o 2

#include <stdio.h>
#include <stdlib.h>

typedef struct reg celula;
struct reg{
	int dado;
	celula * prox;
};

celula * mediana(celula * l){
    celula *p;
    int cont = 0, posi;
    float mediana;
    p = l;

    while (p != NULL){
        cont++;
        p = p->prox;
    }

    p = l;

    if (cont%2 == 0){
        posi = cont/2;
        for(int i = 0; i<cont; i ++){
            p = p->prox;
        }

        mediana = (p->dado + p->prox->dado)/2;
        printf("A mediana é: %.2f", mediana);

    }else{
        posi = cont/2;
        for(int i = 0; i<cont+1; i ++){
            p = p->prox;
        }
        mediana = p->dado;
        printf("A mediana é: %.2f", mediana);
    }

    return p;
}
