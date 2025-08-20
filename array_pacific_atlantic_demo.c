/*
Pacific Atlantic Water Flow (LeetCode 417)

Given an m×n matrix of heights, determine which cells allow water to flow
to both the Pacific Ocean (touching top/left edges) and the Atlantic Ocean
(touching right/bottom edges). Water flows only from higher or equal to
lower/equal elevation.

Approach: Reverse graph traversal using two DFS runs, one from each ocean’s edges.

Runtime: O(m×n), Space: O(m×n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int** heights, int m, int n, int i, int j, bool** vis) {
    vis[i][j] = true;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for (int d = 0; d < 4; d++) {
        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
        if (vis[ni][nj]) continue;
        if (heights[ni][nj] < heights[i][j]) continue;
        dfs(heights, m, n, ni, nj, vis);
    }
}

int** pacificAtlantic(int** heights, int m, int* colSize,
                      int* returnSize, int** returnColumnSizes) {
    bool** pac = malloc(m * sizeof(bool*));
    bool** atl = malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        pac[i] = calloc(colSize[0], sizeof(bool));
        atl[i] = calloc(colSize[0], sizeof(bool));
    }

    for (int i = 0; i < m; i++) {
        dfs(heights, m, colSize[0], i, 0, pac);
        dfs(heights, m, colSize[0], i, colSize[0]-1, atl);
    }
    for (int j = 0; j < colSize[0]; j++) {
        dfs(heights, m, colSize[0], 0, j, pac);
        dfs(heights, m, colSize[0], m-1, j, atl);
    }

    int cap = m * colSize[0];
    int** res = malloc(cap * sizeof(int*));
    *returnColumnSizes = malloc(cap * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < colSize[0]; j++)
            if (pac[i][j] && atl[i][j]) {
                res[*returnSize] = malloc(2 * sizeof(int));
                res[*returnSize][0] = i;
                res[*returnSize][1] = j;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }

    for (int i = 0; i < m; i++) {
        free(pac[i]); free(atl[i]);
    }
    free(pac); free(atl);

    return res;
}

int main(void) {
    int mat[5][5] = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    int* heights[5];
    for (int i = 0; i < 5; i++) heights[i] = mat[i];
    
    int returnSize, *returnCols;
    int** ans = pacificAtlantic(heights, 5, &(int){5}, &returnSize, &returnCols);

    printf("Cells that flow to both oceans:\n");
    for (int k = 0; k < returnSize; k++) {
        printf("[%d, %d]\n", ans[k][0], ans[k][1]);
        free(ans[k]);
    }
    free(ans);
    free(returnCols);
    return 0;
}
