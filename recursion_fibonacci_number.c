/*
Problem:
Return the nth number in the Fibonacci sequence.
Base Cases:
- fib(0) = 0
- fib(1) = 1
- fib(n) = fib(n-1) + fib(n-2) for n ≥ 2

Example:
Input: 5 → Output: 5
Sequence: 0, 1, 1, 2, 3, 5

Time Complexity:
Exponential: O(2^n) due to recursive tree without memoization.
*/

#include <stdio.h>

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// Demo
int main() {
    for (int i = 0; i <= 10; i++) {
        printf("fib(%d) = %d\n", i, fib(i));
    }
    return 0;
}
