/*
Problem: Minimum Obstacle Removal to Reach Corner

You are given a 2D integer array grid. Each cell is either 0 (empty) or 1 (obstacle). 
You can move up, down, left, or right, and you can remove obstacles.

Return the minimum number of obstacles that need to be removed to reach the bottom-right cell.

Example:
Input:
    grid = [[0,1,1],
            [1,1,0],
            [1,1,0]]

Output:
    2
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 1000000

typedef struct {
    int x, y, cost;
} Node;

typedef struct {
    Node heap[MAXN];
    int size;
} MinHeap;

void swap(Node* a, Node* b) {
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(MinHeap* h, Node n) {
    int i = h->size++;
    h->heap[i] = n;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->heap[p].cost <= h->heap[i].cost) break;
        swap(&h->heap[p], &h->heap[i]);
        i = p;
    }
}

Node pop(MinHeap* h) {
    Node top = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < h->size && h->heap[l].cost < h->heap[smallest].cost) smallest = l;
        if (r < h->size && h->heap[r].cost < h->heap[smallest].cost) smallest = r;
        if (smallest == i) break;
        swap(&h->heap[i], &h->heap[smallest]);
        i = smallest;
    }
    return top;
}

int minimumObstacles(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int** dist = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) dist[i][j] = INT_MAX;
    }

    MinHeap h = {.size = 0};
    dist[0][0] = 0;
    push(&h, (Node){0, 0, 0});

    while (h.size > 0) {
        Node curr = pop(&h);
        int x = curr.x, y = curr.y, c = curr.cost;
        if (x == m - 1 && y == n - 1) break;
        if (c > dist[x][y]) continue;
        for (int d = 0; d < 4; d++) {
            int nx = x + dir[d][0], ny = y + dir[d][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int nc = c + grid[nx][ny];
                if (nc < dist[nx][ny]) {
                    dist[nx][ny] = nc;
                    push(&h, (Node){nx, ny, nc});
                }
            }
        }
    }

    int result = dist[m - 1][n - 1];
    for (int i = 0; i < m; i++) free(dist[i]);
    free(dist);
    return result;
}

int main() {
    int arr[3][3] = {
        {0, 1, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    int* grid[3];
    int gridColSize[3];
    for (int i = 0; i < 3; i++) {
        grid[i] = arr[i];
        gridColSize[i] = 3;
    }

    int result = minimumObstacles(grid, 3, gridColSize);
    printf("Output: %d\n", result);  // Output: 2
    return 0;
}
