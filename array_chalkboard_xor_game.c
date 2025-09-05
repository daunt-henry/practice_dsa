/*
 * Problem: Chalkboard XOR Game (LeetCode 810)
 *
 * Alice and Bob alternately erase one number from the chalkboard:
 * - If erasing makes the XOR of remaining numbers equal to zero, that player loses.
 * - If a player's turn starts with XOR = 0, that player wins immediately.
 *
 * Optimal-play insight:
 * Alice wins if either:
 *   1. The initial XOR is 0 (Alice wins instantly).
 *   2. The total number of elements is even (Alice can force a win).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdbool.h>

bool xorGame(int* nums, int numsSize) {
    int totalXor = 0;
    for (int i = 0; i < numsSize; i++) {
        totalXor ^= nums[i];
    }
    return (totalXor == 0) || (numsSize % 2 == 0);
}

int main(void) {
    int nums1[] = {1, 1, 2};
    printf("Test 1 → Expected: false, Got: %s\n", xorGame(nums1, 3) ? "true" : "false");

    int nums2[] = {0, 1};
    printf("Test 2 → Expected: true, Got: %s\n", xorGame(nums2, 2) ? "true" : "false");

    int nums3[] = {1, 2, 3};
    printf("Test 3 → Expected: true, Got: %s\n", xorGame(nums3, 3) ? "true" : "false");

    return 0;
}
