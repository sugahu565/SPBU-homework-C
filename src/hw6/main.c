#include "sortList.h"
#include <stdio.h>
#include <stdlib.h>

#define checkError(result) if (result == -1) printf("ERROR")

void print(list l)
{
    elem* curr = l->head;
    while (curr != NULL) {
	printf("%d ", *(curr->p));
	curr = curr->next;
    }
    printf("\n");
}

int main()
{
    list l;
    init(&l);
    int action;
    scanf("%d", &action);
    while (action != 0) {
	int x;
	if (action == 1) {
	    scanf("%d", &x);
	    checkError(push(&l, x));
	} else if (action == 2) {
	    scanf("%d", &x);
	    checkError(pop(&l, x));
	} else
	    print(&l);
    }
    destroy(&l);
    return 0;
}
