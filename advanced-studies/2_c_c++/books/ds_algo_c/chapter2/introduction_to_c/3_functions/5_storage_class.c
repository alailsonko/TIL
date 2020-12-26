/*
## C Storage Class

In this tutorial, you will learn about and lifetime of local and global
variables. Also, you will learn about static and register variables.

Every variable in C programming has two properties: types and storage class. 

Type refers to the data type of a variable. And, storage class determines the
scope, visibility and lifetime of a variable.

There are 4 types of storage class:

1. automatic
2. external
3. static
4. register

## Local Variable
--------------------
The variables declared inside a block are automatic or local variables. The local
variables exist only inside the block in which it is declared.

Lets take an example.

```
int main(void) {
    
    for (int i = 0; i < 5; ++i) {
    printf("C programming"); 
    }
    printf("%d\n", i);
    return 0;
}

When you run the above program, you will get an error undeclared
identifier i. Its because i is declared insdie the for loop block. Outsid
of the block, its undeclared.

```
Lets take another example.
```
int main() {
    int n1;
}

void func() {
    int n2;
}
In the above example, n1 is local to main() and n2 is local to func().

This means you cannot access the n1 variable inside func() as it only exists
inside main(). Similarly, you cannot access the n2 variable inside main() as it
only exists inside func().
```
### Global Variable
----------------------
Variables that are declared outside of all functions are known
as external on global variables. They are accessible from any function inside 
the program.
Example 1: Global Variable
```
#include <stdio.h>
void display()

int n = 5;

int main()
{
    ++n;
    display()
    return 0;
}
void display()
{
    ++n;
    printf("n = %d", n);
}
output> n = 7

Suppose, a global variable is declared in file1. If you try to use that variable
in a different file file2, the compiler will complain. To solve this problem,
keyword extern is used in file2 to indicate that the external variable is declated
in another file.
```
------------------------------------------------
## Register variable
The register keyword is used to declare register variables. Register Variables
were supposed to be faster than local variables.

However, modern compilers are very good at code optimization, and there is a rare
chance that using register variables will make your program faster.

Unless you are working on embedded systems where you know how to optimize 
code for the given application, there is no use of register variables.

## Static Variable
A static variable is declared by using the static keyword. For example:

> static int i;

The value of a static variable persists until the end of the program.

Example 2: static variable
```
#include <stdio.h>
void display();

int main()
{
    display();
    display();
}
void display()
{
    static int c = 1;
    c += 5;
    printf("%d", c);
}

During the first function call, the value of c is initialized to 1. Its value is 
increased by 5. Now, the value of c is 6, which is printed on the screen.

During the second function call, c is not initialized to 1 again. Its because c
is a static variable. The value c is increased by 5. Now, its value will be 11,
which is printed on the screen.

```
*/

#include <stdio.h>
void display();

int n = 5;

int main()
{
    ++n;
    display();
    display();
    display();

    return 0;
}


void display()
{   
    static int c = 1;
    c += 5;
    ++n;
    printf("n = %d\n, c = %d\n", n, c);
}