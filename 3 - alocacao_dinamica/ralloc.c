#include<stdio.h>
#include<stdlib.h>

int main(){

    //criando um array de 50 inteiros (200 bytes)
    int *v = (int* ) malloc(200);

    //aumenta a memória alocada para 100 inteiros (400 bytes)
    v = (int* ) realloc(v, 400);
    printf("%d\n", &v);
    printf("%d\n", *v);

    return 0;
}