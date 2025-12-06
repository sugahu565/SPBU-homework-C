#include "binaryRepresOfNum.h"
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int* binA = toBin(a);
    int* binB = toBin(b);

    int* binS = binAdd(binA, binB);

    printBin(binA);
    printBin(binB);
    printBin(binS);

    int s = toDec(binS);

    printf("%d\n", s);

    free(binA);
    free(binB);
    free(binS);

    return 0;
}

