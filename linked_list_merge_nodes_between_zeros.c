/*
Problem:
Given the head of a linked list, every node has a value from [0, 1000].
- The list starts and ends with 0.
- Between two 0s, there are several positive integers.

For each 0-delimited segment, sum the values in-between and build a new node list of those sums.

Example:
Input: head = [0,3,1,0,4,5,2,0]
Output: [4, 11]

-----------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode dummy = {0, NULL};
    struct ListNode* tail = &dummy;
    int sum = 0;

    head = head->next; // skip initial 0
    while (head) {
        if (head->val == 0) {
            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            newNode->val = sum;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            sum = 0;
        } else {
            sum += head->val;
        }
        head = head->next;
    }

    return dummy.next;
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
    int vals[] = {0, 3, 1, 0, 4, 5, 2, 0};
    struct ListNode* head = createList(vals, 8);
    struct ListNode* result = mergeNodes(head);
    printf("Merged node sums: ");
    printList(result);  // Output: 4 11
    freeList(head);
    freeList(result);
    return 0;
}
