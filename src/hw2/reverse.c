#include <stdio.h>
#include <stdlib.h>

void reverseArray(int* start, int lenArray)
{
    if (start == NULL || lenArray <= 1)
        return;
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

    const int LEN_ARRAY = n + m;
    int* arr = calloc(LEN_ARRAY, sizeof(int));

    if (arr == NULL)
        return -1;

    printf("Write array: ");
    for (int i = 0; i < LEN_ARRAY; i++)
        scanf("%d", arr + i);

    reverseArray(arr, LEN_ARRAY);
    reverseArray(arr, n);
    reverseArray(arr + n, m);

    for (int i = 0; i < LEN_ARRAY; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    free(arr);
    return 0;
}
