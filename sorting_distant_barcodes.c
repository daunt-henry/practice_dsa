/*
Problem:
Rearrange barcodes such that no two adjacent barcodes are the same.

Approach:
- Count frequency of each barcode.
- Sort barcodes by frequency (most frequent first).
- Fill even indices first, then odd.
- Guarantees no two adjacent elements are the same.

Time: O(n log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpByFreqDesc(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return y[1] - x[1];  // sort descending by frequency
}

int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize) {
    int count[10001] = {0};
    for (int i = 0; i < barcodesSize; i++) {
        count[barcodes[i]]++;
    }

    int** freqList = (int**)malloc(sizeof(int*) * barcodesSize);
    int freqCount = 0;

    for (int i = 0; i <= 10000; i++) {
        if (count[i] > 0) {
            freqList[freqCount] = (int*)malloc(sizeof(int) * 2);
            freqList[freqCount][0] = i;
            freqList[freqCount][1] = count[i];
            freqCount++;
        }
    }

    qsort(freqList, freqCount, sizeof(int*), cmpByFreqDesc);

    int* result = (int*)malloc(sizeof(int) * barcodesSize);
    int index = 0;

    for (int i = 0; i < freqCount; i++) {
        while (freqList[i][1] > 0) {
            result[index] = freqList[i][0];
            freqList[i][1]--;
            index += 2;
            if (index >= barcodesSize) {
                index = 1;
            }
        }
        free(freqList[i]);
    }

    free(freqList);
    *returnSize = barcodesSize;
    return result;
}

// Test
int main() {
    int barcodes[] = {1, 1, 1, 2, 2, 3};
    int size = sizeof(barcodes) / sizeof(barcodes[0]);
    int returnSize;
    int* result = rearrangeBarcodes(barcodes, size, &returnSize);

    printf("Rearranged barcodes:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Rearranged barcodes:
1 2 1 2 1 3
(or any valid non-adjacent repeat arrangement)
==========================
*/
