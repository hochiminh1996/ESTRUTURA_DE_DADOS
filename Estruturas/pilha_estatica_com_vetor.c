/*	
	ALGORITMO : PILHA
	AUTOR : FELIPPE M.
	DESCRIÇÃO : APLICAÇÃO DOS CONCEITOS BÁSICOS DE ESTRUTURA DE DADOS : PILHA
	
*/
#define MAX 3
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>//getch() = pause
#include <locale.h>


//estrutura da PILHA
typedef struct{
	int itens[MAX];//quantidade de posições ou indice
	int topo;//topo da PILHA
	
}PILHA;

//MENU DE OPÇÕES
int menu(){
	int opt;//variável da opção
	
	printf("**************************************\n");
 	printf("\tSELECIONE UMA OPÇÃO : \n");
 	printf("**************************************\n");
	printf("0 : EXIBIR PILHA\n");
	printf("1 : ADICIONAR ELEMENTOS\n");
	printf("2 : REMOVER ELEMENTOS\n");
	printf("3 : LIMPAR PILHA\n");
	printf("4 : SAIR\n");

	scanf("%i",&opt);
	return opt;
}


//ESCOLHA JÁ EFETUADO
int escolha(int opt, PILHA *pont_pilha){
	int i,x,aux,indice_topo;
	/*
		X : será para o novo valor acrescentado
		aux : será armazenado o último valor que será removido
		indice_topo : irá armazenar o indice do último valor removido
	*/
	printf("\nOPÇÃO ESCOLHIDA : %i\n\n",opt);
	
	switch(opt){
		//EXIBIÇÃO DA PILHA
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
			printf("TAMANHO ATUAL DA PILHA -> %i\n\nTAMANHO MÁXIMO (MAX) : %i\n\n",pont_pilha->topo, MAX-1);
			if(pont_pilha->topo < MAX-1){
			/*
				A condição acima compara o tamanho da PILHA com o tamanho do indice máximo = 3
				-1 < 3-1(2) = true = insere 
				 0 < 3-1(2) = true = insere
				 1 < 3-1(2) = true = insere
				 2 < 3-1(0) = falso = encerra.	
			*/
			
				
//			printf("%i < %i = %i\n",pont_pilha->topo,MAX-1,pont_pilha->topo<MAX-1);
				if(pilha_cheia(pont_pilha)==0){
					printf("DIGITE O VALOR A SER ACRESCENTADO : ");
					scanf("%i",&x);
					
					pilha_inserir(pont_pilha,x);//chama função para inserir
				
					system("pause");
					system("cls");
				}
			}else{
//				printf("%i < %i = %i\n",pont_pilha->topo,MAX-1,pont_pilha->topo<MAX-1);

				printf("ALERTA : NÃO HÁ ESPAÇO NA PILHA %i\n\n",pont_pilha->topo);
				system("pause");
				system("cls");
			}
		break;
		case 2:
			if(pilha_vazia(pont_pilha) != 1){
				indice_topo = pont_pilha->topo;
				/*
					está guardando a posição do último valor (topo). Pois quando passar por pilha_remover
					ele será decrementado, para regredir uma casa.
					
					Se não armazenarmos o indice que será removido, ele sempre virá com uma posiço a menos 
					5 1 10 25
					0 1 2 3
					
					Por exemplo, quando passar pela função remove, ele irá informar que removeu o valor certo(25).
					Contudo, irá retornar na posição 2, ou seja, [2] = 25. O certo é [3] = 25.
					Por isso salvamos o valor que será removido (em aux) e sua posição em indice_topo
					
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
			pont_pilha->topo = -1;//reseta o último 
			printf("PILHA RESETADA...\n\n");
			
			
			
			system("pause");
			system("cls");
		
		break;
		case 4:
			printf("Saindo...\n\n");
			
			
			system("pause");
			system("cls");
		
		break;
		default : printf("\n[OPÇÃO INVÁLIDA]\n\n");
		system("pause");
		system("cls");
	}
}


//1 ) inicialização da PILHA
void pilha_inicia(PILHA *pont_pilha){//um ponteiro p(PILHA) do tipo PILHA
//	pont_pilha<-topo = -1;//determina que nossa PILHA está vazia
	
	pont_pilha->topo = -1;
}


//2 ) verifica se a PILHA está vazia
int pilha_vazia(PILHA *pont_pilha){
	if(pont_pilha->topo==-1){
		printf("***PILHA VAZIA***\n");
		//está acessando o último elemento, que foi inicializado anteriormente. Se tiver -1, será vazio
		
		return 1;
	}else{
		return 0;//se o valor for 0, significa que há elementos na PILHA
	}
}


//3 ) verifica se a PILHA está cheia
int pilha_cheia(PILHA *pont_pilha){
	if(pont_pilha->topo > MAX-1){	// cheia
		return 1;
	}else{
		return 0;
	}
}

//4 ) inserindo elementos na PILHA
int pilha_inserir(PILHA *pont_pilha, int x){//x é o valor que será inserido no topo da PILHA
	

	if(pilha_cheia(pont_pilha)==1){
		printf("*PILHA CHEIA**");
	}else{
		pont_pilha->topo++;//irá acrecentar +1 na posição
		/*
			PILHA
			explicação de topo ++
			
			topo  =	 1  2  X
			  		[0][1][2]
			
			quando for inserir um novo valor (x), o topo precisa avançar uma posição.
			Ou seja, ele estava na [1] e irá adicionar no [2]
		*/ 
		
		pont_pilha->itens[pont_pilha->topo] = x;
		/*	Estamos acessando o indíce (pont_pilha->itens) e atribuindo o valor dele na posição X.
			[pont_pilha->topo] = este topo no vetor é o topo++. Ou seja, a posição */		
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
			aux = acessa a última posição dos elementos [PILHA->topo]
		*/
		pont_pilha->topo--;
		// Irá regredir uma posição do vetor, por causa da remoção	
		return aux;
	}	
}

//0 ) FUNÇÃO PRINCIPAL
int main(){
	setlocale(LC_ALL,"PORTUGUESE");
	int aux,i,opcao;

	PILHA *pont_pilha = (PILHA*)malloc(sizeof(PILHA));

	pilha_inicia(pont_pilha);

	do{
		opcao = menu();//chama menu
		escolha(opcao,pont_pilha);//passa a opção para função escolha
	}while(opcao!=4) ;//irá rodar enquanto o valor for diferente de 4	
}
