/*
Max Number of K-Sum Pairs

Problem:
Given an array `nums` and an integer `k`, find the maximum number of operations
such that you pick two numbers that sum to k and remove them.

Approach:
- Sort the array
- Use two-pointer technique from both ends
- If sum == k, count it and move both pointers
- If sum < k, move left pointer
- If sum > k, move right pointer

Time Complexity: O(n log n)
Space Complexity: O(1)

Example:
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: (1,4) and (2,3)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int maxOperations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0, j = numsSize - 1, count = 0;

    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum == k) {
            count++;
            i++;
            j--;
        } else if (sum < k) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}
