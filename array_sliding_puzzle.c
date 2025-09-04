/*
 * Problem: Sliding Puzzle (LeetCode 773)
 * On a 2×3 board with numbers 0–5 (0 is empty), find the least moves to reach:
 *   [[1,2,3],
 *    [4,5,0]]
 * Return -1 if unsolvable.
 *
 * Use BFS over state space (at most 720 states).
 * Represent board as 6-character string, e.g. "123450".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    const char* goal = "123450";
    char start[7] = {0};
    int idx = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            start[idx++] = '0' + board[i][j];

    if (strcmp(start, goal) == 0) return 0;

    // Simple queue + visited via brute comparison
    char q[720][7];
    int front = 0, back = 0;
    strcpy(q[back++], start);

    int moves = 0;
    const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (front < back) {
        moves++;
        int levelSize = back - front;
        while (levelSize--) {
            char curr[7];
            strcpy(curr, q[front++]);
            int zeroPos = strchr(curr, '0') - curr;
            int x = zeroPos / 3, y = zeroPos % 3;

            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d][0], ny = y + dirs[d][1];
                if (nx < 0 || nx >= 2 || ny < 0 || ny >= 3) continue;
                int np = nx * 3 + ny;
                char next[7];
                strcpy(next, curr);
                char tmp = next[zeroPos];
                next[zeroPos] = next[np];
                next[np] = tmp;

                if (strcmp(next, goal) == 0) {
                    return moves;
                }

                bool seen = false;
                for (int k = 0; k < back; k++) {
                    if (strcmp(q[k], next) == 0) { seen = true; break; }
                }
                if (!seen) strcpy(q[back++], next);
            }
        }
    }
    return -1;
}

int main(void) {
    int b1[2][3] = {{1,2,3},{4,0,5}};
    int* board1[2] = {b1[0], b1[1]};
    int col1[2] = {3,3};
    printf("Expected: 1, Got: %d\n", slidingPuzzle(board1, 2, col1));

    int b2[2][3] = {{1,2,3},{5,4,0}};
    int* board2[2] = {b2[0], b2[1]};
    printf("Expected: -1, Got: %d\n", slidingPuzzle(board2, 2, col1));

    int b3[2][3] = {{4,1,2},{5,0,3}};
    int* board3[2] = {b3[0], b3[1]};
    printf("Expected: 5, Got: %d\n", slidingPuzzle(board3, 2, col1));

    return 0;
}
