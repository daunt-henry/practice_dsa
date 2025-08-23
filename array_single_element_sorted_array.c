/*
Problem: Single Element in a Sorted Array
URL: https://leetcode.com/problems/single-element-in-a-sorted-array/

You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. Find that single element.

You must write a solution with O(log n) runtime complexity and O(1) space complexity.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

#include <stdio.h>

int singleNonDuplicate(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // Ensure mid is even
        if (mid % 2 == 1) mid--;
        
        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

// --- Test driver for GitHub showcase ---
int main() {
    int nums1[] = {1,1,2,3,3,4,4,8,8};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output 1: %d\n", singleNonDuplicate(nums1, n1)); // Expected: 2

    int nums2[] = {3,3,7,7,10,11,11};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output 2: %d\n", singleNonDuplicate(nums2, n2)); // Expected: 10

    return 0;
}
