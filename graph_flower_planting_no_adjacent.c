/*
Problem: Flower Planting With No Adjacent

You have `n` gardens, labeled from 1 to `n`, and an array `paths` where `paths[i] = [xi, yi]` describes a bidirectional path between garden `xi` and garden `yi`.

There are 4 types of flowers. Each garden must be planted with exactly one type of flower. No two gardens connected by a path can have the same type of flower.

Return an array `answer` such that `answer[i]` is the type of flower planted in the (i+1)th garden.

Example:
Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* gardenNoAdj(int n, int** paths, int pathsSize, int* pathsColSize, int* returnSize) {
    int** graph = (int**)malloc(n * sizeof(int*));
    int* degree = (int*)calloc(n, sizeof(int));
    int* res = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++)
        graph[i] = (int*)malloc(3 * sizeof(int)); // max 3 neighbors per garden

    for (int i = 0; i < pathsSize; i++) {
        int a = paths[i][0] - 1;
        int b = paths[i][1] - 1;
        graph[a][degree[a]++] = b;
        graph[b][degree[b]++] = a;
    }

    for (int i = 0; i < n; i++) {
        int used[5] = {0};
        for (int j = 0; j < degree[i]; j++) {
            int nei = graph[i][j];
            used[res[nei]] = 1;
        }
        for (int c = 1; c <= 4; c++) {
            if (!used[c]) {
                res[i] = c;
                break;
            }
        }
    }

    *returnSize = n;

    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
    free(degree);

    return res;
}

// Sample Test
int main() {
    int path_arr[][2] = {{1, 2}, {2, 3}, {3, 1}};
    int pathsSize = sizeof(path_arr) / sizeof(path_arr[0]);
    int* paths[pathsSize];
    int pathsColSize[pathsSize];

    for (int i = 0; i < pathsSize; i++) {
        paths[i] = path_arr[i];
        pathsColSize[i] = 2;
    }

    int n = 3;
    int returnSize;
    int* result = gardenNoAdj(n, paths, pathsSize, pathsColSize, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
