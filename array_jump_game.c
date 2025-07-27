// Problem: Jump Game

// Description:
// You are given an integer array `nums`. You are initially positioned at the array's first index,
// and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.
//
// Example:
// Input: nums = [2,3,1,1,4]
// Output: true
//
// Input: nums = [3,2,1,0,4]
// Output: false

#include <stdio.h>

int canJump(int* nums, int numsSize) {
    int reachable = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > reachable)
            return 0;
        if (i + nums[i] > reachable)
            reachable = i + nums[i];
    }
    return 1;
}

// Sample test cases
int main() {
    int nums1[] = {2, 3, 1, 1, 4};
    int nums2[] = {3, 2, 1, 0, 4};

    printf("Can jump from nums1: %s\n", canJump(nums1, 5) ? "true" : "false");
    printf("Can jump from nums2: %s\n", canJump(nums2, 5) ? "true" : "false");

    return 0;
}

/*
Output:
Can jump from nums1: true
Can jump from nums2: false
*/
