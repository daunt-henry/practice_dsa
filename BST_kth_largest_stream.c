/*
Problem:
Design a class that finds the kth largest element in a stream.
It should support:
- KthLargest(int k, int[] nums): initialize the object with the integer k and the stream.
- int add(int val): appends the integer val to the stream and returns the element representing the kth largest element.

Approach:
- Use a min-heap of size k.
- The root of the heap is always the kth largest element.
- Add new element:
  - If heap size < k, push directly.
  - Else, replace root if val > heap[0], then heapify.

Time: O(log k) per insertion
Space: O(k)

-------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_HEAP 10000

typedef struct {
    int* heap;
    int size;
    int capacity;
    int k;
} KthLargest;

// Swap utility
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Heapify up
void heapifyUp(KthLargest* obj, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (obj->heap[index] < obj->heap[parent]) {
            swap(&obj->heap[index], &obj->heap[parent]);
            index = parent;
        } else break;
    }
}

// Heapify down
void heapifyDown(KthLargest* obj, int index) {
    while (index * 2 + 1 < obj->size) {
        int smallest = index;
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        if (left < obj->size && obj->heap[left] < obj->heap[smallest]) smallest = left;
        if (right < obj->size && obj->heap[right] < obj->heap[smallest]) smallest = right;

        if (smallest != index) {
            swap(&obj->heap[index], &obj->heap[smallest]);
            index = smallest;
        } else break;
    }
}

// Push value into min-heap
void push(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }
}

// Public add function
int kthLargestAdd(KthLargest* obj, int val) {
    push(obj, val);
    return obj->heap[0];
}

// Constructor
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = malloc(sizeof(KthLargest));
    obj->heap = malloc(sizeof(int) * MAX_HEAP);
    obj->size = 0;
    obj->capacity = MAX_HEAP;
    obj->k = k;

    for (int i = 0; i < numsSize; i++)
        push(obj, nums[i]);

    return obj;
}

// Free memory
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

// ----------------------
// Demo
// ----------------------
int main() {
    int nums[] = {4, 5, 8, 2};
    int k = 3;
    KthLargest* kth = kthLargestCreate(k, nums, 4);

    printf("Add 3 → %d\n", kthLargestAdd(kth, 3));   // 4
    printf("Add 5 → %d\n", kthLargestAdd(kth, 5));   // 5
    printf("Add 10 → %d\n", kthLargestAdd(kth, 10)); // 5
    printf("Add 9 → %d\n", kthLargestAdd(kth, 9));   // 8
    printf("Add 4 → %d\n", kthLargestAdd(kth, 4));   // 8

    kthLargestFree(kth);
    return 0;
}
