#include "lista_dupla.h"

struct lista_dupla * cria_lista_dupla() {
	struct lista_dupla * aux = (struct lista_dupla *) malloc (sizeof(struct lista_dupla));
	if (aux != NULL) {
		aux->prim = NULL;
	}
	return aux;
}

int lista_dupla_vazia (struct lista_dupla *l) {
	if (l->prim == NULL) {
		return 1;
	}
	return 0;
}

int insere_inicio_dupla (int i, struct lista_dupla *l) {
	struct no_duplo * novo = cria_no_duplo(i);
	if (novo != NULL) {
		if (!lista_dupla_vazia(l)) {
			novo->prox = l->prim;           //O primeiro vira o proximo do novo //O novo campo prox recebe o endereco do primeiro
			novo->ant = l->prim->ant;      //O ant do novo e o ultimo da lista (antes de prim) //O novo ant aponta para o ultimo
			novo->prox->ant = novo;       //Novo prox no campo ant recebe o novo
			novo->ant->prox = novo;      //Novo ant no campo prox recebe o novo
		}
		l->prim = novo;				   //Independente da situacao, o primeiro passa a ser o novo
		return 1;	
	}
	return 0;
}

int remove_inicio_dupla (int *i, struct lista_dupla *l) {
	struct no_duplo *aux;
	if (lista_dupla_vazia(l)) {
		return 0;
	}
	aux = l->prim;
	*i = l->prim->info;
	if (l->prim == l->prim->prox) {   //tinha um so (aponta pra ele mesmo)
		l->prim = NULL;
	}
	else {
		aux->prox->ant = aux->ant;
		aux->ant->prox = aux->prox;
		l->prim = l->prim->prox;
	}
	free(aux);
	return 1;
}

int insere_fim_dupla (int i, struct lista_dupla *l) {
	struct no_duplo * novo = cria_no_duplo(i);
	if (novo != NULL) {
		if (!lista_dupla_vazia(l)) {
			novo->prox = l->prim;           
			novo->ant = l->prim->ant;      
			novo->prox->ant = novo;       
			novo->ant->prox = novo;      
		}
		else {
			l->prim = novo;
		}
		return 1;	
	}
	return 0;
}

int remove_fim_dupla (int *i, struct lista_dupla *l) {
	struct no_duplo *aux;
	if (lista_dupla_vazia(l)) {
		return 0;
	}
	aux = l->prim->ant;
	*i = aux->info;                                        //inserir como print //remover como scan, por isso "int *i"
	if (l->prim == l->prim->prox) {   
		l->prim = NULL;
	}
	else {
		aux->prox->ant = aux->ant;
		aux->ant->prox = aux->prox;
	}
	free(aux);
	return 1;
}

void mostra_lista_dupla (const char *msg, struct lista_dupla *l) {
	struct no_duplo * aux;
	printf ("\n%s\n", msg);
	if (lista_dupla_vazia(l)) {
		printf ("\nLista Vazia\n");
	}
	else {
		aux = l->prim;
		do {
			printf ("%d ", aux->info);
			aux = aux->prox;
		} while (aux != l->prim);
	}
	printf ("\n");
}

int remove_por_endereco (struct no_duplo * aux, int * i, struct lista_dupla *l) {
	if (lista_dupla_vazia(l)) {
		return 0;
	}	
	
	*i = aux->info;
	
	if (l->prim == l->prim->prox) {    //tem um so
		l->prim = NULL;
	}
	else {
		aux->prox->ant = aux->ant;
		aux->ant->prox = aux->prox;
		if (aux == l->prim) {           //tem varios elementos, mas esta removendo o primeiro
			l->prim = l->prim->prox; 
		}
	}
	free(aux);
	return 1;
}

/*int insere_final_dupla (int i, struct lista_dupla *l) {
	struct no_duplo * novo = cria_no_duplo(i);
	if (novo != NULL) {
		
		if (lista_dupla_vazia(l)) {
			insere_inicio_dupla (i,l);
			return 1;
		}
		if (l->prim == l->prim->prox) {  //esse if não e necessario
			novo->prox = l->prim;
			novo->ant = l->prim;
			l->prim->prox = novo;
			l->prim->ant = novo;
			return 1;
		}
		novo->prox = l->prim;    //o novo no campo prox aponta para o primeiro da lista
		novo->ant = l->prim->ant; //o novo no campo ant aponta para o anterior do primeiro 
		novo->ant->prox = novo; //o campo proximo do anterior do novo aponta para o novo
		novo->prox->ant = novo; //o campo anterior do proximo do novo aponta para o novo
		return 1;	
	}
	return 0;
}

int remove_final_dupla (struct lista_dupla *l) {
	int i=0;
	if (lista_dupla_vazia(l)) {
		return 0;
	}
	
	i = l->prim->ant->info;
	if (l->prim == l->prim->prox) {   //tinha um so (aponta pra ele mesmo)
		i=l->prim->info;
		l->prim = NULL;
		return i;
	}
	
	l->prim->ant->ant->prox = l->prim;
	l->prim->ant = l->prim->ant->ant;
	return i;
}


void mostra_lista_dupla (struct lista_dupla *l) {
	struct no_duplo * aux;
	if (lista_dupla_vazia(l)) {
		printf ("\nLista Vazia\n");
		return 1;
	}
	aux = l->prim;
	
	do {
		printf ("%d ", aux->info);
		aux = aux->prox;	
	}
	while (aux != l->prim);
	printf("\n");
}
*/

//1) Remover um elemento da lista (Ex.: Elemento 7). Caso o elemento não esteja na lista devolver fracasso.
int remove_elemento_lista_dupla (int i, struct lista_dupla *l) {
	
	struct no_duplo * aux;
	aux = l->prim;
	int a;
	
	if (l->prim == l->prim->prox && aux->info == i) { 
		a = aux->info;
		l->prim = NULL;
		return a;
	}
	
	if (aux->info == i) {
		a = aux->info;
		aux->prox->ant = aux->ant;
		aux->ant->prox = aux->prox;
		l->prim = l->prim->prox;
		return a;
	} 
	
	do {
		aux = aux->prox;
		if (aux->info == i) {
			a = aux->info;
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
			return a;
		}
		} while (aux != l->prim);
		
	return 0;
}
//2) Remover todas as ocorrências de um elemento da lista. A função devolve quantos elementos foram removidos. (Dica: Fazer função de busca).

int remove_ocorrencia_lista_dupla (int i, struct lista_dupla *l) {
	
	struct no_duplo * aux;
	aux = l->prim;
	int cont = 0;
	
	if (aux == aux->prox && aux->info == i) {
		l->prim = NULL;
		return 1;
	}
	
	do {
	
		if (aux->info == i) {
			aux->prox->ant = aux->ant;
			aux->ant->prox = aux->prox;
			l->prim = l->prim->prox;	
			cont++;
		}
		aux = l->prim;
	
	} while (aux->info == i);
	
	do {
		if (aux->info == i ){
			aux->prox->ant = aux->ant;
			aux->ant->prox = aux->prox;
			cont++;
		}
		aux =aux->prox;
		
	} while (aux != l->prim);
		
	return cont;
}

int tamanho_lista_dupla (struct lista_dupla *l) {
	struct no_duplo * aux;
	int cont = 0;
	
	aux = l->prim;
	
	do { 
		cont++;
		aux = aux->prox;
	} while (aux != l->prim);		
	return cont;
}


//3) Remover um elemento de uma determinada posição. Se a posição for maior que o tamanho da lista, devolver fracasso. 

int remove_posicao_lista_dupla (int i, struct lista_dupla *l) {
	
	struct no_duplo * aux;
	aux = l->prim;
	int pos = 0;
	
	if (lista_dupla_vazia(l)) {
		return 0;
	}
	
	if (aux == aux->prox && i == 0) {
		l->prim = NULL;
		return 1;
	}
	
	if (i > tamanho_lista_dupla(l)) {
		return 0;
	}

	while (pos  < i) {   
		aux = aux->prox;
		pos++;
	}
	
	if (aux == l->prim) {
		aux->prox->ant = aux->ant;
		aux->ant->prox = aux->prox;
		l->prim = l->prim->prox;	
	} else {
		aux->prox->ant = aux->ant;
		aux->ant->prox = aux->prox;		
	}
		
	return 1;
}

//4) Inserir um elemento em uma determinada posição. Se a posição for maior que o tamanho da lista, continue contando.

int insere_posicao_lista_dupla (int i, int pos, struct lista_dupla *l) {
	struct no_duplo * novo = cria_no_duplo(i);
	struct no_duplo * aux;
	int cont = 0;
	
	if (lista_dupla_vazia(l)) {
		printf ("\nLista Vazia\n");
		return 0;
	}
	
	if (pos == 0) {
		insere_inicio_dupla (i,l);
		return 1;
	}
	
	aux = l->prim;
	
	while (cont < pos-1) {
		aux = aux->prox;
		cont++;
	}
	
	novo->prox=aux->prox;
	aux->prox->ant = novo;
	aux->prox = novo;
	novo->ant = aux;
	return 1;

}

//5) Inserir elementos na ordem topológica (Ex.: 1, 2, 3). Observação: Essa função só funciona quando os elementos estão na ordem.

int insere_ordem_lista_dupla (int i, struct lista_dupla *l) {
	struct no_duplo * aux;	
	int anterior;	 
	
	if (lista_dupla_vazia(l)) {
		insere_inicio_dupla (i,l);
	}

	aux = l->prim;
	while (aux->prox != l->prim){	
	
		if(aux->info > aux->prox->info) {
			return 0;
		} 
		aux = aux->prox;
	}	

	if (i > l->prim->ant->info) {
		insere_fim_dupla (i,l);	
		return 1;
	}
}


