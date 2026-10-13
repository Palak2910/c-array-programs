#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int i = 0, j = 0, count = 0;

    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            count++;
            i++;
        }
        j++;
    }
    return count;
}
