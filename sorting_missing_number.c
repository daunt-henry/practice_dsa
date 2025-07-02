/*
Problem: Missing Number

Description:
Given an array nums containing n distinct numbers in the range [0, n],
return the one number that is missing from the array.

Example:
Input: [3, 0, 1]
Output: 2
*/

#include <stdio.h>

// Function to find the missing number
int missingNumber(int* nums, int numsSize) {
    int expectedSum = numsSize * (numsSize + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < numsSize; i++) {
        actualSum += nums[i];
    }

    return expectedSum - actualSum;
}

// Test the function
int main() {
    int nums[] = {3, 0, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    int missing = missingNumber(nums, size);
    printf("Missing Number: %d\n", missing);

    return 0;
}

/*
========= OUTPUT =========
Missing Number: 2
==========================
*/
