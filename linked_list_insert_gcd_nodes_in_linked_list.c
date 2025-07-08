/*
Problem:
Given a singly linked list, insert a node with the GCD (greatest common divisor) between every two adjacent nodes.

Return the modified list.

Example:
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]

Explanation:
- GCD(18,6) = 6 → insert between
- GCD(6,10) = 2 → insert between
- GCD(10,3) = 1 → insert between

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to compute GCD
int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr && curr->next) {
        int g = gcd(curr->val, curr->next->val);
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = g;
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
    return head;
}

// Demo helpers
struct ListNode* createList(int* arr, int size) {
    struct ListNode* head = NULL, *tail = NULL;
    for (int i = 0; i < size; ++i) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
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
    int vals[] = {18, 6, 10, 3};
    struct ListNode* head = createList(vals, 4);
    head = insertGreatestCommonDivisors(head);
    printf("Modified list with GCDs inserted: ");
    printList(head); // Output: 18 6 6 2 10 1 3
    freeList(head);
    return 0;
}
