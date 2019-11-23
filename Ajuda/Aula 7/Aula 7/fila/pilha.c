#include "pilha.h"

struct pilha {
	int *v;
	int topo;
	int capacidade;
};

Pilha * cria_pilha (int n) {
	Pilha * aux = (Pilha *) malloc (sizeof(Pilha));
	if (aux != NULL) {
		aux->v = (int *) malloc (n * sizeof(int));
		if (aux->v == NULL) {
			return NULL;
		}
		aux->topo = 0;
		aux->capacidade = n;
	}
	return aux;
}
int pilha_vazia (Pilha *p) {
	if (p->topo == 0)
		return 1;
	return 0;
	//return !p->topo; (Outra Opção)
}
int pilha_cheia (Pilha *p) {
	if (p->topo == p->capacidade)
		return 1;
	return 0;	
	//return p->topo == p->tamanho; (Outra Opção)
}
int push (int i, Pilha *p) { //Passagem de referência por valor.
	if (pilha_cheia(p))
		return 0;	
	p->v[p->topo] = i;
	p->topo++;
	//p->v[p->topo++] = i;
	return 1;
}
int pop (int *i, Pilha *p) { //i é um ponteiro de inteiro.
	if (pilha_vazia(p))
		return 0;	
	p->topo--;
	*i = p->v[p->topo]; //Operador de referência da variável i, a "caixinha" que i aponta.
	//*i = p->v[--p->topo];
	return 1;
}
//Ex.5:
int tamanho_pilha (Pilha *p){
	return p->topo;
}
int consulta_topo (Pilha *p){
	if (pilha_vazia(p))
		return -1;	
	return p->v[p->topo-1]; //a estrutura que p aponta no campo v | a estrutura que p aponta no campo p
}

/*
int consulta_topo2 (Pilha *p, int *ultimo){
	if(pilha_vazia(p))
		return 0;
	*ultimo = p->v[p->topo-1];
	return 1; //1 retorna sucesso
}
*/

void mostra_pilha (Pilha *p) {
	int i;
	printf("\n");
	
	for(i = p->topo-1; i >= 0; i--){
		printf("%d ", p->v[i]);
	}
	printf("\n");
	
}


//Ex.6:
int inserirPosicao(Pilha * p, int pos, int n){
    int i;
    if(pilha_cheia(p))
        return -1;
 
    if(pos > p->topo){
    	
        p->v[p->topo] = n;
        p->topo++;
        return 1;
    }

    for(i = p->topo; i < pos; i--)
        p->v[i] == p->v[++i];

    p->v[pos] = n;
    p->topo++;
    return 0;
}

int removerPosicao(Pilha * p, int pos){
    int i;
	if (pilha_vazia(p)) 
		return -1;

	if(pos > p->topo)
		return 0;

	for(i = pos; i <= p->topo; i++)
		p->v[i] = p->v[++i];
	
	 p->capacidade--;
}	
	
	
	
	
	

