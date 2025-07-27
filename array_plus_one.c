/*
Plus One

You are given a large integer represented as an integer array digits, where each digits[i] is the i-th digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order.
Increment the large integer by one and return the resulting array of digits.

Example:
Input: digits = [1,2,3]
Output: [1,2,4]

Input: digits = [9,9,9]
Output: [1,0,0,0]
*/

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }

    int* result = (int*)malloc(sizeof(int) * (digitsSize + 1));
    result[0] = 1;
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }
    *returnSize = digitsSize + 1;
    return result;
}

// Sample test
int main() {
    int digits[] = {9, 9, 9};
    int returnSize;
    int* result = plusOne(digits, 3, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    if (result != digits) free(result);  // Free only if new array was allocated
    return 0;
}
