/*
Problem: Count Good Numbers

A number of length `n` is good if:
- All digits at even indices (0-based) are EVEN digits → 0, 2, 4, 6, 8 (5 options)
- All digits at odd indices are PRIME digits → 2, 3, 5, 7 (4 options)

We need to count how many such numbers of length `n` exist.
Return the result modulo 10^9 + 7.

Approach:
Let evenCount = (n + 1) / 2
Let oddCount = n / 2

Total = (5^evenCount) * (4^oddCount) % MOD
*/

#include <stdio.h>

#define MOD 1000000007
typedef long long ll;

// Recursive fast power with modulo
ll power(ll base, ll exp) {
    if (exp == 0) return 1;
    ll half = power(base, exp / 2);
    ll result = (half * half) % MOD;
    if (exp % 2 == 1)
        result = (result * base) % MOD;
    return result;
}

// Main function
int countGoodNumbers(long long n) {
    ll evenCount = (n + 1) / 2;
    ll oddCount = n / 2;

    ll evens = power(5, evenCount);
    ll odds = power(4, oddCount);

    return (int)((evens * odds) % MOD);
}

// Test code
int main() {
    long long n = 50;
    int result = countGoodNumbers(n);
    printf("Number of good numbers of length %lld = %d\n", n, result);
    return 0;
}
