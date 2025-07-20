/*
Title: Largest Rectangle in Histogram

Description:
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10

Example 2:
Input: heights = [2,4]
Output: 4
*/

#include <stdio.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int stack[heightsSize + 1];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        int h = (i == heightsSize) ? 0 : heights[i];
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

int main() {
    int heights1[] = {2, 1, 5, 6, 2, 3};
    int heights2[] = {2, 4};

    printf("Max Area (Example 1): %d\n", largestRectangleArea(heights1, 6)); // Output: 10
    printf("Max Area (Example 2): %d\n", largestRectangleArea(heights2, 2)); // Output: 4

    return 0;
}
