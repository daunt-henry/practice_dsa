/*
Problem: Count Words Obtained After Adding a Letter

You are given two arrays of strings: startWords and targetWords.
A target word can be formed by adding one letter to a word from startWords and rearranging the letters.

Return the number of target words that can be formed in this way.

Approach:
- For each start word, sort its characters and store in a hash set.
- For each target word, sort the characters and try removing one character at each position.
  If the resulting string exists in the hash set, count it as valid.

Time Complexity:
- Sorting each word takes O(n log n), and each check is O(n^2 log n).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_SIZE 100003

typedef struct Node {
    char *word;
    struct Node *next;
} Node;

Node* hashTable[HASH_SIZE];

unsigned int hash(char *s) {
    unsigned int h = 0;
    while (*s) h = (h * 131 + *s++) % HASH_SIZE;
    return h;
}

void insert(char *s) {
    unsigned int h = hash(s);
    Node *node = malloc(sizeof(Node));
    node->word = strdup(s);
    node->next = hashTable[h];
    hashTable[h] = node;
}

bool search(char *s) {
    unsigned int h = hash(s);
    Node *cur = hashTable[h];
    while (cur) {
        if (strcmp(cur->word, s) == 0) return true;
        cur = cur->next;
    }
    return false;
}

int wordCount(char **startWords, int startWordsSize, char **targetWords, int targetWordsSize) {
    memset(hashTable, 0, sizeof(hashTable));
    char buffer[27];

    for (int i = 0; i < startWordsSize; i++) {
        strcpy(buffer, startWords[i]);
        int len = strlen(buffer);
        qsort(buffer, len, sizeof(char), (int(*)(const void*, const void*))strcmp);
        insert(buffer);
    }

    int count = 0;
    for (int i = 0; i < targetWordsSize; i++) {
        int len = strlen(targetWords[i]);
        strcpy(buffer, targetWords[i]);
        qsort(buffer, len, sizeof(char), (int(*)(const void*, const void*))strcmp);
        
        for (int j = 0; j < len; j++) {
            char temp[27];
            int k = 0;
            for (int m = 0; m < len; m++) {
                if (m != j) temp[k++] = buffer[m];
            }
            temp[k] = '\0';
            if (search(temp)) {
                count++;
                break;
            }
        }
    }

    return count;
}

/*
Example:
Input:
startWords = ["ant","act","tack"]
targetWords = ["tack","act","acti"]
Output: 2
*/
