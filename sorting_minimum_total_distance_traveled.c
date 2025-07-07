/*
Problem:
You are given:
- An array `robots`, where robots[i] is the position of the i-th robot.
- A 2D array `factories`, where factories[j][0] is the position and factories[j][1] is the max number of robots it can repair.

Each robot must be assigned to exactly one factory. The total cost is the sum of distances between robots and the factories they are assigned to.

Return the **minimum total distance** to repair all robots.

Example Input:
robots = [0,4,6]
factories = [[2,2],[6,2]]

Expected Output:
4

Explanation:
Assign:
- Robot at 0 → Factory at 2 → Distance 2
- Robot at 4 → Factory at 2 → Distance 2
- Robot at 6 → Factory at 6 → Distance 0
Total = 2 + 2 + 0 = 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long dp[301][301];

long long dfs(int i, int j, int* robots, int robotsSize, int** factories, int factoriesSize) {
    if (i == robotsSize) return 0;
    if (j == factoriesSize) return 1e18;

    if (dp[i][j] != -1) return dp[i][j];

    long long res = dfs(i, j + 1, robots, robotsSize, factories, factoriesSize);
    long long dist = 0;

    for (int k = 0; k < factories[j][1] && i + k < robotsSize; ++k) {
        dist += abs(robots[i + k] - factories[j][0]);
        res = fmin(res, dist + dfs(i + k + 1, j + 1, robots, robotsSize, factories, factoriesSize));
    }

    return dp[i][j] = res;
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int cmp2(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

long long minimumTotalDistance(int* robot, int robotSize, int** factory, int factorySize, int* factoryColSize) {
    qsort(robot, robotSize, sizeof(int), cmp);
    qsort(factory, factorySize, sizeof(int*), cmp2);

    for (int i = 0; i <= robotSize; ++i)
        for (int j = 0; j <= factorySize; ++j)
            dp[i][j] = -1;

    return dfs(0, 0, robot, robotSize, factory, factorySize);
}

int main() {
    int robots[] = {0, 4, 6};
    int robotSize = sizeof(robots) / sizeof(robots[0]);

    int factoryData[2][2] = {{2, 2}, {6, 2}};
    int* factories[2];
    for (int i = 0; i < 2; ++i)
        factories[i] = factoryData[i];

    int factoryCols[] = {2, 2};

    long long result = minimumTotalDistance(robots, robotSize, factories, 2, factoryCols);
    printf("Minimum total distance: %lld\n", result);
    return 0;
}
