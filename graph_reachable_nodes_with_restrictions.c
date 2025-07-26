/*
    Title: Reachable Nodes With Restrictions

    There is an undirected tree with n nodes labeled from 0 to n - 1 and exactly n - 1 edges.
    You are given the integer n and a 2D integer array edges, where edges[i] = [ai, bi] indicates 
    that there is an edge between nodes ai and bi in the tree.

    You are also given an integer array restricted which represents restricted nodes.

    Return the maximum number of nodes you can reach from node 0 without visiting any restricted node.

    Example:
    Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
    Output: 4
*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int** graph, int* graphSize, int* visited, int* restrictedMark, int* count) {
    if (visited[node] || restrictedMark[node])
        return;

    visited[node] = 1;
    (*count)++;

    for (int i = 0; i < graphSize[node]; i++) {
        dfs(graph[node][i], graph, graphSize, visited, restrictedMark, count);
    }
}

int** createGraph(int n, int** edges, int edgesSize, int* edgesColSize, int* graphSize) {
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(100 * sizeof(int));
        graphSize[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    return graph;
}

int reachableNodes(int n, int** edges, int edgesSize, int* edgesColSize, int* restricted, int restrictedSize) {
    int* visited = (int*)calloc(n, sizeof(int));
    int* restrictedMark = (int*)calloc(n, sizeof(int));
    int* graphSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < restrictedSize; i++) {
        restrictedMark[restricted[i]] = 1;
    }

    int** graph = createGraph(n, edges, edgesSize, edgesColSize, graphSize);

    int count = 0;
    dfs(0, graph, graphSize, visited, restrictedMark, &count);
    return count;
}

// Sample test not included because LeetCode handles multi-dimensional input format.
