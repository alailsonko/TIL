/*
## Relationship Between Arrays and Pointers

In this tutorial, you will learn about the relationship between arrays and pointers
int C programming. You will also learn to access array elements using pointers

Before you learn about the relationship between arrays and pointers, be sure to
check these two topics
    * C arrays
    * C pointers

## Relationship Between Arrays and Pointers
-------------------------
An array is a block of sequential data. Lets write a program to print addresses
of array elements.
```
#include <stdio.h>
int main() {
    int x[4];
    int i;

    for (i = 0; i < 4; ++i) {
        printf("&x[%d] = %p\n", i, &x[i]);
    }

    printf("Address of array x: %p", x);

    return 0;
}
There is a difference of 4 bytes between two consecutive elements of array x.
It is because the size of int is 4 bytes (on our compiler).

Notice that, the address of &x[0] and x is the same. Its because the variable
name x points to the first element of the array. 

From the above example, it is clear that &x[0] is equivalent to x. And, x[0] is
equivalent to *x;

Similarly,
    * &x[1] is equivalent to x + 1 and x[1] is equivalent to *(x+1).
    * &x[2] is equivalent to x + 2 and x[2] is equivalent to *(x+2).
    * ..........
    * Basically, &x[i] is equivalent to x + i and &x[i+1] is equivalent to *(x+i).

Example 1: Pointers and Arrays
#include <stdio.h>
int main() {
    int i, x[6], sum = 0;
    pritnf("Enter 6 numbers: ");
    for (i = 0; i < 6; ++i) {
        // Equivalent to scanf("%d", &x[i]);
        scanf("%d", x + i);

        // Equivalent to sum += x[i]
        sum += *(x + i);
    }
    pritnf("Sum = %d", sum);

    return 0;
}
Here, we have declared an array x of 6 elements. To access elements of the array,
we have used pointers.
```
In most contexts, array names decay to pointers. In simple words, array names
are converted to pointers. Thats the reason why you can use pointers to access
elements of arrays. However, you should remember that pointers and arrays are not
not the same.
----------------------------
Example 2: Arrays and Pointers 
```
#include <stdio.h>
int main() {
    int x[5] = {1,2,3,4,5};

    int* ptr;
    // ptr is assigned the address of the third element
    ptr = &x[2];

    printf("*ptr = %d\n", *ptr);
    printf("*(ptr + 1) = %d\n", *(ptr+1));
    printf("*(ptr - 1) = %d\n", *(ptr -1 ));
    return 0;
}
When you run the program, the output will be;

*ptr = 3
*(ptr + 1) = 4
*(ptr - 1) = 2

In this example, &x[2], the address of the third element, is assigned to the ptr
pointer. Hence, 3 was displayed when we printed *ptr.

And, printing *(prt+1) gives us the fourth element. Similarly, printing *(prt-1) gives
us the second element.
```
*/

#include <stdio.h>
int main() {
    int i, x[6], sum = 0;
    printf("Enter 6 numbers: ");
    for (i = 0; i < 6; ++i) {
        // Equivalent to scanf("%d", &x[i]);
        scanf("%d", x+i);

        // Equivalent to sum += x[i]
        sum += *(x+i);
    }
    printf("Sum = %d\n", sum);

    int y[5] = {1,2,3,4,5};
    int* ptrTwo;

    ptrTwo = &y[2];

    printf("*ptrTwo = %d\n", *ptrTwo);
    printf("*(ptrTwo+1) = %d\n", *(ptrTwo+1));
    printf("*(ptrTwo-1) = %d\n", *(ptrTwo-1));

    return 0;
}