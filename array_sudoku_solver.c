/*
Problem: Sudoku Solver


Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes.

The '.' character indicates empty cells.

Example:
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]

Output:
Fully filled valid board.
*/

#include <stdio.h>
#include <stdbool.h>

bool isValid(char** board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;
        if (board[row][i] == c) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    return true;
}

bool solve(char** board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, row, col, c)) {
                        board[row][col] = c;
                        if (solve(board)) return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}
