#include <stdio.h>
#include <stdlib.h>

void reverseArray(int* start, int lenArray)
{
    int* end = start + lenArray - 1;
    int stop = lenArray / 2;
    for (int i = 0; i < stop; ++i) {
        int temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}

int main(void)
{
    int m, n;

    printf("Write m and n: ");
    scanf("%d%d", &m, &n);

    const int lenArray = n + m;
    int* arr = malloc(lenArray * sizeof(int));

    if (arr == NULL)
        return -1;

    printf("Write array: ");
    for (int i = 0; i < lenArray; i++) {
        scanf("%d", arr + i);
    }

    reverseArray(arr, lenArray);
    reverseArray(arr, n);
    reverseArray(arr + n, m);

    for (int i = 0; i < lenArray; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    free(arr);
    return 0;
}
