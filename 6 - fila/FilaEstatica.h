#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct  aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct fila Fila;

struct  fila
{
    int inicio, final, quantidade;
    struct aluno dados[MAX];
};

Fila* cria_fila();

void libera_fila(Fila* fila);

int tamanho_fila(Fila* fi);


