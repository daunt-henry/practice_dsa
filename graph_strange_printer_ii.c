/*
Strange Printer II

You are given a 2D array `targetGrid` of integers where each cell is colored. The printer can only print
rectangular submatrices in a single operation and must print one color at a time. It can overwrite colors.

Determine if it is possible to print the entire grid following these constraints.

Example:
Input: targetGrid = [[1,1,1],[3,1,3]]
Output: true

Explanation:
- Print 3 over corners (0,0)-(1,0) and (0,2)-(1,2)
- Then print 1 over the middle (0,1)-(1,1)
*/

#include <stdio.h>
#include <stdlib.h>

bool isPrintable(int** targetGrid, int targetGridSize, int* targetGridColSize){
    int colorSeen[61] = {0};
    int minRow[61], maxRow[61], minCol[61], maxCol[61];
    for (int i = 1; i <= 60; i++) {
        minRow[i] = minCol[i] = 100;
        maxRow[i] = maxCol[i] = -1;
    }

    for (int i = 0; i < targetGridSize; i++) {
        for (int j = 0; j < targetGridColSize[i]; j++) {
            int color = targetGrid[i][j];
            colorSeen[color] = 1;
            if (i < minRow[color]) minRow[color] = i;
            if (i > maxRow[color]) maxRow[color] = i;
            if (j < minCol[color]) minCol[color] = j;
            if (j > maxCol[color]) maxCol[color] = j;
        }
    }

    int changed;
    int count = 0;
    do {
        changed = 0;
        for (int color = 1; color <= 60; color++) {
            if (!colorSeen[color]) continue;
            int valid = 1;
            for (int i = minRow[color]; i <= maxRow[color] && valid; i++) {
                for (int j = minCol[color]; j <= maxCol[color]; j++) {
                    if (targetGrid[i][j] != 0 && targetGrid[i][j] != color) {
                        valid = 0;
                        break;
                    }
                }
            }
            if (valid) {
                for (int i = minRow[color]; i <= maxRow[color]; i++) {
                    for (int j = minCol[color]; j <= maxCol[color]; j++) {
                        if (targetGrid[i][j] == color)
                            targetGrid[i][j] = 0;
                    }
                }
                colorSeen[color] = 0;
                changed = 1;
                count++;
            }
        }
    } while (changed);

    for (int color = 1; color <= 60; color++) {
        if (colorSeen[color])
            return false;
    }
    return true;
}

int main() {
    int data[2][3] = {{1,1,1},{3,1,3}};
    int* grid[2] = {data[0], data[1]};
    int cols[2] = {3, 3};
    bool result = isPrintable(grid, 2, cols);
    printf("Is printable: %s\n", result ? "true" : "false");  // Output: true
    return 0;
}
