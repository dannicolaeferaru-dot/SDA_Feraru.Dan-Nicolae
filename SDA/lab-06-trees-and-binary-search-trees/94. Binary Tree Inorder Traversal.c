#include <stdlib.h>

static int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

static void dfs(struct TreeNode* root, int* res, int* count) {
    if (root == NULL) {
        return;
    }
    dfs(root->left, res, count);
    res[(*count)++] = root->val;
    dfs(root->right, res, count);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int n = countNodes(root);
    int* res = (int*)malloc((n == 0 ? 1 : n) * sizeof(int));
    *returnSize = 0;

    dfs(root, res, returnSize);

    return res;
}
