#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct No *Apontador;
typedef struct No{
    char registro;
    int altura;
    Apontador esq;
    Apontador dir;
}No;

void inicializa(Apontador *no);
void insere (Apontador *no, char reg);
void ordem (Apontador p);
void Pesquisa (Apontador *no, char x);
void preordem (Apontador p);
void posordem(Apontador p);

#endif // NO_H_INCLUDED
