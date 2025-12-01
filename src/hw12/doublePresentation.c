#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef union Number {
    double num;
    char bin[8];
} Number;

int findExpon(Number a)
{
    int expon = 0;
    int diff = 0;

    for (int i = 4; i < 8; i++) {
        expon += ((a.bin[6] >> i) & 1) << diff;
        diff++;
    }

    for (int i = 0; i < 7; i++) {
        expon += ((a.bin[7] >> i) & 1) << diff;
        diff++;
    }
    return expon - 1023;
}

double findMant(Number a)
{
    long long mantissa = 0;
    int diff = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            int k = ((a.bin[i] >> j) & 1);
            mantissa += ((long long)((a.bin[i] >> j) & 1)) << diff;
            diff++;
        }
    }
    for (int j = 0; j < 4; ++j) {
        mantissa += ((long long)((a.bin[6] >> j) & 1)) << diff;
        diff++;
    }
    return (double)mantissa / (double)((long long)1 << 52);
}

int main()
{
    Number a;

    printf("Write number: ");
    scanf("%lf", &(a.num));

    int n = 1, littleEndian = 0;
    if (*(char*)&n == 1)
        littleEndian = 1;

    int sign = (a.bin[7] >> 7) & 1;
    int exp = findExpon(a);
    double mant = findMant(a);

    int accur = (1 << 16);
    if (sign)
        printf("-1.%d*2^%d\n", (int)(mant * accur), exp);
    else
        printf("1.%d*2^%d\n", (int)(mant * accur), exp);
    return 0;
}