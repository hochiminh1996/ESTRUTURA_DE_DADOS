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
	int localizado[MAX]; 
	int indice;
	
	/*
		FUNÇÃO BUSCA : 
		
		itens[max] = vetor principal
		
		localizado[max] = vetor auxiliar / irá receber as posições dos elementos localizados
		
		indice = será utilizado para incrementar as posições do vetor "localizado".
		
		Ou seja, se o número for localizado 2x, indice será = 2. 
		Portanto, o vetor auxiliar irá ter duas opções = localizado[indice] / localizado[0] e localizado[1]
	*/
	
	
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
	pont_fila->indice = 0;	
}

int escolha(int opt, fila *pont_fila){
	int valor,i,j,primeiro,num;
		
	// COM BASE NO VALOR CAPTURADO DA INTERFACE (MENU)
	switch(opt){
		case 0:
			if(pont_fila->total==-1){//CONSULTAR O VALOR DO TOTAL
				printf("FILA VAZIA : %i\n\n",pont_fila->total);//-1 = VAZIA
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
				printf("ALERTA : NÃO FOI POSSÍVEL REMOVER ELEMENTOS : %i\n\n",pont_fila->total);
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
				printf("NÃO HÁ ELEMENTOS NA FILA : %i\n\n",pont_fila->total);
			}else{
				printf("DIGITE O VALOR A SER BUSCADO : ");
				scanf("%i",&num);
				//valor de comparação
				
				/*
					irá percorrer todos os elementos de acordo com seu tamanho
					se total = 1, irá percorrer apenas 1x
				*/
				for(i=0;i<=pont_fila->total;i++){
					if(num == pont_fila->itens[i]){//comparação
						pont_fila->localizado[pont_fila->indice] = i;
						pont_fila->indice++;
						
						/*
						
						pont_fila->localizado[pont_fila->indice] = i;
						Se o elemento for localizado, o vetor auxiliar irá receber sua posição (i)
						
						Por exemplo : 
						pont_fila tem 3 posições [0] = 10, [1] = 5, [2] = 10
						
						Se o usuário digitar 10, a posição [0] e [2] será armazenada no vetor auxiliar 
						
						
						E, em seguida, iremos incrementar o indice++, que irá valer 2 que, por consequência, irá fazer
						o vetor localiza ter duas posições, conforme já explicado
						
						*/
					}
				}

				if(pont_fila->indice > 0){
					printf("\nELEMENTO LOCALIZADO\n\n");
					for(i=0;i<pont_fila->indice;i++){
						printf("[%i] - > %i\n", pont_fila->localizado[i],pont_fila->itens[pont_fila->localizado[i]]);
					}
					printf("\n");
					pont_fila->indice = 0;
				}else if(pont_fila->indice == 0){
					printf("\nELEMENTO NÃO LOCALIZADO : %i\n\n",pont_fila->indice);
				}
				
			}
			system("pause");
			system("cls");
		break;
		case 4:
			inicializar(pont_fila);//REAPROVEITAMENTO DE FUNÇÃO
			printf("FILA ZERADA :%i...\n\n",pont_fila->total);
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

//	ordena_lista(pont_fila);//ORDENA APÓS INSERÇÃO

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


//ordena_lista(fila *pont_fila){
//	int i,j,aux;
//	/*
//			O código abaixo representa a ordenação dos valores 
//			visando  facilitar o processo de busca binária
//	*/
//	
//	for(i=0;i<=pont_fila->total;i++){// 10 5
//		for(j=i+1;j<=pont_fila->total;j++){
//			if(pont_fila->itens[i] > pont_fila->itens[j]){
//				aux = pont_fila->itens[i];//maior valor
//				pont_fila->itens[i] = pont_fila->itens[j];
//				pont_fila->itens[j] = aux;
//			}
//		}
//	}
//}




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
