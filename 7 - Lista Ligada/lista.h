#include "no.h"

struct lista {
	struct no * prim;
};

struct lista * constroi_lista ();

int lista_vazia (struct lista *);

int insere_inicio (int, struct lista *);

void mostra_lista (const char *, struct lista *);

int insere_fim (int, struct lista *);

int remove_inicio(int *, struct lista *);

int remove_fim(int *, struct lista *);

//construir uma funcao que conta o numero de elementos da lista.
int quantidade_elementos (struct lista *);

float media_elementos (struct lista *);