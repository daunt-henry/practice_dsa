/*
Problem:
Given the head of a linked list and an array of integers G (a subset of node values),
return the number of connected components in the list where every node in the component belongs to G.

Two nodes are connected if they appear consecutively in the list.

Example:
Input: head = [0,1,2,3], G = [0,1,3]
Output: 2
Explanation:
Components are [0,1] and [3].

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Hashing for values in G
bool* createSet(int* G, int GSize) {
    bool* set = calloc(10001, sizeof(bool));
    for (int i = 0; i < GSize; i++) {
        set[G[i]] = true;
    }
    return set;
}

int numComponents(struct ListNode* head, int* G, int GSize) {
    bool* set = createSet(G, GSize);
    int count = 0;
    while (head) {
        if (set[head->val] && (!head->next || !set[head->next->val])) {
            count++;
        }
        head = head->next;
    }
    free(set);
    return count;
}

// Helper functions for demo
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

void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Demo
int main() {
    int arr[] = {0, 1, 2, 3};
    int G[] = {0, 1, 3};
    struct ListNode* head = createList(arr, 4);

    int result = numComponents(head, G, 3);
    printf("Number of components: %d\n", result);  // Output: 2

    freeList(head);
    return 0;
}
