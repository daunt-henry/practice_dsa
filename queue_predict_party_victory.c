/*
Problem: Dota2 Senate

The Dota2 senate has two parties: Radiant and Dire. Each senator can ban the rights of one opposing senator.
Given the initial sequence, determine which party will win assuming each senator acts optimally.

Example:
Input: "RD"
Output: "Radiant"

Input: "RDD"
Output: "Dire"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* predictPartyVictory(char* senate) {
    int len = strlen(senate);
    int *rQueue = (int*)malloc(len * sizeof(int));
    int *dQueue = (int*)malloc(len * sizeof(int));
    int rFront = 0, rBack = 0, dFront = 0, dBack = 0;

    for (int i = 0; i < len; i++) {
        if (senate[i] == 'R')
            rQueue[rBack++] = i;
        else
            dQueue[dBack++] = i;
    }

    while (rFront < rBack && dFront < dBack) {
        int rIndex = rQueue[rFront++];
        int dIndex = dQueue[dFront++];
        if (rIndex < dIndex)
            rQueue[rBack++] = rIndex + len;
        else
            dQueue[dBack++] = dIndex + len;
    }

    free(rQueue);
    free(dQueue);
    return (rFront < rBack) ? "Radiant" : "Dire";
}

// Test driver
int main() {
    char input1[] = "RD";
    printf("Input: %s\nOutput: %s\n\n", input1, predictPartyVictory(input1));

    char input2[] = "RDD";
    printf("Input: %s\nOutput: %s\n", input2, predictPartyVictory(input2));

    return 0;
}
