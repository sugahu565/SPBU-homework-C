#include "cycleList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    printf("Write n and m: ");
    scanf("%d %d", &n, &m);
    cycleList l;
    init(&l);

    push(&l, NULL, 1);

    elem_t* curr = l.head;

    for (int i = 2; i <= n; ++i) {
        push(&l, curr, i);
        curr = curr->next;
    }

    if (m == 1) {
        printf("%d\n", n);
        return 0;
    }

    int flag = m - 2;
    curr = l.head;

    while (l.len > 1) {
        if (flag)
            flag--;
        else {
            pop(&l, curr);
            flag = m - 2;
        }
        curr = curr->next;
    }
    printf("%d\n", *(l.head->p));
    destroy(&l);
    return 0;
}
