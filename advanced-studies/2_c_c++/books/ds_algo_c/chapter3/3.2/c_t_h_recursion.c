#include <stdlib.h>
#include <stdio.h>

int SumSquare(int m, int n){
    int middle;
    if(m == n) {
        printf("%d\n", m*m);
        return m*m;
    } else {
        middle = (m + n) / 2;
        printf("%d\n", SumSquare(m, middle) + SumSquare(middle + 1, n));
        return SumSquare(m, middle) + SumSquare(middle + 1, n);
    }
}

int main(){

    printf("%d\n", SumSquare(7, 9));
    return 0;
}