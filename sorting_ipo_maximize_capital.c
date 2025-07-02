/*
Problem: IPO

Description:
You are given k and initial capital w, and lists of profits[] and capital[].
Each project requires a minimum capital and gives a profit.
Pick up to k projects to maximize your final capital.

Approach:
1. Sort all projects by capital.
2. Use max-heap to choose the most profitable project you can afford.
3. Repeat k times or until no projects can be taken.

Time: O(n log n + k log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capital;
    int profit;
} Project;

int compare(const void* a, const void* b) {
    return ((Project*)a)->capital - ((Project*)b)->capital;
}

void push(int* heap, int* size, int value) {
    int i = (*size)++;
    heap[i] = value;
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        int tmp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}

int pop(int* heap, int* size) {
    int result = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0;
    while (2 * i + 1 < *size) {
        int maxChild = 2 * i + 1;
        if (maxChild + 1 < *size && heap[maxChild + 1] > heap[maxChild]) {
            maxChild++;
        }
        if (heap[i] >= heap[maxChild]) break;
        int tmp = heap[i];
        heap[i] = heap[maxChild];
        heap[maxChild] = tmp;
        i = maxChild;
    }
    return result;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    Project* projects = malloc(sizeof(Project) * profitsSize);
    for (int i = 0; i < profitsSize; i++) {
        projects[i].capital = capital[i];
        projects[i].profit = profits[i];
    }

    qsort(projects, profitsSize, sizeof(Project), compare);

    int* heap = malloc(sizeof(int) * profitsSize);
    int heapSize = 0;
    int i = 0;

    while (k--) {
        while (i < profitsSize && projects[i].capital <= w) {
            push(heap, &heapSize, projects[i].profit);
            i++;
        }

        if (heapSize == 0) break;
        w += pop(heap, &heapSize);
    }

    free(projects);
    free(heap);
    return w;
}

// Test
int main() {
    int k = 2, w = 0;
    int profits[] = {1, 2, 3};
    int capital[] = {0, 1, 1};
    int n = sizeof(profits) / sizeof(profits[0]);

    int finalCapital = findMaximizedCapital(k, w, profits, n, capital, n);
    printf("Final capital after selecting projects: %d\n", finalCapital);
    return 0;
}

/*
========= OUTPUT =========
Final capital after selecting projects: 4
==========================
*/
