/*
Problem: Flood Fill (LeetCode 733)
URL: https://leetcode.com/problems/flood-fill/

Perform a "paint bucket" fill starting from pixel (sr, sc)—change all connected
pixels of the same starting color to the new color.

Approach: Depth-First Search (DFS) Recursion
1. Record the original color `origColor = image[sr][sc]`.
2. If `origColor == newColor`, do nothing (prevents infinite recursion).
3. Define `dfs(r, c)`:
   - Check boundaries and whether `image[r][c]` matches `origColor`.
   - Recolor it and recursively call `dfs` on up, down, left, and right neighbors.
4. Return the modified image.

Time Complexity: O(m × n)  
Space Complexity: O(m × n) recursion stack in worst case
*/

#include <stdio.h>
#include <stdlib.h>

static int origColor, newColor, R, C;

void dfs(int** image, int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (image[r][c] != origColor) return;
    image[r][c] = newColor;
    dfs(image, r + 1, c);
    dfs(image, r - 1, c);
    dfs(image, r, c + 1);
    dfs(image, r, c - 1);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    R = imageSize;
    C = imageColSize[0];
    origColor = image[sr][sc];
    newColor = color;
    if (origColor != newColor) {
        dfs(image, sr, sc);
    }
    *returnSize = R;
    *returnColumnSizes = imageColSize;
    return image;
}

// --------------- Test Driver ----------------
int main(void) {
    int data[][3] = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int rows = 3, cols = 3;
    int** image = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        image[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            image[i][j] = data[i][j];
        }
    }

    int imageColSize[] = {cols, cols, cols};
    int returnSize, *returnColSize;
    int** res = floodFill(image, rows, imageColSize, 1, 1, 2, &returnSize, &returnColSize);

    printf("Flood-filled image:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColSize[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);

    return 0;
}
