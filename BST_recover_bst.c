void inorder(struct TreeNode* root, struct TreeNode** prev,
             struct TreeNode** first, struct TreeNode** second) {
    if (!root) return;

    inorder(root->left, prev, first, second);

    if (*prev && (*prev)->val > root->val) {
        if (!*first) *first = *prev;
        *second = root;
    }

    *prev = root;
    inorder(root->right, prev, first, second);
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    struct TreeNode* first = NULL;
    struct TreeNode* second = NULL;

    inorder(root, &prev, &first, &second);

    if (first && second) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}
