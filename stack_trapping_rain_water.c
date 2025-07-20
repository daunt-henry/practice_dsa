/*
Title: Trapping Rain Water

Description:
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
*/

#include <stdio.h>

int trap(int* height, int heightSize) {
    if (heightSize == 0) return 0;

    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0, water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];
            right--;
        }
    }

    return water;
}

int main() {
    int height1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int height2[] = {4,2,0,3,2,5};
    
    printf("Trapped water (example 1): %d\n", trap(height1, sizeof(height1)/sizeof(int)));
    printf("Trapped water (example 2): %d\n", trap(height2, sizeof(height2)/sizeof(int)));

    return 0;
}
