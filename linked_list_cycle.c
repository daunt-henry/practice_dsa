/*
Problem:
Given the head of a linked list, determine if the linked list has a cycle in it.

A cycle occurs if a node's next pointer points to a previous node in the list.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example:
Input: head = [3,2,0,-4], pos = 1 (tail connects to node index 1)
Output: true

Input: head = [1,2], pos = 0
Output: true

Input: head = [1], pos = -1
Output: false

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to detect cycle using Floyd's Tortoise and Hare
bool hasCycle(struct ListNode *head) {
    if (!head || !head->next) return false;

    struct ListNode *slow = head, *fast = head->next;

    while (slow != fast) {
        if (!fast || !fast->next)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
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
    n4->next = n2; // cycle here

    if (hasCycle(n1))
        printf("Output: true\n");  // Expected: true
    else
        printf("Output: false\n");

    return 0;
}
