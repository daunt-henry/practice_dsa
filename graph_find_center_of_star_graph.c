/*
Find Center of Star Graph

In a star graph with n nodes, exactly one node has degree n - 1, and all others have degree 1.
You are given a 2D integer array `edges` where each `edges[i] = [ui, vi]` represents a connection
between the nodes `ui` and `vi`. Return the center of the graph.

Example:
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
*/

#include <stdio.h>

int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    // Center must appear in both first two edges
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        return edges[0][0];
    return edges[0][1];
}

// Sample test function (for demonstration)
int main() {
    int e1[] = {1, 2};
    int e2[] = {2, 3};
    int e3[] = {4, 2};

    int* edges[] = {e1, e2, e3};
    int colSize[] = {2, 2, 2};

    int result = findCenter(edges, 3, colSize);
    printf("Center of star graph: %d\n", result);  // Expected Output: 2

    return 0;
}
