/*
Problem: Top K Frequent Words

Given an array of strings, return the k most frequent words.
Sort by frequency (descending), then alphabetically (ascending) if tied.

Approach:
- Use struct WordFreq to store frequency
- Sort with custom comparator
- Output top k

Note: This version uses a simplified array-based solution instead of a heap
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 101

typedef struct {
    char word[MAX_LEN];
    int freq;
} WordFreq;

int compare(const void* a, const void* b) {
    WordFreq* wa = (WordFreq*)a;
    WordFreq* wb = (WordFreq*)b;

    if (wa->freq != wb->freq)
        return wb->freq - wa->freq;  // higher frequency first
    return strcmp(wa->word, wb->word);  // lexicographically smaller first
}

// Helper to find index of word in frequency array
int find(WordFreq* arr, int size, const char* word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].word, word) == 0)
            return i;
    }
    return -1;
}

// Test version
int main() {
    char* words[] = {"i", "love", "leetcode", "i", "love", "coding"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    int k = 2;

    WordFreq freqList[MAX_WORDS];
    int count = 0;

    // Count frequency
    for (int i = 0; i < wordsSize; i++) {
        int idx = find(freqList, count, words[i]);
        if (idx != -1) {
            freqList[idx].freq++;
        } else {
            strcpy(freqList[count].word, words[i]);
            freqList[count].freq = 1;
            count++;
        }
    }

    // Sort
    qsort(freqList, count, sizeof(WordFreq), compare);

    // Output top k
    printf("Top %d frequent words:\n", k);
    for (int i = 0; i < k && i < count; i++) {
        printf("%s\n", freqList[i].word);
    }

    return 0;
}

/*
========= OUTPUT =========
Top 2 frequent words:
i
love
==========================
*/
