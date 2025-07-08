/*
Problem:
Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.

Example:
Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]

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

// Main logic to remove duplicates (retain one copy)
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;

    while (current && current->next) {
        if (current->val == current->next->val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
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
    // Input: [1,1,2,3,3]
    struct ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    struct ListNode* result = deleteDuplicates(head);
    printf("Output: ");
    printList(result);  // Expected: 1 -> 2 -> 3

    return 0;
}
