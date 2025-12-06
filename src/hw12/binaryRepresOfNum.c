#include <stdio.h>
#include <stdlib.h>

int* toBin(int dec)
{
    /*
    it would be possible to count bitwise, since the nums are bitwise in int
    but then I don't think that this can be considered a
    "translation into the binary system"
    */
    int i = 0;
    int* bin = calloc(32, sizeof(int));
    if (dec < 0) {
        dec = -dec - 1;
        while (dec > 0) {
            bin[i++] = 1 - dec % 2;
            dec /= 2;
        }
        for (int j = i; j < 32; ++j)
            bin[j] = 1;
        return bin;
    }
    while (dec > 0) {
        bin[i++] = dec % 2;
        dec /= 2;
    }
    return bin;
}

int* binAdd(const int* a, const int* b)
{
    int k = 0;
    int* s = calloc(32, sizeof(int));
    for (int i = 0; i < 32; ++i) {
        k = a[i] + b[i] + k;
        s[i] = k & 1;
        k >>= 1;
    }
    return s;
}

void printBin(const int* bin)
{
    for (int i = 31; i >= 0; --i)
        printf("%d", bin[i]);
    printf("\n");
}

int toDec(const int* bin)
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
