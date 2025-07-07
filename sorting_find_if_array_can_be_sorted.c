/*
Problem:
You are given an array `nums`. You can only sort **contiguous subarrays**
where all elements have the same number of 1s in their binary representation.

Determine whether you can sort the entire array using **only** such operations.

Example Input:
nums = [8,4,2,30,15]

Expected Output:
true

Explanation:
Binary bit counts:
8 (1000) → 1
4 (0100) → 1
2 (0010) → 1
30 (11110) → 4
15 (01111) → 4

We can sort [8,4,2] → [2,4,8] and [30,15] → [15,30]

Final array: [2,4,8,15,30] which is sorted → return true.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool canSortArray(int* nums, int numsSize) {
    int* bitCounts = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        int count = 0, n = nums[i];
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        bitCounts[i] = count;
    }

    int l = 0;
    while (l < numsSize) {
        int r = l;
        while (r + 1 < numsSize && bitCounts[r + 1] == bitCounts[l]) ++r;

        if (r > l) {
            qsort(nums + l, r - l + 1, sizeof(int), cmp);
        }
        l = r + 1;
    }

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] < nums[i - 1]) {
            free(bitCounts);
            return false;
        }
    }

    free(bitCounts);
    return true;
}

int main() {
    int nums[] = {8, 4, 2, 30, 15};
    int size = sizeof(nums) / sizeof(nums[0]);

    if (canSortArray(nums, size)) {
        printf("The array can be sorted under the constraints.\n");
    } else {
        printf("The array cannot be sorted under the constraints.\n");
    }

    return 0;
}
