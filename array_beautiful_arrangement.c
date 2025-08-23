/*
Beautiful Arrangement (LeetCode 526)

Problem:
Count how many permutations of {1,...,n} (for 1 ≤ n ≤ 15) satisfy:
for every position i (1-indexed), either perm[i] is divisible by i, or i is divisible by perm[i].

Approach:
Use backtracking (depth-first search) with a visited array to generate permutations one position at a time,
ensuring divisibility conditions at each step.

Time Complexity: ~O(n · 2ⁿ), Space Complexity: O(n) for recursion and visitation tracking.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int dfs(int pos, int n, bool* used) {
    if (pos > n) return 1;
    int count = 0;
    for (int num = 1; num <= n; num++) {
        if (!used[num] && (num % pos == 0 || pos % num == 0)) {
            used[num] = true;
            count += dfs(pos + 1, n, used);
            used[num] = false;
        }
    }
    return count;
}

int countArrangement(int n) {
    bool* used = calloc(n + 1, sizeof(bool));
    int result = dfs(1, n, used);
    free(used);
    return result;
}

int main(void) {
    int n1 = 2;
    printf("n = %d, Beautiful Arrangements = %d (expected 2)\n", n1, countArrangement(n1));
    int n2 = 3;
    printf("n = %d, Beautiful Arrangements = %d (expected 3)\n", n2, countArrangement(n2));  
    // For n = 3, the valid arrangements are [1,2,3], [2,1,3], [3,2,1].

    return 0;
}
