#include "list.h"
#include<stdlib.h>
#include<stdio.h>

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

int testPalyndrome1(void)
{

}

int main(void)
{
    List* l = listInit();
    int currNum = 0;

    scanf("%d", &currNum);
    listPushHead(l, currNum);
    char end = (char)getchar();

    while (end != '\n')
    {
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
