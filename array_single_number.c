// Filename: single_number.c

/*
Problem: Single Number

Given a non-empty array of integers `nums`, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
*/

#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    int nums1[] = {2, 2, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Single number is: %d\n", singleNumber(nums1, size1)); // Output: 1

    int nums2[] = {4, 1, 2, 1, 2};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Single number is: %d\n", singleNumber(nums2, size2)); // Output: 4

    return 0;
}
