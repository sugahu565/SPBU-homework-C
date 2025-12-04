#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int bracketToNum(char bracket)
{
    if (bracket == '(')
        return 1;
    if (bracket == '[')
        return 2;
    if (bracket == '{')
        return 3;
    if (bracket == ')')
        return 4;
    if (bracket == ']')
        return 5;
    if (bracket == '}')
        return 6;
    return -1;
}

int main(void)
{
    stack s;
    init(&s);

    char bracket = (char)getchar();
    int answer = 1;

    while (bracket != '\n') {

        int num = bracketToNum(bracket);

        if (num < 4)
            push(&s, num);
        else {

            if (s.len == 0 || get(&s) != num - 3)
                answer = 0;
            else
                pop(&s);
        }

        bracket = (char)getchar();
    }

    if (s.len > 0)
        answer = 0;

    if (answer)
        printf("Correct!");
    else
        printf("Wrong!");

    destroy(&s);
    return 0;
}
