/*
Problem: Find Target Indices After Sorting Array

Given an integer array `nums` and an integer `target`, return the list of indices
where `target` appears in the array after sorting it in non-decreasing order.

Approach:
1. Sort the array.
2. Traverse the array and collect all indices where value == target.

Time Complexity: O(n log n) due to sorting

Sample Input:
nums = [1,2,5,2,3], target = 2

Expected Output:
[1,2]
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int* result = (int*)malloc(numsSize * sizeof(int));
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            result[count++] = i;
        }
    }

    *returnSize = count;
    return result;
}
