/*
 * Problem: Bricks Falling When Hit (LeetCode 803)
 *
 * We must compute how many bricks fall after each hit.
 * Strategy: Process hits in reverse using Union-Find with a "ceiling" node.
 *
 * Steps:
 * 1. Copy the grid and apply all hits.
 * 2. Build DSU: connect adjacent bricks and top-row bricks to the ceiling.
 * 3. Reverse the hits: restore bricks one by one, union them, and count how many newly connect to ceiling.
 * 4. The difference (minus one) gives the number of bricks that fell at that hit.
 * 5. Return results in original order.
 */

#include <stdio.h>
#include <stdlib.h>

// DSU data
static int *parent, *sz, rows, cols;
static int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};

static int findp(int x) {
    return parent[x] == x ? x : (parent[x] = findp(parent[x]));
}
static void unionp(int x, int y) {
    int rx = findp(x), ry = findp(y);
    if (rx != ry) {
        parent[ry] = rx;
        sz[rx] += sz[ry];
    }
}

int* hitBricks(int** grid, int gridSize, int* gridColSize,
               int** hits, int hitsSize, int* hitsColSize, int* returnSize) {
    rows = gridSize; cols = gridColSize[0];
    int total = rows * cols, roof = total;
    parent = malloc((total + 1) * sizeof(int));
    sz = malloc((total + 1) * sizeof(int));
    for (int i = 0; i <= total; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    // Copy grid and apply all hits
    int** g = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        g[i] = malloc(cols * sizeof(int));
        memcpy(g[i], grid[i], cols * sizeof(int));
    }
    for (int h = 0; h < hitsSize; h++) {
        g[hits[h][0]][hits[h][1]] = 0;
    }

    // Initial unions
    for (int j = 0; j < cols; j++) {
        if (g[0][j] == 1) unionp(j, roof);
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (g[i][j] == 1) {
                int idx = i * cols + j;
                if (g[i-1][j] == 1) unionp(idx, (i - 1) * cols + j);
                if (j > 0 && g[i][j-1] == 1) unionp(idx, i * cols + j - 1);
            }
        }
    }

    int* result = calloc(hitsSize, sizeof(int));

    for (int h = hitsSize - 1; h >= 0; h--) {
        int r = hits[h][0], c = hits[h][1];
        if (grid[r][c] == 0) { result[h] = 0; continue; }

        int before = sz[findp(roof)];
        g[r][c] = 1;
        int idx = r * cols + c;
        if (r == 0) unionp(idx, roof);
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && g[nr][nc] == 1)
                unionp(idx, nr * cols + nc);
        }
        int after = sz[findp(roof)];
        result[h] = (after > before) ? after - before - 1 : 0;
    }

    *returnSize = hitsSize;
    for (int i = 0; i < rows; i++) free(g[i]);
    free(g);
    free(parent);
    free(sz);
    return result;
}

#ifdef DEMO
int main(void) {
    int grid_data[2][4] = {{1,0,0,0}, {1,1,1,0}};
    int hits_data[1][2] = {{1,0}};
    int* grid[2] = {grid_data[0], grid_data[1]};
    int* hits[1] = {hits_data[0]};
    int gridCols[2] = {4,4}, hitsCols[1] = {2};

    int retSize;
    int* ans = hitBricks(grid, 2, gridCols, hits, 1, hitsCols, &retSize);
    printf("Bricks fallen: %d (expected: 2)\n", ans[0]);
    free(ans);
    return 0;
}
#endif
