/*
Minimum Deletions to Make Character Frequencies Unique

Problem:
Given a string, return the minimum number of deletions needed so that no two characters have the same frequency.

Approach:
- Count frequency of each character (a-z)
- Sort the frequencies in descending order
- For each frequency, ensure it's less than the one before it (if not, delete characters)
- Count the number of deletions needed

Time Complexity: O(n + k log k), where k = 26 (constant)
Space Complexity: O(1)

Example:
Input: "aaabbbcc"
Output: 2  (remove one 'a' and one 'b' to get "aabbbc")
*/

#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;  // Descending order
}

int minDeletions(char * s){
    int freq[26] = {0};

    for (int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
    }

    qsort(freq, 26, sizeof(int), cmp);

    int deletions = 0;
    for (int i = 1; i < 26; i++) {
        while (freq[i] && freq[i] >= freq[i - 1]) {
            freq[i]--;
            deletions++;
        }
    }

    return deletions;
}
