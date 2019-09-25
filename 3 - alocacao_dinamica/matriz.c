#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int **p;
    int i, j, N = 2;

    int p = (int **) malloc (N * sizeof(int*));

    for(i = 0; i < N; i++){

        p[i] = (int *) malloc (N * sizeof(int));
        
    }

    return 0;
}