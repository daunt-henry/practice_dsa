/*
Problem:
Convert a non-negative integer to its English words representation.

Example:
Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Approach:
- Divide the number into chunks of 3 digits from the end.
- Convert each chunk to English using a helper function.
- Combine with "Thousand", "Million", "Billion" as needed.

Time Complexity: O(log n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* below_20[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                    "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

char* tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

char* thousands[] = {"", "Thousand", "Million", "Billion"};

void helper(int num, char* res) {
    if (num == 0) return;
    if (num < 20) {
        strcat(res, below_20[num]);
        strcat(res, " ");
    } else if (num < 100) {
        strcat(res, tens[num / 10]);
        strcat(res, " ");
        helper(num % 10, res);
    } else {
        strcat(res, below_20[num / 100]);
        strcat(res, " Hundred ");
        helper(num % 100, res);
    }
}

char* numberToWords(int num) {
    if (num == 0) return strdup("Zero");
    char* res = calloc(1024, sizeof(char));
    int i = 0;

    while (num > 0) {
        if (num % 1000 != 0) {
            char* temp = calloc(1024, sizeof(char));
            helper(num % 1000, temp);
            strcat(temp, thousands[i]);
            strcat(temp, " ");
            strcat(temp, res);
            strcpy(res, temp);
            free(temp);
        }
        num /= 1000;
        i++;
    }

    int len = strlen(res);
    while (len > 0 && res[len - 1] == ' ') res[--len] = '\0';

    return res;
}

// Demo
int main() {
    int num = 1234567;
    char* result = numberToWords(num);
    printf("Number: %d\nEnglish: %s\n", num, result);
    free(result);
    return 0;
}
