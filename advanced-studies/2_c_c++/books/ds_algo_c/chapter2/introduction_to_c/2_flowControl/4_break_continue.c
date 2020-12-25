/*
## C break and continue
We learned about loops in previous tutorials. In this tutorial, we will learn
to use break and continue statements with help of examples.

#### C break
--------------------
The break statement ends the loop immediately when it is encountered. its
syntax is:

> break;

The break statement is almost always used with if...else statements inside the 
loop.

##### How break statement works?
```While loop
while (testExpression) {
    // code
    if(condition to break) {
        break;
    }
    // codes 
}
// if condition break pass then code after while loop runs
```
```do...while loop
do {
    // codes
    if (condition to break) {
        break;
    }
} while (testExpression)
// if condition break pass then code after do...while loop runs
```
```for loop
for (init; testExpression; update) {
    // codes
    if(condition to break) {
        break;
    }
    // codes
}
```
Example 1: break statement
```
// Program to calculate the sum of numbers (10 numbers max)
// If the user enters a negative number, the loop terminates
#include <stdio.h>
int main() {
    int i;
    double number, sum = 0.0;

    for (i = 0; i < 10; i++) {
        printf("Enter a n%d: ", i);
        scanf("%lf", &number);

        // if the user enters a negative number, break the loop
        if (number < 0.0) {
            break;
        }

        sum += number; // sum = sum + number;
    }

    printf("Sum = %.2lf\n", sum);

    return 0;
}

Output>
Enter a n1: 2.4
Enter a n2: 4.5
Enter a n3: 3.4
Enter a n4: -3
Sum = 10.30

This program calculates the sum of a maximum of 10 numbers. Why a
maximum of 10 numbers? its because if the user enters a negative number, the
break statement is executed. This will end the for loop, and the sum is displayed.

In C, break is also used with the switch statement. This will be discussed in the
next tutorial.
```
----------------------
## C continue
--------------------------
The continue statement skips the current iteration of the loop and continue
with the next iteration, its syntax is:

> continue;

The continue statement is almost always used with the if...else statement.

### How continue statement works?
```while loop
// the loops continues if test pass
 while (test expression) {
     // codes
     if (test expression) {
         continute;
     }
     // codes  
 }
```
```do...while loop
do {
    // codes
    if (test expression) {
        continute;
    }
    // codes
}
while (test expression);
```
```
for (init; test expression; update) {
    // codes
    if (test expression) {
        continue;
    }
    // codes
}
```
Example 2: continue statement
```
// Program to calculate the sum of numbers (10 numbers max)
// If the user enters a negative number, its not added to the result
#include <stdio.h>
int main() {
    int i;
    double number, sum = 0.0;
    for (i = 0; i < 10; i++) {
        printf("Enter a n%d: ", i);
        scanf("%lf", &number);

        if (number < 0.0) {
            continue;
        }
        sum += number; // sum = sum + number
    }
    printf("Sum = %.2lf", sum);
}

output>
Enter a n1: 1.1
Enter a n2: 2.2
Enter a n3: 5.5
Enter a n4: 4.4
Enter a n5: -3.4
Enter a n6: -45.5
Enter a n7: 34.5
Enter a n8: -4.2
Enter a n9: -1000
Enter a n10: 12
Sum = 59.70

In this program, when the user enters a positive number, the sum is calculated
using sum += number; statement

When the user enters a negative number, the continute statement is executed
and it skips the negative number from the calculation.
```
*/
#include <stdio.h>

int main () {
    int i;
    double number, sum = 0.0;

    for (i = 0; i < 10; i++) {
        printf("Enter a n%d: ", i);
        scanf("%lf", &number);

        if ( number < 0.0) {
            break;
        }
        sum += number;
    }
    printf("Sum = %.2lf\n", sum);
    
    for (i = 0; i < 10; i++) {
        printf("Enter a n%d: ", i);
        scanf("%lf", &number);

        if( number < 0.0) {
            continue;
        }
        sum += number;
    }
    printf("Sum = %.2lf\n", sum);

    return 0;
}