/*
Problem: Insertion Sort List

Description:
Sort a linked list using insertion sort.
The algorithm iterates, removing one element from the input data and inserting it in-place into the sorted part.

Example:
Input: 4 -> 2 -> 1 -> 3
Output: 1 -> 2 -> 3 -> 4
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

// Insertion sort for linked list
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = -5000;
    dummy->next = NULL;

    while (head) {
        struct ListNode* curr = head;
        head = head->next;

        struct ListNode* prev = dummy;
        while (prev->next && prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;
    }

    struct ListNode* sortedHead = dummy->next;
    free(dummy);
    return sortedHead;
}

// Utility: Create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Utility: Print the linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Free memory
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function for testing
int main() {
    // Input: 4 -> 2 -> 1 -> 3
    struct ListNode* head = newNode(4);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(3);

    printf("Original List: ");
    printList(head);

    struct ListNode* sorted = insertionSortList(head);

    printf("Sorted List:   ");
    printList(sorted);

    freeList(sorted);
    return 0;
}

/*
========= OUTPUT =========
Original List: 4 -> 2 -> 1 -> 3
Sorted List:   1 -> 2 -> 3 -> 4
==========================
*/
