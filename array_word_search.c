/*
Problem: Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
where "adjacent" cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example:
Input:
  board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  }
  word = "ABCCED"
Output: true

Filename: word_search.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int boardSize, int* boardColSize, int row, int col, char* word, int index) {
    if (word[index] == '\0') return true;
    if (row < 0 || col < 0 || row >= boardSize || col >= boardColSize[row] || board[row][col] != word[index])
        return false;

    char temp = board[row][col];
    board[row][col] = '*';

    bool found = dfs(board, boardSize, boardColSize, row + 1, col, word, index + 1) ||
                 dfs(board, boardSize, boardColSize, row - 1, col, word, index + 1) ||
                 dfs(board, boardSize, boardColSize, row, col + 1, word, index + 1) ||
                 dfs(board, boardSize, boardColSize, row, col - 1, word, index + 1);

    board[row][col] = temp;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardColSize[i]; ++j) {
            if (dfs(board, boardSize, boardColSize, i, j, word, 0)) return true;
        }
    }
    return false;
}

// Sample driver code for testing
int main() {
    char b0[] = {'A','B','C','E'};
    char b1[] = {'S','F','C','S'};
    char b2[] = {'A','D','E','E'};
    char* board[] = {b0, b1, b2};
    int boardColSize[] = {4, 4, 4};
    char word[] = "ABCCED";

    bool found = exist(board, 3, boardColSize, word);
    printf("Word found? %s\n", found ? "true" : "false");

    return 0;
}
