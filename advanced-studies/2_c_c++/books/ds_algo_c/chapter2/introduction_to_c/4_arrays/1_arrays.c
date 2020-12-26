/*
## C Arrays

in this tutorial, you will learn to work with arrays.
You will learn to declare, initialize and access elements
of an array with the help of examples.

An array is a variable that can store multiple values. 
For example, if you want to store 100 integers, you can create an array for it.

> int data[100];

## How to declare an array?

> dataType arrayName[arraySize];

For example,

> float mark[5];

Here, we declared an array, mark, of floating-point type.
And its sie is 5. Its important to nore that the size and type
of an array cannot be changed once it is declared.

## Access Array Elements
-------------------
You can access elements of an array by indices.

Suppose you declared an array mark as above. The first element
is mark[0], the second element is mark[1] and so on.

Few keynotes:
    * Arrays have 0 as the first index, not 1. In this example, mark[0]
    is the first element.
    * If the size of an array is n, to access the last element, the n-1
    index is used. In this example, mark[4].
    This is because the size of a float is 4bytes.

## How to initialize an array?

it is possible to initialize an array during declaration.For example,

> int mark[5] = {19, 10, 8, 17, 9};

You can also initialize an array like this.

> int mark[] = {19, 10, 8, 17, 9};

Here, we haven't specified the size. However, the compiler knows its size is 5
as we are initilizing it with 5 elements.

Here,

mark[0] is equal to 19
mark[1] is equal to 10
mark[2] is equal to 8
mark[3] is equal to 17
mark[4] is equal to 9

Change value of array elements

```
int mark[5] = {19, 10, 8, 17, 9}

// make the value of the third element to -1
mark[2] = -1;
// make the value of the fifth element to 0
mark[4] = 0;
```
## Input and Output array Elements

Here's how you can take input from the user and store it in an array
elements

```
// take input and store it in the 3rd element
scanf("%d", &mark[2]);
// take input and store it in the ith element
scanf("%d", &mark[i -1]);
```
Example 1: Array Input/Output
```
#include <stdio.h>

int main() {
    int value[5];

    printf("Enter 5 integers: ");

    //  taking input and storing it in an array
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &value[i]);
    }

    printf("Displaying integers");

    // printing elements of an array
    for(int i = 0; i < 5; ++i) {
        printf("%d", value[i])
    }
    return 0;
}

Here, we have used a for loop to take 5 inputs from the user and store thenin an 
array. Then, using another for looṕ, these elements are displayed on the screen.
```
Example 2: Calculate Average
```
#include <stdio.h>
int main() {
    int marks[10], i, n, sum = 0, average;

    prtinf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter number%d: ", i + 1);
        scanf("%d", &marks[i]);

        // adding integers entered by the user to the sum variable
        sum += marks[i];
    }
    average = sum / n;
    pritnf("Average = %d", average);

    return 0;
}

Here, we have computed the average of n numbers entered by the user.

```
## Access elements out of its bound
Suppose you declared an array of 10 elements. Lets say,

> int testArray[10];

You can access the array elements from testArray´[0] to testArray[9]

Now lets say if you try to access testArray[12]. The element is not available.
This may cause unexpected output(undefined behavior). Sometimes you might
get an error and some other time your program may run correctly.

Hence, you should never access elements of an array outside of its bound.

### Multidimensional arrays

In this tutorial, you learned about arrays. These arrays are called one-dimensional 
arrays.
*/

#include <stdio.h>

int main() {
    int values[5];

    printf("Enter 5 integers: ");

    for (int i = 0; i < 5; ++i) {
        scanf("%d", &values[i]);
    }

    printf("Displaying integers: ");

    // printing elements of an array
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", values[i]);
    }

    int marks[10], i, n, sum = 0, average;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i <n; ++i ) {
        printf("Enter number%d: ", i+ 1);
        scanf("%d", &marks[i]);

        // adding integers entered by the user to the sum variable
        sum += marks[i];
    }

    average = sum /n;
    printf("Average = %d\n", average);

    return 0;
}