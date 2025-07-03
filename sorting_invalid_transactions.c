/*
Problem:
A transaction is invalid if:
- Amount > 1000, or
- It occurs within 60 minutes of another transaction with the same name in a different city.

Approach:
- Parse each transaction string into a struct.
- Check amount and compare with others for timing and city.
- Mark invalids and return them.

Time: O(n^2) for pair comparisons
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TRANS 1000

typedef struct {
    char name[21];
    int time;
    int amount;
    char city[21];
    char raw[101];
} Transaction;

int parseTransaction(char* str, Transaction* t) {
    sscanf(str, "%[^,],%d,%d,%[^,]", t->name, &t->time, &t->amount, t->city);
    strcpy(t->raw, str);
    return 1;
}

char** invalidTransactions(char** transactions, int transactionsSize, int* returnSize) {
    Transaction list[MAX_TRANS];
    bool invalid[MAX_TRANS] = {false};

    for (int i = 0; i < transactionsSize; i++) {
        parseTransaction(transactions[i], &list[i]);
    }

    for (int i = 0; i < transactionsSize; i++) {
        if (list[i].amount > 1000) {
            invalid[i] = true;
        }
        for (int j = 0; j < transactionsSize; j++) {
            if (i == j) continue;
            if (strcmp(list[i].name, list[j].name) == 0 &&
                abs(list[i].time - list[j].time) <= 60 &&
                strcmp(list[i].city, list[j].city) != 0) {
                invalid[i] = true;
                break;
            }
        }
    }

    char** result = malloc(sizeof(char*) * transactionsSize);
    *returnSize = 0;
    for (int i = 0; i < transactionsSize; i++) {
        if (invalid[i]) {
            result[*returnSize] = strdup(list[i].raw);
            (*returnSize)++;
        }
    }
    return result;
}

// Test
int main() {
    char* transactions[] = {
        "alice,20,800,mtv",
        "alice,50,100,beijing",
        "alice,51,1200,mtv",
        "bob,30,1200,sf"
    };
    int size = sizeof(transactions) / sizeof(transactions[0]);
    int returnSize;
    char** invalids = invalidTransactions(transactions, size, &returnSize);

    printf("Invalid Transactions:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", invalids[i]);
        free(invalids[i]);
    }
    free(invalids);
    return 0;
}

/*
========= OUTPUT =========
Invalid Transactions:
alice,50,100,beijing
alice,51,1200,mtv
bob,30,1200,sf
==========================
*/
