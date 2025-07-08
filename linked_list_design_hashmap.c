/*
Problem:
Design a HashMap without using any built-in hash table libraries.

Implement:
- myHashMapCreate()
- put(key, value)
- get(key): return value or -1 if not present
- remove(key)

Constraints:
- 0 <= key <= 10^6
- 0 <= value <= 10^6
- Up to 10^4 operations

Example:
Input:
["MyHashMap","put","put","get","get","put","get","remove","get"]
[[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]

Output:
[null,null,null,1,-1,null,1,null,-1]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* table[SIZE];
} MyHashMap;

int hash(int key) {
    return key % SIZE;
}

Node* createNode(int key, int value) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

MyHashMap* myHashMapCreate() {
    MyHashMap* map = malloc(sizeof(MyHashMap));
    for (int i = 0; i < SIZE; i++) map->table[i] = NULL;
    return map;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int idx = hash(key);
    Node* cur = obj->table[idx];
    while (cur) {
        if (cur->key == key) {
            cur->value = value;
            return;
        }
        cur = cur->next;
    }
    Node* node = createNode(key, value);
    node->next = obj->table[idx];
    obj->table[idx] = node;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int idx = hash(key);
    Node* cur = obj->table[idx];
    while (cur) {
        if (cur->key == key) return cur->value;
        cur = cur->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int idx = hash(key);
    Node* cur = obj->table[idx];
    Node* prev = NULL;
    while (cur) {
        if (cur->key == key) {
            if (prev) prev->next = cur->next;
            else obj->table[idx] = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    for (int i = 0; i < SIZE; i++) {
        Node* cur = obj->table[i];
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(obj);
}

// Demo
int main() {
    MyHashMap* map = myHashMapCreate();
    myHashMapPut(map, 1, 1);
    myHashMapPut(map, 2, 2);
    printf("get(1): %d\n", myHashMapGet(map, 1)); // 1
    printf("get(3): %d\n", myHashMapGet(map, 3)); // -1
    myHashMapPut(map, 2, 1);
    printf("get(2): %d\n", myHashMapGet(map, 2)); // 1
    myHashMapRemove(map, 2);
    printf("get(2): %d\n", myHashMapGet(map, 2)); // -1
    myHashMapFree(map);
    return 0;
}
