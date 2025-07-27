/*
Problem: Insert Interval

You are given an array of non-overlapping intervals sorted by start time.
Insert a new interval into the intervals (merge if necessary) and return the result.

Input:
intervals = [[1,3],[6,9]], newInterval = [2,5]

Output:
[[1,5],[6,9]]
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));
    *returnSize = 0;

    int i = 0;

    // Add intervals before newInterval
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[*returnSize] = (int*)malloc(sizeof(int) * 2);
        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        i++;
    }

    // Merge overlapping intervals
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = fmin(newInterval[0], intervals[i][0]);
        newInterval[1] = fmax(newInterval[1], intervals[i][1]);
        i++;
    }

    result[*returnSize] = (int*)malloc(sizeof(int) * 2);
    result[*returnSize][0] = newInterval[0];
    result[*returnSize][1] = newInterval[1];
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;

    // Add remaining intervals
    while (i < intervalsSize) {
        result[*returnSize] = (int*)malloc(sizeof(int) * 2);
        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        i++;
    }

    return result;
}

int main() {
    int intervalsArray[][2] = {{1, 3}, {6, 9}};
    int intervalsSize = sizeof(intervalsArray) / sizeof(intervalsArray[0]);

    int** intervals = (int**)malloc(sizeof(int*) * intervalsSize);
    int* intervalsColSize = (int*)malloc(sizeof(int) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = (int*)malloc(sizeof(int) * 2);
        intervals[i][0] = intervalsArray[i][0];
        intervals[i][1] = intervalsArray[i][1];
        intervalsColSize[i] = 2;
    }

    int newInterval[] = {2, 5};
    int newIntervalSize = 2;

    int returnSize;
    int* returnColSize;
    int** result = insert(intervals, intervalsSize, intervalsColSize, newInterval, newIntervalSize, &returnSize, &returnColSize);

    printf("Merged Intervals: [");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d,%d]", result[i][0], result[i][1]);
        if (i != returnSize - 1) printf(", ");
    }
    printf("]\n");

    // Free memory
    for (int i = 0; i < intervalsSize; i++) free(intervals[i]);
    free(intervals);
    free(intervalsColSize);
    for (int i = 0; i < returnSize; i++) free(result[i]);
    free(result);
    free(returnColSize);

    return 0;
}

/*
Expected Output:
Merged Intervals: [[1,5], [6,9]]
*/
