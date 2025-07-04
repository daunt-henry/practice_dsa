/*
Determine if Two Strings Are Close

Problem:
Two strings are considered "close" if:
1. You can swap any two characters any number of times.
2. You can transform every occurrence of one character into another existing character (and vice versa).

Approach:
- Count frequency of each character in both strings
- Also track which characters are present (sets)
- Check if both strings have the same character set
- Check if their frequency arrays (sorted) are identical

Time Complexity: O(n + k log k), where k = 26 (constant)
Space Complexity: O(1)

Example:
Input: word1 = "abc", word2 = "bca"
Output: true

Input: word1 = "a", word2 = "aa"
Output: false
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

bool closeStrings(char * word1, char * word2) {
    int freq1[26] = {0}, freq2[26] = {0};
    int set1[26] = {0}, set2[26] = {0};

    for (int i = 0; word1[i]; i++) {
        freq1[word1[i] - 'a']++;
        set1[word1[i] - 'a'] = 1;
    }

    for (int i = 0; word2[i]; i++) {
        freq2[word2[i] - 'a']++;
        set2[word2[i] - 'a'] = 1;
    }

    // Check if both words use the same characters
    for (int i = 0; i < 26; i++) {
        if (set1[i] != set2[i])
            return false;
    }

    // Sort and compare frequencies
    qsort(freq1, 26, sizeof(int), cmp);
    qsort(freq2, 26, sizeof(int), cmp);

    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i])
            return false;
    }

    return true;
}
