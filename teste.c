#include<stdio.h>
#include<stdlib.h>

int main(){

    int d = 4;
    int *p;
    p = &d;

    printf("%d\n", d);
    printf("%d\n", &d);
    printf("%d\n", *p);
    printf("%d\n", p);

    *p = 12;
    printf("%d\n", *p);

    return 0;
}