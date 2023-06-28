#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 5
typedef struct{
    char p[5];
}item;
int main()
{
    int i, j;
    item aux;
    item vetor[n];

    strcpy(vetor[0].p, "hasa");
    strcpy(vetor[1].p, "amor");
    strcpy(vetor[2].p, "doce");
    strcpy(vetor[3].p, "xuxa");
    strcpy(vetor[4].p, "zgua");

    for(i = 0; i < n; i++)
    {
        printf("%s ", vetor[i].p);
    }
    printf("\n");

    for(i = 1; i < n; i++)
    {
        aux = vetor[i];
        j = i-1;

        while(j>=0 && strcmp(vetor[j].p, aux.p) > 0)
        {
            vetor[j+1] = vetor[j];
            j = j-1;
            printf("Valor de j no while: %d\n", j);
        }
        vetor[j+1] = aux;
    }

    for(i = 0; i < n; i++)
    {
        printf("%s ", vetor[i].p);
    }
    return 0;
}
