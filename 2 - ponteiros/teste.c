#include<stdio.h>
#include<stdlib.h>

int main(){

    int d = 4;
    int *p;
    p = &d;
    int *c =(int *) 10;

    printf("%d\n", d);
    printf("%d\n", &d);
    printf("%d\n", *p);
    printf("%d\n", p);


    void *pp;
    int *p1, p2 = 10;
    p1 = &p2;
    pp = &p2;
    printf("Endereco em pp: %p \n", pp);
    pp = &p1;
    printf("Endereco em pp: %p \n", pp);
    pp = p1;
    printf("Endereco em pp: %p \n", pp);

    pp = &p2;
    //printf("Conteudo: %d \n", *pp); ERRO
    printf("Conteudo: %d \n", *(int *)pp);


    return 0;
}