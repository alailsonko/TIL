/*
## Types of User-defined Functions in C programming

In this tutorial, you will learn about different approaches
you can take to solve the same problem using functions.

These 4 programs below check wheter the integer entered by the user is a prime
number or not.

The output of all these programs below is the same, and we have created a user-defined
function in each example. However, the approach we have taken in eacg example is
different.

Example 1: No arguments passed and no return value.
```
#include <stdio.h>

void checkPrimeNumber();

int main()
{
    checkPrimeNumber();  // argument is not passed
    return 0;
}

// return type is void meaning doesn't return any value
void checkPrimeNumber()
{
    int n, i, flag = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);
    for (i = 0; i <= n/2; ++i)
    {
        if(n%i == 0)
        {
            flag = 1;
        }
    }
    if (flag == 1) {
        pritnf("%d is not a prime number.", n);
    } else {
        printf("%d is a prime number.", n);
    }
}

The checkPrimeNumber() function takes inut from the user, checks
whether it is a prime number or not and displays it on the screen.

The empty parenthesis in checkPrimeNumber(); statements inside the main()
function indicates that no argument is passed to the function.

The return type of the function is void. Hence, no value is returned from the
function.
```
Example 2: No arguments passed but a return value
```
#include <stdio.h>

int getInteger();

int main() {
    int n, i, flag = 0;

    // no argument is passed
    n = getinteger();

    for(i = 0; i <= n/2; ++i)
    {
        if(n%i == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        printf("%d is not a prime number.", n);
    } else {
        printf("%d is a prime number.", n);
    }
    return 0;
}

int getinteger() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    return n;
}

The empty parenthesis in the n = getinteger(); statement indicates that no
argument is passed to the function. And, the value returned from the function is
assigned to n.

Here, the getInteger() function takes input from the user and returns it. The
code to check whether a number is prime or not is inside the main() fucntion.
```
Example 3: Argument passed but not return value
```
#include <stdio.h>
void checkPrimeAndDisplay(int n);

int main()
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    checkPrimeAndDisplay(n);

    return 0;
}

void checkPrimeAndDisplay(int n)
{
    int i, flag = 0;

    for (i = 0; i <= n/2; ++i)
    {
        if(n%i == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        pritnf("%d is not a prime number", n);
    } else {
        printf("%d is an prime integer." n);
    }
}
The integer value entered by the user is passed to the checkPrimeAndDisplay()
function.

Here, the checkPrimeAndDisplay() function checks whether the argument passed
is a prime number ror not and isplays the appropriate message.
```
Example 4: Argument passed and a return value
```
#include <stdio.h>
int checkPrimeNumber(int n);

int main() {
    int n, flag;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // n is passed to the checkPrimeNumber() function
    // the return value is assigned to the flag variable
    flag = checkPrimeNumber(n);

    if(flag == 1) {
        pritnf("%d is not a prime number", n);
    } else {
        printf("%d is an prime integer." n);
    }
    return 0;
}

int checkPrimeNumber(int n)
{
    int i;
    for (i = 0; i <= n/2; ++i)
    {
        if (n%i == 0){
            return 1;
        }

    }
    return 0;
}

The input from the user is passed to the checkPrimeNumber() function.

the checkPrimeNumber() function checks whether the passed argument is prime
or not.

If the passed argument is a prime number, the function returns 0.
If the passed argument is a non-prime number, the function returns 1. The return 
value is assigned to the flag variable.

Depending on whether flag is 0 or 1, an appropriate message is printed from 
the main() function.
```
## Which approach is better?
----------------------------
Well, it depends on the problem you are trying to solve. In this case,
passing argument and returning a value from the function(example 4) is better.

A funcion should perform a specific task. The checkPrimeNumber() function doesn't
take input from the user nor it displays the appropriate message. It only checks 
whether a number is prime or not.
----------------------------
*/

# include <stdio.h>

void checkPrimeNumber();
int getInteger();
void checkPrimeAndDisplay(int n);
int checkPrimeNumberWithReturn(int n);

int main()
{
    checkPrimeNumber();

    int n, i, flag = 0;
    n = getInteger();

    for (i = 2; i <= n/2; ++i){
        if(n%i == 0){
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("Example 2: %d is not a prime number.\n", n);
    } else {
        printf("Example 2: %d is prime number.\n", n);
    }
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    checkPrimeAndDisplay(n);

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    flag = checkPrimeNumberWithReturn(n);
    
    if (flag == 1) {
        printf("Example 4: %d is not a prime number.\n", n);
    } else {
        printf("Example 4: %d is a prime number.\n", n);
    }

    return 0;
}

void checkPrimeNumber()
{
    int n, i, flag = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 2; i <= n/2; ++i)
    {
        if (n%i == 0)
        {
            flag = 1;
        }
    }
    if (flag == 1) {
        printf("Example 1: %d is not a prime number.\n", n);
    } else {
        printf("Example 1: %d is a prime number.\n", n);
    }


}


int getInteger()
{
    int n;
    printf("Enter an positive integer: ");
    scanf("%d", &n);

    return n;
}


void checkPrimeAndDisplay(int n)
{
    int i, flag = 0;
    for (i = 2; i <= n/2; ++i)
    {
        if(n%i == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("Example 3: %d is not a prime number.\n", n);
    } else {
        printf("Example 3: %d is a prime number.\n", n);
    }
}

int checkPrimeNumberWithReturn(int n)
{
    int i;

    for (i = 2; i <= n/2; ++i)
    {
        if (n%i == 0) {
            return 1;
        }
    }
    return 0;
}