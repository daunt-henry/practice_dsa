/*
Title: Minimum Number of K Consecutive Bit Flips

Problem:
You are given a binary array nums and an integer k.
A k-bit flip is choosing a subarray of length k and flipping all bits (0 -> 1, 1 -> 0).
Return the minimum number of k-bit flips to make the array all 1s.
If it's not possible, return -1.

Example:
Input: nums = [0,1,0], k = 1
Output: 2

Input: nums = [1,1,0], k = 2
Output: -1

Constraints:
- 1 <= nums.length <= 10^5
- 1 <= k <= nums.length
*/

#include <stdio.h>
#include <stdlib.h>

int minKBitFlips(int* nums, int numsSize, int k) {
    int flips = 0, flip = 0;
    int *hint = (int *)calloc(numsSize, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        if (i >= k) flip ^= hint[i - k];
        if ((nums[i] ^ flip) == 0) {
            if (i + k > numsSize) {
                free(hint);
                return -1;
            }
            flips++;
            flip ^= 1;
            hint[i] = 1;
        }
    }

    free(hint);
    return flips;
}

int main() {
    int nums[] = {0, 1, 0};
    int k = 1;
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = minKBitFlips(nums, size, k);
    printf("Minimum flips needed: %d\n", result);

    return 0;
}
