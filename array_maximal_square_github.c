/*
Problem: Maximal Square

Given a 2D binary matrix filled with '0's and '1's, find the largest square 
containing only 1's and return its area.

Example:
Input:
matrix = [["1","0","1","0","0"],
          ["1","0","1","1","1"],
          ["1","1","1","1","1"],
          ["1","0","0","1","0"]]

Output: 4
*/

#include <stdio.h>
#include <stdlib.h>

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return 0;
    
    int rows = matrixSize, cols = matrixColSize[0];
    int** dp = (int**)malloc(sizeof(int*) * (rows + 1));
    for (int i = 0; i <= rows; i++) {
        dp[i] = (int*)calloc(cols + 1, sizeof(int));
    }

    int maxSide = 0;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = 1 + fmin(dp[i - 1][j], fmin(dp[i][j - 1], dp[i - 1][j - 1]));
                if (dp[i][j] > maxSide) maxSide = dp[i][j];
            }
        }
    }

    for (int i = 0; i <= rows; i++) free(dp[i]);
    free(dp);
    return maxSide * maxSide;
}

int main() {
    char* matrix[] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };
    int cols = 5;
    int result = maximalSquare(matrix, 4, &cols);
    printf("Output: %d\n", result);  // Output: 4
    return 0;
}
