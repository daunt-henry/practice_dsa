/*
Problem: Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into 
a space-separated sequence of one or more dictionary words.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool wordBreak(char * s, char ** wordDict, int wordDictSize) {
    int len = strlen(s);
    bool *dp = (bool *)calloc(len + 1, sizeof(bool));
    dp[0] = true;

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]) {
                for (int k = 0; k < wordDictSize; k++) {
                    int wlen = strlen(wordDict[k]);
                    if (wlen == i - j && strncmp(s + j, wordDict[k], wlen) == 0) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[i]) break;
        }
    }

    bool result = dp[len];
    free(dp);
    return result;
}

int main() {
    char *dict1[] = {"leet", "code"};
    printf("Can break 'leetcode'? %s\n", wordBreak("leetcode", dict1, 2) ? "true" : "false"); // true

    char *dict2[] = {"cats", "dog", "sand", "and", "cat"};
    printf("Can break 'catsandog'? %s\n", wordBreak("catsandog", dict2, 5) ? "true" : "false"); // false

    char *dict3[] = {"apple", "pen"};
    printf("Can break 'applepenapple'? %s\n", wordBreak("applepenapple", dict3, 2) ? "true" : "false"); // true

    return 0;
}
