/*
Problem: Longest Word in Dictionary (LeetCode 720)
URL: https://leetcode.com/problems/longest-word-in-dictionary/

Given a list of lowercase alphabet strings `words`, return the longest word that can be built by one character at a time,
where all its prefixes are also in the dictionary. If multiple answers exist, choose the lexicographically smallest.

Approach:
1. Sort words by descending length, lexicographically ascending.
2. For each word, check if all prefixes exist in the list.
3. Return the first valid candidate; otherwise, return empty string.

Time Complexity: O(N^2 * L), where N = number of words (≤1000), L = max word length (≤30).
Space Complexity: O(1) extra.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static int cmp(const void* a, const void* b) {
    const char* sa = *(const char**)a;
    const char* sb = *(const char**)b;
    int la = strlen(sa), lb = strlen(sb);
    if (la != lb) return lb - la;
    return strcmp(sa, sb);
}

static bool allPrefixesExist(const char* word, char** dict, int dictSize) {
    char prefix[31];
    int len = strlen(word);
    for (int i = 1; i <= len; i++) {
        strncpy(prefix, word, i);
        prefix[i] = '\0';
        bool found = false;
        for (int j = 0; j < dictSize; j++) {
            if (strcmp(dict[j], prefix) == 0) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

char* longestWord(char** words, int wordsSize) {
    qsort(words, wordsSize, sizeof(char*), cmp);

    for (int i = 0; i < wordsSize; i++) {
        if (allPrefixesExist(words[i], words, wordsSize)) {
            return words[i];
        }
    }
    return "";
}

// Helper to print array of strings
void printList(char** arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("\"%s\"%s", arr[i], (i+1 < size) ? ", " : "");
    }
    printf("]");
}

int main(void) {
    char* words1[] = {"w","wo","wor","worl","world"};
    int n1 = sizeof(words1)/sizeof(words1[0]);
    printf("Input: "); printList(words1, n1);
    printf(" → Output: \"%s\" (expected \"world\")\n", longestWord(words1, n1));

    char* words2[] = {"a","banana","app","appl","ap","apply","apple"};
    int n2 = sizeof(words2)/sizeof(words2[0]);
    printf("Input: "); printList(words2, n2);
    printf(" → Output: \"%s\" (expected \"apple\")\n", longestWord(words2, n2));

    return 0;
}
