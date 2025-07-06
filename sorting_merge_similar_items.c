/*
Question:
You are given two 2D integer arrays items1 and items2, where each array represents a collection of items.
Each item is represented as a pair of integers [value, weight], where:
- value is the value of the item,
- weight is the number of times that item appears.

Merge the two arrays into a single array of items, combining the weights of items with the same value.
Return the merged array sorted by value.

Approach:
- Use a fixed-size map (since values range from 1 to 1000).
- Merge the weights by value, then output sorted results.

Example:
Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
Output: [[1,6],[3,9],[4,5]]
*/

#include <stdio.h>
#include <stdlib.h>

int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize,
                        int** items2, int items2Size, int* items2ColSize,
                        int* returnSize, int** returnColumnSizes) {
    
    int map[1001] = {0};  // weights from 1 to 1000

    for (int i = 0; i < items1Size; i++) {
        map[items1[i][0]] += items1[i][1];
    }

    for (int i = 0; i < items2Size; i++) {
        map[items2[i][0]] += items2[i][1];
    }

    int count = 0;
    for (int i = 1; i <= 1000; i++) {
        if (map[i]) count++;
    }

    int** res = (int**)malloc(sizeof(int*) * count);
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    int idx = 0;
    for (int i = 1; i <= 1000; i++) {
        if (map[i]) {
            res[idx] = (int*)malloc(sizeof(int) * 2);
            res[idx][0] = i;
            res[idx][1] = map[i];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }
    *returnSize = count;
    return res;
}

/*
Output:
Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
Output: [[1,6],[3,9],[4,5]]
*/
