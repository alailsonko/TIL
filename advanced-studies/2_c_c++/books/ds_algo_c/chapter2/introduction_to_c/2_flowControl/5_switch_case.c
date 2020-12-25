/*
## C switch Statement
In this tutorial, you will learn to create the C switch statement in C programming
with the help of an example.

The switch statement allows us to execute one code block among many alternatives

You can do the same thing with the if...else...if ladder. However, the syntax of
the switch statement is much easier to read and write.

#### Syntax of switch...case
```
switch (expression) {
    case constant1:
        // statements
        break;
    case constant2:
        // statements
        break;
    .
    .
    .
    default:
        // default statements
}
```
## How does the switch statement work?
-------------------------------
The expression is evaluated once and compared with the values of each case label.
    * If there is a match, the corresponding statements after the matching label
    are executed. For example if the value of the expression is equal to constant2,
    statements after case constant2: are executed until break us encountered.
    * If there is no match, the default statements are executed.
    
    | Note: if we not break, all statements after the matching label are executed.
    | Note: By the way, the default clause inside the switch statement is optional.

Switch statement Flowchart

            |
            |
        single expression
            |
        equals to case ___yes___ code block 1 _
        constant1?                             |
            |                                  |
            | no                               |
            |                                  |
        equals to case ___yes___ code block 2 _|
        constant2                              |
            .                                  |
            . no                               |
            .______________ default code_______|
                                               |
                                               |
-------------------------------------------------
Example: Simple Calculator

```
// Program to create a simple calculator
#include <stdio.h>
int main() {
    char operator;
    double n1, n2;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &n1, &n2);

    switch(operator){
        case '+':
            printf("%.1lf + %.1lf = %.1lf", n1, n2, n1+n2);
            break;
        case '-':
            printf("%.1lf - %.1lf = %.1lf", n1, n2, n1-n2);
            break;
        case '*':
            printf("%.1lf * %.1lf = %.1lf", n1, n2, n1*n2);
            break;
        case '/':
            printf("%.1lf / %.1lf = %.1lf", n1, n2, n1/n2);
            break;
        // operator doesn't match any case constant +. -. *, /
        default:
            printf("Error! operator is not correct");
    }
    return 0;
}

Output>
Enter an operator(+, -, *, /)
Enter two operands: 32.5
12.4
32.5 - 12.4 = 20.1

The - operator entered by the user is stored in the operator variable. And, two
operands 32.5 and 12.4 are stored in variables n1 and n2 respectively.
Since the operator is -, the control of the program jumps to

> printf("%.1lf - %.1lf = %.1lf", n1, n2, n1 - n2);
```
Finally, the break statement terminates the switch statement.
*/

#include <stdio.h>

int main () {
    
    char operator;
    double n1, n2;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &n1, &n2);

    switch(operator){
        case '+':
            printf("%.1lf + %.1lf = %.1lf\n", n1, n2, n1+n2);
            break;
        case '-':
            printf("%.1lf - %.1lf = %.1lf\n", n1, n2, n1-n2);
            break;
        case '*':
            printf("%.1lf * %.1lf = %.1lf\n", n1, n2, n1*n2);
            break;
        case '/':
            printf("%.1lf / %.1lf = %.1lf\n", n1, n2, n1/n2);
            break;
        // operator doesn't match any case constant +, -, *, /,
        default:
            printf("Error! operator is not correct");
    }
}