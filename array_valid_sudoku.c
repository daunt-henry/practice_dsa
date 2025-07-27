/*
Valid Sudoku

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated.

Rules:
- Each row must contain the digits 1-9 without repetition.
- Each column must contain the digits 1-9 without repetition.
- Each of the 9 sub-boxes (3x3) must also contain the digits 1-9 without repetition.

Example Input:
[
  ['5','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]

Output: true

Filename: valid_sudoku.c
*/

#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') continue;
            int num = board[r][c] - '1';  // 0-based index
            int boxIndex = (r / 3) * 3 + (c / 3);

            if (rows[r][num] || cols[c][num] || boxes[boxIndex][num])
                return false;

            rows[r][num] = cols[c][num] = boxes[boxIndex][num] = true;
        }
    }

    return true;
}

// Sample test driver
int main() {
    char row0[] = {'5','3','.','.','7','.','.','.','.'};
    char row1[] = {'6','.','.','1','9','5','.','.','.'};
    char row2[] = {'.','9','8','.','.','.','.','6','.'};
    char row3[] = {'8','.','.','.','6','.','.','.','3'};
    char row4[] = {'4','.','.','8','.','3','.','.','1'};
    char row5[] = {'7','.','.','.','2','.','.','.','6'};
    char row6[] = {'.','6','.','.','.','.','2','8','.'};
    char row7[] = {'.','.','.','4','1','9','.','.','5'};
    char row8[] = {'.','.','.','.','8','.','.','7','9'};

    char* board[] = {row0, row1, row2, row3, row4, row5, row6, row7, row8};
    int colSize[] = {9,9,9,9,9,9,9,9,9};

    bool valid = isValidSudoku(board, 9, colSize);
    printf("The board is %s\n", valid ? "valid" : "invalid");

    return 0;
}
