#include "ListaExercEst.h"

struct lista{
    int qtd;
    struct dados d1[MAX];
};

Lista * cria_lista(){
    Lista * li = (Lista *) malloc (sizeof(Lista));
    if(li == NULL){
        return 0;
    }
    li->qtd = 0;
    li->d1->numero = 0;

    return li;
}

Lista * concatena_lista(Lista * l1, Lista * l2){
    Lista * l3 = (Lista *) malloc (sizeof(Lista));

    if(l1 == NULL){
        return l2;
    }

    if(l2 == NULL){
        return l1;
    }
    
    int i = 0;
    while(i < l1->qtd){
        l3[i] = l1[i];
        i++;
    }

    int j = 0;
    while(j < l2->qtd){
        l3[j+i] = l2[j];
        j++;
    }

    return l3;
}

int insere_lista(Lista * li, struct dados d){
    if(li == NULL) 
        return 0;
    
    int i = 0;
    while(i < li->qtd){
        if(li->d1[i] == NULL){
            li->d1[i] = d;
        }
        i++;
    }
    li->d1 = d;
}
