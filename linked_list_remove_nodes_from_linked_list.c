/*
Problem:
Given the head of a linked list, remove every node that has a node with a greater value to its right.
Return the head of the modified list.

Example:
Input: head = [5,2,13,3,8]
Output: [13,8]

Explanation:
- Node 5 → 13 is greater → remove 5
- Node 2 → 13 is greater → remove 2
- Node 13 → keep
- Node 3 → 8 is greater → remove 3
- Node 8 → keep

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Helper to reverse a list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Main logic
struct ListNode* removeNodes(struct ListNode* head) {
    head = reverseList(head);
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;

    int maxVal = -1;
    struct ListNode* curr = head;
    struct ListNode* tail = dummy;

    while (curr) {
        if (curr->val >= maxVal) {
            maxVal = curr->val;
            tail->next = curr;
            tail = curr;
        }
        curr = curr->next;
    }
    tail->next = NULL;
    struct ListNode* result = reverseList(dummy->next);
    free(dummy);
    return result;
}

// Helpers for demo
struct ListNode* createList(int* arr, int size) {
    struct ListNode* head = NULL, *tail = NULL;
    for (int i = 0; i < size; ++i) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Demo
int main() {
    int vals[] = {5, 2, 13, 3, 8};
    struct ListNode* head = createList(vals, 5);
    struct ListNode* result = removeNodes(head);
    printf("After removal: ");
    printList(result);  // Output: 13 8
    freeList(result);
    return 0;
}
