/*
Split Array into Consecutive Subsequences (LeetCode 659)

Given a sorted integer array `nums`, determine whether it can be split into
one or more subsequences where each subsequence:
  - Is strictly increasing consecutive numbers.
  - Has a length of at least 3.

Approach: Greedy using two hash maps (`frequency` and `need`)
- If number `x` is needed by an existing subsequence → extend it.
- Else try forming a new subsequence with `x, x+1, x+2`.
- If neither is possible → return false.

Time: O(n), Space: O(n)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define MAP_SIZE 1024
int hashKey(int key) {
    return (key ^ (key >> 16)) & (MAP_SIZE - 1);
}
void mapPut(Node** map, int key, int delta) {
    int h = hashKey(key);
    Node* cur = map[h];
    while (cur) {
        if (cur->key == key) {
            cur->value += delta;
            return;
        }
        cur = cur->next;
    }
    Node* node = calloc(1, sizeof(Node));
    node->key = key;
    node->value = delta;
    node->next = map[h];
    map[h] = node;
}
int mapGet(Node** map, int key) {
    int h = hashKey(key);
    Node* cur = map[h];
    while (cur) {
        if (cur->key == key) return cur->value;
        cur = cur->next;
    }
    return 0;
}

bool isPossible(int* nums, int numsSize) {
    Node* freq[MAP_SIZE] = {0}, *need[MAP_SIZE] = {0};
    for (int i = 0; i < numsSize; i++) {
        mapPut(freq, nums[i], 1);
    }

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (mapGet(freq, x) == 0) continue;

        if (mapGet(need, x) > 0) {
            mapPut(need, x, -1);
            mapPut(need, x + 1, 1);
        } else if (mapGet(freq, x + 1) > 0 && mapGet(freq, x + 2) > 0) {
            mapPut(freq, x + 1, -1);
            mapPut(freq, x + 2, -1);
            mapPut(need, x + 3, 1);
        } else {
            return false;
        }
        mapPut(freq, x, -1);
    }
    return true;
}

int main(void) {
    int a1[] = {1, 2, 3, 3, 4, 5};
    printf("Expected true: %s\n",
           isPossible(a1, 6) ? "true" : "false");

    int a2[] = {1, 2, 3, 3, 4, 4, 5, 5};
    printf("Expected true: %s\n",
           isPossible(a2, 8) ? "true" : "false");

    int a3[] = {1, 2, 3, 4, 4, 5};
    printf("Expected false: %s\n",
           isPossible(a3, 6) ? "true" : "false");

    return 0;
}
