#include "../../src/hw6/sortList.h"
#include<stdio.h>
#include<stdlib.h>

int sameElements(list l, int* arr)
{
    for (int i = 0; i < l.len; ++i)
        if (arr[i] != getElem(&l, i))
            return 0;
    return 1;
}

void randomElements(int* arr, int len)
{
    for (int i = 0; i < len; ++i)
        arr[i] = rand();
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void sort(int* arr, int len)
{
    qsort(arr, len, sizeof(int), compare);
}
