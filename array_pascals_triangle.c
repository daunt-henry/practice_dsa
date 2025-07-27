/*
Problem: Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

Input: numRows = 5
Output:
[
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for(int i = 0; i < numRows; i++) {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for(int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}

int main() {
    int numRows = 5;
    int returnSize;
    int* returnColumnSizes;
    int** result = generate(numRows, &returnSize, &returnColumnSizes);

    printf("Pascal's Triangle:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
    return 0;
}
