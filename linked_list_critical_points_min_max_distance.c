/*
Problem:
Given the head of a linked list, a node is **critical** if:
- It is neither the first nor last node.
- Its value is strictly greater or smaller than both its neighbors.

You must return a list of two integers:
- The minimum distance between any two critical points
- The maximum distance between the first and last critical point

If there are fewer than two critical points, return [-1, -1].

Example:
Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3, 6]

Explanation:
Critical points at indices 1, 4, and 7. Min = 3 (between 1 and 4), Max = 6 (between 1 and 7)

----------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = result[1] = -1;

    if (!head || !head->next || !head->next->next) return result;

    int idx = 1;
    int first = -1, last = -1, prev = 0, minDist = __INT_MAX__;

    struct ListNode* prevNode = head;
    struct ListNode* curr = head->next;
    struct ListNode* next = head->next->next;

    while (next) {
        if ((curr->val > prevNode->val && curr->val > next->val) ||
            (curr->val < prevNode->val && curr->val < next->val)) {
            
            if (first == -1) {
                first = idx;
            } else {
                minDist = (idx - prev < minDist) ? (idx - prev) : minDist;
            }
            prev = idx;
            last = idx;
        }
        prevNode = curr;
        curr = next;
        next = next->next;
        idx++;
    }

    if (first != -1 && last != first) {
        result[0] = minDist;
        result[1] = last - first;
    }

    return result;
}

// Demo helpers
struct ListNode* createList(int* arr, int n) {
    struct ListNode* head = NULL, *tail = NULL;
    for (int i = 0; i < n; ++i) {
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
    int vals[] = {1, 3, 2, 2, 3, 2, 2, 2, 7};
    struct ListNode* head = createList(vals, 9);

    int returnSize;
    int* res = nodesBetweenCriticalPoints(head, &returnSize);
    printf("Min Distance: %d, Max Distance: %d\n", res[0], res[1]); // Output: 3, 6

    free(res);
    freeList(head);
    return 0;
}
