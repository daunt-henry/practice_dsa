/*
Title: Maximal Rectangle

Description:
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's
and return its area.

Example:
Input:
matrix = [
  ['1','0','1','0','0'],
  ['1','0','1','1','1'],
  ['1','1','1','1','1'],
  ['1','0','0','1','0']
]
Output: 6
*/

#include <stdio.h>

int largestRectangleArea(int* heights, int size) {
    int stack[size + 1], top = -1, maxArea = 0;

    for (int i = 0; i <= size; ++i) {
        int h = (i == size) ? 0 : heights[i];
        while (top >= 0 && heights[stack[top]] > h) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea) maxArea = area;
        }
        stack[++top] = i;
    }

    return maxArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0 || *matrixColSize == 0) return 0;
    int cols = *matrixColSize;
    int heights[cols];
    for (int i = 0; i < cols; ++i) heights[i] = 0;

    int maxArea = 0;
    for (int row = 0; row < matrixSize; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (matrix[row][col] == '1') heights[col]++;
            else heights[col] = 0;
        }
        int area = largestRectangleArea(heights, cols);
        if (area > maxArea) maxArea = area;
    }

    return maxArea;
}

// Sample usage (basic simulation)
int main() {
    char* matrix[] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };
    int rows = 4;
    int cols = 5;
    int colSize = cols;

    char* inputMatrix[rows];
    for (int i = 0; i < rows; ++i) inputMatrix[i] = matrix[i];

    int result = maximalRectangle(inputMatrix, rows, &colSize);
    printf("Maximal Rectangle Area: %d\n", result);  // Output: 6

    return 0;
}
