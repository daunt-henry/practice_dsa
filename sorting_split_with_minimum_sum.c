// Problem: Split With Minimum Sum
/*
You are given a positive integer `num`. Split it into two non-empty parts by 
rearranging its digits, then return the *minimum* possible sum of the two numbers.

Constraints:
- Rearranged digits must use all original digits
- Each part must be non-empty

Example:
Input: num = 4325
Output: 59
Explanation: Split into "24" and "35", sum = 59.

Approach:
1. Convert number to digit characters.
2. Sort the digits to make the smallest possible numbers.
3. Alternate digit placement into two numbers for minimal total.
4. Return their sum.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

int splitNum(int num) {
    char digits[12];
    sprintf(digits, "%d", num);
    int len = strlen(digits);
    
    qsort(digits, len, sizeof(char), cmp);
    
    int num1 = 0, num2 = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0)
            num1 = num1 * 10 + (digits[i] - '0');
        else
            num2 = num2 * 10 + (digits[i] - '0');
    }
    
    return num1 + num2;
}

// Sample test
int main() {
    int num = 4325;
    int result = splitNum(num);
    printf("Output: %d\n", result);  // Expected Output: 59
    return 0;
}
