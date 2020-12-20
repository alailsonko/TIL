#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
   char Airport;
   struct Node * Link;
} node;

int main()
{
  node * L = NULL;
  L = (node *) malloc(sizeof(node));

  (*L).Airport = "MIA";
  (*L).Link.Airport = "MEX";
  (*L).Link.Link.Airport = "ORD";
}