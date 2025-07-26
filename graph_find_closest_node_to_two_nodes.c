/*
Find Closest Node to Given Two Nodes

You are given a directed graph of n nodes numbered from 0 to n - 1, 
where each node has at most one outgoing edge. The graph is represented with a 
0-indexed array edges of size n, indicating that there is a directed edge 
from node i to node edges[i]. If edges[i] == -1, node i does not have an outgoing edge.

You are also given two nodes node1 and node2.
Return the index of the node that can be reached from both node1 and node2, 
such that the maximum of the distances from node1 and node2 to that node is minimized. 
If there are multiple answers, return the node with the smallest index. 
If no such node exists, return -1.

Example:
Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

void getDistances(int* edges, int n, int start, int* dist) {
    for (int i = 0; i < n; i++) dist[i] = -1;
    int d = 0;
    while (start != -1 && dist[start] == -1) {
        dist[start] = d++;
        start = edges[start];
    }
}

int closestMeetingNode(int* edges, int edgesSize, int node1, int node2) {
    int* dist1 = (int*)malloc(sizeof(int) * edgesSize);
    int* dist2 = (int*)malloc(sizeof(int) * edgesSize);
    getDistances(edges, edgesSize, node1, dist1);
    getDistances(edges, edgesSize, node2, dist2);

    int minDist = 1e9;
    int res = -1;
    for (int i = 0; i < edgesSize; i++) {
        if (dist1[i] != -1 && dist2[i] != -1) {
            int maxDist = dist1[i] > dist2[i] ? dist1[i] : dist2[i];
            if (maxDist < minDist) {
                minDist = maxDist;
                res = i;
            }
        }
    }

    free(dist1);
    free(dist2);
    return res;
}

// Sample test
int main() {
    int edges[] = {2, 2, 3, -1};
    int node1 = 0, node2 = 1;
    int n = sizeof(edges) / sizeof(edges[0]);

    int result = closestMeetingNode(edges, n, node1, node2);
    printf("Closest meeting node: %d\n", result); // Expected: 2

    return 0;
}
