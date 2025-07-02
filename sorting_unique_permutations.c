/*
Problem: Generate all unique permutations of a given array.

Description:
Given an array that may contain duplicates, return all possible unique permutations.

Example:
Input: nums = [1, 1, 2]
Output:
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparison function for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Backtracking function
void backtrack(int* nums, int numsSize, bool* used, int* current, int depth,
               int** result, int* returnSize, int** returnColumnSizes) {
    if (depth == numsSize) {
        int* temp = malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) temp[i] = current[i];
        result[*returnSize] = temp;
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

        used[i] = true;
        current[depth] = nums[i];
        backtrack(nums, numsSize, used, current, depth + 1, result, returnSize, returnColumnSizes);
        used[i] = false;
    }
}

// Wrapper function
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int capacity = 1000;
    int** result = malloc(sizeof(int*) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);

    int* current = malloc(sizeof(int) * numsSize);
    bool* used = calloc(numsSize, sizeof(bool));

    qsort(nums, numsSize, sizeof(int), compare);
    backtrack(nums, numsSize, used, current, 0, result, returnSize, returnColumnSizes);

    free(current);
    free(used);
    return result;
}

// Main function for local testing
int main() {
    int nums[] = {1, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;

    int** result = permuteUnique(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("Unique permutations:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
    return 0;
}

/*
========= OUTPUT =========
Unique permutations:
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
==========================
*/
