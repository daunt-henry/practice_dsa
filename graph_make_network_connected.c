/*
Number of Operations to Make Network Connected

There are `n` computers numbered from 0 to n-1 connected by a list of connections.
You can extract cables and reconnect them, but each computer must be connected to the network.
Return the minimum number of operations required to connect all computers. If impossible, return -1.

Example:
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
*/

#include <stdio.h>
#include <stdlib.h>

int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unite(int* parent, int* rank, int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    if (px == py) return;
    if (rank[px] < rank[py]) {
        parent[px] = py;
    } else if (rank[py] < rank[px]) {
        parent[py] = px;
    } else {
        parent[py] = px;
        rank[px]++;
    }
}

int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    if (connectionsSize < n - 1) return -1;

    int* parent = (int*)malloc(n * sizeof(int));
    int* rank = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; i < connectionsSize; i++) {
        unite(parent, rank, connections[i][0], connections[i][1]);
    }

    int components = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) components++;
    }

    free(parent);
    free(rank);

    return components - 1;
}

int main() {
    int n = 4;
    int a[] = {0, 1}, b[] = {0, 2}, c[] = {1, 2};
    int* connections[] = {a, b, c};
    int connectionsColSize[] = {2, 2, 2};
    int res = makeConnected(n, connections, 3, connectionsColSize);
    printf("Minimum operations required: %d\n", res); // Output: 1
    return 0;
}
