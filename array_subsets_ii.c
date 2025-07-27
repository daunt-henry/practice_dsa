/*
Subsets II

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int** result, int* returnSize, int* temp, int tempSize, int start, int* colSizes) {
    result[*returnSize] = (int*)malloc(sizeof(int) * tempSize);
    memcpy(result[*returnSize], temp, sizeof(int) * tempSize);
    colSizes[*returnSize] = tempSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; ++i) {
        if (i > start && nums[i] == nums[i - 1]) continue;

        temp[tempSize] = nums[i];
        backtrack(nums, numsSize, result, returnSize, temp, tempSize + 1, i + 1, colSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1 << numsSize;
    int** result = (int**)malloc(sizeof(int*) * total * 2);
    *returnColumnSizes = (int*)malloc(sizeof(int) * total * 2);
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), cmp);
    backtrack(nums, numsSize, result, returnSize, temp, 0, 0, *returnColumnSizes);
    free(temp);
    return result;
}

// Sample test code
int main() {
    int nums[] = {1, 2, 2};
    int numsSize = 3;
    int returnSize;
    int* colSizes;
    int** result = subsetsWithDup(nums, numsSize, &returnSize, &colSizes);

    printf("Subsets:\n");
    for (int i = 0; i < returnSize; ++i) {
        printf("[");
        for (int j = 0; j < colSizes[i]; ++j) {
            printf("%d", result[i][j]);
            if (j < colSizes[i] - 1) printf(",");
        }
        printf("]\n");
        free(result[i]);
    }
    free(result);
    free(colSizes);
    return 0;
}
