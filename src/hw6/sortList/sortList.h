#pragma once

#include <stdio.h>
#include <stdlib.h>

#define checkError(result) \
    if ((result) == -1)      \
    printf("ERROR\n")

typedef struct Elem {
    int* p;
    struct Elem* next;
} elem_t;

typedef struct {
    int len;
    elem_t* head;
} list;

void init(list* l);
int push(list* l, int x);
int pop(list* l, int x);
void destroy(list* l);
