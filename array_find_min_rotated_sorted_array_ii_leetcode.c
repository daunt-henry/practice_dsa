/*
Problem: Find Minimum in Rotated Sorted Array II

You are given an integer array `nums` sorted in non-decreasing order 
(possibly with duplicates) that was rotated at an unknown pivot.

Return the minimum element of this array.

Input:  nums = [2,2,2,0,1]
Output: 0

Input:  nums = [1,3,5]
Output: 1
*/

#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[right]) {
            right = mid;
        } else if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right--;
        }
    }

    return nums[left];
}

// Test the function
int main() {
    int nums1[] = {2, 2, 2, 0, 1};
    int nums2[] = {1, 3, 5};

    printf("Minimum in nums1: %d\n", findMin(nums1, 5));  // Output: 0
    printf("Minimum in nums2: %d\n", findMin(nums2, 3));  // Output: 1

    return 0;
}
