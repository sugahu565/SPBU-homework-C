#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr = malloc(100 * sizeof(int));
    int* arrCopy = malloc(100 * sizeof(int));

    printf("Write an array (enter is the end): ");

    int elem, len = 0, flag = 1;
    char c;

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
    free(arr);
    free(arrCopy);
    return changePositions;
}