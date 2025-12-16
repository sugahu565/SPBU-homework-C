#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char nowSymb;
    printf("Write string: ");

    int openBracket = 0;

    nowSymb = getchar();
    while (nowSymb != '\n') {
        if (nowSymb == '(')
            ++openBracket;
        if (nowSymb == ')')
            --openBracket;

        if (openBracket < 0) {
            printf("Wrong!\n");
            return 0;
        }
        nowSymb = getchar();
    }
    if (!openBracket)
        printf("Right!\n");
    else
        printf("Wrong!\n");
    return 0;
}
