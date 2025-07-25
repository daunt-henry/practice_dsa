/*
Second Minimum Time to Reach Destination

You're in a city with n nodes (1-indexed) and bidirectional roads. It takes `time` seconds to travel a road.
Traffic lights alternate every `change` seconds. You must start at node 1 and reach node n.

Find the second shortest time (in seconds) to reach node n from node 1.

Example:
Input:
n = 5
edges = [[1,2],[1,3],[1,4],[3,4],[4,5]]
time = 3
change = 5

Output:
13

Explanation:
Two paths of length 3 exist. First arrives at 9s. Second one after waiting at red light, arrives at 13s.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10005
#define INF 1000000000

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* graph[MAXN];

void addEdge(int u, int v) {
    Node* node1 = malloc(sizeof(Node));
    node1->val = v;
    node1->next = graph[u];
    graph[u] = node1;

    Node* node2 = malloc(sizeof(Node));
    node2->val = u;
    node2->next = graph[v];
    graph[v] = node2;
}

int secondMinimum(int n, int** edges, int edgesSize, int* edgesColSize, int time, int change) {
    for (int i = 0; i <= n; i++) graph[i] = NULL;

    for (int i = 0; i < edgesSize; i++) {
        addEdge(edges[i][0], edges[i][1]);
    }

    int dist[MAXN][2];
    for (int i = 0; i <= n; i++) dist[i][0] = dist[i][1] = INF;
    dist[1][0] = 0;

    typedef struct {
        int node, time;
    } QueueNode;

    QueueNode q[MAXN * 10];
    int front = 0, rear = 0;

    q[rear++] = (QueueNode){1, 0};

    while (front < rear) {
        QueueNode curr = q[front++];
        int u = curr.node;
        int t = curr.time;

        Node* neighbor = graph[u];
        while (neighbor) {
            int v = neighbor->val;
            int wait = (t / change) % 2 == 1 ? change - (t % change) : 0;
            int arrival = t + wait + time;

            if (arrival < dist[v][0]) {
                dist[v][1] = dist[v][0];
                dist[v][0] = arrival;
                q[rear++] = (QueueNode){v, arrival};
            } else if (arrival > dist[v][0] && arrival < dist[v][1]) {
                dist[v][1] = arrival;
                q[rear++] = (QueueNode){v, arrival};
            }

            neighbor = neighbor->next;
        }
    }

    for (int i = 0; i <= n; i++) {
        Node* node = graph[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }

    return dist[n][1];
}

int main() {
    int n = 5, time = 3, change = 5;
    int edgesArr[5][2] = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    int edgesSize = 5;

    int** edges = malloc(sizeof(int*) * edgesSize);
    int edgesColSize[5];
    for (int i = 0; i < edgesSize; i++) {
        edges[i] = malloc(sizeof(int) * 2);
        edges[i][0] = edgesArr[i][0];
        edges[i][1] = edgesArr[i][1];
        edgesColSize[i] = 2;
    }

    int result = secondMinimum(n, edges, edgesSize, edgesColSize, time, change);
    printf("Second minimum time to reach destination: %d\n", result);

    for (int i = 0; i < edgesSize; i++) free(edges[i]);
    free(edges);

    return 0;
}
