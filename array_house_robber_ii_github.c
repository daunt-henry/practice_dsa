/*
Problem: House Robber II

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses at this 
place are arranged in a circle. That means the first house is the 
neighbor of the last one. Meanwhile, adjacent houses have security 
systems connected, and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given an integer array `nums` representing the amount of money 
of each house, return the maximum amount of money you can rob tonight 
without alerting the police.

Example:
Input: nums = [2,3,2]
Output: 3

Input: nums = [1,2,3,1]
Output: 4
*/

#include <stdio.h>

int robRange(int* nums, int start, int end) {
    int prev = 0, curr = 0;
    for (int i = start; i <= end; i++) {
        int temp = curr;
        curr = fmax(curr, prev + nums[i]);
        prev = temp;
    }
    return curr;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    return fmax(robRange(nums, 0, numsSize - 2), robRange(nums, 1, numsSize - 1));
}

// Sample test
int main() {
    int nums1[] = {2, 3, 2};
    int nums2[] = {1, 2, 3, 1};

    printf("Max money robbed (example 1): %d\n", rob(nums1, 3));  // Output: 3
    printf("Max money robbed (example 2): %d\n", rob(nums2, 4));  // Output: 4

    return 0;
}
