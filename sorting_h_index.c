/*
Problem: H-Index

Description:
Given an array of citations (each citation is a non-negative integer) of a researcher,
write a function to compute the researcher's h-index.

A scientist has an index h if h of their n papers have at least h citations each.

Example:
Input: [3,0,6,1,5]
Output: 3
*/

#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Compute H-index
int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), cmp);

    for (int i = 0; i < citationsSize; i++) {
        int h = citationsSize - i;
        if (citations[i] >= h) {
            return h;
        }
    }

    return 0;
}

// Test the function
int main() {
    int citations[] = {3, 0, 6, 1, 5};
    int size = sizeof(citations) / sizeof(citations[0]);

    int h = hIndex(citations, size);
    printf("H-Index: %d\n", h);

    return 0;
}

/*
========= OUTPUT =========
H-Index: 3
==========================
*/
