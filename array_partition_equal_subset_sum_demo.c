/*
Partition Equal Subset Sum (LeetCode 416)

Problem:
Given a non-empty array of positive integers, determine whether it can be
partitioned into two subsets such that both subsets have the same sum.

Solution Outline:
1. Compute total sum of the array. If odd → impossible, return false.
2. Target = total / 2.
3. Use 1D DP array to check subset sum:
    - dp[j] = true if subset sum j is achievable.
    - Initialize dp[0] = true.
    - For each number x, update dp[j] (for j from target down to x):
        dp[j] = dp[j] OR dp[j - x].
4. Final result = dp[target].
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canPartition(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) total += nums[i];
    if (total % 2) return false;
    int half = total / 2;

    bool* dp = calloc(half + 1, sizeof(bool));
    dp[0] = true;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        for (int j = half; j >= x; j--) {
            dp[j] = dp[j] || dp[j - x];
        }
    }

    bool result = dp[half];
    free(dp);
    return result;
}

int main(void) {
    int nums1[] = {1, 5, 11, 5};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1: %s (expected true)\n", canPartition(nums1, n1) ? "true" : "false");

    int nums2[] = {1, 2, 3, 5};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Example 2: %s (expected false)\n", canPartition(nums2, n2) ? "true" : "false");

    return 0;
}
