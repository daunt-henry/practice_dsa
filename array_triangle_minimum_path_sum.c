/*
Problem: Triangle

Given a triangle array, return the minimum path sum from top to bottom.

Each step you may move to adjacent numbers on the row below.

Input:
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
Output: 11
Explanation: 2 + 3 + 5 + 1 = 11
*/

#include <stdio.h>
#include <stdlib.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j < triangleColSize[i]; j++) {
            triangle[i][j] += triangle[i + 1][j] < triangle[i + 1][j + 1] ?
                              triangle[i + 1][j] : triangle[i + 1][j + 1];
        }
    }
    return triangle[0][0];
}

// Test driver
int main() {
    int triangleSize = 4;
    int triangleColSize[] = {1, 2, 3, 4};

    int** triangle = (int**)malloc(sizeof(int*) * triangleSize);
    triangle[0] = (int[]){2};
    triangle[1] = (int[]){3, 4};
    triangle[2] = (int[]){6, 5, 7};
    triangle[3] = (int[]){4, 1, 8, 3};

    int result = minimumTotal(triangle, triangleSize, triangleColSize);
    printf("Minimum path total: %d\n", result);  // Output: 11

    free(triangle);
    return 0;
}
