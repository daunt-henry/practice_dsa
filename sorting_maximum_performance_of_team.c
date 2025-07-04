/*
Maximum Performance of a Team

Problem:
- Select up to k engineers with given speed and efficiency.
- Performance = sum of speeds * minimum efficiency among selected.

Approach:
- Sort engineers by efficiency descending.
- Maintain a min-heap of speeds to keep the k highest.
- At each step, calculate performance using current efficiency.

Time: O(n log k)
Space: O(k)

Example:
Input:
  n = 6
  speed =      [2,10,3,1,5,8]
  efficiency = [5, 4,3,9,7,2]
  k = 2

Output: 60
*/

#include <stdlib.h>
#define MOD 1000000007

typedef struct {
    int speed;
    int efficiency;
} Engineer;

int cmpEfficiency(const void *a, const void *b) {
    return ((Engineer *)b)->efficiency - ((Engineer *)a)->efficiency;
}

void push(int *heap, int *heapSize, int val) {
    heap[(*heapSize)++] = val;
    int i = *heapSize - 1;
    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        int tmp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}

int pop(int *heap, int *heapSize) {
    int top = heap[0];
    heap[0] = heap[--(*heapSize)];
    int i = 0;
    while (1) {
        int smallest = i, l = 2*i + 1, r = 2*i + 2;
        if (l < *heapSize && heap[l] < heap[smallest]) smallest = l;
        if (r < *heapSize && heap[r] < heap[smallest]) smallest = r;
        if (smallest == i) break;
        int tmp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = tmp;
        i = smallest;
    }
    return top;
}

int maxPerformance(int n, int* speed, int speedSize, int* efficiency, int efficiencySize, int k) {
    Engineer *engineers = malloc(n * sizeof(Engineer));
    for (int i = 0; i < n; i++) {
        engineers[i].speed = speed[i];
        engineers[i].efficiency = efficiency[i];
    }

    qsort(engineers, n, sizeof(Engineer), cmpEfficiency);

    long sumSpeed = 0, maxPerf = 0;
    int *heap = malloc(k * sizeof(int));
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        if (heapSize == k) {
            sumSpeed -= pop(heap, &heapSize);
        }
        push(heap, &heapSize, engineers[i].speed);
        sumSpeed += engineers[i].speed;
        long perf = sumSpeed * engineers[i].efficiency;
        if (perf > maxPerf) maxPerf = perf;
    }

    free(engineers);
    free(heap);
    return maxPerf % MOD;
}
