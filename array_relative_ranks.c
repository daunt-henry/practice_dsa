/*
Problem: Relative Ranks
URL: https://leetcode.com/problems/relative-ranks/

Description:
You are given an integer array `score` of size n, where score[i] is the score of the ith athlete in a competition.
Return an array `answer` of size n where answer[i] is the rank of the ith athlete.

The top three athletes get medals:
- "Gold Medal"
- "Silver Medal"
- "Bronze Medal"
The rest get their rank number (as a string).

Example:
Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]

Explanation:
- 1st place: score=10 → "Gold Medal"
- 2nd place: score=9  → "Silver Medal"
- 3rd place: score=8  → "Bronze Medal"
- 4th place: score=4  → "4"
- 5th place: score=3  → "5"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;

    char** result = (char**)malloc(scoreSize * sizeof(char*));
    int* indices = (int*)malloc(scoreSize * sizeof(int));

    for (int i = 0; i < scoreSize; i++) {
        indices[i] = i;
    }

    // Sort indices based on score values (descending)
    for (int i = 0; i < scoreSize; i++) {
        for (int j = i + 1; j < scoreSize; j++) {
            if (score[indices[i]] < score[indices[j]]) {
                int tmp = indices[i];
                indices[i] = indices[j];
                indices[j] = tmp;
            }
        }
    }

    for (int i = 0; i < scoreSize; i++) {
        result[indices[i]] = (char*)malloc(15 * sizeof(char));
        if (i == 0) {
            strcpy(result[indices[i]], "Gold Medal");
        } else if (i == 1) {
            strcpy(result[indices[i]], "Silver Medal");
        } else if (i == 2) {
            strcpy(result[indices[i]], "Bronze Medal");
        } else {
            sprintf(result[indices[i]], "%d", i + 1);
        }
    }

    free(indices);
    return result;
}

int main() {
    int score[] = {10, 3, 8, 9, 4};
    int n = sizeof(score) / sizeof(score[0]);
    int returnSize;

    char** ranks = findRelativeRanks(score, n, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", ranks[i]);
        if (i < returnSize - 1) printf(", ");
        free(ranks[i]); // free allocated memory
    }
    printf("]\n");

    free(ranks);
    return 0;
}

/*
Sample Run:
Input: [10, 3, 8, 9, 4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
*/
