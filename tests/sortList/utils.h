#include<stdio.h>
#include<stdlib.h>

#define fillList(list, start, end) for (int x = (start); x < (end); ++x) push(&(list), x);

int sameElements(list l, int* arr);
void randomElements(int* arr, int len);
int compare(const void* a, const void* b);
void sort(int* arr, int len);
