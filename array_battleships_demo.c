/*
Battleships in a Board (LeetCode 419)

Given an m×n grid representing a board where each cell is either:
  - 'X' (part of a battleship), or
  - '.' (empty)

Each battleship is placed either horizontally or vertically (1×k or k×1),
and ships are separated by at least one empty cell—no adjacent ships.

Count the number of battleships without using extra space or modifying the board.

Key Insight:
A cell is the **leader** of a ship if:
  - It is an 'X'
  - Neither the cell above nor to the left is 'X'
Leader count = total number of ships.

Time: O(m·n), Space: O(1)
*/

#include <stdio.h>

int countBattleships(char** board, int m, int* nCols) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < nCols[i]; j++) {
            if (board[i][j] != 'X') continue;
            if (i > 0 && board[i - 1][j] == 'X') continue;
            if (j > 0 && board[i][j - 1] == 'X') continue;
            count++;
        }
    }
    return count;
}

int main(void) {
    char row0[] = "X..X";
    char row1[] = "...X";
    char row2[] = "...X";
    char* board[] = { row0, row1, row2 };
    int m = 3, nCols[] = {4, 4, 4};

    int result = countBattleships(board, m, nCols);
    printf("Number of battleships: %d  (expected 2)\n", result);

    char single[] = ".";
    char* board2[] = { single };
    int result2 = countBattleships(board2, 1, (int[]){1});
    printf("Number of battleships: %d  (expected 0)\n", result2);

    return 0;
}
