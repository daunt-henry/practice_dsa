// Problem: Redundant Connection
// A tree is a connected graph without cycles.
// You are given a graph that started as a tree with n nodes and one extra edge.
// Return the edge that can be removed so that the resulting graph is a tree.
//
// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]

#include <stdio.h>
#include <stdlib.h>

int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int* parent, int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    if (px != py)
        parent[px] = py;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));
    for (int i = 0; i <= edgesSize; ++i) {
        parent[i] = i;
    }

    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        if (find(parent, u) == find(parent, v)) {
            result[0] = u;
            result[1] = v;
            *returnSize = 2;
            free(parent);
            return result;
        }
        unionSet(parent, u, v);
    }

    *returnSize = 0;
    free(parent);
    return NULL;
}

int main() {
    int data[][2] = {{1,2},{1,3},{2,3}};
    int* edges[3];
    for (int i = 0; i < 3; i++) edges[i] = data[i];
    int colSize[3] = {2, 2, 2};
    int returnSize;

    int* res = findRedundantConnection(edges, 3, colSize, &returnSize);
    if (res) {
        printf("Output: [%d,%d]\n", res[0], res[1]);  // Output: [2,3]
        free(res);
    }
    return 0;
}
