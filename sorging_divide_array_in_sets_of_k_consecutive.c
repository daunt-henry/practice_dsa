/*
Problem:
Check if an array can be divided into sets of k consecutive numbers.

Approach:
1. Sort the array.
2. Use a visited/used array to track which numbers are grouped.
3. Greedily attempt to build each consecutive group of size k from the smallest unused number.

Time: O(n log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool isPossibleDivide(int* nums, int numsSize, int k) {
    if (numsSize % k != 0) return false;

    qsort(nums, numsSize, sizeof(int), cmp);

    int* used = calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;

        used[i] = 1;
        int count = 1;
        int current = nums[i];

        for (int j = i + 1; j < numsSize && count < k; j++) {
            if (!used[j] && nums[j] == current + 1) {
                used[j] = 1;
                current = nums[j];
                count++;
            }
        }

        if (count < k) {
            free(used);
            return false;
        }
    }

    free(used);
    return true;
}

// Test
int main() {
    int nums[] = {1,2,3,3,4,4,5,6};
    int k = 4;
    int n = sizeof(nums) / sizeof(nums[0]);

    bool res = isPossibleDivide(nums, n, k);
    printf("Can divide into sets of %d consecutive numbers: %s\n", k, res ? "true" : "false");  // Expected: true

    return 0;
}

/*
========= OUTPUT =========
Can divide into sets of 4 consecutive numbers: true
==========================
*/
