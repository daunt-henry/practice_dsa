/*
Problem: Majority Element

Description:
Given an array of size n, find the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists.

Example:
Input: [2,2,1,1,1,2,2]
Output: 2
*/

#include <stdio.h>

// Moore's Voting Algorithm
int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int candidate = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}

// Main for testing
int main() {
    int nums[] = {2, 2, 1, 1, 1, 2, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = majorityElement(nums, size);
    printf("Majority Element: %d\n", result);
    return 0;
}

/*
========= OUTPUT =========
Majority Element: 2
==========================
*/
