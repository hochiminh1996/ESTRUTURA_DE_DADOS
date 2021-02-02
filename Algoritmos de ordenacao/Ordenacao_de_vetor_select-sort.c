/*
	ALGORITMO BÁSICO : VETORES
	AUTOR : FELIPPE M	
	DESCRIÇÃO : ORDENAÇÃO DOS ELEMENTOS DO VETOR PELO MÉTODO SELECTION SORT
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define N 5 //quantidade de elementos

void select_sort(int lista[]){
	int min_index=0,i=0,j=0, aux=0;
//50,1,20
//[0][1][2]
	for(j=0;j<N;j++){
		min_index = j;//Será o indice para identificar o menor valor. Ele já inicia com o valor de J para efeito de compraraçao 
		for(i=j;i<N;i++){//irá irá validar posição por posição
			//a validação das posições se dá em função de i=j 
			if(lista[i]<lista[min_index]){
				min_index = i;//10<50 = 10
				//verifica a posição do menor elemento do vetor
			}
			if(lista[j]>lista[min_index]){//50[0] > 1[1] = true
			//Se o elemento na posição [j] for maior que o elemento de [min_index]	
				aux = lista[j];// 50[0]
				//Armazena o maior valor até em então em aux.
				//[0] = 1
				lista[j] = lista[min_index];// Troca : A posição do 50 = [0]  irá armazenar o 1
				lista[min_index] = aux;// Troca : A posição[1] que tinha o menor valor irá receber o maior[1] = 50
				//[1] = 50
			}	

		}
	}
}

void exibir_origina(int lista[]){
	int i;
	printf("DESORDENADO:\n");
	for(i=0;i<N;i++){
		printf("%i ",lista[i]);
	}
		printf("\n\n");

}


void exibir(int lista[]){
	int i;
	printf("ORDENAÇÃO:\n");
	for(i=0;i<N;i++){
		printf("%i ",lista[i]);
	}
}
int main(){
	setlocale(LC_ALL,"PORTUGUESE");

	int lista[N] = {50,1,5,10,2};
	exibir_origina(lista);//mostra o vetor original

	select_sort(lista);//realiza a organização via select_sort
	
	exibir(lista);//exibe o vetor organizado	
	
}
