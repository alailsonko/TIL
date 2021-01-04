/*
pointers and arrays
*/

#include <stdlib.h>
#include <stdio.h>

int main() {

    int A[5]; // 4 bytes x 5 = 20 bytes

    A[0] = 6;
    A[1] = 2;
    A[2] = 8;
    A[3] = 2;
    A[4] = 9;

   for (int i = 0; i < 5; ++i) {
       printf("%d\n", A[i]);
   }
    
    int B[] = {2,4,5,8,1};
    int *p = B;
    int j;

    printf("---------------------\n");
    
    for (int j = 0; j < 5; ++j) {
       printf("%p\n", &B[j]);
       printf("%d\n", B+j);
       printf("%d\n", B[j]);
       printf("%d\n", *(B+j));
    }

    return 0;
}

