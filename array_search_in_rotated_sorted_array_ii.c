/*
Problem: Search in Rotated Sorted Array II

Given an integer array nums sorted in non-decreasing order and a target value, 
return true if target is in the array, otherwise return false.

The array may contain duplicates and was rotated at an unknown pivot.

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

#include <stdio.h>
#include <stdbool.h>

bool search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return true;

        // Handle duplicates
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
        }
        else if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return false;
}

int main() {
    int nums[] = {2, 5, 6, 0, 0, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    bool found = search(nums, size, target);

    printf("Target %d %s in the array.\n", target, found ? "exists" : "does not exist");

    return 0;
}
