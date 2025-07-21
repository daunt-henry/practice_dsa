/*
Title: Subarray With Elements Greater Than Varying Threshold
Link: https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/

Given an array nums and integer threshold, return the size of the shortest subarray
such that the minimum in the subarray * length > threshold.
Return -1 if no such subarray exists.

Example:
Input: nums = [1,3,4,3,1], threshold = 6
Output: 3
Explanation: The subarray [3,4,3] has min=3, len=3 => 3*3=9 > 6

Approach:
- Use a monotonic stack to find previous and next smaller elements for each index.
- Determine width (subarray length) where current element is the minimum.
- Check if element * width > threshold.
*/

#include <stdio.h>

int validSubarraySize(int* nums, int numsSize, int threshold) {
    int left[numsSize], right[numsSize];
    int stack[numsSize], top = -1;

    // Previous smaller element (left bound)
    for (int i = 0; i < numsSize; ++i) {
        while (top >= 0 && nums[stack[top]] >= nums[i])
            --top;
        left[i] = (top == -1) ? 0 : stack[top] + 1;
        stack[++top] = i;
    }

    // Next smaller element (right bound)
    top = -1;
    for (int i = numsSize - 1; i >= 0; --i) {
        while (top >= 0 && nums[stack[top]] >= nums[i])
            --top;
        right[i] = (top == -1) ? numsSize - 1 : stack[top] - 1;
        stack[++top] = i;
    }

    // Check valid window size
    for (int i = 0; i < numsSize; ++i) {
        int len = right[i] - left[i] + 1;
        if (nums[i] > threshold / len)
            return len;
    }

    return -1;
}

int main() {
    int nums[] = {1, 3, 4, 3, 1};
    int threshold = 6;
    int result = validSubarraySize(nums, 5, threshold);
    printf("Output: %d\n", result); // Expected: 3
    return 0;
}
