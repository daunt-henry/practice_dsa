/*
Problem: Minimum Absolute Sum Difference

Description:
You are given two arrays nums1 and nums2 of the same length.
Each element in nums1 can be replaced with another element from nums1 (only once).
Return the minimum possible sum of absolute differences between nums1[i] and nums2[i].

You may replace **at most one** element in nums1 with any element from nums1 to minimize the total absolute sum difference.

Example 1:
Input: nums1 = [1,7,5], nums2 = [2,3,5]
Output: 3

Example 2:
Input: nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
Output: 0

Example 3:
Input: nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
Output: 20

Approach:
- For each index, compute the current difference.
- For every element, find the closest possible value from nums1 (using binary search on sorted nums1).
- Maximize the reduction (gain) in absolute difference.
- Return total - max gain.

Time: O(n log n) due to sorting and binary search
Space: O(n) for sorted array copy
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int* arr, int size, int target) {
    int left = 0, right = size - 1, mid, best = arr[0];
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (abs(arr[mid] - target) < abs(best - target)) {
            best = arr[mid];
        } else if (abs(arr[mid] - target) == abs(best - target)) {
            best = best < arr[mid] ? best : arr[mid];
        }

        if (arr[mid] == target) return arr[mid];
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return best;
}

int minAbsoluteSumDiff(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    const int MOD = 1000000007;
    int totalDiff = 0, maxGain = 0;
    int* sorted = (int*)malloc(sizeof(int) * nums1Size);
    for (int i = 0; i < nums1Size; i++) sorted[i] = nums1[i];
    qsort(sorted, nums1Size, sizeof(int), cmp);

    for (int i = 0; i < nums1Size; i++) {
        int diff = abs(nums1[i] - nums2[i]);
        totalDiff = (totalDiff + diff) % MOD;

        int closest = binarySearch(sorted, nums1Size, nums2[i]);
        int gain = diff - abs(closest - nums2[i]);
        if (gain > maxGain) maxGain = gain;
    }

    free(sorted);
    return (totalDiff - maxGain + MOD) % MOD;
}

// Example usage
/*
int main() {
    int nums1[] = {1,7,5};
    int nums2[] = {2,3,5};
    int n = sizeof(nums1)/sizeof(nums1[0]);
    printf("Output: %d\n", minAbsoluteSumDiff(nums1, n, nums2, n)); // Output: 3
    return 0;
}
*/
