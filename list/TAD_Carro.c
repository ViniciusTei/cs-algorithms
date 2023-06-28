#include <stdlib.h>
#include <stdio.h>
#include "TAD_Carro.h"

void CriaListaVazia(tLista *pLista) //cria uma lista vazia
{
    pLista->primeiro = inicio;
    pLista->ultimo = pLista->primeiro;
}

int VerificaListaVazia(tLista *pLista) //verifica se a lista esta vazia
{
    //funcao retorna 1 se a lista esta vazia e 0 caso contrario
    if(pLista->primeiro ==  pLista->ultimo)
        return 1;
    else
        return 0;
}

void insere(tCarro item, tLista *pLista) //insere item no final da lista
{
    if(pLista->ultimo == maxtam){
        printf("Lista cheia!\n");
        return;
    }
    if(VerificaListaVazia(pLista)== 1){
        pLista->carro[pLista->ultimo] = item;
        pLista->ultimo++;
    }
    else{
        pLista->carro[pLista->ultimo] = item;
        pLista->ultimo++;
    }
}

void retira(tLista *pLista, apontador posicao)
{
    int i;
    if((VerificaListaVazia(pLista)==1)||posicao>=pLista->ultimo){
        printf("Posicao nao existe\n");
        return;
    }
    for(i=posicao+1; i<pLista->ultimo; i++){
        pLista->carro[i-1] = pLista->carro[i];
    }
    pLista->ultimo--;
}

void imprime(tLista *pLista)
{
    int i;

    for(i=0; i<pLista->ultimo; i++){
        printf("item %d: \n", i+1);
        printf("modelo: %s\n", pLista->carro[i].modelo);
        printf("marca: %s\n", pLista->carro[i].marca);
        printf("ano: %d\n", pLista->carro[i].ano);
        printf("\n");
    }
}

void copia(tLista *pLista1, tLista *pLista2)
{
    *pLista2 = *pLista1;
}

void concatena(tLista *pLista1, tLista *pLista2, tLista *pLista3)
{
    int i;

    CriaListaVazia(pLista3);

    for(i=0; i<pLista1->ultimo; i++)
    {
        insere(pLista1->carro[i], pLista3);
    }

    for(i=0; i<pLista2->ultimo; i++)
    {
        insere(pLista2->carro[i], pLista3);
    }
}

void intercala(tLista *pLista1, tLista *pLista2, tLista *pLista3)
{
    int cont=0;
    int i, j=0;

    pLista3->ultimo = pLista1->ultimo + pLista2->ultimo;

    if(VerificaListaVazia(pLista1)==1 && VerificaListaVazia(pLista2)==1)
        return;

    if(pLista1->ultimo == pLista2->ultimo){
        for(i=0; i<pLista3->ultimo; i++){
            if(i%2 == 0){
                pLista3->carro[i] = pLista1->carro[j];
            }
            if(i%2 != 0){
                pLista3->carro[i] = pLista2->carro[j];
                j++;
            }
        }
    }
    //se um dia eu resolver voltar a mexer nisso faz uma ai pra caso uma lista for maior q a outra
}
