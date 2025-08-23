/*
Problem: K-diff Pairs in an Array
URL: https://leetcode.com/problems/k-diff-pairs-in-an-array/

Description:
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
A k-diff pair is an integer pair (nums[i], nums[j]), where:
    - 0 <= i < j < nums.length
    - |nums[i] - nums[j]| == k

Constraints:
- 1 <= nums.length <= 10^4
- -10^7 <= nums[i] <= 10^7
- 0 <= k <= 10^7

Example 1:
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: The 2 pairs are (1, 3) and (3, 5).

Example 2:
Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: The 4 pairs are (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:
Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: The 1 pair is (1, 1).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findPairs(int* nums, int numsSize, int k) {
    if (numsSize == 0 || k < 0) return 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    int count = 0;
    int left = 0, right = 1;

    while (right < numsSize) {
        if (left == right || nums[right] - nums[left] < k) {
            right++;
        } else if (nums[right] - nums[left] > k) {
            left++;
        } else {
            count++;
            left++;
            right++;
            while (right < numsSize && nums[right] == nums[right - 1]) {
                right++;
            }
        }
    }

    return count;
}

int main() {
    int nums1[] = {3, 1, 4, 1, 5};
    int k1 = 2;
    printf("Output: %d\n", findPairs(nums1, 5, k1)); // Expected 2

    int nums2[] = {1, 2, 3, 4, 5};
    int k2 = 1;
    printf("Output: %d\n", findPairs(nums2, 5, k2)); // Expected 4

    int nums3[] = {1, 3, 1, 5, 4};
    int k3 = 0;
    printf("Output: %d\n", findPairs(nums3, 5, k3)); // Expected 1

    return 0;
}
