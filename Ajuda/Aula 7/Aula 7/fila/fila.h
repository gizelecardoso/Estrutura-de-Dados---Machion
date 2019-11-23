#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct fila Fila;

Fila * cria_fila (int);

int fila_vazia (Fila *);

int fila_cheia (Fila *);

int remove_elemento (int *, Fila *);

int insere_elemento (int, Fila *);

int tamanho_fila (Fila *);

void mostra_fila (Fila *);

void mostra_vetor (Fila *);

int consulta_prim (Fila *);

int compara_fila (Fila *, Fila *);

int unifica_fila (Fila *, Fila *);

int inverte_fila (Fila *);

int soma_impar (Fila *);

int intercala_fila (Fila *, Fila *);
