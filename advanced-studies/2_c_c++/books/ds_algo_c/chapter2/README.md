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

7. What are aliases? 

8. How do you recycle dynamically allocated storage when it is no longer needed so that its space can be reused to meet further storage allocation needs?   

9. How can dynamically allocated storage become inaccessible in C?

10. What is garbage?

11. what is a dangling pointer?

12. What is the lifetime of dynamically allocated storage?

13. What is an anonymous variable?
