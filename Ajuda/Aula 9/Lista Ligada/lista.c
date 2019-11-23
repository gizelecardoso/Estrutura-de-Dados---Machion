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
	struct no * novo = constroi_no(i);
	if (novo) {
		if (!lista_vazia(l)) {
			novo->prox = l->prim;
		}
		l->prim = novo;
		return 1;
	}
	return 0;
}
void mostra_lista (const char * msg, struct lista *l) {
	struct no * aux;
	printf ("\n%s: ", msg);
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
int insere_fim (int i, struct lista * l) {
	struct no * novo = constroi_no(i);
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

int remove_inicio (int *i, struct lista *l) {
	struct no * aux;
	if (lista_vazia(l)) {
		return 0;
	}
	aux = l->prim;
	*i = aux->info;
	l->prim = aux->prox;
	free(aux);
	return 1;
}

int remove_fim (int *i, struct lista *l) {
	struct no * aux;
	if (lista_vazia(l)) {
		return 0;
	}
	if (l->prim->prox == NULL) { //tem um elemento só
		return remove_inicio(i,l);
	}
	aux = l->prim;
	while (aux->prox->prox != NULL) {
		aux = aux->prox;
	}
	*i = aux->prox->info;
	free(aux->prox);
	aux->prox = NULL;
	return 1;
}

int elementos_lista (struct lista *l) {
	int cont = 0;
	struct no * aux;
	if (lista_vazia(l)) {
		return 0;
	}
	aux = l->prim;
	while (aux != NULL) {
		aux = aux->prox;
		cont = cont+1;
	}
	return cont;
}

int elementos_media (struct lista *l) {
	int cont = 0, soma = 0;
	struct no * aux;
	aux = l->prim;
	while (aux != NULL) {
		soma += aux->info;
		aux = aux->prox;
		cont = cont+1;
	}
	return (float) soma/cont;
}

int insere_posicao (int i, int pos, struct lista *l) {
	struct no * novo = constroi_no(i);
	struct no * aux;
	struct no * aux2;
	int cont = 0;
	
	if (novo) {
		
		if (lista_vazia(l)) {
			insere_inicio (i, l);
			return 1;
		}
		
		if (pos > elementos_lista(l)) {
			insere_fim (i, l);
			return 1;
		}
		
		aux = l->prim;
		
		while (cont < pos - 1) {
			aux = aux->prox;
			cont++;
		}
		
		aux2 = aux->prox;
		aux->prox = novo;
		novo->prox = aux2;
	}
	return 1;	
}

int remove_posicao (int pos, struct lista *l) {
	struct no * aux;
	struct no * aux2;
	struct no * aux3;
	int* i;
	int cont = 0;
	
	if ((lista_vazia(l)) || (pos > elementos_lista(l))) {
		return 0;
	}
	
	if (l->prim->prox == NULL) {
		aux = l->prim;
		free (aux);
		return 1;
	}
	
	if (pos == (elementos_lista(l)-1)) {
		aux = l->prim;
		while (aux->prox->prox != NULL) {
			aux = aux->prox;
		}	
		*i = aux->prox->info;
		free(aux->prox);
		aux->prox = NULL;
		return 1;
	}
	
	aux = l->prim;
	
	while (cont < pos) {
		aux2 = aux;
		aux = aux->prox;
		cont++;
	}
	aux3 = aux->prox;
	printf ("aux3 prox %d\n", aux3->info);
	free(aux);
	aux2->prox = aux3;
}

int remove_elemento (int i, struct lista *l) {
	struct no * aux;
	struct no * aux2;
	struct no * aux3;
	int cont = 0;
	
	if (lista_vazia(l)) {
		return 0;
	}

	aux = l->prim;
	
	if (aux->info == i && aux->prox == NULL) {
		remove_fim(i,l);
		return 1;
	}
	
	if (l->prim->prox == NULL) {
		return 0;
	}

	while (i != aux->info) {
		aux2 = aux;
		aux = aux->prox;
		cont++;
	}
	
	aux3 = aux->prox;
	free(aux);
	aux2->prox = aux3;
}

int verifica_elemento (int i, struct lista *l) {
	struct no * aux;
	int cont = 0;
		
	if (lista_vazia(l)) {
		return 0;
	}
	
	aux = l->prim;
	
	while (cont <= elementos_lista(l)) {
		if (i == aux->info) {
			return 1;
		}
		aux = aux->prox;
		cont++;
	}
}

int remove_ocorrencia (int i, struct lista *l) {
	struct no * aux;
	struct no * aux2;
	struct no * aux3;
	int cont = 0;
	int valor = 0;
	
	if (lista_vazia(l)) {
		return 0;
	}

	aux = l->prim;
	
	if (aux->info == i && l->prim->prox == NULL) {
		free (aux);
		return 1;
	}
	
	if (l->prim->prox == NULL) {
		return 0;
	}
	
	remove_fim (&valor,l);
	
	if (valor != i) {
		insere_fim(valor, l);
	}
	
	while (cont < elementos_lista(l)) {
		if (i == aux->info) {
			aux3 = aux->prox;
			free(aux);
			aux = aux3; 
			aux2->prox = aux3;
		}	
		else {
			aux2 = aux;
			aux = aux->prox;
		}
	cont++;				
	}
	return 1;
}

/*Anotacoes:

int remove_posicao (int pos, struct lista *l) {
	struct no * aux;
	struct no * aux2;
	struct no * aux3;
	int* i;
	int cont = 0;
	
	if ((lista_vazia(l)) || (pos > elementos_lista(l))) {
		return 0;
	}
	
	if (l->prim->prox == NULL) {
		aux = l->prim;
		free (aux);
		return 1;
	}
	
	if (pos == (elementos_lista(l)-1)) {
		aux = l->prim;
		while (aux->prox->prox != NULL) {
			aux = aux->prox;
		}	
		*i = aux->prox->info;
		free(aux->prox);
		aux->prox = NULL;
		return 1;
	}
	
	aux = l->prim;
	//7 5 3 2 10 4 6
	while (cont < pos) {
		aux2 = aux;
		//7 5 3 2
		printf ("aux2 %d\n", aux2->info);
		aux = aux->prox;
		//3 2 10 4
		printf ("aux prox %d\n", aux->info);
		cont++;
	}
	aux3 = aux->prox;
	//4 6
	printf ("aux3 prox %d\n", aux3->info);
	free(aux); //10 4 6
	aux2->prox = aux3;
	//7532 46
	//printf ("%d", aux->info);
	//l->prim = aux->prox;
	//free (aux);
}

int remove_elemento (int i, struct lista *l) {
	struct no * aux;
	struct no * aux2;
	struct no * aux3;
	int cont = 0;
	
	if (lista_vazia(l)) {
		return 0;
	}

	aux = l->prim;
	
	if (aux->info == i && l->prim->prox == NULL) {
		free (aux);
		return 1;
	}
	
	if (l->prim->prox == NULL) {
		return 0;
	}
	
	aux = l->prim; //retirar

	while (i != aux->info) {
		aux2 = aux;
		printf ("aux2 %d\n", aux2->info);
		aux = aux->prox;
		printf ("aux prox %d\n", aux->info);
		cont++;
	}
	
	if (aux->prox == NULL) {
		remove_fim (i,l);
		return 1;
	}
	
	aux3 = aux->prox;
	//4 6
	printf ("aux3 prox %d\n", aux3->info);
	free(aux); //10 4 6
	aux2->prox = aux3;
	//7532 46
	//printf ("%d", aux->info);
	//l->prim = aux->prox;
	//free (aux);
}
*/
