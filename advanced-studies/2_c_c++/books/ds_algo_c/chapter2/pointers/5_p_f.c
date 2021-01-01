/*
pointers as function arguments - call by reference
*/

#include <stdio.h>

void Increment(int *a) {
    *a = *a + 1;
    printf("address: a = %p\n", a);
    printf("value: a = %d\n", *a);
}

int main() {
    int a;

    a = 10;

    Increment(&a);
    printf("address: a = %p\n", &a);
    printf("value: a = %d\n", a);
}