/*
Course Schedule IV

You are given an integer n representing the number of courses, and an array of prerequisite pairs.
Return an array of booleans where each entry answers whether the first course in the query is a prerequisite of the second.

Example:
Input:
    numCourses = 3,
    prerequisites = [[1,0],[2,0]],
    queries = [[1,0],[1,2]]
Output: [true,false]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int graph[MAX][MAX];
int reachable[MAX][MAX];

void dfs(int u, int start, int n) {
    for (int v = 0; v < n; v++) {
        if (graph[u][v] && !reachable[start][v]) {
            reachable[start][v] = 1;
            dfs(v, start, n);
        }
    }
}

bool* checkIfPrerequisite(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    memset(graph, 0, sizeof(graph));
    memset(reachable, 0, sizeof(reachable));
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][0], v = prerequisites[i][1];
        graph[u][v] = 1;
    }

    for (int i = 0; i < numCourses; i++) {
        dfs(i, i, numCourses);
    }

    bool* res = (bool*)malloc(sizeof(bool) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0], v = queries[i][1];
        res[i] = reachable[u][v];
    }

    *returnSize = queriesSize;
    return res;
}

int main() {
    int prereqArr[][2] = {{1, 0}, {2, 0}};
    int queriesArr[][2] = {{1, 0}, {1, 2}};
    int numCourses = 3, preSize = 2, qSize = 2;

    int* prerequisites[2] = {prereqArr[0], prereqArr[1]};
    int* queries[2] = {queriesArr[0], queriesArr[1]};
    int preColSize = 2, qColSize = 2, returnSize;

    bool* result = checkIfPrerequisite(numCourses, prerequisites, preSize, &preColSize, queries, qSize, &qColSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf(result[i] ? "true\n" : "false\n");
    }

    free(result);
    return 0;
}
