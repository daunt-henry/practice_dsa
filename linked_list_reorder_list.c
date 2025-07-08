/*
Problem:
You are given the head of a singly linked list. Reorder the list as:
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...

Do this **in-place** without modifying the node values.

Example:
Input:  head = [1,2,3,4]
Output: [1,4,2,3]

Input:  head = [1,2,3,4,5]
Output: [1,5,2,4,3]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Utility: Create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Step 1: Find the middle of the list
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Step 2: Reverse the second half of the list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Step 3: Merge two halves alternately
void mergeLists(struct ListNode* l1, struct ListNode* l2) {
    while (l1 && l2) {
        struct ListNode* l1_next = l1->next;
        struct ListNode* l2_next = l2->next;

        l1->next = l2;

        if (!l1_next) break;

        l2->next = l1_next;
        l1 = l1_next;
        l2 = l2_next;
    }
}

// Main function to reorder the list
void reorderList(struct ListNode* head) {
    if (!head || !head->next) return;

    struct ListNode* mid = findMiddle(head);
    struct ListNode* second = reverseList(mid->next);
    mid->next = NULL;
    mergeLists(head, second);
}

// Utility: Print list
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
    // Input: [1,2,3,4,5]
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    reorderList(head);

    printf("Reordered list: ");
    printList(head);  // Expected: 1 -> 5 -> 2 -> 4 -> 3

    return 0;
}
