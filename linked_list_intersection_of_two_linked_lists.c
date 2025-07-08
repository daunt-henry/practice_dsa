/*
Problem:
Given the heads of two singly linked lists `headA` and `headB`,
return the node at which the two lists intersect.
If the two linked lists have no intersection, return NULL.

Note: The intersection is defined by reference, not value.

Example:
Input: A = [4,1,8,4,5], B = [5,6,1,8,4,5], where the node with value 8 is shared.
Output: Reference to the node with value 8

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Utility: create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to find the intersection node
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a = headA, *b = headB;

    while (a != b) {
        a = (a != NULL) ? a->next : headB;
        b = (b != NULL) ? b->next : headA;
    }

    return a;  // May return NULL if no intersection
}

// Driver code
int main() {
    // Shared part: [8,4,5]
    struct ListNode* shared = createNode(8);
    shared->next = createNode(4);
    shared->next->next = createNode(5);

    // List A: [4,1,8,4,5]
    struct ListNode* headA = createNode(4);
    headA->next = createNode(1);
    headA->next->next = shared;

    // List B: [5,6,1,8,4,5]
    struct ListNode* headB = createNode(5);
    headB->next = createNode(6);
    headB->next->next = createNode(1);
    headB->next->next->next = shared;

    struct ListNode* intersect = getIntersectionNode(headA, headB);

    if (intersect)
        printf("Intersection at node with value: %d\n", intersect->val);  // Expected: 8
    else
        printf("No intersection.\n");

    return 0;
}
