/*
Special Array With X Elements Greater Than or Equal X

Problem:
You are given an array `nums` of non-negative integers.
A special array has the property that there are exactly `x` elements ≥ `x`.
Return the value of `x` if it exists, otherwise return -1.

Approach:
- Try all values of `x` from 0 to numsSize.
- For each x, count how many elements are >= x.
- If count == x, return x.

Time Complexity: O(n^2) in worst case (small constraints)
Space Complexity: O(1)

Example:
Input: nums = [3,5]
Output: 2
*/

#include <stdio.h>

int specialArray(int* nums, int numsSize) {
    for (int x = 0; x <= numsSize; x++) {
        int count = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] >= x) count++;
        }
        if (count == x) return x;
    }
    return -1;
}
