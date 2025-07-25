/*
Largest Color Value in a Directed Graph

You are given a directed graph of n colored nodes represented as a string `colors` where colors[i] is a lowercase English letter 
representing the color of the i-th node. You are also given a 2D array `edges` representing a list of directed edges.

Return the largest color value in any valid path in the graph. If the graph contains a cycle, return -1.

Example:
Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes with color 'a'.
*/

#include <stdio.h>
#include <string.h>

#define MAXN 100005
#define MAXC 26

int largestPathValue(char *colors, int** edges, int edgesSize, int* edgesColSize) {
    int n = strlen(colors);
    int indegree[MAXN] = {0};
    int colorCount[MAXN][MAXC] = {0};
    int adj[MAXN][MAXC], adjSize[MAXN] = {0};

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][adjSize[u]++] = v;
        indegree[v]++;
    }

    int queue[MAXN], front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
        colorCount[i][colors[i] - 'a'] = 1;
    }

    int visited = 0, maxColor = 0;

    while (front < rear) {
        int node = queue[front++];
        visited++;

        for (int i = 0; i < adjSize[node]; i++) {
            int nei = adj[node][i];

            for (int c = 0; c < MAXC; c++) {
                int val = colorCount[node][c] + (c == colors[nei] - 'a');
                if (val > colorCount[nei][c])
                    colorCount[nei][c] = val;
            }

            indegree[nei]--;
            if (indegree[nei] == 0)
                queue[rear++] = nei;
        }

        for (int c = 0; c < MAXC; c++)
            if (colorCount[node][c] > maxColor)
                maxColor = colorCount[node][c];
    }

    return visited == n ? maxColor : -1;
}

// Sample Test (not part of submission)
int main() {
    char colors[] = "abaca";
    int e1[] = {0, 1};
    int e2[] = {0, 2};
    int e3[] = {2, 3};
    int e4[] = {3, 4};
    int* edges[] = {e1, e2, e3, e4};
    int colSizes[] = {2, 2, 2, 2};

    int result = largestPathValue(colors, edges, 4, colSizes);
    printf("Largest color value in any path: %d\n", result); // Expected: 3

    return 0;
}
