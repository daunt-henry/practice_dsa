/*
Title: Loud and Rich

There are n people numbered from 0 to n - 1. Each person has a quietness rating.
Also, you are given a list "richer", where richer[i] = [a, b] means person a is richer than person b.
Return an array where answer[i] is the least quiet person among all people richer than or equal to person i.

Example:
Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int node, int** graph, int* graphColSize, int* quiet, int* answer, int* visited) {
    if (visited[node]) return;
    visited[node] = 1;
    answer[node] = node;

    for (int i = 0; i < graphColSize[node]; ++i) {
        int nei = graph[node][i];
        dfs(nei, graph, graphColSize, quiet, answer, visited);
        if (quiet[answer[nei]] < quiet[answer[node]]) {
            answer[node] = answer[nei];
        }
    }
}

int* loudAndRich(int** richer, int richerSize, int* richerColSize, int* quiet, int quietSize, int* returnSize){
    int** graph = (int**)malloc(sizeof(int*) * quietSize);
    int* graphColSize = (int*)calloc(quietSize, sizeof(int));

    for (int i = 0; i < quietSize; ++i) {
        graph[i] = (int*)malloc(sizeof(int) * quietSize);
    }

    for (int i = 0; i < richerSize; ++i) {
        int u = richer[i][0];
        int v = richer[i][1];
        graph[v][graphColSize[v]++] = u;
    }

    int* answer = (int*)malloc(sizeof(int) * quietSize);
    int* visited = (int*)calloc(quietSize, sizeof(int));

    for (int i = 0; i < quietSize; ++i) {
        dfs(i, graph, graphColSize, quiet, answer, visited);
    }

    for (int i = 0; i < quietSize; ++i) {
        free(graph[i]);
    }
    free(graph);
    free(graphColSize);
    free(visited);

    *returnSize = quietSize;
    return answer;
}

// Sample test
int main() {
    int richerData[][2] = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    int richerSize = sizeof(richerData) / sizeof(richerData[0]);
    int* richer[richerSize];
    int richerColSize[richerSize];
    for (int i = 0; i < richerSize; ++i) {
        richer[i] = richerData[i];
        richerColSize[i] = 2;
    }

    int quiet[] = {3,2,5,4,6,1,7,0};
    int returnSize;
    int* result = loudAndRich(richer, richerSize, richerColSize, quiet, 8, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d%s", result[i], (i < returnSize - 1) ? ", " : "");
    }
    printf("]\n");

    free(result);
    return 0;
}
