/*
Problem:
Design a data structure that follows the Least Recently Used (LRU) cache policy.

Implement the LRUCache class with:
- LRUCache(int capacity): Initializes the cache with positive size.
- int get(int key): Return the value of the key if present; otherwise, -1.
- void put(int key, int value): Update or insert the value. If full, evict the least recently used.

Example:
Input:
["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
Output:
[null,null,null,1,null,-1,null,-1,3,4]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10009  // A prime number for better hashing

// Doubly Linked List Node
typedef struct Node {
    int key, value;
    struct Node *prev, *next;
} Node;

// LRU Cache structure
typedef struct {
    int capacity, size;
    Node *head, *tail;
    Node **hashmap;
} LRUCache;

// Create a new node
Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = node->next = NULL;
    return node;
}

// Hash function
int hash(int key) {
    return key % HASH_SIZE;
}

// Move node to front
void moveToFront(LRUCache* obj, Node* node) {
    if (obj->head == node) return;

    // Remove node
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (obj->tail == node) obj->tail = node->prev;

    // Insert at front
    node->next = obj->head;
    node->prev = NULL;
    if (obj->head) obj->head->prev = node;
    obj->head = node;
    if (!obj->tail) obj->tail = node;
}

// Remove LRU node from tail
void removeTail(LRUCache* obj) {
    if (!obj->tail) return;

    Node* node = obj->tail;
    if (node->prev) node->prev->next = NULL;
    obj->tail = node->prev;
    if (!obj->tail) obj->head = NULL;

    // Remove from hashmap
    int h = hash(node->key);
    while (obj->hashmap[h] && obj->hashmap[h]->key != node->key) {
        h = (h + 1) % HASH_SIZE;
    }
    obj->hashmap[h] = NULL;

    free(node);
    obj->size--;
}

// Get value
int lRUCacheGet(LRUCache* obj, int key) {
    int h = hash(key);
    while (obj->hashmap[h] && obj->hashmap[h]->key != key) {
        h = (h + 1) % HASH_SIZE;
    }

    if (!obj->hashmap[h]) return -1;

    moveToFront(obj, obj->hashmap[h]);
    return obj->hashmap[h]->value;
}

// Put key-value
void lRUCachePut(LRUCache* obj, int key, int value) {
    int h = hash(key);
    while (obj->hashmap[h] && obj->hashmap[h]->key != key) {
        h = (h + 1) % HASH_SIZE;
    }

    if (obj->hashmap[h]) {
        obj->hashmap[h]->value = value;
        moveToFront(obj, obj->hashmap[h]);
        return;
    }

    if (obj->size == obj->capacity) {
        removeTail(obj);
    }

    Node* node = createNode(key, value);
    node->next = obj->head;
    if (obj->head) obj->head->prev = node;
    obj->head = node;
    if (!obj->tail) obj->tail = node;

    while (obj->hashmap[h]) h = (h + 1) % HASH_SIZE;
    obj->hashmap[h] = node;
    obj->size++;
}

// Constructor
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->head = obj->tail = NULL;
    obj->hashmap = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    return obj;
}

// Destructor
void lRUCacheFree(LRUCache* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj->hashmap);
    free(obj);
}

// Driver
int main() {
    LRUCache* lru = lRUCacheCreate(2);

    lRUCachePut(lru, 1, 1);
    lRUCachePut(lru, 2, 2);
    printf("Get 1: %d\n", lRUCacheGet(lru, 1)); // 1
    lRUCachePut(lru, 3, 3);                     // Evicts key 2
    printf("Get 2: %d\n", lRUCacheGet(lru, 2)); // -1
    lRUCachePut(lru, 4, 4);                     // Evicts key 1
    printf("Get 1: %d\n", lRUCacheGet(lru, 1)); // -1
    printf("Get 3: %d\n", lRUCacheGet(lru, 3)); // 3
    printf("Get 4: %d\n", lRUCacheGet(lru, 4)); // 4

    lRUCacheFree(lru);
    return 0;
}
