#include "no.h"

typedef struct pilha Pilha;

Pilha * cria_pilha ();

//int pilha_cheia(Pilha *); --> não faz sentido

int pilha_vazia (Pilha *);

int push (int, Pilha *);
int pop (int *, Pilha *);

int tamanho_pilha (Pilha *);
int consulta_topo (Pilha *);
void mostra_pilha (Pilha *);
