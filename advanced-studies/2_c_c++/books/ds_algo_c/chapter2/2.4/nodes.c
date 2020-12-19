#include <stdlib.h>
#include <stdio.h>

typedef struct Data {
    char Airport;
    link Link;
} data;

typedef struct Link {
   node Link;
   char Airport;
} link;

typedef struct Node {
    link Link;
    char Airport;
} node;

int main() {
  
    node *l;

    (*l).Airport = "MIA";
    (*l).Link.Airport = "MEX";
    (*l).Link.Link.Airport = "ORD";
    (*l).Link.Link.Link.Airport = "";
 
    return 0;
};
