#include <stdlib.h>
#include <stdio.h>

int main()
{
  typedef int *IntegerPointer;

  IntegerPointer A;
  A = (IntegerPointer) malloc(sizeof(int));

  A = 5;
  printf("A = %d\n", *A);
}