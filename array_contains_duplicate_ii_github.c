/*
Problem: Contains Duplicate II

Given an integer array `nums` and an integer `k`, return true if there are two distinct indices i and j 
in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example:
Input:
nums = [1,2,3,1], k = 3

Output:
true
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define HASH_SIZE 10007

typedef struct Node {
    int key;
    int index;
    struct Node* next;
} Node;

int hash(int key) {
    return (key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    Node* table[HASH_SIZE] = {0};

    for (int i = 0; i < numsSize; i++) {
        int h = hash(nums[i]);
        Node* curr = table[h];
        while (curr) {
            if (curr->key == nums[i] && i - curr->index <= k) {
                return true;
            }
            curr = curr->next;
        }

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = nums[i];
        newNode->index = i;
        newNode->next = table[h];
        table[h] = newNode;
    }

    // Free memory
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = table[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int k = 3;
    int size = sizeof(nums) / sizeof(nums[0]);

    bool result = containsNearbyDuplicate(nums, size, k);
    printf("Output: %s\n", result ? "true" : "false");

    return 0;
}
