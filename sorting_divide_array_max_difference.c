/*
Problem:
You are given an integer array `nums` and an integer `k`.
Divide `nums` into groups of 3 such that the **maximum difference** between
the smallest and largest number in each group is at most `k`.

Return a 2D array of the groups if possible, otherwise return an empty array.

Example Input:
nums = [1, 3, 4, 8, 7, 9]
k = 2

Expected Output:
[[1, 3, 4], [7, 8, 9]]
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    if (numsSize % 3 != 0) return NULL;

    int groupCount = numsSize / 3;
    int** result = (int**)malloc(sizeof(int*) * groupCount);
    *returnColumnSizes = (int*)malloc(sizeof(int) * groupCount);

    int j = 0;
    for (int i = 0; i < numsSize; i += 3) {
        if (nums[i + 2] - nums[i] > k) {
            *returnSize = 0;
            return NULL;
        }
        result[j] = (int*)malloc(sizeof(int) * 3);
        result[j][0] = nums[i];
        result[j][1] = nums[i + 1];
        result[j][2] = nums[i + 2];
        (*returnColumnSizes)[j] = 3;
        j++;
    }

    *returnSize = groupCount;
    return result;
}

int main() {
    int nums[] = {1, 3, 4, 8, 7, 9};
    int k = 2;
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;

    int** result = divideArray(nums, size, k, &returnSize, &returnColumnSizes);

    if (result == NULL || returnSize == 0) {
        printf("No valid grouping possible.\n");
    } else {
        printf("Grouped arrays:\n");
        for (int i = 0; i < returnSize; ++i) {
            for (int j = 0; j < 3; ++j) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
            free(result[i]);
        }
        free(result);
        free(returnColumnSizes);
    }

    return 0;
}
