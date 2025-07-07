/*
Problem:
You're given an array of strings `words`. You may reorder characters in each word independently.

Determine the **maximum number of words** you can turn into palindromes **after reordering**.

A palindrome can have:
- Even length → all characters in pairs.
- Odd length → one odd-count character allowed, others in pairs.

Return the max number of palindromes possible.

Example Input:
words = ["abbb","ba","aa"]

Expected Output:
3

Explanation:
"abbb" → can become "abba"
"ba"   → "ab" → can't be palindrome unless characters are changed → but "abbb" provides enough b's
"aa"   → already palindrome
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxPalindromesAfterOperations(char** words, int wordsSize) {
    int totalFreq[26] = {0};
    int lengths[1000];
    int lenSum = 0;

    for (int i = 0; i < wordsSize; ++i) {
        int len = 0;
        for (int j = 0; words[i][j]; ++j) {
            totalFreq[words[i][j] - 'a']++;
            len++;
        }
        lengths[i] = len;
        lenSum += len;
    }

    int totalPairs = 0;
    for (int i = 0; i < 26; ++i)
        totalPairs += totalFreq[i] / 2;

    qsort(lengths, wordsSize, sizeof(int), compare);

    int answer = 0;
    for (int i = 0; i < wordsSize; ++i) {
        int pairsNeeded = lengths[i] / 2;
        if (totalPairs >= pairsNeeded) {
            totalPairs -= pairsNeeded;
            answer++;
        } else {
            break;
        }
    }

    return answer;
}

int main() {
    char* words[] = {"abbb", "ba", "aa"};
    int size = sizeof(words) / sizeof(words[0]);

    int result = maxPalindromesAfterOperations(words, size);
    printf("Maximum palindromes possible: %d\n", result);
    return 0;
}
