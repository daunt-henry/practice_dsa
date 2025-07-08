/*
Problem:
Given head which is a reference node to a singly-linked list. 
The linked list represents a binary number, where each node contains a 0 or 1.
Return the decimal value of the number represented by the linked list.

Example:
Input: head = [1,0,1]
Output: 5

Explanation:
(1 * 2^2) + (0 * 2^1) + (1 * 2^0) = 5

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode* head) {
    int result = 0;
    while (head) {
        result = (result << 1) | head->val;
        head = head->next;
    }
    return result;
}

// Demo helpers
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;

    struct ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        curr->next = node;
        curr = node;
    }
    return head;
}

void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Demo
int main() {
    int bits[] = {1, 0, 1};
    struct ListNode* head = createList(bits, 3);

    int decimal = getDecimalValue(head);
    printf("Decimal value: %d\n", decimal);  // Output: 5

    freeList(head);
    return 0;
}
