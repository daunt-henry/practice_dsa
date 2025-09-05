/*
Problem: Most Common Word

Given a paragraph and a list of banned words, return the most frequent word that is not banned. 
It is guaranteed there is at least one word that isn’t banned, and that the answer is unique.

Example:
Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"

Explanation: 
"hit" occurs 3 times but it is banned.
"ball" occurs 2 times (the most among the remaining words), so it is the answer.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    char* words[10000];
    int count[10000];
    int wc = 0;

    int n = strlen(paragraph);
    for (int i = 0; i < n; i++) {
        if (isalpha(paragraph[i])) {
            paragraph[i] = tolower(paragraph[i]);
        } else {
            paragraph[i] = ' ';
        }
    }

    char* token = strtok(paragraph, " ");
    while (token) {
        if (strlen(token) > 0) {
            int found = -1;
            for (int i = 0; i < wc; i++) {
                if (strcmp(words[i], token) == 0) {
                    found = i;
                    break;
                }
            }
            if (found != -1) {
                count[found]++;
            } else {
                words[wc] = token;
                count[wc] = 1;
                wc++;
            }
        }
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < bannedSize; i++) {
        for (int j = 0; j < wc; j++) {
            if (strcmp(words[j], banned[i]) == 0) {
                count[j] = -1;
            }
        }
    }

    int maxCount = 0;
    char* ans = NULL;
    for (int i = 0; i < wc; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            ans = words[i];
        }
    }

    return ans;
}

int main() {
    char paragraph[] = "Bob hit a ball, the hit BALL flew far after it was hit.";
    char* banned[] = {"hit"};
    int bannedSize = 1;

    char* ans = mostCommonWord(paragraph, banned, bannedSize);
    printf("Most common word: %s\n", ans);
    return 0;
}

/*
Sample Output:
Most common word: ball
*/
