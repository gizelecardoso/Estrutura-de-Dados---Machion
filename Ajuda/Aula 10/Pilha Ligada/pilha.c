#include "pilha.h"

struct pilha {
	struct no * topo;
	int tamanho; //desnecessário
};

Pilha * cria_pilha() {  //também pode chamar de struct pilha
	Pilha * aux;
	aux = (Pilha *) malloc (sizeof(Pilha));
	if (aux) {
		aux->topo = NULL;
		aux->tamanho = 0; //desnecessário - ver int tamanho 
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
	struct no * novo = constroi_no(i);
	if (novo) {
		if (!pilha_vazia(l)) {
			novo->prox = l->topo;
		}
		l->topo = novo;
		l->tamanho++; //desnecessário - ver infos acima
		return 1;
	}
	return 0;
}
void mostra_pilha (Pilha *l) {
	struct no * aux;
	if (pilha_vazia(l)) {
		printf("\nPilha vazia");
	}
	else {
		aux = l->topo;
		while (aux != NULL) { //chega ao fim da lista
			printf("%d ", aux->info);
			aux = aux->prox;
		}
	}
	printf("\n");
}
int pop (int *i, Pilha *l){
	struct no * aux;
	if (pilha_vazia(l)) {
		return 0;
	}
	aux = l->topo;
	*i = aux->info;
	l->topo = aux->prox;
	l->tamanho--; //desnecesario - vc ja sabe, ne
	free(aux);
	return 1;
}
/*int tamanho_pilha (Pilha *l) {
	struct no * aux;
	int cont = 0;
	aux = l->topo;
	while (aux != NULL) { //chega ao fim da lista
		cont = cont++;
		aux = aux->prox;
	}
	return cont;
}*/
int tamanho_pilha (Pilha *l) {
	return l->tamanho;
}
int consulta_topo (Pilha *l) {
	if (pilha_vazia(l)) {
		return -1;
	}
	return l->topo->info;
}
