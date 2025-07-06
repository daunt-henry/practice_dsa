// smallest_value_of_the_rearranged_number.c

/*
Problem:
Given an integer num, rearrange the digits of num such that its value is minimized 
if num is positive or maximized if num is negative. The rearranged number must not 
contain any leading zeros.

Return the rearranged number with the correct sign.

Example:
Input: num = 310
Output: 103

Input: num = -7605
Output: -7650
*/

#include <stdio.h>
#include <stdlib.h>

int cmp_asc(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

int cmp_desc(const void* a, const void* b) {
    return (*(char*)b - *(char*)a);
}

long long smallestNumber(long long num){
    if (num == 0) return 0;

    char digits[20];
    int len = 0;
    long long abs_num = num < 0 ? -num : num;

    // Extract digits
    while (abs_num > 0) {
        digits[len++] = (abs_num % 10) + '0';
        abs_num /= 10;
    }

    // Sort digits
    if (num > 0) {
        qsort(digits, len, sizeof(char), cmp_asc);
        if (digits[0] == '0') {
            for (int i = 1; i < len; i++) {
                if (digits[i] != '0') {
                    char temp = digits[0];
                    digits[0] = digits[i];
                    digits[i] = temp;
                    break;
                }
            }
        }
    } else {
        qsort(digits, len, sizeof(char), cmp_desc);
    }

    // Build result
    long long result = 0;
    for (int i = 0; i < len; i++) {
        result = result * 10 + (digits[i] - '0');
    }

    return num > 0 ? result : -result;
}

/*
Test Cases:
Input: 310      => Output: 103
Input: -7605    => Output: -7650
Input: 0        => Output: 0
*/
