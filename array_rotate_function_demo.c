/*
Rotate Function (LeetCode 396)

Problem:
Given an integer array nums of length n, define for each rotation k:
  F(k) = Σ (i * nums_k[i]) // nums_k is nums rotated k times

Goal: Find the maximum F(k) value for k = 0 to n-1.

Key Insight:
F(k) = F(k-1) + sum(nums) − n * nums[n − k]

This allows computation in O(n) time without recomputation from scratch.

Example:
nums = [4, 3, 2, 6]
sum = 15, F(0) = 25
F(1) = 25 + 15 − 4*6 = 16
F(2) = 16 + 15 − 4*2 = 23
F(3) = 23 + 15 − 4*3 = 26  → Maximum

*/

#include <stdio.h>
#include <stdlib.h>

int maxRotateFunction(int* nums, int numsSize) {
    long sum = 0, f = 0;
    int n = numsSize;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        f += (long)i * nums[i];
    }

    long ans = f;
    for (int i = n - 1; i > 0; i--) {
        f += sum - (long)n * nums[i];
        if (f > ans) ans = f;
    }

    return (int)ans;
}

int main(void) {
    int nums[] = {4, 3, 2, 6};
    int n = sizeof(nums) / sizeof(nums[0]);
    int result = maxRotateFunction(nums, n);
    printf("Maximum rotate function: %d\n", result);  // Expected: 26
    return 0;
}
