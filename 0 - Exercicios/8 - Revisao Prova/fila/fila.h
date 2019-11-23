#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct dado
{
    int numero;
};

typedef struct filaEstatica FilaE;
typedef struct filaDinamica FilaD;

FilaE * cria_FilaE();
void libera_fila(FilaE * fi);
int tamanho_fila(FilaE * fi);
int Fila_cheia(FilaE * fi);
int Fila_vazia(FilaE * fi);

int fura_fila(FilaE * fi, struct dado d);

FilaD * cria_FilaD();
void libera_fila(FilaD * fi);
int tamanho_fila(FilaD * fi);
int Fila_cheia(FilaD * fi);
int Fila_vazia(FilaD * fi);

int fura_fila(FilaD * fi, struct dado d);

