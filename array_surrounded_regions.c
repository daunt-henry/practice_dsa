/*
Problem: Surrounded Regions

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
Input:
[
  ['X','X','X','X'],
  ['X','O','O','X'],
  ['X','X','O','X'],
  ['X','O','X','X']
]

Output:
[
  ['X','X','X','X'],
  ['X','X','X','X'],
  ['X','X','X','X'],
  ['X','O','X','X']
]
*/

#include <stdio.h>

void dfs(char** board, int boardSize, int boardColSize, int i, int j) {
    if (i < 0 || j < 0 || i >= boardSize || j >= boardColSize || board[i][j] != 'O')
        return;

    board[i][j] = 'T'; // Temporarily mark safe 'O's

    dfs(board, boardSize, boardColSize, i + 1, j);
    dfs(board, boardSize, boardColSize, i - 1, j);
    dfs(board, boardSize, boardColSize, i, j + 1);
    dfs(board, boardSize, boardColSize, i, j - 1);
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0 || *boardColSize == 0) return;

    int cols = *boardColSize;

    for (int i = 0; i < boardSize; i++) {
        dfs(board, boardSize, cols, i, 0);
        dfs(board, boardSize, cols, i, cols - 1);
    }
    for (int j = 0; j < cols; j++) {
        dfs(board, boardSize, cols, 0, j);
        dfs(board, boardSize, cols, boardSize - 1, j);
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == 'T') board[i][j] = 'O';
        }
    }
}

// Test driver not included due to 2D dynamic array complexity in C.
// Can be added if required.
