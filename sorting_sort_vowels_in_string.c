// Question:
// Given a string s, reorder the vowels in s so that they are sorted in increasing order,
// while all other characters remain in their original positions.
// Return the resulting string.
//
// Example:
// Input: s = "lEetcOde"
// Output: "lEOtcede"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int cmpChar(const void* a, const void* b) {
    return (*(char*)a) - (*(char*)b);
}

char* sortVowels(char* s) {
    int len = strlen(s);
    char* vowels = (char*)malloc(len + 1);
    int vcount = 0;

    // Collect vowels
    for (int i = 0; i < len; i++) {
        if (isVowel(s[i])) {
            vowels[vcount++] = s[i];
        }
    }

    // Sort collected vowels
    qsort(vowels, vcount, sizeof(char), cmpChar);

    // Place sorted vowels back
    int idx = 0;
    for (int i = 0; i < len; i++) {
        if (isVowel(s[i])) {
            s[i] = vowels[idx++];
        }
    }

    free(vowels);
    return s;
}

int main() {
    char input[] = "lEetcOde";
    char* result = sortVowels(input);
    printf("Output: %s\n", result);  // Expected Output: "lEOtcede"
    return 0;
}
