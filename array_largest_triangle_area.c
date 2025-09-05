/*
 * Problem: Largest Triangle Area (LeetCode 812)
 *
 * Given a list of points on a 2D plane, find the maximum area of any triangle
 * that can be formed by any three of those points.
 *
 * Approach:
 * - Use brute force with three nested loops to explore all combinations.
 * - Compute area via the cross-product formula:
 *     area = fabs( (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1) ) * 0.5
 *
 * Time Complexity: O(n^3)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdlib.h>

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double maxArea = 0.0;
    for (int i = 0; i < pointsSize; i++) {
        int x1 = points[i][0], y1 = points[i][1];
        for (int j = i + 1; j < pointsSize; j++) {
            int x2 = points[j][0], y2 = points[j][1];
            for (int k = j + 1; k < pointsSize; k++) {
                int x3 = points[k][0], y3 = points[k][1];
                double area = fabs(
                    (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)
                ) * 0.5;
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }
    return maxArea;
}

int main(void) {
    int ptsArr[][2] = {
        {0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}
    };
    int* points[5];
    for (int i = 0; i < 5; i++) points[i] = ptsArr[i];
    int cols[5] = {2, 2, 2, 2, 2};

    double result = largestTriangleArea(points, 5, cols);
    printf("Max triangle area: %.5f (expected: 2.00000)\n", result);

    return 0;
}
