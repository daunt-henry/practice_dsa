/*
Problem:
Given a list of strings, group them by special equivalence.

Definition:
Two strings are special equivalent if you can swap letters at even or odd positions to make them equal.

Approach:
- For each word, count frequency of even-indexed and odd-indexed characters separately.
- Use this as a signature to group words.

Time: O(n * k), where n = number of words, k = word length
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSameGroup(char* s1, char* s2) {
    int count1[52] = {0};
    int count2[52] = {0};

    for (int i = 0; s1[i]; i++) {
        int idx = (i % 2) * 26 + (s1[i] - 'a');
        count1[idx]++;
    }
    for (int i = 0; s2[i]; i++) {
        int idx = (i % 2) * 26 + (s2[i] - 'a');
        count2[idx]++;
    }

    for (int i = 0; i < 52; i++) {
        if (count1[i] != count2[i])
            return false;
    }
    return true;
}

int numSpecialEquivGroups(char** words, int wordsSize) {
    bool* visited = calloc(wordsSize, sizeof(bool));
    int groups = 0;

    for (int i = 0; i < wordsSize; i++) {
        if (visited[i]) continue;
        groups++;
        visited[i] = true;

        for (int j = i + 1; j < wordsSize; j++) {
            if (!visited[j] && isSameGroup(words[i], words[j])) {
                visited[j] = true;
            }
        }
    }

    free(visited);
    return groups;
}

// Test
int main() {
    char* words[] = {"a", "b", "c", "a", "c", "c"};
    int size = sizeof(words) / sizeof(words[0]);

    int result = numSpecialEquivGroups(words, size);
    printf("Output: %d\n", result);  // Expected: 3

    return 0;
}

/*
========= OUTPUT =========
Output: 3
==========================
*/
