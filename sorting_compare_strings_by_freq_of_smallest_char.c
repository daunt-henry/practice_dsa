/*
Problem:
For each query string, count how many words have a higher frequency
of their smallest character than that of the query.

Approach:
- For each string, compute frequency of its smallest character.
- For each query, count how many word frequencies are greater than the query frequency.

Time: O(q * w * l) where l is the average string length
Space: O(w)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFreq(const char* s) {
    char minChar = 'z' + 1;
    int freq = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] < minChar) {
            minChar = s[i];
            freq = 1;
        } else if (s[i] == minChar) {
            freq++;
        }
    }
    return freq;
}

int* numSmallerByFrequency(char** queries, int queriesSize, char** words, int wordsSize, int* returnSize) {
    int* wordFreq = malloc(sizeof(int) * wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        wordFreq[i] = getFreq(words[i]);
    }

    int* result = malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        int qFreq = getFreq(queries[i]);
        int count = 0;
        for (int j = 0; j < wordsSize; j++) {
            if (wordFreq[j] > qFreq) count++;
        }
        result[i] = count;
    }

    free(wordFreq);
    *returnSize = queriesSize;
    return result;
}

// Test
int main() {
    char* queries[] = {"cbd", "aaa"};
    char* words[] = {"zaa", "a", "aa", "aaa"};
    int qSize = sizeof(queries) / sizeof(queries[0]);
    int wSize = sizeof(words) / sizeof(words[0]);
    int returnSize;

    int* result = numSmallerByFrequency(queries, qSize, words, wSize, &returnSize);

    printf("Result:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Result:
3 0
==========================
*/
