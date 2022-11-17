#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
//#define N 3 //definindo uma constante N para usar no tamanho do vetor

struct reg{
	int cod;
	char nome[60];
	float salario;
};

typedef struct reg funcionario;

void mostraMenu();
void imprimeTodos(funcionario *v,int N);
void imprimePos(funcionario *v, int pos);
int maiorSalario(funcionario *v,int N);
int menorSalario(funcionario *v,int N);
float mediaSalarios(funcionario *v,int N);
funcionario * deletar(funcionario *v, int N);
funcionario * incluir(funcionario *v, int N);


int main(){
	setlocale(LC_ALL, "Portuguese");
	funcionario *vetor;
	int op,i,tmp,N,cod;
	do{
		mostraMenu();
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("digite a quantidade de funcionarios que deseja cadastrar: ");
				scanf("%d",&N);
				
				  vetor = (funcionario*)malloc(N*sizeof(funcionario));

				for(i=0;i<N;i++){
					system("cls"); //isso vai limpar a tela
					printf("Pos %i:\n",i);
					printf("Digite o c?digo:\n");
					scanf("%d",&vetor[i].cod);
					printf("Digite o nome:\n");
					scanf("%s",&vetor[i].nome);
					printf("Digite o sal?rio:\n");
					scanf("%f",&vetor[i].salario);
				}
				break;
			case 2:
				system("cls"); //limpa a tela
				imprimeTodos(vetor,N);
				system("pause"); //mensagem que espera o "enter"
				break;
			case 3:
				printf("Qual posi??o quer imprimir?\n");
				scanf("%d",&tmp);
				imprimePos(vetor,tmp);
				system("pause");
				break;
			case 4:
				printf("O maior salario esta na posi??o %d\n",maiorSalario(vetor,N));  
				system("pause");
				break;
			case 5:
				printf("O menor salario esta na posi??o %d\n",menorSalario(vetor,N));  
				system("pause");
				break;
			case 6:
				printf("A m?dia dos sal?rios ? %.2f\n",mediaSalarios(vetor,N));  
				system("pause");
				break;
			case 7:
				vetor=deletar(vetor,N);
				system("pause");
				N=N-1;
				break;
			case 8:
				vetor=incluir(vetor,N);
				system("pause");
				N=N+1;
				break;
			case 0:
				printf("Obrigado por usar o nosso programa!\n");  
				break;
			default:
				system("cls");
				printf("OP??O N?O CADASTRADA!\n");  
				system("pause");
				break;

		}
	}while(op!=0);
}

void mostraMenu(){
	system("cls");//limpa a tela
	printf("|      CADASTRO DE FUNCION?RIOS      |\n");
	printf("|____________________________________|\n");
	printf("|           MENU DE OP??ES           |\n");
	printf("|------------------------------------|\n");
	printf("| 1 - INSERIR VALORES NO VETOR       |\n");
	printf("| 2 - IMPRIMIR TODOS OS FUNCION?RIOS |\n");
	printf("| 3 - IMPRIMIR FUNCION?RIO DA POSI??O|\n");	
	printf("| 4 - RETORNAR POS. DO MAIOR SAL?RIO |\n");
	printf("| 5 - RETORNAR POS. DO MENOR SAL?RIO |\n");
	printf("| 6 - RETORNAR A M?DIA DOS SAL?RIOS  |\n");
	printf("| 7 - REMOVER FUNCIONARIO            |\n");
	printf("| 8 - INCLUIR FUNCIONARIO            |\n");
	printf("| 0 - SAIR                           |\n");
	printf("|------------------------------------|\n");
}

void imprimeTodos(funcionario *v, int N){
	int i;
	for(i=0;i<N;i++){
		printf("Pos %i:\n",i);
		printf("C?digo: %d\n",v[i].cod);
		printf("Nome: %s\n",v[i].nome);
		printf("Sal?rio: %.2f\n",v[i].salario); //%.2f fara imprimir duas casas decimais depois da virgula
	}
}

void imprimePos(funcionario *v, int pos){
	printf("Pos %i:\n",pos);
	printf("C?digo: %d\n",v[pos].cod);
	printf("Nome: %s\n",v[pos].nome);
	printf("Sal?rio: %.2f\n",v[pos].salario); 
}

int maiorSalario(funcionario *v, int N){
	int i,maior;
	maior=0;
	for(i=0;i<N;i++){
		if(v[i].salario>v[maior].salario){
			maior=i;
		}
	}
	return(maior);
}

int menorSalario(funcionario *v,int N){
	int i,menor;
	menor=0;
	for(i=0;i<N;i++){
		if(v[i].salario<v[menor].salario){
			menor=i;
		}
	}
	return(menor);
}

float mediaSalarios(funcionario *v,int N){
	int i;
	float soma;
	soma=0.0;
	for(i=0;i<N;i++){
		soma+=v[i].salario;
	}
	return(soma/N);
}

funcionario * deletar(funcionario *v, int N){
    printf("Qual a posi??o a excluir?");
    int pos;
    scanf("%d", &pos);
    if (pos >= 0 && pos < N){ //se a posi??o ? valida
        int i;
        //andar todos um para tr?s a partir da posi??o a remover
        for (i = pos; i < N - 1; ++i){ 
            v[i] = v[i + 1];
        }
        v = (funcionario *)realloc(v, (N-1) * sizeof(funcionario)); 
    }
    return (v);
}


funcionario * incluir(funcionario *v, int N){
		v = (funcionario *) realloc(v, (N+1) * sizeof(funcionario)); 

    	printf("Pos %i:\n",N);
		printf("Digite o c?digo:\n");
		scanf("%d",&v[N].cod);
		printf("Digite o nome:\n");
		scanf("%s",&v[N].nome);
		printf("Digite o sal?rio:\n");
		scanf("%f",&v[N].salario);
		return(v);
		
}

