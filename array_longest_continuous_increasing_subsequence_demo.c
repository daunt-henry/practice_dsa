/*
Problem: Longest Continuous Increasing Subsequence (LeetCode 674)

Find the length of the longest strictly increasing contiguous subarray in nums.

Approach:
Use a single pass with two counters:
- curr: current length of increasing run
- maxLen: maximum so far
Reset curr to 1 when the sequence breaks.

Time: O(n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int findLengthOfLCIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int maxLen = 1, curr = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) curr++;
        else curr = 1;
        if (curr > maxLen) maxLen = curr;
    }
    return maxLen;
}

void test(int* arr, int n) {
    printf("Input: [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], i + 1 < n ? ", " : "");
    }
    printf("] → LCIS length = %d\n", findLengthOfLCIS(arr, n));
}

int main(void) {
    int v1[] = {1, 3, 5, 4, 7};
    test(v1, 5);  // Expected 3

    int v2[] = {2, 2, 2, 2, 2};
    test(v2, 5);  // Expected 1

    int v3[] = {1, 2, 3, 4, 5};
    test(v3, 5);  // Expected 5

    int v4[] = {};
    test(v4, 0);  // Expected 0

    return 0;
}
