/*
Problem: Merge Intervals

Description:
Given an array of intervals where intervals[i] = [start, end],
merge all overlapping intervals and return the result.

Example:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/

#include <stdio.h>
#include <stdlib.h>

// Comparison function to sort by start time
int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

// Merge overlapping intervals
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    *returnSize = 0;

    for (int i = 0; i < intervalsSize; i++) {
        if (*returnSize == 0 || result[*returnSize - 1][1] < intervals[i][0]) {
            int* newInterval = malloc(sizeof(int) * 2);
            newInterval[0] = intervals[i][0];
            newInterval[1] = intervals[i][1];
            result[*returnSize] = newInterval;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        } else {
            if (result[*returnSize - 1][1] < intervals[i][1]) {
                result[*returnSize - 1][1] = intervals[i][1];
            }
        }
    }

    return result;
}

// Test function
int main() {
    int input[][2] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int intervalsSize = sizeof(input) / sizeof(input[0]);
    int* intervalsColSize = malloc(sizeof(int) * intervalsSize);
    int** intervals = malloc(sizeof(int*) * intervalsSize);

    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = malloc(sizeof(int) * 2);
        intervals[i][0] = input[i][0];
        intervals[i][1] = input[i][1];
        intervalsColSize[i] = 2;
    }

    int returnSize;
    int* returnColumnSizes;
    int** merged = merge(intervals, intervalsSize, intervalsColSize, &returnSize, &returnColumnSizes);

    printf("Merged Intervals:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", merged[i][0], merged[i][1]);
        free(merged[i]);
    }

    // Clean up
    for (int i = 0; i < intervalsSize; i++) free(intervals[i]);
    free(intervals);
    free(merged);
    free(returnColumnSizes);
    free(intervalsColSize);
    return 0;
}

/*
========= OUTPUT =========
Merged Intervals:
[1, 6]
[8, 10]
[15, 18]
==========================
*/
