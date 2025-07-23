/*
Min Cost to Connect All Points

You are given an array `points` representing integer coordinates of some points on a 2D-plane,
where points[i] = [xi, yi]. The cost of connecting two points is the Manhattan distance between them.

Return the minimum cost to connect all points. All points are connected if there is exactly one simple path between any two points.

Example:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20

Explanation:
One possible MST connects all points with minimal total distance of 20.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int u, v, cost;
} Edge;

int find(int* parent, int x) {
    if (parent[x] != x) 
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int* parent, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY)
        parent[rootY] = rootX;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
    int edgeCount = pointsSize * (pointsSize - 1) / 2;
    Edge* edges = malloc(sizeof(Edge) * edgeCount);
    int idx = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges[idx++] = (Edge){i, j, cost};
        }
    }

    int cmp(const void* a, const void* b) {
        return ((Edge*)a)->cost - ((Edge*)b)->cost;
    }
    qsort(edges, edgeCount, sizeof(Edge), cmp);

    int* parent = malloc(sizeof(int) * pointsSize);
    for (int i = 0; i < pointsSize; i++) parent[i] = i;

    int totalCost = 0, edgesUsed = 0;
    for (int i = 0; i < edgeCount && edgesUsed < pointsSize - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int cost = edges[i].cost;
        if (find(parent, u) != find(parent, v)) {
            unionSet(parent, u, v);
            totalCost += cost;
            edgesUsed++;
        }
    }

    free(edges);
    free(parent);
    return totalCost;
}

int main() {
    int data[5][2] = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    int* points[5];
    for (int i = 0; i < 5; i++) points[i] = data[i];
    int colsize = 2;
    int result = minCostConnectPoints(points, 5, &colsize);
    printf("Minimum cost to connect all points: %d\n", result);  // Output: 20
    return 0;
}
