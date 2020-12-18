#include <stdlib.h>
#include <stdio.h>

int main()
{
  typedef int *IntegerPointer;

  IntegerPointer A, B;
  A = (IntegerPointer) malloc(sizeof(int));
  B = (IntegerPointer) malloc(sizeof(int));

  *A = 19;
  *B = 2;
  printf("A = %d\n", *A);
  
  *A = *A * *B;
  printf("B = %d\n", *A);
}