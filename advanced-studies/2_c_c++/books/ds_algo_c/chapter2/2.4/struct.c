#include <stdio.h>

/*
In C programming, a struct (or structure)
is a collection of variables(can be of different types)
under a single name.

## How to define structures?
before you can create structure variables, you  
need to define its data typ. To define a struct, the
struct keyword is used.

### Syntax of struct 

struct structureName
{
    dataType member1;
    dataType member1;
    ...
};

Here is an example:
struct Person
{
    char name[50];
    int citNo;
    float salary;
};

Here, a derived type struct Person is defined. 
Now, you can create variables of this type.

## Create struct variables

when a struct type is declared, no storage or 
memory is allocated. To allocate memory of a given
structure type and work with it, we need to create
variables.

Here's how we create structure variables:

struct Person
{
    char name[50];
    int citNo;
    float salary;
}
int main() 
{
    struct Person person1, person2, p[20];
    return 0;
}

Another way of creating a struct variable is:

struct Person 
{
    char name[50];
    int citNo;
    float salary;
} person1, person2, p[20];

In both cases, two variables person1, person2, 
and an array variable p having 20 elements of
type struct Person are created.


## Access members of a structure

There are two types of operators used for accessing
members of a structure.

1. . - Member operator
2. -> - Structure pointer operator(Will be discussed in the next tutorial)

Suppose, you want to access the salary of person2.
Here's how you can do it.

person2.salary  


## keyword typedef

we use the typedef keyword to create an alias
name for data types, it is commonly used with 
structures to simplify the syntax of declaring
variables

this code:

struct Distance {
    int feet;
    float inch;
};

int main() {
    struct Distance d1, d2;
}

is equivalent to

typedef struct Distance {
    int feet;
    float inch;
} distances;

int main() {
    distances d1, d2;
}

## Nested structures

you can create structures within a structure
in C programming. For example,

struct complex 
{
    int imag;
    float real;
}

struct number 
{
    struct complex comp;
    int integers
} num1, num2;

Suppose, you want to set imag of num2 
variable to 11. Here's how you can do it:

num2.comp.imag = 11;

## Why structs in C?

suppose, you want to store information about a person:
his/her name, citizenship number, and salary. You can
create different variables name, citNo, and salary to
store this information.

what if you need to store information of more than one
person? Now, you need to create different variables
for each information per person: name1, citNo1,
salary1, name2, citNo2, salary2, etc.

A better approach would be to have a collection
of all related information under a single name
.Person structure and use it for every person.

*/

struct Distance
{
    int feet;
    float inch; 
} dist1, dist2, sum; 

int main() 
{
    printf("1st distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist1.feet);

    printf("Enter inch: ");
    scanf("%f", &dist1.inch);
    printf("2nd distance\n");

    printf("Enter feet: ");
    scanf("%d", &dist2.feet);

    printf("Enter inch: ");
    scanf("%d", &dist2.feet);

    // adding feet
    sum.feet = dist1.feet + dist2.feet;
    // adding inch
    sum.inch = dist1.inch + dist2.inch;

    // changing to feet if inch is greater than 12
    while (sum.inch > 12)
    {
        ++sum.feet;
        sum.inch = sum.inch - 12;
    }  

    printf("Sum of distances = %d\'-%.1f\"", sum.feet, sum.inch);
    printf("value");
}