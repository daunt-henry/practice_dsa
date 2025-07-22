/*
Problem: Shortest Path with Alternating Colors

You are given a directed graph with `n` nodes where each edge is colored either red or blue. The graph is represented with two arrays `redEdges` and `blueEdges`, each a list of [from, to] directed edges.

Return an array `answer` where `answer[i]` is the length of the shortest path from node 0 to node i such that the edge colors alternate between red and blue. If no such path exists, return -1 for that node.

Example:
Input:
n = 3,
redEdges = [[0,1]],
blueEdges = [[1,2]]

Output: [0,1,2]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED 0
#define BLUE 1
#define INF 1e9

typedef struct {
    int node;
    int color;
    int dist;
} QueueItem;

int** createGraph(int n, int** edges, int edgesSize, int* edgesColSize) {
    int** graph = (int**)malloc(n * sizeof(int*));
    int* count = (int*)calloc(n, sizeof(int));
    int** temp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        temp[i] = (int*)malloc(100 * sizeof(int)); // generous upper bound
        graph[i] = (int*)malloc(100 * sizeof(int));
    }

    for (int i = 0; i < edgesSize; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        temp[from][count[from]++] = to;
    }

    for (int i = 0; i < n; i++)
        memcpy(graph[i], temp[i], count[i] * sizeof(int));

    free(count);
    for (int i = 0; i < n; i++)
        free(temp[i]);
    free(temp);

    return graph;
}

int* shortestAlternatingPaths(int n, int** redEdges, int redSize, int* redColSize,
                              int** blueEdges, int blueSize, int* blueColSize,
                              int* returnSize) {
    int** redGraph = createGraph(n, redEdges, redSize, redColSize);
    int** blueGraph = createGraph(n, blueEdges, blueSize, blueColSize);

    int visited[n][2]; // visited[node][color]
    memset(visited, 0, sizeof(visited));

    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) result[i] = -1;

    QueueItem queue[2 * n * n];
    int front = 0, rear = 0;

    queue[rear++] = (QueueItem){0, RED, 0};
    queue[rear++] = (QueueItem){0, BLUE, 0};
    visited[0][RED] = visited[0][BLUE] = 1;
    result[0] = 0;

    while (front < rear) {
        QueueItem curr = queue[front++];
        int** graph = (curr.color == RED) ? blueGraph : redGraph;
        int color = (curr.color == RED) ? BLUE : RED;

        for (int i = 0; i < n; i++) {
            if (graph[curr.node][i] == 0) continue;
            int next = i;
            if (!visited[next][color]) {
                visited[next][color] = 1;
                if (result[next] == -1 || result[next] > curr.dist + 1)
                    result[next] = curr.dist + 1;
                queue[rear++] = (QueueItem){next, color, curr.dist + 1};
            }
        }
    }

    *returnSize = n;
    for (int i = 0; i < n; i++) {
        free(redGraph[i]);
        free(blueGraph[i]);
    }
    free(redGraph);
    free(blueGraph);

    return result;
}

// Sample Test
int main() {
    int red_arr[][2] = {{0, 1}};
    int blue_arr[][2] = {{1, 2}};

    int* redEdges[1] = { red_arr[0] };
    int* blueEdges[1] = { blue_arr[0] };
    int redColSize[1] = {2};
    int blueColSize[1] = {2};

    int returnSize;
    int* ans = shortestAlternatingPaths(3, redEdges, 1, redColSize, blueEdges, 1, blueColSize, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", ans[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(ans);
    return 0;
}
