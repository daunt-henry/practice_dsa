/*
   Problem: Find K Pairs with Smallest Sums

   Given two sorted arrays nums1 and nums2, and an integer k,
   return k pairs (u, v) where u is from nums1 and v is from nums2
   such that the sum u + v is the smallest.

   Example:
   Input:
       nums1 = [1,7,11]
       nums2 = [2,4,6]
       k = 3
   Output:
       [ [1,2], [1,4], [1,6] ]
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sum;
    int i;
    int j;
} Node;

typedef struct {
    Node* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (Node*)malloc(sizeof(Node) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(Node* a, Node* b) {
    Node t = *a; *a = *b; *b = t;
}

void heapPush(MinHeap* h, Node val) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (Node*)realloc(h->data, sizeof(Node) * h->capacity);
    }
    int i = h->size++;
    h->data[i] = val;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p].sum <= h->data[i].sum) break;
        swap(&h->data[p], &h->data[i]);
        i = p;
    }
}

Node heapPop(MinHeap* h) {
    Node top = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, s = i;
        if (l < h->size && h->data[l].sum < h->data[s].sum) s = l;
        if (r < h->size && h->data[r].sum < h->data[s].sum) s = r;
        if (s == i) break;
        swap(&h->data[i], &h->data[s]);
        i = s;
    }
    return top;
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size,
                     int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (nums1Size == 0 || nums2Size == 0 || k == 0) return NULL;

    int** result = (int**)malloc(sizeof(int*) * k);
    *returnColumnSizes = (int*)malloc(sizeof(int) * k);

    MinHeap* heap = createHeap(k + 1);
    for (int i = 0; i < nums1Size && i < k; i++) {
        Node node = {nums1[i] + nums2[0], i, 0};
        heapPush(heap, node);
    }

    while (*returnSize < k && heap->size > 0) {
        Node cur = heapPop(heap);
        int i = cur.i, j = cur.j;

        result[*returnSize] = (int*)malloc(sizeof(int) * 2);
        result[*returnSize][0] = nums1[i];
        result[*returnSize][1] = nums2[j];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;

        if (j + 1 < nums2Size) {
            Node next = {nums1[i] + nums2[j + 1], i, j + 1};
            heapPush(heap, next);
        }
    }

    free(heap->data);
    free(heap);
    return result;
}

int main() {
    int nums1[] = {1, 7, 11};
    int nums2[] = {2, 4, 6};
    int k = 3;
    int returnSize;
    int* returnColumnSizes;

    int** result = kSmallestPairs(nums1, 3, nums2, 3, k, &returnSize, &returnColumnSizes);

    printf("Output pairs:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
    return 0;
}
