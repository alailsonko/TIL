/*
## C Multidimensional Arrays

In this tutorial, you will learn to work with muldidimensional arrays(two-
dimensional and three-dimensional arrays) with the help of exaples.

In C progrmming, you canc reate an array of arrays. These arrays are known as
multidimensional arrays. For example,

> float[3][4];

Here, x is a two-dimensional (2nd)array. The array  
can hol 12 elements. You can think the array as a table with 3 rows and each row 
has 4 columns. 


    col1    col2    col3    col4
row1x[0][0]x[0][1]x[0][2]x[0][3]
row2x[1][0]x[1][1]x[1][2]x[1][3]
row3x[2][0]x[2][1]x[2][2]x[2][3]

Similarly, you can declare a three-dimensional (3rd)array.
For example,

> float y[2][4][3];

Here, the array y can hold 24 elements

## Initializing a multidimensional array
-------------------------
Here is how you can initilize two-multidimensional and three-dimensional arrays:

Initialization of a 2d array
```
int c[2][3] = {{1,3,0}, {-1,5,9}}
int c[][3] = {{1,3,0}, {-1,5,9}}
int c[2][3] = {{1,3,0}, {-1,5,9}}
```

Initialization of a 3d array

You can initialize a three-dimensional array in a similar way like a two-dimensional array.
Here's an example

```
int test[2][3][4] = {
    {{3,4,2,3}, {0,-3,9,11}, {23,12,23,2}},
    {{3,4,2,3}, {0,-3,9,11}, {23,12,23,2}}
    }
```

Example 1: Two-dimensional array to store and print values

```
// C program to store temperature of two cities of a week and display it.
#include <stdio.h>

const int CITY = 2;
const int WEEK = 7;

int main() {
    int temperature[CITY][WEEK];

    // using nested loop to store values in a 2nd array
    for (int i = 0; i < CITY; ++i)
    {
        for (int j = 0; j < WEEK; ++j)
        {
            printf("City %d, Day %d: ", i+1, j+1);
            scanf("%d", &temperature[i][j]);
        }
    }
    printf("\nDisplaying values: \n\n");

    // using nested loop to displau values of a 2d array
    for (int i = 0; i < CITY; ++i)
    {
        for (int j = 0; j < WEEK; ++j)
        {
            printf("City %d, Day %d = %d\n", i + 1, j + 1, temperature[i][j]);
        }
    }
    return 0;
}
```
Example 2: Sum of two matrices
```
// C program to find the sum of two matrices of order 2*2
#include <stdio.h>

int main() {

    float a[2][2], b[2][2], result[2][2];

    // Taking input using nested for loop
    printf("Enter elements of 1st matrix\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("Enter a%d%d: ", i + 1, j+ 1);
            scanf("%f", &a[i][j]);
        }
    }

    // taling input using nested for loop
    printf("Enter elements of 2nd matrix\n");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("Enter b%d%d: ", i + 1, j+ 1);
            scanf("%f", &b[i][j]);
        }
    }

    // adding correspinding elements of two aarays
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    // Displaying the sum
    printf("\nSum of matrix:");

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("%.1f\t", result[i][j]);

            if(j == 1) {
                pritnf("\n")
            }
        }
    }
    return 0;
}
```
Example 3: Three-dimensional array
```
// C program to store and print 12 values entered by the user
#include <stdio.h>
int main() {
    int test[2][3][2];

    printf("Enter 12 values: \n");

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3, ++j) {
            for (int k = 0; k < 5; ++k) {
                scanf("%d", &test[i][j][k]);
            }
        }
    }
    // printing  values with with proper index
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3, ++j) {
            for (int k = 0; k < 2; ++k) {
                printf("test[%d][%d][%d] = %d\n", i, j, k, test[i][j][k]);
            }
        }
    }
    return 0;
}
```
*/

#include <stdio.h>

const int CITY = 2;
const int WEEK = 7;

int main() {

    int temperature[CITY][WEEK];

    // Using nested loop to store values in a 2d array

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("City %d, Week %d: ", i+1, j+1);
            scanf("%d", &temperature[i][j]);
        }
    }
    printf("\nDisplaying values: \n\n");

    // using nested loop to diplay values of a 2d array
    for (int i = 0; i < CITY; ++i) {
        for (int j = 0; j < WEEK; ++j) {
            printf("City %d, Day %d = %d\n", i+1, j+1, temperature[i][j]);
        }
    }

    float a[2][2], b[2][2], result[2][2];

    // taking input using nested for loop
    printf("Enter elements of 1st matrix\n");

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j){
            printf("Enter a%d%d: ", i + 1, j+ 1);
            scanf("%f", &a[i][j]);
        }
    }
    // Taking input using nested for loop
    printf("Enter elements of 2nd matrix\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("Enter a%d%d: ", i + 1, j+ 1);
            scanf("%f", &a[i][j]);
        }
    }

    // adding correspinding elements of two arrays
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j]  = a[i][j] + b[i][j];
        }
    }
    // Displaying the sum
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%f1", result[i][j]);

            if (j == 1) {
                printf("\n");
            }
        }
    }

    int test[2][3][2];

    printf("Enter 12 values: \n");

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                scanf("%d", &test[i][j][k]);
            }
        }
    }
    // Printing values with proper index
    printf("\nDisplaying values: \n");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 2; ++k) {
                printf("test[%d][%d][%d] = %d\n", i, j, k, test[i][j][k]);
            }
        }
    }

    return 0;
}