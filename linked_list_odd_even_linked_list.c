/*
Problem:
Given the head of a singly linked list, group all the nodes with odd indices together
followed by the nodes with even indices, and return the reordered list.

Note:
- The relative order inside both the even and odd groups should remain as it was in the input.

Example:
Input:  head = [1,2,3,4,5]  
Output: [1,3,5,2,4]

Input:  head = [2,1,3,5,6,4,7]  
Output: [2,3,6,7,1,5,4]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Utility: create new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Rearrange odd and even positioned nodes
struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
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
    // Input: [1,2,3,4,5]
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list: ");
    printList(head);

    struct ListNode* result = oddEvenList(head);

    printf("Reordered list: ");
    printList(result);  // Expected: 1 -> 3 -> 5 -> 2 -> 4

    return 0;
}
