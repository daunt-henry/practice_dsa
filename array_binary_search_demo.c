/*
Problem: Binary Search (LeetCode 704)
URL: https://leetcode.com/problems/binary-search/

Given a sorted integer array `nums` and a `target`, return the index of `target`
in `nums` if present; otherwise, return −1. Must use O(log n) time.

Approach:
Use iterative binary search by maintaining `left` and `right` pointers.

Time Complexity: O(log n)  
Space Complexity: O(1)
*/

#include <stdio.h>

// LeetCode-compliant function
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Demo usage for GitHub
int main(void) {
    int nums1[] = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("search([-1,0,3,5,9,12], 9) = %d (expected: 4)\n", search(nums1, n1, target1));

    int target2 = 2;
    printf("search([-1,0,3,5,9,12], 2) = %d (expected: -1)\n", search(nums1, n1, target2));

    return 0;
}
