// Min Stack Implementation in C
// Supports push, pop, top, and retrieving the minimum element in constant time.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *stack;
    int *minStack;
    int top;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = malloc(sizeof(MinStack));
    obj->capacity = 10000;
    obj->stack = malloc(sizeof(int) * obj->capacity);
    obj->minStack = malloc(sizeof(int) * obj->capacity);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->stack[++(obj->top)] = val;
    if (obj->top == 0) {
        obj->minStack[obj->top] = val;
    } else {
        int prevMin = obj->minStack[obj->top - 1];
        obj->minStack[obj->top] = val < prevMin ? val : prevMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}

int main() {
    MinStack* stack = minStackCreate();
    minStackPush(stack, -2);
    minStackPush(stack, 0);
    minStackPush(stack, -3);
    printf("Minimum: %d\n", minStackGetMin(stack)); // Output: -3
    minStackPop(stack);
    printf("Top: %d\n", minStackTop(stack));        // Output: 0
    printf("Minimum: %d\n", minStackGetMin(stack)); // Output: -2
    minStackFree(stack);
    return 0;
}
