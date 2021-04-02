/*
	ALGORITMO : �RVORE BIN�RIA
	AUTOR : FELIPPE M.
	DESCRI��O : APLICA��O DOS CONCEITOS B�SICOS DE ESTRUTURA DE DADOS : PR�-ORDEM/EM ORDEM/P�S-ORDEM
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Arvore{
	int dado;
	struct Arvore *esq,*dir;
}arvore;


int main(){
	setlocale(LC_ALL,"PORTUGUESE");

	int opt,num;
	arvore *pont_arvore = NULL; // INICIALIZA COM NULL O PONTEIRO
	do{
        printf("*************************************************\n\n");
        printf("ESTRUTURA DE DADOS -> INSTITUTO FEDERAL/SP\n");
        printf("�RVORE BIN�RIA: PR�-ORDEM | EM ORDEM | P�S-ORDEM\n");
        printf("FEITO NA LINGUAGEM C\n\n");
        printf("*************************************************\n\n");
        printf("1) INSERIR ELEMENTOS\n2) EXIBIR �RVORE\n3) LIMPAR �RVORE\n4) BUSCAR ELEMENTO\n5) SAIR\n");
        scanf("%d",&opt);
       
	    switch(opt){
        	case 1: 
				printf("\nDIGITE O ELEMENTO A SER INSERIDO : ");
				scanf("%d", &num);
				
				inserir(&pont_arvore,num);//fornece 
    		
			break;
        
			case 2:	mostrar(pont_arvore);
        	break;
        
        	case 3: 
       			 pont_arvore = NULL; // atribui null para 'zerar'
       			 printf("\n***�RVORE ZERADA***\n\n");
       			 system("pause");
				system("cls");
			break;
			
			case 4:
				//incompleto
			break;
			case 5: 
			printf("SAINDO...");
			break;
        	
			default: printf("\nOP��O INV�LIDA...\n\n");
				system("pause");
				system("cls");
        	break;
        }
	}while(opt!=5);
	free(pont_arvore);
}

int inserir(arvore **pont_arvore,int num){//PONT DE PONT
	
		if(*pont_arvore==NULL){
			
			*pont_arvore = (arvore *)malloc(sizeof(arvore));
			
			(*pont_arvore)->dado = num;//o
			(*pont_arvore)->esq = (*pont_arvore)->dir = NULL;
			
			if(*pont_arvore!=NULL){
				printf("\nVALOR INSERIDO : %i\n\n",(*pont_arvore)->dado);//(*pont_arvore)-> retorna o valor inserido
				system("pause");
				system("cls");
			}
		}else{
			if(num<(*pont_arvore)->dado){//menor
				inserir(&((*pont_arvore)->esq),num);
			}else if(num>(*pont_arvore)->dado){//maior
				inserir(&((*pont_arvore)->dir),num);
			}else if(num==(*pont_arvore)->dado){//igual
				printf("\n***VALOR J� INSERIDO***\n\n");
				system("pause");
				system("cls");
			}
				
		}
}

int mostrar(arvore *pont_arvore){
	int i;
	
//	printf("%i",*pont_arvore->dado);
	
	if(pont_arvore!=NULL){
		printf("\nPR�-ORDEM : ");
		pre_ordem(pont_arvore);
		printf("\n");
		
		printf("\nEM ORDEM  : ");
		em_ordem(pont_arvore);
		
		printf("\n");
		
		printf("\nP�S-ORDEM : ");
		pos_ordem(pont_arvore);
		
		printf("\n");
		printf("\n");
		
		system("pause");
		system("cls");
		
	}
	else{
		printf("\n***�RVORE VAZIA***\n\n");
		system("pause");
		system("cls");
	}
}


/*
	EXIBI��O RECURSIVA PR�-ORDEM
	1 ) EXIBE
	2 ) ESQUERDA
	3 ) DIREITA	
*/
int pre_ordem (arvore *pont_arvore){
	if(pont_arvore!=NULL){
		printf("%i ",pont_arvore->dado);
		pre_ordem(pont_arvore->esq);
		pre_ordem(pont_arvore->dir);
	}
}


/*
	EXIBI��O RECURSIVA EM ORDEM
	1 ) ESQUERDA
	2 ) EXIBE
	3 ) DIREITA	
*/
int em_ordem (arvore *pont_arvore){
	if(pont_arvore!=NULL){
		em_ordem(pont_arvore->esq);
		printf("%i ",pont_arvore->dado);
		em_ordem(pont_arvore->dir);
	}
}


/*
	EXIBI��O RECURSIVA P�S-ORDEM
	1 ) ESQUERDA
	2 ) DIREITA
	3 ) EXIBE	
*/
int pos_ordem (arvore *pont_arvore){
	if(pont_arvore!=NULL){
		pos_ordem(pont_arvore->esq);
		pos_ordem(pont_arvore->dir);
		printf("%i ",pont_arvore->dado);
	}
}

