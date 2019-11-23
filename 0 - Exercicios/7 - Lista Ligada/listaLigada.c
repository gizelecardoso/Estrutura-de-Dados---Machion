#include "listaLigada.h"

struct componente{
    struct dado numero;
    struct componente *ant;
    struct componente *prox;
};

typedef struct componente Comp;

Lista * cria_lista(){
    Lista * li = (Lista *) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }

    return li;
}

void libera_lista(Lista * li){
    if(li != NULL){
        Comp * aux;
        while(*li != NULL){
            aux = *li;
            *li = (*li)->prox;
            free(aux);
        }
        free(li);
    }
}

int tamanho_lista(Lista * li){
    int cont = 0;
    Comp * aux = *li;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }

    return cont;
}

int lista_vazia(Lista * li){
    if(*li != NULL){
        return 0;
    }
    return 1;
}

int insere_lista_inicio(Lista * li, struct dado d){
    if(li == NULL){
        return 0;
    }

    Comp * no = (Comp *) malloc(sizeof(Comp));
    if(no == NULL){
        return 0;
    }

    no->numero = d;
    no->ant = NULL;
    no->prox = *li;

    if(*li == NULL){
        (*li)->ant = no;
    }

    *li = no;

    return 1;

}

int insere_lista_final(Lista * li, struct dado d){
    if(li == NULL){
        return 0;
    }
    Comp * aux = (Comp *) malloc(sizeof(Comp));
    if(aux == NULL){
        return 0;
    }

    aux->numero = d;
    aux->prox = NULL;

    if(*li == NULL){
        aux->ant = NULL;
        *li = aux;
    } else{
        Comp * noAux = *li;
        while(noAux->prox != NULL){
            noAux = noAux->prox;
        }

        noAux->prox = aux;
        aux->ant = noAux;
    }
    return 1;
}

int remove_lista_inicio (Lista *li){
    if(li == NULL){
        return 0;
    }

    if((*li) == NULL){
        return 0;
    }

    Comp * aux = *li;
    *li = aux->prox;

    if(aux->prox != NULL){
        aux->prox->ant = NULL;
    }
    free(aux);
    return 0;
}

int remove_lista_final (Lista *li){
    if(li == NULL){
        return 0;
    }
    if((*li) == NULL){
        return 0;
    }

    Comp * aux = *li;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    if(aux->ant == NULL){
        *li = aux->prox;
    } else{
        aux->ant->prox = NULL;
    }

    free(aux);
    return 1;
}

//1 - Remover um elemento da lista (Ex.: Elemento 7). Caso o elemento não esteja na lista devolver fracasso.

int remove_elemento_lista(Lista * li, int elemento){
    if(li == NULL){
        return 0;
    }

    Comp * aux = li;

    while(aux != NULL || aux->numero.numero  != elemento){
        aux = aux->prox;
    }

    if(aux == NULL){
        return 0;
    }

    if(aux->ant == NULL){
        *li = aux->prox;
    } else{
        aux->ant->prox = aux->prox;
    }

    if(aux->prox != NULL){
        aux->prox->ant= aux->ant;
    }

    free(aux);
    return 1;
}

//2 - Remover todas as ocorrências de um elemento da lista. 
//A função devolve quantos elementos foram removidos. (Dica: Fazer função de busca).

int remove_todosElemento_lista(Lista * li, int elemento){
    if(li == NULL){
        return 0;
    }

    Comp * aux = li;

    int cont = 0;

    while(aux != NULL){
        if(aux->numero.numero  == elemento){
            cont++;

            if(aux->ant == NULL){
                *li = aux->prox;
            } else{
                aux->ant->prox = aux->prox;
            }

            if(aux->prox != NULL){
                aux->prox->ant= aux->ant;
            }

            free(aux);
        }
        aux = aux->prox;
    }

    if(aux == NULL){
        return 0;
    }

    return cont;
}

//3 - Remover um elemento de uma determinada posição. 
//Se a posição for maior que o tamanho da lista, devolver fracasso.

int remove_elementoPosicao_lista(Lista * li, int posicao){
    if(li == NULL){
        return 0;
    }

    if(posicao > tamanho_lista(li)){
        return 0;
    }

    Comp * aux = li;

    int cont = 0;

    while(aux != NULL){
        if(cont == posicao){
            if(aux->ant == NULL){
                *li = aux->prox;
            } else{
                aux->ant->prox = aux->prox;
            }

            if(aux->prox != NULL){
                aux->prox->ant= aux->ant;
            }
            free(aux);
            return 1;
        }    
        aux = aux->prox;
    }

    if(aux == NULL){
        return 0;
    }
}

//4 - Inserir um elemento em uma determinada posição. 
//Se a posição for maior que o tamanho da lista, continue contando.

int insere_elementoPosicao_lista(Lista * li, int posicao, struct dado d){
    if(li == NULL){
        return 0;
    }

    Comp * aux = li;
    Comp * no = (Comp*) malloc(sizeof(Comp));

    int cont = 0;

    while(aux != NULL){
        if(cont == posicao){
            if(aux->ant == NULL){
                insere_lista_inicio(li, d);
            } else{
                no->numero = d;
                no->ant = aux->ant->prox;
                no->prox = aux->ant;
            } 
            return 1;
        }    
        aux = aux->prox;
    }

    if(aux == NULL){
        return 0;
    }
}

//5 - Inserir elementos na ordem topológica (Ex.: 1, 2, 3). 
//Observação: Essa função só funciona quando os elementos estão na ordem.

int insere_lista_ordenada (Lista * li, struct dado d){
    if(li == NULL){
        return 0;
    }
    Comp * aux = (Comp *) malloc(sizeof(Comp));
    if(aux == NULL){
        return 0;
    }

    aux->numero = d;
    aux->prox = NULL;

    if(*li == NULL){
        aux->ant = NULL;
        *li = aux;
    } else{
        Comp *ante, *atual = *li;
        while(atual != NULL && atual->numero.numero < d.numero){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            aux->ant = NULL;
            (*li)->ant = aux;
            aux->prox = (*li);
            *li = aux;
        } else{
            aux->prox = ante->prox;
            aux->ant = ante;
            ante->prox = aux;
        }

        if(atual != NULL){
            atual->ant = aux;
        }

        return 1;
}