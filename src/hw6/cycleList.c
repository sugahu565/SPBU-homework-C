#include "cycleList.h"
#include <stdio.h>
#include <stdlib.h>

void init(cycleList *l) {
  l->head = NULL;
  l->len = 0;
}

int push(cycleList *l, elem_t *prevElem, int x) {
  elem_t *new = malloc(sizeof(elem_t));
  if (!new)
    return -1;

  new->p = malloc(sizeof(int));
  if (new->p == NULL) {
    free(new);
    return -1;
  }
  *(new->p) = x;
  l->len++;
  if (l->head == NULL) {
    l->head = new;
    new->next = new;
    return 0;
  }
  new->next = prevElem->next;
  prevElem->next = new;
  return 0;
}

void pop(cycleList *l, elem_t *prevElem) {
  // delete elem after prevElem;
  l->len--;
  if (prevElem->next == prevElem) {
    free(prevElem->p);
    free(prevElem);
    l->head = NULL;
    return;
  }
  elem_t *needToPop = prevElem->next;
  prevElem->next = prevElem->next->next;
  if (l->head == needToPop)
    l->head = prevElem->next;
  free(needToPop->p);
  free(needToPop);
}

void destroy(cycleList *l) {
  while (l->len != 0) {
    pop(l, l->head);
  }
}
