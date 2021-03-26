#include<stdlib.h>
#include<stdio.h>
#include <string.h>


int SumSquares(int m, int n) {
    int i, sum;
    sum = 0;
    for (i = m; i <= n; ++i) {
        
        sum += i*i;
    printf("%d\n", sum);
        
    };
    return sum;
}

int main() {
    SumSquares(3, 6);
    
    return 0;
}