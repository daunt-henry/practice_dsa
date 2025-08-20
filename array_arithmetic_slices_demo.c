/*
Arithmetic Slices (LeetCode 413)

A slice of an integer array is arithmetic if it has at least three elements
and the differences between consecutive elements are equal.

Goal: Count how many contiguous arithmetic slices exist in the array.

Efficient Approach (O(n) time, O(1) space):
Keep a running count 'dp' of arithmetic slices ending at index i:
  if the current triplet continues the pattern,
    dp++ and accumulate 'dp' into 'ans'
  else reset dp to 0
*/

#include <stdio.h>

int numberOfArithmeticSlices(int* nums, int numsSize) {
    int ans = 0, dp = 0;
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            dp++;
            ans += dp;
        } else {
            dp = 0;
        }
    }
    return ans;
}

int main(void) {
    int nums1[] = {1, 2, 3, 4};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1: %d arithmetic slices (expected 3)\n",
           numberOfArithmeticSlices(nums1, n1));

    int nums2[] = {1, 3, 5, 7, 9, 15};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Example 2: %d arithmetic slices (expected 6)\n",
           numberOfArithmeticSlices(nums2, n2));

    return 0;
}
