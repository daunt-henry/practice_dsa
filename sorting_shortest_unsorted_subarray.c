/*
Problem: Shortest Unsorted Continuous Subarray

Given an integer array, return the length of the shortest subarray
that needs to be sorted for the whole array to be sorted.

Approach:
1. Find left and right bounds where sorting breaks.
2. Find min and max in that range.
3. Expand bounds if necessary.
4. Return length of the unsorted window.

Time: O(n)
Space: O(1)
*/

#include <stdio.h>

int findUnsortedSubarray(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < numsSize - 1 && nums[left] <= nums[left + 1])
        left++;

    if (left == numsSize - 1) return 0;

    while (right > 0 && nums[right] >= nums[right - 1])
        right--;

    int min = nums[left], max = nums[left];
    for (int i = left; i <= right; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }

    while (left > 0 && nums[left - 1] > min)
        left--;

    while (right < numsSize - 1 && nums[right + 1] < max)
        right++;

    return right - left + 1;
}

// Test
int main() {
    int nums[] = {2, 6, 4, 8, 10, 9, 15};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = findUnsortedSubarray(nums, size);
    printf("Length of shortest unsorted subarray: %d\n", result);

    return 0;
}

/*
========= OUTPUT =========
Length of shortest unsorted subarray: 5
==========================
*/
