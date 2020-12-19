#include <stdio.h>
#include <stdlib.h>

int main(){
    typedef int *IntegerPointer;
    IntegerPointer A;
    A = (IntegerPointer) malloc(sizeof(int));

    A = NULL;
    
    A = *A;
    
    printf("%d\n", A);
}