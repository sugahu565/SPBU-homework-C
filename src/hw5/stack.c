#include "stack.h"
#include <stddef.h>
#include <stdlib.h>

void init(stack* s)
{
    s->len = 0;
    s->last = NULL;
}

int get(stack* s)
{
    if (s->last == NULL)
	exit(EXIT_FAILURE);
    return *(s->last->p);
}

void push(stack* s, int x)
{
    elem_t* new = malloc(sizeof(elem_t));
    new->p = malloc(sizeof(int));
    *(new->p) = x;
    new->prev = s->last;
    s->last = new;
    s->len++;
}

int pop(stack* s)
{
    if (s->len == 0)
	exit(EXIT_FAILURE);
    int a = *(s->last->p);
    elem_t* topElem = s->last->prev;
    free(s->last->p);
    free(s->last);
    s->last = topElem;
    s->len--;
    return a;
}

void destroy(stack* s) {
    while (s->len > 0)
	pop(s);
}
