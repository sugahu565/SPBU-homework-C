#pragma once

typedef struct elem {
    int p;
    struct elem* prev;
} elem_t;

typedef struct {
    int len;
    elem_t* last;
} stack;

void init(stack* s);
int peek(stack* s);
int push(stack* s, int x);
int pop(stack* s);
void destroy(stack* s);