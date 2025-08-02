/*
Problem: Word Search II

Given an m x n board of characters and a list of strings words, 
return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

Example:
Input: 
board = [["o","a","a","n"],
         ["e","t","a","e"],
         ["i","h","k","r"],
         ["i","f","l","v"]]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    char* word;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) node->children[i] = NULL;
    node->word = NULL;
    return node;
}

void insert(TrieNode* root, char* word) {
    TrieNode* curr = root;
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!curr->children[idx]) curr->children[idx] = createNode();
        curr = curr->children[idx];
    }
    curr->word = word;
}

void dfs(char** board, int boardSize, int boardColSize, int i, int j, TrieNode* node, char** result, int* returnSize) {
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize || board[i][j] == '#')
        return;

    char c = board[i][j];
    TrieNode* next = node->children[c - 'a'];
    if (!next) return;

    if (next->word) {
        result[(*returnSize)++] = next->word;
        next->word = NULL;
    }

    board[i][j] = '#';
    dfs(board, boardSize, boardColSize, i + 1, j, next, result, returnSize);
    dfs(board, boardSize, boardColSize, i - 1, j, next, result, returnSize);
    dfs(board, boardSize, boardColSize, i, j + 1, next, result, returnSize);
    dfs(board, boardSize, boardColSize, i, j - 1, next, result, returnSize);
    board[i][j] = c;
}

char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    char** result = (char**)malloc(wordsSize * sizeof(char*));

    TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; i++) insert(root, words[i]);

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            dfs(board, boardSize, boardColSize[0], i, j, root, result, returnSize);
        }
    }

    return result;
}

// Sample usage not included due to board complexity for console demo
