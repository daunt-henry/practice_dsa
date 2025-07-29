/*
Problem: Find Peak Element

A peak element is an element that is strictly greater than its neighbors.
Given an integer array `nums`, find a peak element, and return its index.
You may imagine that `nums[-1] = nums[n] = -∞`.

Input:  nums = [1,2,3,1]
Output: 2

Input:  nums = [1,2,1,3,5,6,4]
Output: 5
*/

#include <stdio.h>

int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

// Test function
int main() {
    int nums1[] = {1, 2, 3, 1};
    int nums2[] = {1, 2, 1, 3, 5, 6, 4};

    printf("Peak Index in nums1: %d\n", findPeakElement(nums1, 4));  // Output: 2
    printf("Peak Index in nums2: %d\n", findPeakElement(nums2, 7));  // Output: 5

    return 0;
}
