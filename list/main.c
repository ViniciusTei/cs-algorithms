#include <stdio.h>
#include <stdlib.h>
#include "TAD_Carro.h"

int main()
{
    tLista lista, lista2, lista3;
    tCarro carro[3];
    int i;

    CriaListaVazia(&lista);

    for(i=0; i<3; i++){
        printf("Entre com o modelo do carro: ");
        scanf("%s", &carro[i].modelo);
        printf("Entre com a marca: ");
        scanf("%s", &carro[i].marca);
        printf("Entre com o ano: ");
        scanf("%d", &carro[i].ano);
    }

    insere(carro[0], &lista);
    insere(carro[1], &lista);
    insere(carro[2], &lista);

    copia(&lista, &lista2);

    intercala(&lista, &lista2, &lista3);

    //concatena(&lista, &lista2, &lista3);

    imprime(&lista3);
    /*printf("lista 1:\n");
    imprime(&lista);

    printf("Lista 2:\n");
    imprime(&lista2);*/

    return 0;
}
