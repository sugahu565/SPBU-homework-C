#include <stdio.h>
#include <stdlib.h>

struct elem_t {
    int* p;
    struct elem_t* next;
} elem;

struct {
    int len;
    elem* head;
} list;

void init(list* l);
int push(list* l, int x);
int pop(list* l, int x);
void destroy(list* l);
