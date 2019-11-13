#include "no.h"

typedef struct fila Fila;

Fila * cria_fila ();

int fila_vazia (Fila *);

int remove_elemento (int *, Fila *);

int insere_elemento (int, Fila *);

int tamanho_fila (Fila *);

void mostra_fila (Fila *);
