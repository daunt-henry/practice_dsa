/*
Problem: Given an integer array, return the sum of widths of all subsequences.
The width of a subsequence is (max - min) of that subsequence.

Approach:
- Sort the array
- Use the formula:
    Each element nums[i] will appear in:
      - 2^i subsets as max
      - 2^(n-1-i) subsets as min

Contribution of nums[i] = nums[i] * (2^i - 2^(n-1-i))

Time: O(n log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int sumSubseqWidths(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    long* pow2 = malloc(sizeof(long) * numsSize);
    pow2[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    long result = 0;
    for (int i = 0; i < numsSize; i++) {
        result = (result + (pow2[i] - pow2[numsSize - 1 - i]) * nums[i]) % MOD;
    }

    free(pow2);
    return (result + MOD) % MOD;
}

// Test
int main() {
    int nums[] = {2, 1, 3};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = sumSubseqWidths(nums, size);
    printf("Output: %d\n", result);  // Expected: 6

    return 0;
}

/*
========= OUTPUT =========
Output: 6
==========================
*/
