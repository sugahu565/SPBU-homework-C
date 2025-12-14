#include "binaryRepresOfNum.h"
#include<stdio.h>
#include<stdlib.h>


int nums[7] = {0, 1, 5, 11, -1, -8, -13};

int binNums[7][32] = {
    {0}, // 0

    {1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0}, //1

    {1, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0}, //5

    {1, 1, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0}, //11

    {1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1}, //-1

    {0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1}, //-8

    {1, 1, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1}, //-13

};

int sumNums[8][3] = {
    {0, 0, 0},
    {1, 0, 1},
    {-1, 0, -1},
    {1, 1, 2},
    {3, 7, 10},
    {7, 1, 8},
    {-1, -2, -3},
    {-1, 5, 4}
};

void testPrint(int result, int number)
{
    if (result)
        printf("Test №%d passed!\n", number);
    else
        printf("Test №%d failed!\n", number);
}

int equalBin(int* a, int* b)
{
    for (int i = 0; i < 32; ++i)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int testToBin()
{
    printf("==========Start testing toBin==========\n");
    int passed = 0;
    for (int i = 0; i < 7; ++i)
    {
        int* bin = toBin(nums[i]);
        int result = equalBin(bin, binNums[i]);
        free(bin);

        testPrint(result, i + 1);
        passed += result;
    }
    return passed;
}

int testToDec()
{
    printf("==========Start testing toDec==========\n");
    int passed = 0;
    for (int i = 0; i < 7; ++i)
    {
        int result = (nums[i] == toDec(binNums[i]));
        testPrint(result, i + 1);
        passed += result;
    }
    return passed;
}

int testBinSum()
{
    printf("==========Start testing binSum==========\n");
    int passed = 0;
    for (int i = 0; i < 8; ++i)
    {
        int* bin1 = toBin(sumNums[i][0]);
        int* bin2 = toBin(sumNums[i][1]);
        int* sum = binSum(bin1, bin2);
        int decSum = toDec(sum);
        int result = (decSum == sumNums[i][2]);

        testPrint(result, i + 1);

        free(bin1);
        free(bin2);
        free(sum);
        passed += result;
    }
    return passed;
}

int main(void)
{
    int passed = 0;
    passed += testToBin();
    passed += testToDec();
    passed += testBinSum();
    printf("==========Passed %d/22==========\n", passed);
    return 0;
}
