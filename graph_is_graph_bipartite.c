// Problem: Is Graph Bipartite?
// Given an adjacency list of a graph, return true if the graph is bipartite.
// A graph is bipartite if its vertices can be divided into two groups such that no two vertices within the same group are adjacent.
//
// Input: graph = {{1,3},{0,2},{1,3},{0,2}}
// Output: true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int** graph, int* graphColSize, int* colors, int node, int color) {
    colors[node] = color;
    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (colors[neighbor] == -1) {
            if (!dfs(graph, graphColSize, colors, neighbor, 1 - color)) return false;
        } else if (colors[neighbor] == color) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* colors = (int*)malloc(sizeof(int) * graphSize);
    for (int i = 0; i < graphSize; i++) colors[i] = -1;

    for (int i = 0; i < graphSize; i++) {
        if (colors[i] == -1 && !dfs(graph, graphColSize, colors, i, 0)) {
            free(colors);
            return false;
        }
    }

    free(colors);
    return true;
}

int main() {
    int a0[] = {1, 3};
    int a1[] = {0, 2};
    int a2[] = {1, 3};
    int a3[] = {0, 2};

    int* graph[] = {a0, a1, a2, a3};
    int graphColSize[] = {2, 2, 2, 2};
    int graphSize = 4;

    bool result = isBipartite(graph, graphSize, graphColSize);
    printf("Is the graph bipartite? %s\n", result ? "true" : "false");  // Output: true

    return 0;
}
