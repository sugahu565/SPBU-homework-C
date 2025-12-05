#include<stdio.h>
#include<stdlib.h>

void printBin(unsigned int a)
{
    unsigned int mask = (1 << 31);
    while (mask > 0) {
	printf("%d", (a & mask) > 0);
	mask >>= 1;
    }
    printf("\n");
}

int getMax(unsigned int num)
{
    unsigned int maxNum = num;
    int lastBit;
    for (int i = 0; i < 31; ++i) {
	lastBit = num & 1;
	num >>= 1;
	num |= (lastBit << 31);
	if (maxNum < num)
	    maxNum = num;
    }
    return maxNum;
}

int test1(void)
{
    unsigned int num = 1;
    unsigned int expected = 2147483648;
    return num == expected;
}

int test2(void)
{
    unsigned int num = 0;
    unsigned int expected = 0;
    return num == expected;
}

int test13(void)
{
    unsigned int num = 53;
    unsigned int expected = 3556769792;
    return num == expected;
}

int main(void)
{
    unsigned int num;
    scanf("%d", &num);

    unsigned int maxNum = getMax(num);
    printBin(num);
    printBin(maxNum);
    printf("%u\n", maxNum);

    return 0;
}
