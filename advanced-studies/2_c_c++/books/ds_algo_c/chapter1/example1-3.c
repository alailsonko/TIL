#include <stdio.h>

#define MaxIndex 100

/* int Find(int A[])
{
    int j;
	    
    for(j = 0; j < MaxIndex ; ++j) {
	if(A[j] < 0) {
		return j;
	}
    }
    return -1;
} */

typedef int SearchArray[];

int Find(SearchArray A)
{
  int i = 0;

  while((A[i] >= 0) && (i < MaxIndex)) {
    ++i;
  }
  return (i < MaxIndex) ? i : -1;
}

int main(void)
{
	int A[MaxIndex];
	int i;

	for (i = 0; i < MaxIndex; ++i) A[i] = i*i;
  // A[17] = -A[17];
  
	printf("First negative integer in A found at index = %2d.\n", Find(A));
}
