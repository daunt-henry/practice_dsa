/*
Problem:
Given a linked list, swap every two adjacent nodes and return its head.

You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

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

// Main logic to swap pairs
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (head && head->next) {
        struct ListNode* first = head;
        struct ListNode* second = head->next;

        // Swap
        prev->next = second;
        first->next = second->next;
        second->next = first;

        // Move pointers
        prev = first;
        head = first->next;
    }

    return dummy.next;
}

// Utility to print the list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Driver code
int main() {
    // Create list: [1,2,3,4]
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    struct ListNode* result = swapPairs(head);
    printf("Output: ");
    printList(result);  // Expected: 2 -> 1 -> 4 -> 3

    return 0;
}
