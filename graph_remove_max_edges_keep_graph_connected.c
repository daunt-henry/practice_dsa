/*
Remove Max Number of Edges to Keep Graph Fully Traversable

You are given a graph with n nodes and edges that are type 1 (Alice only), 
type 2 (Bob only), or type 3 (both Alice and Bob). You must ensure both Alice 
and Bob can fully traverse the graph using edges assigned to them. 
Return the maximum number of edges you can remove while keeping the graph 
traversable by both.

Example:
Input:
    n = 4
    edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output:
    2
Explanation:
    We can remove edges [1,1,2] and [1,1,3], and both Alice and Bob can still traverse the graph.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* parent;
    int* rank;
} DSU;

DSU* dsu_create(int size) {
    DSU* dsu = (DSU*)malloc(sizeof(DSU));
    dsu->parent = (int*)malloc(sizeof(int) * size);
    dsu->rank = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i)
        dsu->parent[i] = i;
    return dsu;
}

int dsu_find(DSU* dsu, int x) {
    if (dsu->parent[x] != x)
        dsu->parent[x] = dsu_find(dsu, dsu->parent[x]);
    return dsu->parent[x];
}

int dsu_union(DSU* dsu, int x, int y) {
    int rootX = dsu_find(dsu, x);
    int rootY = dsu_find(dsu, y);
    if (rootX == rootY)
        return 0;
    if (dsu->rank[rootX] < dsu->rank[rootY])
        dsu->parent[rootX] = rootY;
    else if (dsu->rank[rootX] > dsu->rank[rootY])
        dsu->parent[rootY] = rootX;
    else {
        dsu->parent[rootY] = rootX;
        dsu->rank[rootX]++;
    }
    return 1;
}

void dsu_free(DSU* dsu) {
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
}

int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) {
    DSU* alice = dsu_create(n + 1);
    DSU* bob = dsu_create(n + 1);
    int used = 0;

    for (int i = 0; i < edgesSize; i++) {
        int type = edges[i][0], u = edges[i][1], v = edges[i][2];
        if (type == 3) {
            int a = dsu_union(alice, u, v);
            int b = dsu_union(bob, u, v);
            if (a | b) used++;
        }
    }

    for (int i = 0; i < edgesSize; i++) {
        int type = edges[i][0], u = edges[i][1], v = edges[i][2];
        if (type == 1) used += dsu_union(alice, u, v);
        else if (type == 2) used += dsu_union(bob, u, v);
    }

    int root = dsu_find(alice, 1);
    for (int i = 2; i <= n; ++i)
        if (dsu_find(alice, i) != root) {
            dsu_free(alice);
            dsu_free(bob);
            return -1;
        }

    root = dsu_find(bob, 1);
    for (int i = 2; i <= n; ++i)
        if (dsu_find(bob, i) != root) {
            dsu_free(alice);
            dsu_free(bob);
            return -1;
        }

    dsu_free(alice);
    dsu_free(bob);
    return edgesSize - used;
}

int main() {
    int n = 4;
    int data[][3] = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    int* edges[6];
    for (int i = 0; i < 6; i++) edges[i] = data[i];
    int edgeCols[6] = {3,3,3,3,3,3};

    int result = maxNumEdgesToRemove(n, edges, 6, edgeCols);
    printf("Maximum number of removable edges: %d\n", result); // Output: 2

    return 0;
}
