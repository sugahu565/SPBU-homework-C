#include <stdio.h>
#include <stdlib.h>

int palyndrome(int a, int end)
{
    int start = 1;
    while (start < end) {
	int b1 = a & start, b2 = a & end;
	if (b1 > 0 && b2 == 0 || b1 == 0 && b2 > 0)
	    return 0;
	start *= 2;
	end /= 2;
    }
    return 1;
}

int main()
{
    int n = 100, twoDegree = 1;
    for (int i = 1; i <= n; ++i) {
	if (i >= twoDegree)
	    twoDegree *= 2;
	if (palyndrome(i, twoDegree / 2))
	    printf("%d ", i);
    }
    printf("\n");
    return 0;
}
