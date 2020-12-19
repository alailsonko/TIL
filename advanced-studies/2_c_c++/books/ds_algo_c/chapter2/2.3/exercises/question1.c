#include <stdio.h>
#include <stdlib.h>

int main(){
    typedef int *IntegerPointer;
    IntegerPointer A, B;

    A = (IntegerPointer) malloc(sizeof(int));
    B = (IntegerPointer) malloc(sizeof(int));
    
    *A = 19;
    *B = 5;
    
    A = B;
    *B = 7;
    printf("%d\n", *A);
}