#include "no.h"

struct no * constroi_no (int i) { //é uma E S T R E L A
	struct no * aux;
	aux = (struct no *) malloc (sizeof(struct no));
	if (aux) { //if (aux != NULL) é correto
		aux->info = i;
		aux->prox = NULL;
	}
	return aux;
}

