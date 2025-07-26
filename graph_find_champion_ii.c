/*
Title: Find Champion II

Problem:
There are n players labeled from 0 to n-1. You're given a list of matches in a directed graph format.
Each match [u, v] means player u defeats player v.
A player x is a *champion* if no one defeats x and x defeats all others either directly or indirectly.
Return the label of the champion if there's exactly one, otherwise return -1.

Example:
Input: n = 4, edges = [[0,1],[1,2],[2,3]]
Output: 0

Approach:
- Use indegree logic. Only one node should have indegree 0.
- That node must be able to reach all others (but the problem states this is guaranteed if only one with indegree 0 exists).
*/

#include <stdio.h>

int findChampion(int n, int** edges, int edgesSize, int* edgesColSize){
    int indegree[n];
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    for (int i = 0; i < edgesSize; i++)
        indegree[edges[i][1]]++;

    int champion = -1;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            if (champion != -1) return -1;
            champion = i;
        }
    }

    return champion;
}

// Sample Test
int main() {
    int n = 4;
    int data[][2] = {{0,1}, {1,2}, {2,3}};
    int edgesSize = sizeof(data) / sizeof(data[0]);
    int* edges[edgesSize];
    int edgesColSize[edgesSize];
    for (int i = 0; i < edgesSize; i++) {
        edges[i] = data[i];
        edgesColSize[i] = 2;
    }

    int result = findChampion(n, edges, edgesSize, edgesColSize);
    printf("Champion: %d\n", result);  // Output: 0
    return 0;
}
