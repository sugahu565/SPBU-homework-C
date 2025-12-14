#include "stack.h"
#include <stddef.h>
#include <stdlib.h>

void init(stack* s)
{
    s->len = 0;
    s->last = NULL;
}

int peek(stack* s)
{
    if (s->last == NULL)
        exit(EXIT_FAILURE);
    return s->last->p;
}

int push(stack* s, int x)
{
    elem_t* new = malloc(sizeof(elem_t));

    if (new == NULL)
        return -1;

    new->p = x;
    new->prev = s->last;
    s->last = new;
    s->len++;
    return 0;
}

int pop(stack* s)
{
    if (s->len == 0)
        exit(EXIT_FAILURE);
    int a = s->last->p;
    elem_t* topElem = s->last->prev;
    free(s->last);
    s->last = topElem;
    s->len--;
    return a;
}

void destroy(stack* s)
{
    while (s->len > 0)
        pop(s);
}
