#include <stdio.h>
#include <stdlib.h>

// Question:
// Given a matrix, in each operation pick the largest element from any row (only once per row).
// Return the sum of the maximum elements picked from each column after sorting rows in descending order.

// Output:
// For input: [[1,2,3],[4,5,6],[7,8,9]], Output: 18

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;  // Sort in descending order
}

int matrixSum(int** nums, int numsSize, int* numsColSize){
    int n = *numsColSize;
    for (int i = 0; i < numsSize; i++) {
        qsort(nums[i], n, sizeof(int), cmp);
    }

    int sum = 0;
    for (int col = 0; col < n; col++) {
        int maxVal = 0;
        for (int row = 0; row < numsSize; row++) {
            if (nums[row][col] > maxVal)
                maxVal = nums[row][col];
        }
        sum += maxVal;
    }

    return sum;
}

// ---------- Main Test ----------
int main() {
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8, 9};
    int* matrix[] = {row1, row2, row3};
    int cols = 3;

    int result = matrixSum(matrix, 3, &cols);
    printf("%d\n", result); // Output: 18

    return 0;
}
