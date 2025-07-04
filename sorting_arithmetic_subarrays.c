/*
Arithmetic Subarrays

Problem:
Given an array `nums`, and two index arrays `l` and `r`, check whether the subarray from l[i] to r[i]
can be rearranged to form an arithmetic sequence.

Approach:
1. For each query (l[i], r[i]), extract the subarray.
2. Sort it and check if the difference between elements is consistent.
3. Store the result for each query.

Time Complexity:
- O(k * n log n) where k = number of queries, n = length of each subarray

Example:
Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
Output: [true,false,true]
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool isArithmetic(int* arr, int size) {
    qsort(arr, size, sizeof(int), compare);
    int diff = arr[1] - arr[0];
    for (int i = 2; i < size; i++) {
        if (arr[i] - arr[i - 1] != diff)
            return false;
    }
    return true;
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
    *returnSize = lSize;
    bool* result = (bool*)malloc(sizeof(bool) * lSize);

    for (int i = 0; i < lSize; i++) {
        int len = r[i] - l[i] + 1;
        int* subarr = (int*)malloc(sizeof(int) * len);
        for (int j = 0; j < len; j++) {
            subarr[j] = nums[l[i] + j];
        }
        result[i] = isArithmetic(subarr, len);
        free(subarr);
    }

    return result;
}
