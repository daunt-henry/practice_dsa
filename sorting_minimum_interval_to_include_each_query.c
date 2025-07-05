/*
Problem: Minimum Interval to Include Each Query

You are given a 2D list of intervals and an array of queries. For each query,
find the length of the smallest interval that includes the query value. If no such
interval exists, return -1 for that query.

Example:
Input:
  intervals = [[1,4],[2,4],[3,6],[4,4]]
  queries = [2,3,4,5]
Output:
  [3,3,1,4]
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int left;
    int right;
} Interval;

typedef struct {
    int val;
    int index;
} Query;

int compareInterval(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    return i1->left - i2->left;
}

int compareQuery(const void* a, const void* b) {
    Query* q1 = (Query*)a;
    Query* q2 = (Query*)b;
    return q1->val - q2->val;
}

int minHeap[100001];
int right[100001];
int size = 0;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void push(int len, int r) {
    minHeap[size] = len;
    right[size] = r;
    int i = size++;
    while (i > 0 && (minHeap[i] < minHeap[(i - 1) / 2])) {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        swap(&right[i], &right[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void pop() {
    size--;
    minHeap[0] = minHeap[size];
    right[0] = right[size];
    int i = 0;
    while (2 * i + 1 < size) {
        int j = 2 * i + 1;
        if (j + 1 < size && minHeap[j + 1] < minHeap[j]) j++;
        if (minHeap[i] <= minHeap[j]) break;
        swap(&minHeap[i], &minHeap[j]);
        swap(&right[i], &right[j]);
        i = j;
    }
}

int topLen() {
    return minHeap[0];
}

int topRight() {
    return right[0];
}

int* minInterval(int** intervals, int intervalsSize, int* intervalsColSize,
                 int* queries, int queriesSize, int* returnSize) {
    Interval* ints = malloc(sizeof(Interval) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        ints[i].left = intervals[i][0];
        ints[i].right = intervals[i][1];
    }
    qsort(ints, intervalsSize, sizeof(Interval), compareInterval);

    Query* qs = malloc(sizeof(Query) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        qs[i].val = queries[i];
        qs[i].index = i;
    }
    qsort(qs, queriesSize, sizeof(Query), compareQuery);

    int* res = malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;
    int j = 0;
    size = 0;

    for (int i = 0; i < queriesSize; i++) {
        int qval = qs[i].val;
        while (j < intervalsSize && ints[j].left <= qval) {
            if (ints[j].right >= qval)
                push(ints[j].right - ints[j].left + 1, ints[j].right);
            j++;
        }

        while (size && topRight() < qval)
            pop();

        if (size == 0)
            res[qs[i].index] = -1;
        else
            res[qs[i].index] = topLen();
    }

    free(ints);
    free(qs);
    return res;
}
