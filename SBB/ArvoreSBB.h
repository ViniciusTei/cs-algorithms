#ifndef ARVORESBB_H_INCLUDED
#define ARVORESBB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef enum {
    Vertical, Horizontal
} TipoInclinacao;

typedef struct TipoNo* Apontador;
typedef struct TipoNo {
    int registro;
    Apontador esq, dir;
    TipoInclinacao bitE, bitD;
} TipoNo;

void incializa (Apontador *pNo);
void EE(Apontador *Ap);
void ED (Apontador *Ap);
void DD (Apontador *Ap);
void DE (Apontador *Ap);
void insere (int reg, Apontador *p);
void Iinsere (int reg, Apontador *Ap, TipoInclinacao *IAp, short *fim);
void pesquisa (int chave, Apontador *Ap);
void imprime(Apontador Ap);

#endif // ARVORESBB_H_INCLUDED
