/*
Maximum Score of a Node Sequence

We have an undirected graph with n nodes (0 to n‑1), each with a `scores[i]`. Given edges list.

Goal:
  Find the maximum total score of a *valid sequence* of exactly four distinct nodes
  [a, u, v, b], such that there are edges (a-u), (u-v), (v-b). Return −1 if none.

Solution strategy:
  - For each node, keep its top‑3 highest‑scoring neighbors.
  - Then for each edge (u, v), consider all combinations picking a from u’s top‑3 and b from v’s top‑3,
    ensuring a, b, u, v are all distinct. Track the maximum sum.

Time Complexity: O(n + m)
Space: O(n + m), but only storing 3 neighbors per node.
*/

#include <stdio.h>
#include <stdlib.h>

int maximumScore(int* scores, int scoresSize, int** edges, int edgesSize, int* edgesColSize) {
    int n = scoresSize;
    // store top 3 neighbor indices
    int top3[100000][3];
    int cnt[100000] = {0};

    for (int i = 0; i < n; i++) {
        cnt[i] = 0;
        for (int j = 0; j < 3; j++) top3[i][j] = -1;
    }

    // Build top‑3 lists
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        for (int it = 0; it < 2; it++) {
            int x = (it == 0 ? u : v), y = (it == 0 ? v : u);
            int sc = scores[y];
            // insert y into x’s sorted top3
            for (int k = 0; k < cnt[x] || k < 3; k++) {
                if (k >= cnt[x]) {
                    top3[x][k] = y;
                    cnt[x]++;
                    break;
                }
                if (scores[top3[x][k]] < sc) {
                    for (int t = 2; t > k; t--) top3[x][t] = top3[x][t-1];
                    top3[x][k] = y;
                    if (cnt[x] < 3) cnt[x]++;
                    break;
                }
            }
            if (cnt[x] > 3) cnt[x] = 3;
        }
    }

    int ans = -1;
    // Evaluate sequences
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        if (cnt[u] < 1 || cnt[v] < 1) continue;
        for (int ai = 0; ai < cnt[u]; ai++) {
            int a = top3[u][ai];
            if (a == v) continue;
            for (int bi = 0; bi < cnt[v]; bi++) {
                int b = top3[v][bi];
                if (b == u || b == a) continue;
                int total = scores[a] + scores[u] + scores[v] + scores[b];
                ans = ans < total ? total : ans;
            }
        }
    }

    return ans;
}

// 📁 Filename suggestion: maximum_score_node_sequence.c

int main() {
    int scores[] = {5, 2, 9, 8, 4};
    int edgesArr[][2] = {
        {0,1},{1,2},{2,3},{0,2},{1,3},{2,4}
    };
    int n = sizeof(scores) / sizeof(scores[0]);
    int m = sizeof(edgesArr)/sizeof(edgesArr[0]);

    // build edges matrix
    int** edges = malloc(m * sizeof(int*));
    int* colSize = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        edges[i] = malloc(2 * sizeof(int));
        edges[i][0] = edgesArr[i][0];
        edges[i][1] = edgesArr[i][1];
        colSize[i] = 2;
    }

    int answer = maximumScore(scores, n, edges, m, colSize);
    printf("Maximum valid node‑sequence score: %d\n", answer);  // Expected: 24

    for (int i = 0; i < m; i++) free(edges[i]);
    free(edges);
    free(colSize);

    return 0;
}
