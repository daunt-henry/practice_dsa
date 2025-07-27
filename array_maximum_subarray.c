/*
Problem: Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
*/

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int max_sum = nums[0];
    int current_sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        current_sum = nums[i] > (current_sum + nums[i]) ? nums[i] : (current_sum + nums[i]);
        max_sum = current_sum > max_sum ? current_sum : max_sum;
    }
    return max_sum;
}

// Sample test
int main() {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = maxSubArray(nums, size);
    printf("Maximum Subarray Sum: %d\n", result); // Output: 6
    return 0;
}
