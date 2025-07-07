/*
Problem:
You are given two integer arrays:
- `players[i]` is the ability of the i-th player
- `trainers[j]` is the training capacity of the j-th trainer

A player can be matched with a trainer if:
trainer[j] >= player[i]

Each player and trainer can be matched **at most once**.
Return the **maximum number of matchings** possible.

Example Input:
players = [4, 7, 9]
trainers = [8, 2, 5, 8]

Expected Output:
2

Explanation:
Match player[0]=4 with trainer[2]=5, and player[1]=7 with trainer[0]=8
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize) {
    qsort(players, playersSize, sizeof(int), cmp);
    qsort(trainers, trainersSize, sizeof(int), cmp);

    int i = 0, j = 0, count = 0;

    while (i < playersSize && j < trainersSize) {
        if (trainers[j] >= players[i]) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }
    }

    return count;
}

int main() {
    int players[] = {4, 7, 9};
    int trainers[] = {8, 2, 5, 8};
    int pSize = sizeof(players) / sizeof(players[0]);
    int tSize = sizeof(trainers) / sizeof(trainers[0]);

    int result = matchPlayersAndTrainers(players, pSize, trainers, tSize);
    printf("Maximum matchings: %d\n", result);

    return 0;
}
