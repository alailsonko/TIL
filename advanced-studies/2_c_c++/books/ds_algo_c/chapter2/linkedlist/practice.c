#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char AirportCode[4];

typedef struct NodeTag {
    AirportCode Aiport;
    struct NodeTag *Link;
} NodeType;

void InsertNewNodeBeginning(char *A, NodeType **L) {
    NodeType *N;
    
    N = (NodeType *)malloc(sizeof(NodeType));
    strcpy(N->Aiport, A);
    N->Link = NULL;
    if(*L == NULL) {
       *L = N;
    } else {
        N->Link = *L;
        *L = N;
    }
}

void PrintList(NodeType *L) {
    NodeType *N;

    printf("(");
    
    N = L;

    while(N != NULL) {
      printf("%s", N->Aiport);
      N = N->Link;
      if(N != NULL) printf(",");
    }

    printf(")\n");
}

int main() {
    
   NodeType *L;

   L = (NodeType*)malloc(sizeof(NodeType));
   L = NULL;

   InsertNewNodeBeginning("BRU", &L);  
   InsertNewNodeBeginning("GRU", &L);  
   InsertNewNodeBeginning("ZRU", &L);  
   
   PrintList(L);

    return (1);
}