/*
Problem:
Given a list of intervals, remove those intervals that are covered by another.

Approach:
1. Sort by start ascending, and end descending.
2. Keep track of the current max `end`. If an interval’s end <= `end`, it's covered.
3. Count the uncovered intervals.

Time: O(n log n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* intA = *(int**)a;
    int* intB = *(int**)b;
    if (intA[0] != intB[0])
        return intA[0] - intB[0];
    return intB[1] - intA[1];
}

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int count = 0, end = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i][1] > end) {
            count++;
            end = intervals[i][1];
        }
    }
    return count;
}

// Test
int main() {
    int data[][2] = {{1,4},{3,6},{2,8}};
    int* intervals[3];
    for (int i = 0; i < 3; i++) intervals[i] = data[i];
    int cols = 2;

    int result = removeCoveredIntervals(intervals, 3, &cols);
    printf("Remaining intervals count: %d\n", result);  // Expected: 2

    return 0;
}

/*
========= OUTPUT =========
Remaining intervals count: 2
==========================
*/
