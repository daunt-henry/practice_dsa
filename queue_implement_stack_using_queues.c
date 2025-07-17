/*
Problem: Implement Stack using Queues

Description:
Implement a last-in-first-out (LIFO) stack using only two queues.
You must implement the following operations:
- void push(int x): Push element x onto stack.
- int pop(): Removes the element on the top of the stack and returns it.
- int top(): Get the top element.
- bool empty(): Returns whether the stack is empty.

Constraints:
- All operations must use only standard queue operations.
- You may use multiple queues.
- You may assume stack capacity is large enough for your test cases.

Sample Operations:
Push(10)
Push(20)
Push(30)
Top() -> 30
Pop() -> 30
Top() -> 20
Empty() -> false

Expected Output:
Top: 30
Pop: 30
Top: 20
Is empty? No
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = malloc(sizeof(Queue));
    q->data = malloc(sizeof(int) * capacity);
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

bool isEmptyQueue(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
    q->size++;
}

int dequeue(Queue* q) {
    q->size--;
    return q->data[q->front++];
}

int peekFront(Queue* q) {
    return q->data[q->front];
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

// Stack implementation using two queues
typedef struct {
    Queue *q1;
    Queue *q2;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    int cap = 100;
    MyStack* stack = malloc(sizeof(MyStack));
    stack->q1 = createQueue(cap);
    stack->q2 = createQueue(cap);
    stack->capacity = cap;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x);
    while (!isEmptyQueue(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

int myStackTop(MyStack* obj) {
    return peekFront(obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(obj->q1);
}

void myStackFree(MyStack* obj) {
    freeQueue(obj->q1);
    freeQueue(obj->q2);
    free(obj);
}

int main() {
    MyStack* stack = myStackCreate();
    myStackPush(stack, 10);
    myStackPush(stack, 20);
    myStackPush(stack, 30);
    printf("Top: %d\n", myStackTop(stack)); // 30
    printf("Pop: %d\n", myStackPop(stack)); // 30
    printf("Top: %d\n", myStackTop(stack)); // 20
    printf("Is empty? %s\n", myStackEmpty(stack) ? "Yes" : "No"); // No
    myStackFree(stack);
    return 0;
}
