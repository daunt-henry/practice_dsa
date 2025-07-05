/*
Checking Existence of Edge Length Limited Paths

Problem:
Given a weighted undirected graph and a list of queries where each query asks if there's a path between two nodes such that every edge on the path is less than a certain limit.

Approach:
1. Sort the edge list and the queries by weight limit.
2. Use Union-Find to connect components.
3. For each query, process all edges smaller than the query limit and then check if the two nodes are connected.

Time Complexity:
- O(E log E + Q log Q + α(N)) where E = edges, Q = queries

Example:
Input:
n = 3
edgeList = [[0,1,2],[1,2,4],[2,0,8]]
queries = [[0,1,2],[0,2,5]]
Output: [false,true]
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmpEdges(const void* a, const void* b) {
    return ((int**)a)[0][2] - ((int**)b)[0][2];
}

int cmpQueries(const void* a, const void* b) {
    return ((int**)a)[0][2] - ((int**)b)[0][2];
}

int find(int* parent, int x) {
    if (parent[x] != x) parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unite(int* parent, int* rank, int x, int y) {
    int xr = find(parent, x);
    int yr = find(parent, y);
    if (xr == yr) return;
    if (rank[xr] < rank[yr]) parent[xr] = yr;
    else if (rank[xr] > rank[yr]) parent[yr] = xr;
    else {
        parent[yr] = xr;
        rank[xr]++;
    }
}

bool* distanceLimitedPathsExist(int n, int** edgeList, int edgeListSize, int* edgeListColSize,
                                int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    bool* result = calloc(queriesSize, sizeof(bool));
    
    int** qCopy = malloc(sizeof(int*) * queriesSize);
    for (int i = 0; i < queriesSize; ++i) {
        qCopy[i] = malloc(sizeof(int) * 4);
        qCopy[i][0] = queries[i][0];
        qCopy[i][1] = queries[i][1];
        qCopy[i][2] = queries[i][2];
        qCopy[i][3] = i;
    }

    qsort(edgeList, edgeListSize, sizeof(int*), cmpEdges);
    qsort(qCopy, queriesSize, sizeof(int*), cmpQueries);

    int* parent = malloc(sizeof(int) * n);
    int* rank = calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) parent[i] = i;

    int i = 0;
    for (int j = 0; j < queriesSize; ++j) {
        while (i < edgeListSize && edgeList[i][2] < qCopy[j][2]) {
            unite(parent, rank, edgeList[i][0], edgeList[i][1]);
            i++;
        }
        if (find(parent, qCopy[j][0]) == find(parent, qCopy[j][1])) {
            result[qCopy[j][3]] = true;
        }
    }

    for (int i = 0; i < queriesSize; ++i) free(qCopy[i]);
    free(qCopy);
    free(parent);
    free(rank);
    return result;
}
