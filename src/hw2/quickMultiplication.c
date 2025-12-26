#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float x;
    scanf("%f", &x);
    const float X2 = x * x;
    printf("%f", (X2 + 1) * (X2 + x) + 1);
    return 0;
}
