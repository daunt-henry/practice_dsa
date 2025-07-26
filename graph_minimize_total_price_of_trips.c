/*
    Title: Minimize the Total Price of the Trips

    Problem:
    You're given a tree with `n` nodes. Each node has a price. You are given a list of trips.
    Each trip is a path from a start node to an end node.

    For each trip, the entire path contributes the full price of every node on the path.
    You can choose some nodes to offer a 50% discount, but no two adjacent nodes can be discounted.

    Task:
    Minimize the total cost of all trips.

    Input:
        n = 4
        edges = [[0,1],[1,2],[1,3]]
        price = [2,2,10,6]
        trips = [[0,3],[2,1],[2,3]]

    Output:
        23

    Explanation:
        Optimal discounts: node 1 discounted (2→1), node 2 full price (10), etc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 51
#define INF 1000000000

int price[MAXN];
int dp[MAXN][2];
int visited[MAXN];
int used[MAXN];
int graph[MAXN][MAXN];
int n;

void dfs_path(int u, int parent, int start, int end) {
    if (u == end) {
        used[u]++;
        return;
    }
    for (int v = 0; v < n; v++) {
        if (v != parent && graph[u][v]) {
            int prev = used[v];
            dfs_path(v, u, start, end);
            if (used[v] > prev) {
                used[u]++;
                return;
            }
        }
    }
}

void dfs_dp(int u, int parent) {
    dp[u][0] = price[u] * used[u];
    dp[u][1] = price[u] * used[u] / 2;
    for (int v = 0; v < n; v++) {
        if (graph[u][v] && v != parent) {
            dfs_dp(v, u);
            dp[u][0] += fmin(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
}

int minimumTotalPrice(int n_, int** edges, int edgesSize, int* edgesColSize,
                      int* price_, int priceSize, int** trips, int tripsSize, int* tripsColSize) {
    n = n_;
    memset(graph, 0, sizeof(graph));
    memset(used, 0, sizeof(used));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    for (int i = 0; i < priceSize; i++) price[i] = price_[i];

    for (int i = 0; i < tripsSize; i++) {
        int start = trips[i][0], end = trips[i][1];
        dfs_path(start, -1, start, end);
    }

    dfs_dp(0, -1);

    return fmin(dp[0][0], dp[0][1]);
}
