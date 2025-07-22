// Problem: Couples Holding Hands
// Given an array `row` of even length representing couples in seats, return the minimum number of swaps required to arrange couples side by side.
// Each couple is two consecutive even-odd or odd-even numbers like (0,1), (2,3), etc.
//
// Input: row = [0, 2, 1, 3]
// Output: 1

#include <stdio.h>
#include <stdlib.h>

int minSwapsCouples(int* row, int rowSize) {
    int n = rowSize / 2;
    int* pos = (int*)malloc(sizeof(int) * rowSize);
    for (int i = 0; i < rowSize; i++) {
        pos[row[i]] = i;
    }

    int swaps = 0;
    for (int i = 0; i < rowSize; i += 2) {
        int first = row[i];
        int partner = first ^ 1;  // Partner of even is next odd; of odd is previous even

        if (row[i + 1] != partner) {
            swaps++;

            int partnerPos = pos[partner];

            // Swap positions in row
            pos[row[i + 1]] = partnerPos;
            row[partnerPos] = row[i + 1];

            row[i + 1] = partner;
            pos[partner] = i + 1;
        }
    }

    free(pos);
    return swaps;
}

int main() {
    int row[] = {0, 2, 1, 3};
    int size = sizeof(row) / sizeof(row[0]);

    int result = minSwapsCouples(row, size);
    printf("Minimum swaps required: %d\n", result);  // Output: 1

    return 0;
}
