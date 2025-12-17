#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[100];
    int arrCopy[100];
    printf("Write an array (enter is the end): ");

    int elem, len = 0, flag = 1;

    while (flag) {
        scanf("%d", &elem);
        arr[len] = elem;
        arrCopy[len] = elem;
        ++len;
        if (getchar() == '\n')
            flag = 0;
    }
    sort(arr, arr + len);

    int changePositions = 0, now = 0;

    while (now < len) {
        printf("%d ", arr[now]);
        if (arr[now] != arrCopy[now])
            ++changePositions;
        now++;
    }
    printf("\n");
    return changePositions;
}
