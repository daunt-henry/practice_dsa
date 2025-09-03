/*
Problem: Stickers to Spell Word (LeetCode 691)
URL: https://leetcode.com/problems/stickers-to-spell-word/

You are given stickers (words) and a target string.
You have infinite copies of each sticker.
Cut letters from stickers to form target. Find the minimum number of stickers needed,
or return -1 if impossible.

Approach: Bitmask Dynamic Programming
- Represent each subset of characters of target via bitmask (up to 2^n states).
- dp[mask] = minimum stickers to form characters represented by mask.
- Transition: For each mask and each sticker, greedily augment mask by matching missing characters.
- Return dp[fullMask] or -1 if unreachable.

Time: O(stickersSize * 2^n * n)
Space: O(2^n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// LeetCode-compatible function
int minStickers(char** stickers, int stickersSize, char* target) {
    int n = strlen(target), fullMask = 1 << n;
    int* dp = malloc(fullMask * sizeof(int));
    for (int i = 0; i < fullMask; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int mask = 0; mask < fullMask; mask++) {
        if (dp[mask] == INT_MAX) continue;
        for (int i = 0; i < stickersSize; i++) {
            char* st = stickers[i];
            int freq[26] = {0};
            for (char* p = st; *p; p++) freq[*p - 'a']++;

            int superMask = mask;
            for (int j = 0; j < n; j++) {
                if (!(superMask & (1 << j)) && freq[target[j] - 'a'] > 0) {
                    freq[target[j] - 'a']--;
                    superMask |= (1 << j);
                }
            }

            if (dp[superMask] > dp[mask] + 1) {
                dp[superMask] = dp[mask] + 1;
            }
        }
    }

    int res = dp[fullMask - 1];
    free(dp);
    return res == INT_MAX ? -1 : res;
}

// Simple test harness
int main(void) {
    char* stickers1[] = {"with", "example", "science"};
    char target1[] = "thehat";
    printf("Min stickers for \"%s\": %d (expected: 3)\n",
           target1, minStickers(stickers1, 3, target1));

    char* stickers2[] = {"notice", "possible"};
    char target2[] = "basicbasic";
    printf("Min stickers for \"%s\": %d (expected: -1)\n",
           target2, minStickers(stickers2, 2, target2));

    return 0;
}
