/*
Problem:
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807

Note: The output list should also be in reverse order.

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Main logic to add two numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* temp = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y + carry;

        carry = sum / 10;
        temp->next = createNode(sum % 10);
        temp = temp->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy.next;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Sample driver code
int main() {
    // l1 = [2,4,3]
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // l2 = [5,6,4]
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Output: ");
    printList(result);  // Expected: 7 -> 0 -> 8

    return 0;
}
