/*
Problem:
Find the k points closest to origin (0, 0) using Euclidean distance.

Approach:
- Sort points based on distance² from origin (to avoid sqrt).
- Return first k points after sorting.

Time: O(n log n) for sorting
Space: O(k) for result
*/

#include <stdio.h>
#include <stdlib.h>

int distance(int* point) {
    return point[0] * point[0] + point[1] * point[1];
}

int cmp(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    return distance(p1) - distance(p2);
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    qsort(points, pointsSize, sizeof(int*), cmp);

    int** result = (int**)malloc(sizeof(int*) * k);
    *returnColumnSizes = (int*)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++) {
        result[i] = (int*)malloc(sizeof(int) * 2);
        result[i][0] = points[i][0];
        result[i][1] = points[i][1];
        (*returnColumnSizes)[i] = 2;
    }

    *returnSize = k;
    return result;
}

// Test
int main() {
    int arr[3][2] = {{1, 3}, {-2, 2}, {2, -2}};
    int* points[3];
    for (int i = 0; i < 3; i++) points[i] = arr[i];
    int pointsColSize[3] = {2, 2, 2};

    int k = 2;
    int returnSize;
    int* returnColumnSizes;

    int** result = kClosest(points, 3, pointsColSize, k, &returnSize, &returnColumnSizes);

    printf("K Closest Points:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
    return 0;
}

/*
========= OUTPUT =========
K Closest Points:
[-2, 2]
[2, -2]
==========================
*/
