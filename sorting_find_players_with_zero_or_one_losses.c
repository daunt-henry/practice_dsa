/*
Problem:
Given an array of match results [winner, loser], return:
1. Players who never lost.
2. Players who lost exactly once.

Approach:
- Track number of losses for each player.
- Track which players have played.
- Count and collect players with 0 and 1 losses separately.

Input:
matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]

Output:
[[1,2,10],[4,5,7,8]]
*/

#include <stdio.h>
#include <stdlib.h>

int** findWinners(int** matches, int matchesSize, int* matchesColSize, int* returnSize, int** returnColumnSizes){
    int lossCount[100001] = {0};
    int played[100001] = {0};
    int i, winner, loser;

    for (i = 0; i < matchesSize; i++) {
        winner = matches[i][0];
        loser = matches[i][1];
        played[winner] = 1;
        played[loser] = 1;
        lossCount[loser]++;
    }

    int* zeroLoss = (int*)malloc(100001 * sizeof(int));
    int* oneLoss = (int*)malloc(100001 * sizeof(int));
    int zeroCount = 0, oneCount = 0;

    for (i = 0; i <= 100000; i++) {
        if (played[i]) {
            if (lossCount[i] == 0)
                zeroLoss[zeroCount++] = i;
            else if (lossCount[i] == 1)
                oneLoss[oneCount++] = i;
        }
    }

    int** result = (int**)malloc(2 * sizeof(int*));
    result[0] = (int*)malloc(zeroCount * sizeof(int));
    result[1] = (int*)malloc(oneCount * sizeof(int));
    for (i = 0; i < zeroCount; i++)
        result[0][i] = zeroLoss[i];
    for (i = 0; i < oneCount; i++)
        result[1][i] = oneLoss[i];

    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = zeroCount;
    (*returnColumnSizes)[1] = oneCount;

    free(zeroLoss);
    free(oneLoss);

    return result;
}

/*
Example:
Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
*/
