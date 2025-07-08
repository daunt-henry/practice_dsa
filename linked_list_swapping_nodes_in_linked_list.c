/*
Problem:
You are given the head of a linked list and an integer k. 
Swap the values of the k-th node from the beginning and the k-th node from the end.

Example:
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Explanation:
2nd from start = 2, 2nd from end = 4 → Swap values

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* first = head;
    for (int i = 1; i < k; i++) {
        first = first->next;
    }

    struct ListNode* second = head;
    struct ListNode* temp = first;
    while (temp->next) {
        temp = temp->next;
        second = second->next;
    }

    int swap = first->val;
    first->val = second->val;
    second->val = swap;

    return head;
}

// Demo helpers
struct ListNode* createList(int* arr, int size) {
    struct ListNode* head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++) {
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
    int arr[] = {1, 2, 3, 4, 5};
    struct ListNode* list = createList(arr, 5);

    int k = 2;
    struct ListNode* result = swapNodes(list, k);
    printf("Swapped list: ");
    printList(result);  // Output: 1 4 3 2 5

    freeList(result);
    return 0;
}
