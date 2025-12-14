#define MAX_SIZE 100
int a[MAX_SIZE];

void sort(int* startArr, int* endArr)
{
    if (startArr + 1 >= endArr)
        return;

    int diff = (endArr - startArr) / 2;
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