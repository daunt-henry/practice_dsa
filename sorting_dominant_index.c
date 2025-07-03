/*
Problem: Largest Number At Least Twice of Others (LeetCode 747)

Given an integer array, find the index of the largest element if it is at least twice as much as every other number. Otherwise, return -1.

Approach:
- Find the maximum value and its index
- Check if it's at least twice every other value

Time: O(n)
Space: O(1)
*/

#include <stdio.h>

int dominantIndex(int* nums, int numsSize) {
    if (numsSize == 0) return -1;

    int maxVal = -1;
    int maxIndex = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            maxIndex = i;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (i != maxIndex && nums[i] * 2 > maxVal) {
            return -1;
        }
    }

    return maxIndex;
}

// Test case
int main() {
    int nums[] = {3, 6, 1, 0};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = dominantIndex(nums, size);
    printf("Output: %d\n", result);

    return 0;
}

/*
========= OUTPUT =========
Output: 1
==========================
*/
