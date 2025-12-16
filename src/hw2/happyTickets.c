#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[28] = { 0 };
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k)
                a[i + j + k] += 1;
        }
    }
    int answer = 0;
    for (int i = 0; i < 28; ++i)
        answer += a[i] * a[i];
    printf("%d", answer);
}
