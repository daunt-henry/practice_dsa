/*
Title: Find Eventual Safe States

You are given a directed graph where each node points to a list of other nodes.
Return all the nodes that are eventually safe: that is, all paths starting from the node
lead to a terminal node (a node with no outgoing edges).

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation:
- Nodes 5 and 6 have no outgoing edges, so they are safe.
- Node 4 only points to 5, which is safe.
- Node 2 points to 5 (safe), so it's also safe.
- Node 0, 1, 3 are part of a cycle, so they are not safe.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int** graph, int* graphColSize, int* state) {
    if (state[node] != 0)
        return state[node] == 2;

    state[node] = 1; // visiting
    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!dfs(neighbor, graph, graphColSize, state))
            return false;
    }
    state[node] = 2; // safe
    return true;
}

int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize) {
    int* state = (int*)calloc(graphSize, sizeof(int)); // 0: unvisited, 1: visiting, 2: safe
    int* res = (int*)malloc(sizeof(int) * graphSize);
    int idx = 0;

    for (int i = 0; i < graphSize; i++) {
        if (dfs(i, graph, graphColSize, state)) {
            res[idx++] = i;
        }
    }

    free(state);
    *returnSize = idx;
    return res;
}

// Sample test
int main() {
    int data[7][3] = {
        {1, 2},     // node 0
        {2, 3},     // node 1
        {5},        // node 2
        {0},        // node 3
        {5},        // node 4
        {},         // node 5
        {}          // node 6
    };
    int sizes[] = {2, 2, 1, 1, 1, 0, 0};

    int** graph = (int**)malloc(sizeof(int*) * 7);
    for (int i = 0; i < 7; i++) {
        graph[i] = (int*)malloc(sizeof(int) * sizes[i]);
        for (int j = 0; j < sizes[i]; j++) {
            graph[i][j] = data[i][j];
        }
    }

    int returnSize;
    int* result = eventualSafeNodes(graph, 7, sizes, &returnSize);

    printf("Safe nodes: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    for (int i = 0; i < 7; i++) {
        free(graph[i]);
    }
    free(graph);
    free(result);
    return 0;
}
