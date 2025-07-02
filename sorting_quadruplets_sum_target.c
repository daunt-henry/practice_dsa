/*
Problem: Find all unique quadruplets in an array that sum to a given target.

Description:
Given an integer array and a target value, return all unique sets of four numbers (quadruplets)
[a, b, c, d] such that: a + b + c + d == target.

Each combination must be unique.

Example:
Input: nums = [1, 0, -1, 0, -2, 2], target = 0
Output:
[-2, -1, 1, 2]
[-2, 0, 0, 2]
[-1, 0, 0, 1]
*/

#include <stdio.h>
#include <stdlib.h>

// Helper for sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to find all unique quadruplets that sum to target
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int capacity = 1000;
    int** result = malloc(sizeof(int*) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1, right = numsSize - 1;
            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    int* quad = malloc(sizeof(int) * 4);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];
                    result[*returnSize] = quad;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while (left < right && nums[left] == quad[2]) left++;
                    while (left < right && nums[right] == quad[3]) right--;

                    if (*returnSize >= capacity) {
                        capacity *= 2;
                        result = realloc(result, sizeof(int*) * capacity);
                        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * capacity);
                    }
                }
            }
        }
    }

    return result;
}

// Main function for local testing
int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int target = 0;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;

    int** result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);

    printf("Quadruplets that sum to %d:\n", target);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d, %d]\n", result[i][0], result[i][1], result[i][2], result[i][3]);
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}

/*
========= OUTPUT =========
Quadruplets that sum to 0:
[-2, -1, 1, 2]
[-2,  0, 0, 2]
[-1,  0, 0, 1]
==========================
*/
