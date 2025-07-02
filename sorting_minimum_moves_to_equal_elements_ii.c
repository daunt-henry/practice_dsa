/*
Problem: Minimum Moves to Equal Array Elements II

Description:
You can increment/decrement any element by 1.
Return the minimum moves to make all elements equal.

Approach:
- The optimal target value is the median.
- Sort the array, pick median, and sum absolute differences.

Time: O(n log n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int median = nums[numsSize / 2];
    int moves = 0;
    for (int i = 0; i < numsSize; i++) {
        moves += abs(nums[i] - median);
    }
    return moves;
}

// Test
int main() {
    int nums[] = {1, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = minMoves2(nums, size);
    printf("Minimum moves to equal elements: %d\n", result);
    return 0;
}

/*
========= OUTPUT =========
Minimum moves to equal elements: 2
==========================
*/
