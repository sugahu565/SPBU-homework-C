#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
  int *p;
  struct elem *next;
} elem_t;

typedef struct {
  int len;
  elem_t *head;
} list;

void init(list *l);
int push(list *l, int x);
int pop(list *l, int x);
void destroy(list *l);
