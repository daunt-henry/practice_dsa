/*
    Title: Count the Number of Complete Components

    Problem:
    You're given an undirected graph with `n` nodes and `edges`.
    A *complete component* is a connected component where every pair of nodes is directly connected by an edge.

    Return the number of complete components in the graph.

    Example:
    Input:
        n = 6,
        edges = [[0,1],[0,2],[1,2],[3,4]]

    Output:
        3

    Explanation:
        Component 0-1-2 is complete.
        Component 3-4 is complete.
        Component 5 is a single node (complete by default).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000

int parent[MAXN], size[MAXN], edgeCount[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) {
        edgeCount[pa]++;
        return;
    }
    parent[pa] = pb;
    size[pb] += size[pa];
    edgeCount[pb] += edgeCount[pa] + 1;
}

int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
        edgeCount[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        unionSet(u, v);
    }

    bool visited[MAXN] = {false};
    int count = 0;

    for (int i = 0; i < n; i++) {
        int root = find(i);
        if (!visited[root]) {
            visited[root] = true;
            int nodes = size[root];
            int edgesNeeded = nodes * (nodes - 1) / 2;
            if (edgeCount[root] == edgesNeeded)
                count++;
        }
    }

    return count;
}
