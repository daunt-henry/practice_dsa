/*
Problem: Min Cost Climbing Stairs (LeetCode 746)
URL: https://leetcode.com/problems/min-cost-climbing-stairs/

Given a cost array where cost[i] is the cost to step on stair i. You can climb 1 or 2 steps at a time.
You may start from step 0 or 1. Compute the minimum cost to reach just beyond the last stair.

Approaches:
- DP with O(n) time, O(1) space using rolling variables `prev2`, `prev1`.
- OR, use memoized recursion or full DP array if needed.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>

int minCostClimbingStairs(int* cost, int costSize) {
    if (costSize == 0) return 0;
    if (costSize == 1) return cost[0];

    int prev2 = cost[0];
    int prev1 = cost[1];
    for (int i = 2; i < costSize; i++) {
        int curr = cost[i] + (prev1 < prev2 ? prev1 : prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1 < prev2 ? prev1 : prev2;
}

int main(void) {
    {
        int cost[] = {10, 15, 20};
        int n = sizeof(cost) / sizeof(cost[0]);
        printf("[10,15,20] → %d (expected: 15)\n", 
               minCostClimbingStairs(cost, n));
    }
    {
        int cost[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        int n = sizeof(cost) / sizeof(cost[0]);
        printf("[1,100,1,1,1,100,1,1,100,1] → %d (expected: 6)\n", 
               minCostClimbingStairs(cost, n));
    }
    return 0;
}
