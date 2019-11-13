#include "fila.h"

struct fila {
	struct no * prim;
	struct no * ult;
	int tamanho;
};

Fila * cria_fila () {
	Fila * aux = (Fila *) malloc (sizeof(Fila));
	if (aux != NULL) {
		aux->prim = NULL; //estrutura que aux aponta, no campo prim...
		aux->ult = NULL;
		aux->tamanho = 0;
	}
	return aux; 
}

int fila_vazia (Fila *f) {
	if (f->tamanho == 0)
		return 1;
	return 0;
}

int insere_elemento (int i, Fila *f) {
	struct no * novo = constroi_no(i);
	if (novo != NULL) {
		if (fila_vazia(f)) {
			f->prim = novo;
		}
		else {
			f->ult->prox = novo;
		}
		f->ult = novo;
		f->tamanho++;
		return 1;
	}
	return 0;
}

int remove_elemento (int *i, Fila *f) {
	if (fila_vazia(f)) {
		return 0;
	}
	*i = f->prim->info;
	f->tamanho--;
	
	if (f->tamanho == 0) { //tinha um so, esvaziou a fila
		f->prim = NULL;
		f->ult = NULL;
	}
	else {
		f->prim = f->prim->prox;
	}
	return 1;
}

