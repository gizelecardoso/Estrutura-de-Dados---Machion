#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;

Pilha * cria_pilha (int); //tamanho do vetor que o usuário vai escolher

int pilha_cheia (Pilha *); 

int pilha_vazia (Pilha *);

int push (int, Pilha *); //Inserir um inteiro em uma pilha

int pop (int *, Pilha *); //Remover um inteiro em uma pilha

int tamanho_pilha (Pilha *);

int consulta_topo (Pilha *);

void mostra_pilha (Pilha *);

