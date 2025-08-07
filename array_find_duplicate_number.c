/*
Problem: Find the Duplicate Number

Given an array `nums` containing `n + 1` integers where each integer
is in the range [1, n]. There is only one repeated number. Find this
duplicate without modifying the array and using only constant extra space.

Example:
Input: nums = [1, 3, 4, 2, 2]
Output: 2

Input: nums = [3, 1, 3, 4, 2]
Output: 3
*/

#include <stdio.h>

int findDuplicate(int* nums, int numsSize) {
    int slow = nums[0];
    int fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    int nums1[] = {1, 3, 4, 2, 2};
    int nums2[] = {3, 1, 3, 4, 2};

    printf("Duplicate in nums1: %d\n", findDuplicate(nums1, 5)); // Output: 2
    printf("Duplicate in nums2: %d\n", findDuplicate(nums2, 5)); // Output: 3

    return 0;
}
