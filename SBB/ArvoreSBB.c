#include "ArvoreSBB.h"

void incializa (Apontador *pNo)
{
	*pNo = NULL;
}

void EE(Apontador *Ap)
{
	Apontador Ap1;

    Ap1 = (*Ap)->esq;
    (*Ap)->esq = Ap1->dir;
    Ap1->dir = *Ap;
    Ap1->bitE = Vertical;
    (*Ap)->bitE = Vertical;
    *Ap = Ap1;
}

void ED (Apontador *Ap)
{
    Apontador Ap1, Ap2;

    Ap1 = (*Ap)->esq;
    Ap2 = Ap1->dir;
    Ap1->bitD = Vertical;
    (*Ap)->bitE = Vertical;
    Ap1->dir = Ap2->esq;
    Ap2->esq = Ap1;
    (*Ap)->esq = Ap2->dir;
    Ap2->dir = *Ap;
    *Ap = Ap2;
}

void DD (Apontador *Ap)
{
    Apontador Ap1;

    Ap1 = (*Ap)->dir;
    (*Ap)->dir = Ap1->esq;
    Ap1->esq = *Ap;
    Ap1->bitD = Vertical;
    (*Ap)->bitD = Vertical;
    *Ap = Ap1;
}

void DE (Apontador *Ap)
{
    Apontador Ap1, Ap2;

    Ap1 = (*Ap)->dir;
    Ap2 = Ap1->esq;
    Ap1->bitE = Vertical;
    (*Ap)->bitD = Vertical;
    Ap1->esq = Ap2->dir;
    Ap2->dir = Ap1;
    (*Ap)->dir = Ap2->esq;
    Ap2->esq = *Ap;
    *Ap = Ap2;
}

void insere (int reg, Apontador *p)
{
    short fim;
    TipoInclinacao pi;
    Iinsere (reg, p, &pi, &fim);
}

void Iinsere (int reg, Apontador *Ap, TipoInclinacao *IAp, short *fim)
{
    if(*Ap == NULL)
    {
        *Ap = (Apontador) malloc(sizeof(TipoNo));
        *IAp = Horizontal;
        (*Ap)->registro = reg;
        (*Ap)->bitE = Vertical;
        (*Ap)->bitD = Vertical;
        (*Ap)->esq = NULL;
        (*Ap)->dir = NULL;
        *fim = FALSE;
        return;
    }
    if(reg < (*Ap)->registro)
    {
        Iinsere(reg, &(*Ap)->esq, &(*Ap)->bitE, fim);
        if(*fim)
            return;
        if((*Ap)->bitE != Horizontal)
        {
            *fim = TRUE;
            return;
        }
        if((*Ap)->esq->bitE == Horizontal)
        {
            EE(Ap);
            *IAp = Horizontal;
            return;
        }
        if((*Ap)->esq->bitD == Horizontal)
        {
            ED(Ap);
            *IAp = Horizontal;
        }
        return;
    }
    if(reg > (*Ap)->registro)
    {
        Iinsere(reg, &(*Ap)->dir, &(*Ap)->bitD, fim);
        if(*fim)
            return;
        if((*Ap)->bitD != Horizontal)
        {
            *fim = TRUE;
            return;
        }
        if((*Ap)->dir->bitD == Horizontal)
        {
            DD(Ap);
            *IAp = Horizontal;
            return;
        }
        if((*Ap)->dir->bitE == Horizontal)
        {
            DE(Ap);
            *IAp = Horizontal;
        }
    }
}

void pesquisa (int chave, Apontador *Ap)
{
    if(*Ap == NULL)
    {
        printf("Erro: registro nao encontrado!\n");
    }
    else if(chave > (*Ap)->registro)
    {
        pesquisa(chave, &(*Ap)->dir);
    }
    else if(chave < (*Ap)->registro)
        pesquisa(chave, &(*Ap)->esq);
    else
        printf("Chave encontrada!\n");
}

void imprime(Apontador Ap)
{
    if(Ap == NULL)
        return;
    imprime(Ap->esq);
    printf(" %d", Ap->registro);
    imprime(Ap->dir);
}

int contaAlturaVertical(Apontador Ap) {
    if(Ap == NULL) {
        return 0;
    } 
        
    if(Ap->bitE == Vertical) {
        return conta(Ap->esq) + 1;
    }

    if(Ap->bitD == Vertical) {
        return conta(Ap->dir) + 1;
    }
}