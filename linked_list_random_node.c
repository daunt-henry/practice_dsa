/*
Problem:
Given a singly linked list, return a random node's value from the linked list.  
Each node must have the same probability of being chosen.

Implement the following:
- Solution(struct ListNode* head): Initializes the object with the head of the linked list.
- int getRandom(): Returns a random node’s value.

Note: Must use O(1) space and ensure uniform probability.

Example:
Input: head = [1,2,3]
Calls: getRandom() multiple times → outputs random values like 1,2,3 uniformly.

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Object definition
typedef struct {
    struct ListNode* head;
} Solution;

// Constructor
Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->head = head;
    srand(time(NULL));  // Seed for randomness
    return obj;
}

// Reservoir sampling: uniform random selection
int solutionGetRandom(Solution* obj) {
    int result = -1;
    int scope = 1;
    struct ListNode* curr = obj->head;

    while (curr) {
        if (rand() % scope == 0)
            result = curr->val;
        scope++;
        curr = curr->next;
    }

    return result;
}

// Destructor
void solutionFree(Solution* obj) {
    free(obj);
}

// Utility: create a node
struct ListNode* createNode(int val) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Utility: build sample list and test getRandom
int main() {
    // Create linked list: 1 -> 2 -> 3
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    Solution* obj = solutionCreate(head);

    printf("Random outputs:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", solutionGetRandom(obj));  // Expected: ~uniform values 1, 2, or 3
    }
    printf("\n");

    solutionFree(obj);
    return 0;
}
