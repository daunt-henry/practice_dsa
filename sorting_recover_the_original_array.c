/*
Problem: Recover the Original Array

Given an array nums formed by doubling elements and adding/subtracting a value k,
return the original array.

Approach:
- Sort the input array
- Try each difference between nums[i] and nums[0] as a potential 2*k
- Try to reconstruct the original array using a greedy match approach
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool isValid(int* nums, int numsSize, int k, int* original) {
    bool* used = calloc(numsSize, sizeof(bool));
    int oIdx = 0;

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;

        used[i] = true;
        int target = nums[i] + 2 * k;
        bool found = false;

        for (int j = i + 1; j < numsSize; j++) {
            if (!used[j] && nums[j] == target) {
                used[j] = true;
                original[oIdx++] = nums[i] + k;
                found = true;
                break;
            }
        }

        if (!found) {
            free(used);
            return false;
        }
    }

    free(used);
    return true;
}

int* recoverArray(int* nums, int numsSize, int* returnSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int* result = malloc(sizeof(int) * (numsSize / 2));
    *returnSize = numsSize / 2;

    for (int i = 1; i < numsSize; i++) {
        int diff = nums[i] - nums[0];
        if (diff == 0 || diff % 2 != 0) continue;

        int k = diff / 2;
        if (isValid(nums, numsSize, k, result)) return result;
    }

    return NULL;
}

/*
Example:
Input: nums = [2,10,6,4,8,12]
Output: [3,7,5]
*/
