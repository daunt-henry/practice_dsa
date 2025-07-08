/*
Problem:
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

Explanation: The final merged list contains all elements from the k lists in sorted order.

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Helper to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Merge two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next;
}

// Main function to merge k sorted lists using divide and conquer
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    if (listsSize == 1) return lists[0];

    while (listsSize > 1) {
        int mid = (listsSize + 1) / 2;
        for (int i = 0; i < listsSize / 2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[i + mid]);
        }
        listsSize = mid;
    }

    return lists[0];
}

// Utility function to print list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Driver code for testing
int main() {
    // Create lists = [[1,4,5],[1,3,4],[2,6]]
    struct ListNode* lists[3];

    lists[0] = createNode(1);
    lists[0]->next = createNode(4);
    lists[0]->next->next = createNode(5);

    lists[1] = createNode(1);
    lists[1]->next = createNode(3);
    lists[1]->next->next = createNode(4);

    lists[2] = createNode(2);
    lists[2]->next = createNode(6);

    struct ListNode* result = mergeKLists(lists, 3);
    printf("Output: ");
    printList(result);  // Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

    return 0;
}
