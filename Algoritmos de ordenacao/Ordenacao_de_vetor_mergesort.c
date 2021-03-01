/*
	ALGORITMO : ORDENAÇÃO
	AUTOR : FELIPPE M	
	DESCRIÇÃO : ORDENAÇÃO DOS ELEMENTOS DO VETOR PELO MÉTODO MERGE SORT
*/


#include <stdlib.h>
#include <stdio.h>

int intercalacao(int v[], int inicio, int meio, int fim)
{
    int aux[fim - inicio + 1];
    /*para cada intercalação, essa conta vai dizer quantas posições o aux
    precisa no momento para salvar o que vai ser intercalado.*/
    int esquerda = inicio;
    int direita = meio + 1; //meio + 1 porque o meio ainda é da primeira metade
    int i = 0; //indica a posição onde a carta vai entrar no vetor auxiliar

    while(esquerda <= meio && direita <= fim)
    {
        if(v[esquerda] <= v[direita])
        /*baixa a carta da esquerda e incrementa esquerda(variavel)
        e o i pra indicar a proxima posicao que vai ser colocado
        (colocar no vetor auxiliar com as novas posicoes, e depois colocar
         tudo do auxiliar no vetor que eu tava usando desde o começo*/
        {
            aux[i] = v[esquerda];
            esquerda++; //na próxima rodada eu analiso o próximo e.
            i++;
        }
        else
        /*baixa a carta da direita e incrementa direita(variavel)
        e o pos pra indicar a proxima posicao (i) que a proxima carta vai ser colocada*/
        {
            aux[i] = v[direita];
            direita++;
            i++;
        }

    }
    while(esquerda <= meio)
    /*na situação onde todos as cartas da direita já terminaram, é só baixar as da esquerda*/
    {
        //baixa a carta esquerda e incrementa esquerda(variavel) e incrementa o i(posição).
        aux[i] = v[esquerda];
        esquerda++;
        i++;

    }
    while(direita <= fim)
    /*na situação onde todas as cartas da esquerda já terminaram, é só baixar as da direita*/
    {
        //baixa a carta direita e incrementa direita(variavel) e incrementa o i (posição).
        aux[i] = v[direita];
        direita++;
        i++;
    }

    //transportar os dados do vetor auxiliar de volta pro vetor vetor[].
    for(i = 0; i <= fim - inicio; i++)
        v[inicio + i] = aux[i]; //não pode ser só o i no v[] porque se não ele sempre vai sobreescrever na posição 0
        //por isso eu tenho que somar com o início.
        //ex: eu quero passar a posição 4 do aux pro vetor v, supondo que o inicio é 3, fica v[3+4] = aux[4]
        //i++, então v[3+5] = aux[5]
        //o início é uma faixa dependendo de quantas cartas ele tem na mão
        //ele pode ter o inicio daquela faixa da posicao 8, por isso não vai ser sempre zero...
}

void mergeSort(int v[], int inicio, int fim)
{
    int meio;
    if(inicio < fim)
    {
        meio = (inicio + fim)/2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        intercalacao(v, inicio, meio, fim);
        impressao(v);
    }
}

int impressao(int v[])
{
    int i;
    for(i = 0; i < 10; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int vetor[10] = {23, 95, 77, 11, 84, 40, 62, 5, 58, 31};
    mergeSort(vetor, 0, 9);
    return 0;
}
