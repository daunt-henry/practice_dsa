/*
Problem: Degree of an Array (LeetCode 697)
URL: https://leetcode.com/problems/degree-of-an-array/

Given a non-empty array 'nums', the **degree** is the maximum frequency of any element.
Find the length of the shortest contiguous subarray with the same degree.

Approach:
1. Track count[], first[], and last[] occurrences for each value.
2. Compute the degree (maximum count).
3. For all values with that count, calculate subarray length (last - first + 1).
4. Return the minimum of these lengths.

Time Complexity: O(n + M), Space Complexity: O(M), where M = range of values (≤50,000).
*/

#include <stdio.h>
#include <stdlib.h>

int findShortestSubArray(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    const int MAXV = 50000;
    int *count = calloc(MAXV, sizeof(int));
    int *first = malloc(MAXV * sizeof(int));
    int *last  = malloc(MAXV * sizeof(int));

    for (int i = 0; i < MAXV; i++) {
        first[i] = -1;
        last[i] = -1;
    }

    int degree = 0;
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        if (first[v] == -1) first[v] = i;
        last[v] = i;
        count[v]++;
        if (count[v] > degree) degree = count[v];
    }

    int ans = numsSize;
    for (int v = 0; v < MAXV; v++) {
        if (count[v] == degree) {
            int len = last[v] - first[v] + 1;
            if (len < ans) ans = len;
        }
    }

    free(count);
    free(first);
    free(last);
    return ans;
}

// --------------- Demo ----------------
int main(void) {
    int nums1[] = {1, 2, 2, 3, 1};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1 → %d (expected: 2)\n", findShortestSubArray(nums1, n1));

    int nums2[] = {1, 2, 2, 3, 1, 4, 2};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Example 2 → %d (expected: 6)\n", findShortestSubArray(nums2, n2));

    return 0;
}
