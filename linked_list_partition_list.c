/*
Problem:
Given the head of a linked list and a value x, partition it such that all nodes less than x
come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Utility to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Main logic to partition list based on value x
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode beforeDummy = {0, NULL};
    struct ListNode afterDummy = {0, NULL};
    struct ListNode *before = &beforeDummy, *after = &afterDummy;

    while (head) {
        if (head->val < x) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }

    after->next = NULL;
    before->next = afterDummy.next;

    return beforeDummy.next;
}

// Utility to print the list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Driver code
int main() {
    // Input: [1,4,3,2,5,2], x = 3
    struct ListNode* head = createNode(1);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(2);

    int x = 3;
    struct ListNode* result = partition(head, x);
    printf("Output: ");
    printList(result);  // Expected: 1 -> 2 -> 2 -> 4 -> 3 -> 5

    return 0;
}
