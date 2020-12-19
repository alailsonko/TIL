#include <stdio.h>
#include <stdlib.h>

int main(){
    typedef int *IntegerPointer;
    IntegerPointer A, B;

    A = (int *) malloc(sizeof(int));
    B = (int *) malloc(sizeof(int));
    
    *A = 19;
    *B = 5;
    
    *A = *B;
    *B = 7;
    printf("%d\n", *A);
}