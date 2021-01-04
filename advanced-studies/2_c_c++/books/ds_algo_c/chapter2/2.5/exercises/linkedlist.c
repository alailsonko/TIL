#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char AirportCode[4];

typedef struct NodeTag {
    AirportCode Airport;
    struct NodeTag *Link;
} NodeType;

NodeType *L, *M, *N, *C;

int InsertNewFirstNode(char *A, NodeType **L);
int DeleteFirstNode(NodeType **L);
int InsertNewMidNode(char *A, char *B, NodeType **L, NodeType **C);

int main() {
    
    L = NULL;
    C = NULL;

    InsertNewFirstNode("INI", &L);
    InsertNewFirstNode("OTH", &L);
    InsertNewFirstNode("THR", &L);
    InsertNewFirstNode("QUA", &L);
    InsertNewFirstNode("LAT", &L);
    InsertNewFirstNode("FOU", &L);
    InsertNewFirstNode("NAS", &L);
    DeleteFirstNode(&L);
    DeleteFirstNode(&L);
    DeleteFirstNode(&L);
    InsertNewFirstNode("NAS", &L);
    DeleteFirstNode(&L);
    DeleteFirstNode(&L);
    DeleteFirstNode(&L);
    DeleteFirstNode(&L);
    DeleteFirstNode(&L);
    InsertNewFirstNode("INI", &L);
    InsertNewFirstNode("OTH", &L);
    InsertNewFirstNode("THR", &L);
    InsertNewFirstNode("QUA", &L);
    InsertNewFirstNode("LAT", &L);
    InsertNewFirstNode("FOU", &L);
    InsertNewFirstNode("NAS", &L);

/*
Given a non-null pointer N to a node of a list L,
and a pointer M to a new node to be inserted, write a C
function to insert the node that is M's referent before
the node that is N's referent on list L.
[Hint: Adjust pointers to insert M after N and then swap
the aiport codes in N and M.]

1.step
    
    *N = "FOO";

    N = | Airport | Link -> non-NULL

    L -> | Airport | Link -> | Airport | Link -> 
    | Airport | Link -> NULL

*/
   // (NAS,FOU,LAT,QUA,THR,OTH,INI)
    InsertNewMidNode("NEW", "QUA", &L, &C);
 
// start the print
    // printf("(");
     
    // while (C->Link != NULL) {
    //     printf("from C %s\n", C->Airport);
    //     C = C->Link;
    //     if( C->Link != NULL) printf(",");
    // }
    // printf(")\n");
// end the print

    return 0;
}

int InsertNewMidNode(char *A, char *B, NodeType **L, NodeType **C){
    
    // (NAS,FOU,LAT,QUA,THR,OTH,INI)
    N = (NodeType *) malloc(sizeof(NodeType));
    
    printf("A = %s, B = %s\n", A, B);
    strcpy(N->Airport, A);
    N->Link = NULL;

    while (*L != NULL) {
        
// start the print
    // printf("(");
     
    // while ((*C)->Link != NULL) {
        // printf("from C %s\n", (*C)->Airport);
        // (*C) = (*C)->Link;
        // if( (*C)->Link != NULL) printf(",");
    // }
    // printf(")\n");
// end the print

        if(strcmp((*L)->Airport, B) == 0) {
            printf("%s\n", *L);
            N->Link = *L;
                // start the print
    printf("(");
    // N = *L;

    while (N != NULL) {
        printf("%s", N->Airport);
        N = N->Link;
        if( N != NULL) printf(",");
    }
    printf(")\n");
    // end the print
            return 0;
        } else {

        M = (NodeType *) malloc(sizeof(NodeType));
    
        strcpy(M->Airport, *L);

        M->Link = NULL;

        if(*C == NULL){
        
        *C = M;
       
        printf("L is null, %s\n", M->Airport);
   
    }  if(*C != NULL) {
        
        M->Link = NULL;
        
        *C = M;
        
        printf("C is not NUll %s, %s, %s\n", M->Airport, M->Link, *C);
    }
        
        *L = (*L)->Link;
// start the print
    printf("(");
         
    while ((*C)->Link != NULL) {
        printf("from C %s\n", (*C)->Airport);
        (*C) = (*C)->Link;
        if( (*C)->Link != NULL) printf(",");
    }
    printf(")\n");
// end the print
    }   
    }
    return 0;
}       

int DeleteFirstNode(NodeType **L){
    if(*L != NULL) {
        // free(*L);
        printf("deleted %s\n", *L);
        *L = (*L)->Link;
        printf("new first node %s\n", *L);

    // start the print
    printf("(");
    N = *L;

    while (N != NULL) {
        printf("%s", N->Airport);
        N = N->Link;
        if( N != NULL) printf(",");
    }
    printf(")\n");
    // end the print
    return 0;
    }
           
    return 0;
}

/*
L -> NULL

if L->NULL {
    L -> Airport(INI) -> LINK -> NUll
} else if(L != NULL) {
    L -> Airport(OTH) -> LINK -> Airport(INI) -> LINK -> NUll
}

*/

int InsertNewFirstNode(char *A, NodeType **L){
    printf("%s\n", A);
   
    N = (NodeType *) malloc(sizeof(NodeType));
    strcpy(N->Airport, A);
    N->Link = NULL;

    if(*L == NULL){
        *L = N;
       printf("L is null, %s\n", N->Airport);
       return 0;
    }  if(*L != NULL) {
      /*
L -> Airport -> Link -> NULL
      */

    N->Link = *L;
    *L = N;
     printf("L is not NUll %s, %s, %s\n", N->Airport, N->Link, *L);

// start the print
    printf("(");
    N = *L;

    while (N != NULL) {
        printf("%s", N->Airport);
        N = N->Link;
        if( N != NULL) printf(",");
    }
    printf(")\n");
// end the print

    return 0;

    }
    


    return 0;
}
