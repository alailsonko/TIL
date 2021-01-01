/*
1. variables that store address of other variables
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int a; // integer
    int *P; // pointer to integer
    P = &a;

    printf("%p\n",&a);
    printf("%d\n",(int)sizeof(int));
    printf("%d\n",(int)sizeof(P+1+1));
    printf("%p\n",P+1+1);

    char c; // character
    char *PC; // pointer to character
    PC = &c;

    printf("%p\n",&c);
    printf("%p\n",PC);

    double d; // double
    double *PD; // pointer to double
    PD = &d;

    printf("%p\n",&d);
    printf("%p\n",PD);


    return 0;
}