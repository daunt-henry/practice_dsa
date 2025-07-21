/*
Title: Design a Stack With Increment Operation

Description:
  Implement a custom stack with a maximum size. It supports the following operations:
  - Push: Adds element if size < maxSize
  - Pop: Removes and returns the top element. Returns -1 if empty.
  - Increment: Increments the bottom k elements by val

Example Input/Output:
  MaxSize = 3
  Push(1)
  Push(2)
  Pop() -> 2
  Push(2)
  Push(3)
  Push(4)  // Ignored, stack full
  Increment(5, 100)
  Increment(2, 100)
  Pop() -> 103
  Pop() -> 202
  Pop() -> 101
  Pop() -> -1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int* inc;
    int size;
    int maxSize;
} CustomStack;

CustomStack* customStackCreate(int maxSize) {
    CustomStack* stack = (CustomStack*)malloc(sizeof(CustomStack));
    stack->data = (int*)malloc(sizeof(int) * maxSize);
    stack->inc = (int*)calloc(maxSize, sizeof(int));
    stack->size = 0;
    stack->maxSize = maxSize;
    return stack;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->size < obj->maxSize) {
        obj->data[obj->size] = x;
        obj->size++;
    }
}

int customStackPop(CustomStack* obj) {
    if (obj->size == 0) return -1;
    obj->size--;
    int res = obj->data[obj->size] + obj->inc[obj->size];
    if (obj->size > 0) {
        obj->inc[obj->size - 1] += obj->inc[obj->size];
    }
    obj->inc[obj->size] = 0;
    return res;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    int n = (k < obj->size) ? k : obj->size;
    if (n > 0) obj->inc[n - 1] += val;
}

void customStackFree(CustomStack* obj) {
    free(obj->data);
    free(obj->inc);
    free(obj);
}

int main() {
    CustomStack* stack = customStackCreate(3);
    customStackPush(stack, 1);
    customStackPush(stack, 2);
    printf("Pop: %d\n", customStackPop(stack)); // 2
    customStackPush(stack, 2);
    customStackPush(stack, 3);
    customStackPush(stack, 4); // Ignored
    customStackIncrement(stack, 5, 100);
    customStackIncrement(stack, 2, 100);
    printf("Pop: %d\n", customStackPop(stack)); // 103
    printf("Pop: %d\n", customStackPop(stack)); // 202
    printf("Pop: %d\n", customStackPop(stack)); // 101
    printf("Pop: %d\n", customStackPop(stack)); // -1
    customStackFree(stack);
    return 0;
}
