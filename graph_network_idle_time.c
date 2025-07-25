/*
The Time When the Network Becomes Idle

There is a server at node 0 sending messages to other servers in an undirected graph.
Each server i has a patience[i], meaning it resends the message every patience[i] seconds if no reply.

Find the time when the network becomes idle — i.e., when there are no more messages in transit.

Example:
Input:
edges = [[0,1],[1,2]], patience = [0,2,1]
Output:
8

Explanation:
- Node 1 receives reply in 2s, resends at 2s (still waiting), gets reply back at 4s.
- Node 2 receives reply in 4s, resends at 1s/2s/3s — last resend at 3s, final reply comes at 7s.
- Network becomes idle at time 8.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

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

int networkBecomesIdle(int** edges, int edgesSize, int* edgesColSize, int* patience, int patienceSize) {
    for (int i = 0; i < patienceSize; i++) graph[i] = NULL;

    for (int i = 0; i < edgesSize; i++) {
        addEdge(edges[i][0], edges[i][1]);
    }

    int* dist = malloc(sizeof(int) * patienceSize);
    for (int i = 0; i < patienceSize; i++) dist[i] = -1;

    int* queue = malloc(sizeof(int) * patienceSize);
    int front = 0, rear = 0;
    queue[rear++] = 0;
    dist[0] = 0;

    while (front < rear) {
        int curr = queue[front++];
        Node* neighbor = graph[curr];
        while (neighbor) {
            int next = neighbor->val;
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                queue[rear++] = next;
            }
            neighbor = neighbor->next;
        }
    }

    int maxTime = 0;
    for (int i = 1; i < patienceSize; i++) {
        int roundTrip = dist[i] * 2;
        int lastSent;
        if (roundTrip <= patience[i]) {
            lastSent = 0;
        } else {
            lastSent = ((roundTrip - 1) / patience[i]) * patience[i];
        }
        int idleTime = lastSent + roundTrip + 1;
        if (idleTime > maxTime) maxTime = idleTime;
    }

    for (int i = 0; i < patienceSize; i++) {
        Node* node = graph[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }

    free(dist);
    free(queue);
    return maxTime;
}

int main() {
    int edgesArr[2][2] = {{0,1},{1,2}};
    int patienceArr[] = {0, 2, 1};
    int n = 3;

    int** edges = malloc(sizeof(int*) * 2);
    int edgesColSize[2] = {2,2};
    for (int i = 0; i < 2; i++) {
        edges[i] = malloc(sizeof(int) * 2);
        edges[i][0] = edgesArr[i][0];
        edges[i][1] = edgesArr[i][1];
    }

    int result = networkBecomesIdle(edges, 2, edgesColSize, patienceArr, n);
    printf("The network becomes idle at time: %d\n", result);

    for (int i = 0; i < 2; i++) free(edges[i]);
    free(edges);

    return 0;
}
