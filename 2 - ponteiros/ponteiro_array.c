#include<stdio.h>
#include<stdlib.h>

int main(){

    int vet[5] = {1,2,3,4,5};
    int *p = vet;
    int i;

    for(i=0; i<5; i++){
        printf("%d\n", p[i]);
        printf("%d\n", *(p+i));
        
    }

    int *pvet[2];
    int x = 10, y[2] = {20, 30};

    pvet [0] = &x;//colocando endereco de x na primeira posicao do vetor de ponteiros
    pvet [1] = y;//endereco do vetor y na segunda posicao

    printf("pvet[0]: %p\n", pvet[0]);//endereco de x      &x
    printf("pvet[0]: %p\n", pvet[1]);//endereco da primeira posicao de y  &y 

    printf("*pvet[0]: %d\n", *pvet[0]);  //conteudo do primeiro endereco do vetor de ponteiros - no caso x = 10.
    printf("pvet[1][1]: %d\n", pvet[1][1]); //imprima a primeira posicao do vetor de ponteiros, 
                                            //essa primeira posicao recebe um vetor entao colocamos 
                                            //o elemento que queremos retornar desse vetor, 
                                            //no caso a posicao 1 - 30



    return 0;
}