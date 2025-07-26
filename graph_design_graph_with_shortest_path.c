/*
    Title: Design Graph With Shortest Path Calculator
    
    Problem:
    Design a graph class that supports:
    1. Initialization with a list of edges and nodes
    2. Adding new directed edges
    3. Finding the shortest path from node1 to node2

    Input:
        n = 4
        edges = [[0,2,5],[0,1,2],[1,2,1],[2,3,1]]
        Add Edge: [1,3,4]
        Shortest Path: (0, 3)
    Output:
        Shortest path = 4

    Explanation:
        0 -> 1 (2) -> 2 (1) -> 3 (1) = Total 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

typedef struct {
    int n;
    int** graph;
} Graph;

Graph* graphCreate(int n, int** edges, int edgesSize, int* edgesColSize) {
    Graph* obj = (Graph*)malloc(sizeof(Graph));
    obj->n = n;

    obj->graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        obj->graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            obj->graph[i][j] = INF;
        }
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        obj->graph[u][v] = w;
    }

    return obj;
}

void graphAddEdge(Graph* obj, int* edge, int edgeSize) {
    int u = edge[0];
    int v = edge[1];
    int w = edge[2];
    if (obj->graph[u][v] > w)
        obj->graph[u][v] = w;
}

int graphShortestPath(Graph* obj, int node1, int node2) {
    int* dist = (int*)malloc(obj->n * sizeof(int));
    int* visited = (int*)calloc(obj->n, sizeof(int));

    for (int i = 0; i < obj->n; i++) {
        dist[i] = INF;
    }

    dist[node1] = 0;

    for (int i = 0; i < obj->n; i++) {
        int u = -1;
        for (int j = 0; j < obj->n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) break;

        visited[u] = 1;

        for (int v = 0; v < obj->n; v++) {
            if (obj->graph[u][v] != INF && dist[v] > dist[u] + obj->graph[u][v]) {
                dist[v] = dist[u] + obj->graph[u][v];
            }
        }
    }

    int result = dist[node2] == INF ? -1 : dist[node2];
    free(dist);
    free(visited);
    return result;
}

void graphFree(Graph* obj) {
    for (int i = 0; i < obj->n; i++) {
        free(obj->graph[i]);
    }
    free(obj->graph);
    free(obj);
}
