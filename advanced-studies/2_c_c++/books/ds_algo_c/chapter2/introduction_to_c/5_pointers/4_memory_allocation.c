/*
C Dynamic Memory Allocation

In this tutorial, you will learn to dynamically allocate memory in your C program
using standard library functions: malloc(), calloc(), free() and realloc().

As you know, an array is a collection of a fixed number of values. Once the size
of an array is declared, you cannot change it.

Sometimes the size of the array you declared may be insufficient. TO solve this
issue, you can allocate memory manually during run-time. This is known as
dynamic memory allocation in C programming.

To allocate memory dynamically, library functions are malloc(), calloc(),
realloc() and free() are used. These functions are defined in the <stdlib.h>
header file.

### C malloc()

The name "malloc" stands for memory allocation

The malloc() function reserves a block of memory of the specified number of bytes.
And, it returns a pointer of void which can be casted into pointers of any form. 

#### Syntax of malloc()
ptr = (castType*) malloc(size);

Example
ptr = (float*) malloc(100 * sizeof(float));

The above statement allocates 400 bytes of memory. Its because the size of 
float is 4bytes. And, the pointer ptr holds the address of the first byte in the 
allocated memory.

The expression results in a NULL pointer if the memory cannot be allocated.

## calloc()

The name "calloc" stands for contiguous allocation.

The malloc() function allocates memory and leaves the memory uninitialized.
Whereas, the calloc() function allocates memory and initializes all bits to zero.

## Syntax of calloc()

> ptr = (castType *) calloc(n, size)

Example:

> ptr = (float *) calloc(25, sizeof(float));

The above statement allocates contiguous space in memory for 25 elements of type
float.

### C free()

Dynamically allocated memory created with either calloc() or malloc()
doesn't get freed on their own. You must explicitly use free() to
release the space.

#### Syntax of free()

> free(ptr);

This statement frees the space allocated in the memory pointed by ptr.

Example 1: malloc() and free()
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int *) malloc(n * sizeof(int));

    // if memory cannot be allocated
    if(ptr == NULL) {
        printf("Error! memory not allocated");
        exit(0);
    }

    printf("Enter elements: ");
    for(i = 0; i < n; ++i) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d\n", sum);

    free(ptr);

    return 0;
}
Here, we have dynamically allocated the memory for n number of int.

```
Example 2: calloc() and free()
```
// program to calculate the sum of n numbers entered by the user
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *ptr, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));
    if(ptr == NULL) {
        printf("Error! memory not allocated");
        exit(0);
    }

    printf("Enter elements: ");
    for(i = 0; i < n; ++i) {
        scanf("%d", ptr + i);
        sum += *(ptr+ i);
    }
    printf("Sum = %d\n", sum);
    free(ptr);
    return 0;
}
```
### realloc()
If the dynamically allocated memory is insufficient or more than required, you
can change the size of previously allocated memory using the realloc()
function.

#### Syntax of realloc()

> ptr = realloc(ptr, x);

Here, ptr is reallocated with a new size x.

Example 3: realloc()
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, i, n1, n2;
    printf("Enter size: ");
    scanf("%d", &n1);

    ptr = (int *) malloc(n1 * sizeof(int));

    printf("Address of previously allocated memory");
    for (i = 0; i < n1; ++i) {
        printf("%d\n", ptr + i);
    }
    printf("Enter the new size: ");
    scanf("%d", &n2);

    // reallocating the memory
    ptr = realloc(ptr, n2 * sizeof(int));
    printf("Address of newly allocated memory: ");
    for(i = 0; i < 2n; ++i) {
        printf("%u", ptr + i);
    }

    free(ptr);

    return 0;
}
```

*/
#include  <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    // if memory cannot be allocated
    if(ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Sum = %d", sum);

    free(ptr);

    int nTwo, iTwo, *ptrTwo, sumTwo = 0;
    printf("Enter number of elements: ");
    scanf("%d", &nTwo);

    ptrTwo = (int *)calloc(nTwo, sizeof(int));
    if (ptrTwo == NULL)
    {
        printf("Error! memory not allocated");
        exit(0);
    }

    printf("Enter elements: ");
    for(iTwo = 0; iTwo < nTwo; ++iTwo) {
        scanf("%d", ptrTwo + iTwo);
        sumTwo += *(ptrTwo + iTwo);
    }
    
    printf("Sum = %d\n", sumTwo);
    free(ptrTwo);

    int *ptrThree, iThree, n1Three, n2Three;
    printf("Enter size: ");
    scanf("%d", &n1Three);

    ptrThree = (int*) malloc(n1Three * sizeof(int));

    printf("Address of previously allocated memory: ");
    for (iThree = 0; iThree < n1Three; ++iThree) {
        printf("%u\n",ptrThree + iThree);
    }
    printf("\nEnter the new size: ");
    scanf("%d", &n2Three);
    
    ptrThree = realloc(ptrThree, n2Three * sizeof(int));

    printf("Address of newly allocated memory: ");
    for(iThree = 0; iThree < n2Three; ++iThree) {
        printf("%u\n",ptrThree + iThree);
    }
    free(ptrThree);

    return 0;
}