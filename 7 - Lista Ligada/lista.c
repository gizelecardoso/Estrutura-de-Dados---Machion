#include "lista.h"

struct lista * constroi_lista() {
	struct lista * aux;
	aux = (struct lista *) malloc (sizeof(struct lista));
	if (aux) {
		aux->prim = NULL;
	}
	return aux;
}

int lista_vazia (struct lista *l) {
	if (l->prim == NULL) {
		return 1;
	}
	return 0;
	//return !l->prim; //youtube version
}
int insere_inicio (int i, struct lista *l) {
	struct no * novo = constroi_no (i);
	if (novo) {
		if (!lista_vazia(l)) {
			novo->prox = l->prim;
		}
		l->prim = novo;
		return 1;
	}
	return 0;
}
void mostra_lista (const char *msg, struct lista *l) {
	struct no * aux;
	printf("\n%s", msg);
	if (lista_vazia(l)) {
		printf("\nLista vazia");
	}
	else {
		aux = l->prim;
		while (aux != NULL) { //chega ao fim da lista
			printf("%d ", aux->info);
			aux = aux->prox;
		}
	}
	printf("\n");
}

int quantidade_elementos(struct lista *l){
	struct no * aux;

	aux = l->prim;
	int i = 0;
	while(aux != NULL){
		aux = aux->prox;
		i++;
	}
	return i;
}

float media_elementos(struct lista *l){
	struct no * aux;

	aux = l->prim;
	int i = 0;
	int soma = 0;
	while(aux != NULL){
		aux = aux->prox;
		i++;
		soma = soma + aux->info;
	}
	
	return (float)(soma/i);
}

int insere_fim (int i, struct lista * l) {
	struct no * novo = constroi_no (i);
	struct no * aux;
	if (novo) {
		if(lista_vazia(l)) {
			l->prim = novo;
		}
		else {
			aux = l->prim;
			while(aux->prox != NULL) { //chega ao ultimo da lista
				aux = aux->prox;
			}
			aux->prox = novo;
		}	
		return 1;
	}
	return 0;
}


int remove_inicio(int *i, struct lista *l){
	struct no * aux;

	if(lista_vazia(l)){
		return 0;
	} else{
		aux = l->prim;
		*i = aux->info;
		l->prim = aux->prox;
		free(aux);
		return 1;
	}
}

int remove_fim(int *i, struct lista *l){
	struct no * aux;

	if(lista_vazia(l)){
		return 0;
	}

	//se existe somente um elemento
	if(l->prim->prox == NULL){
		return remove_inicio(i, l);
	}

	//mais de um elemento - temos que percorrer e chegar no penultimo
	aux = l->prim;
	while(aux->prox->prox != NULL){
		aux = aux->prox;
	}

	*i = aux->prox->info;
	free(aux->prox);

	aux->prox = NULL;
	return 1;
}
