/*
Problem:
Write a function to delete a node in a singly-linked list.  
You will not be given access to the head of the list,  
instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not the tail node.

Example:
Input: head = [4,5,1,9], node = 5  
Output: [4,1,9]

Note:
- The input node is not the head.
- The node is guaranteed not to be the last node.

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
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to delete the given node (non-tail guaranteed)
void deleteNode(struct ListNode* node) {
    if (!node || !node->next) return;

    struct ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    free(temp);
}

// Utility: print list
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
    // Input list: [4,5,1,9], delete node 5
    struct ListNode* head = createNode(4);
    head->next = createNode(5);
    head->next->next = createNode(1);
    head->next->next->next = createNode(9);

    printf("Original list: ");
    printList(head);

    // Call deleteNode on node with value 5 (not head or tail)
    deleteNode(head->next);  // This deletes the node with value 5

    printf("After deletion: ");
    printList(head);  // Expected: 4 -> 1 -> 9

    return 0;
}
