/*
character arrays and pointers

string: group of characters

e.g: "john", "hello world", "i am feeling lucky"

1. How to store strings
    size of array > no. of char in string + 1
    "john" size > 5

    char c[8];
    c[0] = 'j';
    c[1] = 'o';
    c[2] = 'h';
    c[3] = 'n';
    c[4] = '\o';
    
    rule: A, string in c has to be null terminated

2. Arrays and pointers are different types that are used in similar manner  

3. Arrays are always passed to function by reference.

*/

#include <stdio.h>
#include <string.h>





void print(char* c3) {
    int i = 0;
    while(c3[i] != '\0') {
        printf("%c", c3[i]);
        i++;
    }
    printf("\n");
}

int main() {
    char c[6];
    c[0] = 'J';
    c[1] = 'O';
    c[2] = 'H';
    c[3] = 'N';
    c[4] = '\0';
    c[5] = 'N';

    int len = strlen(c);
    printf("%s\n", c);
    printf("%d\n", len);

    char c1[6] = "hello";
    char* c2;
    c2 = c1;
    printf("%s\n", c2);
    printf("%s\n", c1);

    char c3[20] = "hello";
    print(c3);
}
