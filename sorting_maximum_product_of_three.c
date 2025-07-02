/*
Problem: Maximum Product of Three Numbers

Given an integer array, return the maximum product of any three numbers.

Approach:
- Sort the array.
- Compare:
    1. Product of top 3 elements.
    2. Product of 2 smallest and largest element (in case of negatives).

Time: O(n log n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int a = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    int b = nums[0] * nums[1] * nums[numsSize - 1];

    return a > b ? a : b;
}

// Test
int main() {
    int nums[] = {-10, -10, 5, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = maximumProduct(nums, size);
    printf("Maximum product of three numbers: %d\n", result);

    return 0;
}

/*
========= OUTPUT =========
Maximum product of three numbers: 500
==========================
*/
