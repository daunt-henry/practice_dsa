/*
Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

Problem:
- Given a graph (n nodes, edge list), return:
  1. Critical edges: removing it increases MST cost.
  2. Pseudo-critical edges: part of at least one valid MST.

Approach:
- Use Kruskal’s algorithm with Disjoint Set Union (DSU).
- For each edge:
  - Try removing it → check if MST cost increases.
  - Try including it forcibly → check if MST cost same as original.

Time: O(E^2 * α(N)) due to repeated MST builds
Space: O(E + N)

Example:
Input: n = 5, edges = [[0,1,1],[0,2,1],[1,2,1],[1,3,1],[2,3,1],[3,4,1]]
Output: [[0,1],[2,3,4]]
*/

#include <stdlib.h>

typedef struct {
    int u, v, w, index;
} Edge;

int cmpEdge(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

int unionSets(int* parent, int* rank, int x, int y) {
    int xr = find(parent, x);
    int yr = find(parent, y);
    if (xr == yr) return 0;
    if (rank[xr] < rank[yr])
        parent[xr] = yr;
    else if (rank[xr] > rank[yr])
        parent[yr] = xr;
    else {
        parent[yr] = xr;
        rank[xr]++;
    }
    return 1;
}

int kruskal(int n, Edge* edges, int edgesSize, int include, int exclude) {
    int* parent = malloc(sizeof(int) * n);
    int* rank = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) parent[i] = i;

    int cost = 0, count = 0;

    if (include != -1) {
        Edge e = edges[include];
        if (unionSets(parent, rank, e.u, e.v)) {
            cost += e.w;
            count++;
        }
    }

    for (int i = 0; i < edgesSize; i++) {
        if (i == exclude) continue;
        if (unionSets(parent, rank, edges[i].u, edges[i].v)) {
            cost += edges[i].w;
            count++;
        }
    }

    free(parent);
    free(rank);
    return count == n - 1 ? cost : 1e9;
}

int** findCriticalAndPseudoCriticalEdges(int n, int** inputEdges, int edgesSize, int* edgesColSize, int* returnSize, int** returnColumnSizes) {
    Edge* edges = malloc(sizeof(Edge) * edgesSize);
    for (int i = 0; i < edgesSize; i++) {
        edges[i].u = inputEdges[i][0];
        edges[i].v = inputEdges[i][1];
        edges[i].w = inputEdges[i][2];
        edges[i].index = i;
    }

    qsort(edges, edgesSize, sizeof(Edge), cmpEdge);
    int minCost = kruskal(n, edges, edgesSize, -1, -1);

    int* critical = malloc(sizeof(int) * edgesSize);
    int* pseudo = malloc(sizeof(int) * edgesSize);
    int cSize = 0, pSize = 0;

    for (int i = 0; i < edgesSize; i++) {
        int costExcl = kruskal(n, edges, edgesSize, -1, i);
        if (costExcl > minCost) {
            critical[cSize++] = edges[i].index;
        } else {
            int costIncl = kruskal(n, edges, edgesSize, i, -1);
            if (costIncl == minCost)
                pseudo[pSize++] = edges[i].index;
        }
    }

    int** result = malloc(sizeof(int*) * 2);
    result[0] = malloc(sizeof(int) * cSize);
    result[1] = malloc(sizeof(int) * pSize);
    for (int i = 0; i < cSize; i++) result[0][i] = critical[i];
    for (int i = 0; i < pSize; i++) result[1][i] = pseudo[i];

    *returnSize = 2;
    *returnColumnSizes = malloc(sizeof(int) * 2);
    (*returnColumnSizes)[0] = cSize;
    (*returnColumnSizes)[1] = pSize;

    free(critical);
    free(pseudo);
    free(edges);
    return result;
}
