#include <stdlib.h>

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode** curr = &root;

    while (*curr != NULL) {
        if (val < (*curr)->val) {
            curr = &((*curr)->left);
        } else {
            curr = &((*curr)->right);
        }
    }

    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    *curr = newNode;

    return root;
}
