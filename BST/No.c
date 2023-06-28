#include "No.h"

void inicializa (Apontador *no)
{
    *no = NULL;
    //(*no)->altura = -1;
}

void insere (Apontador *no, char reg)
{
    if(*no == NULL)
    {
        *no = (Apontador) malloc(sizeof(No));
        (*no)->registro = reg;
        (*no)->dir = NULL;
        (*no)->esq = NULL;
        return;
    }
    if(reg < (*no)->registro)
    {
        insere(&(*no)->esq, reg);
        return;
    }
    if(reg > (*no)->registro)
    {
        insere(&(*no)->dir, reg);
    }
}

void Pesquisa (Apontador *no, char x)
{
    if((*no) == NULL)
    {
        printf("O registro %c nao existe!\n", x);
        return;
    }
    if(x < (*no)->registro)
    {
        Pesquisa(&(*no)->esq, x);
        return;
    }
    if(x > (*no)->registro)
    {
        Pesquisa(&(*no)->dir, x);
    }
    else
        printf("O registro %c existe!\n", x);
}

void ordem (Apontador p)
{
    if(p == NULL)
        return;
    ordem(p->esq);
    printf("%c ", p->registro);
    ordem(p->dir);
}

void preordem (Apontador p)
{
    if(p == NULL)
        return;
    printf("%c ", p->registro);
    preordem(p->esq);
    preordem(p->dir);
}

void posordem(Apontador p)
{
    if(p == NULL)
        return;
    posordem(p->esq);
    posordem(p->dir);
    printf("%c ", p->registro);
}
