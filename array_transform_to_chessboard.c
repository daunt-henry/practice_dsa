/*
 * Problem: Transform to Chessboard (LeetCode 782)
 *
 * Given an n×n binary board, you may swap any two rows or any two columns.
 * Return the minimum moves needed to make it "chessboard"—i.e., no two
 * adjacent (horizontal/vertical) cells share the same value—or -1 if impossible.
 *
 * Strategy:
 * 1. Any valid board must have exactly two row patterns (and col patterns),
 *    each being the bitwise complement of the other.
 * 2. Use bitmasks to represent the first row and column. Check all rows/columns
 *    match one of these two patterns.
 * 3. Count how many already match the first pattern. Use helper `calc_swaps`
 *    to determine minimum swaps to alternate patterns for both rows and columns.
 * 4. Return sum of row and column swaps, or -1 if either is impossible.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

static int calc_swaps(int mask, int cnt, int n) {
    int ones = __builtin_popcount(mask);
    if (n & 1) {
        if (abs(n - 2*ones) != 1 || abs(n - 2*cnt) != 1) return -1;
        if (ones == n / 2)
            return (n / 2) - __builtin_popcount(mask & 0xAAAAAAAA);
        else
            return ((n + 1) / 2) - __builtin_popcount(mask & 0x55555555);
    } else {
        if (ones != n / 2 || cnt != n / 2) return -1;
        int c0 = (n / 2) - __builtin_popcount(mask & 0xAAAAAAAA);
        int c1 = (n / 2) - __builtin_popcount(mask & 0x55555555);
        return c0 < c1 ? c0 : c1;
    }
}

int movesToChessboard(int** board, int boardSize, int* boardColSize) {
    int n = boardSize;
    int rowMask = 0, colMask = 0, maskAll = (1 << n) - 1;

    for (int i = 0; i < n; ++i) {
        rowMask |= board[0][i] << i;
        colMask |= board[i][0] << i;
    }

    int invRow = maskAll ^ rowMask;
    int invCol = maskAll ^ colMask;

    int sameRow = 0, sameCol = 0;
    for (int i = 0; i < n; ++i) {
        int rm = 0, cm = 0;
        for (int j = 0; j < n; ++j) {
            rm |= board[i][j] << j;
            cm |= board[j][i] << j;
        }
        if (rm != rowMask && rm != invRow) {
            printf("Invalid row at %d\n", i);
            return -1;
        }
        if (cm != colMask && cm != invCol) {
            printf("Invalid col at %d\n", i);
            return -1;
        }
        sameRow += (rm == rowMask);
        sameCol += (cm == colMask);
    }

    int rowSwaps = calc_swaps(rowMask, sameRow, n);
    int colSwaps = calc_swaps(colMask, sameCol, n);
    if (rowSwaps < 0 || colSwaps < 0) return -1;
    return rowSwaps + colSwaps;
}

int main(void) {
    int data[4][4] = {
        {0,1,1,0},
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1}
    };
    int* board[4];
    for (int i = 0; i < 4; i++) board[i] = data[i];
    int cols[4] = {4,4,4,4};

    int res = movesToChessboard(board, 4, cols);
    printf("Result: %d (expected: 2)\n", res);
    return 0;
}
