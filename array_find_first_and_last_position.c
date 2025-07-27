/*
Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Filename: find_first_and_last_position.c
*/

#include <stdio.h>
#include <stdlib.h>

// Binary search to find first or last occurrence
int binarySearch(int* nums, int numsSize, int target, int findFirst) {
    int low = 0, high = numsSize - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result = mid;
            if (findFirst)
                high = mid - 1;
            else
                low = mid + 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Main search function
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = binarySearch(nums, numsSize, target, 1);
    result[1] = binarySearch(nums, numsSize, target, 0);
    *returnSize = 2;
    return result;
}

// Sample test
int main() {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int returnSize;
    int* range = searchRange(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);

    printf("Range for target %d: [%d, %d]\n", target, range[0], range[1]);  // Output: [3, 4]

    target = 6;
    range = searchRange(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
    printf("Range for target %d: [%d, %d]\n", target, range[0], range[1]);  // Output: [-1, -1]

    free(range);
    return 0;
}
