/*
Problem:
Given a list of rectangles and points, return how many rectangles contain each point.
A rectangle [li, hi] contains point [xj, yj] if xj <= li and yj <= hi.

Approach:
- Group rectangle widths by their height.
- For each height, sort the widths for binary search.
- For each point, check all heights >= point.y.
- For each such height, binary search to count rectangles with width >= point.x.

Time Complexity:
- Preprocessing: O(N log N)
- Each query: O(100 * log M) where M is the number of widths at that height
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int countGreaterOrEqual(int *arr, int size, int val) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= val)
            right = mid;
        else
            left = mid + 1;
    }
    return size - left;
}

int* countRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize,
                     int** points, int pointsSize, int* pointsColSize, int* returnSize) {
    int* heights[101] = {0};
    int sizes[101] = {0};

    for (int i = 0; i < rectanglesSize; i++) {
        int width = rectangles[i][0];
        int height = rectangles[i][1];
        if (!heights[height]) {
            heights[height] = (int*)malloc(sizeof(int) * rectanglesSize);
        }
        heights[height][sizes[height]++] = width;
    }

    for (int i = 1; i <= 100; i++) {
        if (sizes[i]) {
            qsort(heights[i], sizes[i], sizeof(int), compare);
        }
    }

    int* res = (int*)malloc(sizeof(int) * pointsSize);
    *returnSize = pointsSize;

    for (int i = 0; i < pointsSize; i++) {
        int x = points[i][0];
        int y = points[i][1];
        int count = 0;
        for (int h = y; h <= 100; h++) {
            if (sizes[h]) {
                count += countGreaterOrEqual(heights[h], sizes[h], x);
            }
        }
        res[i] = count;
    }

    return res;
}

/*
Example:

Input:
rectangles = [[1,2],[2,3],[2,5]]
points = [[2,1],[1,4]]

Output:
[3,2]
*/
