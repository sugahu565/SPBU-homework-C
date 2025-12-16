#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float x;
    scanf("%f", &x);
    const float x2 = x * x;
    printf("%f", (x2 + 1) * (x2 + x) + 1);
    return 0;
}
