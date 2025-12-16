#include <stdio.h>
#include <stdlib.h>

int* getArr(int* len)
{
    printf("Введите массив: ");
    int lenArr = 8; // не хочу под каждый новый элемент маллочить, так что делаю это как можно реже
    int* arr = malloc(lenArr * sizeof(int));

    if (arr == NULL)
        return NULL;

    scanf("%d", &arr[0]);
    int currLen = 1;

    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        int newElem;
        scanf("%d", &newElem);
        if (currLen == lenArr) {
            lenArr *= 2;
            int* bigArr = realloc(arr, lenArr * sizeof(int));
            if (bigArr == NULL) {
                free(arr);
                return NULL;
            }
            arr = bigArr;
        }
        arr[currLen] = newElem;
        currLen++;
    }
    int* resultArr = realloc(arr, currLen * sizeof(int));
    if (resultArr == NULL)
        free(arr);
    *len = currLen;
    return resultArr;
}

int main(void)
{
    int len;
    int* arr = getArr(&len);

    if (arr == NULL)
        return -1;

    int zero = 0;
    for (int i = 0; i < len; ++i)
        zero += (arr[i] == 0);

    printf("%d\n", zero);
    free(arr);
    return 0;
}
