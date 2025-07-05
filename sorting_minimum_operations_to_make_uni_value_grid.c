/*
Problem:
You are given a 2D grid and an integer x.
You can perform the operation: increase or decrease an element by x any number of times.
Return the minimum number of operations to make all grid elements equal.
Return -1 if it's impossible.

Approach:
- Flatten the 2D grid into a 1D array.
- Check if all elements modulo x are equal.
- Use median as the target value to minimize total moves.

Example:
Input: grid = [[2,4],[6,8]], x = 2
Output: 4
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x){
    int m = gridSize;
    int n = gridColSize[0];
    int size = m * n;
    int* nums = (int*)malloc(sizeof(int) * size);
    int index = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            nums[index++] = grid[i][j];
        }
    }

    for(int i = 1; i < size; i++){
        if ((nums[i] - nums[0]) % x != 0){
            free(nums);
            return -1;
        }
    }

    qsort(nums, size, sizeof(int), cmp);
    int median = nums[size / 2];
    int operations = 0;

    for(int i = 0; i < size; i++){
        operations += abs(nums[i] - median) / x;
    }

    free(nums);
    return operations;
}

/*
Sample Input:
grid = [[2,4],[6,8]]
x = 2
Output: 4
*/
