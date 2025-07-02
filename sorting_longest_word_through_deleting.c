/*
Problem: Longest Word in Dictionary through Deleting

Given a string s and a dictionary of strings,
return the longest string in the dictionary that is a subsequence of s.
If multiple answers exist, return the one that's lexicographically smallest.

Approach:
- For each word in dictionary, check if it's a subsequence of s.
- Keep track of the best candidate based on length and lex order.

Time: O(n * m), where n = dictionary size, m = s length
Space: O(1)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char* word, char* s) {
    int i = 0, j = 0;
    while (word[i] && s[j]) {
        if (word[i] == s[j]) i++;
        j++;
    }
    return word[i] == '\0';
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    char* best = "";
    for (int i = 0; i < dictionarySize; i++) {
        char* word = dictionary[i];
        if (isSubsequence(word, s)) {
            if (strlen(word) > strlen(best) ||
                (strlen(word) == strlen(best) && strcmp(word, best) < 0)) {
                best = word;
            }
        }
    }
    return best;
}

// Test
int main() {
    char* s = "abpcplea";
    char* dictionary[] = {"ale", "apple", "monkey", "plea"};
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);

    char* result = findLongestWord(s, dictionary, dictSize);
    printf("Longest word through deleting: %s\n", result);

    return 0;
}

/*
========= OUTPUT =========
Longest word through deleting: apple
==========================
*/
