/*
Best Team With No Conflicts

Problem:
Form a team with players such that no younger player has a strictly higher score than an older player.
Return the maximum total score of such a team.

Approach:
1. Pair each player's age and score.
2. Sort players by age, breaking ties with score.
3. Use DP (similar to LIS) where dp[i] is the best score ending with player i.
4. A valid previous player j must have score[j] ≤ score[i].

Time Complexity: O(n^2)
Space Complexity: O(n)

Example:
Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int score;
    int age;
} Player;

int compare(const void* a, const void* b) {
    Player* p1 = (Player*)a;
    Player* p2 = (Player*)b;
    if (p1->age == p2->age) return p1->score - p2->score;
    return p1->age - p2->age;
}

int bestTeamScore(int* scores, int scoresSize, int* ages, int agesSize) {
    Player players[scoresSize];
    for (int i = 0; i < scoresSize; i++) {
        players[i].score = scores[i];
        players[i].age = ages[i];
    }

    qsort(players, scoresSize, sizeof(Player), compare);

    int dp[scoresSize];
    int maxScore = 0;

    for (int i = 0; i < scoresSize; i++) {
        dp[i] = players[i].score;
        for (int j = 0; j < i; j++) {
            if (players[j].score <= players[i].score) {
                if (dp[i] < dp[j] + players[i].score)
                    dp[i] = dp[j] + players[i].score;
            }
        }
        if (dp[i] > maxScore) maxScore = dp[i];
    }

    return maxScore;
}
