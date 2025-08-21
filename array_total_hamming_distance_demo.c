/*
Total Hamming Distance (LeetCode 477)

Given an array of non-negative integers, return the sum of Hamming
distances between all pairs of them.

Hamming distance between two numbers is the count of positions where
corresponding bits differ.

Optimized Approach:
- Iterate over each of 31 bit positions (since nums[i] ≤ 1e9).
- Count how many numbers have bit = 1 (countOnes).
- Numbers with bit = 0 is (n - countOnes).
- Add countOnes * (n - countOnes) to the total for that bit.
Overall complexity: O(n·31).

This is significantly faster than O(n²) pairwise comparison.
*/

#include <stdio.h>
#include <stdlib.h>

int totalHammingDistance(int* nums, int numsSize) {
    int total = 0;
    for (int bit = 0; bit < 31; ++bit) {
        int countOnes = 0;
        for (int i = 0; i < numsSize; ++i) {
            countOnes += (nums[i] >> bit) & 1;
        }
        total += countOnes * (numsSize - countOnes);
    }
    return total;
}

int main(void) {
    int nums1[] = {4, 14, 2};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1: %d (expected 6)\n", totalHammingDistance(nums1, n1));

    int nums2[] = {0, 1, 2};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    // Pairs are (0,1)->1, (0,2)->1, (1,2)->2 -> total = 4
    printf("Example 2: %d (expected 4)\n", totalHammingDistance(nums2, n2));

    return 0;
}
