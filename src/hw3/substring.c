#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int lenS, lenS1;
    printf("Write lenght of s and s1: ");
    scanf("%d %d", &lenS, &lenS1);
    getchar();

    char* s = (char*)malloc(lenS * sizeof(char));
    char* s1 = (char*)malloc(lenS1 * sizeof(char));

    printf("Write s: ");
    for (int i = 0; i < lenS; ++i)
        scanf("%c", s + i);
    getchar();
    printf("Write s1: ");
    for (int i = 0; i < lenS1; ++i)
        scanf("%c", s1 + i);

    int answer = 0;
    for (int i = 0; i <= lenS - lenS1; ++i) {
        int sameSymb = 0; // совпадающие символы
        for (int j = i; j < i + lenS1; ++j) {
            if (s[j] == s1[j - i])
                ++sameSymb;
        }
        if (sameSymb == lenS1)
            ++answer;
    }
    printf("%d", answer);
    free(s);
    free(s1);
    return 0;
}
