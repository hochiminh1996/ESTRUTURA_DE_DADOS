/*
	ALGORITMO : ORDENAÇÃO
	AUTOR : FELIPPE M	
	DESCRIÇÃO : ORDENAÇÃO DOS ELEMENTOS DO VETOR PELO MÉTODO QUICK SORT
*/

#include <stdio.h>
#include <stdlib.h>

int particao(int v[], int inicio, int fim)
{
    int i, aux;
    int muro = inicio; //posição do elemento "muro"
    int pivo = fim; //posição do elemento pivô
    for(i = inicio; i < pivo; i++)
    {
        if(v[i] <= v[pivo])
        {
            aux = v[i];
            v[i] = v[muro];
            v[muro] = aux;
            muro++;
        }
    }
    //trocar o pivô com o muro (muro vira o novo pivô)
    aux = v[pivo];
    v[pivo] = v[muro];
    v[muro] = aux;
    return muro; //retorna a posição do elemento pivô (que é o muro porque eles trocaram de lugar!)
}

void quickSort(int v[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int pos = particao(v, inicio, fim); //faz a partição e retorna o a posição do pivô em seu lugar final
        quickSort(v, inicio, pos - 1);
        quickSort(v, pos + 1, fim);
    }
}

void impressao(int v[])
{
    int i;
    for(i = 0; i < 10; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int vetor[10] = {23, 95, 77, 11, 84, 40, 62, 5, 58, 31};
    quickSort(vetor, 0, 9);
    impressao(vetor);
    return 0;
}
