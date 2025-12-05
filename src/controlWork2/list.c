#include "list.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define IS_NOT_NULL(a) assert((a) != NULL)

List* listInit(void)
{
    List* l = malloc(sizeof(List));
    IS_NOT_NULL(l);
    l->len = 0;
    l->head = NULL;
}

void listFree(List* l)
{
    elem_t* curr = l->head;
    while (curr != NULL)
    {
	elem_t* nextElem = curr-> next;
	free(curr);
	curr = nextElem;
    }
    free(l);
}

void listPushHead(List* l, int val)
{
    elem_t* newElem = malloc(sizeof(elem_t));
    IS_NOT_NULL(newElem);
    newElem->value = val;
    newElem->prev = NULL;
    newElem->next = l->head;
    l->head = newElem;
    if (l->len != 0)
	newElem->next->prev = newElem;
    l->len++;
}
