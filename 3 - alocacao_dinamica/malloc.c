#include<stdio.h>
#include<stdlib.h>

int main(){

    int *p;
    p = (int*) malloc(5 * sizeof(int));//a partir do momento que aqui deu certo, nao preciso mais lembrar que tem o ponteiro *p.

    if(p == NULL){
        printf("Erro: Sem memoria!\n");
        exit(1);
    }

    int i;

    for(i=0; i<5; i++){
        printf("Digite p[%d]: ", i);
        scanf("%d", &p[i]);//trabalho como o vetor e nao mais como um ponteiro.
    }

    free(p);

    return 0;
}