/*
Split Array Largest Sum (LeetCode 410)

Problem:
Given an integer array `nums` and an integer `k`, split `nums` into `k` non-empty
contiguous subarrays such that the largest sum among them is minimized.

Approach:
Use binary search on the range [max(nums), sum(nums)]. For each mid-point, use
a greedy pass to check if we can split into ≤ k parts without exceeding mid.

Complexity: O(n log S), where S is sum(nums).
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

static int max(int a, int b) { return a > b ? a : b; }

bool canSplit(int* nums, int n, int k, long limit) {
    int cnt = 1;
    long sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + nums[i] > limit) {
            sum = nums[i];
            cnt++;
            if (cnt > k) return false;
        } else {
            sum += nums[i];
        }
    }
    return true;
}

int splitArray(int* nums, int n, int k) {
    long low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        low = max(low, nums[i]);
        high += nums[i];
    }

    while (low < high) {
        long mid = low + (high - low) / 2;
        if (canSplit(nums, n, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return (int)low;
}

int main(void) {
    int nums[] = {7, 2, 5, 10, 8};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = splitArray(nums, n, k);
    printf("Minimum largest subarray sum: %d\n", result);
    // Expected output: 18

    return 0;
}
