/*
Problem:
Minimum Difference Between Highest and Lowest of K Scores

You are given a 0-indexed integer array `nums`, where `nums[i]` represents the score of the i-th student.
Also given an integer `k`.

Pick any k students such that the difference between the highest and lowest scores among them is minimized.

Return the **minimum possible difference**.

Approach:
- Sort the array.
- Use a sliding window of size k to find the minimum difference between max and min in each window.

Example:
Input: nums = [90,100,85,70,60,75], k = 3
Output: 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minimumDifference(int* nums, int numsSize, int k) {
    if (k == 1) return 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    int minDiff = INT_MAX;
    for (int i = 0; i <= numsSize - k; i++) {
        int diff = nums[i + k - 1] - nums[i];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

/*
Sample Input:
nums = [9, 4, 1, 7], k = 2

Sample Output:
2
Explanation: Choose subarray [1, 3] → 4 - 2 = 2
*/
