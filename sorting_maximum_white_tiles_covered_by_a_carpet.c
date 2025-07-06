/*
Problem:
You are given a 2D integer array tiles where tiles[i] = [start_i, end_i] represents a white tile from start_i to end_i (inclusive).
You are also given an integer carpetLen, the length of a single carpet.

Return the maximum number of white tiles that can be covered by the carpet.

Approach:
- Sort the tiles by starting point.
- Use a prefix sum to keep track of total tiles covered.
- For each tile, try to cover as many tiles as possible using the carpet.
- Use two pointers to track valid window and calculate maximum tiles covered.

Time Complexity: O(N log N), where N is number of tile intervals.

Example:
Input: tiles = [[1,5],[10,11],[12,18],[20,25]], carpetLen = 10  
Output: 9
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int maximumWhiteTiles(int** tiles, int tilesSize, int* tilesColSize, int carpetLen) {
    qsort(tiles, tilesSize, sizeof(int*), compare);
    
    int* prefix = (int*)malloc(sizeof(int) * (tilesSize + 1));
    prefix[0] = 0;
    for (int i = 0; i < tilesSize; i++) {
        prefix[i + 1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);
    }

    int res = 0, j = 0;
    for (int i = 0; i < tilesSize; i++) {
        int end = tiles[i][0] + carpetLen - 1;
        while (j < tilesSize && tiles[j][1] < end) j++;

        int total = 0;
        if (j < tilesSize && tiles[j][0] <= end) {
            int partial = end - tiles[j][0] + 1;
            total = prefix[j] - prefix[i] + partial;
        } else {
            total = prefix[j] - prefix[i];
        }

        if (total > res) res = total;
    }

    free(prefix);
    return res;
}

/*
Output:
Input: tiles = [[1,5],[10,11],[12,18],[20,25]], carpetLen = 10
Output: 9
*/
