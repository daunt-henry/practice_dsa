/*
Problem: Candy

There are n children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to distribute.

Example:
Input: ratings = [1,0,2]
Output: 5

Input: ratings = [1,2,2]
Output: 4
*/

#include <stdio.h>

int candy(int* ratings, int ratingsSize) {
    if (ratingsSize == 0) return 0;

    int candies[ratingsSize];
    for (int i = 0; i < ratingsSize; i++)
        candies[i] = 1;

    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;
    }

    int total = 0;
    for (int i = 0; i < ratingsSize; i++)
        total += candies[i];

    return total;
}

int main() {
    int ratings[] = {1, 0, 2};
    int n = sizeof(ratings) / sizeof(ratings[0]);
    printf("Minimum candies needed: %d\n", candy(ratings, n));  // Output: 5

    int ratings2[] = {1, 2, 2};
    int m = sizeof(ratings2) / sizeof(ratings2[0]);
    printf("Minimum candies needed: %d\n", candy(ratings2, m));  // Output: 4

    return 0;
}
