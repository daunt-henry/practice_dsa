/*
Problem: Find the Town Judge

In a town of `n` people labeled from 1 to `n`, there is a rumor that one of these people is the town judge.

The town judge has the following properties:
1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.

Given an array `trust` where `trust[i] = [a, b]` representing that person `a` trusts person `b`, return the label of the town judge if the town judge exists, and return -1 otherwise.

Example:
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
*/

#include <stdio.h>
#include <stdlib.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int* indegree = (int*)calloc(n + 1, sizeof(int));
    int* outdegree = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0];
        int b = trust[i][1];
        outdegree[a]++;
        indegree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0) {
            free(indegree);
            free(outdegree);
            return i;
        }
    }

    free(indegree);
    free(outdegree);
    return -1;
}

// Sample test
int main() {
    int trust_arr[][2] = {{1, 3}, {2, 3}};
    int n = 3;
    int trustSize = sizeof(trust_arr) / sizeof(trust_arr[0]);
    int trustColSize[trustSize];
    int* trust[trustSize];

    for (int i = 0; i < trustSize; i++) {
        trust[i] = trust_arr[i];
        trustColSize[i] = 2;
    }

    int result = findJudge(n, trust, trustSize, trustColSize);
    printf("Output: %d\n", result); // Output: 3
    return 0;
}
