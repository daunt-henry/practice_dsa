/*
Find if Path Exists in Graph

You are given an undirected graph with n nodes, numbered from 0 to n - 1,
and an array edges where edges[i] = [ui, vi] indicates a bidirectional edge between ui and vi.
You are also given two integers source and destination.
Return true if there is a valid path from source to destination.

Example:
Input:
n = 6,
edges = [[0,1],[0,2],[3,5],[5,4],[4,3]],
source = 0,
destination = 5

Output:
false
*/

#include <stdio.h>
#include <stdlib.h>

bool dfs(int u, int target, int* visited, int** graph, int* graphSize) {
    if (u == target) return true;
    visited[u] = 1;

    for (int i = 0; i < graphSize[u]; ++i) {
        int v = graph[u][i];
        if (!visited[v] && dfs(v, target, visited, graph, graphSize)) {
            return true;
        }
    }
    return false;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphSize = (int*)calloc(n, sizeof(int));
    int* cap = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; ++i) {
        cap[i] = 2;
        graph[i] = (int*)malloc(cap[i] * sizeof(int));
    }

    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0], v = edges[i][1];

        if (graphSize[u] == cap[u]) {
            cap[u] *= 2;
            graph[u] = realloc(graph[u], cap[u] * sizeof(int));
        }
        if (graphSize[v] == cap[v]) {
            cap[v] *= 2;
            graph[v] = realloc(graph[v], cap[v] * sizeof(int));
        }

        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    bool result = dfs(source, destination, visited, graph, graphSize);

    for (int i = 0; i < n; ++i) free(graph[i]);
    free(graph);
    free(graphSize);
    free(cap);
    free(visited);

    return result;
}

int main() {
    int n = 6;
    int edgeVals[5][2] = {{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};
    int** edges = malloc(5 * sizeof(int*));
    int edgesColSize[5];

    for (int i = 0; i < 5; ++i) {
        edges[i] = malloc(2 * sizeof(int));
        edges[i][0] = edgeVals[i][0];
        edges[i][1] = edgeVals[i][1];
        edgesColSize[i] = 2;
    }

    int source = 0, destination = 5;
    bool result = validPath(n, edges, 5, edgesColSize, source, destination);
    printf("Path exists from %d to %d: %s\n", source, destination, result ? "true" : "false");

    for (int i = 0; i < 5; ++i) free(edges[i]);
    free(edges);

    return 0;
}
