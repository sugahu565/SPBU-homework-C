#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    int* p;
    struct elem* next;
} elem_t;

typedef struct {
    int len;
    elem_t* head;
} cycleList;

void init(cycleList* l);
int push(cycleList* l, elem_t* prevElem, int x);
void pop(cycleList* l, elem_t* prevElem);
void destroy(cycleList* l);
