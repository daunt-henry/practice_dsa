/*
Problem:
Make array elements unique by incrementing duplicates.
Return the minimum number of increments needed.

Approach:
- Sort the array.
- Traverse from left to right.
- If current number is not greater than previous, increment it to (previous + 1).
- Track total increments (moves).

Time: O(n log n) due to sort
Space: O(1) extra
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minIncrementForUnique(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int moves = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= nums[i - 1]) {
            int increment = nums[i - 1] + 1 - nums[i];
            moves += increment;
            nums[i] = nums[i - 1] + 1;
        }
    }
    return moves;
}

// Test
int main() {
    int nums[] = {3, 2, 1, 2, 1, 7};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = minIncrementForUnique(nums, size);
    printf("Output: %d\n", result);  // Expected: 6

    return 0;
}

/*
========= OUTPUT =========
Output: 6
==========================
*/
