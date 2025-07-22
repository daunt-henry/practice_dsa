/*
Title: Shortest Path Visiting All Nodes

You have an undirected connected graph of n nodes labeled from 0 to n - 1.
You need to find the shortest path that visits every node exactly once. 
Return the length of the shortest path that visits every node.

Example:
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int node;
    int mask;
    int dist;
} State;

int shortestPathLength(int** graph, int graphSize, int* graphColSize) {
    int finalMask = (1 << graphSize) - 1;
    int visited[graphSize][1 << graphSize];
    memset(visited, 0, sizeof(visited));

    State* queue = malloc(sizeof(State) * graphSize * (1 << graphSize));
    int front = 0, back = 0;

    for (int i = 0; i < graphSize; ++i) {
        queue[back++] = (State){i, 1 << i, 0};
        visited[i][1 << i] = 1;
    }

    while (front < back) {
        State curr = queue[front++];

        if (curr.mask == finalMask) {
            free(queue);
            return curr.dist;
        }

        for (int i = 0; i < graphColSize[curr.node]; ++i) {
            int nei = graph[curr.node][i];
            int newMask = curr.mask | (1 << nei);
            if (!visited[nei][newMask]) {
                visited[nei][newMask] = 1;
                queue[back++] = (State){nei, newMask, curr.dist + 1};
            }
        }
    }

    free(queue);
    return -1;
}

// Sample Test
int main() {
    int data0[] = {1,2,3};
    int data1[] = {0};
    int data2[] = {0};
    int data3[] = {0};
    int* graph[] = {data0, data1, data2, data3};
    int colSize[] = {3, 1, 1, 1};
    int result = shortestPathLength(graph, 4, colSize);
    printf("Output: %d\n", result);  // Expected: 4
    return 0;
}
