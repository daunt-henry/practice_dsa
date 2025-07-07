// Question:
// Given an integer array nums with at least three elements,
// return any element that is neither the minimum nor the maximum.
// If no such element exists, return -1.

// Output:
// Input: nums = [3, 2, 1, 4]
// Possible Output: 2 or 3 (any value that is not the min or max)

#include <stdio.h>

int findNonMinOrMax(int* nums, int numsSize) {
    if (numsSize < 3) return -1;

    int a = nums[0], b = nums[1], c = nums[2];

    if ((a > b && a < c) || (a < b && a > c)) return a;
    if ((b > a && b < c) || (b < a && b > c)) return b;
    return c;
}

// ---------- Main Test ----------
int main() {
    int nums[] = {3, 2, 1, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = findNonMinOrMax(nums, size);
    printf("%d\n", result); // Output: 2 or 3
    return 0;
}
