/*
Problem:
You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.
In one operation, select any two adjacent words that are anagrams of each other and delete one of them.
Return the array after performing all operations. It can be shown that selecting the order of operations does not matter.

Approach:
- Use a helper function `isAnagram` to compare adjacent words.
- Traverse the array and keep only non-anagram neighbors.

Example:
Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* a, char* b) {
    int count[26] = {0};
    for (int i = 0; a[i]; i++) count[a[i] - 'a']++;
    for (int i = 0; b[i]; i++) count[b[i] - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    char** res = (char**)malloc(wordsSize * sizeof(char*));
    int idx = 0;
    res[idx++] = words[0];

    for (int i = 1; i < wordsSize; i++) {
        if (!isAnagram(words[i], words[i - 1])) {
            res[idx++] = words[i];
        }
    }

    *returnSize = idx;
    return res;
}

/*
Output:
Input: ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
*/
