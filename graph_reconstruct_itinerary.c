/*
Problem: Reconstruct Itinerary

You are given a list of airline tickets represented by pairs of departure and arrival airports [from, to]. 
Reconstruct the itinerary in order. All of the tickets belong to a man who departs from "JFK". 
Thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, 
you should return the itinerary that has the smallest lexical order when read as a single string.

Example:
Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 300
#define MAX_CODE_LEN 4
#define HASH_SIZE 1000

typedef struct Node {
    char dest[MAX_CODE_LEN];
    struct Node* next;
} Node;

typedef struct {
    char key[MAX_CODE_LEN];
    Node* head;
} HashEntry;

HashEntry hashMap[HASH_SIZE];
int returnSize;
char** result;

unsigned hash(char* str) {
    unsigned h = 0;
    while (*str) h = (h * 31) + *str++;
    return h % HASH_SIZE;
}

void addEdge(char* from, char* to) {
    unsigned h = hash(from);
    while (hashMap[h].key[0] && strcmp(hashMap[h].key, from) != 0)
        h = (h + 1) % HASH_SIZE;

    if (!hashMap[h].key[0])
        strcpy(hashMap[h].key, from);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->dest, to);
    newNode->next = NULL;

    // Insert in lex order
    Node** curr = &hashMap[h].head;
    while (*curr && strcmp((*curr)->dest, to) < 0)
        curr = &(*curr)->next;
    newNode->next = *curr;
    *curr = newNode;
}

Node* getEdges(char* from) {
    unsigned h = hash(from);
    while (hashMap[h].key[0] && strcmp(hashMap[h].key, from) != 0)
        h = (h + 1) % HASH_SIZE;
    return hashMap[h].head;
}

void removeEdge(char* from) {
    unsigned h = hash(from);
    while (hashMap[h].key[0] && strcmp(hashMap[h].key, from) != 0)
        h = (h + 1) % HASH_SIZE;
    Node* temp = hashMap[h].head;
    if (temp) {
        hashMap[h].head = temp->next;
        free(temp);
    }
}

void visit(char* airport) {
    Node* edge = getEdges(airport);
    while (edge) {
        char next[MAX_CODE_LEN];
        strcpy(next, edge->dest);
        removeEdge(airport);
        visit(next);
        edge = getEdges(airport);
    }
    result[--returnSize] = strdup(airport);
}

char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSizeOut) {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashMap[i].key[0] = '\0';
        hashMap[i].head = NULL;
    }

    for (int i = 0; i < ticketsSize; i++)
        addEdge(tickets[i][0], tickets[i][1]);

    result = (char**)malloc((ticketsSize + 1) * sizeof(char*));
    returnSize = ticketsSize + 1;

    visit("JFK");

    *returnSizeOut = ticketsSize + 1;
    return result;
}

// Sample Test
int main() {
    char* rawTickets[][2] = {{"JFK", "MUC"}, {"MUC", "LHR"}, {"LHR", "SFO"}, {"SFO", "SJC"}};
    int ticketsSize = 4;

    char*** tickets = (char***)malloc(ticketsSize * sizeof(char**));
    int* ticketsColSize = (int*)malloc(ticketsSize * sizeof(int));
    for (int i = 0; i < ticketsSize; i++) {
        tickets[i] = (char**)malloc(2 * sizeof(char*));
        tickets[i][0] = rawTickets[i][0];
        tickets[i][1] = rawTickets[i][1];
        ticketsColSize[i] = 2;
    }

    int returnSize = 0;
    char** itinerary = findItinerary(tickets, ticketsSize, ticketsColSize, &returnSize);

    printf("Itinerary: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", itinerary[i]);
        free(itinerary[i]);
    }
    printf("\n");

    free(itinerary);
    for (int i = 0; i < ticketsSize; i++)
        free(tickets[i]);
    free(tickets);
    free(ticketsColSize);

    return 0;
}
