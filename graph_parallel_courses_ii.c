/*
Parallel Courses II

There are n courses labeled from 1 to n and a list of dependencies. You must take at most k courses per semester, and some courses depend on others. Return the minimum number of semesters needed to complete all courses.

Example:
Input:
    n = 4,
    dependencies = [[2,1],[3,1],[1,4]],
    k = 2
Output: 3
Explanation:
    Take courses [2,3] in semester 1
    Take course [1] in semester 2
    Take course [4] in semester 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int dp[1 << 15];
int prereq[15];
int n, k;

int countBits(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int dfs(int mask) {
    if (mask == (1 << n) - 1)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];

    int avail = 0;
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0 && (prereq[i] & mask) == prereq[i]) {
            avail |= (1 << i);
        }
    }

    int res = INT_MAX;
    for (int subset = avail; subset; subset = (subset - 1) & avail) {
        if (countBits(subset) <= k) {
            res = fmin(res, 1 + dfs(mask | subset));
        }
    }

    if (avail == 0)
        res = fmin(res, 1 + dfs(mask));

    return dp[mask] = res;
}

int minNumberOfSemesters(int N, int** dependencies, int depSize, int* depColSize, int K) {
    n = N;
    k = K;
    memset(prereq, 0, sizeof(prereq));
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < depSize; i++) {
        int u = dependencies[i][0] - 1;
        int v = dependencies[i][1] - 1;
        prereq[v] |= (1 << u);
    }

    return dfs(0);
}

int main() {
    int depArr[][2] = {{2,1},{3,1},{1,4}};
    int depSize = 3, depColSize = 2, k = 2, n = 4;

    int* dependencies[depSize];
    for (int i = 0; i < depSize; i++)
        dependencies[i] = depArr[i];

    int result = minNumberOfSemesters(n, dependencies, depSize, &depColSize, k);
    printf("Minimum semesters needed: %d\n", result);  // Output: 3

    return 0;
}
