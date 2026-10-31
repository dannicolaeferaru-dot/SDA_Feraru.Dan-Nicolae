#include <stdlib.h>

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode* queue[2005];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;

    int** result = (int**)malloc(2005 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2005 * sizeof(int));
    int levels = 0;

    while (front < rear) {
        int level_size = rear - front;
        int* current_level = (int*)malloc(level_size * sizeof(int));

        for (int i = 0; i < level_size; i++) {
            struct TreeNode* curr = queue[front++];
            current_level[i] = curr->val;

            if (curr->left) {
                queue[rear++] = curr->left;
            }
            if (curr->right) {
                queue[rear++] = curr->right;
            }
        }

        (*returnColumnSizes)[levels] = level_size;
        result[levels] = current_level;
        levels++;
    }

    *returnSize = levels;
    return result;
}
