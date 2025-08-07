/*
Problem: Increasing Triplet Subsequence

Given an integer array `nums`, determine whether there exists indices i < j < k 
such that `nums[i] < nums[j] < nums[k]`. Return `true` if such a triplet exists, otherwise `false`.

Example:
nums = [2, 1, 5, 0, 4, 6]
Output: true  // One increasing triplet is 1, 4, 6
*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool increasingTriplet(int* nums, int numsSize) {
    if (numsSize < 3) return false;

    int first = INT_MAX, second = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num <= first) {
            first = num;
        } else if (num <= second) {
            second = num;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int nums[] = {2, 1, 5, 0, 4, 6};
    int n = sizeof(nums) / sizeof(nums[0]);

    bool found = increasingTriplet(nums, n);
    printf("Increasing triplet exists: %s\n", found ? "true" : "false");  // Expected: true

    return 0;
}
