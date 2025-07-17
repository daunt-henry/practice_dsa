/*
Problem: K-th Symbol in Grammar

You are given two integers n and k.
Return the k-th symbol in the n-th row of a binary grammar.

Grammar Rule:
- Row 1: 0
- Replace 0 -> 01, and 1 -> 10 for the next row

Example:
Input: n = 4, k = 5
Output: 1

Explanation:
Row 1:        0
Row 2:      0 1
Row 3:    0 1 1 0
Row 4:  0 1 1 0 1 0 0 1
                  ^
                k = 5 => 1
*/

#include <stdio.h>

// Recursive function
int kthGrammar(int n, int k) {
    if (n == 1) return 0;

    int parent = kthGrammar(n - 1, (k + 1) / 2);

    if (k % 2 == 0)
        return parent ^ 1;
    else
        return parent;
}

// Test function
int main() {
    int n = 4, k = 5;
    int result = kthGrammar(n, k);
    printf("The %d-th symbol in row %d is: %d\n", k, n, result);
    return 0;
}
