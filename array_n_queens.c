/*
Problem: N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example:
Input: n = 4
Output: [
 [".Q..",
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSafe(char** board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solve(int row, int n, char** board, char*** result, int* returnSize, int** returnColumnSizes) {
    if (row == n) {
        result[*returnSize] = (char**)malloc(n * sizeof(char*));
        (*returnColumnSizes)[*returnSize] = n;

        for (int i = 0; i < n; i++) {
            result[*returnSize][i] = strdup(board[i]);
        }

        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(row + 1, n, board, result, returnSize, returnColumnSizes);
            board[row][col] = '.';
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int maxSolutions = 1000;

    char*** result = (char***)malloc(maxSolutions * sizeof(char**));
    *returnColumnSizes = (int*)malloc(maxSolutions * sizeof(int));

    char** board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
        board[i][n] = '\0';
    }

    solve(0, n, board, result, returnSize, returnColumnSizes);

    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);

    return result;
}

// Sample test
int main() {
    int n = 4;
    int returnSize;
    int* returnColumnSizes;
    char*** solutions = solveNQueens(n, &returnSize, &returnColumnSizes);

    printf("Number of solutions: %d\n\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < n; j++) {
            printf("%s\n", solutions[i][j]);
            free(solutions[i][j]);
        }
        free(solutions[i]);
        printf("\n");
    }

    free(solutions);
    free(returnColumnSizes);
    return 0;
}
