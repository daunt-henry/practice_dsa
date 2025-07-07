/*
Problem:
You're given an array of intervals, where each interval has a start and end time.
You must divide all intervals into the minimum number of groups such that
no two intervals in the same group overlap.

Return the minimum number of such groups required.

Example Input:
intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]

Expected Output:
3

Explanation:
One possible grouping:
- Group 1: [1,5], [6,8]
- Group 2: [2,3], [5,10]
- Group 3: [1,10]
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

typedef struct {
    int* data;
    int size;
} MinHeap;

void heapifyUp(MinHeap* heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[i] >= heap->data[parent]) break;
        int tmp = heap->data[i];
        heap->data[i] = heap->data[parent];
        heap->data[parent] = tmp;
        i = parent;
    }
}

void heapifyDown(MinHeap* heap, int i) {
    int left, right, smallest;
    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        smallest = i;

        if (left < heap->size && heap->data[left] < heap->data[smallest]) smallest = left;
        if (right < heap->size && heap->data[right] < heap->data[smallest]) smallest = right;

        if (smallest == i) break;

        int tmp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = tmp;
        i = smallest;
    }
}

void push(MinHeap* heap, int val) {
    heap->data[heap->size++] = val;
    heapifyUp(heap, heap->size - 1);
}

int pop(MinHeap* heap) {
    int top = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapifyDown(heap, 0);
    return top;
}

int top(MinHeap* heap) {
    return heap->data[0];
}

int minGroups(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    MinHeap heap;
    heap.data = malloc(sizeof(int) * intervalsSize);
    heap.size = 0;

    for (int i = 0; i < intervalsSize; ++i) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (heap.size > 0 && top(&heap) < start)
            pop(&heap);

        push(&heap, end);
    }

    int result = heap.size;
    free(heap.data);
    return result;
}

int main() {
    int a[] = {5, 10};
    int b[] = {6, 8};
    int c[] = {1, 5};
    int d[] = {2, 3};
    int e[] = {1, 10};
    int* intervals[] = {a, b, c, d, e};
    int colSize[] = {2, 2, 2, 2, 2};

    int res = minGroups(intervals, 5, colSize);
    printf("Minimum number of groups: %d\n", res);
    return 0;
}
