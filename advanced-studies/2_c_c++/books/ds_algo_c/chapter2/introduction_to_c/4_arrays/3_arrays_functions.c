/*
## Pass arrays to a function in C

In this tutorial, you will learn to pass arrays(both one-dimensional and
multidimensional arrays) to a function in C programming with the help
of examples.

In C programming, you can pass en entire array to functions. Before we learn that,
lets see how you can pass individual elements of an array to functions.

## Passing individual array elements.

Passing array elements to a function is similar to passing
variables to a function. 

Example 1: Passin an array.
```
#include <stdio.h>
void display(int age1, int age2) {
    printf("%d\n", age1);
    printf("%d\n", age2);
}
int main() {
    int ageArray[] = {2,8,4,12};

    // passing scond and third elements to display()
    display(ageArray[1], ageArray[2]);
    return 0;
}
```
Example 2: passing arrays to functions
```
// program to calculate the sum of array elements by passing to a function
#include <stdio.h>
float calculateSum(float age[]);

int main() {
    float result, age[] = {23.4, 55, 22.6, 3.40.5, 18};

    // age array is passed to calculateSum()
    result = calculateSum(age);
    printf("Result = %.2f\n", result);
    return 0;
}

float calculateSum(float age[]) {
    float sum = 0.0;

    for (int i = 0; i < 5; ++i) {
        sum += age[i];
    }
    return sum;
}

output>
Result = 162.50

To pass an entire array to a function, only the name of the array is passed as an argument.

result = calculateSum(age)

However, notice the use of [] in the function definition.

```
float calculateSum(float age[]) {
    ....... 
}
This informs the compiuler that you are passing a one-dimensional array to the
function. 
```
```
## Passing Multidimensional arrays to a function
To pass multiimensional arrays to function, only the name of the aray is passed
to the fucntion( similar to one -dimensional arrays).

Example 3: pasing two-dimensional arrays
```
#include <stdio.h>
void displayNumbers(int num[2][2]);
int main(){
    int num[2][2];
    priintf("Enter 4 numbers: \n");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &num[i][j]);
        }
    }

    // passing multi-dimensional array to a function
    displayNumbers(num);
    return 0;
}

void displayNumbers(int num[2][2]) {
    printf("displaying: \n");
    for(int i = 0; i < 2; ++i) {
        printf("%d\n", num[i][0j]);
    }
}
```

|Note: In C programming, you can pass arrays to functions, however, you 
cannot return arrays from functions.
*/
#include <stdio.h>
void display(int age1, int age2) {
    printf("%d\n", age1);
    printf("%d\n", age2);
}

float calculateSum(float age[]);
void displayNumbers(int num[2][2]);

int main() {
    int ageArray[] = {2,8,4,12};
    // passing second and third elements to display()
    display(ageArray[1], ageArray[2]);

    float result, age[] = {23.4,55,22.6,3,40.5,18};

    result = calculateSum(age);
    printf("Result = %.2f\n", result);

    int num[2][2];
    printf("Enter 4 numbers: \n");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &num[i][j]);
        }
    } 
     
    displayNumbers(num);
    
    return 0;
}

void displayNumbers(int num[2][2]) {
    printf("Displaying:\n");
    for (int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            printf("%d\n", num[i][j]);
        }
    }
}

float calculateSum(float age[]) {
    float sum = 0.0;

    for (int i = 0; i < 6; ++i) {
        sum += age[i];
    }
   return sum;
}
