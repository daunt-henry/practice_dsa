/*
Problem: Maximum Length of Pair Chain

Given pairs where each pair [a, b] has a < b,
find the maximum length chain where for each pair [a, b] and next [c, d], b < c.

Approach:
- Sort by second value (end time)
- Greedily pick pairs where start > previous end

Time: O(n log n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return ((int*)a)[1] - ((int*)b)[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize) {
    qsort(pairs, pairsSize, sizeof(int*), compare);

    int count = 0;
    int currentEnd = -10001;

    for (int i = 0; i < pairsSize; i++) {
        if (pairs[i][0] > currentEnd) {
            count++;
            currentEnd = pairs[i][1];
        }
    }

    return count;
}

// Test
int main() {
    int data[][2] = {{1, 2}, {2, 3}, {3, 4}};
    int* pairs[3];
    for (int i = 0; i < 3; i++) pairs[i] = data[i];
    int cols = 2;

    int result = findLongestChain(pairs, 3, &cols);
    printf("Maximum length of pair chain: %d\n", result);

    return 0;
}

/*
========= OUTPUT =========
Maximum length of pair chain: 2
==========================
*/
