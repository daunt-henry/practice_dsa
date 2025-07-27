/*
Text Justification

Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully justified.

Example:
Input:
  words = ["This", "is", "an", "example", "of", "text", "justification."]
  maxWidth = 16

Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    int count = 0;
    int i = 0;

    while (i < wordsSize) {
        int len = strlen(words[i]);
        int j = i + 1;
        int total = len;

        while (j < wordsSize && total + strlen(words[j]) + (j - i) <= maxWidth) {
            total += strlen(words[j]);
            j++;
        }

        int spaces = maxWidth - total;
        int slots = j - i - 1;
        char* line = (char*)malloc(maxWidth + 1);

        if (j == wordsSize || slots == 0) {
            int pos = 0;
            for (int k = i; k < j; k++) {
                int wlen = strlen(words[k]);
                memcpy(line + pos, words[k], wlen);
                pos += wlen;
                if (pos < maxWidth) line[pos++] = ' ';
            }
            while (pos < maxWidth) line[pos++] = ' ';
            line[pos] = '\0';
        } else {
            int space_each = spaces / slots;
            int extra = spaces % slots;
            int pos = 0;
            for (int k = i; k < j; k++) {
                int wlen = strlen(words[k]);
                memcpy(line + pos, words[k], wlen);
                pos += wlen;
                if (k < j - 1) {
                    int sp = space_each + (extra-- > 0 ? 1 : 0);
                    for (int s = 0; s < sp; s++) line[pos++] = ' ';
                }
            }
            line[pos] = '\0';
        }

        result[count++] = line;
        i = j;
    }

    *returnSize = count;
    return result;
}

int main() {
    char* words[] = {"This", "is", "an", "example", "of", "text", "justification."};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    int maxWidth = 16;
    int returnSize;
    
    char** result = fullJustify(words, wordsSize, maxWidth, &returnSize);

    printf("Output:\n[\n");
    for (int i = 0; i < returnSize; i++) {
        printf("  \"%s\"\n", result[i]);
        free(result[i]);
    }
    printf("]\n");
    free(result);
    return 0;
}
