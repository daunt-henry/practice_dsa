/*
Problem: Smallest Range Covering Elements from K Lists

Given k sorted lists, find the smallest range [a, b] that includes at least
one number from each of the k lists.

Approach:
- Use a min-heap to track the smallest element among current k elements.
- Keep track of the max element across heap.
- At each step, pop min and insert next element from same list.
- Track best range.

Time: O(n log k)
Space: O(k)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int val;
    int row; // list index
    int idx; // index within list
} HeapNode;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(HeapNode heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[i].val < heap[p].val) {
            swap(&heap[i], &heap[p]);
            i = p;
        } else break;
    }
}

void heapifyDown(HeapNode heap[], int size, int i) {
    while (2 * i + 1 < size) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (heap[left].val < heap[smallest].val) smallest = left;
        if (right < size && heap[right].val < heap[smallest].val) smallest = right;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

HeapNode pop(HeapNode heap[], int* size) {
    HeapNode top = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return top;
}

void push(HeapNode heap[], int* size, HeapNode node) {
    heap[(*size)++] = node;
    heapifyUp(heap, *size - 1);
}

int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    HeapNode* heap = malloc(sizeof(HeapNode) * numsSize);
    int heapSize = 0;
    int max = INT_MIN;

    // Initialize heap with first element from each list
    for (int i = 0; i < numsSize; i++) {
        push(heap, &heapSize, (HeapNode){nums[i][0], i, 0});
        if (nums[i][0] > max) max = nums[i][0];
    }

    int rangeStart = 0, rangeEnd = INT_MAX;

    while (1) {
        HeapNode minNode = pop(heap, &heapSize);
        int curRange = max - minNode.val;
        if (curRange < rangeEnd - rangeStart) {
            rangeStart = minNode.val;
            rangeEnd = max;
        }

        int nextIdx = minNode.idx + 1;
        if (nextIdx == numsColSize[minNode.row]) break;

        int nextVal = nums[minNode.row][nextIdx];
        if (nextVal > max) max = nextVal;
        push(heap, &heapSize, (HeapNode){nextVal, minNode.row, nextIdx});
    }

    int* res = malloc(sizeof(int) * 2);
    res[0] = rangeStart;
    res[1] = rangeEnd;
    *returnSize = 2;
    free(heap);
    return res;
}

// Test
int main() {
    int a[] = {4, 10, 15, 24, 26};
    int b[] = {0, 9, 12, 20};
    int c[] = {5, 18, 22, 30};

    int* lists[] = {a, b, c};
    int sizes[] = {5, 4, 4};
    int returnSize;

    int* result = smallestRange(lists, 3, sizes, &returnSize);
    printf("Smallest range: [%d, %d]\n", result[0], result[1]);

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Smallest range: [20, 24]
==========================
*/
