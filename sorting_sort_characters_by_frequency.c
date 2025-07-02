/*
Problem: Sort Characters by Frequency

Description:
Given a string, sort the characters in descending order based on frequency.

Approach:
1. Count character frequencies.
2. Use array of structs to map characters and their frequency.
3. Sort using qsort based on frequency descending.
4. Build output string.

Time: O(n log k) — k is number of unique characters
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

int compare(const void* a, const void* b) {
    CharFreq* c1 = (CharFreq*)a;
    CharFreq* c2 = (CharFreq*)b;
    return c2->freq - c1->freq;
}

char* frequencySort(char* s) {
    int freq[128] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[(int)s[i]]++;
    }

    CharFreq list[128];
    int count = 0;
    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            list[count].ch = (char)i;
            list[count].freq = freq[i];
            count++;
        }
    }

    qsort(list, count, sizeof(CharFreq), compare);

    char* result = malloc(len + 1);
    int idx = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < list[i].freq; j++) {
            result[idx++] = list[i].ch;
        }
    }
    result[idx] = '\0';
    return result;
}

// Test
int main() {
    char input[] = "tree";
    char* output = frequencySort(input);
    printf("Sorted by frequency: %s\n", output);
    free(output);
    return 0;
}

/*
========= OUTPUT =========
Sorted by frequency: eert
==========================
*/
