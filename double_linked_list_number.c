/*
Problem:
Double the value of a number represented as a singly-linked list
with most significant digit first.

Approach:
- Reverse the list
- Multiply each digit by 2 and handle carry
- If carry remains at end, create a new node
- Reverse the list back

Time Complexity: O(n)
Space Complexity: O(1) auxiliary (reuses nodes)
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition
struct ListNode {
    int val;
    struct ListNode* next;
};

// Reverse helper
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Core function
struct ListNode* doubleIt(struct ListNode* head) {
    head = reverse(head);
    struct ListNode* cur = head;
    int carry = 0;

    while (cur) {
        int sum = cur->val * 2 + carry;
        cur->val = sum % 10;
        carry = sum / 10;
        if (!cur->next && carry) {
            cur->next = malloc(sizeof(struct ListNode));
            cur->next->val = 0;
            cur->next->next = NULL;
        }
        cur = cur->next;
    }

    return reverse(head);
}

// Utility functions for demo
struct ListNode* createList(int* arr, int size) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        if (!head) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        head = head->next;
    }
    printf("\n");
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
    int digits[] = {1, 8, 9}; // Represents 189
    struct ListNode* head = createList(digits, sizeof(digits)/sizeof(digits[0]));

    printf("Original: ");
    printList(head);

    struct ListNode* doubled = doubleIt(head);

    printf("Doubled:  ");
    printList(doubled);

    freeList(doubled);
    return 0;
}
