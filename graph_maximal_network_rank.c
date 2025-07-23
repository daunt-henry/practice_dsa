/*
Maximal Network Rank

There is an infrastructure of n cities with some bidirectional roads between them.
The network rank of two cities is the total number of roads connected to either city,
counting shared roads only once.

Return the maximal network rank of all pairs of different cities.

Example:
Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
Output: 4
Explanation: The pair (1, 3) has 4 connections.
*/

#include <stdio.h>

int maximalNetworkRank(int n, int** roads, int roadsSize, int* roadsColSize){
    int degree[101] = {0};
    int connected[101][101] = {0};

    for (int i = 0; i < roadsSize; i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        degree[a]++;
        degree[b]++;
        connected[a][b] = 1;
        connected[b][a] = 1;
    }

    int maxRank = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rank = degree[i] + degree[j];
            if (connected[i][j]) rank--;
            if (rank > maxRank) maxRank = rank;
        }
    }

    return maxRank;
}

int main() {
    int arr[4][2] = {{0,1}, {0,3}, {1,2}, {1,3}};
    int* roads[4] = {arr[0], arr[1], arr[2], arr[3]};
    int colSizes[4] = {2,2,2,2};
    int n = 4;

    int result = maximalNetworkRank(n, roads, 4, colSizes);
    printf("Maximal Network Rank: %d\n", result);  // Output: 4
    return 0;
}
