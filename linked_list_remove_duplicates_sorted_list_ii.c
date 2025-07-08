/*
Problem:
Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Input: head = [1,1,1,2,3]
Output: [2,3]

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

// Main logic to remove all duplicates (not just duplicates in sequence)
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (head) {
        // Check for duplicate values
        if (head->next && head->val == head->next->val) {
            int dupVal = head->val;
            while (head && head->val == dupVal) {
                struct ListNode* temp = head;
                head = head->next;
                free(temp);
            }
            prev->next = head;
        } else {
            prev = head;
            head = head->next;
        }
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
    // Input: [1,2,3,3,4,4,5]
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);

    struct ListNode* result = deleteDuplicates(head);
    printf("Output: ");
    printList(result);  // Expected: 1 -> 2 -> 5

    return 0;
}
