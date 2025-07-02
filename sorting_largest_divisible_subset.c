/*
Problem: Largest Divisible Subset

Description:
Given a set of distinct positive integers,
find the largest subset where every pair (Si, Sj)
satisfies Si % Sj == 0 or Sj % Si == 0.

Approach:
1. Sort the array
2. Apply DP to find longest divisible chains
3. Use a prev[] array to reconstruct the path

Time: O(n^2)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    int* dp = malloc(sizeof(int) * numsSize);
    int* prev = malloc(sizeof(int) * numsSize);
    int max_len = 0, max_index = -1;

    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            max_index = i;
        }
    }

    int* result = malloc(sizeof(int) * max_len);
    int idx = max_len - 1;
    while (max_index != -1) {
        result[idx--] = nums[max_index];
        max_index = prev[max_index];
    }

    *returnSize = max_len;
    free(dp);
    free(prev);
    return result;
}

// Test
int main() {
    int nums[] = {1, 2, 4, 8};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = largestDivisibleSubset(nums, size, &returnSize);

    printf("Largest Divisible Subset: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Largest Divisible Subset: 1 2 4 8
==========================
*/
