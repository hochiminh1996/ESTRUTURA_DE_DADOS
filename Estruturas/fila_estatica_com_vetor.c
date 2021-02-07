/*
	ALGORITMO : PILHA
	AUTOR : FELIPPE M.
	DESCRIÇÃO : APLICAÇÃO DOS CONCEITOS BÁSICOS DE ESTRUTURA DE DADOS : FILA E BUSCA BINÁRIA.
	...
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#define MAX 3

typedef struct{
	int total;
	int itens[MAX];
}fila;
/*
	CRIAÇÃO DA ESTRUTURA DO TIPO FILA.
	COMPORTA DUAS VARIÁVEIS 
	1 : TOTAL -> IRÁ CONTABILIZAR O TAMANHO DO INDÍCE 
	2 : ITENS -> SERÁ NOSSO VETOR DE [MAX] POSIÇÕES
*/


//INTERFACE BÁSICA
int menu(){
	int i,opt=0;
	printf("\n**************************************\n");
 	printf("\tSELECIONE UMA OPÇÃO : \n");
 	printf("**************************************\n");
	printf("0 ) MOSTRAR FILA\n");
	printf("1 ) ADICIONAR ELEMENTOS\n");
	printf("2 ) REMOVER ELEMENTOS\n");
	printf("3 ) BUSCAR ELEMENTOS\n");
	printf("4 ) LIMPAR FILA\n");
	printf("5 ) SAIR\n\n");
	printf("OPÇÃO : ");
	scanf("%i",&opt);

	return opt;//ESTE RETORNO SERÁ UTILIZADO NA FUNÇÃO ESCOLHA
}


//INICIALIZANDO A FILA
void inicializar(fila *pont_fila){
	pont_fila->total = -1;//PODERIA SER QUALQUER VALOR, MAS O "CONVENCIONAL" É USAR -1	
}

int escolha(int opt, fila *pont_fila){
	int valor,i,j,primeiro,chave,inicio, fim,busca,quant;
	
	// COM BASE NO VALOR CAPTURADO DA INTERFACE (MENU)
	switch(opt){
		case 0:
			if(pont_fila->total==-1){//CONSULTAR O VALOR DO TOTAL
				printf("FILA VAZIA...\n\n");//-1 = VAZIA
				system("pause");
				system("cls");
			}else{//CASO TENHA VALORES NA FILA, IRÁ EXIBIR SEUS VALORES
	
							
				// EXIBE OS ELEMENTOS JÁ ORDENADOS
				for(i=0;i<=pont_fila->total;i++){
					printf("\nELEMENTOS : [%i] %i",i,pont_fila->itens[i]);
					
					//IRÁ EXIBIR O VALOR DE CADA POSIÇÃO COM BASE NO NOSSO INDICE (i)
				}
				printf("\n\n");
				system("pause");
				system("cls");
			}

		break;
		case 1:
			if(pont_fila->total >= MAX-1){
				/*
					SE O VALOR FOR IGUAL A 2, A FILA ESTÁ CHEIA
					VALE LEMBRAR QUE O TOTAL COMEÇA COM -1
					
					FLUXO :
					pont_fila->total = -1 / MAX = 3-1 = 2
					-1 >= 2 / FALSO
					0 >= 2 / FALSO
					1 >= 2 / FALSO
					2 >=2 // VERDADEIRO  = FILA CHEIA 
				*/
				printf("\nFILA CHEIA\n\n");
				system("pause");
				system("cls");
			}else{
				printf("DIGITE UM VALOR : ");
				scanf("%i",&valor);
				
				if(pont_fila->total==-1){// IRÁ MOSTRAR O VALOR INICIAL DA FILA (-1)
					printf("\nPOSIÇÃO INICIAL : %i\n",pont_fila->total);
				}else{//IRÁ MOSTRAR A POSIÇÃO 0 - COM VALOR - e o índice final com o valor
					printf("\nPOSIÇÃO INICIAL : [0] %i \nPOSIÇÃO FINAL : [%i] %i\n\n",pont_fila->itens[0],pont_fila->total,pont_fila->itens[pont_fila->total]);

				}
				
				inserir(pont_fila,valor);// FUNÇÃO INSERIR
			}
		break;
		case 2:
			if(pont_fila->total==-1){//FILA ZERADA
				printf("ALERTA : NÃO FOI POSSÍVEL REMOVER ELEMENTOS\n\n");
				system("pause");
				system("cls");
			}else{
				primeiro = pont_fila->itens[0];	//IRÁ APENAS ARMAZENAR A POSIÇÃO 0			
				
				remover_da_fila(pont_fila);//FUNÇÃO REMOVER DA FLA
				
				printf("\nVALOR REMOVIDO : [0] %i\n\n",primeiro);// EXIBE O VALOR DA 0 POSIÇÃO
				
				system("pause");
				system("cls");
			}
		break;
		case 3:
			if(pont_fila->total == -1){
				printf("NÃO HÁ ELEMENTOS NA FILA...\n\n");
			}else{
				printf("DIGITE UM VALOR : ");
				scanf("%i",&chave);//valor a ser pesquisado
				
				quant = pont_fila->total;
				/*
					IMPORTANTE : QUANT ARMAZENA O TOTAL DE ALEMENTOS ATÉ ENTÃO
					
				*/
				busca = busca_binaria(pont_fila,inicio,quant, chave);
				/*
					BUSCA RETORNA O VALOR DA POSIÇÃO DO ELEMENTO CASO SEJA LOCALIZADO.
					pont_fila (são os intes)
					inicio = começa do zero
					quant = o total de elementos que foram adicionados
					chave = o elemento digitado pelo usuário
				*/
				
				
				if(busca!=-1){
					printf("\nVALOR LOCALIZADO : [%i] -> %i\n\n",busca,pont_fila->itens[busca]);
					
				}else {
					printf("VALOR NÃO LOCALIZADO %i\n\n",busca);
				}
			}
			system("pause");
			system("cls");
		break;
		case 4:
			inicializar(pont_fila);//REAPROVEITAMENTO DE FUNÇÃO
			printf("FILA ZERADA...\n\n");
			system("pause");
			system("cls");
		break;
		case 5:
			printf("SAINDO...\n");
		
		break;
		default : printf("OPÇÃO INVÁLIDA : TENTE NOVAMENTE\n\n");
		system("pause");
		system("cls");
		
	}
}

int inserir(fila *pont_fila,int valor){
	
	pont_fila->total++;// TOTAL COMEÇA COM -1, QUE IRÁ VIRAR 0..1..2..
	
	pont_fila->itens[pont_fila->total] = valor;//A POSIÇÃO FINAL IRÁ RECEBER O NOVO VALOR
	
	printf("VALOR INSERIDO : [%i] %i\n\n",pont_fila->total,pont_fila->itens[pont_fila->total]);//MOSTRA O QUE FOI FEITO

	ordena_lista(pont_fila);//ORDENA APÓS INSERÇÃO

	system("pause");
	system("cls");
}

int remover_da_fila(fila *pont_fila){
	int i=0;

	for(i=0;i<=pont_fila->total;i++){//IRÁ EXIBIR DA POSIÇÃO 0 ATÉ O TOTAL DE ELEMENTOS
		pont_fila->itens[i] = pont_fila->itens[i+1];
		/*
			EXEMPLO : 
			ELEMENTOS: 3, 5 ,1 
			POSIÇÕES : 0, 1, 2
			TOTAL : 3
			
			IREMOS SEMPRE REMOVER O VALOR DA POSIÇÃO 0
			LOGO,
			
		1 REMOÇÃO :	PONT_FILA->ITENS[0] (QUE É 3), SERÁ SUBSTITUIDO PELOVALOR DE 1 (I+1), QUE SERÁ O 5.
		2 REMOÇÃO : PONT_FILA->ITENS[0] (QUE É 5), SERÁ SUBSTITUIDO O VALOR DE 1 (I+1), QUE SERÁ 1
		

		
		*/
	}
	pont_fila->total--;//IRÁ DIMINUIR O TAMANHO DO TOTAL. OU SEJA, IRÁ PERCORRER DE 0 ATÉ TOTAL-1
}


ordena_lista(fila *pont_fila){
	int i,j,aux;
	/*
			O código abaixo representa a ordenação dos valores 
			visando  facilitar o processo de busca binária
	*/
	
	for(i=0;i<=pont_fila->total;i++){// 10 5
		for(j=i+1;j<=pont_fila->total;j++){
			if(pont_fila->itens[i] > pont_fila->itens[j]){
				aux = pont_fila->itens[i];//maior valor
				pont_fila->itens[i] = pont_fila->itens[j];
				pont_fila->itens[j] = aux;
			}
		}
	}
}

int busca_binaria(fila *pont_fila, int inicio, int fim, int chave){
	int meio;
	
	/*
		IRÁ EXECUTAR SE O VALOR DO INICIO FOR <= FIM
			
	
	*/

	if(inicio<=fim){

		meio = (inicio + fim) /2; //RETORNO O INDÍCE DO MEIO ATRAVÉS DA DIVISÃO DE INTEIRO. 4.5 = 4/ 1.5 = 1

		if(chave == pont_fila->itens[meio]){//SE O VALOR DIGITADO FOR IGUAL AO VALOR DO MEIO
			return meio;//RETURNA O MEIO, QUE É O INDICE

		}else{
			if(chave < pont_fila->itens[meio]){//SE O VALOR DIGITADO FOR < QUE O VALOR DO INDICE DO MEIO
				return busca_binaria(pont_fila, inicio, meio - 1,chave);
				/*
				Está retornando, recursivamente, o valor do ponteiro(elementos), 
				FIM = será o valor de meio - 1, pois o valor digitado pelo usuário é menor que o valor do indice meio
				
				EXEMPLO :
					
					Indice :    0  1  2   3
					Elementos : 5 10 15  20
					
				passo 1
					inicio = 0
					fim = 3
					meio = (inicio+fim)/2. Será 3/2 = 1 (divisão inteira) 
					busca : 5
					
					busca (5) é igual ao valor do indice [1]= 10? Não
					
					busca (5) é maior ou menor que indice[1]= 10 ? Menor
					
				passo 2
					inicio = 0
					fim = (meio - 1) pois o valor do usuário era maior
					fim = 1 - 1 = 0
					
					meio =  0 - 0 = 0 / 2 = 0 (divisão inteira)
					
					busca (5) é igual ao valor do indice [0]= 5? Sim
					Encontramos o valor
				*/
			}else if(chave > pont_fila->itens[meio]){
				return busca_binaria(pont_fila, meio + 1, fim,chave);
				/*
					está retornando, recursivamente, o valor do ponteiro(elementos), 
					INICIO = será o valor de meio + 1, pois o valor digitado pelo usuário é maior que o valor do indice meio
					
					Indice :    0  1  2   3
					Elementos : 5 10 15  20
	
				EXEMPLO :
	
				passo 1
					inicio = 0
					fim = 3
					meio = (inicio+fim)/2. Será 3/2 = 1 (divisão inteira) 
					busca : 20
					
					busca (20) é igual ao valor do indice [1]= 10? Não
					
					busca (20) é maior ou menor que indice[1]= 10 ? maior
					
				passo 2
					inicio = meio + 1, pois o valor do usuário era maior
					inicio = 1 + 1 = 2
					fim = 3
					meio = 2 + 3 = 5. 5/2 = 2 (divisão inteira)
					
					busca (20) é igual ao valor do indice [2]= 15? Não
					
					busca (20) é maior ou menor que indice[2]= 15 ? maior
 				
 				passo 3
					inicio = meio + 1, pois o valor do usuário era maior
					inicio = 2 + 1 = 3
					fim = 3
					meio = 3+3 = 6. 6/2 = 3 (divisão inteira)
					
					busca (20) é igual ao valor do indice [3]= 20? Sim
											
				*/
			}
		}
	}

	return -1;//significa que não foi localizado o elemento
		
}


int main(){
	setlocale(LC_ALL,"PORTUGUESE");
	int opt;
	fila *pont_fila = (fila*) malloc(sizeof(fila));
	//ESTAMOS REALIZANDO O PROCEDIMENTO DE ALOCAÇÃO DE MEMÓRIA COM BASE NO TAMANHO DA STRUCT FILA
	
	inicializar(pont_fila);//INICIALIZA A FILA COM -1 ("VAZIA")
	
	do
	{
		opt = menu();//OPT RECEBE O VALOR DIGITADO NA INTERFACE
		escolha(opt,pont_fila);//FORNECE A OPÇÃO E O PONTEIRO
	}while(opt!=5);
	/*
		TEMOS UM LAÇO DO PARA FACILITAR A EXIBIÇÃO FIXA DA INTERFACE.
		LOGO, QUALQUER COMANDO QUE NÃO SEJA 5 IRÁ RECHAMAR A INTERFACE
	*/
	
}
