/*
Minimum Number of Vertices to Reach All Nodes

Given a directed acyclic graph with n nodes labeled from 0 to n - 1, 
return the smallest set of vertices from which all nodes in the graph are reachable.

Example:
Input:
    n = 6
    edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output:
    [0,3]
Explanation:
    Nodes 0 and 3 have no incoming edges, so they must be starting points.
*/

#include <stdio.h>
#include <stdlib.h>

int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* indegree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        int to = edges[i][1];
        indegree[to]++;
    }

    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            result[(*returnSize)++] = i;
        }
    }

    free(indegree);
    return result;
}

int main() {
    int n = 6;
    int edgeArr[5][2] = {{0,1},{0,2},{2,5},{3,4},{4,2}};
    int* edges[5];
    for (int i = 0; i < 5; i++) edges[i] = edgeArr[i];
    int edgeCols[5] = {2, 2, 2, 2, 2};

    int returnSize = 0;
    int* res = findSmallestSetOfVertices(n, edges, 5, edgeCols, &returnSize);

    printf("Minimum set of vertices: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);
    return 0;
}
