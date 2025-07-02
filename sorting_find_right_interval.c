/*
Problem: Find Right Interval

Description:
Given a list of intervals, for each interval return the index
of the next interval whose start is >= current end.
If no such interval exists, return -1.

Approach:
1. Store start points with original indices.
2. Sort by start.
3. Use binary search for each end to find next valid interval.

Time: O(n log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int index;
} IntervalIndex;

int compare(const void* a, const void* b) {
    IntervalIndex* i1 = (IntervalIndex*)a;
    IntervalIndex* i2 = (IntervalIndex*)b;
    return i1->start - i2->start;
}

int binarySearch(IntervalIndex* arr, int size, int target) {
    int left = 0, right = size - 1, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].start >= target) {
            ans = arr[mid].index;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
    IntervalIndex* arr = malloc(sizeof(IntervalIndex) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        arr[i].start = intervals[i][0];
        arr[i].index = i;
    }

    qsort(arr, intervalsSize, sizeof(IntervalIndex), compare);

    int* result = malloc(sizeof(int) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        int end = intervals[i][1];
        result[i] = binarySearch(arr, intervalsSize, end);
    }

    *returnSize = intervalsSize;
    free(arr);
    return result;
}

// Test
int main() {
    int raw[][2] = {{1, 2}, {2, 3}, {0, 1}};
    int size = sizeof(raw) / sizeof(raw[0]);

    int** intervals = malloc(sizeof(int*) * size);
    int* colSizes = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        intervals[i] = malloc(sizeof(int) * 2);
        intervals[i][0] = raw[i][0];
        intervals[i][1] = raw[i][1];
        colSizes[i] = 2;
    }

    int returnSize;
    int* result = findRightInterval(intervals, size, colSizes, &returnSize);

    printf("Right intervals: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    for (int i = 0; i < size; i++) free(intervals[i]);
    free(intervals);
    free(colSizes);
    free(result);
    return 0;
}

/*
========= OUTPUT =========
Right intervals: 1 -1 0
==========================
*/
