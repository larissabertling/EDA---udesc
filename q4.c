#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct reg aluno;
struct reg{
	int matricula;
    char nome[50];
    float * notas;
	aluno * prox, *ant;
};

float calcula_mediana(aluno *l);
void alunos_mediana(aluno *l);

float calcula_mediana(aluno *l){
    float mediana, soma = 0;
    int i = 0, cont = 0;

    aluno *p = l;

    if(l == NULL){
        printf("\n\nNenhum aluno foi cadastrado!\n\n");
    }
    else{
        while (p != NULL){
            while(p->notas[i] != NULL){
                soma = soma + p->notas[i];
                i++;
                cont++;
            }

            p = p->prox;
            i = 0;
        }

        mediana = cont / 2;
    }
    return media;
}

void alunos_mediana(aluno *l){
    aluno * p = l;
    float mediana = calcula_mediana(l), soma = 0;
    int cont = 0, i = 0;

    if(l == NULL){
        printf("\n\nNenhum aluno foi cadastrado!");
    }else{
        while (p != NULL){
            while(p->notas[i] != NULL){
                soma = soma + p->notas[i];
                i++;
                cont++;
            }
            soma = soma / cont;

            if(soma < mediana){
            	printf("\nAluno abaixo da mediana");
                printf("\n\nMatricula: ", p->matricula);
                printf("\n\nNome: %s\n",  p->nome);
                printf("\n\n Média: %f",  soma);
            }else
            soma = 0;
            p = p->prox;
            i = 0;
            
            printf("\nAluno acima da mediana");
            printf("\n\nMatricula: ", p->matricula);
            printf("\n\nNome: %s\n",  p->nome);
            printf("\n\n Média: %f",  soma);
            
        }

        mediana = cont / 2;
    }
}
