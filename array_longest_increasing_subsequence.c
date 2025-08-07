/*
Problem: Longest Increasing Subsequence (LIS)

Given an integer array 'nums', return the length of the longest strictly increasing subsequence.

Example:
Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]
Output: 4
Explanation: The longest increasing subsequence is [2, 3, 7, 101].

This implementation uses the O(n²) dynamic programming approach.
*/

#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int maxLen = 1;
    for (int i = 0; i < numsSize; i++) dp[i] = 1;

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxLen) maxLen = dp[i];
    }

    free(dp);
    return maxLen;
}

int main() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = lengthOfLIS(nums, n);
    printf("Length of LIS: %d\n", result);  // Expected output: 4

    return 0;
}
