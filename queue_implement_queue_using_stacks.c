/*
Problem: Implement Queue using Stacks

Description:
Implement a first in first out (FIFO) queue using only two stacks.
You must implement the following operations:
- void push(int x): Push element x to the back of queue.
- int pop(): Removes the element from the front of queue and returns it.
- int peek(): Get the front element.
- bool empty(): Returns whether the queue is empty.

Constraints:
- You must use only standard stack operations (push to top, pop from top, peek/top, size, and is empty).
- You may assume that all operations are valid and the queue capacity is sufficient.

Sample Operations:
Push(10)
Push(20)
Push(30)
Peek() -> 10
Pop() -> 10
Peek() -> 20
Empty() -> false

Expected Output:
Peek: 10
Pop: 10
Peek: 20
Is empty? No
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack implementation
typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* s = malloc(sizeof(Stack));
    s->data = malloc(sizeof(int) * capacity);
    s->top = -1;
    s->capacity = capacity;
    return s;
}

void pushStack(Stack* s, int val) {
    s->data[++s->top] = val;
}

int popStack(Stack* s) {
    return s->data[s->top--];
}

int peekStack(Stack* s) {
    return s->data[s->top];
}

bool isEmptyStack(Stack* s) {
    return s->top == -1;
}

void freeStack(Stack* s) {
    free(s->data);
    free(s);
}

// Queue using two stacks
typedef struct {
    Stack* inStack;
    Stack* outStack;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate() {
    int cap = 100;
    MyQueue* q = malloc(sizeof(MyQueue));
    q->inStack = createStack(cap);
    q->outStack = createStack(cap);
    q->capacity = cap;
    return q;
}

void shiftStacks(MyQueue* obj) {
    if (isEmptyStack(obj->outStack)) {
        while (!isEmptyStack(obj->inStack)) {
            pushStack(obj->outStack, popStack(obj->inStack));
        }
    }
}

void myQueuePush(MyQueue* obj, int x) {
    pushStack(obj->inStack, x);
}

int myQueuePop(MyQueue* obj) {
    shiftStacks(obj);
    return popStack(obj->outStack);
}

int myQueuePeek(MyQueue* obj) {
    shiftStacks(obj);
    return peekStack(obj->outStack);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmptyStack(obj->inStack) && isEmptyStack(obj->outStack);
}

void myQueueFree(MyQueue* obj) {
    freeStack(obj->inStack);
    freeStack(obj->outStack);
    free(obj);
}

int main() {
    MyQueue* q = myQueueCreate();
    myQueuePush(q, 10);
    myQueuePush(q, 20);
    myQueuePush(q, 30);
    printf("Peek: %d\n", myQueuePeek(q)); // 10
    printf("Pop: %d\n", myQueuePop(q));   // 10
    printf("Peek: %d\n", myQueuePeek(q)); // 20
    printf("Is empty? %s\n", myQueueEmpty(q) ? "Yes" : "No"); // No
    myQueueFree(q);
    return 0;
}
