/*
Problem:
Given a string and an integer k, reorder the string based on allowed operations:

Rules:
- If k == 1: you can only rotate by moving the first char to the end.
- If k > 1: you can reorder the string freely.

Approach:
- If k == 1: try all rotations and return the smallest.
- If k > 1: sort the string.

Time: O(n^2) for k == 1; O(n log n) for k > 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char* orderlyQueue(char* s, int k) {
    int len = strlen(s);
    if (k > 1) {
        char* result = strdup(s);
        qsort(result, len, sizeof(char), compareChars);
        return result;
    }

    char* best = strdup(s);
    for (int i = 1; i < len; i++) {
        char* rotated = malloc(len + 1);
        strncpy(rotated, s + i, len - i);
        strncpy(rotated + len - i, s, i);
        rotated[len] = '\0';
        if (strcmp(rotated, best) < 0) {
            strcpy(best, rotated);
        }
        free(rotated);
    }
    return best;
}

// Test
int main() {
    char input[] = "cba";
    int k = 1;

    char* result = orderlyQueue(input, k);
    printf("Output: %s\n", result);  // Expected: "acb"

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Output: acb
==========================
*/
