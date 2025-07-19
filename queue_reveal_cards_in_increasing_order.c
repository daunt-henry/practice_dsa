/*
Title: Reveal Cards in Increasing Order

Problem:
You are given an integer array deck. There is a deck of cards where every card has a unique integer.
You want to reveal them in increasing order following a process:
1. Reveal the top card and remove it.
2. If any cards remain, move the next top card to the bottom of the deck.
3. Repeat until all cards are revealed.

Return an ordering of the deck so that when the above process is followed, the cards are revealed in increasing order.

Example:
Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]

Explanation:
The order of cards revealed is [2,3,5,7,11,13,17], which matches the sorted deck.

Constraints:
- 1 <= deck.length <= 1000
- 1 <= deck[i] <= 10^6
- All integers in deck are unique.
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    qsort(deck, deckSize, sizeof(int), compare);

    int *res = (int*)malloc(sizeof(int) * deckSize);
    int queue[deckSize], front = 0, rear = 0;

    for (int i = 0; i < deckSize; i++) queue[rear++] = i;

    for (int i = 0; i < deckSize; i++) {
        int pos = queue[front++ % deckSize];
        res[pos] = deck[i];
        if (front < rear) {
            queue[rear++ % deckSize] = queue[front++ % deckSize];
        }
    }

    *returnSize = deckSize;
    return res;
}

int main() {
    int deck[] = {17, 13, 11, 2, 3, 5, 7};
    int size = sizeof(deck) / sizeof(deck[0]);
    int returnSize;

    int *result = deckRevealedIncreasing(deck, size, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i != returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
