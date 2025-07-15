/*
Problem:
Count how many times digit '1' appears from 1 to n.

Approach:
Go digit by digit (unit, tens, hundreds...):
- For each position, calculate high, current, and low parts of number.
- Apply formula based on the current digit value.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <stdio.h>

int countDigitOne(int n) {
    long digit = 1;
    int res = 0;
    int high = n / 10, cur = n % 10, low = 0;

    while (n / digit) {
        cur = (n / digit) % 10;
        high = n / (digit * 10);
        low = n % digit;

        if (cur == 0) {
            res += high * digit;
        } else if (cur == 1) {
            res += high * digit + low + 1;
        } else {
            res += (high + 1) * digit;
        }

        digit *= 10;
    }

    return res;
}

// Demo
int main() {
    int n = 13;
    int result = countDigitOne(n);
    printf("Number of '1's from 1 to %d: %d\n", n, result);  // Output: 6
    return 0;
}
