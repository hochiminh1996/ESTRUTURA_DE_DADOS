/*
	ALGORITMO : BUSCA
	AUTOR : FELIPPE M.
	DESCRIÇÃO : APLICAÇÃO DOS CONCEITOS BÁSICOS DE ESTRUTURA DE DADOS : BUSCA BINÁRIA
	...
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define MAX 3

typedef struct{
	int total;
	int itens[MAX];
	
}estrutura;



int inicializar(estrutura *pont_busca){

	pont_busca->total = -1;
	
}
int menu(){
	int opcao;
	printf("\n**************************************\n");
 	printf("\tSELECIONE UMA OPÇÃO : \n");
 	printf("**************************************\n");
	printf("0 ) MOSTRAR ELEMENTOS\n");
	printf("1 ) ADICIONAR ELEMENTOS\n");
	printf("2 ) BUSCAR ELEMENTOS\n");
	printf("3 ) ZERAR ELEMENTOS\n");
	printf("4 ) SAIR\n");
	scanf("%i",&opcao);
	return opcao;
	
}

int selecao(int opcao, estrutura *pont_busca){
	int i,valor,total,inicio=0,indice_retorno;

	
	
	switch (opcao){
		case 0 :
			printf("\n");
			if(pont_busca->total == -1){
				printf("***NÃO  HÁ ELEMENTOS : %i ***\n\n",pont_busca->total);
			}else{
				for(i=0;i<=pont_busca->total;i++){
					printf("ELEMENTOS : [%i] -> %i\n",i,pont_busca->itens[i]);
				}
				printf("\n");
			}
			
			system("pause");
			system("cls");
			
		break;
		case 1 :
			adicionar_elementos(pont_busca);	
		
			system("pause");
			system("cls");
		break;
		case 2 :
			if(pont_busca->total == -1){//VAZIO
				printf("\n***NÃO HÁ ELEMENTOS : %i***\n\n",pont_busca->total);
				system("pause");
				system("cls");
			}else{
				ordenacao(pont_busca);
				/*
					BUSCA BINÁRIA : NECESSITA DOS ELEMENTOS ORDENADOS				
				
				*/
				
				printf("\nDIGITE O VALOR A SER PESQUISADO : ");
				scanf("%i",&valor);
				
				total = pont_busca->total;
				//irá armazenar o total de elementos para percorrer
				
			
				indice_retorno = buscar_elementos(pont_busca, inicio, total,valor);
				/*
					FUNÇÃO RECURSIVA QUE RETORNA O INDICE DO ELEMENTO, CASO SEJA LOCALIZADO.
					CASO NÃO, RETORNA -1
				*/
				
					
				if(indice_retorno == -1){//ELEMENTO NÃO LOCALIZADO
					printf("\n***ELEMENTO NÃO LOCALIZADO : %i ***\n\n",indice_retorno);
					system("pause");
					system("cls");
				}else{//ELEMENTO LOCALIZADO
					printf("\nELEMENTO LOCALIZADO : ");
					printf("[%i] -> %i\n\n",indice_retorno,pont_busca->itens[indice_retorno]);
					//APENAS ACESSA O ELEMENTO LOCALIZADO ATRAVES DO INDICE RETORNADO
					system("pause");
					system("cls");
				}
				
				
			}
			
		break;

		case 3 :
			if(pont_busca->total!=-1){
				inicializar(pont_busca);
				printf("\nELEMENTOS ZERADOS...\n\n");
				system("pause");
				system("cls");
			}else{
				printf("\n***NÃO HÁ ELEMENTOS A SEREM ZERADOS : %i***\n\n",pont_busca->total);
				system("pause");
				system("cls");
			}
		break;
		case 4 :
			printf("SAINDO...\n");
			system("pause");
		break;
		default : printf("\n\n**OPÇÃO INVÁLIDA***\n\n");
		system("pause");
		system("cls");
		
		
	}
	
}

int adicionar_elementos(estrutura *pont_busca){
	int valor;
	
	if(pont_busca->total>=MAX-1){
		printf("\n***NÃO HÁ ESPAÇO : %i***\n\n",pont_busca->total);
		/*
			VERIFICA SE O INDICE ESTOUROU O VALOR PERMTIDO
			LEMBRA-SE : A COMPRAÇÃO COMEÇA COM -1
			
			POR EXEMPLO: MAX = 3. LOGO MAX - 1 = 2
			
			TOTAL COMEÇA COM -1, POIS É INICIALIZADO COM ESTE VALOR
			
			1X  = -1 >= 2 / FALSO
			2X  =  0 >= 2 / FALSO
			3X  =  1 >= 2 / FALSO
			4X  =  2 >=2 / VERDEIRO -> TERMINA A COMPARAÇÃO, POIS MAX-1 <=TOTAL 
				
		*/
		
	}else{
		
		printf("DIGITE O VALOR : ");
		scanf("%i",&valor);	
			
				
		printf("\nTAMANHO MÁXIMO : %i\nTAMANHO ATUAL : %i\n\n", MAX-1,pont_busca->total);
		// INFORME O TAMANHO MÁXIMO (MAX-1) E TAMANHO ATUAL (PONT_BUSCA->TOTAL)
		
		pont_busca->total++;//incrementa o indice total, que no inicio é -1
		
		pont_busca->itens[pont_busca->total] = valor;
		//itens irá receber o valor digital na posição total. Q será 0 na primeira vez
		
		printf("\nVALOR ADICIONADO : %i\n",pont_busca->itens[pont_busca->total]);	
		//exibe o valor desejado		
	}
}


//estrutura simples de ordenação 
int ordenacao(estrutura *pont_busca){
	int aux,i,j;
	
	for(i=0;i<=pont_busca->total;i++){
		for(j=i+1;j<=pont_busca->total;j++){
			if(pont_busca->itens[i] > pont_busca->itens[j]){
				aux = pont_busca->itens[i];//maior valor
				pont_busca->itens[i] = pont_busca->itens[j];
				pont_busca->itens[j] = aux;
			}
		}
	}
	
}


//FUNÇÃO RECURSIVA PARA A BUSCA DO VALOR DESEJADO
int buscar_elementos(estrutura *pont_busca,int inicio,int fim,int valor){
	int meio;
	
	if(inicio<=fim){
		meio = (inicio + fim ) /2;
//		printf("MEIO : %i\n",meio);
		
		if(valor == pont_busca->itens[meio]){
			return meio;
			/*
				CASO O VALOR DESEJADO ESTEJA NA POSIÇÃO DO MEIO. MEIO = (INICIO+FIM)/2
				 RETORNA SEU INDICE PARA indice_retorno, LINHA 79
			*/
		}else{
			if(valor < pont_busca->itens[meio]){
				return buscar_elementos(pont_busca, inicio, meio - 1, valor);
				/*
					CASO O VALOR DIGITADO, SEJA MENOR QUE A POSIÇÃO DO MEIO DO VETOR
					LOGO, O VALOR DO FIM SERÁ = (MEIO -1)
				*/
			}else{
				return buscar_elementos(pont_busca, meio + 1, fim, valor);
				/*
					CASO O VALOR DIGITADO, SEJA MAIOR QUE A POSIÇÃO DO MEIO DO VETOR
					LOGO, O VALOR DO INICIO SERÁ = (MEIO + 1)
				*/
			}
		}
	}
	return -1;//VALOR NÃO LOCALIZADO
}

int main(){
	setlocale(LC_ALL,"PORTUGUESE");
	int opt;
	estrutura *pont_busca = (estrutura*) malloc(sizeof(estrutura));
	
	inicializar(pont_busca);
	
	//ESTRUTURA BÁSICA DE REPETIÇÃO ATÉ SER IGUAL 3
	do{
		opt = menu();
//		printf("OPT : %i",opt);
		selecao(opt, pont_busca);
		
	}while(opt!=4);
}



