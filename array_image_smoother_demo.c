/*
Image Smoother (LeetCode 661)

Given a grayscale image represented as a matrix `img`, smooth it by replacing
each cell with the floored average of itself and its valid 8-connected neighbors.
Handles edge cells by only including neighbors within bounds.

Approach:
For each cell (i, j):
  1. Sum values within the 3×3 grid centered at (i, j).
  2. Count how many valid cells were included.
  3. Assign floor(sum / count) to the corresponding result cell.

Time: O(m * n), Space: O(m * n)
*/

#include <stdio.h>
#include <stdlib.h>

int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    int m = imgSize, n = imgColSize[0];
    *returnSize = m;
    *returnColumnSizes = malloc(m * sizeof(int));
    int** ans = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        ans[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            int sum = 0, cnt = 0;
            for (int di = -1; di <= 1; di++)
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        sum += img[ni][nj];
                        cnt++;
                    }
                }
            ans[i][j] = sum / cnt;
        }
    }
    return ans;
}

int main(void) {
    int row0[] = {1, 1, 1};
    int row1[] = {1, 0, 1};
    int row2[] = {1, 1, 1};
    int* img[] = {row0, row1, row2};
    int colSize[] = {3, 3, 3}, returnSize, *returnColSizes;

    int** smoothed = imageSmoother(img, 3, colSize, &returnSize, &returnColSizes);

    printf("Smoothed Image:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColSizes[i]; j++) {
            printf("%d ", smoothed[i][j]);
        }
        printf("\n");
        free(smoothed[i]);
    }
    free(smoothed);
    free(returnColSizes);
    return 0;
}
