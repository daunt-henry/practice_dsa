/*
Problem: Find the Winner of the Circular Game

There are `n` friends sitting in a circle. Each person is numbered from 1 to `n`.
Every `k`-th friend will be eliminated in a clockwise manner.
Return the number of the last remaining friend.

This is a classic Josephus Problem.

Formula:
f(n, k) = (f(n-1, k) + k) % n
Base case: f(1, k) = 0
Answer = f(n, k) + 1

Example:
Input: n = 5, k = 2
Output: 3

Explanation:
Friends: 1 2 3 4 5
Eliminate: 2 → 4 → 1 → 5 → Winner: 3
*/

#include <stdio.h>

// Recursive Josephus function
int findTheWinner(int n, int k) {
    if (n == 1) return 1;
    return (findTheWinner(n - 1, k) + k - 1) % n + 1;
}

// Test function
int main() {
    int n = 5, k = 2;
    int winner = findTheWinner(n, k);
    printf("Winner of the circular game with n = %d, k = %d is: %d\n", n, k, winner);
    return 0;
}
