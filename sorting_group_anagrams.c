/*
Problem: Group Anagrams

Description:
Given an array of strings, group the anagrams together.
An Anagram is a word formed by rearranging the letters of another.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"]
Output:
[["bat"],
 ["nat","tan"],
 ["ate","eat","tea"]]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* key;
    char** group;
    int size;
    int capacity;
    struct Node* next;
} Node;

unsigned long hash(char* str) {
    unsigned long hash = 5381;
    while (*str)
        hash = ((hash << 5) + hash) + (*str++);
    return hash % 10007;
}

char* sortStr(const char* str) {
    int len = strlen(str);
    char* sorted = strdup(str);
    qsort(sorted, len, sizeof(char), (int (*)(const void*, const void*)) strcmp);
    return sorted;
}

void addToGroup(Node* node, char* word) {
    if (node->size >= node->capacity) {
        node->capacity *= 2;
        node->group = realloc(node->group, sizeof(char*) * node->capacity);
    }
    node->group[node->size++] = word;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Node* table[10007] = {0};
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * strsSize);
    char*** result = malloc(sizeof(char**) * strsSize);

    for (int i = 0; i < strsSize; i++) {
        char* sorted = sortStr(strs[i]);
        unsigned long idx = hash(sorted);
        Node* curr = table[idx];

        while (curr) {
            if (strcmp(curr->key, sorted) == 0) break;
            curr = curr->next;
        }

        if (!curr) {
            curr = malloc(sizeof(Node));
            curr->key = sorted;
            curr->group = malloc(sizeof(char*) * 10);
            curr->group[0] = strs[i];
            curr->size = 1;
            curr->capacity = 10;
            curr->next = table[idx];
            table[idx] = curr;
        } else {
            addToGroup(curr, strs[i]);
            free(sorted); // already exists in key
        }
    }

    for (int i = 0; i < 10007; i++) {
        Node* curr = table[i];
        while (curr) {
            result[*returnSize] = curr->group;
            (*returnColumnSizes)[*returnSize] = curr->size;
            (*returnSize)++;
            Node* temp = curr;
            curr = curr->next;
            free(temp->key);
            free(temp);
        }
    }

    return result;
}

// Test function
int main() {
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int size = sizeof(strs) / sizeof(strs[0]);
    int returnSize;
    int* returnColumnSizes;

    char*** grouped = groupAnagrams(strs, size, &returnSize, &returnColumnSizes);

    printf("Grouped Anagrams:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("\"%s\" ", grouped[i][j]);
        }
        printf("]\n");
        free(grouped[i]);
    }

    free(grouped);
    free(returnColumnSizes);
    return 0;
}

/*
========= OUTPUT =========
Grouped Anagrams:
[ "eat" "tea" "ate" ]
[ "tan" "nat" ]
[ "bat" ]
==========================
*/
