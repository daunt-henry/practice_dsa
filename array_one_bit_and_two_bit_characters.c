/*
Problem: 1-bit and 2-bit Characters (LeetCode 717)
URL: https://leetcode.com/problems/1-bit-and-2-bit-characters/

Given a binary array `bits[]` that ends with 0, determine if the last character
decoded must be a one-bit character (0), rather than the trailing part of a two-bit character (10 or 11).

Approach:
Iterate through the array using a single pointer `i`:
- If bits[i] == 0, skip 1 position.
- If bits[i] == 1, skip 2 positions.
Stop when `i` reaches or surpasses `bitsSize - 1`. If `i` equals `bitsSize - 1`, the last character is one-bit.

Time: O(n), Space: O(1)
*/

#include <stdio.h>
#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;
    while (i < bitsSize - 1) {
        i += bits[i] + 1;
    }
    return i == bitsSize - 1;
}

int main(void) {
    int bits1[] = {1, 0, 0};
    printf("[1,0,0] → %s (expected: true)\n",
           isOneBitCharacter(bits1, 3) ? "true" : "false");

    int bits2[] = {1, 1, 1, 0};
    printf("[1,1,1,0] → %s (expected: false)\n",
           isOneBitCharacter(bits2, 4) ? "true" : "false");

    int bits3[] = {0, 0, 0};
    printf("[0,0,0] → %s (expected: true)\n",
           isOneBitCharacter(bits3, 3) ? "true" : "false");

    return 0;
}
