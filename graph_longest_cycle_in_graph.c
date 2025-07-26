/*
    Title: Longest Cycle in a Graph

    You are given a directed graph of n nodes, numbered from 0 to n - 1, where each node has at most one outgoing edge.
    The graph is represented with a given 0-indexed array edges of length n, 
    indicating that there is a directed edge from node i to edges[i]. If edges[i] == -1, there is no outgoing edge.

    Return the length of the longest cycle in the graph. If no cycle exists, return -1.

    Example:
    Input: edges = [3,3,4,2,3]
    Output: 3
*/

#include <stdio.h>

int longestCycle(int* edges, int edgesSize) {
    int visited[100001] = {0};
    int visitTime[100001];
    int time = 1;
    int maxCycle = -1;

    for (int i = 0; i < edgesSize; i++) {
        if (visited[i])
            continue;

        int curr = i;
        int startTime = time;

        while (curr != -1 && !visited[curr]) {
            visited[curr] = 1;
            visitTime[curr] = time++;
            curr = edges[curr];
        }

        if (curr != -1 && visitTime[curr] >= startTime) {
            int cycleLength = time - visitTime[curr];
            if (cycleLength > maxCycle)
                maxCycle = cycleLength;
        }
    }

    return maxCycle;
}

// Sample test
int main() {
    int edges[] = {3, 3, 4, 2, 3};
    int n = sizeof(edges) / sizeof(edges[0]);
    int result = longestCycle(edges, n);
    printf("Longest cycle length: %d\n", result);  // Output: 3
    return 0;
}
