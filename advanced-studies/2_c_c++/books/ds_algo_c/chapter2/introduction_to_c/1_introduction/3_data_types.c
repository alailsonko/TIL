/*
## C Data Types

In this tutorial, you will lear about basic data 
types such as int, float, char etc.
in C programming. 

In C programming, data types are declarions for variables.
This determines the type and size of data associated with variables.
For example,

> int myVar;

Here, myVar is a variable of int(integer) type. The size of int is 4 bytes


## Basic types

-------------------------
Here's a table containing commonly used types in 
C programming for quick

Type	Size (bytes)	Format Specifier
int	at least 2, usually 4	%d, %i
char	1	%c
float	4	%f
double	8	%lf
short int	2 usually	%hd
unsigned int	at least 2, usually 4	%u
long int	at least 4, usually 8	%ld, %li
long long int	at least 8	%lld, %lli
unsigned long int	at least 4	%lu
unsigned long long int	at least 8	%llu
signed char	1	%c
unsigned char	1	%c
long double	at least 10, usually 12 or 16	%Lf

#### Int
    intergers are whole numbers that can have both zero,
    positive and negative values but no decimal values.
    For example: 0, -5, 10.

    We can use int for declaring an integer variable.

    > int id;

    Here, id is a variable of type integer.

    You can declare multiple variables at once in C programming.
    For example,

    > int id, age;

    The size of int is usually 4 bytes (32bits). And, it can
    take 2^32 distinct states from -2147483648 to 2147483647 

#### float and double
    float and double are used to hold real numbers.

    > float salary;
    > double price;

    In C, floating-point numbers can also be represented 
    in exponential. For example,

    > float normalizationFactor = 22.442e2;

    what's the difference between float and double?

    The size of float(single precision float data type) is 4 bytes.
    And the size of double(single precision float data type) is 8 bytes.

#### char
    Keyword char is used for declaring character type variables.
    For example,

    > char test = 'h';

    The size of the character variable is 1 byte.

#### void
    void is an incomplete type. It means 'nothing' or 'no type'.
    You can think of void as absent.

    For example, if a function is not returning anything,
    its return type should be void.

    Note that, you cannot create variables of void type.

#### short and long

    If you need to use a large number, you can use a type specifier long. Here's 
    how: 

    > long a;
    > long long b;
    > long double c;

    Here variables a and b can store integer values. And, c can store
    a floating-point number.

    If you are sure, only a small integer ([-32,767, +32,767] range) will be
    used, you can use short.

    > short d;

    You can always check the size of a variable using the sizeof() operator.

    ```C
    #include <stdio.h>
    int main() {
        short a;
        long b;
        long long c;
        long double d; 

        printf("size of short = %d bytes\n", sizeof(a));
        printf("size of long = %d bytes\n", sizeof(b));
        printf("size of long long = %d bytes\n", sizeof(c));
        printf("size of long double = %d bytes\n", sizeof(d));
        return 0;
    }
    ```
#### signed and unsigned
    In C, signed and unsigned are type modifiers. You can alter the data storage
    of a data type by using them. For example,

    > unsigned int x;
    > int y;

    Here, the variable x can hold only zero and positive values
    because we have used the unsigned modifier.

    Considering the size of int is 4 bytes, variable y can hold
    values from -2^31 to 2(^31)-1, whereas variable x can hold values from 0 to (2^32)-1

    Other data types defined in C programming are:

    * bool type
    * Enumerated type
    * Complex types

#### Derived Data Types
    Data types that are derived from fundamental data types are derived types.
    For example: arrays, pointers, functions types, structures, etc.

    We will learn about these derived data types in later tutorials.
*/



/*
Checking the size of variables
*/

#include <stdio.h>

int main() {
    int a;
    char b;
    float c;
    double d;
    short int e;
    unsigned int f;
    long int g;
    long long int h;
    unsigned long int i;
    unsigned long long int j;
    signed char k;
    unsigned char l;
    long double m;
    
    printf("size of int = %ld bytes\n", (long)sizeof(a));
    printf("size of char = %ld bytes\n", (long)sizeof(b));
    printf("size of float = %ld bytes\n", (long)sizeof(c));
    printf("size of double = %ld bytes\n", (long)sizeof(d));
    printf("size of short int = %ld bytes\n", (long)sizeof(e));
    printf("size of unsigned int = %lu bytes\n", (unsigned long)sizeof(f));
    printf("size of long int = %ld bytes\n", (long)sizeof(g));
    printf("size of long long int = %ld bytes\n", (long)sizeof(h));
    printf("size of unsigned long int = %lu bytes\n", (unsigned long)sizeof(i));
    printf("size of unsigned long long int = %lu bytes\n", (unsigned long)sizeof(j));
    printf("size of signed char = %ld bytes\n", (long)sizeof(k));
    printf("size of unsigned char = %ld bytes\n", (long)sizeof(l));
    printf("size of long double = %ld bytes\n", (long)sizeof(m));
    return 0;
}