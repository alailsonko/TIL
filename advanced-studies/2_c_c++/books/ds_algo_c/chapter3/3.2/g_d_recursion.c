#include<stdlib.h>
#include<stdio.h>
#include <string.h>


int SumSquares(int m, int n) {
    if(m < n) {
        printf("%d\n", m);
        return SumSquares(m,n - 1) + n*n;
    } else {
        printf("%d\n", m);
        return n*n;
    }
}

int main() {
    printf("%d\n", SumSquares(3, 6));
    
    return 0;
}