/*
Problem:
Given a linked list and an integer k, split the linked list into k consecutive parts.

Each part should have as equal length as possible:
- No two parts should have size differing by more than 1.
- Some parts may be NULL if not enough nodes.

Example:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to get the length of the linked list
int getLength(struct ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Split linked list in parts
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    int totalLen = getLength(head);
    int baseSize = totalLen / k;
    int extra = totalLen % k;

    struct ListNode** parts = malloc(sizeof(struct ListNode*) * k);
    *returnSize = k;

    for (int i = 0; i < k; i++) {
        parts[i] = head;
        int partSize = baseSize + (i < extra ? 1 : 0);

        for (int j = 1; j < partSize && head; j++) {
            head = head->next;
        }

        if (head) {
            struct ListNode* temp = head->next;
            head->next = NULL;
            head = temp;
        }
    }

    return parts;
}

// Helper functions for testing
struct ListNode* createList(int* arr, int len) {
    if (len == 0) return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* curr = head;

    for (int i = 1; i < len; i++) {
        curr->next = malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}

void printParts(struct ListNode** parts, int size) {
    for (int i = 0; i < size; i++) {
        struct ListNode* node = parts[i];
        printf("Part %d: ", i + 1);
        while (node) {
            printf("%d ", node->val);
            node = node->next;
        }
        printf("\n");
    }
}

void freeParts(struct ListNode** parts, int size) {
    for (int i = 0; i < size; i++) {
        struct ListNode* curr = parts[i];
        while (curr) {
            struct ListNode* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(parts);
}

// Demo
int main() {
    int arr[] = {1, 2, 3};
    int k = 5;
    struct ListNode* head = createList(arr, 3);
    int returnSize = 0;

    struct ListNode** result = splitListToParts(head, k, &returnSize);
    printParts(result, returnSize);
    freeParts(result, returnSize);

    return 0;
}
