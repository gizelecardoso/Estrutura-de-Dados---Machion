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

    *p = 12;
    printf("%d\n", *p);

    
    c++;
    printf("%d\n", *c);

    c = c + 15;
    printf("%d\n", *c);

    c = c - 2;
    printf("%d\n", *c);

    return 0;
}