#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int lenS, lenS1;
    printf("Write lenght of s and s1: ");
    if (scanf("%d %d", &lenS, &lenS1) != 2) {
        return -1;
    }

    if (lenS <= 0 || lenS1 <= 0)
        return 0;

    getchar();

    char* s = malloc((lenS + 1) * sizeof(char));

    if (s == NULL)
        return -1;

    char* s1 = malloc((lenS1 + 1) * sizeof(char));

    if (s1 == NULL) {
        free(s);
        return -1;
    }

    printf("Write s: ");
    for (int i = 0; i < lenS; ++i) {
        if (scanf("%c", &s[i]) != 1) {
            free(s);
            free(s1);
            return -1;
        }
    }
    getchar();
    printf("Write s1: ");
    for (int i = 0; i < lenS1; ++i) {
        if (scanf("%c", &s1[i]) != 1) {
            free(s);
            free(s1);
            return -1;
        }
    }
    int answer = 0;
    if (lenS1 <= lenS) {
        for (int i = 0; i <= lenS - lenS1; ++i) {
            int sameSymb = 0;
            for (int j = i; j < i + lenS1; ++j) {
                sameSymb += (s[j] == s1[j - i]);
            }
            if (sameSymb == lenS1) {
                ++answer;
            }
        }
    }
    printf("%d", answer);
    free(s);
    free(s1);
    return 0;
}
