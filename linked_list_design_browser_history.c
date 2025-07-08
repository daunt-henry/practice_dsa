/*
Problem:
Design a BrowserHistory class to simulate a browser's history functionality:
- BrowserHistory(char *homepage)
- void visit(char *url)
- char *back(int steps)
- char *forward(int steps)

Constraints:
- URLs are strings
- Back/forward must operate in O(steps)

Approach:
- Implement doubly linked list of nodes, each storing a URL.
- Current node pointer tracks the active page.

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for each history page
typedef struct HistoryNode {
    char* url;
    struct HistoryNode* prev;
    struct HistoryNode* next;
} HistoryNode;

// Browser history class
typedef struct {
    HistoryNode* current;
} BrowserHistory;

BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory* obj = malloc(sizeof(BrowserHistory));
    HistoryNode* node = malloc(sizeof(HistoryNode));
    node->url = strdup(homepage);
    node->prev = node->next = NULL;
    obj->current = node;
    return obj;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    HistoryNode* node = malloc(sizeof(HistoryNode));
    node->url = strdup(url);
    node->prev = obj->current;
    node->next = NULL;

    // Cut off forward history
    if (obj->current->next) {
        HistoryNode* temp = obj->current->next;
        while (temp) {
            HistoryNode* next = temp->next;
            free(temp->url);
            free(temp);
            temp = next;
        }
    }

    obj->current->next = node;
    obj->current = node;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    while (steps-- > 0 && obj->current->prev) {
        obj->current = obj->current->prev;
    }
    return obj->current->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    while (steps-- > 0 && obj->current->next) {
        obj->current = obj->current->next;
    }
    return obj->current->url;
}

void browserHistoryFree(BrowserHistory* obj) {
    while (obj->current->prev) {
        obj->current = obj->current->prev;
    }
    HistoryNode* temp = obj->current;
    while (temp) {
        HistoryNode* next = temp->next;
        free(temp->url);
        free(temp);
        temp = next;
    }
    free(obj);
}

// Demo
int main() {
    BrowserHistory* bh = browserHistoryCreate("leetcode.com");
    browserHistoryVisit(bh, "google.com");
    browserHistoryVisit(bh, "facebook.com");
    browserHistoryVisit(bh, "youtube.com");

    printf("Back 1: %s\n", browserHistoryBack(bh, 1));     // facebook.com
    printf("Back 1: %s\n", browserHistoryBack(bh, 1));     // google.com
    printf("Forward 1: %s\n", browserHistoryForward(bh, 1)); // facebook.com

    browserHistoryVisit(bh, "linkedin.com");
    printf("Forward 2: %s\n", browserHistoryForward(bh, 2)); // linkedin.com
    printf("Back 2: %s\n", browserHistoryBack(bh, 2));     // google.com
    printf("Back 7: %s\n", browserHistoryBack(bh, 7));     // leetcode.com

    browserHistoryFree(bh);
    return 0;
}
