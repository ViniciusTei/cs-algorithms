#ifndef NOTA_H_INCLUDED
#define NOTA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct Aluno{
    float nota;
    int matricula;
    char nome[24];
}Aluno;

typedef struct No *Apontador;
typedef struct No{
    Aluno registro;
    Apontador esq;
    Apontador dir;
}No;

void inicializa (Apontador *p);
void insere (Apontador *p, Aluno x);
void imprime (Apontador p);
int contaalunos (Apontador p);
void menorNota(Apontador p);
void maiorNota(Apontador p);
int contamedia(Apontador p);
void abrearquivo(Apontador *p, char *nome, Aluno reg);

#endif // NOTA_H_INCLUDED
