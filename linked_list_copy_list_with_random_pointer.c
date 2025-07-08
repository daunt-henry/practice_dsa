/*
Problem:
A linked list of length n is given where each node has an additional random pointer.
Each node contains a value, a next pointer to the next node, and a random pointer to any node in the list or NULL.

Return a deep copy of the list.

Example:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

// Utility to create a new node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    node->random = NULL;
    return node;
}

// Main logic to copy the list with random pointers
struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;

    struct Node* curr = head;

    // Step 1: Insert copy nodes between original nodes
    while (curr) {
        struct Node* copy = createNode(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    // Step 2: Assign random pointers to the copied nodes
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Separate the copied list from the original
    curr = head;
    struct Node* copyHead = head->next;
    while (curr) {
        struct Node* copy = curr->next;
        curr->next = copy->next;
        if (copy->next)
            copy->next = copy->next->next;
        curr = curr->next;
    }

    return copyHead;
}

// Helper to print the list (value and random index)
void printCopiedList(struct Node* head) {
    struct Node* curr = head;
    int index = 0;
    while (curr) {
        printf("Node %d: val = %d, random = %d\n", index, curr->val,
               curr->random ? curr->random->val : -1);
        curr = curr->next;
        index++;
    }
}

// Driver code (simplified for demonstration)
int main() {
    // Construct: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    struct Node* n1 = createNode(7);
    struct Node* n2 = createNode(13);
    struct Node* n3 = createNode(11);
    struct Node* n4 = createNode(10);
    struct Node* n5 = createNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    struct Node* copied = copyRandomList(n1);
    printf("Copied list:\n");
    printCopiedList(copied);  // Should show the same structure

    return 0;
}
