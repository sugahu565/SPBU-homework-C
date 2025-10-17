#include <stdio.h>
#include <stdlib.h>

void mix(int* arr, int len)
{
    for (int i = 0; i < len; ++i) {
	int index = rand() % len;
	int temp = arr[i];
	arr[i] = arr[index];
	arr[index] = temp;
    }
}

int check(int* arr, int len)
{
    for (int i = 1; i < len; ++i) {
	if (arr[i - 1] > arr[i])
	    return 0;
    }
    return 1;
}

int main()
{
    int arr[] = {5, 7, 3, 6, 1, 7, 9, 1};
    int len = sizeof(arr) / sizeof(int);
    while (!check(arr, len))
	mix(arr, len);
    printf("Sorted\n");
    for (int i = 0; i < len; ++i)
	printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
