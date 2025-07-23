/*
Minimum Cost to Make at Least One Valid Path in a Grid

You are given an m x n grid where each cell has a direction from 1 to 4:
1 → right, 2 → left, 3 → down, 4 → up.

You can modify the direction of any cell at a cost of 1. A valid path starts at (0,0)
and follows directions to reach (m-1,n-1).

Return the minimum total cost to make at least one valid path.

Example:
Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
Output: 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DIRS 4

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

typedef struct {
    int x, y, cost;
} Node;

typedef struct {
    Node *data;
    int front, rear, size, capacity;
} Deque;

Deque* createDeque(int cap) {
    Deque *dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (Node*)malloc(sizeof(Node) * cap);
    dq->front = dq->rear = dq->size = 0;
    dq->capacity = cap;
    return dq;
}

bool isEmpty(Deque* dq) {
    return dq->size == 0;
}

void pushFront(Deque* dq, Node val) {
    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->data[dq->front] = val;
    dq->size++;
}

void pushBack(Deque* dq, Node val) {
    dq->data[dq->rear] = val;
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->size++;
}

Node popFront(Deque* dq) {
    Node val = dq->data[dq->front];
    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
    return val;
}

int minCost(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0];
    int** dist = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        dist[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) dist[i][j] = 1e9;
    }

    Deque* dq = createDeque(m * n * 2);
    dist[0][0] = 0;
    pushFront(dq, (Node){0, 0, 0});

    while (!isEmpty(dq)) {
        Node cur = popFront(dq);
        for (int d = 0; d < DIRS; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            int cost = (grid[cur.x][cur.y] == d + 1) ? 0 : 1;
            if (dist[nx][ny] > dist[cur.x][cur.y] + cost) {
                dist[nx][ny] = dist[cur.x][cur.y] + cost;
                if (cost == 0) pushFront(dq, (Node){nx, ny, dist[nx][ny]});
                else pushBack(dq, (Node){nx, ny, dist[nx][ny]});
            }
        }
    }

    int result = dist[m - 1][n - 1];
    for (int i = 0; i < m; i++) free(dist[i]);
    free(dist);
    free(dq->data);
    free(dq);
    return result;
}

int main() {
    int gridArr[3][3] = {{1, 1, 3}, {3, 2, 2}, {1, 1, 4}};
    int* grid[3];
    for (int i = 0; i < 3; i++) grid[i] = gridArr[i];
    int colSize = 3;
    printf("Minimum cost: %d\n", minCost(grid, 3, &colSize)); // Output: 0
    return 0;
}
