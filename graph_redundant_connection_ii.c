// Problem: Redundant Connection II
// In a rooted tree, one node is the root and every other node has exactly one parent.
// One extra directed edge was added, possibly creating a cycle or a node with two parents.
// Return the edge that can be removed to make the graph a rooted tree.
//
// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int* parent, int x, int y) {
    parent[find(parent, x)] = find(parent, y);
}

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));
    for (int i = 0; i <= edgesSize; ++i)
        parent[i] = i;

    int* cand1 = NULL;
    int* cand2 = NULL;
    int* nodeParent = (int*)calloc(edgesSize + 1, sizeof(int));

    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0], v = edges[i][1];
        if (nodeParent[v] == 0) {
            nodeParent[v] = u;
        } else {
            cand1 = (int*)malloc(2 * sizeof(int));
            cand1[0] = nodeParent[v];
            cand1[1] = v;

            cand2 = (int*)malloc(2 * sizeof(int));
            cand2[0] = u;
            cand2[1] = v;

            edges[i][0] = -1; // Temporarily invalidate this edge
            edges[i][1] = -1;
        }
    }

    for (int i = 0; i <= edgesSize; ++i)
        parent[i] = i;

    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0], v = edges[i][1];
        if (u == -1 && v == -1) continue;

        if (find(parent, u) == find(parent, v)) {
            free(nodeParent);
            *returnSize = 2;
            return cand1 ? cand1 : edges[i];
        }
        unionSet(parent, u, v);
    }

    free(nodeParent);
    *returnSize = 2;
    return cand2;
}

int main() {
    int data[][2] = {{1,2},{1,3},{2,3}};
    int* edges[3];
    for (int i = 0; i < 3; ++i) edges[i] = data[i];
    int colSize[3] = {2, 2, 2};
    int returnSize;

    int* res = findRedundantDirectedConnection(edges, 3, colSize, &returnSize);
    if (res) {
        printf("Output: [%d,%d]\n", res[0], res[1]);  // Output: [2,3]
        free(res);
    }
    return 0;
}
