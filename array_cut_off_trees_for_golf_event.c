/*
Problem: Cut Off Trees for Golf Event (LeetCode 675)
URL: https://leetcode.com/problems/cut-off-trees-for-golf-event/

Given an m x n grid 'forest':
- 0: obstacle
- 1: empty space (walkable)
- >1: tree with unique height (walkable)

You start at (0,0). You must cut all trees in ascending order of height.
Cutting turns the tree cell into 1. Return the minimum steps needed, or -1 if impossible.

Approach:
1) Gather all trees into an array of (height, row, col), then sort by height.
2) Iterate through each tree, using BFS to find minimum steps from current position.
3) Sum steps; if any tree is unreachable, return -1.

Complexity: O((mn) * mn) = O(m^2 n^2), due to BFS for each tree.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int h, r, c;
} Tree;

int cmpTree(const void* a, const void* b) {
    return ((Tree*)a)->h - ((Tree*)b)->h;
}

int bfs(int** forest, int m, int n, int sr, int sc, int tr, int tc) {
    if (sr == tr && sc == tc) return 0;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int** visited = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        visited[i] = calloc(n, sizeof(int));
    }
    int* qr = malloc(m * n * sizeof(int));
    int* qc = malloc(m * n * sizeof(int));
    int front = 0, back = 0;
    qr[back] = sr; qc[back++] = sc;
    visited[sr][sc] = 1;
    int steps = 0;

    while (front < back) {
        int sz = back - front;
        while (sz--) {
            int r = qr[front], c = qc[front++];
            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d][0], nc = c + dirs[d][1];
                if (nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && forest[nr][nc] > 0) {
                    if (nr == tr && nc == tc) {
                        for(int i=0;i<m;i++) free(visited[i]);
                        free(visited); free(qr); free(qc);
                        return steps + 1;
                    }
                    visited[nr][nc] = 1;
                    qr[back] = nr; qc[back++] = nc;
                }
            }
        }
        steps++;
    }

    for(int i=0;i<m;i++) free(visited[i]);
    free(visited); free(qr); free(qc);
    return -1;
}

int cutOffTree(int** forest, int forestSize, int* forestColSize) {
    int m = forestSize, n = forestColSize[0];
    Tree* trees = malloc(m * n * sizeof(Tree));
    int count = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (forest[i][j] > 1)
                trees[count++] = (Tree){forest[i][j], i, j};

    qsort(trees, count, sizeof(Tree), cmpTree);

    int sr = 0, sc = 0, ans = 0;
    for (int i = 0; i < count; i++) {
        int steps = bfs(forest, m, n, sr, sc, trees[i].r, trees[i].c);
        printf("Moving from (%d,%d) to (%d,%d) takes %d steps\n",
               sr, sc, trees[i].r, trees[i].c, steps);
        if (steps < 0) {
            printf("Cannot reach tree #%d at height %d. Returning -1.\n", i+1, trees[i].h);
            free(trees);
            return -1;
        }
        ans += steps;
        sr = trees[i].r;
        sc = trees[i].c;
        forest[sr][sc] = 1;
    }
    printf("All trees cut. Total steps: %d\n", ans);
    free(trees);
    return ans;
}

int main() {
    int m = 3, n = 3;
    int colSize[] = {3,3,3};
    int row0[] = {1,2,3};
    int row1[] = {0,0,4};
    int row2[] = {7,6,5};
    int* forest[] = {row0, row1, row2};

    printf("Result: %d\n", cutOffTree(forest, m, colSize));  // Expected: 6

    return 0;
}
