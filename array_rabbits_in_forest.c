/*
 * Problem: Rabbits in Forest (LeetCode 781)
 *
 * You ask several rabbits how many other rabbits share their color.
 * Each answer is an integer x, meaning there are x+1 rabbits of that color (including itself).
 * Given the array of answers, return the minimum possible number of rabbits in the forest.
 *
 * Approach:
 * - Count how many rabbits reported each answer (use freq[x]).
 * - For each unique answer x:
 *     * Group size = x + 1
 *     * Number of groups needed = ceil(freq[x] / groupSize)
 *     * Rabbits counted = groups * groupSize
 * - Sum across all answers to get the minimum total rabbits.
 */

#include <stdio.h>
#include <stdlib.h>

int numRabbits(int* answers, int answersSize) {
    int freq[1000] = {0};
    for (int i = 0; i < answersSize; i++) {
        freq[answers[i]]++;
    }

    int total = 0;
    for (int x = 0; x < 1000; x++) {
        if (freq[x] > 0) {
            int groupSize = x + 1;
            int cnt = freq[x];
            int groups = (cnt + groupSize - 1) / groupSize;
            total += groups * groupSize;
        }
    }
    return total;
}

int main(void) {
    int answers1[] = {1, 1, 2};
    int n1 = sizeof(answers1) / sizeof(answers1[0]);
    printf("Answers [1,1,2] → minimum rabbits = %d (expected: 5)\n", numRabbits(answers1, n1));

    int answers2[] = {10, 10, 10};
    int n2 = sizeof(answers2) / sizeof(answers2[0]);
    printf("Answers [10,10,10] → minimum rabbits = %d (expected: 11)\n", numRabbits(answers2, n2));

    int answers3[] = {0, 0, 0};
    int n3 = sizeof(answers3) / sizeof(answers3[0]);
    printf("Answers [0,0,0] → minimum rabbits = %d (expected: 3)\n", numRabbits(answers3, n3));

    return 0;
}
