#include "Nota.h"

void inicializa (Apontador *p)
{
    *p = NULL;
}

void insere (Apontador *p, Aluno x)
{
    if(*p == NULL)
    {
        *p = (Apontador) malloc(sizeof(No));
        (*p)->registro = x;
        /*printf("\nNa insere:\n");
        printf("nome: %s\n", (*p)->registro.nome);
        printf("matricula: %d\n", (*p)->registro.matricula);
        printf("nota: %.1f", (*p)->registro.nota);*/
        (*p)->dir = NULL;
        (*p)->esq = NULL;
        return;
    }
    if(x.nota > (*p)->registro.nota)
    {
        insere(&(*p)->dir, x);
        return;
    }
    if(x.nota < (*p)->registro.nota)
        insere(&(*p)->esq, x);
}

/*variação do codigo ordem*/
void imprime (Apontador p)
{
    if(p == NULL)
        return;
    imprime(p->dir);
    printf("Nome: %s", p->registro.nome);
    printf("\n");
    printf("Matricula: %d", p->registro.matricula);
    printf("\n");
    printf("Nota: %.1f", p->registro.nota);
    printf("\n");
    printf("------------------\n");
    imprime(p->esq);
}

int contaalunos (Apontador p)
{
    if(p == NULL)
        return 0;
    else
        return 1 + contaalunos(p->esq) + contaalunos(p->dir);
}

int contamedia(Apontador p)
{
    if(p == NULL)
        return 0;
    if(p->registro.nota >= 12)
        return 1 + contamedia(p->dir) + contamedia(p->esq);
    else
        return 0 + contamedia(p->dir) + contamedia(p->esq);
}

/*Variação do cadigo do sucessor*/
void menorNota(Apontador p)
{
    if(p->esq != NULL)
    {
        menorNota(p->esq);
        return;
    }

    printf("    \n\nMenor nota:\n\n");
    printf("    Aluno: %s\n", p->registro.nome);
    printf("    Matricula: %d\n", p->registro.matricula);
    printf("    Nota: %.1f", p->registro.nota);
}

/*Variação do codigo do antecessor*/
void maiorNota(Apontador p)
{
    if(p->dir != NULL)
    {
        maiorNota(p->dir);
        return;
    }

    printf("    \n\nMaior nota:\n\n");
    printf("    Aluno: %s\n", p->registro.nome);
    printf("    Matricula: %d\n", p->registro.matricula);
    printf("    Nota: %.1f", p->registro.nota);
}

void abrearquivo(Apontador *p, char *nome, Aluno reg)
{
    FILE *arq;

    inicializa(&(*p));

    arq = fopen(nome, "r");

    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    else
    {
        while((fscanf(arq, "%f %s %d\n", &reg.nota, reg.nome, &reg.matricula)) != EOF)
        {
            insere(&(*p), reg);
        }
    }

    fclose(arq);
}
