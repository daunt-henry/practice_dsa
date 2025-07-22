// Problem: Number of Provinces
// URL: [removed]
// A province is a group of directly or indirectly connected cities.
// You are given an adjacency matrix isConnected.
// Return the number of provinces.
//
// Input:
// isConnected = [
//   [1,1,0],
//   [1,1,0],
//   [0,0,1]
// ]
// Output: 2

#include <stdio.h>
#include <stdlib.h>

void dfs(int** graph, int graphSize, int* visited, int city) {
    visited[city] = 1;
    for (int j = 0; j < graphSize; ++j) {
        if (graph[city][j] && !visited[j]) {
            dfs(graph, graphSize, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int* visited = (int*)calloc(isConnectedSize, sizeof(int));
    int provinces = 0;

    for (int i = 0; i < isConnectedSize; ++i) {
        if (!visited[i]) {
            dfs(isConnected, isConnectedSize, visited, i);
            provinces++;
        }
    }

    free(visited);
    return provinces;
}

int main() {
    int data[3][3] = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int* isConnected[3];
    for (int i = 0; i < 3; i++) {
        isConnected[i] = data[i];
    }

    int colSize[3] = {3, 3, 3};

    int result = findCircleNum(isConnected, 3, colSize);
    printf("Output: %d\n", result); // Output: 2

    return 0;
}
