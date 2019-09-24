#include<stdio.h>
#include<stdlib.h>

int main(){

    int x = 10;
    int *p = &x;
    int **p2  = &p;

    printf("p2: %d\n", p2);
    printf("*p2: %d\n", *p2);
    printf("**p2: %d\n", **p2); 
    

    char letra = 'a';
    char *ptrChar = &letra;
    char **ptrPtrChar = &ptrChar;
    char ***ptrPtr = &ptrPtrChar;

    printf("*ptrChar: %c\n", *ptrChar);
    printf("**ptrPtrChar: %c\n", **ptrPtrChar);
    printf("***ptrPtr: %c\n", ***ptrPtr);

    return 0;
}