/*
 * Problem: Expressive Words (LeetCode 809)
 *
 * Count how many words are stretchy w.r.t string s:
 * - A group in s with length >=3 allows the word's group to be shorter.
 * - A group in s with length <3 requires exact matching.
 * - Character sequences must align.
 */

#include <stdio.h>
#include <stdbool.h>

static bool isStretchy(const char* s, const char* word) {
    int i = 0, j = 0;
    while (s[i] && word[j]) {
        if (s[i] != word[j]) return false;
        char c = s[i];
        int cntS = 0, cntW = 0;
        while (s[i] == c) { cntS++; i++; }
        while (word[j] == c) { cntW++; j++; }
        if (cntS < cntW) return false;
        if (cntS < 3 && cntS != cntW) return false;
    }
    return s[i] == '\0' && word[j] == '\0';
}

int expressiveWords(char* s, char** words, int wordsSize) {
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (isStretchy(s, words[i])) count++;
    }
    return count;
}

int main(void) {
    char* s = "heeellooo";
    char* words1[] = {"hello", "hi", "helo"};
    printf("Expected: 1, Got: %d\n", expressiveWords(s, words1, 3));

    char* s2 = "zzzzzyyyyy";
    char* words2[] = {"zzyy", "zy", "zyy"};
    printf("Expected: 3, Got: %d\n", expressiveWords(s2, words2, 3));

    return 0;
}
