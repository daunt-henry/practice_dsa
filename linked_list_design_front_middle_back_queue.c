/*
Problem:
Design a queue that supports:
- void pushFront(int val)
- void pushMiddle(int val)
- void pushBack(int val)
- int popFront()
- int popMiddle()
- int popBack()

Operations must run efficiently.

-----------------------------------------
Approach:
Use a doubly linked list to allow O(1) insertion/removal at front and back.
For middle operations, keep track of size and compute middle dynamically.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} FrontMiddleBackQueue;

Node* newNode(int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->prev = node->next = NULL;
    return node;
}

FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue* q = malloc(sizeof(FrontMiddleBackQueue));
    q->head = q->tail = NULL;
    q->size = 0;
    return q;
}

void pushAt(FrontMiddleBackQueue* q, int pos, int val) {
    Node* node = newNode(val);
    if (q->size == 0) {
        q->head = q->tail = node;
    } else if (pos == 0) {
        node->next = q->head;
        q->head->prev = node;
        q->head = node;
    } else if (pos == q->size) {
        node->prev = q->tail;
        q->tail->next = node;
        q->tail = node;
    } else {
        Node* curr = q->head;
        for (int i = 0; i < pos; i++) curr = curr->next;
        node->prev = curr->prev;
        node->next = curr;
        curr->prev->next = node;
        curr->prev = node;
    }
    q->size++;
}

int popAt(FrontMiddleBackQueue* q, int pos) {
    if (q->size == 0) return -1;
    Node* curr;
    if (pos == 0) {
        curr = q->head;
        q->head = curr->next;
        if (q->head) q->head->prev = NULL;
        else q->tail = NULL;
    } else if (pos == q->size - 1) {
        curr = q->tail;
        q->tail = curr->prev;
        if (q->tail) q->tail->next = NULL;
        else q->head = NULL;
    } else {
        curr = q->head;
        for (int i = 0; i < pos; i++) curr = curr->next;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    int val = curr->val;
    free(curr);
    q->size--;
    return val;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* q, int val) {
    pushAt(q, 0, val);
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* q, int val) {
    pushAt(q, q->size / 2, val);
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* q, int val) {
    pushAt(q, q->size, val);
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* q) {
    return popAt(q, 0);
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* q) {
    if (q->size == 0) return -1;
    int mid = (q->size - 1) / 2;
    return popAt(q, mid);
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* q) {
    return popAt(q, q->size - 1);
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* q) {
    Node* curr = q->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(q);
}

// Demo
int main() {
    FrontMiddleBackQueue* q = frontMiddleBackQueueCreate();
    frontMiddleBackQueuePushFront(q, 1); // [1]
    frontMiddleBackQueuePushBack(q, 2);  // [1,2]
    frontMiddleBackQueuePushMiddle(q, 3); // [1,3,2]
    frontMiddleBackQueuePushMiddle(q, 4); // [1,4,3,2]
    printf("Pop Front: %d\n", frontMiddleBackQueuePopFront(q));   // 1
    printf("Pop Middle: %d\n", frontMiddleBackQueuePopMiddle(q)); // 4
    printf("Pop Middle: %d\n", frontMiddleBackQueuePopMiddle(q)); // 3
    printf("Pop Back: %d\n", frontMiddleBackQueuePopBack(q));     // 2
    printf("Pop Front (empty): %d\n", frontMiddleBackQueuePopFront(q)); // -1

    frontMiddleBackQueueFree(q);
    return 0;
}
