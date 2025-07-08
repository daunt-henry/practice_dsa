/*
Problem:
Given the head of a linked list, rotate the list to the right by k places.

Example:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Explanation: After rotating the list 2 times to the right, the new list starts from node 4.

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

// Core function to rotate list
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Find length and make the list circular
    int len = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    tail->next = head; // make circular

    // Find new tail: len - k % len - 1, new head: len - k % len
    k = k % len;
    for (int i = 0; i < len - k - 1; i++) {
        head = head->next;
    }

    struct ListNode* newHead = head->next;
    head->next = NULL;

    return newHead;
}

// Print the linked list
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
    // Input: [1,2,3,4,5], k = 2
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int k = 2;
    struct ListNode* rotated = rotateRight(head, k);
    printf("Output: ");
    printList(rotated);  // Expected: 4 -> 5 -> 1 -> 2 -> 3

    return 0;
}
