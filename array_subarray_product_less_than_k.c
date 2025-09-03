/*
Problem: Subarray Product Less Than K (LeetCode 713)
URL: https://leetcode.com/problems/subarray-product-less-than-k/

Given an array of positive integers `nums[]` and a positive threshold `k`,
return the number of contiguous subarrays where the product of all elements is strictly less than `k`.

Approach: Sliding Window (Two Pointers)
- Keep a window from `left` to `right`, tracking the product of elements in `prod`.
- For each `right`, multiply into `prod`.
  - If `prod >= k`, divide out elements from the left until `prod < k` again.
- The number of valid subarrays ending at `right` is `right - left + 1`.
- Accumulate this count in `total`.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <stdio.h>

int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (k <= 1) return 0;

    long long prod = 1;
    int total = 0, left = 0;

    for (int right = 0; right < numsSize; right++) {
        prod *= nums[right];
        while (prod >= k && left <= right) {
            prod /= nums[left++];
        }
        total += right - left + 1;
    }

    return total;
}

int main(void) {
    int nums1[] = {10, 5, 2, 6};
    int k1 = 100;
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Result1: %d (expected 8)\n", numSubarrayProductLessThanK(nums1, n1, k1));

    int nums2[] = {1, 2, 3};
    int k2 = 0;
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Result2: %d (expected 0)\n", numSubarrayProductLessThanK(nums2, n2, k2));

    int nums3[] = {1, 1, 1};
    int k3 = 2;
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Result3: %d (expected 6)\n", numSubarrayProductLessThanK(nums3, n3, k3));

    return 0;
}
