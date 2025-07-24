/*
Problem: Minimum Degree of a Connected Trio in a Graph

A connected trio is a set of three nodes where each pair is connected by an edge.
The degree of such a trio is the total number of edges from those three nodes to nodes outside the trio.
Return the minimum degree of a connected trio in the graph, or -1 if no such trio exists.

Sample Input:
n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]

Sample Output:
3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXN 401

int minTrioDegree(int n, int** edges, int edgesSize, int* edgesColSize){
    int adj[MAXN][MAXN] = {0};
    int degree[MAXN] = {0};

    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = adj[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }

    int minDeg = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (!adj[i][j]) continue;
            for (int k = j + 1; k <= n; ++k) {
                if (adj[i][k] && adj[j][k]) {
                    int trioDeg = degree[i] + degree[j] + degree[k] - 6;
                    if (trioDeg < minDeg)
                        minDeg = trioDeg;
                }
            }
        }
    }

    return (minDeg == INT_MAX) ? -1 : minDeg;
}

int main() {
    int n = 6;
    int input[][2] = {{1,2},{1,3},{3,2},{4,1},{5,2},{3,6}};
    int size = sizeof(input)/sizeof(input[0]);
    int** edges = malloc(size * sizeof(int*));
    int colSize[size];
    for (int i = 0; i < size; i++) {
        edges[i] = malloc(2 * sizeof(int));
        edges[i][0] = input[i][0];
        edges[i][1] = input[i][1];
        colSize[i] = 2;
    }

    int res = minTrioDegree(n, edges, size, colSize);
    printf("Minimum degree of connected trio: %d\n", res);

    for (int i = 0; i < size; i++) free(edges[i]);
    free(edges);
    return 0;
}
