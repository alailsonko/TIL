#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char AirportCode[4];

typedef struct NodeTag {
    AirportCode Aiport;
    struct NodeTag *Link;
} NodeType;

void InsertNewFirstNode(char *A, NodeType **L) {
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

void InsertNewSecondNode(char *A, NodeType *L) {
    NodeType *N;
    
    N = (NodeType *)malloc(sizeof(NodeType));
    strcpy(N->Aiport, A);
    N->Link = L->Link;
    L->Link = N;
}

void DeleteFirstNode(NodeType **L) {
    
    NodeType *N;
    N = (NodeType *)malloc(sizeof(NodeType));
    N = *L;
    *L = (*L)->Link;
    free(N);
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

void DeleteLastNode(NodeType **L) 
{
  NodeType *prevNode, *currNode;
  prevNode = *L;
  currNode = (*L)->Link;
  if(currNode != NULL) {
     if(currNode->Link == NULL) {
         currNode = NULL;
     } else {
        while(currNode->Link != NULL) {
            prevNode = currNode;
            currNode = currNode->Link;
        }
         prevNode->Link = NULL;
         free(currNode);
     }
  }
}

NodeType *ListSearch(char *A, NodeType *L)
{
    NodeType *N;

    N = L;

    while(N != NULL) {
        if(strcmp(N->Aiport, A) == 0) {
            return N;
        } else {
            N = N->Link;
        }
    }
    return N;
}


void CopyLinkedList(NodeType **NewCopy, NodeType **CopyFrom) {
  if(*CopyFrom == NULL) {
    return;
  }
  NodeType *N;
  N = (NodeType*)malloc(sizeof(NodeType));
  strcpy(N->Aiport, (*CopyFrom)->Aiport);
  *NewCopy = N;
  CopyLinkedList(&(*NewCopy)->Link, &(*CopyFrom)->Link);
}

void ReverseLinkedListOrder(NodeType **L) {
    NodeType *N;
    N = (NodeType*)malloc(sizeof(NodeType));
    CopyLinkedList(&N, L);

    while(N != NULL) {
      InsertNewFirstNode(N->Aiport, L);
      DeleteLastNode(L);
      N = N->Link;
    }
}


int main() {
    
   NodeType *L, *CopyList;

   L = (NodeType*)malloc(sizeof(NodeType));
   CopyList = (NodeType*)malloc(sizeof(NodeType));
   L = NULL;
   CopyList = NULL;

   InsertNewFirstNode("BRU", &L);
   InsertNewFirstNode("GRU", &L);  
   InsertNewFirstNode("ZRU", &L);  
   InsertNewSecondNode("CGN", L);
   InsertNewSecondNode("OTP", L);
   PrintList(L);
   DeleteLastNode(&L);
   printf("%s\n", ListSearch("GRU", L)->Aiport);
   PrintList(L);
   DeleteFirstNode(&L);
   CopyLinkedList(&CopyList, &L);
   DeleteFirstNode(&CopyList);
   printf("Normal: ");
   PrintList(L);
   printf("Normal: ");
   PrintList(CopyList);
   ReverseLinkedListOrder(&L);
   ReverseLinkedListOrder(&CopyList);
   printf("Reversed: ");
   PrintList(L);
   printf("Reversed: ");
   PrintList(CopyList);

    return (1);
}