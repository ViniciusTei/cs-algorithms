#include <stdlib.h>
#include "nLinhas.h"

void FLVazia(tLista *ptrLista)
{
    /*Cria uma celula cabeça para iniciar a lista
    e inicializa o contador de celulas com 0*/
    ptrLista->primeiro = (apontador) malloc(sizeof(tCelula));
    ptrLista->ultimo = ptrLista->primeiro;
    ptrLista->primeiro->prox = NULL;
    ptrLista->cont = 0;
}

int LeVazia(tLista *ptrLista)
{
    /*Retorna 1 se a ista estiver vazia
     *e 0 caso contrario. Faz duas verificações,
     *se o apontador primeiro for igual ao ultimo
     *significa q a lista esta vazia, ou se o
     *apontador proximo da primeira celula for nulo
     */
    if(ptrLista->primeiro == ptrLista->ultimo)
        return 1;//lista vazia
    else if(ptrLista->primeiro == NULL)
        return 1;//lista vazia
    else
        return 0;
}

void Insere(tLista *ptrLista, tItem Item) //insere um item NO FINAL da lista
{
    /*Insere um item no final da lista
     *criando uma nova celula e inserindo
     *o item nela, tbm incrementa o contador.
     *Sò insere um item caso ele não existir na
     *lista.
     */
    if(Verifica(ptrLista, Item) == 0)
    {
        ptrLista->ultimo->prox = (apontador) malloc(sizeof(tCelula));
        ptrLista->ultimo = ptrLista->ultimo->prox;
        ptrLista->ultimo->item = Item;
        ptrLista->ultimo->prox = NULL;
        (ptrLista->cont)++;
    }
}

int Verifica(tLista *ptrLista, tItem Item)
{
    /*Verifica se ja exista um item na lista
     *Cria um apontador aux que recebe a primeira
     *celula da lista. Percorre toda a lista usando
     *o apontador e verificando o seu item com os
     *itens ja presentes na lista
     */
    apontador Aux;
    Aux = ptrLista->primeiro->prox;

    //percorre a lista
    while(Aux != NULL)
    {
        if(Item.nlinhas == Aux->item.nlinhas)
            return 1;
        Aux = Aux->prox;
    }
    return 0;
}

void RemoverFinal(tLista *ptrLista)
{
    apontador Aux1, Aux2;

    Aux1 = ptrLista->ultimo;
    Aux2 = ptrLista->primeiro->prox;

    //verifica se a lista esta vazia
    if(LeVazia(ptrLista)==1)
        return;

    /*Caso a lista possuir apenas um item
    *retira a primeira celula
    */
    if(ptrLista->cont == 1)
    {
        ptrLista->ultimo = ptrLista->primeiro;
        ptrLista->primeiro->prox = NULL;
        free(Aux1);
        (ptrLista->cont)--;

    }
    else
    {
        /*Caso a lista possuir mais de um item
        *percorremos a lista ate a ultima celula
        *e a retiramos da lista
        */
        while(Aux2 != Aux1)
        {
            if(Aux2->prox == Aux1)
            {
                Aux2->prox == NULL;
                free(Aux1);
                (ptrLista->cont)--;
            }
            Aux2 = Aux2->prox;
        }
    }
}

int QtdLinhas(tLista *lista) //retorna a quantidade de linhas
{
    return(lista->cont);
}

void Imprime(tLista lista) //imprime os itens contidos na lista
{
    apontador Aux;

    Aux = lista.primeiro->prox;

    if(LeVazia(&lista) == 1)
        printf("Lista vazia!\n");
    else{
        while(Aux != NULL) //percorre a lista printando seus itens
        {
            printf("Linha: %d\n", Aux->item.nlinhas);
            Aux = Aux->prox;
        }
    }
}

void ApagaLista(tLista *pLista) //apaga lista inteira
{
    apontador AuxCelula, Aux;

    AuxCelula = pLista->primeiro; //faz receber celula cabeça

    while(AuxCelula != NULL) //percorre lista apagando do inicio para o final
    {
        Aux = AuxCelula;
        AuxCelula = AuxCelula->prox;
        free(Aux);
    }

    pLista->primeiro = NULL; //inicia primeiro com nulo
}

