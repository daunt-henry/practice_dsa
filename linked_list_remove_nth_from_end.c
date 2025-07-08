/*
Problem:
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Explanation: The 2nd node from the end (which is 4) is removed.

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Utility function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Main logic to remove nth node from end
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *fast = &dummy, *slow = &dummy;

    // Move fast n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both fast and slow
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete);

    return dummy.next;
}

// Utility function to print linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Sample driver code
int main() {
    // Create list: [1, 2, 3, 4, 5]
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int n = 2;

    struct ListNode* newHead = removeNthFromEnd(head, n);
    printf("Output: ");
    printList(newHead);  // Expected: 1 -> 2 -> 3 -> 5

    return 0;
}
