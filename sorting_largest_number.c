/*
Problem: Largest Number

Description:
Given a list of non-negative integers, arrange them such that they form the largest number.

Example:
Input: [3,30,34,5,9]
Output: "9534330"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom comparator for sorting strings
int compare(const void* a, const void* b) {
    char ab[21], ba[21];
    sprintf(ab, "%s%s", *(char**)a, *(char**)b);
    sprintf(ba, "%s%s", *(char**)b, *(char**)a);
    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
    char** strNums = malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        strNums[i] = malloc(12);
        sprintf(strNums[i], "%d", nums[i]);
    }

    qsort(strNums, numsSize, sizeof(char*), compare);

    if (strcmp(strNums[0], "0") == 0) {
        char* zeroResult = malloc(2);
        strcpy(zeroResult, "0");
        for (int i = 0; i < numsSize; i++) free(strNums[i]);
        free(strNums);
        return zeroResult;
    }

    int totalLen = 0;
    for (int i = 0; i < numsSize; i++) totalLen += strlen(strNums[i]);

    char* result = malloc(totalLen + 1);
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strNums[i]);
        free(strNums[i]);
    }

    free(strNums);
    return result;
}

int main() {
    int nums[] = {3, 30, 34, 5, 9};
    int size = sizeof(nums) / sizeof(nums[0]);

    char* result = largestNumber(nums, size);
    printf("Largest Number: %s\n", result);
    free(result);
    return 0;
}

/*
========= OUTPUT =========
Largest Number: 9534330
==========================
*/
