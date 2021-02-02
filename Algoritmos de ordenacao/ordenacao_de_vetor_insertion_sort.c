/*
	ALGORITMO B�SICO : VETORES
	AUTOR : FELIPPE M		AUTOR : FELIPPE M
	DESCRI��O : ORDENA��O DOS ELEMENTOS DO VETOR PELO M�TODO INSERTION SORT
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
	printf("Sa�da   : ");
   	for(i=0;i<TAM;i++){
   		printf("%i ", vet[i]);	
	}
}

int main() 
{ 
	setlocale(LC_ALL,"PORTUGUESE");
    int vet[TAM] = { 40,30,20,10,0 },n=5; 
   
   
   	printf("***ORDENA��O COM INSERTION SORT***\n\n");
   	//EXIBI��O DO VETOR
   	printf("Entrada : ");
	exibicao(vet);   	
	
   	printf("\n");
   
    //PROCESSAMENTO
    processamento(n,vet);
    
    //SAIDA
   	saida(vet);
   	printf("\n");
   	
} 

