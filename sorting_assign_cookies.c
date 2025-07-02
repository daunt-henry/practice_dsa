/*
Problem: Assign Cookies

Description:
Each child has a greed factor. Each cookie has a size.
Assign cookies such that the number of content children is maximized.
A child is content if cookie size >= greed.

Approach:
1. Sort both greed and cookie arrays.
2. Greedily assign smallest sufficient cookie to each child.

Time: O(n log n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int i = 0, j = 0;
    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            i++;
        }
        j++;
    }
    return i;
}

// Test
int main() {
    int g[] = {1, 2, 3};
    int s[] = {1, 1};
    int gSize = sizeof(g) / sizeof(g[0]);
    int sSize = sizeof(s) / sizeof(s[0]);

    int result = findContentChildren(g, gSize, s, sSize);
    printf("Maximum number of content children: %d\n", result);
    return 0;
}

/*
========= OUTPUT =========
Maximum number of content children: 1
==========================
*/
