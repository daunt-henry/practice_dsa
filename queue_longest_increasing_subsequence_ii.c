/*
Title: Longest Increasing Subsequence II

Description:
Given an integer array nums and an integer k, return the length of the longest
increasing subsequence of nums such that the difference between adjacent elements
is at most k.

Example:
Input: nums = [1, 5, 4, 6, 2, 1], k = 2
Output: 4

Explanation:
The LIS could be: [1, 4, 6], [1, 2], etc. Best one: [1, 4, 6, or 1, 2, 4, 6].

Constraints:
- 1 <= nums.length <= 1e5
- 1 <= nums[i], k <= 1e5
*/

#include <stdio.h>

#define MAX 100005

int seg[MAX * 4];

int max(int a, int b) {
    return a > b ? a : b;
}

int query(int l, int r, int s, int e, int idx) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return seg[idx];
    int m = (s + e) / 2;
    return max(query(l, r, s, m, 2*idx), query(l, r, m+1, e, 2*idx+1));
}

void update(int pos, int val, int s, int e, int idx) {
    if (s == e) {
        seg[idx] = max(seg[idx], val);
        return;
    }
    int m = (s + e) / 2;
    if (pos <= m) update(pos, val, s, m, 2*idx);
    else update(pos, val, m+1, e, 2*idx+1);
    seg[idx] = max(seg[2*idx], seg[2*idx+1]);
}

int lengthOfLIS(int* nums, int numsSize, int k) {
    for (int i = 0; i < MAX * 4; i++) seg[i] = 0;

    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        int l = (nums[i] - k > 1) ? nums[i] - k : 1;
        int r = nums[i] - 1;
        int maxPrev = 0;
        if (l <= r)
            maxPrev = query(l, r, 1, MAX, 1);
        int currLen = maxPrev + 1;
        update(nums[i], currLen, 1, MAX, 1);
        if (currLen > maxVal)
            maxVal = currLen;
    }
    return maxVal;
}

int main() {
    int nums[] = {1, 5, 4, 6, 2, 1};
    int k = 2;
    int n = sizeof(nums) / sizeof(nums[0]);
    int result = lengthOfLIS(nums, n, k);
    printf("Longest Increasing Subsequence II length: %d\n", result); // Output: 4
    return 0;
}
