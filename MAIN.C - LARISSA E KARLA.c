//Karla Alexsandra de Souza Joriatti E Larissa Regina Bertling

#include "script.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int op = -1, n;
    float valor, alvo;
    celula *l;
    l = NULL;

    while (op != 0)
    {
        printf("\n__________________________________________\n\n");
        printf("|----------------Operações:-----------------|\n");
        printf("|1------Cadastrar uma série de dados-----|\n");
        printf("|2-----------Imprimir a série------------|\n");
        printf("|3----------Inserir novo valor-----------|\n");
        printf("|4-----------Remover um valor------------|\n");
        printf("|5---Trocar um valor da série por outro--|\n");
        printf("|----------------------------------------|\n");
        printf("|-------   Entre com 0 para sair   ------|\n");
        printf("__________________________________________\n");


        scanf("%d", &op);


        switch (op)
        {
        case 1:
            
            printf("Quantos valores deseja cadastrar? ");
            scanf("%d", &n);

            for(int i = 0; i < n; i++){
                printf("%dÂº: ", i+1);
                scanf("%f", &valor);

                l = insere_fim(l, valor);
            }

            break;

        case 2:

            imprime_serie(l);

            break;

        case 3:

            printf("Digite o valor a ser inserido: ");
            scanf("%f", &valor);

            l = insere_fim(l, valor);

            break;

        case 4:

            printf("Digite o valor a ser removido: ");
            scanf("%f", &valor);

            l = remove_valor(l, valor);

            break;

        case 5:

            printf("Valor a ser alterado: ");
            scanf("%f", &alvo);
            printf("Novo valor: ");
            scanf("%f", &valor);

            l = atualiza(l, alvo, valor);

            break;

        default:
            break;
        }
    }

    // libera_lista(l);
    printf("\n\nO programa foi encerrado e a lista foi esvaziada!\n\n");

    return 0;
}
