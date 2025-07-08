/*
Problem:
Design a singly linked list with the following functions:

- get(index): Get the value of the index-th node, or -1 if index is invalid.
- addAtHead(val): Add node before the first element.
- addAtTail(val): Append node at end.
- addAtIndex(index, val): Insert before index-th node.
- deleteAtIndex(index): Delete index-th node.

Example:
Input:
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]

Output:
[null,null,null,null,2,null,3]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    Node* curr = obj->head;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (!obj->head) {
        obj->head = node;
    } else {
        Node* curr = obj->head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) return;
    if (index <= 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* node = malloc(sizeof(Node));
    node->val = val;

    Node* curr = obj->head;
    for (int i = 0; i < index - 1; i++) curr = curr->next;
    node->next = curr->next;
    curr->next = node;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;

    Node* temp;
    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
    } else {
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; i++) curr = curr->next;
        temp = curr->next;
        curr->next = curr->next->next;
    }
    free(temp);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

// Demo
int main() {
    MyLinkedList* list = myLinkedListCreate();
    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtTail(list, 3);
    myLinkedListAddAtIndex(list, 1, 2);  // List: 1 -> 2 -> 3
    printf("Get index 1: %d\n", myLinkedListGet(list, 1)); // 2
    myLinkedListDeleteAtIndex(list, 1);                    // List: 1 -> 3
    printf("Get index 1: %d\n", myLinkedListGet(list, 1)); // 3
    myLinkedListFree(list);
    return 0;
}
