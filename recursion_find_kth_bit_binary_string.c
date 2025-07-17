/*
Problem: Find K-th Bit in N-th Binary String

S_1 = "0"
S_2 = "0 1 1"
S_3 = "0 1 1 1 1 0 0"
S_4 = "0 1 1 1 1 0 0 1 1 1 1 0 0 0 0"

Recursive rule:
S_n = S_{n-1} + "1" + reverse(invert(S_{n-1}))

Find the K-th bit in S_n.

Example:
Input: n = 4, k = 11
Output: '1'

Explanation:
S_4 = "011110011100100"
11-th bit is '1'
*/

#include <stdio.h>
#include <math.h>

// Recursive function
char findKthBit(int n, int k) {
    if (n == 1) return '0';

    int length = (1 << n) - 1;
    int mid = (length / 2) + 1;

    if (k == mid) return '1';
    if (k < mid) return findKthBit(n - 1, k);

    int mirror = length - k + 1;
    char bit = findKthBit(n - 1, mirror);
    return (bit == '0') ? '1' : '0';
}

// Test function
int main() {
    int n = 4, k = 11;
    char result = findKthBit(n, k);
    printf("The %d-th bit in S_%d is: '%c'\n", k, n, result);
    return 0;
}
