/*
Problem:
You are given a 2D list of `points`, where each point is [x, y], and a positive integer `w`.

You can draw a rectangle of width `w` (unlimited height) to cover as many points as possible,
but each rectangle must be aligned with the y-axis and span x to x+w.

Return the **minimum number of rectangles** needed to cover all points.

Only x-coordinate matters in the coverage.

Example Input:
points = [[2,1],[1,0],[3,3],[5,2]], w = 1

Expected Output:
3

Explanation:
You can cover:
- [1,0] and [2,1] with first rectangle (x in [1,2])
- [3,3] with second (x in [3,4])
- [5,2] with third (x in [5,6])
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minRectanglesToCoverPoints(int** points, int pointsSize, int* pointsColSize, int w) {
    int* x = (int*)malloc(sizeof(int) * pointsSize);
    for (int i = 0; i < pointsSize; ++i)
        x[i] = points[i][0];

    qsort(x, pointsSize, sizeof(int), cmp);

    int count = 0, i = 0;
    while (i < pointsSize) {
        int start = x[i];
        while (i < pointsSize && x[i] <= start + w)
            i++;
        count++;
    }

    free(x);
    return count;
}

int main() {
    int p1[] = {2, 1}, p2[] = {1, 0}, p3[] = {3, 3}, p4[] = {5, 2};
    int* points[] = {p1, p2, p3, p4};
    int cols[] = {2, 2, 2, 2};
    int w = 1;

    int result = minRectanglesToCoverPoints(points, 4, cols, w);
    printf("Minimum rectangles needed: %d\n", result);  // Output: 3
    return 0;
}
