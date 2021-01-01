#include <stdio.h>
#include <stdlib.h>
/*
1.the memory ram has adress of memory

2.and each variable is allocated in a adress in the memory

3.each byte has one adress.

4.each type of the variable allocates different bytes of memory.

5.what is a pointer?
> variables that store address of another variable.


     memory
208 | b = 10
204 | a = 4


64 | P = 208  >>> 208 | b = 10

int a;
int *P;
P = &a;
s = 5;
print P
print &a
print &P

*/

int main() {
    int a;
    int *P;
    P = &a;
    a = 5;
    printf("%p\n", P);
    printf("%p\n", &a);
    printf("%p\n", &P);
    P = &a;
    *P = a;
    printf("%d\n", *P);
    printf("%p\n", &P);
    printf("%d\n", a);
    *P = 11;
    printf("%d\n", *P);
    printf("%d\n", a);
    

    return 0;
}