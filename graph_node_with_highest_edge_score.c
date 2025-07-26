/*
    Title: Node With Highest Edge Score
  
    You are given a directed graph with n nodes labeled from 0 to n - 1, 
    and an integer array edges where edges[i] indicates that there is a directed edge 
    from node i to node edges[i].

    The edge score of a node i is defined as the sum of the indices j for which 
    edges[j] == i.

    Return the node with the highest edge score. If multiple nodes have the same score, 
    return the node with the smallest index.

    Example:
    Input: edges = [1,0,0,0,0,7,7,5]
    Output: 7
*/

#include <stdio.h>
#include <stdlib.h>

int edgeScore(int* edges, int edgesSize) {
    long long* scores = (long long*)calloc(edgesSize, sizeof(long long));
    
    for (int i = 0; i < edgesSize; i++) {
        scores[edges[i]] += i;
    }

    long long maxScore = -1;
    int result = 0;

    for (int i = 0; i < edgesSize; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            result = i;
        }
    }

    return result;
}

// Example usage (test logic omitted since LeetCode handles I/O):
// int edges[] = {1,0,0,0,0,7,7,5};
// int result = edgeScore(edges, 8);
// printf("Output: %d\n", result); // Output: 7
