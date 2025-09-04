/*
 * Problem: Unique Morse Code Words (LeetCode 804)
 *
 * Given an array of lowercase words, each can be transformed into Morse
 * code by replacing each character with its Morse representation and
 * concatenating. Return the number of unique such transformations.
 *
 * Example:
 * words = ["gin", "zen", "gig", "msg"]
 * Transformations -> {"--...-.", "--...--."}
 * Output: 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int uniqueMorseRepresentations(char** words, int wordsSize) {
    static const char* morse[26] = {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
        "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
        "..-","...-",".--","-..-","-.--","--.."
    };

    char** trans = malloc(wordsSize * sizeof(char*));
    int count = 0;

    for (int w = 0; w < wordsSize; w++) {
        char* word = words[w];
        size_t len = strlen(word);
        size_t bufSize = len * 4 + 1;
        char* code = malloc(bufSize);
        code[0] = '\0';

        for (char* p = word; *p; ++p) {
            strcat(code, morse[*p - 'a']);
        }

        bool exists = false;
        for (int i = 0; i < count; i++) {
            if (strcmp(trans[i], code) == 0) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            trans[count++] = code;
        } else {
            free(code);
        }
    }

    for (int i = 0; i < count; i++) free(trans[i]);
    free(trans);

    return count;
}

int main(void) {
    char* words1[] = {"gin","zen","gig","msg"};
    printf("Unique transformations: %d (expected: 2)\n",
           uniqueMorseRepresentations(words1, 4));

    char* words2[] = {"a","b","c","a"};
    printf("Unique transformations: %d (expected: 3)\n",
           uniqueMorseRepresentations(words2, 4));

    return 0;
}
