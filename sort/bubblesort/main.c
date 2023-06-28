#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char palavra[50];
}tpalavra;

int main()
{
    char aux[50];
    tpalavra vetor[10];
    int i, j;

    for(i=0;i<10;i++){
        printf("String %d: ", i);
        fgets(vetor[i].palavra, 50, stdin);
    }

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(strcmp(vetor[i].palavra, vetor[j].palavra)<0){
                strcpy(aux, vetor[i].palavra);
                strcpy(vetor[i].palavra, vetor[j].palavra);
                strcpy(vetor[j].palavra, aux);
            }
        }
    }

    printf("Strings ordenadas: \n");

    for(i=0;i<10;i++){
        printf("String %d: %s", i, vetor[i].palavra);
    }

return(0);
}

