/*
Problem: Longest Uncommon Subsequence II

Given a list of strings, return the length of the longest uncommon subsequence.
A subsequence is uncommon if it is not a subsequence of any other string in the list.

Approach:
1. For each string, check if it's a subsequence of any other string.
2. If it's not a subsequence of any other, it's a candidate.
3. Track the maximum length among such candidates.

Time: O(n^2 * m), where m is max string length
Space: O(1)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char* a, char* b) {
    int i = 0, j = 0;
    while (a[i] && b[j]) {
        if (a[i] == b[j]) i++;
        j++;
    }
    return a[i] == '\0';
}

int findLUSlength(char** strs, int strsSize) {
    int maxLen = -1;

    for (int i = 0; i < strsSize; i++) {
        bool uncommon = true;

        for (int j = 0; j < strsSize; j++) {
            if (i == j) continue;
            if (isSubsequence(strs[i], strs[j])) {
                uncommon = false;
                break;
            }
        }

        if (uncommon) {
            int len = strlen(strs[i]);
            if (len > maxLen)
                maxLen = len;
        }
    }

    return maxLen;
}

// Test
int main() {
    char* strs[] = {"aba", "cdc", "eae"};
    int size = sizeof(strs) / sizeof(strs[0]);

    int result = findLUSlength(strs, size);
    printf("Longest Uncommon Subsequence Length: %d\n", result);

    return 0;
}

/*
========= OUTPUT =========
Longest Uncommon Subsequence Length: 3
==========================
*/
