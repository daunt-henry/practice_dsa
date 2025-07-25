/*
Process Restricted Friend Requests

You are given:
- An integer n (number of people labeled from 0 to n - 1).
- A 2D array 'restrictions', where restrictions[i] = [ai, bi] means person ai and bi cannot be friends.
- A 2D array 'requests', where requests[i] = [ui, vi] is a friend request.

Each friend request [ui, vi] is successful only if:
  - ui and vi are not already indirectly restricted.
  - Adding them does not violate any restriction.

Return an array of booleans where the ith value is true if the ith request is successful.

Example:
Input:
n = 3,
restrictions = [[0,1]],
requests = [[0,2],[2,1]]

Output:
[true,false]
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000

int find(int* parent, int x) {
    return parent[x] == x ? x : (parent[x] = find(parent, parent[x]));
}

void unionSet(int* parent, int* rank, int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    if (px != py) {
        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
}

bool* friendRequests(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize,
                     int** requests, int requestsSize, int* requestsColSize, int* returnSize) {
    *returnSize = requestsSize;
    bool* result = malloc(sizeof(bool) * requestsSize);

    int parent[MAXN], rank[MAXN];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < requestsSize; i++) {
        int u = requests[i][0];
        int v = requests[i][1];

        int pu = find(parent, u);
        int pv = find(parent, v);

        bool valid = true;

        if (pu != pv) {
            for (int j = 0; j < restrictionsSize; j++) {
                int a = restrictions[j][0];
                int b = restrictions[j][1];
                int pa = find(parent, a);
                int pb = find(parent, b);
                if ((pa == pu && pb == pv) || (pa == pv && pb == pu)) {
                    valid = false;
                    break;
                }
            }
        }

        result[i] = valid;
        if (valid)
            unionSet(parent, rank, pu, pv);
    }

    return result;
}

int main() {
    int n = 3;

    int restrictionsArr[][2] = {{0, 1}};
    int requestsArr[][2] = {{0, 2}, {2, 1}};

    int restrictionsSize = sizeof(restrictionsArr) / sizeof(restrictionsArr[0]);
    int requestsSize = sizeof(requestsArr) / sizeof(requestsArr[0]);

    int** restrictions = malloc(restrictionsSize * sizeof(int*));
    int** requests = malloc(requestsSize * sizeof(int*));
    int restrictionsColSize[restrictionsSize];
    int requestsColSize[requestsSize];

    for (int i = 0; i < restrictionsSize; i++) {
        restrictions[i] = malloc(2 * sizeof(int));
        restrictions[i][0] = restrictionsArr[i][0];
        restrictions[i][1] = restrictionsArr[i][1];
        restrictionsColSize[i] = 2;
    }

    for (int i = 0; i < requestsSize; i++) {
        requests[i] = malloc(2 * sizeof(int));
        requests[i][0] = requestsArr[i][0];
        requests[i][1] = requestsArr[i][1];
        requestsColSize[i] = 2;
    }

    int returnSize;
    bool* res = friendRequests(n, restrictions, restrictionsSize, restrictionsColSize,
                               requests, requestsSize, requestsColSize, &returnSize);

    printf("Result: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%s", res[i] ? "true" : "false");
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    for (int i = 0; i < restrictionsSize; i++) free(restrictions[i]);
    for (int i = 0; i < requestsSize; i++) free(requests[i]);
    free(restrictions);
    free(requests);
    free(res);

    return 0;
}
