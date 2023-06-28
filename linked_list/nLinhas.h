#ifndef NLINHAS_H_INCLUDED
#define NLINHAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//estrutura de dados
typedef struct{
    int nlinhas; //armazena numero da linha
}tItem;

//celula
typedef struct tCelula *apontador; //para funcionar o nome dado a celula tem q ser igual (tCelula)
typedef struct tCelula {
    tItem item;
    apontador prox; //apontador para proxima celula
}tCelula;

//lista
typedef struct{
    apontador primeiro;
    apontador ultimo;
    int cont; //contador para numero de linhas
}tLista;


void FLVazia(tLista *ptrLista);
int LeVazia(tLista *ptrLista);
void Insere(tLista *ptrLista, tItem Item);
void RemoverFinal(tLista *ptrLista);
int QtdLinhas(tLista *lista);
void Imprime(tLista lista);
void ApagaLista(tLista *pLista);

#endif // NLINHAS_H_INCLUDED
