/*
Minimum Moves to Equal Array Elements (LeetCode 453)

Given an integer array, each move increases n - 1 elements by 1.
This is equivalent to decrementing one element per move.

Insight:
The fewest moves are achieved by reducing all elements down to the minimum.
So total moves = sum(nums) - min(nums) * n

Complexity: O(n) time, O(1) additional space
*/

#include <stdio.h>
#include <stdlib.h>

int minMoves(int* nums, int n) {
    long sum = 0;
    int mn = nums[0];
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (nums[i] < mn) mn = nums[i];
    }
    return (int)(sum - (long)mn * n);
}

int main(void) {
    int nums1[] = {1, 2, 3};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Moves needed: %d (expected 3)\n", minMoves(nums1, n1));

    int nums2[] = {5, 6, 8, 8, 5};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Moves needed: %d (expected 7)\n", minMoves(nums2, n2));

    return 0;
}
