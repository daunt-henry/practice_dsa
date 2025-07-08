/*
Problem:
Given the head of a linked list and an integer val, remove all the nodes of the linked list that have Node.val == val,
and return the new head.

Example:
Input: head = [1,2,6,3,4,5,6], val = 6  
Output: [1,2,3,4,5]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Utility: create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to remove elements with target value
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* curr = &dummy;

    while (curr->next) {
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}

// Utility: print linked list
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
    // Input: [1,2,6,3,4,5,6]
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    int val = 6;

    struct ListNode* newHead = removeElements(head, val);

    printf("Updated list after removing %d: ", val);
    printList(newHead);  // Expected: 1 -> 2 -> 3 -> 4 -> 5

    return 0;
}
