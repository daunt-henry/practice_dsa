/*
Problem:
Given a preorder traversal of a BST, count how many reorderings of the array
would yield the same BST.

Approach:
- Use divide-and-conquer with combinatorics.
- Recurse left/right and count combinations using Pascal's triangle.

Time Complexity: O(n^2)
Space Complexity: O(n^2)

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX 1001

long long comb[MAX][MAX];

// Precompute Pascal's triangle
void initComb() {
    for (int i = 0; i < MAX; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
}

// Recursive BST reorder counter
long long dfs(int* nums, int size) {
    if (size <= 2) return 1;

    int* left = malloc(size * sizeof(int));
    int* right = malloc(size * sizeof(int));
    int l = 0, r = 0;

    for (int i = 1; i < size; i++) {
        if (nums[i] < nums[0]) left[l++] = nums[i];
        else right[r++] = nums[i];
    }

    long long leftWays = dfs(left, l);
    long long rightWays = dfs(right, r);
    long long totalWays = comb[l + r][l] * leftWays % MOD * rightWays % MOD;

    free(left);
    free(right);
    return totalWays;
}

// Main function
int numOfWays(int* nums, int numsSize) {
    initComb();
    return (dfs(nums, numsSize) - 1 + MOD) % MOD;
}

// Demo
int main() {
    /*
        Input: [2,1,3]
        Possible reorderings to get same BST: 1
        Output: 1
    */

    int nums[] = {2, 1, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = numOfWays(nums, size);
    printf("Number of reorderings: %d\n", result);  // Expected: 1

    return 0;
}
