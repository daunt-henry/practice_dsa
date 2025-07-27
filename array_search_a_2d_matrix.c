/*
Problem: Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

Example:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int m = matrixSize;
    int n = matrixColSize[0];
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_value = matrix[mid / n][mid % n];

        if (mid_value == target)
            return true;
        else if (mid_value < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

// Example test
int main() {
    int data[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int* matrix[3] = { data[0], data[1], data[2] };
    int colSize[3] = {4, 4, 4};

    int target = 3;
    bool found = searchMatrix(matrix, 3, colSize, target);
    printf("Target %d %s in matrix.\n", target, found ? "found" : "not found");
    return 0;
}
