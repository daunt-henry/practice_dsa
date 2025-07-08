/*
Problem:
Design a circular deque with fixed size k.

Implement:
- MyCircularDeque(k): Constructor.
- insertFront(), insertLast(): Insert element at front/rear.
- deleteFront(), deleteLast(): Delete from front/rear.
- getFront(), getRear(): Return front/rear values.
- isEmpty(), isFull(): Status checks.

All operations must run in O(1) time.

Example:
Input:
["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear",
 "isFull","deleteLast","insertFront","getFront"]
[[3],[1],[2],[3],[4],[],[],[],[4],[]]
Output:
[null,true,true,true,false,2,true,true,true,4]

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
} MyCircularDeque;

// Create deque
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = malloc(sizeof(MyCircularDeque));
    obj->data = malloc(sizeof(int) * k);
    obj->front = 0;
    obj->rear = k - 1;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

// Insert at front
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->data[obj->front] = value;
    obj->size++;
    return true;
}

// Insert at rear
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->data[obj->rear] = value;
    obj->size++;
    return true;
}

// Delete from front
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

// Delete from rear
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

// Get front
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->data[obj->front];
}

// Get rear
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->data[obj->rear];
}

// Is empty
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

// Is full
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

// Free deque
void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->data);
    free(obj);
}

// Demo
int main() {
    MyCircularDeque* dq = myCircularDequeCreate(3);

    printf("insertLast(1): %d\n", myCircularDequeInsertLast(dq, 1)); // true
    printf("insertLast(2): %d\n", myCircularDequeInsertLast(dq, 2)); // true
    printf("insertFront(3): %d\n", myCircularDequeInsertFront(dq, 3)); // true
    printf("insertFront(4): %d\n", myCircularDequeInsertFront(dq, 4)); // false (full)
    printf("getRear(): %d\n", myCircularDequeGetRear(dq));           // 2
    printf("isFull(): %d\n", myCircularDequeIsFull(dq));             // true
    printf("deleteLast(): %d\n", myCircularDequeDeleteLast(dq));     // true
    printf("insertFront(4): %d\n", myCircularDequeInsertFront(dq, 4));// true
    printf("getFront(): %d\n", myCircularDequeGetFront(dq));         // 4

    myCircularDequeFree(dq);
    return 0;
}
