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
	struct no * aux;
	if (fila_vazia(f)) {
		return 0;
	aux = f->prim;	
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
	free(aux);
	return 1;
}

int tamanho_fila (Fila *f) {
	return f->tamanho;
}

void mostra_fila (Fila *f) {
	struct no * aux;
	printf ("\n");
	if (fila_vazia(f)) {
		printf ("Fila Vazia");
	}
	else {
		aux = f->prim;
		while (aux != NULL) {
			printf ("%d ", aux->info);
			aux = aux->prox;
		}
	}
	printf ("\n");
}
