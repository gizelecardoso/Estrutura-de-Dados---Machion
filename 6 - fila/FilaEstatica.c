#include "FilaEstatica.h"

Fila* cria_fila(){
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->quantidade = 0;
    }
    return fi;
}

void libera_fila(Fila* fi){
    free(fi);
}

int tamanho_fila(Fila* fi){
    if(fi == NULL){
        return -1;
    } else{
        return fi->quantidade;
    }

}