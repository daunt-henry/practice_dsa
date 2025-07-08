/*
Problem:
Design your implementation of a circular queue. Implement the `MyCircularQueue` class:

- MyCircularQueue(k): Initializes the queue with size k.
- enQueue(value): Inserts an element. Returns true if successful.
- deQueue(): Deletes an element. Returns true if successful.
- Front(): Gets the front item. Returns -1 if empty.
- Rear(): Gets the last item. Returns -1 if empty.
- isEmpty(): Checks whether the queue is empty.
- isFull(): Checks whether the queue is full.

Example:
Input:
["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
[[3],[1],[2],[3],[4],[],[],[],[4],[]]
Output:
[null,true,true,true,false,3,true,true,true,4]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = malloc(sizeof(MyCircularQueue));
    obj->data = malloc(sizeof(int) * k);
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity) return false;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->data[obj->rear] = value;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) return false;
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0) return -1;
    return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) return -1;
    return obj->data[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

// Demo
int main() {
    MyCircularQueue* q = myCircularQueueCreate(3);

    printf("EnQueue 1: %d\n", myCircularQueueEnQueue(q, 1)); // true
    printf("EnQueue 2: %d\n", myCircularQueueEnQueue(q, 2)); // true
    printf("EnQueue 3: %d\n", myCircularQueueEnQueue(q, 3)); // true
    printf("EnQueue 4: %d\n", myCircularQueueEnQueue(q, 4)); // false
    printf("Rear: %d\n", myCircularQueueRear(q));           // 3
    printf("IsFull: %d\n", myCircularQueueIsFull(q));       // true
    printf("DeQueue: %d\n", myCircularQueueDeQueue(q));     // true
    printf("EnQueue 4: %d\n", myCircularQueueEnQueue(q, 4)); // true
    printf("Rear: %d\n", myCircularQueueRear(q));           // 4

    myCircularQueueFree(q);
    return 0;
}
