/*
Clone Graph

You are given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.

Each node contains a value (int) and a list of its neighbors.

Example:
Input:
    Node 1 connected to [2, 4]
    Node 2 connected to [1, 3]
    Node 3 connected to [2, 4]
    Node 4 connected to [1, 3]

Output:
    Deep copy of the graph with the same structure and values.

Note:
- The graph is guaranteed to be connected.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 101

// Definition for a Node.
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* map[MAX_NODES]; // mapping from original node val to cloned node

struct Node* clone(struct Node* node) {
    if (!node) return NULL;

    if (map[node->val]) return map[node->val];

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = node->val;
    newNode->numNeighbors = node->numNeighbors;
    newNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);
    map[node->val] = newNode;

    for (int i = 0; i < node->numNeighbors; ++i) {
        newNode->neighbors[i] = clone(node->neighbors[i]);
    }

    return newNode;
}

struct Node* cloneGraph(struct Node* node) {
    for (int i = 0; i < MAX_NODES; ++i) map[i] = NULL; // reset global map
    return clone(node);
}

// Test stub
/*
int main() {
    // Manual graph creation for testing can be added here
    // Example: create 4 nodes and link them as in the input case

    return 0;
}
*/
