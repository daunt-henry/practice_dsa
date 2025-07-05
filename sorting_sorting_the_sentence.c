/*
Problem: Sorting the Sentence

A sentence is given in shuffled order, with each word ending with a number indicating its correct position.
Rearrange the sentence based on the position digits and return the sorted sentence.

Example:
Input:  "is2 sentence4 This1 a3"
Output: "This is a sentence"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sortSentence(char* s) {
    char* words[10] = {0};  // Assuming max 9 words
    char* token = strtok(s, " ");
    
    while (token != NULL) {
        int len = strlen(token);
        int pos = token[len - 1] - '1';  // Convert char to index
        token[len - 1] = '\0';  // Remove the digit
        words[pos] = token;
        token = strtok(NULL, " ");
    }

    static char result[1000];
    result[0] = '\0';

    for (int i = 0; words[i]; ++i) {
        strcat(result, words[i]);
        if (words[i + 1]) strcat(result, " ");
    }

    return result;
}
