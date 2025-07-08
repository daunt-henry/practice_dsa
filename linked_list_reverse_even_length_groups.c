/*
Problem:
You are given the head of a linked list. Split the list into groups:
- 1st group has 1 node
- 2nd group has 2 nodes
- 3rd group has 3 nodes, and so on...

If the group length is **even**, reverse the nodes in that group.
Return the modified list.

Example:
Input: head = [1,2,3,4,5,6]
Output: [1,3,2,4,5,6]

----------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

// Helper to reverse 'k' nodes from head, returns new head and tail
struct ListNode* reverseList(struct ListNode* head, int k) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (k--) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* reverseEvenLengthGroups(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prevGroupTail = &dummy;
    struct ListNode* curr = head;

    int groupSize = 1;

    while (curr) {
        struct ListNode* groupHead = curr;
        int count = 0;
        // Count actual nodes available
        struct ListNode* temp = curr;
        for (int i = 0; i < groupSize && temp; i++) {
            count++;
            temp = temp->next;
        }

        struct ListNode* groupTail = curr;
        for (int i = 1; i < count; i++) {
            groupTail = groupTail->next;
        }

        struct ListNode* nextGroupHead = groupTail->next;

        if (count % 2 == 0) {
            // Reverse this group
            groupTail->next = NULL;
            struct ListNode* newHead = reverseList(groupHead, count);
            prevGroupTail->next = newHead;
            groupHead->next = nextGroupHead;
            prevGroupTail = groupHead;
        } else {
            // No reversal
            prevGroupTail = groupTail;
        }

        curr = nextGroupHead;
        groupSize++;
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
    int vals[] = {1, 2, 3, 4, 5, 6};
    struct ListNode* head = createList(vals, 6);
    struct ListNode* result = reverseEvenLengthGroups(head);
    printf("Reversed groups: ");
    printList(result);  // Output: 1 3 2 4 5 6
    freeList(result);
    return 0;
}
