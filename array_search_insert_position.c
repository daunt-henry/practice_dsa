/*
Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Filename: search_insert_position.c
*/

#include <stdio.h>

// Function to find the insert position
int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

// Sample test
int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int index = searchInsert(nums, 4, target);
    printf("Insert position for %d is: %d\n", target, index);

    target = 2;
    index = searchInsert(nums, 4, target);
    printf("Insert position for %d is: %d\n", target, index);

    target = 7;
    index = searchInsert(nums, 4, target);
    printf("Insert position for %d is: %d\n", target, index);

    return 0;
}
