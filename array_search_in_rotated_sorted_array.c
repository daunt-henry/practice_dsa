/*
Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values),
which is rotated at an unknown pivot. You are given the array and a target value.

Return the index of the target if found, otherwise return -1.
The algorithm must run in O(log n) time.

Example:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Filename: search_in_rotated_sorted_array.c
*/

#include <stdio.h>

// Binary search in rotated sorted array
int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}

// Sample test
int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    int index = search(nums, size, target);
    printf("Target %d found at index: %d\n", target, index);  // Output: 4

    target = 3;
    index = search(nums, size, target);
    printf("Target %d found at index: %d\n", target, index);  // Output: -1

    return 0;
}
