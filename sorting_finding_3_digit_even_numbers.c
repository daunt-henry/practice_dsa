/*
Problem: Finding 3-Digit Even Numbers

Given an array of digits (0-9), return all **unique** 3-digit even numbers 
that can be formed using the digits **at most once**.

Approach:
- Count frequency of each digit
- Loop from 100 to 998 (even numbers only)
- For each number, check if digits exist in original array (not exceeding frequency)
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize){
    int count[10] = {0};
    for (int i = 0; i < digitsSize; ++i)
        count[digits[i]]++;

    int* result = malloc(900 * sizeof(int));
    int index = 0;

    for (int num = 100; num <= 998; num += 2) {
        int d1 = num / 100;
        int d2 = (num / 10) % 10;
        int d3 = num % 10;

        int tempCount[10];
        memcpy(tempCount, count, sizeof(count));

        if (tempCount[d1]-- > 0 && tempCount[d2]-- > 0 && tempCount[d3]-- > 0)
            result[index++] = num;
    }

    *returnSize = index;
    return result;
}

// Sample Output:
// Input: digits = [2,1,3,0]
// Output: [102,120,130,132,210,230,302,310,312,320]
