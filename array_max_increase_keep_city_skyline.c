/*
 * Problem: Max Increase to Keep City Skyline (LeetCode 807)
 *
 * You are given an n×n grid where each cell is a building height.
 * You may increase heights arbitrarily, but the skyline (max per row and column)
 * must remain unchanged. Return the total sum of all height increases.
 */

#include <stdio.h>
#include <stdlib.h>

int maxIncreaseKeepingSkyline(int** grid, int n, int* gridColSize) {
    int* rowMax = calloc(n, sizeof(int));
    int* colMax = calloc(n, sizeof(int));

    // Determine row and column skylines
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int h = grid[i][j];
            if (h > rowMax[i]) rowMax[i] = h;
            if (h > colMax[j]) colMax[j] = h;
        }
    }

    int total = 0;
    // Calculate total possible increase per building
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int maxAllowed = rowMax[i] < colMax[j] ? rowMax[i] : colMax[j];
            total += maxAllowed - grid[i][j];
        }
    }

    free(rowMax);
    free(colMax);
    return total;
}

int main(void) {
    int data[4][4] = {
        {3, 0, 8, 4},
        {2, 4, 5, 7},
        {9, 2, 6, 3},
        {0, 3, 1, 0}
    };
    int n = 4;
    int* grid[4];
    for (int i = 0; i < 4; i++) grid[i] = data[i];
    int cols[4] = {4,4,4,4};

    int result = maxIncreaseKeepingSkyline(grid, n, cols);
    printf("Max total increase: %d (expected: 35)\n", result);

    return 0;
}
