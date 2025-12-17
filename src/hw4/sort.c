#define MAX_SIZE 100
int a[MAX_SIZE];

// NOLINTNEXTLINE(misc-no-recursion)
void sort(int* startArr, int* endArr)
{
    if (startArr + 1 >= endArr)
        return;

    long long diff = (endArr - startArr) / 2;

    if (diff < 0)
        return;

    int* mid = startArr + diff;

    sort(startArr, mid);
    sort(mid, endArr);

    int* now = a;
    int* i = startArr;
    int* j = mid;

    while (i < mid && j < endArr) {
        if (*i < *j) {
            *now = *i;
            ++i;
        } else {
            *now = *j;
            ++j;
        }
        ++now;
    }

    while (i < mid) {
        *now = *i;
        ++now;
        ++i;
    }

    while (j < endArr) {
        *now = *j;
        ++now;
        ++j;
    }

    now = a;

    while (startArr < endArr) {
        *startArr = *now;
        ++startArr;
        ++now;
    }
}