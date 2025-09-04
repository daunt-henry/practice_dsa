/*
 * Problem: Number of Subarrays with Bounded Maximum (LeetCode 795)
 *
 * Given an array nums[], and two integers left and right, return the number
 * of contiguous non-empty subarrays such that the maximum element lies in [left, right].
 *
 * Approach: Subtract counts of subarrays with max ≤ (left-1) from those with max ≤ right.
 * We count subarrays where max ≤ bound by accumulating lengths of valid segments.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

static long long countAtMost(int* nums, int n, int bound) {
    long long total = 0, consec = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > bound) {
            consec = 0;
        } else {
            consec++;
            total += consec;
        }
    }
    return total;
}

int numSubarrayBoundedMax(int* nums, int numsSize, int left, int right) {
    return (int)(countAtMost(nums, numsSize, right)
                - countAtMost(nums, numsSize, left - 1));
}

int main(void) {
    int nums1[] = {2, 1, 4, 3};
    printf("Expected: 3, Got: %d\n",
        numSubarrayBoundedMax(nums1, 4, 2, 3));

    int nums2[] = {2, 9, 2, 5, 6};
    printf("Expected: 7, Got: %d\n",
        numSubarrayBoundedMax(nums2, 5, 2, 8));

    return 0;
}
