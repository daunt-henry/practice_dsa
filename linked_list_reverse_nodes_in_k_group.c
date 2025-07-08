/*
Problem:
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list.  
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as is.

Example:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Helper to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper to reverse a segment
struct ListNode* reverse(struct ListNode* head, struct ListNode* tail) {
    struct ListNode* prev = tail->next;
    struct ListNode* curr = head;
    while (prev != tail) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return tail;
}

// Main function
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* groupPrev = &dummy;

    while (1) {
        struct ListNode* kth = groupPrev;
        for (int i = 0; i < k && kth != NULL; i++) {
            kth = kth->next;
        }
        if (kth == NULL) break;

        struct ListNode* groupNext = kth->next;
        struct ListNode* prev = groupPrev->next;
        struct ListNode* curr = prev->next;

        for (int i = 1; i < k; i++) {
            prev->next = curr->next;
            curr->next = groupPrev->next;
            groupPrev->next = curr;
            curr = prev->next;
        }

        groupPrev = prev;
    }

    return dummy.next;
}

// Print list
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
    // Input: [1,2,3,4,5], k = 3
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int k = 3;
    struct ListNode* result = reverseKGroup(head, k);
    printf("Output: ");
    printList(result);  // Expected: 3 -> 2 -> 1 -> 4 -> 5

    return 0;
}
