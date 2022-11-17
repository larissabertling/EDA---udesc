#include "ldecerto.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){

    int op = -1, valor,alvo;
    celula *l;
    l = NULL;

    while (op != 0)
    {

        printf("\n---------------Opções:----------------\n");
        printf("1-----------Imprimir lista------------\n");
        printf("2----------Remover um valor-----------\n");
        printf("3------Colocar um valor no final------\n");
        printf("4------Colocar um valor no inicio-----\n");
        printf("5--Colocar um valor de forma ordenada-\n");
        printf("6--Trocar um valor da lista por outro-\n");
        printf("--------------------------------------\n");
        printf("------   Entre com 0 para sair   -----\n\n");



        scanf("%d", &op);


        switch (op)
        {
        case 1:
            imprime_lista(l);
            break;

        case 2:
            printf("Entre com o valor que deseja remover: ");
            scanf("%d", &valor);

            l = busca_exclui(l, valor);
            break;

        case 3:
            printf("Entre com o valor a ser inserido ao final da lista: ");
            scanf("%d", &valor);

            l = insere_fim(l, valor);
            break;

        case 4:
            printf("Entre com o valor a ser inserido ao inicio da lista: ");
            scanf("%d", &valor);

            l = insere_inicio(l, valor);
            break;

        case 5:
            printf("Entre com o valor para encaixá-lo de forma ordenada à lista: ");
            scanf("%d", &valor);

            l = insere_ordenado(l, valor);
            break;

        case 6:
            printf("Entre com o valor a ser substituído: ");
            scanf("%d", &alvo);
            printf("Entre com o novo valor: ");
            scanf("%d", &valor);

            l = atualiza(l, alvo, valor);
            break;

        default:
            break;
        }
    }

    libera_lista(l);
    printf("\n\nO programa foi encerrado e a lista foi esvaziada!\n\n");

    return 0;
}
