#include<stdlib.h>
#include<stdio.h>

#define MAX 100

struct dados { 
    int numero;
};

typedef struct lista Lista;

Lista * cria_lista();

int insere_lista(Lista * li, struct dados d);

Lista * concatena_lista(Lista * l1, Lista * l2);
