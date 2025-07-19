/*
Title: Max Value of Equation

Problem:
You are given an array points containing the coordinates of points on a 2D plane, 
sorted by the x-coordinate, and an integer k. Return the maximum value of the equation:
yi + yj + |xi - xj| 
such that |xi - xj| <= k and i < j.

Example:
Input: points = [[1,3],[2,0],[3,10],[4,2],[5,5]], k = 1
Output: 11
Explanation: i = 1, j = 2 -> 0 + 10 + |2 - 3| = 11

Constraints:
- 2 <= points.length <= 10^5
- points[i].length == 2
- -10^8 <= points[i][0], points[i][1] <= 10^8
- 0 <= k <= 2 * 10^8
- points are sorted in strictly increasing order by x
*/

#include <stdio.h>
#include <limits.h>

int findMaxValueOfEquation(int** points, int pointsSize, int* pointsColSize, int k) {
    int deque[pointsSize], front = 0, back = 0;
    int maxVal = INT_MIN;

    for (int i = 0; i < pointsSize; i++) {
        int x = points[i][0];
        int y = points[i][1];

        while (front < back && x - points[deque[front]][0] > k) front++;

        if (front < back) {
            int j = deque[front];
            int value = y + x + points[j][1] - points[j][0];
            if (value > maxVal) maxVal = value;
        }

        while (front < back && points[i][1] - points[i][0] >= points[deque[back - 1]][1] - points[deque[back - 1]][0])
            back--;

        deque[back++] = i;
    }

    return maxVal;
}

// Example usage
int main() {
    int arr[][2] = {{1,3},{2,0},{3,10},{4,2},{5,5}};
    int k = 1;
    int size = sizeof(arr) / sizeof(arr[0]);
    int* colSize = (int*)malloc(size * sizeof(int));
    int** points = (int**)malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++) {
        points[i] = (int*)malloc(2 * sizeof(int));
        points[i][0] = arr[i][0];
        points[i][1] = arr[i][1];
        colSize[i] = 2;
    }

    int result = findMaxValueOfEquation(points, size, colSize, k);
    printf("Maximum value of equation: %d\n", result);

    for (int i = 0; i < size; i++) free(points[i]);
    free(points);
    free(colSize);

    return 0;
}
