/*
Problem:
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return NULL.

Use constant extra space.

Example:
Input: head = [3,2,0,-4], pos = 1 (tail connects to node index 1)
Output: Reference to node with value 2

Input: head = [1,2], pos = 0
Output: Reference to node with value 1

Input: head = [1], pos = -1
Output: NULL

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Utility to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to detect cycle and return the starting node
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected
            struct ListNode* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }

    return NULL;
}

// Driver code
int main() {
    // Create nodes: [3,2,0,-4]
    struct ListNode* n1 = createNode(3);
    struct ListNode* n2 = createNode(2);
    struct ListNode* n3 = createNode(0);
    struct ListNode* n4 = createNode(-4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // cycle here at node with value 2

    struct ListNode* start = detectCycle(n1);

    if (start)
        printf("Cycle starts at node with value: %d\n", start->val);  // Expected: 2
    else
        printf("No cycle detected\n");

    return 0;
}
