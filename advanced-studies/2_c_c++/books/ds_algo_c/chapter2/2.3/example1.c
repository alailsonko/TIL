#include <stdio.h>
#include <stdlib.h>

int main() {
  
  typedef int *IntegerPointer;
  
  IntegerPointer A, B;

  A = (IntegerPointer) malloc(sizeof(int));

  B = (int *) malloc(sizeof(int));
  
  *A = 5;

  *B = 17;

  printf("A: %d %p\n", (*A), A);

  printf("B: %d %p\n", (*B), B);
 
  *A = *B;

  printf("A = B: %d %p\n", (*A), A);

  printf("B = A: %d %p\n", (*B), B);
  
  return 0;
}
