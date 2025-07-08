/*
Problem:
In a linked list with even number of nodes, a twin pair is defined as:
- node[i] and node[n - 1 - i] for i in [0, n/2 - 1]

Find the **maximum twin sum**.

Example:
Input: head = [5,4,2,1]
Output: 6
Explanation: Twin pairs = (5,1), (4,2) → sums = 6, 6 → max = 6

-------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int pairSum(struct ListNode* head) {
    if (!head) return 0;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // Find middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode* second = reverseList(slow);
    struct ListNode* first = head;

    // Compute max twin sum
    int maxSum = 0;
    while (second) {
        int sum = first->val + second->val;
        if (sum > maxSum) maxSum = sum;
        first = first->next;
        second = second->next;
    }

    return maxSum;
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

void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Demo
int main() {
    int vals[] = {5, 4, 2, 1};
    struct ListNode* head = createList(vals, 4);
    int result = pairSum(head);
    printf("Maximum twin sum: %d\n", result);  // Output: 6
    freeList(head);
    return 0;
}
