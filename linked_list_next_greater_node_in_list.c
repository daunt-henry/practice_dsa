/*
Problem:
Given the head of a linked list with integers, return an array `res` where `res[i]` is the **next greater node**
for the i-th node in the linked list. If there is no next greater node, use 0.

Example:
Input: head = [2, 1, 5]
Output: [5, 5, 0]

Approach:
- Convert the linked list to an array.
- Use a monotonic stack to track the next greater element for each index.

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// First pass: convert linked list to array
int getLength(struct ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    int n = getLength(head);
    *returnSize = n;

    int* values = malloc(sizeof(int) * n);
    int* res = calloc(n, sizeof(int));
    int* stack = malloc(sizeof(int) * n);
    int top = -1;

    // Fill values array from list
    struct ListNode* curr = head;
    for (int i = 0; i < n; i++) {
        values[i] = curr->val;
        curr = curr->next;
    }

    // Monotonic stack to find next greater element
    for (int i = 0; i < n; i++) {
        while (top >= 0 && values[i] > values[stack[top]]) {
            res[stack[top]] = values[i];
            top--;
        }
        stack[++top] = i;
    }

    free(values);
    free(stack);
    return res;
}

// Demo helpers
struct ListNode* createList(int* arr, int len) {
    struct ListNode* head = NULL, *tail = NULL;
    for (int i = 0; i < len; i++) {
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

void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Demo
int main() {
    int arr[] = {2, 1, 5};
    struct ListNode* head = createList(arr, 3);

    int size = 0;
    int* result = nextLargerNodes(head, &size);

    printf("Next Greater Nodes: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    freeList(head);
    free(result);
    return 0;
}
