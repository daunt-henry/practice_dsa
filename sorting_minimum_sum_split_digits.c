/*
Problem:
Given a four-digit number, split its digits and rearrange them
to form two new two-digit numbers such that their sum is minimized.

Approach:
1. Extract digits from the number.
2. Sort the digits.
3. Form two numbers:
   - One with digits[0] and digits[2]
   - One with digits[1] and digits[3]
4. Return their sum.

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimumSum(int num) {
    int digits[4];
    for (int i = 0; i < 4; i++) {
        digits[i] = num % 10;
        num /= 10;
    }
    qsort(digits, 4, sizeof(int), compare);
    int num1 = digits[0] * 10 + digits[2];
    int num2 = digits[1] * 10 + digits[3];
    return num1 + num2;
}

// Output Example:
// Input: num = 2932
// Sorted digits: [2, 2, 3, 9]
// Formed: 2_3 = 23, 2_9 = 29
// Output: 52
