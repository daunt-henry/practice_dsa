/*
Problem: Single Number II

Given an integer array `nums` where every element appears three times except for one, which appears exactly once. 
Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/

#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0;
    for (int i = 0; i < numsSize; i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}

int main() {
    int nums1[] = {2, 2, 3, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Single number is: %d\n", singleNumber(nums1, size1)); // Output: 3

    int nums2[] = {0, 1, 0, 1, 0, 1, 99};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Single number is: %d\n", singleNumber(nums2, size2)); // Output: 99

    return 0;
}
