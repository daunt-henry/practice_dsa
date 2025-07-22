// Problem: Network Delay Time
// You are given a network represented as a list of travel times as directed edges `times[i] = [u, v, w]`.
// You must find the minimum time it takes for all nodes to receive a signal from node `k`.
// Return -1 if it is impossible.
//
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 100000000

typedef struct {
    int u, v, w;
} Edge;

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int* dist = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[k] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < timesSize; j++) {
            int u = times[j][0], v = times[j][1], w = times[j][2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            free(dist);
            return -1;
        }
        if (dist[i] > max) max = dist[i];
    }

    free(dist);
    return max;
}

int main() {
    int arr[][3] = {{2,1,1},{2,3,1},{3,4,1}};
    int* times[3];
    for (int i = 0; i < 3; i++) times[i] = arr[i];
    int colSize[3] = {3,3,3};
    int result = networkDelayTime(times, 3, colSize, 4, 2);
    printf("Output: %d\n", result);  // Output: 2
    return 0;
}
