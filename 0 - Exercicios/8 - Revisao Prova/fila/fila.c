#include "fila.h"

struct filaEstatica{
    int inicio, final, qtd;
    struct dado numero[MAX];
};

struct filaDinamica {
    struct elemento *inicio;
    struct elemento *final;
};

struct elemento {
    struct dado d;
    struct elemento *prox;
};

typedef struct elemento Elem;

FilaE * cria_FilaE(){
    FilaE * fi = (FilaE *) malloc(sizeof(FilaE));

    if(fi == NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila(FilaE * fi){
    free(fi);
}

int tamanho_fila(FilaE * fi){
    if(fi == NULL){
        return 0;
    }
    return fi->qtd;
}

int Fila_cheia(FilaE * fi){
    if(fi == NULL){
        return 0;
    }
    if(fi->qtd == MAX){
        return 1;
    } else {
        return 0;
    }
}
int Fila_vazia(FilaE * fi){
    if(fi == NULL){
        return 0;
    }
    if(fi->qtd == 0){
        return 1;
    } else{
        return 0;
    }
}

int insere_Fila(FilaE * fi, struct dado d){
    if (fi == NULL){
        return 0;
    }
    if(Fila_cheia(fi)){
        return 0;
    }

    fi->numero[fi->final] = d;
    fi->final = (fi->final+1)%MAX;
    fi->qtd++;
    return 1;
}

int remove_Fila (FilaE * fi){
    if(fi == NULL || Fila_vazia(fi)){
        return 0;
    }

    fi->inicio = (fi->inicio+1)%MAX;
    fi->qtd--;
    return 1;
}

int fura_fila(FilaE * fi, struct dado d){
    if(fi == NULL || Fila_cheia(fi)){
        return 0;
    }
    int cont = fi->final;
    fi->final = (fi->final+1)%MAX;
    int aux = fi->qtd;
    while(cont < fi->inicio){
        cont = fi->final-1;
        cont--;
    }
    fi->numero[fi->inicio] = d;
}

FilaD * cria_FilaD(){
    FilaD * fi = (FilaD *) malloc(sizeof(FilaD));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void libera_fila(FilaD * fi){
    if(fi != NULL){
        Elem * no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(no);
    }
}

int tamanho_fila(FilaD * fi){
    if(fi == NULL){
        return 0;
    } 
    int cont = 0;
    Elem* no;
    no = fi->inicio;

    while(no != NULL){
        cont ++;
        no = no->prox;
    }
    return cont;
}
int Fila_vazia(FilaD * fi){
    if(fi == NULL){
        return 1;
    }

    if(fi->inicio == NULL){
        return 1;
    }

    return 0;
}

int insere_Fila(FilaD * fi, struct dado d){
    if(fi == NULL){
        return 0;
    }

    Elem * no = (Elem *) malloc(sizeof(Elem));

    if(no == NULL){
        return 0;
    }

    no->d = d;
    no->prox = NULL;

    if(fi->final == NULL){
        fi->inicio = no;
    } else {
        fi->final->prox = no;
    }

    fi->final = no;
    return 1;
}

int remove_Fila (FilaD * fi){
    if(fi == NULL){
        return 0;
    }
    if(fi->inicio == NULL){
        return 0;
    }

    Elem * no = fi->inicio;
    fi->inicio = fi->inicio->prox;

    if(fi->inicio == NULL){
        fi->final = NULL;
    }
    free(no);
    return 1;
}

int  consulta_Fila(FilaD * fi, struct dado *d){
    if(fi == NULL){
        return 0;
    }

    if(fi->inicio == NULL){
        return 0;
    }

    *d = fi->inicio->d;
    return 1;
}

int fura_fila(FilaD * fi, struct dado d){
    if(fi == NULL){
        return 0;
    }
}
