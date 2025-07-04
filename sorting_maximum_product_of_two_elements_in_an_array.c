/*
Maximum Product of Two Elements in an Array

Problem:
- Given an array of integers, return the maximum value of (nums[i]-1)*(nums[j]-1)
  where i ≠ j.

Approach:
- Sort the array in descending order.
- The largest product will always be from the two largest numbers.

Time: O(n log n) — due to sorting
Space: O(1) — in-place sort

Example:
Input: nums = [3,4,5,2]
Sorted: [5,4,3,2]
Output: (5-1)*(4-1) = 4*3 = 12
*/

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a); // Descending
}

int maxProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return (nums[0] - 1) * (nums[1] - 1);
}
