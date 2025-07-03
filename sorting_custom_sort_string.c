/*
Problem: Custom Sort String (LeetCode 791)

You are given two strings: 'order' and 's'.
Sort 's' so that characters appear in the same relative order as 'order'.
Characters not in 'order' can appear in any position afterward.

Approach:
- Count the frequency of each character in 's'
- Append characters in 'order' first, then others
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* customSortString(char* order, char* s) {
    int freq[26] = {0};
    for (int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
    }

    char* result = (char*)malloc(strlen(s) + 1);
    int idx = 0;

    for (int i = 0; order[i]; i++) {
        char ch = order[i];
        while (freq[ch - 'a'] > 0) {
            result[idx++] = ch;
            freq[ch - 'a']--;
        }
    }

    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            result[idx++] = i + 'a';
            freq[i]--;
        }
    }

    result[idx] = '\0';
    return result;
}

// Test case
int main() {
    char order[] = "cba";
    char s[] = "abcd";

    char* output = customSortString(order, s);
    printf("Output: %s\n", output);  // Expected: cbad

    free(output);
    return 0;
}

/*
========= OUTPUT =========
Output: cbad
==========================
*/
