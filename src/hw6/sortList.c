#include "sortList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void init(list* l)
{
    l->len = 0;
    l->head = NULL;
}

int push(list* l, int x)
{
    elem_t* new = malloc(sizeof(elem_t));
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
    elem_t* curr = l->head;
    while (curr->next != NULL && *(curr->next->p) < x)
        curr = curr->next;

    new->next = curr->next;
    curr->next = new;
    l->len++;
    return 0;
}

int pop(list* l, int x)
{
    elem_t* curr = l->head;
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
    if (curr->next == NULL || *(curr->next->p) != x)
        return -1;
    elem_t* needToPop = curr->next;
    curr->next = curr->next->next;
    free(needToPop->p);
    free(needToPop);
    l->len--;
    return 0;
}

int getElem(list* l, int index)
{
    assert(index < l->len);
    elem_t* curr = l->head;
    int nowIndex = 0;
    if (curr == NULL)
        return -1;
    while (nowIndex < index) {
        curr = curr->next;
        nowIndex++;
    }
    return *(curr->p);
}

void destroy(list* l)
{
    elem_t* curr = l->head;
    elem_t* nextElem;
    while (curr != NULL) {
        nextElem = curr->next;
        free(curr->p);
        free(curr);
        curr = nextElem;
    }
    l->len = 0;
    l->head = NULL;
}