/*
Title: Constrained Subsequence Sum

Problem:
Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence
such that for every pair of consecutive integers in the subsequence, their indices differ by at most k.

Example:
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].

Constraints:
- 1 <= nums.length <= 10^5
- -10^4 <= nums[i] <= 10^4
- 1 <= k <= nums.length
*/

#include <stdio.h>
#include <stdlib.h>

int constrainedSubsetSum(int* nums, int numsSize, int k) {
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int* deque = (int*)malloc(sizeof(int) * numsSize);
    int front = 0, back = 0;
    
    int maxSum = nums[0];
    dp[0] = nums[0];
    deque[back++] = 0;

    for (int i = 1; i < numsSize; i++) {
        if (deque[front] < i - k) front++;

        dp[i] = nums[i] + (dp[deque[front]] > 0 ? dp[deque[front]] : 0);
        while (back > front && dp[i] >= dp[deque[back - 1]]) back--;
        deque[back++] = i;

        if (dp[i] > maxSum) maxSum = dp[i];
    }

    free(dp);
    free(deque);
    return maxSum;
}

int main() {
    int nums[] = {10, 2, -10, 5, 20};
    int k = 2;
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = constrainedSubsetSum(nums, size, k);
    printf("Maximum constrained subsequence sum: %d\n", result);
    return 0;
}
