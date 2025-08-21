/*
Matchsticks to Square (LeetCode 473)

Given an array of matchsticks, determine if it's possible to form a square
using all of them exactly once (four sides of equal length).

Approach:
1. Check basic constraints (sum divisible by 4, max stick ≤ target side length).
2. Sort sticks descending—prune faster.
3. Use DFS + backtracking: try each stick in 4 sides, with pruning to skip duplicate states.

Time Complexity: ~O(4^n) in worst case, with optimizations via sorting and pruning. 2
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmpdesc(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

bool dfs(int* sticks, int sticksSize, int idx, int* sides, int target) {
    if (idx == sticksSize) {
        return sides[0] == target && sides[1] == target &&
               sides[2] == target && sides[3] == target;
    }
    int cur = sticks[idx];
    for (int i = 0; i < 4; i++) {
        if (sides[i] + cur > target) continue;
        if (i > 0 && sides[i] == sides[i - 1]) continue;
        sides[i] += cur;
        if (dfs(sticks, sticksSize, idx + 1, sides, target)) return true;
        sides[i] -= cur;
    }
    return false;
}

bool makesquare(int* sticks, int sticksSize) {
    if (sticksSize < 4) return false;
    int sum = 0, maxv = 0;
    for (int i = 0; i < sticksSize; i++) {
        sum += sticks[i];
        if (sticks[i] > maxv) maxv = sticks[i];
    }
    if (sum % 4 != 0) return false;
    int target = sum / 4;
    if (maxv > target) return false;

    qsort(sticks, sticksSize, sizeof(int), cmpdesc);

    int sides[4] = {0};
    return dfs(sticks, sticksSize, 0, sides, target);
}

int main(void) {
    int arr1[] = {1,1,2,2,2};
    int n1 = sizeof(arr1)/sizeof(int);
    printf("Can form square? %s (expected true)\n", makesquare(arr1, n1) ? "true" : "false");

    int arr2[] = {3,3,3,3,4};
    int n2 = sizeof(arr2)/sizeof(int);
    printf("Can form square? %s (expected false)\n", makesquare(arr2, n2) ? "true" : "false");

    return 0;
}
