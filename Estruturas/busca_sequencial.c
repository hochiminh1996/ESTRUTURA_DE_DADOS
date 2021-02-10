/*
	ALGORITMO : BUSCA
	AUTOR : FELIPPE M.
	DESCRI��O : APLICA��O DOS CONCEITOS B�SICOS DE ESTRUTURA DE DADOS : BUSCA SEQUENCIAL
	...
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>


int main(){
	setlocale(LC_ALL,"PORTUGUESE");
	
	int i,busca_fila[5] = {0,10,2,1,2},num;
	int localizado[5]={};
	int indice=0;	
	
	/*
		busca_fila[5] = vetor principal / armazena todos valores
		
		localizado[5] = vetor auxiliar / ir� receber as posi��es dos elementos localizados
		
		indice = ser� utilizado para incrementar as posi��es do vetor "localizado".
		Ou seja, se o n�mero for localizado 2x, indice ser� = 2. 
		Portanto, o vetor auxiliar ir� ter duas op��es = localizado[indice] / localizado[0] e localizado[1]
	*/
	
	printf("QUAL N�MERO VOC� DESEJA PESQUISAR : ");
	scanf("%i",&num);
	for(i=0;i<5;i++){//percorre o vetor inteiro
		if(num == busca_fila[i]){//condicional de compara��o
			localizado[indice] = i;
			indice++;
			/*
				caso num == busca_fila[i]
				A sua primeira posi��o [0](indice)..., ir� receber a posi��o do elemento localizado.
				
				Por exemplo, o elemento 2 ocorre 2x no vetor. 
				Logo, localiza[indice = 0] = 2 (posi��o do 1 elemento) e localiza[1=indice] = 4 (posi��o do 2 elemento) 
				
				E, em seguida, iremos incrementar o indice++, que ir� valer 2 que, por consequ�ncia, ir� fazer
				o vetor localiza ter duas posi��es, conforme j� explicado
			
			*/
		}
	}
	if(indice>0){
		for(i=0;i<indice;i++){
			printf("INDICE : [%i] -> %i\n",localizado[i],busca_fila[localizado[i]]);
			//exibe o indice armazenado no vetor auxiliar e seu elemento
		}
	}else{
		printf("VALOR N�O LOCALIZADO");
	}
}
