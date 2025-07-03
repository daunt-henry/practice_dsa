/*
Problem:
Given a list of words, find the length of the longest word chain where each word is a predecessor
of the next by adding exactly one letter.

Approach:
- Sort words by length.
- Use dynamic programming (dp[i] = longest chain ending at word[i]).
- Check if word[j] is a predecessor of word[i] using character matching.

Time: O(n^2 * L), where L = average word length
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return strlen(*(char**)a) - strlen(*(char**)b);
}

int isPredecessor(char* shorter, char* longer) {
    int len1 = strlen(shorter), len2 = strlen(longer);
    if (len2 - len1 != 1) return 0;

    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (shorter[i] == longer[j]) {
            i++; j++;
        } else {
            j++;
            if (j - i > 1) return 0;
        }
    }
    return 1;
}

int longestStrChain(char** words, int wordsSize) {
    qsort(words, wordsSize, sizeof(char*), compare);

    int* dp = (int*)calloc(wordsSize, sizeof(int));
    int maxLen = 1;

    for (int i = 0; i < wordsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (isPredecessor(words[j], words[i])) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (dp[i] > maxLen) maxLen = dp[i];
    }

    free(dp);
    return maxLen;
}

// Test
int main() {
    char* words[] = {"a", "b", "ba", "bca", "bda", "bdca"};
    int size = sizeof(words) / sizeof(words[0]);
    int result = longestStrChain(words, size);
    printf("Longest String Chain Length: %d\n", result);  // Expected: 4

    return 0;
}

/*
========= OUTPUT =========
Longest String Chain Length: 4
==========================
*/
