/*
Minimum Subsequence in Non-Increasing Order

Problem:
- Given an array of integers, return the minimum subsequence in non-increasing order 
  such that the sum of the subsequence is strictly greater than the sum of the remaining elements.

Approach:
- Sort in descending order.
- Keep adding elements to result until their sum exceeds the rest.

Time: O(n log n)
Space: O(n)

Example:
Input: [4,3,10,9,8]
Sorted: [10,9,8,4,3]
Subsequence: [10,9] → sum = 19 > rest sum = 15
Output: [10,9]
*/

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);  // descending
}

int* minSubsequence(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int total = 0, curr = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }

    int* res = malloc(numsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        curr += nums[i];
        res[(*returnSize)++] = nums[i];
        if (curr > total - curr)
            break;
    }

    return res;
}
