/*
	ALGORITMO BÁSICO : VETORES
	AUTOR : FELIPPE M		AUTOR : FELIPPE M
	DESCRIÇÃO : ORDENAÇÃO DOS ELEMENTOS DO VETOR PELO MÉTODO INSERTION SORT
*/
#define TAM 5  
#include <stdio.h> 
#include <locale.h>
  
void exibicao(int vet[]){
	int i;
	for(i=0;i<TAM;i++){
		printf("%i ",vet[i]);
	}
} 

void processamento(int n, int vet[]){
	int i,x,j;
	for (i = 1; i < n; i++){ 
        x = vet[i]; 
        j = i - 1; 

        while (j >= 0 && vet[j] > x) { 
            vet[j + 1] = vet[j]; 
            j = j - 1; 
        } 
        vet[j + 1] = x; 
    }
}

void saida(int vet[]){
	int i;
	printf("Saída   : ");
   	for(i=0;i<TAM;i++){
   		printf("%i ", vet[i]);	
	}
}

int main() 
{ 
	setlocale(LC_ALL,"PORTUGUESE");
    int vet[TAM] = { 40,30,20,10,0 },n=5; 
   
   
   	printf("***ORDENAÇÃO COM INSERTION SORT***\n\n");
   	//EXIBIÇÃO DO VETOR
   	printf("Entrada : ");
	exibicao(vet);   	
	
   	printf("\n");
   
    //PROCESSAMENTO
    processamento(n,vet);
    
    //SAIDA
   	saida(vet);
   	printf("\n");
   	
} 

