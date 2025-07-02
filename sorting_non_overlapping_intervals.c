/*
Problem: Non-overlapping Intervals

Description:
Given a list of intervals, return the minimum number
of intervals to remove to make the rest non-overlapping.

Approach:
1. Sort intervals by end time.
2. Use greedy selection to keep non-overlapping ones.
3. Count and return the number of overlapping intervals (to remove).

Time: O(n log n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* int1 = *(int**)a;
    int* int2 = *(int**)b;
    return int1[1] - int2[1];  // Sort by end time
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int count = 0;
    int prevEnd = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < prevEnd) {
            count++;  // Overlapping, remove
        } else {
            prevEnd = intervals[i][1];  // Non-overlapping, keep it
        }
    }

    return count;
}

// Test
int main() {
    int raw[][2] = {{1,2}, {2,3}, {3,4}, {1,3}};
    int size = sizeof(raw) / sizeof(raw[0]);

    int** intervals = malloc(sizeof(int*) * size);
    int* colSizes = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        intervals[i] = malloc(sizeof(int) * 2);
        intervals[i][0] = raw[i][0];
        intervals[i][1] = raw[i][1];
        colSizes[i] = 2;
    }

    int result = eraseOverlapIntervals(intervals, size, colSizes);
    printf("Minimum intervals to remove: %d\n", result);

    for (int i = 0; i < size; i++) free(intervals[i]);
    free(intervals);
    free(colSizes);

    return 0;
}

/*
========= OUTPUT =========
Minimum intervals to remove: 1
==========================
*/
