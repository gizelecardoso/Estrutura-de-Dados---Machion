#include "lista.h"

struct listaEstatica {
    int qtd;
    struct dado d[MAX];
};

struct listaElementoD {
    struct dado d;
    struct listaElementoD *prox;
};

struct listaElementoDu {
    struct dado d;
    struct listaElementoDu *ant;
    struct listaElementoDu *prox;
};

typedef struct listaElementoD ElemD;
typedef struct listaElementoDu ElemDu;

// Lista Sequencial Estática

ListaE * cria_listaE(){
    ListaE *li;
    li = (ListaE*) malloc (sizeof(ListaE));

    if(li != NULL){
        li->qtd = 0;
    }

    return li;
}

void libera_lista(ListaE *li){
    free(li);
}

int tamanho_lista(ListaE *li){
    if(li == NULL){
        return 0;
    } else{
        return li->qtd;
    }
}

int lista_cheia (ListaE *li){
    if(li == NULL){
        return 0;
    }

    return (li->qtd == MAX);
}

int lista_vazia (ListaE *li){
    if(li == NULL){
        return 0;
    }

    return (li->qtd == 0);
}

int insere_lista_final(ListaE *li, struct dado d){
    if(li == NULL){
        return 0;
    }

    if(lista_cheia(li)){
        return 0;
    }

    li->d[li->qtd] = d;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(ListaE *li, struct dado d){
    if(li == NULL){
        return 0;
    }

    if(lista_cheia(li)){
        return 0;
    }

    int i;
    for(i=li->qtd-1; i>=0; i--){
        li->d[i+1] = li->d[i];
    }

    li->d[0] = d;
    li->qtd++;
    return 1;
}

int insere_lista_ordenanda(ListaE *li, struct dado d){
    if(li == NULL){
        return 0;
    }

    if(lista_cheia(li)){
        return 0;
    }

    int k, i = 0;
    while(i<li->qtd && li->d[i].numero < d.numero){
        i++;
    }

    for(k=li->qtd-1; k>=i; k--){
        li->d[k+1] = li->d[k];
    }

    li->d[i] = d;
    li->qtd++;
    return 1;

}

int remove_lista_final(ListaE *li){
    if(li == NULL){
        return 0;
    }

    if(lista_vazia(li)){
        return 0;
    }

    li->qtd--;
    return 1;
}

int remove_lista_inicio(ListaE *li){
    if(li == NULL){
        return 0;
    }

    if(lista_vazia(li)){
        return 0;
    }

    int k;
    for(k = 0; k<li->qtd-1; k++){
        li->d[k] = li->d[k+1];
    }

    li->qtd--;
    return 1;
}

int remove_lista_ordenada(ListaE *li, int numero){
    if(li == NULL){
        return 0;
    }

    if(lista_vazia(li)){
        return 0;
    }

    int k, i = 0;
    while(i<li->qtd && li->d[i].numero != numero){
        i++;
    }

    if(i == li->qtd){
        return 0;
    }


    for(k = i; k<li->qtd-1; k++){
        li->d[k] = li->d[k+1];
    }

    li->qtd--;
    return 1;
}

int consulta_lista_pos(ListaE *li,int pos, struct dado *d){
    if(li == NULL || pos <= 0 || pos > li->qtd){
        return 0;
    }

    *d = li->d[pos-1];
    return 1;
}

int consulta_lista_mat(ListaE *li,int mat, struct dado *d){
    if(li == NULL){
        return 0;
    }

    int k, i = 0;

    while(i<li->qtd && li->d[i].numero != d){
        i++;
    }

    if(i == li->qtd){
        return 0;
    }

    *d = li->d[i];
    return 1;
}


//Lista Dinâmica Encadeada - Lista Ligada

ListaD * cria_listaD(){
    ListaD *li = (ListaD *) malloc(sizeof(ListaD));
    if(li != NULL){
        *li = NULL;
    }

    return li;
}

void libera_lista(ListaD *li){
    if(li != NULL){
        ElemD *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(ListaD *li){
    if(li == NULL){
        return 0;
    }
    
    int cont = 0;

    ElemD *no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia (ListaD *li){
    if(li == NULL){
        return 1;
    }

    if(*li == NULL){
        return 1;
    }

    return 0;
}

int insere_lista_final(ListaD *li, struct dado d){
    if(li == NULL){
        return 0;
    }

    ElemD *no = (ElemD *) malloc(sizeof(ElemD));

    if(no == NULL){
        return 0;
    }

    no->d = d;
    no->prox = NULL;

    if((*li) == NULL){
        *li = no;
    } else {
        ElemD *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(ListaD *li, struct dado d){
    if(li == NULL){
        return 0;
    }

    ElemD *no = (ElemD *) malloc(sizeof(ElemD));
    if(no == NULL){
        return 0;
    }

    no->d = d;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenanda(ListaD *li, struct dado d){
    if(li == NULL){
        return 0;
    }

    ElemD *no = (ElemD *) malloc(sizeof(ElemD));

    if(no == NULL){
        return 0;
    }

    no->d = d;

    if(lista_vazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    } else {
        ElemD *ant, *atual = *li;

        while(atual != NULL && atual->d.numero < d.numero){
            ant = atual;
            atual = atual->prox;
        }

        if(atual == *li){
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista_final(ListaD *li){
    if(li == NULL){
        return 0;
    }

    if((*li) == NULL){
        return 0;
    }

    ElemD *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li)){
        *li = no->prox;
    } else{
        ant->prox = no->prox;
    }

    free(no);
    return 1;
}

int remove_lista_inicio(ListaD *li){
     if(li == NULL){
        return 0;
    }

    if((*li) == NULL){
        return 0;
    }

    ElemD *no = *li;
    *li = no->prox;
    free(no);
    return 1; 
}

int remove_lista_ordenanda(ListaD *li, int d){
    if(li == NULL){
        return 0;
    }

    ElemD *ant, *no = *li;

    while(no != NULL && no->d.numero != d){
        ant = no;
        no = no->prox;
    }

    if(no == NULL){
        return 0;
    }

    if(no == *li){
        *li = no->prox;
    } else{
        ant->prox = no->prox;
    }

    free(no);
    return 1;
}

int consulta_lista_pos(ListaD *li,int pos, struct dado *d){
    if(li == NULL || pos <= 0){
        return 0;
    }

    ElemD *no = *li;

    int i = 1;
    while(no != NULL && i<pos){
        no = no->prox;
        i++;
    }

    if(no == NULL){
        return 0;
    } else{
        *d = no->d;
        return 1;
    }
}

int consulta_lista_mat(ListaD *li,int mat, struct dado *d){
    if(li == NULL){
        return 0;
    }
    ElemD *no = *li;
    while(no != NULL && no->d.numero != d){
        no = no->prox;
    }

    if(no == NULL){
        return 0;
    } else {
        *d = no->d;
        return 1;
    }
}


//Lista Dinâmica Duplamente Ligada

ListaDu * cria_listaDu(){
    ListaDu *li = (ListaDu *) malloc(sizeof(ListaDu));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void libera_lista(ListaDu *li){
    if(li != NULL){
        ElemDu *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        } 
        free(li);
    }
}

int tamanho_lista(ListaDu *li){
    if(li == NULL){
        return 0;
    }
    int cont = 0;
    ElemDu *no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia (ListaDu *li){
    if(li == NULL){
        return 1;
    }

    if(*li == NULL){
        return 1;
    }

    return 0;
}

int insere_lista_final(ListaDu *li, struct dado d){
    if(li == NULL){
        return 0;
    }

    ElemDu *no = (ElemDu *) malloc(sizeof(ElemDu));

    if(no == NULL){
        return 0;
    }

    no->d = d;
    no->prox = NULL;

    if(*li == NULL){
        no->ant = NULL;
        *li = no;
    } else {
        ElemDu *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_inicio(ListaDu *li, struct dado d){
    if(li == NULL){
        return 0;
    }

    ElemDu *no = (ElemDu *) malloc(sizeof(ElemDu)); 

    if(no == NULL){
        return 0;
    }

    no->d = d;
    no->prox = (*li);
    no->ant = NULL;

    if(*li == NULL){
        (*li)->ant = no;
    }
    *li = no;
    return 1;
}

int insere_lista_ordenanda(ListaDu *li, struct dado d){
    if(li == NULL){
        return 0;
    }

    ElemDu *no = (ElemDu *) malloc(sizeof(ElemDu));

    if(no == NULL){
        return 0;
    }

    no->d = d;
    no->prox = NULL;

    if(*li == NULL){
        no->ant = NULL;
        *li = no;
    } else {
        ElemDu *ante, *atual = *li;
        while(atual != NULL && atual->d.numero < d.numero){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;

            if(atual != NULL){
                atual->ant = no;
            }
        }
    }
    return 1;
}

int remove_lista_final(ListaDu *li){
    if(li == NULL){
        return 0;
    }

    if((*li) == NULL){
        return 0;
    }

    ElemDu *no = *li;

    if(no->prox != NULL){
        no =  no->prox;
    }

    if(no->ant == NULL){
        *li = no->prox;
    } else{
        no->ant->prox = NULL;
    }
    free(no);
    return 0;
}

int remove_lista_inicio(ListaDu *li){
     if(li == NULL){
        return 0;
    }

    if((*li) == NULL){
        return 0;
    }

    ElemDu *no = *li;
    *li = no->prox;

    if(no->prox != NULL){
        no->prox->ant = NULL;
    }
    free(no);
    return 0;
}

int remove_lista_ordenanda(ListaDu *li, int mat){
    if(li == NULL){
        return 0;
    }

    ElemDu *no = li;
    while(no != NULL && no->d.numero != mat){
        no = no->prox;
    }

    if(no == NULL){
        return 0;
    }

    if(no->ant == NULL){
        *li = no->prox;
    } else {
        no->ant->prox = no->prox;
    }

    if(no->prox != NULL){
        no->prox->ant = no->ant;
    }

    free(no);
    return 1;
}

int consulta_lista_pos(ListaDu *li,int pos, struct dado *d){
    if(li == NULL || pos <= 0){
        return 0;
    }

    ElemDu *no = *li;

    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }

    if(no == NULL){
        return 0;
    } else{
        *d = no->d;
        return 1;
    }
}

int consulta_lista_mat(ListaDu *li,int mat, struct dado *d){
    if(li == NULL){
        return 0;
    }

    ElemDu *no = *li;

    while(no != NULL && no->d.numero != mat){
        no = no->prox;
    }

    if(no == NULL){
        return 0;
    } else {
        *d = no->d;
        return 1;
    }
}

