/*
Problem: Find Pivot Index (LeetCode 724)
URL: https://leetcode.com/problems/find-pivot-index/

Given an array of integers `nums`, the pivot index is the place where the
sum of all numbers strictly to the left equals the sum of all numbers strictly to the right.
Return the **leftmost** pivot index if it exists, otherwise return -1.

Approach:
1. Calculate total sum.
2. Maintain `left` sum while iterating:
   - Remove current element from `total` → this becomes `right` sum.
   - If `left == total`, return current index.
   - Else, add current element to `left` and continue.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>

int pivotIndex(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }

    int left = 0;
    for (int i = 0; i < numsSize; i++) {
        total -= nums[i];
        if (left == total) {
            return i;
        }
        left += nums[i];
    }
    return -1;
}

int main(void) {
    int nums1[] = {1, 7, 3, 6, 5, 6};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("nums = [1,7,3,6,5,6] → pivotIndex = %d (expected: 3)\n", pivotIndex(nums1, n1));

    int nums2[] = {1, 2, 3};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("nums = [1,2,3] → pivotIndex = %d (expected: -1)\n", pivotIndex(nums2, n2));

    int nums3[] = {2, 1, -1};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("nums = [2,1,-1] → pivotIndex = %d (expected: 0)\n", pivotIndex(nums3, n3));

    return 0;
}
