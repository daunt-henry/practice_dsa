/*
Number of Ways to Arrive at Destination

You are given an undirected weighted graph of n nodes (0 to n-1) and roads[i] = [u, v, time]
representing a bidirectional road between nodes u and v that takes time to travel.

Return the number of *distinct shortest paths* from node 0 to node n - 1. Since the answer may be large,
return it modulo 10^9 + 7.

Example:
Input:
n = 7,
roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output:
4
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007
#define LL long long

// Same internal code as above...

// Only main() for testing:
int main() {
    int n = 7;
    int roads_arr[10][3] = {
        {0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},
        {3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}
    };

    int** roads = malloc(10 * sizeof(int*));
    int roadsColSize[10];
    for (int i = 0; i < 10; i++) {
        roads[i] = malloc(3 * sizeof(int));
        roads[i][0] = roads_arr[i][0];
        roads[i][1] = roads_arr[i][1];
        roads[i][2] = roads_arr[i][2];
        roadsColSize[i] = 3;
    }

    int result = countPaths(n, roads, 10, roadsColSize);
    printf("Number of ways to arrive at destination: %d\n", result);

    for (int i = 0; i < 10; i++) free(roads[i]);
    free(roads);

    return 0;
}
