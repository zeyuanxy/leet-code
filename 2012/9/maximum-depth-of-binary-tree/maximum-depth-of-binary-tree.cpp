/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        int depth1 = maxDepth(root->left), depth2 = maxDepth(root->right);
        if(depth1 > depth2)
            return depth1 + 1;
        else
            return depth2 + 1;
    }
};