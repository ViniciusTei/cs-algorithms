
#define maxtam 100
#define inicio 0

typedef int apontador;

typedef struct{
    char modelo[21];
    char marca[21];
    int ano;
}tCarro;

typedef struct{
    tCarro carro[maxtam];
    apontador primeiro, ultimo;
}tLista;



