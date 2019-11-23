#include "ListaExercEst.c"

int main(){

    Lista * l1;
    l1 = cria_lista();

    Lista * l2;
    l2 = cria_lista();

    Lista * l3 = concatena_lista(l1, l2);

    return 0;
}