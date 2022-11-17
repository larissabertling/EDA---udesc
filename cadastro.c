#include <stdio.h>
#include <locale.h>


struct reg{
	int cod;
	char nome[100];
	float salario;
}funcionario;

typedef struct reg funcionario;

void mostraMenu();
void ler(funcionario *v[], int N);
void imprimeTodos(funcionario *v[], int N);
void imprimePos(funcionario *v[], int pos);
int maiorSalario(funcionario *v[], int N);
int menorSalario(funcionario *v[], int N);
float mediaSalarios(funcionario *v[], int N);
int incluefunc(funcionario *v[], int *N);
int removefunc(funcionario *v[], int pos, int *N);

int main(){
	setlocale(LC_ALL, "Portuguese");
  	int N=1;
	funcionario * vetor;
	int op,i,tmp, pos;
	do{
		mostraMenu();
		scanf("%d",&op);
		switch(op){
			case 1:
					printf("Digite a quantidade de funcionários que deseja cadastrar: \n");
					scanf("%d", &N);
					vetor =(funcionario *)malloc(sizeof(funcionario)*N);
					for(i=0;i<N;i++){
						system("cls"); 
						printf("Pos %i:\n",i);
						printf("Digite o código:\n");
						scanf("%d",&vetor[i].cod);
						printf("Digite o nome:\n");
						scanf("%s",&vetor[i].nome);
						printf("Digite o salário:\n");
						scanf("%f",&vetor[i].salario);
				}
				break;
			case 2:
				system("cls"); 
				imprimeTodos(vetor, N);
				system("pause"); 
				break;
			case 3:
				printf("Qual posição quer imprimir?\n");
				scanf("%d",&tmp);
				imprimePos(vetor,tmp);
				system("pause");
				break;
			case 4:
				printf("O maior salario esta na posição %d\n",maiorSalario(vetor, N));  
				system("pause");
				break;
			case 5:
				printf("O menor salario esta na posição %d\n",menorSalario(vetor, N));  
				system("pause");
				break;
			case 6:
				printf("A média dos salários é de %.2f\n",mediaSalarios(vetor, N));  
				system("pause");
				break;
				
			case 7:
				vetor= incluefunc(vetor, N);
				N+=1;
				
				break;
				
				
			case 8: 
				printf("Qual o código do funcionário que você quer remover?\n");
				scanf("%d", &tmp);
				for(i=0; i<N; i++){
					if (vetor[i].cod == tmp){
						pos = 1;
						break;
				}	
			}
			vetor= deletafunc(vetor, N, pos);
			N--;
			
			break;
			
			
			case 0:
				printf("Obrigado por usar o nosso programa!\n");  
				break;
			default:
				system("cls");
				printf("OPÇÃO NÃO CADASTRADA!\n");  
				system("pause");
				break;

		}
	}while(op!=0);
	
}
	

void mostraMenu(){
	system("cls");
	printf("|      CADASTRO DE FUNCIONÁRIOS      |\n");
	printf("|____________________________________|\n");
	printf("|           MENU DE OPÇÕES           |\n");
	printf("|------------------------------------|\n");
	printf("| 1 - INSERIR VALORES NO VETOR       |\n");
	printf("| 2 - IMPRIMIR TODOS OS FUNCIONÁRIOS |\n");
	printf("| 3 - IMPRIMIR FUNCIONÁRIO DA POSIÇÃO|\n");	
	printf("| 4 - RETORNAR POS. DO MAIOR SALÁRIO |\n");
	printf("| 5 - RETORNAR POS. DO MENOR SALÁRIO |\n");
	printf("| 6 - RETORNAR A MÉDIA DOS SALÁRIOS  |\n");
	printf("| 7 - INCLUIR FUNCIONÁRIO  |\n");
	printf("| 8 - REMOVER UM FUNCIONÁRIO  |\n");
	printf("| 0 - SAIR                           |\n");
	printf("|------------------------------------|\n");
}

void ler(funcionario v[], int N){
    int i;
    for(i=0; i<N; i++){
    printf("----- Funcionario %d -----\n", i+1);
    printf("Digite o codigo\n");
	scanf("%d",&p[i].cod);
    printf("Digite o nome\n");
    scanf("%s", p[i].nome);
    fflush(stdin);
    printf("Digite o salario\n");
    scanf("%f", &p[i].salario);
    fflush(stdin);
    }
}


void imprimeTodos(funcionario v[]){
	int i;
	for(i=0;i<N;i++){
		printf("Pos %i:\n",i);
		printf("Código: %d\n",v[i].cod);
		printf("Nome: %s\n",v[i].nome);
		printf("Sal?rio: %.2f\n",v[i].salario); 
	}
}

void imprimePos(funcionario v[], int pos){
	printf("Pos %i:\n",pos);
	printf("Código: %d\n",v[pos].cod);
	printf("Nome: %s\n",v[pos].nome);
	printf("Sal?rio: %.2f\n",v[pos].salario); 
}

int maiorSalario(funcionario v[], int N){
	int i,maior;
	maior=0;
	for(i=0;i<N;i++){
		if(v[i].salario>v[maior].salario){
			maior=i;
		}
	}
	return(maior);
}

int menorSalario(funcionario v[], int N){
	int i,menor;
	menor=0;
	for(i=0;i<N;i++){
		if(v[i].salario<v[menor].salario){
			menor=i;
		}
	}
	return(menor);
}

float mediaSalarios(funcionario v[], int N){
	int i;
	float soma;
	soma=0.0;
	for(i=0;i<N;i++){
		soma+=v[i].salario;
	}
	return(soma/N);
}

	funcionario * incluefunc(funcionario *v, int N){
	
					v=(funcionario *)realloc(v,sizeof(funcionario)*N+1));
						printf("Digite o código:\n");
						scanf("%d",&v[N].cod);
						printf("Digite o nome:\n");
						scanf("%s",&v[N].nome);
						printf("Digite o salário:\n");
						scanf("%f",&v[N].salario);
						return(v);
	
}

funcionario * removefunc(funcionario * v, int N, int pos){
			v[pos]= v[N-1];
			v= (funcionario *)realloc(v, sizeof(funcionario)*(N-1));
			return(v);
		}
}
	

