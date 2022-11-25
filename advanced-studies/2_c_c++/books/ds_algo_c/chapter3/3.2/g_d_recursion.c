#include<stdlib.h>
#include<stdio.h>
#include <string.h>


int SumSquares(int m, int n) {
    if(m < n) {
        printf("m %d\n", m);
        printf("n %d\n", n);
        return m*m + SumSquares(m + 1,n);
    } else {
        printf("%d\n", m);
        return m*m;
    }
}

int main() {
    printf("%d\n", SumSquares(3, 6));

    return 0;
}