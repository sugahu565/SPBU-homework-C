#include <stdio.h>
#include <stdlib.h>

int notNeg(int a)
{
    if (a >= 0)
        return 1;
    return -1;
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (b == 0) {
        printf("div by zero\n");
        return 0;
    }

    int signA = notNeg(a);
    int signB = notNeg(b);

    a = abs(a);
    b = abs(b);

    int k = 0;
    while (a >= 0) {
        a -= b;
        k += 1;
    }
    a += b;
    k -= 1;

    if (signA > 0)
        printf("%d\n", signB * k);
    else
        printf("%d\n", -signB * (k + (a > 0)));
    return 0;
}
