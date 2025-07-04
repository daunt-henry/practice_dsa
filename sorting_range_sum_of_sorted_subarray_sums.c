/*
Range Sum of Sorted Subarray Sums

Problem:
- Generate all subarray sums from the array.
- Sort these sums.
- Return the sum of elements from index `left` to `right` (1-based) in this sorted array, modulo 1e9+7.

Approach:
1. Generate all possible subarray sums.
2. Sort the array of subarray sums.
3. Sum the values from position `left - 1` to `right - 1`.

Time: O(n^2 log n)
Space: O(n^2)

Example:
Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13
Explanation: Subarray sums: [1,2,3,4,3,5,7,6,9,10]
Sorted: [1,2,3,3,4,5,6,7,9,10], sum of first 5 = 1+2+3+3+4 = 13
*/

#include <stdlib.h>

#define MOD 1000000007

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
    int totalSub = numsSize * (numsSize + 1) / 2;
    int* subsums = malloc(sizeof(int) * totalSub);
    int index = 0;

    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            subsums[index++] = sum;
        }
    }

    qsort(subsums, totalSub, sizeof(int), cmp);

    long long result = 0;
    for (int i = left - 1; i < right; i++) {
        result = (result + subsums[i]) % MOD;
    }

    free(subsums);
    return (int)result;
}
