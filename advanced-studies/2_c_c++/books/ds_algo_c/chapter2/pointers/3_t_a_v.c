/*
Pointer types, void pointer, pointer arithmetic

int * >> int
char * >> char

why strong types?

why not some generic type?

dereference: access/ modify value

int - 4 bytes
char - 1byte
float - 4bytes

*/

#include <stdio.h>

int main() {

    int a = 1025;
    int *p;
    p = &a;

    printf("%d\n", (int)sizeof(int));
    printf("address = %p, value = %d\n", p, *p);

    char *p0;
    p0 = (char*)p;

    printf("%d\n", (int)sizeof(char));
    printf("address = %p, value = %d\n", p0, *p0);

    return 0;
}

