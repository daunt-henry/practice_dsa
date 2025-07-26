/*
Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that
the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Example:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Explanation: The maximum area is formed between height[1] (8) and height[8] (7),
which is min(8,7) * (8 - 1) = 7 * 7 = 49

Filename: container_with_most_water.c
*/

#include <stdio.h>

// Two-pointer approach
int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize - 1;
    int maxArea = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int w = right - left;
        int area = h * w;
        if (area > maxArea)
            maxArea = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxArea;
}

// Sample test
int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    int result = maxArea(height, sizeof(height)/sizeof(height[0]));
    printf("Max Area: %d\n", result);  // Output: 49
    return 0;
}
