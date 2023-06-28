#include "No.h"

int main()
{
    Apontador arvore;

    inicializa(&arvore);

    insere(&arvore, 'd');
    insere(&arvore, 'b');
    insere(&arvore, 'a');
    insere(&arvore, 'c');
    insere(&arvore, 'f');
    insere(&arvore, 'e');
    insere(&arvore, 'g');

    printf("Ordem: ");
    ordem(arvore);

    printf("\n");
    printf("PreOrdem: ");
    preordem(arvore);

    printf("\n");
    printf("PosOrdem: ");
    posordem(arvore);

    printf("\n");
    Pesquisa(&arvore, 'f');
    Pesquisa(&arvore, 'z');

    return 0;
}
