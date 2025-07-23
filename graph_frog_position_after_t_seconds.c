/*
Frog Position After T Seconds

A frog starts at node 1. Each second, it jumps randomly to an unvisited connected node.
If it cannot jump, it stays. Return the probability that after T seconds, the frog is on target node.

Example:
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
Output: 0.1666667
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 101

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* graph[MAX_NODES];
int visited[MAX_NODES];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->val = u;
    newNode->next = graph[v];
    graph[v] = newNode;
}

double dfs(int node, int t, int target) {
    visited[node] = 1;

    if (t == 0) return (node == target) ? 1.0 : 0.0;

    int childCount = 0;
    Node* cur = graph[node];
    while (cur) {
        if (!visited[cur->val]) childCount++;
        cur = cur->next;
    }

    if (childCount == 0) {
        return (node == target) ? 1.0 : 0.0;
    }

    double prob = 0.0;
    cur = graph[node];
    while (cur) {
        if (!visited[cur->val]) {
            prob += dfs(cur->val, t - 1, target);
        }
        cur = cur->next;
    }

    return prob / childCount;
}

double frogPosition(int n, int** edges, int edgesSize, int* edgesColSize, int t, int target) {
    for (int i = 1; i <= n; i++) {
        graph[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        addEdge(u, v);
    }

    return dfs(1, t, target);
}

int main() {
    int edgeArr[][2] = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    int edgesSize = 6;
    int* edges[6];
    int colSize = 2;
    for (int i = 0; i < edgesSize; i++) edges[i] = edgeArr[i];
    int n = 7, t = 2, target = 4;

    double result = frogPosition(n, edges, edgesSize, &colSize, t, target);
    printf("Probability: %.7f\n", result); // Expected Output: 0.1666667
    return 0;
}
