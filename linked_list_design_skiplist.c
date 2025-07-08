/*
Problem:
Design a Skiplist with the following operations:

- `bool search(int target)`
- `void add(int num)`
- `bool erase(int num)`

Constraints:
- 0 <= num, target <= 20000
- At most 5 * 10⁴ calls

-----------------------------------------

Approach:
- Each node can have multiple forward pointers (levels).
- Use randomization for balancing levels.
- Skiplist supports average O(log n) operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LEVEL 16
#define PROBABILITY 0.5

typedef struct SkiplistNode {
    int val;
    struct SkiplistNode** forward;
} SkiplistNode;

typedef struct {
    SkiplistNode* head;
    int level;
} Skiplist;

SkiplistNode* createNode(int val, int level) {
    SkiplistNode* node = malloc(sizeof(SkiplistNode));
    node->val = val;
    node->forward = malloc(sizeof(SkiplistNode*) * (level + 1));
    for (int i = 0; i <= level; i++) node->forward[i] = NULL;
    return node;
}

int randomLevel() {
    int lvl = 0;
    while ((rand() / (double)RAND_MAX) < PROBABILITY && lvl < MAX_LEVEL)
        lvl++;
    return lvl;
}

Skiplist* skiplistCreate() {
    srand(time(NULL));
    Skiplist* list = malloc(sizeof(Skiplist));
    list->level = 0;
    list->head = createNode(-1, MAX_LEVEL);
    return list;
}

bool skiplistSearch(Skiplist* list, int target) {
    SkiplistNode* curr = list->head;
    for (int i = list->level; i >= 0; i--) {
        while (curr->forward[i] && curr->forward[i]->val < target)
            curr = curr->forward[i];
    }
    curr = curr->forward[0];
    return curr && curr->val == target;
}

void skiplistAdd(Skiplist* list, int num) {
    SkiplistNode* update[MAX_LEVEL + 1];
    SkiplistNode* curr = list->head;

    for (int i = list->level; i >= 0; i--) {
        while (curr->forward[i] && curr->forward[i]->val < num)
            curr = curr->forward[i];
        update[i] = curr;
    }

    curr = curr->forward[0];

    int lvl = randomLevel();
    if (lvl > list->level) {
        for (int i = list->level + 1; i <= lvl; i++)
            update[i] = list->head;
        list->level = lvl;
    }

    SkiplistNode* newNode = createNode(num, lvl);
    for (int i = 0; i <= lvl; i++) {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }
}

bool skiplistErase(Skiplist* list, int num) {
    SkiplistNode* update[MAX_LEVEL + 1];
    SkiplistNode* curr = list->head;

    for (int i = list->level; i >= 0; i--) {
        while (curr->forward[i] && curr->forward[i]->val < num)
            curr = curr->forward[i];
        update[i] = curr;
    }

    curr = curr->forward[0];

    if (!curr || curr->val != num)
        return false;

    for (int i = 0; i <= list->level; i++) {
        if (update[i]->forward[i] != curr) break;
        update[i]->forward[i] = curr->forward[i];
    }

    free(curr->forward);
    free(curr);

    while (list->level > 0 && list->head->forward[list->level] == NULL)
        list->level--;

    return true;
}

void skiplistFree(Skiplist* list) {
    SkiplistNode* curr = list->head;
    while (curr) {
        SkiplistNode* next = curr->forward[0];
        free(curr->forward);
        free(curr);
        curr = next;
    }
    free(list);
}

// Demo
int main() {
    Skiplist* list = skiplistCreate();
    skiplistAdd(list, 1);
    skiplistAdd(list, 2);
    skiplistAdd(list, 3);
    printf("Search 0: %s\n", skiplistSearch(list, 0) ? "true" : "false");
    skiplistAdd(list, 4);
    printf("Search 1: %s\n", skiplistSearch(list, 1) ? "true" : "false");
    printf("Erase 0: %s\n", skiplistErase(list, 0) ? "true" : "false");
    printf("Erase 1: %s\n", skiplistErase(list, 1) ? "true" : "false");
    printf("Search 1: %s\n", skiplistSearch(list, 1) ? "true" : "false");

    skiplistFree(list);
    return 0;
}
