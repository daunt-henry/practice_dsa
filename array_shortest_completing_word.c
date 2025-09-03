/*
Problem: Shortest Completing Word (LeetCode 748)
URL: https://leetcode.com/problems/shortest-completing-word/

Define a completing word as one that contains all letters from licensePlate
(ignoring digits, spaces, case), and with at least the required frequency
if a letter appears multiple times. Return the shortest completing word
(from 'words'), choosing the earliest if there are ties.

Approach:
1. Count required letter frequencies from licensePlate.
2. For each word, count its letter frequencies.
3. Check if it meets or exceeds the required frequencies.
4. Track the shortest matching word.

Time Complexity: O(W * L), where W = number of words (~1000), L = word length (~15)
Space Complexity: O(1) (only using fixed-size frequency arrays)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int req[26] = {0};
    for (char* p = licensePlate; *p; ++p) {
        if (isalpha((unsigned char)*p)) {
            req[tolower((unsigned char)*p) - 'a']++;
        }
    }

    char* answer = NULL;
    int bestLen = INT_MAX;

    for (int i = 0; i < wordsSize; i++) {
        char* w = words[i];
        int freq[26] = {0};
        for (char* c = w; *c; ++c) {
            freq[*c - 'a']++;
        }
        bool ok = true;
        for (int j = 0; j < 26; j++) {
            if (freq[j] < req[j]) {
                ok = false;
                break;
            }
        }
        int len = strlen(w);
        if (ok && len < bestLen) {
            bestLen = len;
            answer = w;
        }
    }
    return answer;
}

int main(void) {
    char* words1[] = {"step","steps","stripe","stepple"};
    printf("Expected: steps, Got: %s\n",
           shortestCompletingWord("1s3 PSt", words1, 4));

    char* words2[] = {"looks","pest","stew","show"};
    printf("Expected: pest, Got: %s\n",
           shortestCompletingWord("1s3 456", words2, 4));

    return 0;
}
