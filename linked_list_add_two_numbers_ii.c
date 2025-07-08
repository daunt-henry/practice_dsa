/*
Problem:
You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single digit.

Add the two numbers and return the sum as a linked list (also with most significant digit first).

You **may not** modify the input lists (i.e., cannot reverse them).

Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Stack structure for reversing logic
typedef struct Stack {
    int data[100];
    int top;
} Stack;

void push(Stack* s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack* s) {
    return s->data[(s->top)--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

// Create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Main function to add two numbers using stacks
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    Stack s1 = {.top = -1}, s2 = {.top = -1};

    while (l1) {
        push(&s1, l1->val);
        l1 = l1->next;
    }

    while (l2) {
        push(&s2, l2->val);
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* result = NULL;

    while (!isEmpty(&s1) || !isEmpty(&s2) || carry) {
        int sum = carry;
        if (!isEmpty(&s1)) sum += pop(&s1);
        if (!isEmpty(&s2)) sum += pop(&s2);

        struct ListNode* node = createNode(sum % 10);
        node->next = result;
        result = node;
        carry = sum / 10;
    }

    return result;
}

// Utility to print list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Driver demo
int main() {
    // Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
    struct ListNode* l1 = createNode(7);
    l1->next = createNode(2);
    l1->next->next = createNode(4);
    l1->next->next->next = createNode(3);

    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);  // Expected: 7 -> 8 -> 0 -> 7

    return 0;
}
