/*
Title: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Problem:
Given an array of integers nums and an integer limit, return the size of the longest 
continuous subarray such that the absolute difference between any two elements 
is less than or equal to limit.

Example:
Input: nums = [8,2,4,7], limit = 4
Output: 2
Explanation: The subarray [2,4] has an absolute difference of 2, which is within the limit.

Constraints:
- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^9
- 0 <= limit <= 10^9
*/

#include <stdio.h>

int longestSubarray(int* nums, int numsSize, int limit) {
    int maxDeque[numsSize], minDeque[numsSize];
    int frontMax = 0, backMax = 0;
    int frontMin = 0, backMin = 0;
    int left = 0, result = 0;

    for (int right = 0; right < numsSize; right++) {
        while (backMax > frontMax && nums[right] > maxDeque[backMax - 1]) backMax--;
        maxDeque[backMax++] = nums[right];

        while (backMin > frontMin && nums[right] < minDeque[backMin - 1]) backMin--;
        minDeque[backMin++] = nums[right];

        while (maxDeque[frontMax] - minDeque[frontMin] > limit) {
            if (nums[left] == maxDeque[frontMax]) frontMax++;
            if (nums[left] == minDeque[frontMin]) frontMin++;
            left++;
        }

        if (right - left + 1 > result) result = right - left + 1;
    }

    return result;
}

int main() {
    int nums[] = {8, 2, 4, 7};
    int limit = 4;
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = longestSubarray(nums, size, limit);
    printf("Longest valid subarray length: %d\n", result);
    return 0;
}
