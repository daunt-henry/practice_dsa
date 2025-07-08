/*
Problem:
Given the head of a singly linked list and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, and return the reversed list.

Example:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

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

// Main function to reverse a portion of the list
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    struct ListNode* curr = prev->next;
    struct ListNode* next = NULL;

    for (int i = 0; i < right - left; i++) {
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return dummy.next;
}

// Print the list
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
    // Input: [1,2,3,4,5], left = 2, right = 4
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int left = 2, right = 4;
    struct ListNode* result = reverseBetween(head, left, right);
    printf("Output: ");
    printList(result);  // Expected: 1 -> 4 -> 3 -> 2 -> 5

    return 0;
}
