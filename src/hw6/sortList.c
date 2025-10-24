#include "sortList.h"
#include<stdio.h>
#include<stdlib.h>

void init(list* l)
{
    l->len = 0;
    l->head = NULL;
}

int push(list* l, int x)
{
    elem* new = malloc(sizeof(elem));
    if (new == NULL)
	return -1;

    new->p = malloc(sizeof(int));
    if (new->p == NULL) {
	free(new);
	return -1;
    }
    *(new->p) = x;
    new->next = NULL;

    if (l->len == 0) {
	l->head = new;
	l->len++;
	return 0;
    }
    
    if (*(new->p) < *(l->head->p)) {
	new->next = l->head;
	l->head = new;
	l->len++;
	return 0;
    }
    // curr is a pointer to the max elem that is less than x
    elem* curr = l->head;
    while (curr->next != NULL && *(curr->next->p) < x)
	curr = curr->next;

    new->next = curr->next;
    curr->next = new;
    l->len++;
    return 0;
}

int pop(list* l, int x)
{
    elem* curr = l->head;
    if (curr == NULL) {
	return -1;
    }
    if (*(curr->p) == x) {
	l->head = curr->next;
	free(curr->p);
	free(curr);
	l->len--;
	return 0;
    }
    while (curr->next != NULL && *(curr->next->p) < x)
	curr = curr->next;
    if (*(curr->next->p) != x)
	return -1;
    elem* needToPop = curr->next;
    curr->next = curr->next->next;
    free(needToPop->p);
    free(needToPop);
    l->len--;
    return 0;
}

void destroy(list* l)
{
    elem* curr = l->head, nextElem;
    while (curr != NULL) {
	nextElem = curr->next;
	free(curr->p);
	free(curr);
	curr = nextElem;
    }
    l->len = 0;
    l->head = NULL;
}