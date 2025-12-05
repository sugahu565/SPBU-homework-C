#include <stdio.h>
#include <stdlib.h>

int sumOfNums(int a)
{
    int sum = 0;
    while (a > 0) {
	sum += a % 10;
	a /= 10;
    }
    return sum;
}

int main()
{
    int a[] = {111, 22, 31, 48, 39, 6686, 333, 998};
    int len = sizeof(a) / sizeof(int);
    int maxSum = 0;
    for (int i = 0; i < len; ++i) {
	int s = sumOfNums(a[i]);
	if (s > maxSum)
	    maxSum = s;
    }
    for (int i = 0; i < len; ++i) {
	if (sumOfNums(a[i]) == maxSum)
	    printf("%d ", a[i]);
    }
    return 0;
}
