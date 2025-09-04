/*
Problem: Global and Local Inversions (LeetCode 775)
URL: https://leetcode.com/problems/global-and-local-inversions/

Given a permutation `nums` of length n (containing values 0 to n-1), determine
if the number of global inversions equals the number of local inversions.

- Global Inversion: pair (i, j) where i < j and nums[i] > nums[j].
- Local Inversion: only if j = i + 1.

Since every local inversion is a global inversion, they are equal only if no global
inversion occurs between elements more than 1 apart.

Approach:
1. Track the maximum value seen up to index i - 2 (`maxVal`).
2. Starting from i = 2:
   - If `maxVal > nums[i]`, there's a non-local inversion → return false.
   - Update `maxVal` with `nums[i - 1]` if it's larger.
3. If loop completes, return true.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdbool.h>

bool isIdealPermutation(int* nums, int numsSize) {
    int maxVal = nums[0];
    for (int i = 2; i < numsSize; i++) {
        if (maxVal > nums[i]) {
            return false;
        }
        if (nums[i - 1] > maxVal) {
            maxVal = nums[i - 1];
        }
    }
    return true;
}

int main(void) {
    int nums1[] = {1, 0, 2};
    printf("nums = [1,0,2] → %s (expected: true)\n",
           isIdealPermutation(nums1, 3) ? "true" : "false");

    int nums2[] = {1, 2, 0};
    printf("nums = [1,2,0] → %s (expected: false)\n",
           isIdealPermutation(nums2, 3) ? "true" : "false");

    int nums3[] = {0, 2, 1};
    printf("nums = [0,2,1] → %s (expected: true)\n",
           isIdealPermutation(nums3, 3) ? "true" : "false");

    return 0;
}
