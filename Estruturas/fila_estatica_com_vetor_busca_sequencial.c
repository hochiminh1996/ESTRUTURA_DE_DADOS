/*
	ALGORITMO : PILHA
	AUTOR : FELIPPE M.
	DESCRI��O : APLICA��O DOS CONCEITOS B�SICOS DE ESTRUTURA DE DADOS : FILA E BUSCA BIN�RIA.
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
		FUN��O BUSCA : 
		
		itens[max] = vetor principal
		
		localizado[max] = vetor auxiliar / ir� receber as posi��es dos elementos localizados
		
		indice = ser� utilizado para incrementar as posi��es do vetor "localizado".
		
		Ou seja, se o n�mero for localizado 2x, indice ser� = 2. 
		Portanto, o vetor auxiliar ir� ter duas op��es = localizado[indice] / localizado[0] e localizado[1]
	*/
	
	
}fila;
/*
	CRIA��O DA ESTRUTURA DO TIPO FILA.
	COMPORTA DUAS VARI�VEIS 
	1 : TOTAL -> IR� CONTABILIZAR O TAMANHO DO IND�CE 
	2 : ITENS -> SER� NOSSO VETOR DE [MAX] POSI��ES
*/


//INTERFACE B�SICA
int menu(){
	int i,opt=0;
	printf("\n**************************************\n");
 	printf("\tSELECIONE UMA OP��O : \n");
 	printf("**************************************\n");
	printf("0 ) MOSTRAR FILA\n");
	printf("1 ) ADICIONAR ELEMENTOS\n");
	printf("2 ) REMOVER ELEMENTOS\n");
	printf("3 ) BUSCAR ELEMENTOS\n");
	printf("4 ) LIMPAR FILA\n");
	printf("5 ) SAIR\n\n");
	printf("OP��O : ");
	scanf("%i",&opt);

	return opt;//ESTE RETORNO SER� UTILIZADO NA FUN��O ESCOLHA
}


//INICIALIZANDO A FILA
void inicializar(fila *pont_fila){
	pont_fila->total = -1;//PODERIA SER QUALQUER VALOR, MAS O "CONVENCIONAL" � USAR -1
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
			}else{//CASO TENHA VALORES NA FILA, IR� EXIBIR SEUS VALORES
	
							
				// EXIBE OS ELEMENTOS J� ORDENADOS
				for(i=0;i<=pont_fila->total;i++){
					printf("\nELEMENTOS : [%i] %i",i,pont_fila->itens[i]);
					
					//IR� EXIBIR O VALOR DE CADA POSI��O COM BASE NO NOSSO INDICE (i)
				}
				printf("\n\n");
				system("pause");
				system("cls");
			}

		break;
		case 1:
			if(pont_fila->total >= MAX-1){
				/*
					SE O VALOR FOR IGUAL A 2, A FILA EST� CHEIA
					VALE LEMBRAR QUE O TOTAL COME�A COM -1
					
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
				
				if(pont_fila->total==-1){// IR� MOSTRAR O VALOR INICIAL DA FILA (-1)
					printf("\nPOSI��O INICIAL : %i\n",pont_fila->total);
				}else{//IR� MOSTRAR A POSI��O 0 - COM VALOR - e o �ndice final com o valor
					printf("\nPOSI��O INICIAL : [0] %i \nPOSI��O FINAL : [%i] %i\n\n",pont_fila->itens[0],pont_fila->total,pont_fila->itens[pont_fila->total]);

				}
				
				inserir(pont_fila,valor);// FUN��O INSERIR
			}
		break;
		case 2:
			if(pont_fila->total==-1){//FILA ZERADA
				printf("ALERTA : N�O FOI POSS�VEL REMOVER ELEMENTOS : %i\n\n",pont_fila->total);
				system("pause");
				system("cls");
			}else{
				primeiro = pont_fila->itens[0];	//IR� APENAS ARMAZENAR A POSI��O 0			
				
				remover_da_fila(pont_fila);//FUN��O REMOVER DA FLA
				
				printf("\nVALOR REMOVIDO : [0] %i\n\n",primeiro);// EXIBE O VALOR DA 0 POSI��O
				
				system("pause");
				system("cls");
			}
		break;
		case 3:
			if(pont_fila->total == -1){
				printf("N�O H� ELEMENTOS NA FILA : %i\n\n",pont_fila->total);
			}else{
				printf("DIGITE O VALOR A SER BUSCADO : ");
				scanf("%i",&num);
				//valor de compara��o
				
				/*
					ir� percorrer todos os elementos de acordo com seu tamanho
					se total = 1, ir� percorrer apenas 1x
				*/
				for(i=0;i<=pont_fila->total;i++){
					if(num == pont_fila->itens[i]){//compara��o
						pont_fila->localizado[pont_fila->indice] = i;
						pont_fila->indice++;
						
						/*
						
						pont_fila->localizado[pont_fila->indice] = i;
						Se o elemento for localizado, o vetor auxiliar ir� receber sua posi��o (i)
						
						Por exemplo : 
						pont_fila tem 3 posi��es [0] = 10, [1] = 5, [2] = 10
						
						Se o usu�rio digitar 10, a posi��o [0] e [2] ser� armazenada no vetor auxiliar 
						
						
						E, em seguida, iremos incrementar o indice++, que ir� valer 2 que, por consequ�ncia, ir� fazer
						o vetor localiza ter duas posi��es, conforme j� explicado
						
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
					printf("\nELEMENTO N�O LOCALIZADO : %i\n\n",pont_fila->indice);
				}
				
			}
			system("pause");
			system("cls");
		break;
		case 4:
			inicializar(pont_fila);//REAPROVEITAMENTO DE FUN��O
			printf("FILA ZERADA :%i...\n\n",pont_fila->total);
			system("pause");
			system("cls");
		break;
		case 5:
			printf("SAINDO...\n");
		
		break;
		default : printf("OP��O INV�LIDA : TENTE NOVAMENTE\n\n");
		system("pause");
		system("cls");
		
	}
}

int inserir(fila *pont_fila,int valor){
	
	pont_fila->total++;// TOTAL COME�A COM -1, QUE IR� VIRAR 0..1..2..
	
	pont_fila->itens[pont_fila->total] = valor;//A POSI��O FINAL IR� RECEBER O NOVO VALOR
	
	printf("VALOR INSERIDO : [%i] %i\n\n",pont_fila->total,pont_fila->itens[pont_fila->total]);//MOSTRA O QUE FOI FEITO

//	ordena_lista(pont_fila);//ORDENA AP�S INSER��O

	system("pause");
	system("cls");
}

int remover_da_fila(fila *pont_fila){
	int i=0;

	for(i=0;i<=pont_fila->total;i++){//IR� EXIBIR DA POSI��O 0 AT� O TOTAL DE ELEMENTOS
		pont_fila->itens[i] = pont_fila->itens[i+1];
		/*
			EXEMPLO : 
			ELEMENTOS: 3, 5 ,1 
			POSI��ES : 0, 1, 2
			TOTAL : 3
			
			IREMOS SEMPRE REMOVER O VALOR DA POSI��O 0
			LOGO,
			
		1 REMO��O :	PONT_FILA->ITENS[0] (QUE � 3), SER� SUBSTITUIDO PELOVALOR DE 1 (I+1), QUE SER� O 5.
		2 REMO��O : PONT_FILA->ITENS[0] (QUE � 5), SER� SUBSTITUIDO O VALOR DE 1 (I+1), QUE SER� 1
		

		
		*/
	}
	pont_fila->total--;//IR� DIMINUIR O TAMANHO DO TOTAL. OU SEJA, IR� PERCORRER DE 0 AT� TOTAL-1
}


//ordena_lista(fila *pont_fila){
//	int i,j,aux;
//	/*
//			O c�digo abaixo representa a ordena��o dos valores 
//			visando  facilitar o processo de busca bin�ria
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
	//ESTAMOS REALIZANDO O PROCEDIMENTO DE ALOCA��O DE MEM�RIA COM BASE NO TAMANHO DA STRUCT FILA
	
	inicializar(pont_fila);//INICIALIZA A FILA COM -1 ("VAZIA")
	
	do
	{
		opt = menu();//OPT RECEBE O VALOR DIGITADO NA INTERFACE
		escolha(opt,pont_fila);//FORNECE A OP��O E O PONTEIRO
	}while(opt!=5);
	/*
		TEMOS UM LA�O DO PARA FACILITAR A EXIBI��O FIXA DA INTERFACE.
		LOGO, QUALQUER COMANDO QUE N�O SEJA 5 IR� RECHAMAR A INTERFACE
	*/
	
}
