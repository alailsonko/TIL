#include <stdio.h>
#include <stdlib.h>

int main(){
   typedef int BigArray[1000];
   BigArray *A;

   while((A = (BigArray *)malloc(sizeof(BigArray))) != NULL);

   printf("storage allocation failure occurred");
}