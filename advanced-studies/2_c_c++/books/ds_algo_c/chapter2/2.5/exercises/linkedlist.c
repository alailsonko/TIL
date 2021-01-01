#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char AirportCode[4];

typedef struct NodeTag {
    AirportCode Airport;
    struct NodeTag *Link;
} NodeType;

NodeType *L, *M, *N;

void InsertNewFirstNode(char *A, NodeType **L);
void PrintList(NodeType *L);

int main() {
    
    InsertNewFirstNode((char*)"BRU", &L);
    InsertNewFirstNode((char*)"LKS", &L);
    InsertNewFirstNode((char*)"DOT", &L);
    InsertNewFirstNode((char*)"JSF", &L);
    InsertNewFirstNode((char*)"JGH", &L);
    InsertNewFirstNode((char*)"HKG", &L);
    InsertNewFirstNode((char*)"GBP", &L);
    PrintList(L);
    return 0;
}

void InsertNewFirstNode(char *A, NodeType **L) {
  NodeType *P;

  N = (NodeType *) malloc(sizeof(NodeType));
  strcpy(N->Airport, A);
  N->Link = NULL;
  printf("start: %s\n", N->Airport);  // print airport code 

  if(*L == NULL) {
      *L = N;
  } else {
      P = *L;
      while ( P->Link != NULL) {
          P = P->Link;
        printf("while: %s\n", P->Airport);  // print airport code 
      }
      P->Link = N;
        printf("end: %s\n", P->Airport);  // print airport code 
  }
}

void PrintList(NodeType *L) {
    printf("(");

    N = L;

    while(N != NULL) {
        printf("%s", N->Airport);
        N = N->Link;
        if(N != NULL) {
            printf(",");
        }
    }
    printf(")\n");
}