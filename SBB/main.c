#include "ArvoreSBB.h"

int main()
{
    Apontador x;

    incializa(&x);

    insere(7, &x);
    insere(10, &x);
    insere(5, &x);
    insere(2, &x);
    insere(4, &x);
    insere(9, &x);
    insere(3, &x);
    insere(6, &x);

    imprime(x);

    printf("\n");
    pesquisa(1, &x);
    pesquisa(7, &x);

    return 0;
}
