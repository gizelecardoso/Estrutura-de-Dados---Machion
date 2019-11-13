#include "pilha.h"

struct pilha{
	struct no * topo;
	int tamanho;
};

Pilha * cria_pilha() {
	Pilha * aux;
	aux = (Pilha *) malloc (sizeof(Pilha));
	if (aux) {
		aux->topo = NULL;
		aux->tamanho = 0;
	}
	return aux;
}

int pilha_vazia (Pilha *l) {
	if (l->topo == NULL) {
		return 1;
	}
	return 0;
}

int push (int i, Pilha *l) {
	struct no * novo = constroi_no (i);
	if (novo) {
		if (!pilha_vazia(l)) {
			novo->prox = l->topo;
		}
		l->topo = novo;
		l->tamanho++;
		return 1;
	}
	return 0;
}

void mostra_pilha (Pilha *l) {
	struct no * aux;
	if (pilha_vazia(l)) {
		printf("\npilha vazia");
	}
	else {
		aux = l->topo;
		while (aux != NULL) { 
			printf("%d ", aux->info);
			aux = aux->prox;
		}
	}
	printf("\n");
}

int pop (int *i, Pilha *l){
	struct no * aux;

	if(pilha_vazia(l)){
		return 0;
	} else{
		aux = l->topo;
		*i = aux->info;
		l->topo = aux->prox;
		l->tamanho--;
		free(aux);
		return 1;
	}
}

int tamanho_pilha (Pilha *l){
	return l->tamanho;
}

int consulta_topo (Pilha *l){

	if(pilha_vazia(l)){
		return -1;
	}

	return l->topo->info;
}


