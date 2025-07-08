/*
Problem:
You are given two linked lists: list1 and list2, and two integers `a` and `b`.
Merge list2 into list1 between positions `a` and `b`.

Specifically:
- Remove list1 nodes from position a to b (inclusive, 0-based).
- Splice list2 in place of the removed portion.

Example:
Input:
list1 = [0,1,2,3,4,5], a = 3, b = 4
list2 = [1000000,1000001,1000002]

Output:
[0,1,2,1000000,1000001,1000002,5]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    struct ListNode* prevA = NULL;
    struct ListNode* afterB = NULL;
    struct ListNode* curr = list1;

    int index = 0;
    while (curr) {
        if (index == a - 1) prevA = curr;
        if (index == b + 1) {
            afterB = curr;
            break;
        }
        curr = curr->next;
        index++;
    }

    prevA->next = list2;

    struct ListNode* tail = list2;
    while (tail->next) tail = tail->next;

    tail->next = afterB;
    return list1;
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
    int list1Arr[] = {0, 1, 2, 3, 4, 5};
    int list2Arr[] = {1000000, 1000001, 1000002};
    struct ListNode* list1 = createList(list1Arr, 6);
    struct ListNode* list2 = createList(list2Arr, 3);

    struct ListNode* result = mergeInBetween(list1, 3, 4, list2);
    printf("Merged list: ");
    printList(result);  // Output: 0 1 2 1000000 1000001 1000002 5

    freeList(result);
    return 0;
}
