#include "../../src/hw6/sortList.h"
#include "utils.h"
#include<stdlib.h>
#include<stdio.h>

int testEmpty(list l)
{
    return (l.len == 0);
}

int testOneElem(list l)
{
    push(&l, 1);
    return l.len == 1 && getElem(&l, 0);
}

int testReversed(list l)
{
    for (int x = 4; x >= 0; --x)
        push(&l, x);
    for (int x = 0; x < 5; ++x)
        if (getElem(&l, x) != x)
            return 0;
    return 1;
}

int testPopEmpty(list l)
{
    pop(&l, 1);
    return (l.len == 0);
}

int testPopFirst(list l)
{
    fillList(l, 0, 5);
    pop(&l, 0);
    return (getElem(&l, 0) == 1);
}

int testPopLast(list l)
{
    fillList(l, 0, 5);
    pop(&l, 4);
    return (getElem(&l, 3) == 3);

}

int testRandom(list l, int* arr, int maxLen)
{
    int randomLenght = rand() % maxLen;
    randomElements(arr, randomLenght);

    for (int i = 0; i < randomLenght; ++i)
        push(&l, arr[i]);

    sort(arr, randomLenght);
    return sameElements(l, arr);
}

int main()
{
    // for beauty
    printf("=======RUN TESTS=======\n");
    // also for beauty
    int (*testFunctions[])(list l) = {testEmpty, testOneElem, testReversed, testPopEmpty, testPopFirst, testPopLast};
    int countOfSimpleTests = 6, passedTests = 0, countOfAllTests = 15;
    list l;
    init(&l);
    for (int i = 0; i < countOfSimpleTests; ++i)
    {
        if (testFunctions[i](l)) {
            printf("Test %d passed!\n", i + 1);
            passedTests++;
        } else
            printf("Test %d failed!\n", i + 1);
        destroy(&l);
    }
    int lenMaxTest = 100;
    int arr[lenMaxTest];
    for (int i = countOfSimpleTests; i < countOfAllTests; ++i)
    {
        if (testRandom(l, arr, lenMaxTest)) {
            printf("Test %d passed!\n", i + 1);
            passedTests++;
        } else
            printf("Test %d failed!\n", i + 1);
        destroy(&l);
    }
    printf("Passed %d/%d tests\n", passedTests, countOfAllTests);
    return 0;
}