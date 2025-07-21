/*
Title: Count Submatrices With All Ones

Description:
  Given a m x n binary matrix mat, return the number of submatrices that have all ones.

Example:
  Input:
    mat = [
      [1,0,1],
      [1,1,0],
      [1,1,0]
    ]
  Output: 13

Explanation:
  There are 6 single cell 1s, 4 horizontal 1x2, 1 horizontal 1x3, and 2 vertical 2x1 or 3x1 submatrices.

Approach:
  1. Preprocess each row to store counts of consecutive 1s ending at each cell.
  2. For each column and row from bottom to top, find the minimum width and accumulate possible rectangles.
*/

#include <stdio.h>
#include <stdlib.h>

int numSubmat(int** mat, int matSize, int* matColSize){
    int rows = matSize, cols = *matColSize;
    int result = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (mat[i][j]) {
                mat[i][j] += mat[i][j - 1];
            }
        }
    }

    for (int j = 0; j < rows; j++) {
        for (int k = 0; k < cols; k++) {
            int minWidth = mat[j][k];
            for (int l = j; l >= 0 && minWidth; l--) {
                if (mat[l][k] == 0) break;
                if (mat[l][k] < minWidth) minWidth = mat[l][k];
                result += minWidth;
            }
        }
    }

    return result;
}

int main() {
    int r = 3, c = 3;
    int** mat = (int**)malloc(sizeof(int*) * r);
    int matColSize = c;

    int data[3][3] = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };

    for (int i = 0; i < r; i++) {
        mat[i] = (int*)malloc(sizeof(int) * c);
        for (int j = 0; j < c; j++) {
            mat[i][j] = data[i][j];
        }
    }

    int result = numSubmat(mat, r, &matColSize);
    printf("Number of submatrices with all ones: %d\n", result);

    for (int i = 0; i < r; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}
