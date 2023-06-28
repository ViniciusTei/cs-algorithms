#include <stdio.h>
#include <stdlib.h>
#define tam 5

void constroi(int *A, int *n)
{
    int esq;

    esq = *n/2 + 1;

    while(esq > 0)
    {
        esq --;
        refaz(esq, *n, A);
    }
}

void refaz(int esq, int dir, int *A)
{
    int j = esq*2;
    int aux = A[esq];

    while(j < dir)
    {
        if((j < dir)&&(A[j] < A[j+1]))
            j++;
        if(aux >= A[j])
            break;

        A[esq] = A[j];
        esq = j;
        j = esq*2;
    }
    A[esq] = aux;
}

void heapsort(int *A, int n)
{    int esq, dir;
    int aux;

    constroi(A, &n);

    esq = 0;
    dir = n;

    while(dir > 0)
    {
        aux = A[0];
        A[0] = A[dir];
        A[dir] = aux;
        dir--;
        refaz(esq, dir, A);
    }
}
int main()
{
    int A[tam] = {9, 8, 7, 6, 5};
    int i;

    printf("Vetor original: ");
    for(i = 0; i < tam; i++)
        printf("%d ", A[i]);

    printf("\n-----------------\n");

    heapsort(A, tam-1);

    printf("Vetor ordenado: ");
    for(i = 0; i < tam; i++)
        printf("%d ", A[i]);
    return 0;
}
