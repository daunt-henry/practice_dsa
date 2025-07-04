/*
Number of Subsequences That Satisfy the Given Sum Condition

Problem:
- Given an array nums and an integer target, return the number of non-empty subsequences
  such that the sum of the minimum and maximum elements is less than or equal to target.

Approach:
- Sort the array.
- Use two pointers (left and right).
- For each valid pair (nums[left] + nums[right] <= target),
  the number of subsequences is 2^(right - left).
- Precompute powers of 2 modulo 1e9+7.

Time: O(n log n) for sorting
Space: O(n) for power array

Example:
Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: Subsequences: [3], [3,5], [3,5,6], [3,6]
*/

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int numSubseq(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int* power = malloc(sizeof(int) * numsSize);
    power[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        power[i] = (power[i - 1] * 2) % MOD;
    }

    int left = 0, right = numsSize - 1;
    int count = 0;

    while (left <= right) {
        if (nums[left] + nums[right] <= target) {
            count = (count + power[right - left]) % MOD;
            left++;
        } else {
            right--;
        }
    }

    free(power);
    return count;
}
