/*
	ALGORITMO : BUSCA
	AUTOR : FELIPPE M.
	DESCRIÇÃO : APLICAÇÃO DOS CONCEITOS BÁSICOS DE ESTRUTURA DE DADOS : BUSCA SEQUENCIAL
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
		
		localizado[5] = vetor auxiliar / irá receber as posições dos elementos localizados
		
		indice = será utilizado para incrementar as posições do vetor "localizado".
		Ou seja, se o número for localizado 2x, indice será = 2. 
		Portanto, o vetor auxiliar irá ter duas opções = localizado[indice] / localizado[0] e localizado[1]
	*/
	
	printf("QUAL NÚMERO VOCÊ DESEJA PESQUISAR : ");
	scanf("%i",&num);
	for(i=0;i<5;i++){//percorre o vetor inteiro
		if(num == busca_fila[i]){//condicional de comparação
			localizado[indice] = i;
			indice++;
			/*
				caso num == busca_fila[i]
				A sua primeira posição [0](indice)..., irá receber a posição do elemento localizado.
				
				Por exemplo, o elemento 2 ocorre 2x no vetor. 
				Logo, localiza[indice = 0] = 2 (posição do 1 elemento) e localiza[1=indice] = 4 (posição do 2 elemento) 
				
				E, em seguida, iremos incrementar o indice++, que irá valer 2 que, por consequência, irá fazer
				o vetor localiza ter duas posições, conforme já explicado
			
			*/
		}
	}
	if(indice>0){
		for(i=0;i<indice;i++){
			printf("INDICE : [%i] -> %i\n",localizado[i],busca_fila[localizado[i]]);
			//exibe o indice armazenado no vetor auxiliar e seu elemento
		}
	}else{
		printf("VALOR NÃO LOCALIZADO");
	}
}
