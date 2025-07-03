/*
Problem:
Given an array of integers, return all pairs with the minimum absolute difference in ascending order.

Approach:
1. Sort the array.
2. Calculate minimum adjacent difference.
3. Collect all adjacent pairs with that difference.

Time: O(n log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), cmp);

    int minDiff = arr[1] - arr[0];
    for (int i = 1; i < arrSize - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff < minDiff) minDiff = diff;
    }

    int** result = malloc(sizeof(int*) * (arrSize - 1));
    *returnColumnSizes = malloc(sizeof(int) * (arrSize - 1));
    *returnSize = 0;

    for (int i = 0; i < arrSize - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff == minDiff) {
            result[*returnSize] = malloc(sizeof(int) * 2);
            result[*returnSize][0] = arr[i];
            result[*returnSize][1] = arr[i + 1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }

    return result;
}

// Test
int main() {
    int arr[] = {4, 2, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int returnSize;
    int* returnColSizes;

    int** result = minimumAbsDifference(arr, size, &returnSize, &returnColSizes);

    printf("Pairs with minimum absolute difference:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
        free(result[i]);
    }
    free(result);
    free(returnColSizes);

    return 0;
}

/*
========= OUTPUT =========
Pairs with minimum absolute difference:
[1, 2]
[2, 3]
[3, 4]
==========================
*/
