/*
Problem:
Start with a list from 1 to n. Every round, remove every second number,
alternating direction (left→right, then right→left).
Return the last number remaining.

Example:
Input: 9 → Output: 6

Approach (Recursive):
Let f(n) be the answer.
- From left to right: new list becomes [2, 4, 6, ...]
- Then reverse and recurse on f(n/2)

Recurrence:
f(n) = 2 * (1 + n/2 - f(n/2))

Time Complexity: O(log n)
*/

#include <stdio.h>

int lastRemaining(int n) {
    if (n == 1) return 1;
    return 2 * (1 + n / 2 - lastRemaining(n / 2));
}

// Demo
int main() {
    int test_vals[] = {1, 9, 10, 24, 1000};
    for (int i = 0; i < 5; i++) {
        int n = test_vals[i];
        printf("Last remaining for n = %d → %d\n", n, lastRemaining(n));
    }
    return 0;
}
