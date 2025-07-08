/*
Problem:
Design a HashSet without using any built-in hash table libraries.

Implement:
- myHashSetCreate()
- add(key)
- remove(key)
- contains(key): returns true if key is in the set

Constraints:
- 0 <= key <= 10^6
- Up to 10^4 calls

Example:
Input:
["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]
[[],[1],[2],[1],[3],[2],[2],[2],[2]]

Output:
[null,null,null,true,false,null,true,null,false]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000001  // range: 0 to 10^6

typedef struct {
    bool* table;
} MyHashSet;

// Constructor
MyHashSet* myHashSetCreate() {
    MyHashSet* set = malloc(sizeof(MyHashSet));
    set->table = calloc(SIZE, sizeof(bool));
    return set;
}

// Add key
void myHashSetAdd(MyHashSet* obj, int key) {
    obj->table[key] = true;
}

// Remove key
void myHashSetRemove(MyHashSet* obj, int key) {
    obj->table[key] = false;
}

// Check key
bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->table[key];
}

// Free memory
void myHashSetFree(MyHashSet* obj) {
    free(obj->table);
    free(obj);
}

// Demo
int main() {
    MyHashSet* set = myHashSetCreate();

    myHashSetAdd(set, 1);
    myHashSetAdd(set, 2);
    printf("Contains 1: %s\n", myHashSetContains(set, 1) ? "true" : "false");  // true
    printf("Contains 3: %s\n", myHashSetContains(set, 3) ? "true" : "false");  // false

    myHashSetAdd(set, 2);
    printf("Contains 2: %s\n", myHashSetContains(set, 2) ? "true" : "false");  // true

    myHashSetRemove(set, 2);
    printf("Contains 2: %s\n", myHashSetContains(set, 2) ? "true" : "false");  // false

    myHashSetFree(set);
    return 0;
}
