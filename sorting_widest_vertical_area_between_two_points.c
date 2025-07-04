/*
Widest Vertical Area Between Two Points Containing No Points

Problem:
Given n points on a 2D plane, return the widest vertical area between two points such that no other points lie in between them.

Approach:
- Sort the points by their x-coordinates.
- Traverse and find the maximum difference (gap) between consecutive x-coordinates.

Time Complexity: O(n log n) due to sorting
Space Complexity: O(1)

Example:
Input: [[8,7],[9,9],[7,4],[9,7]]
Output: 1
*/

#include <stdlib.h>

// Comparator to sort points by x-coordinate
int compare(const void* a, const void* b) {
    int x = (*(int **)a)[0];
    int y = (*(int **)b)[0];
    return x - y;
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize){
    qsort(points, pointsSize, sizeof(int*), compare);

    int maxGap = 0;
    for (int i = 1; i < pointsSize; i++) {
        int gap = points[i][0] - points[i - 1][0];
        if (gap > maxGap) {
            maxGap = gap;
        }
    }

    return maxGap;
}
