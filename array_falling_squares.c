/*
Problem: Falling Squares (LeetCode 699)
URL: https://leetcode.com/problems/falling-squares/

We drop squares onto an infinite x-axis. Each square is specified by its left position and side length.
It stacks on top of any overlapping previously-dropped squares. After each drop, report the maximum stack height so far.

Approach:
- Track each fallen square's height in an array.
- For the current square, check all previous squares. If they overlap in x-range, compute stacked height.
- Keep a running maximum of the highest stack after each drop.

Time Complexity: O(n^2)  
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

// A brute-force O(n^2) simulation
int* fallingSquares(int** positions, int positionsSize, int* positionsColSize, int* returnSize) {
    int* ans = malloc(positionsSize * sizeof(int));
    int* heights = calloc(positionsSize, sizeof(int));
    int maxH = 0;
    
    for (int i = 0; i < positionsSize; i++) {
        int left = positions[i][0];
        int side = positions[i][1];
        int right = left + side;
        int h = side;

        for (int j = 0; j < i; j++) {
            int lj = positions[j][0];
            int rj = lj + positions[j][1];
            // Overlap condition
            if (left < rj && right > lj) {
                int stackH = heights[j] + side;
                if (stackH > h) h = stackH;
            }
        }
        heights[i] = h;
        if (h > maxH) maxH = h;
        ans[i] = maxH;
    }

    free(heights);
    *returnSize = positionsSize;
    return ans;
}

// ------------- Demo & Example Usage ---------------
int main(void) {
    int posArr[][2] = {{1,2}, {2,3}, {6,1}};
    int rows = 3;
    int cols = 2;
    int* positionsColSize = malloc(rows * sizeof(int));
    int** positions = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        positions[i] = malloc(cols * sizeof(int));
        positions[i][0] = posArr[i][0];
        positions[i][1] = posArr[i][1];
        positionsColSize[i] = cols;
    }

    int returnSize;
    int* result = fallingSquares(positions, rows, positionsColSize, &returnSize);

    printf("Result: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", result[i], i + 1 < returnSize ? ", " : "");
    }
    printf("] (expected: [2, 5, 5])\n");

    free(result);
    for (int i = 0; i < rows; i++) {
        free(positions[i]);
    }
    free(positions);
    free(positionsColSize);
    return 0;
}
