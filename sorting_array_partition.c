/*
Problem: Array Partition

Given an array of 2n integers, group them into n pairs such that
the sum of min(ai, bi) for all pairs is maximized.

Approach:
1. Sort the array.
2. Add every alternate element (i.e., the smaller of each pair).

Time: O(n log n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int sum = 0;
    for (int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }
    return sum;
}

// Test
int main() {
    int nums[] = {1, 4, 3, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = arrayPairSum(nums, size);
    printf("Maximum sum of min of pairs: %d\n", result);

    return 0;
}

/*
========= OUTPUT =========
Maximum sum of min of pairs: 4
==========================
*/
