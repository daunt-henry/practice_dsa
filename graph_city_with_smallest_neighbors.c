/*
Find the City With the Smallest Number of Neighbors at a Threshold Distance

There are `n` cities numbered from 0 to n-1. You are given an array `edges`
where each edge connects two cities with a certain weight (distance).

Return the city with the smallest number of neighbors reachable within a distance threshold.
If there are multiple such cities, return the one with the greatest number.

Example:
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], threshold = 4
Output: 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int dist[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = (i == j) ? 0 : INT_MAX / 2;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int minCount = n + 1, result = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (dist[i][j] <= distanceThreshold)
                count++;
        if (count <= minCount) {
            minCount = count;
            result = i;
        }
    }
    return result;
}

int main() {
    int a[] = {0, 1, 3}, b[] = {1, 2, 1}, c[] = {1, 3, 4}, d[] = {2, 3, 1};
    int* edges[] = {a, b, c, d};
    int edgesColSize[] = {3, 3, 3, 3};
    int n = 4, distanceThreshold = 4;

    int result = findTheCity(n, edges, 4, edgesColSize, distanceThreshold);
    printf("City with smallest reachable neighbors: %d\n", result); // Output: 3
    return 0;
}
