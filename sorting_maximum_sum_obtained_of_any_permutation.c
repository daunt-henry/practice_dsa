/*
Maximum Sum Obtained of Any Permutation

Problem:
- You're given an array and multiple range queries (requests).
- You can permute the array however you like.
- Maximize the sum of elements at positions defined by requests.

Approach:
- Count how many times each index is covered using prefix sums.
- The more an index is used, the bigger number it should get.
- Sort both the original array and the frequency array, and pair biggest with most used.

Time: O(n log n + m)
Space: O(n)

Example:
Input: nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
Output: 19
Explanation: Best permutation is [1,5,4,3,2] → sum = nums[0]+nums[1]+nums[1]+nums[2]+nums[3] = 1+5+5+4+3 = 18
*/

#include <stdlib.h>

#define MOD 1000000007

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxSumRangeQuery(int* nums, int numsSize, int** requests, int requestsSize, int* requestsColSize) {
    int* freq = (int*)calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i < requestsSize; i++) {
        int l = requests[i][0];
        int r = requests[i][1];
        freq[l]++;
        if (r + 1 < numsSize) freq[r + 1]--;
    }

    for (int i = 1; i < numsSize; i++) {
        freq[i] += freq[i - 1];
    }

    qsort(freq, numsSize, sizeof(int), compare);
    qsort(nums, numsSize, sizeof(int), compare);

    long long sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum = (sum + (long long)freq[i] * nums[i]) % MOD;
    }

    free(freq);
    return (int)sum;
}
