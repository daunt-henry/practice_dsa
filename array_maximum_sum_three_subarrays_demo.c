/*
Problem: Maximum Sum of 3 Non-Overlapping Subarrays (LeetCode 689)
URL: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

Description:
Given an integer array `nums` and an integer `k`, find three non-overlapping subarrays
of length `k` such that their total sum is maximized. Return the starting indices of
these subarrays. If multiple answers exist, return the lexicographically smallest one.

Approach:
1. Compute the sum of each subarray of length k using a sliding window.
2. Precompute:
   - `left[i]`: starting index of the maximum sum subarray in the range [0..i].
   - `right[i]`: starting index of the maximum sum subarray in the range [i..end].
3. The middle subarray can start from `mid = k` to `mid <= windowCount - k - 1`.
   For each, combine the best left and right options to maximize the total.
4. Track and return the best combination.

Time Complexity: O(n), Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    int n = numsSize;
    int windowCount = n - k + 1;

    int* sums = malloc(windowCount * sizeof(int));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (i >= k) sum -= nums[i - k];
        if (i >= k - 1) sums[i - k + 1] = sum;
    }

    int* left = malloc(windowCount * sizeof(int));
    int best = 0;
    for (int i = 0; i < windowCount; i++) {
        if (sums[i] > sums[best]) best = i;
        left[i] = best;
    }

    int* right = malloc(windowCount * sizeof(int));
    best = windowCount - 1;
    for (int i = windowCount - 1; i >= 0; i--) {
        if (sums[i] >= sums[best]) best = i;
        right[i] = best;
    }

    int* ans = malloc(3 * sizeof(int));
    *returnSize = 3;
    int maxTotal = 0;

    for (int mid = k; mid < windowCount - k; mid++) {
        int l = left[mid - k];
        int r = right[mid + k];
        int total = sums[l] + sums[mid] + sums[r];
        if (total > maxTotal) {
            maxTotal = total;
            ans[0] = l;
            ans[1] = mid;
            ans[2] = r;
        }
    }

    free(sums);
    free(left);
    free(right);
    return ans;
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], i + 1 < size ? ", " : "");
    }
    printf("]\n");
}

int main() {
    int nums1[] = {1,2,1,2,6,7,5,1};
    int k1 = 2, returnSize;
    int* result1 = maxSumOfThreeSubarrays(nums1, 8, k1, &returnSize);
    printf("Input: nums = [1,2,1,2,6,7,5,1], k = 2\nOutput: ");
    printArray(result1, returnSize);  // Expected: [0, 3, 5]
    free(result1);

    int nums2[] = {1,2,1,2,1,2,1,2,1};
    int k2 = 2;
    int* result2 = maxSumOfThreeSubarrays(nums2, 9, k2, &returnSize);
    printf("Input: nums = [1,2,1,2,1,2,1,2,1], k = 2\nOutput: ");
    printArray(result2, returnSize);  // Expected: [0, 2, 4]
    free(result2);

    return 0;
}
