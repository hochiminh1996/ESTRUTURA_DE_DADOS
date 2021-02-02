/*	
	ALGORITMO : PILHA
	AUTOR : FELIPPE M.
	DESCRI��O : APLICA��O DOS CONCEITOS B�SICOS DE ESTRUTURA DE DADOS : PILHA
	
*/
#define MAX 3
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>//getch() = pause
#include <locale.h>


//estrutura da PILHA
typedef struct{
	int itens[MAX];//quantidade de posi��es ou indice
	int topo;//topo da PILHA
	
}PILHA;

//MENU DE OP��ES
int menu(){
	int opt;//vari�vel da op��o
	
	printf("**************************************\n");
 	printf("\tSELECIONE UMA OP��O : \n");
 	printf("**************************************\n");
	printf("0 : EXIBIR PILHA\n");
	printf("1 : ADICIONAR ELEMENTOS\n");
	printf("2 : REMOVER ELEMENTOS\n");
	printf("3 : LIMPAR PILHA\n");
	printf("4 : SAIR\n");

	scanf("%i",&opt);
	return opt;
}


//ESCOLHA J� EFETUADO
int escolha(int opt, PILHA *pont_pilha){
	int i,x,aux,indice_topo;
	/*
		X : ser� para o novo valor acrescentado
		aux : ser� armazenado o �ltimo valor que ser� removido
		indice_topo : ir� armazenar o indice do �ltimo valor removido
	*/
	printf("\nOP��O ESCOLHIDA : %i\n\n",opt);
	
	switch(opt){
		//EXIBI��O DA PILHA
		case 0:
			if(pont_pilha->topo==-1){
				pilha_vazia(pont_pilha);
			}else{
				if(pilha_cheia(pont_pilha)==1){
					for(i=0;i<=MAX;i++){
						printf("[%i] = %i \n",i,pont_pilha->itens[i]);
					}
				}else{
				printf("TOPO %i [%i]\n\n",pont_pilha->topo,pont_pilha->itens[pont_pilha->topo]);
					for(i=0;i<=pont_pilha->topo;i++){
						printf("[%i] = %i \n",i,pont_pilha->itens[i]);
					}
				}
				
			}
			printf("\nPILHA -> %i",pont_pilha->topo);	
			printf("\n");
			system("pause");
			system("cls");
			
		break;
		case 1:
			printf("TAMANHO ATUAL DA PILHA -> %i\n\nTAMANHO M�XIMO (MAX) : %i\n\n",pont_pilha->topo, MAX-1);
			if(pont_pilha->topo < MAX-1){
			/*
				A condi��o acima compara o tamanho da PILHA com o tamanho do indice m�ximo = 3
				-1 < 3-1(2) = true = insere 
				 0 < 3-1(2) = true = insere
				 1 < 3-1(2) = true = insere
				 2 < 3-1(0) = falso = encerra.	
			*/
			
				
//			printf("%i < %i = %i\n",pont_pilha->topo,MAX-1,pont_pilha->topo<MAX-1);
				if(pilha_cheia(pont_pilha)==0){
					printf("DIGITE O VALOR A SER ACRESCENTADO : ");
					scanf("%i",&x);
					
					pilha_inserir(pont_pilha,x);//chama fun��o para inserir
				
					system("pause");
					system("cls");
				}
			}else{
//				printf("%i < %i = %i\n",pont_pilha->topo,MAX-1,pont_pilha->topo<MAX-1);

				printf("ALERTA : N�O H� ESPA�O NA PILHA %i\n\n",pont_pilha->topo);
				system("pause");
				system("cls");
			}
		break;
		case 2:
			if(pilha_vazia(pont_pilha) != 1){
				indice_topo = pont_pilha->topo;
				/*
					est� guardando a posi��o do �ltimo valor (topo). Pois quando passar por pilha_remover
					ele ser� decrementado, para regredir uma casa.
					
					Se n�o armazenarmos o indice que ser� removido, ele sempre vir� com uma posi�o a menos 
					5 1 10 25
					0 1 2 3
					
					Por exemplo, quando passar pela fun��o remove, ele ir� informar que removeu o valor certo(25).
					Contudo, ir� retornar na posi��o 2, ou seja, [2] = 25. O certo � [3] = 25.
					Por isso salvamos o valor que ser� removido (em aux) e sua posi��o em indice_topo
					
				*/
			
			
				aux = pilha_remover(pont_pilha);
				printf("VALOR REMOVIDO : [%i] %i\n",indice_topo, aux);
			
				system("pause");
				system("cls");
			}else{
				printf("\n");
				system("pause");
				system("cls");
			}
		break;
		case 3:
			pont_pilha->topo = -1;//reseta o �ltimo 
			printf("PILHA RESETADA...\n\n");
			
			
			
			system("pause");
			system("cls");
		
		break;
		case 4:
			printf("Saindo...\n\n");
			
			
			system("pause");
			system("cls");
		
		break;
		default : printf("\n[OP��O INV�LIDA]\n\n");
		system("pause");
		system("cls");
	}
}


//1 ) inicializa��o da PILHA
void pilha_inicia(PILHA *pont_pilha){//um ponteiro p(PILHA) do tipo PILHA
//	pont_pilha<-topo = -1;//determina que nossa PILHA est� vazia
	
	pont_pilha->topo = -1;
}


//2 ) verifica se a PILHA est� vazia
int pilha_vazia(PILHA *pont_pilha){
	if(pont_pilha->topo==-1){
		printf("***PILHA VAZIA***\n");
		//est� acessando o �ltimo elemento, que foi inicializado anteriormente. Se tiver -1, ser� vazio
		
		return 1;
	}else{
		return 0;//se o valor for 0, significa que h� elementos na PILHA
	}
}


//3 ) verifica se a PILHA est� cheia
int pilha_cheia(PILHA *pont_pilha){
	if(pont_pilha->topo > MAX-1){	// cheia
		return 1;
	}else{
		return 0;
	}
}

//4 ) inserindo elementos na PILHA
int pilha_inserir(PILHA *pont_pilha, int x){//x � o valor que ser� inserido no topo da PILHA
	

	if(pilha_cheia(pont_pilha)==1){
		printf("*PILHA CHEIA**");
	}else{
		pont_pilha->topo++;//ir� acrecentar +1 na posi��o
		/*
			PILHA
			explica��o de topo ++
			
			topo  =	 1  2  X
			  		[0][1][2]
			
			quando for inserir um novo valor (x), o topo precisa avan�ar uma posi��o.
			Ou seja, ele estava na [1] e ir� adicionar no [2]
		*/ 
		
		pont_pilha->itens[pont_pilha->topo] = x;
		/*	Estamos acessando o ind�ce (pont_pilha->itens) e atribuindo o valor dele na posi��o X.
			[pont_pilha->topo] = este topo no vetor � o topo++. Ou seja, a posi��o */		
	}
}	

//5 ) removendo elementos da PILHA
int pilha_remover(PILHA *pont_pilha){
	int aux;
	if(pilha_vazia(pont_pilha) == 1){// 1 vazio
		printf("*PILHA VAZIA*");
	}else{
		aux = pont_pilha->itens[pont_pilha->topo];
		/*
			aux = acessa a �ltima posi��o dos elementos [PILHA->topo]
		*/
		pont_pilha->topo--;
		// Ir� regredir uma posi��o do vetor, por causa da remo��o	
		return aux;
	}	
}

//0 ) FUN��O PRINCIPAL
int main(){
	setlocale(LC_ALL,"PORTUGUESE");
	int aux,i,opcao;

	PILHA *pont_pilha = (PILHA*)malloc(sizeof(PILHA));

	pilha_inicia(pont_pilha);

	do{
		opcao = menu();//chama menu
		escolha(opcao,pont_pilha);//passa a op��o para fun��o escolha
	}while(opcao!=4) ;//ir� rodar enquanto o valor for diferente de 4	
}
