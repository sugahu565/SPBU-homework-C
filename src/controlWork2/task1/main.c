#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int isPalyndrome(List* l)
{
    elem_t* first = l->head;
    elem_t* last = l->head;

    while (last->next != NULL)
        last = last->next;

    int stop = l->len / 2;
    while (stop--) {
        if (first->value != last->value)
            return 0;
        first = first->next;
        last = last->prev;
    }
    return 1;
}

int testPalyndromeNotPalyndrom(void)
{
    int a[5] = { 0, 1, 2, 3, 4 };
    List* l = listInit();
    for (int i = 0; i < 5; ++i)
        listPushHead(l, a[i]);
    int result = isPalyndrome(l);
    listFree(l);
    return result == 0;
}

int testPalyndromeEmpty(void)
{
    List* l = listInit();
    int result = isPalyndrome(l);
    listFree(l);
    return result;
}

int testPalyndromeOneElem(void)
{
    List* l = listInit();
    listPushHead(l, 1);
    int result = isPalyndrome(l);
    listFree(l);
    return result;
}

int testPalyndromeIsPalyndrome(void)
{
    int a[5] = { 0, 1, 2, 1, 0 };
    List* l = listInit();
    for (int i = 0; i < 5; ++i)
        listPushHead(l, a[i]);
    int result = isPalyndrome(l);
    listFree(l);
    return result;
}

int main(void)
{
    List* l = listInit();
    int currNum = 0;

    scanf("%d", &currNum);
    listPushHead(l, currNum);
    char end = (char)getchar();

    while (end != '\n') {
        scanf("%d", &currNum);
        listPushHead(l, currNum);
        end = (char)getchar();
    }

    if (isPalyndrome(l))
        printf("Palyndrome\n");
    else
        printf("Not palyndrome\n");
    listFree(l);
    return 0;
}
