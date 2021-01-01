# Linked Data Representations - chapter 2

## Pointers in C - Rudiments - 2.3

* A pointer is a data value reference a unit of storage


### Learning Objectives

1. To understand how pointers work in C 
2. To be able to declare pointer data types
3. To know how to allocare and deallocate memory dinamically
4. To be able to perform operations, such as dereferencies.
5. To understand the concepts of aliasing, dagling pointers, and the scope if dynamic storage allocation.

* ### Review questions 2.3
--------------------
1. what does it mean to dereference a pointer? if A is a pointer variable in C, what is the notation for dereferencing the pointer value stored in A?

* Answer: Dereferencing is used to access ot manipulate data contained in memory location pointed to by a pointer. 
*(asterik) is used with pointer variable when dereferencing the pointer variable, it refers to variable being pointed, so this is called dereferencing of pointers.

```C
int main() {
    int a = 7, b ;
    int *p; // Un-initialized Pointer
    p = &a; // Stores address of a int ptr
    b = *p; // Put Value at ptr in b
}

```

******

2. what are some other ways of describing the situation in which a unit of storage B contains a pointer to a unit of storage A?

* Answer: 1 way: copying pointers, with A = B, takes the copy of value B which is a pointer to the block of storage and places this pointer in A, so that A now points to the same block of storage that B points to.
 2 way: copying integers, the assignment *A = *B, which says to take a copy of the value stored in B referent, and put it in the location given by A's referent, *A.

```C
int main() {
   typedef int *IntegerPointer;
   integerPointer A, B;
   A = (IntegerPointer) malloc(sizeof(int));
   B = (int *) malloc(sizeof(int));
   *A = 5;
   *B = 17;
   A = B
}
s
```

*********

3. How would you declare a data type in C called IntegerPointer to be a type consisting of pointers to integers? Give the C syntax for the type definition needed to accomplish this.

* Answer: to declare a data type in C, we use expression 'typedef' and declare the type definition that is int and stays 'typedef int' and then puts the name of this defined type and result is 'typedef int *IntegerPointer'.

```C
int main() {
   typedef int *IntegerPointer;
}
```

*********
4. Suppose A is a variable declared in C to be a pointer variable containing pointers to storage of type T. How do you dynamically allocate a new block of storage of type T and obtain a pointer of it in C?

* Answer: To allocate a new block of storage of type T we use 'malloc', this tells the compiler that we want to dynamically allocate just enough to hold a person struct in memory, and then return a pointer to the newly allocated data. after we are done using the dynamically allocated data, we can release it using 'free()'.

```C
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define NUMBER_OF_ELEMENTS 100  

int main()
{
   /* Initialize seed for pseudo random number generator */
   srand(time(0));

   int32_t *parr = calloc(NUMBER_OF_ELEMENTS, sizeof(int32_t));

   if (parr == NULL) /* Memory allocate memory */
   {
      printf("Couldn't allocate memory);
   }
   else /* Memory allocation successful */
   {
      printf("Memory allocation successful\n);

      /* Generate and store random numbers */
      for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
      {
         parr[i] = rand();
      }

      printf("Before reallocation: %d %d %d\n", parr[3], parr[7], parr[11]);

      /* Reduce the array size to half */ 
      parr = realloc(parr, (NUMBER_OF_ELEMENTS / 2) * sizeof(int32_t));

      if (parr == NULL) /* Memory allocation failed*/
      {
         printf("Memory allocation failed)
      }      
      else /* Memory allocation successful */
      {
         printf("Memory allocation successful\n")

         /* proof that realloc keeps old array contents */
         printf("After reallocation: %d %d %d\n", parr[3], parr[7], parr[11])
      }
   }
   printf("\nsizeof parr = %d", sizeof(parr)); 

   free(parr);
   parr = NULL;

   return 0;
}

```


**************

5. Suppose A has been declared to be an IntegerPointer variable. How would you write an asssignment statement to assign the interger 19 to be the value of A's referent? How would you write an asssignment statement to assign the integer 19 to be the value of A's referent? How would you write an expression whose value is twice the value of A's referent?

* Answer: derefencing the A value and assigning it to be 19 integer. Multiple the dereferenced value of A by 2.

```C
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
```

************

6. Suppose A has been declared to be an IntegerPointer variable. What is wrong with the assignment A = 5; for assigning 5 to be the value of A's referent?

* Answer: Converting one datatype into another is known as type castingor, type-conversion. For example, if you want to store a 'long' value into a simple integer then you can type cast 'long' to 'int'. You can convert the values from one type to another explicitly using the cast operator as follows '(type_name) expressiob'. assigning A without *(asterisk) makes a casting error, a error of type.

```C
#include <stdlib.h>
#include <stdio.h>

int main()
{
  typedef int *IntegerPointer;

  IntegerPointer A;
  A = (IntegerPointer) malloc(sizeof(int));

  A = 5; // occur casting error
  printf("A = %d\n", *A);
}
```

***********
7. What are aliases? 

* Answer: Identical pointer values, pointing to the same (shared) storage location. A's referent, *A, and B's referent, *B, "name" the same storage location, they are called aliases. In general, aliases are two different naming expressions that name the same thing.

```C
#include <stdlib.h>
#include <stdio.h>

int main()
{
  typedef int *IntegerPointer;

  IntegerPointer A, B;
  A = (IntegerPointer) malloc(sizeof(int));
  B = (IntegerPointer) malloc(sizeof(int));

   // A and B referent are aliases share the 
   // same storage location
  *A = 19;
  *B = 19;
}
```

*************
8. How do you recycle dynamically allocated storage when it is no longer needed so that its space can be reused to meet further storage allocation needs?

* Answer: (inaccessbible storage) when the blok of storage has no pointer pointing to it. If such a situation should develop, we say that this storage block has become inaccessible - meaning that nobody can access it to read its value or to store a new value into it. It is potentially wasteful to allocate blocks of storage and then abandon them when they become inaccessible, since the pool of storage for allocating new blocks of storage could easily become used up. This could result in a storage allocation failure, in which, when we called the function malloc, there would be no more storage to allocate. (storage reclamation) In order to guard against this possibility, we can execute the special C storage reclamation function, free(x). This returns the block of storage, to which the pointer in X points, tot he pool of unallocated storage so that it can be used again. (In C, this pool of unallocated storage is often called dynamic memory) Reclaiming storage this way is analogous to recycling used bottles and newspapers. (gargabe collection) Sometimes, we use the word garbage to refer to inaccessible storage. Some programming languages, such as the list-processing language, LISP, have procedures for storage reclamation called garbage collection procedures that are triggered when available unallocated storage. C does not have such an automatic garbage collection procedure, however, so the recycling of storage must be explicitly managed by the programmer who writes C programs. (disposing of unused storage) if we want to recycle the storage block, before destroying the pointer to it in A(by overwriting this pointer with a copy of B's pointer), we could first perform the function call, free(A), as in the following sequence of actions:

```C
#include <stdlib.h>
#include <stdio.h>

int main()
{
  typedef int *IntegerPointer;

  IntegerPointer A, B;
  A = (IntegerPointer) malloc(sizeof(int));
  B = (IntegerPointer) malloc(sizeof(int));

  *A = 5;
  *B = 19;
  free(A) // first, recycle the storage block to which A refers 
  A = B  // then, put a copy of B's pointer in A
}
```

*************
9. How can dynamically allocated storage become inaccessible in C?

* Answer: when has no pointer pointing to that block of storage.

**************
10. What is garbage?

* Answer: sometimes, we use the word garbage to refer to inaccessible storage. garbage collection procedures have a way of identifying which blocks of storage are inaccessible and of returning them to the pool of unallocated storage.

****************
11. what is a dangling pointer?

* Answer: Once we have aliases pointing to the same storage location, a new programming danger arises. Starting with the resulting situation immediately above, suppose we called the function free(B). What would happen then, if we tried to evaluate the expression *A + 2? We don't know, but since *A might no longer contain a valid integer value, the result could be unexpected. First, the call to free(B) would return the storage location contraining 17, which is B's referent, to the pool of available storage. (When it does this, it might erase the value contained in the block, or join the block to another block of storage to make a bigger block -- just to nae two of several possibilities) Now, A contains a pointer used to point to. This dangling pointer might now point into the middle of a large block, formed when free(B) caused B's referent block to join another block in the storage reclamation process. The possibility exists that the referent of the dangling pointer doesn't even have a meaningful existence anymore in C. It is reasonable to consider this to be a programming error, even though neither the C compiler nor the running C system may have any means of detecting it. Consequently, the creation of dangling pointers is a pitfall that should be avoided.

****************
12. What is the lifetime of dynamically allocated storage?

* Answer: The blocks of storage that pointers refer to are created dynamically during the running of the program and can be thought if as anonymous variables. Such variables have no explicit textual names in the program, and their lifetimes exist beyond the lifetimes of local variables in the program. For example, even though an anonymous variable might be created by a function having its own local variables that vanish after the function has terminated execution, the pointer values and the locations they reference onetheless have an existence outside the (temporary) existence of the function's local storage. One way to think of this is that dynamic sorage allocated for anonymous variables by malloc exists from the moment it is allocated until the moment when its storage is reclaiming sugin free(x), or until the programs execution terminates(if its storage is not reclaimed previously, using free(x))

****************
13. What is an anonymous variable?
* Answer: One way to think of this is that dyna,ic storage allocated for anonymous variables by malloc exists from the moment it is allocated until the moment when its storage is reclaimd, using free(x), or until the program's execution terminates(if its storage is not reclaimed previously, using free(x))

*****************

### 2.3 - Exercises

1. result: 7
2. result: 5
3. result: infinite loop
3. result: i have cast error

-----------------------------

## Pointer Diagramming Notation - 2.4

### Learning Objectives

1. To understand how to interpret the pointer diagrams used in this book.
2. To learn a notation for picturing linked representations that is helpful when reasonning about them.

* ## review questions - 2.4

1. what is the null address? 

* Answer: null address is not the address of any node. It is depicted by a solid dot ( ° ) that represents an arrow with no tip that points nowhere.

**************

2. How is null address depicted in pointer diagramming notation?

* Answer:  It is depicted by a solid dot ( ° ) that represents an arrow with no tip that points nowhere.

**************

3. What value represents the null address in C?

* Answer: In C, the null pointer is represented by the special pointer value NULL.

****************
4. How is the end of a linked list indicated in pointer diagramming notation? 

* Answer: This special null address is used to show where a linked list ends, and it is used to represent an empty structure(such as a linked list having no nodes).

***************
5. What is an empty linked list, and what value is used to indicate it?

* Answer: This special null address is used to show where a linked list ends, and it is used to represent an empty structure(such as a linked list having no nodes).

***************
6. Explain the difference between explicit pointer variable notation and implicit pointer variable notation.

* Answer: (1) explicitly as a box containing a pointer vale labeled on the left side with the name of the variable followed by colon, or (2) implicitly as an oval (or circle) containing the variable name and pointining to the node the pointer value references.

*****************

7. How is an unknown value signified in pointer diagramming notation?

* Answer: When the value of a variable or the value of a field in a node is unknown, we may symbolize the unknown value by a question mark (?) for nonpointer values, or a pointer to a circle containing a question mark.

*****************

* ## 2.4 - Exercises

1. (a) null, (b) GCM, (c) MEX, (d) null

2. 

```C
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
```

3. 

```C
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
```

4. 

5. 

6. 



## Linear Linked Lists - 2.5

### Learning Objectives

1. To understand how to represent and manipulate linked lists using C's.
2. To develop skill in designing and implementing linked list algorithms.
3. To learn a set of useful basic linked list operations.

* ## 2.5 Review Questions

1. What is top-down programming using stepwise refinement?

Answer: The goals in a program strategy can be achieved by supplying more specific programming details. The process of filling in such details in a series of specific step is called stepwise refinement. The method of starting with a top-level design and expanding its details progressively until an actual program is developed is called top-down programming.
----------------------
2. When defining a struct for a NodeType in C, how can we arrange for a Link field to contain a pointer to the NodeType we are defining?

Answer: We need to define a system of nodes and pointers to serve as the foundation for manipulating linked lists. To do this, we define a structure type for list nodes, called NodeType, in the type definition section of our program as follows: 

```C

typedef char AirportCode[4];

typedef struct NodeTag {
   AirportCode Airport;
   struct NodeTag *Link;
} NodeType;

```
This defines a NodeType to be a struct having two members(or components, or fields, as we shall sometimes call them) which are: (1) an Airport field containing a three-letter AirportCode, and (2) a Link field containing a pointer to a NodeType.
In order to make it possible for the Link field of a NodeType struct to contain a pointer to another NodeType struct, the typedef above introduces the tag NodeTag after the word struct and then specifies the second member of the struct using struct NodeTag *Link; while it is illegal in C to attempt to define a struct having a member which is a pointer to structs of the same type, as is accomplished above.

3. What value in C is automatically a value of every C pointer type?

Answer: Another important idea is that the special null pointer, NULL, is automatically considered to be a value that belongs to every pointer type that is defined in C. Thus it is possible to write assignment such a L->Link = NULL; to put the null pointer into the Link field of the node that the pointer in L references, or to test a pointer value to see if it is null, as in if (L->Link == NULL) {/*L points to the last node in the list *}. [Note: In ANSI C, the null pointer simply has the value 0 and NULL is just a form of "visualdocumentation" for its value.]

* ## 2.5 Exercises

Assume that the folowing types and variables have been defined in C and are available for use: 

```C

typedef char AirportCode[4];

typedef struct NodeTag {
   AirportCode Airport;
   struct NodeTag *Link;
} NodeType;

NodeType *L, *M, *N;

```

1. Write a function, insertNewFirstNode(A, &L), which inserts a node having the airport code A as the new first node of list, L, Where &L is the address of variable L.

2. Write a function, DeleteFirst(&L), which deletes the first node of a linked list L.

3. Given a non-null pointer N to a node of a list L, and a pointer M to a new node to be insrted. write a C function to insert the node that is M's referent before the node that is N's referent on list L. [Hint: Adjust pointers to insert M after N and then swap the aiport codes in N and M.]

4. Write a function, Copy(L), which makes a copy of a linked list, L, and returns a pointer to the first node of the copy.

5. Write a function, Reverse(&L), which reveres the order of the nodes on list L. For example, if L == (ZRH, GLA, YYZ) beforehand, then executing Reverse(&L) changes L to be the list L == (YYZ, GLA, ZRH). [Hint: Write two subroutines to remove the first node N of a list L2, and to insert a node N as the new first node on a list L2. Then, starting with an empty list L2 = NULL, successively remove nodes from L1 and insert them on L2 until L1 is empty.] (Note: The airport codes: ZRH, GLA, and YYZ stand for Zurich, Switzerland; Glasgow, Sotland; and Toronto,Ontario, respectively.)

6. What is wrong with the following search program for finding the node on list L containing the airport code A and returning a pointer to it?
```C

NodeType *FindNode(char *A, NodeType *L) {
   while ((strcmp(L->Airport,A) != 0) && (L != NULL)) {
      L = L->Link;
   }
   return L;
}

```
How could you fix the bug in the program above by changing only one line?

7. Given two lists L1 and L2 write a function, Concat(L1, L2), to return a pointer to a list in which the nodes of L2 follow the nodes of L1. For example, if, beforehand, L1 == (ARN, BRU) and L2 == (JFK, SAN, HKG), the the node pointer returned by Concat(L1, L2) should point to the list (ARN, BRU, JFK, SAN, HKG). (Note: ARN is Stockholm, Sweden,and HKG, Hong Kong).

8. What is wrong with the following algorithm for finding the last node of a list and returning a pointer to it?

```C
NodeType *LastNode(NodeType *L) {
   if(L != NULL) {
      do {
         L = L->Link;
      } while(L->Link != NULL);
   }
   return L;
}

```

9 In Program 2.15, DeleteLastNode(NodeType *L), if you want to delete the last node of a list, L, why does the parameter have to be a pointer to a variable containing a node pointer? Give an example of a list that would fail to have its last node deleted if the parameter had been only a node pointer as in the function prototype void DeleteLastNode(NodeType *L).

