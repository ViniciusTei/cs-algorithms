#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char *vetor, int n)
{
    ordena(0, n-1, vetor);
}

void ordena(int esq, int dir, char *vetor)
{
    int i, j;

    particao(esq, dir, &i, &j, vetor);

    if(j > esq)
        ordena(esq, j, vetor);
    if(i < dir)
        ordena(i, dir, vetor);
}

void particao(int esq, int dir, int *i, int *j, char *vetor)
{
    int pivo, aux;

    *i = esq;
    *j = dir;
    pivo = vetor[(*i + *j)/2];

    do
    {
        while(pivo > vetor[*i])
            (*i)++;
        while(pivo < vetor[*j])
            (*j)--;
        if(*i < j)
        {
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }while(*i < *j);
}

int main()
{
    int i;
    char vetor[5];

    strcpy(vetor, "total");
    printf("Vetor original: ");
    for(i = 0; i < 5; i++)
        printf("%c ", vetor[i]);

    quicksort(vetor, 5);

    printf("\n");
    printf("Vetor ordenado: ");
    for(i = 0; i < 5; i++)
        printf("%c ", vetor[i]);


    return 0;
}
