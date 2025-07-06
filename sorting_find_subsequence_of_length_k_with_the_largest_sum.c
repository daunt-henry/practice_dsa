/*
Problem: Find Subsequence of Length K With the Largest Sum

Given an integer array nums and an integer k, return the subsequence of length k with the largest sum.

Approach:
- Track original indices
- Sort indices by descending nums value
- Mark top k indices
- Extract elements in original order from marked indices
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * k);
    int* indices = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) indices[i] = i;

    // Sort indices based on nums values (descending)
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[indices[i]] < nums[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    // Mark selected indices
    int* selected = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < k; i++) selected[indices[i]] = 1;

    // Preserve original order
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (selected[i]) result[idx++] = nums[i];
    }

    free(indices);
    free(selected);
    *returnSize = k;
    return result;
}

/* 
Example:
Input: nums = [2,1,3,3], k = 2
Output: [3,3]
*/
