/*
Problem:
Given the head of a singly linked list, delete the **middle node** and return the head of the modified list.
- If there are two middle nodes, delete the **second one**.
- If the list has only one node, return NULL.

Example:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]

Explanation:
Middle index = 3 (0-based), value = 7 → deleted

--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
    if (!head || !head->next) return NULL;

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    // Move fast by 2, slow by 1
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node
    if (prev) {
        prev->next = slow->next;
    }

    free(slow);
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
    int vals[] = {1, 3, 4, 7, 1, 2, 6};
    struct ListNode* head = createList(vals, 7);
    struct ListNode* result = deleteMiddle(head);
    printf("After deleting middle: ");
    printList(result);  // Output: 1 3 4 1 2 6
    freeList(result);
    return 0;
}
