/*
Problem: Find Minimum in Rotated Sorted Array

Description:
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
Return the minimum element of the array.
You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [3,4,5,1,2]
Output: 1

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0

Example 3:
Input: nums = [11,13,15,17]
Output: 11
*/

#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

// Sample test
int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    int min = findMin(nums, size);
    printf("Minimum in rotated sorted array: %d\n", min);
    return 0;
}
