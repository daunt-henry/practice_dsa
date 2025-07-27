/*
Problem: First Missing Positive

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

Example 1:
Input: nums = [1,2,0]
Output: 3

Example 2:
Input: nums = [3,4,-1,1]
Output: 2

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
*/

#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            int temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1)
            return i + 1;
    }

    return numsSize + 1;
}

int main() {
    int nums[] = {3, 4, -1, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = firstMissingPositive(nums, size);
    printf("First missing positive: %d\n", result);
    return 0;
}

/*
Sample Output:
First missing positive: 2
*/
