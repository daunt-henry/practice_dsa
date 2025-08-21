/*
Island Perimeter (LeetCode 463)

Given a 2D grid representing a map of land (1) and water (0),
return the perimeter of the island. There is exactly one island and no lakes inside.

Approach:
- Each land cell contributes 4 edges initially.
- For each adjacent pair of land cells (up or left), subtract 2 from total.
- Final perimeter = totalCells*4 - adjacentPairs*2

Complexity: O(m * n) time, O(1) space
*/

#include <stdio.h>
#include <stdlib.h>

int islandPerimeter(int** grid, int m, int* colSize) {
    int islands = 0, neighbors = 0;
    int n = colSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                islands++;
                if (i > 0 && grid[i - 1][j] == 1) neighbors++;
                if (j > 0 && grid[i][j - 1] == 1) neighbors++;
            }
        }
    }
    return islands * 4 - neighbors * 2;
}

int main(void) {
    int arr[4][6] = {
        {0,1,0,0,0,0},
        {1,1,1,0,0,0},
        {0,1,0,0,0,0},
        {0,1,0,0,0,0}
    };
    int* grid[4];
    for (int i = 0; i < 4; i++) grid[i] = arr[i];
    int cols = 6;

    int result = islandPerimeter(grid, 4, &cols);
    printf("Island Perimeter: %d  (expected 16)\n", result);
    return 0;
}
