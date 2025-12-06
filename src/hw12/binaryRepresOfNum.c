#include <stdio.h>
#include <stdlib.h>

void toBin(int dec, int* bin)
{
    /*
    it would be possible to count bitwise, since the nums are bitwise in int
    but then I don't think that this can be considered a
    "translation into the binary system"
    */
    int i = 0;
    if (dec < 0) {
        dec = -dec - 1;
        while (dec > 0) {
            bin[i++] = 1 - dec % 2;
            dec /= 2;
        }
        for (int j = i; j < 32; ++j)
            bin[j] = 1;
        return;
    }
    while (dec > 0) {
        bin[i++] = dec % 2;
        dec /= 2;
    }
}

void add(int* a, int* b, int* s)
{
    int k = 0;
    for (int i = 0; i < 32; ++i) {
        k = a[i] + b[i] + k;
        s[i] = k & 1;
        k >>= 1;
    }
}

void printBin(int* bin)
{
    for (int i = 31; i >= 0; --i)
        printf("%d", bin[i]);
    printf("\n");
}

int toDec(int* bin)
{
    int dec = 0;
    if (bin[31]) {
        dec += 1;
        for (int i = 0; i < 31; ++i)
            dec += ((1 - bin[i]) << i);
        return -dec;
    }
    for (int i = 0; i < 31; ++i)
        dec += (bin[i] << i);
    return dec;
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int binA[32] = { 0 };
    int binB[32] = { 0 };

    toBin(a, binA);
    toBin(b, binB);

    int binS[32] = { 0 };
    add(binA, binB, binS);

    printBin(binA);
    printBin(binB);
    printBin(binS);

    int s = toDec(binS);

    printf("%d\n", s);
}
